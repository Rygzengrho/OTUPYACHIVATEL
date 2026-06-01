// Copyright (C) 2008 Blade <rygzengrho@yandex.ru>
//
// This file is part of OTUPYACHIVATEL.
//
// OTUPYACHIVATEL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// OTUPYACHIVATEL is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with OTUPYACHIVATEL.  If not, see <http://www.gnu.org/licenses/>.

#include "StdAfx.h"
#include "Config.h"

CConfig::CConfig(void)
{
	m_fCapitalizationChance = 0;
	m_f3AdditionsChance = 0;
	m_f2AdditionsChance = 0;
	m_f1AdditionChance = 0;
	m_fNumToRep = 0;
	m_sNumRepString = L"";
	m_fNumRepChance = 0;
	m_dwMinLengthForAddition = 0;

	ResetStrings();
}

CConfig::~CConfig(void)
{
}

bool CConfig::ResetStrings()
{
	m_sComment = L"/";
	m_sBlockCommentSymbol = L"*";;
	m_sEndSymbol = L"\n";
	m_sSpaces = L" \t";
	m_sEquals = L"=";
	m_sStringID = L"\"";
	m_sMacroID = L"*";
	m_sChanceSeparator = L":";
	m_sResultsSeparator = L",";
	m_sNumber = L"1234567890";
	m_sDecimalPoint = L".";
	m_sEngAlphabetLower = L"abcdefghijklmnopqrstuvwxyz";
	m_sEngAlphabetUpper = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	m_sRusAlphabetLower = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	m_sRusAlphabetUpper = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	m_sSeparatorsNotForChange = ",;:'`\"~$%^&*()_=+/<>{}[]№";
	m_sSeparatorsChangeable = ".!?";
	m_sRandAddID = L"~";
	m_sTagID = L"|";

	// Tags
	m_sUpTag = L"UP";
	m_sSaveTag = L"SAVE";

	return 0;
}

// Парсинг строковых и числовых переменных из строки
bool CConfig::ParseVariableString( CString* sVariable, CString* sString )
{
	sString->Delete ( sString->GetLength() - 1 );
	sString->Trim ( m_sSpaces + m_sStringID );
	if ( *sString != L"" )
		*sVariable = (LPCTSTR) *sString ;
	else
	{
		*sVariable = L"";
		return 1;
	}

	return 0;
}

bool CConfig::ParseVariableFloat( FLOAT* fVariable, CString* sString )
{
	sString->Trim ( m_sSpaces + m_sStringID );
	if ( *sString != L"" )
		*fVariable = _wtof( (LPCTSTR) *sString );
	else
	{
		fVariable = 0;
		return 1;
	}

	return 0;
}

bool CConfig::ParseVariableDWORD( DWORD* dwVariable, CString* sString )
{
	CString sZeros ( L"0" );

	sString->Trim ( m_sSpaces + m_sStringID );
	// Это чтобы в окошках, куда выводится это значение, нулей перед числами не было
	sString->TrimLeft ( sZeros );
	if ( *sString != L"" )
		*dwVariable = wcstoul( (LPCTSTR) *sString, '\0', 10 );
	else
	{
		dwVariable = 0;
		return 1;
	}

	return 0;
}

bool CConfig::ParseConfig( CString* sConfig )
{
	CString sSymbol ( L"" );
	CString sSubstring ( L"" );
	CString sPrevious ( L"" );
	CString sCurrent ( L"" );

	// Флаг того, что возможно парсимое выражение является комментом
	// Используется для того, чтобы если выражение - не коммент, но выглядело
	// как коммент, оно парсилось способами "не для комментов"
	bool	bComment = TRUE;
	// Флаг того, что произошла какая-то ошибка и что нужно вывести пользователю предупреждение
	bool	bWarning = FALSE;
	bool	bEndOfString = FALSE;

	CString sNewResult;
	FLOAT	fNewChance;

	while ( !sConfig->IsEmpty() )
	{
		// Проверяем, к какому набору относится следующий символ
		// После этого выделяем эту подстроку полностью
		sSymbol.Empty();
		sSymbol.AppendChar ( sConfig->GetAt(0) );
		//Если есть шанс, что это коммент
		if ( !sSymbol.FindOneOf ( m_sComment ) && bComment )
		{
			// Если это коммент одной строки (2 символа m_sComment подряд) - тогда забиваем на эту строчку
			if ( sConfig->GetAt(1) == m_sComment )
			{
				// На случай, если это последняя строка в файле и после нее нет символа конца строки
				INT nCount = sConfig->FindOneOf ( m_sEndSymbol );
				if ( nCount == -1 )
					nCount = sConfig->GetLength();

				sConfig->Delete ( 0, nCount + 1 );
			}
			// Если это блоковый коммент (начинается с "m_sComment + m_sBlockCommentSymbol" и заканчивается "m_sBlockCommentSymbol + m_sComment" - тогда забиваем на все, что внутри
			else if ( sConfig->GetAt(1) == m_sBlockCommentSymbol )
			{
				// Если закрывающих символов нет - считаем, что коммент - это все до конца файла
				INT nCount = sConfig->Find ( m_sBlockCommentSymbol + m_sComment );
				if ( nCount == -1 )
					nCount = sConfig->GetLength();

				sConfig->Delete ( 0, nCount + 1 );
			}
			// Если это просто одинокий слеш - забиваем на него
			else
				bComment = FALSE;
		}
		// Если есть символы отступа - отбрасываем их
		else if ( !sSymbol.FindOneOf ( m_sSpaces ) )
		{
			sConfig->TrimLeft ( m_sSpaces );
			bComment = TRUE;
		}
		// Если символ конца - тупо переходим на след. строку
		else if ( !sSymbol.FindOneOf ( m_sEndSymbol ) )
		{
			sConfig->Delete ( 0 );
			bComment = TRUE;
		}
		// Если символ из алфавита без указателя строки - парсим как переменную
		else if ( !sSymbol.FindOneOf ( m_sEngAlphabetLower + m_sEngAlphabetUpper ) )
		{
			sSubstring = sConfig->SpanExcluding ( m_sEquals + m_sEndSymbol );
			sConfig->Delete ( 0, sSubstring.GetLength() );
			if ( sConfig->GetAt ( 0 ) != m_sEndSymbol )
			{
				sConfig->Delete ( 0 );
				sSubstring.Trim ( m_sSpaces );
				if ( sSubstring == L"Capitalization Chance" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableFloat ( &m_fCapitalizationChance, &sSubstring ) )
						bWarning = TRUE;
				}
				else if ( sSubstring == L"Three Additions Chance" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableFloat ( &m_f3AdditionsChance, &sSubstring ) )
						bWarning = TRUE;
				}
				else if ( sSubstring == L"Two Additions Chance" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableFloat ( &m_f2AdditionsChance, &sSubstring ) )
						bWarning = TRUE;
				}
				else if ( sSubstring == L"One Addition Chance" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableFloat ( &m_f1AdditionChance, &sSubstring ) )
						bWarning = TRUE;
				}
				else if ( sSubstring == L"Number To Replace" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableFloat ( &m_fNumToRep, &sSubstring ) )
						bWarning = TRUE;
				}
				else if ( sSubstring == L"Number Replacement String" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableString ( &m_sNumRepString, &sSubstring ) )
						bWarning = TRUE;
				}
				else if ( sSubstring == L"Number Replacement Chance" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableFloat ( &m_fNumRepChance, &sSubstring ) )
						bWarning = TRUE;
				}
				else if ( sSubstring == L"Min Word Length For Addition" )
				{
					sSubstring = sConfig->SpanExcluding ( m_sEndSymbol );
					if ( ParseVariableDWORD ( &m_dwMinLengthForAddition, &sSubstring ) )
						bWarning = TRUE;
				}
			}

			sConfig->Delete ( 0, sConfig->FindOneOf ( m_sEndSymbol ) + 1 );
		}
		else if ( !sSymbol.FindOneOf ( m_sStringID ) )
		{
			// Если указатель на то, что будет строка -
			// тогда парсим как действительно нужное нам выражение
			CReplacer	TempReplacer;

			// Сначала копируем заменяемую строку
			sConfig->Delete( 0 );
			sSubstring = sConfig->SpanExcluding ( m_sStringID + m_sEndSymbol );
			TempReplacer.SetStrToChange ( sSubstring );
			sConfig->Delete ( 0, sSubstring.GetLength() );

			if ( sConfig->GetAt ( 0 ) != m_sEndSymbol )
			{
				sConfig->Delete ( 0 );

				// Потом ищем начало правой части выражения
				sSubstring = sConfig->SpanExcluding ( m_sEquals + m_sEndSymbol );
				sConfig->Delete ( 0, sSubstring.GetLength() );
			}

			if ( sConfig->GetAt ( 0 ) != m_sEndSymbol )
			{
				bool	bTag = FALSE;

				sConfig->Delete ( 0 );

				// Потом ищем начало строки, на которую возможна замена
				sSubstring = sConfig->SpanExcluding ( m_sStringID + m_sMacroID + m_sEndSymbol );
				sConfig->Delete ( 0, sSubstring.GetLength() );

				// Проверяем, не является ли строка замены тегом
				if ( sConfig->GetAt ( 0 ) == m_sMacroID )
					bTag = TRUE;
				else
					bTag = FALSE;

				sConfig->Delete ( 0 );

				sSubstring = sConfig->SpanExcluding ( m_sMacroID + m_sStringID + m_sEndSymbol );

				// Если является тегом
				if ( bTag )
				{
					if ( sSubstring == m_sUpTag )
					{
						// Копируем предыдущую строку результатов и ее обрабатываем
						sCurrent = sPrevious;
						sConfig->Delete ( 0, sConfig->FindOneOf ( m_sEndSymbol ) );
					}
					else if ( sSubstring == m_sSaveTag )
					{
						// Делаем шанс замены равным нулю и сразу записываем в вектор замен
						sCurrent.Empty();
						TempReplacer.SetResult ( TempReplacer.GetStrToChange(), 0 );
						sConfig->Delete ( 0, sConfig->FindOneOf ( m_sEndSymbol ) );
					}
				}
				else
				{
					// Используем эту строку
					sCurrent = sConfig->SpanExcluding ( m_sEndSymbol );
					sPrevious = sCurrent;
					sConfig->Delete ( 0, sCurrent.GetLength() );
				}
			}

			// Нужно не забыть удалить символ окончания строки
			sConfig->Delete ( 0 );

			// Средний шанс вставки
			FLOAT fAverageChance;
			fAverageChance = 100 / (Count ( &sCurrent, &m_sResultsSeparator ) + 1);

			// Идем пока не кончится строка, пока не соберем все варианты замены
			while ( !sCurrent.IsEmpty() )
			{
				// Сначала идет название результата
				sSubstring = sCurrent.SpanExcluding ( m_sStringID + m_sEndSymbol );
				sNewResult = sSubstring;
				sCurrent.Delete ( 0, sSubstring.GetLength() + 1 );

				// Обрезаем лишнее до шанса, или до следующего
				sCurrent.Delete ( 0, sCurrent.FindOneOf ( m_sNumber + m_sStringID + m_sEndSymbol ) );

				// Потом идет шанс
				sSubstring = sCurrent.SpanIncluding ( m_sNumber + m_sDecimalPoint );
				if ( sSubstring == L"" )
				{
					// Если шанс явно не указан - делаем его равным среднему значению
					fNewChance = fAverageChance;
				}
				else
					fNewChance = _wtof( (LPCTSTR) sSubstring );
				
				sCurrent.Delete ( 0, sSubstring.GetLength() );

				//Добавляем во временную переменную
				TempReplacer.SetResult ( sNewResult, fNewChance );

				// Обрезаем лишнее (тут пришлось поменять метод, так как в конце строки
				// лишнее не хотело удаляться)
				sSubstring = sCurrent.SpanExcluding ( m_sStringID + m_sEndSymbol );
				sCurrent.Delete ( 0, sSubstring.GetLength() + 1 );
			}
			m_Replacer.push_back ( TempReplacer );
		}
		else if ( !sSymbol.FindOneOf ( m_sRandAddID ) )
		{
			// Эл-т для рандомной вставки
			CRandomAdder	TempRandAdder;

			sConfig->Delete( 0 );
			sSubstring = sConfig->SpanExcluding ( m_sRandAddID + m_sEndSymbol );
			TempRandAdder.SetStrToAdd ( sSubstring );
			sConfig->Delete ( 0, sSubstring.GetLength() );

			if ( sConfig->GetAt ( 0 ) != m_sEndSymbol )
			{
				sConfig->Delete ( 0 );

				// Шанс вставки по-умолчанию
				const FLOAT fDefaultChance = 1;

				// Обрезаем лишнее
				sConfig->Delete ( 0, sConfig->FindOneOf ( m_sNumber + m_sEndSymbol ) );

				// Потом идет шанс
				sSubstring = sConfig->SpanIncluding ( m_sNumber + m_sDecimalPoint );
				if ( sSubstring == L"" )
					// Если шанс явно не указан - делаем его равным дефолтному значению
					TempRandAdder.SetChance ( fDefaultChance );
				else
					TempRandAdder.SetChance ( _wtof( (LPCTSTR) sSubstring ) );
			}

			m_RandomAdder.push_back ( TempRandAdder );

			sConfig->Delete ( 0, sConfig->FindOneOf ( m_sEndSymbol ) + 1 );
		}
		else if ( !sSymbol.FindOneOf ( m_sTagID ) )
		{
			// Тэг
			CTags	TempTag;

			// Сначала считываем открывающий тэг
			sConfig->Delete( 0 );
			sSubstring = sConfig->SpanExcluding ( m_sTagID + m_sEndSymbol );
			TempTag.SetOpenTag ( sSubstring );
			sConfig->Delete ( 0, sSubstring.GetLength() );

			if ( sConfig->GetAt ( 0 ) != m_sEndSymbol )
			{
				sConfig->Delete ( 0 );

				// Обрезаем лишнее
				sConfig->Delete ( 0, sConfig->FindOneOf ( m_sNumber + m_sEndSymbol ) );

				// Потом идет шанс того, что тэг откроется
				sSubstring = sConfig->SpanIncluding ( m_sNumber + m_sDecimalPoint );
				if ( sSubstring != L"" )
					TempTag.SetOpenTagChance ( _wtof( (LPCTSTR) sSubstring ) );
				else
				{
					TempTag.SetOpenTagChance ( 0 );
					bWarning = TRUE;
				}

				// Обрезаем лишнее
				sConfig->Delete ( 0, sConfig->FindOneOf ( m_sTagID + m_sEndSymbol ) );
			}

			if ( sConfig->GetAt ( 0 ) != m_sEndSymbol )
			{
				sConfig->Delete ( 0 );

				// Потом закрывающий тэг
				sSubstring = sConfig->SpanExcluding ( m_sTagID + m_sEndSymbol );
				TempTag.SetCloseTag ( sSubstring );
				sConfig->Delete ( 0, sSubstring.GetLength() );
			}

			if ( sConfig->GetAt ( 0 ) != m_sEndSymbol )
			{
				sConfig->Delete ( 0 );

				// Обрезаем лишнее
				sConfig->Delete ( 0, sConfig->FindOneOf ( m_sNumber + m_sEndSymbol ) );

				// Потом идет шанс того, что тэг закроется
				sSubstring = sConfig->SpanIncluding ( m_sNumber + m_sDecimalPoint );
				if ( sSubstring != L"" )
					TempTag.SetCloseTagChance ( _wtof( (LPCTSTR) sSubstring ) );
				else
				{
					TempTag.SetCloseTagChance ( 0 );
					bWarning = TRUE;
				}
			}

			m_Tags.push_back ( TempTag );

			sConfig->Delete ( 0, sConfig->FindOneOf ( m_sEndSymbol ) + 1 );
		}
		else
			sConfig->Delete ( 0 );
	}

	if ( bWarning )
		return 1;
	else
		return 0;
}

// Очистка конфига
bool CConfig::Clear ()
{
	m_fCapitalizationChance = 0;
	m_f3AdditionsChance = 0;
	m_f2AdditionsChance = 0;
	m_f1AdditionChance = 0;
	m_fNumToRep = 0;
	m_sNumRepString = L"";
	m_fNumRepChance = 0;
	m_dwMinLengthForAddition = 0;

	m_Replacer.clear();
	m_RandomAdder.clear();
	m_Tags.clear();

	return 0;
}

// Дефолтный CString-овский MakeLower и MakeUpper не умеют работать
// с русскими буквами(
bool CConfig::MakeLowerRus ( CString* sString )
{
	sString->Replace ( L'А', L'а' );
	sString->Replace ( L'Б', L'б' );
	sString->Replace ( L'В', L'в' );
	sString->Replace ( L'Г', L'г' );
	sString->Replace ( L'Д', L'д' );
	sString->Replace ( L'Е', L'е' );
	sString->Replace ( L'Ё', L'ё' );
	sString->Replace ( L'Ж', L'ж' );
	sString->Replace ( L'З', L'з' );
	sString->Replace ( L'И', L'и' );
	sString->Replace ( L'Й', L'й' );
	sString->Replace ( L'К', L'к' );
	sString->Replace ( L'Л', L'л' );
	sString->Replace ( L'М', L'м' );
	sString->Replace ( L'Н', L'н' );
	sString->Replace ( L'О', L'о' );
	sString->Replace ( L'П', L'п' );
	sString->Replace ( L'Р', L'р' );
	sString->Replace ( L'С', L'с' );
	sString->Replace ( L'Т', L'т' );
	sString->Replace ( L'У', L'у' );
	sString->Replace ( L'Ф', L'ф' );
	sString->Replace ( L'Х', L'х' );
	sString->Replace ( L'Ц', L'ц' );
	sString->Replace ( L'Ч', L'ч' );
	sString->Replace ( L'Ш', L'ш' );
	sString->Replace ( L'Щ', L'щ' );
	sString->Replace ( L'Ъ', L'ъ' );
	sString->Replace ( L'Ы', L'ы' );
	sString->Replace ( L'Ь', L'ь' );
	sString->Replace ( L'Э', L'э' );
	sString->Replace ( L'Ю', L'ю' );
	sString->Replace ( L'Я', L'я' );
	return 0;
}

bool CConfig::MakeUpperRus ( CString* sString )
{
	sString->Replace ( L'а', L'А' );
	sString->Replace ( L'б', L'Б' );
	sString->Replace ( L'в', L'В' );
	sString->Replace ( L'г', L'Г' );
	sString->Replace ( L'д', L'Д' );
	sString->Replace ( L'е', L'Е' );
	sString->Replace ( L'ё', L'Ё' );
	sString->Replace ( L'ж', L'Ж' );
	sString->Replace ( L'з', L'З' );
	sString->Replace ( L'и', L'И' );
	sString->Replace ( L'й', L'Й' );
	sString->Replace ( L'к', L'К' );
	sString->Replace ( L'л', L'Л' );
	sString->Replace ( L'м', L'М' );
	sString->Replace ( L'н', L'Н' );
	sString->Replace ( L'о', L'О' );
	sString->Replace ( L'п', L'П' );
	sString->Replace ( L'р', L'Р' );
	sString->Replace ( L'с', L'С' );
	sString->Replace ( L'т', L'Т' );
	sString->Replace ( L'у', L'У' );
	sString->Replace ( L'ф', L'Ф' );
	sString->Replace ( L'х', L'Х' );
	sString->Replace ( L'ц', L'Ц' );
	sString->Replace ( L'ч', L'Ч' );
	sString->Replace ( L'ш', L'Ш' );
	sString->Replace ( L'щ', L'Щ' );
	sString->Replace ( L'ъ', L'Ъ' );
	sString->Replace ( L'ы', L'Ы' );
	sString->Replace ( L'ь', L'Ь' );
	sString->Replace ( L'э', L'Э' );
	sString->Replace ( L'ю', L'Ю' );
	sString->Replace ( L'я', L'Я' );
	return 0;
}

DWORD CConfig::Count ( const CString* sString, const CString* sSymbol )
{
	DWORD dwCount = 0;
	DWORD dwStart = 1;

	if ( sString->IsEmpty() )
		return 0;

	// 0-й символ приходится проверять отдельно, так как Find возвращает 0 если е нашел ничего
	// и потом трудно будет понять, есть ли символ на 0-м месте, или нет ничего
	if ( sString->GetAt ( 0 ) == *sSymbol )
		dwCount++;

	while ( dwStart <= sString->GetLength() && dwStart != -0 )
	{
		dwStart = ( sString->Find ( *sSymbol, dwStart ) +1 );
		if ( dwStart )
			dwCount++;
	}

	return dwCount;
}
// Если в строке был обнаружен амперсанд. Проверка, что условия выполняются,
// и обрезание лишнего
bool CConfig::SearchAmper ( CString* sStrToCheck, CString* sStrToCompareWith )
{
	CString sAmper = L"&";

	bool bAmperFirst = FALSE;

	if ( sStrToCompareWith->GetAt( 0 ) == sAmper )
	{
		bAmperFirst = TRUE;
		sStrToCompareWith->TrimLeft ( sAmper );
	}
	else if ( sStrToCompareWith->GetAt( sStrToCompareWith->GetLength() - 1 ) == sAmper )
	{
		bAmperFirst = FALSE;
		sStrToCompareWith->TrimRight ( sAmper );
	}
	else
		return 1;

	if ( sStrToCheck->GetLength() < sStrToCompareWith->GetLength() )
		return 1;

	INT nStrPlace = 0;
	INT nDivStrIndex = 0;

	if ( bAmperFirst )
		nStrPlace = sStrToCheck->Find ( *sStrToCompareWith, sStrToCheck->GetLength() - sStrToCompareWith->GetLength() );

	if ( !bAmperFirst )
		nStrPlace = sStrToCheck->Find ( *sStrToCompareWith, 0 );

	if ( nStrPlace == -1 )
	{
		return 1;
	}

	// Если это первый амперсанд - то строка должна начинаться не с самого начала,
	// а заканчиваться в самом конце
	else if ( nStrPlace == 0 ||
		nStrPlace + sStrToCompareWith->GetLength() < sStrToCheck->GetLength()
		&& bAmperFirst )
	{
		return 1;
	}
	// Если это последний амперсанд - то строка должна начинаться с самого начала,
	// а заканчиваться не в самом конце
	else if ( ( nStrPlace > 0 ||
		nStrPlace + sStrToCompareWith->GetLength() >= sStrToCheck->GetLength() )
		&& !bAmperFirst )
	{
		return 1;
	}

	if ( bAmperFirst )
		sStrToCheck->Delete ( nStrPlace, sStrToCheck->GetLength() - nStrPlace );
	else
		sStrToCheck->Delete ( 0, nStrPlace );

	return 0;
}

// Если в строке была обнаружена звезда. Проверка, что условия выполняются 
bool CConfig::SearchStar ( CString* sStrToCheck, CString* sStrToCompareWith )
{
	CString sStar ( L"*" );

	bool bStarFirst = FALSE;
	bool bStarLast = FALSE;

	if ( sStrToCompareWith->GetAt( 0 ) == sStar )
	{
		bStarFirst = TRUE;
		sStrToCompareWith->TrimLeft ( sStar );
	}
	if ( sStrToCompareWith->GetAt( sStrToCompareWith->GetLength() - 1 ) == sStar )
	{
		bStarLast = TRUE;
		sStrToCompareWith->TrimRight ( sStar );
	}

	// Сначала разбиваем исходную строку, с которой сравниваем, на массив
	// подстрок по признаку разделения звездочкой

	std::vector <CString> sStrDivided;

	while ( !sStrToCompareWith->IsEmpty() )
	{
		CString sSubstrDivided;
		sSubstrDivided = sStrToCompareWith->SpanExcluding ( sStar + m_sEndSymbol );
		sStrToCompareWith->Delete( 0, sSubstrDivided.GetLength() );
		sStrDivided.push_back ( sSubstrDivided );

		// Избавляемся от звездочек, а то вдруг их несколько
		sStrToCompareWith->TrimLeft ( sStar );
	}

	INT nStrPlace = 0;
	INT nDivStrIndex = 0;

	for ( ; nDivStrIndex < sStrDivided.size() ; nDivStrIndex++ )
	{
		nStrPlace = sStrToCheck->Find ( sStrDivided[ nDivStrIndex ], nStrPlace );

		if ( nStrPlace == -1 )
		{
			return 1;
		}
		// Если первой звездочки нет и это первый эл-т - то он должен
		// начинаться с 0-го индекса
		else if ( nStrPlace > 0 && !bStarFirst && !nDivStrIndex )
		{
			return 1;
		};

		// Чтобы искать с правильного места, ставим начальный индекс за тем,
		// что мы уже нашли
		nStrPlace += sStrDivided[ nDivStrIndex ].GetLength();
	}

	if ( nDivStrIndex >= sStrDivided.size() )
	{
		if ( !bStarLast && nStrPlace < sStrToCheck->GetLength() )
			return 1;
	}

	return 0;
}

bool CConfig::CheckAndChangeSubstring ( CString* sStrToCheck )
{
	// Charsets
	CString sStar ( L"*" );
	CString sAmper ( L"&" );

	UINT unIndex = 0;
	bool bAmperFirst = FALSE;
	bool bAddTempToResult = FALSE;

	// sTemp - чтобы не портить исходную строку lower case-ом
	CString sTempToCheck = *sStrToCheck;
	sTempToCheck.MakeLower();
	MakeLowerRus( &sTempToCheck );

	if ( m_Replacer.size() == 0 )
		return 0;

	for ( ; unIndex < m_Replacer.size() ; unIndex++ )
	{
		CString sStrToCompareWith = m_Replacer.at(unIndex).GetStrToChange();
		sStrToCompareWith.MakeLower();
		MakeLowerRus( &sStrToCompareWith );

		if ( sStrToCompareWith.FindOneOf ( sStar + sAmper ) == -1 )
		{
			if ( sTempToCheck == sStrToCompareWith )
			{
				// Очищаем флаг добавления потому, что он используется для сохранения части
				// исходной строки, а это происходит только в случае с амперсандом
				bAddTempToResult = FALSE;
				break;
			}
		}
		else
		{
			INT nAmperPlace = 0;
			if ( sStrToCompareWith.Find ( sStar ) != -1 )
			{
				if ( !SearchStar ( &sTempToCheck, &sStrToCompareWith ) )
				{
					bAddTempToResult = FALSE;
					break;
				}
			}
			else if (( nAmperPlace = sStrToCompareWith.Find ( sAmper )) != -1 )
			{
				if ( nAmperPlace == 0 )
					bAmperFirst = TRUE;
				if ( !SearchAmper ( &sTempToCheck, &sStrToCompareWith ) )
				{
					bAddTempToResult = TRUE;
					break;
				}
			}
		}
	}

	if ( unIndex < m_Replacer.size() )
	{
		bool bNotChanged = m_Replacer[unIndex].AttemptToChange ( sStrToCheck );

		if ( bAddTempToResult && !bNotChanged )
			if ( bAmperFirst )
				sStrToCheck->Insert( 0, sTempToCheck );
			else
				sStrToCheck->Insert( sStrToCheck->GetLength(), sTempToCheck );
	}

	return 0;
}

// Функция проверяет шансы на добавление рандомной вставки (или нескольких)
// Сначала проверются шансы на то, сколько вставок будет сделано, в порядке убывания
// Потом, исходя из этого количества, генерируется такое кол-во вставок
// Возвращает 0 в случае успешного добавления вставки
UINT CConfig::GenerateAdditionsAmount ()
{
	UINT unAmount = 0;
	
	CRandomGenerator RNG;

	if ( RNG.ChanceChecker ( m_f3AdditionsChance ) )
		unAmount = 3;
	else 
	{
		if ( RNG.ChanceChecker ( m_f2AdditionsChance ) )
			unAmount = 2;
		else
		{
			if ( RNG.ChanceChecker ( m_f1AdditionChance ) )
				unAmount = 1;
		}
	}

	return unAmount;
}

// Генерирует определенное кол-во вставок и добавляет их в строку
// Возвращает кол-во вставленных символов, или -1 в случае ошибки
DWORD CConfig::GenerateAdditions ( CString* sSubstring, UINT unAmount )
{
	if ( !unAmount  )
		return 0;

	// -1 means error
	DWORD dwSymbAdded = 0;

	FLOAT fSummaryChance = 0;

	CRandomGenerator RNG;

	for ( UINT unIndex = 0 ; unIndex < m_RandomAdder.size() ; unIndex++ )
		fSummaryChance += m_RandomAdder[unIndex].GetChance();

	if ( !fSummaryChance )
	{
		return -1;
	}

	while ( unAmount > 0 )
	{
		FLOAT fRandNum = RNG.RandomGenerator( 0, fSummaryChance );
		FLOAT fSumm = 0;

		for ( UINT unIndex = 0 ; unIndex < m_RandomAdder.size() ; unIndex++ )
		{
			fSumm += m_RandomAdder[unIndex].GetChance();

			if ( fRandNum <= fSumm )
			{
				m_RandomAdder[unIndex].Add ( sSubstring );
				dwSymbAdded += m_RandomAdder[unIndex].GetStrToAdd().GetLength();
				unAmount--;

				break;
			}
		}
	}

	return dwSymbAdded;
}

// Главная функция. Идет по тексту, проверяет его посимвольно на принадлежность к разным
// группам символов из чарсетов. Группирует по чарсетам. Слова, что логично их двух предыдущих
// предложений, разбирает по-одному (потому, что между словами есть символы из других чарсетов).
std::vector <CString> CConfig::OtupyachitText ( CString sText )
{
	CString sAlphabet = m_sEngAlphabetLower + m_sEngAlphabetUpper + m_sRusAlphabetUpper + m_sRusAlphabetLower;
	CString sResult ( L"" );
	std::vector <CString> svResult;
	CString sSymbol ( L"" );
	CString sSubstring ( L"" );

	// Флаг нового предложения. Служит для делания первой буквы заглавной
	bool bNewSentance = TRUE;

	while ( !sText.IsEmpty() )
	{
		// Проверяем, к какому набору относится следующий символ
		// После этого выделяем эту подстроку полностью
		sSymbol.Empty();
		sSymbol.AppendChar ( sText[0] );
		sSymbol.MakeLower();
		MakeLowerRus ( &sSymbol );
		if ( !sSymbol.FindOneOf ( m_sSeparatorsNotForChange ) )
		{
			// Если неизменяемый разделитель - ничего не делаем
			sSubstring = sText.SpanIncluding ( m_sSeparatorsNotForChange );
			sText.Delete ( 0, sSubstring.GetLength() );
			svResult.push_back( sSubstring );
		}
		else if ( !sSymbol.FindOneOf ( m_sSeparatorsChangeable ) )
		{
			// Если изменяемый разделитель - изменяем
			sSubstring = sText.SpanIncluding ( m_sSeparatorsChangeable );
			sText.Delete ( 0, sSubstring.GetLength() );
			CheckAndChangeSubstring ( &sSubstring );
			//sResult += sSubstring;
			svResult.push_back (sSubstring);

			bNewSentance = TRUE;
		}
		else if ( !sSymbol.FindOneOf ( m_sRusAlphabetLower + m_sEngAlphabetLower ) )
		{
			// Если буква из алфавита - изменяем и пробуем вставить перед словом рандомную
			// вставку
			sSubstring = sText.SpanIncluding ( sAlphabet );
			sText.Delete ( 0, sSubstring.GetLength() );
			CheckAndChangeSubstring ( &sSubstring );

			// Количество символов, добавленных рандомной вставкой
			DWORD dwSymbAdded = 0;

			// Если слово не меньше заданного кол-ва символов - то пробуем сделать вставку
			if ( sSubstring.GetLength() >= m_dwMinLengthForAddition )
			{
				UINT unAmount = GenerateAdditionsAmount ();
				if ( (dwSymbAdded = GenerateAdditions ( &sSubstring, unAmount )) && bNewSentance == TRUE )
					bNewSentance = FALSE;
			}

			// Все дальнейшее имеет смысл только если получилась не нулевая строка
			if ( !sSubstring.IsEmpty() )
			{
				// Проверим, не было ли до этого вставки, и не различается ли
				// она регистром с измененным словом. Если различается - изменяем регистр
				// измененного слова
				sSymbol.Empty();
				if ( dwSymbAdded )
				{
					sSymbol.AppendChar ( sSubstring.GetAt ( dwSymbAdded - 1 ) );

					if ( sSymbol.FindOneOf ( m_sRusAlphabetUpper + m_sEngAlphabetUpper ) != -1 )
					{
						CString sWord ( sSubstring.Right ( sSubstring.GetLength() - dwSymbAdded ));
						sSubstring.Delete( dwSymbAdded, sSubstring.GetLength() - dwSymbAdded );
						sWord.MakeUpper();
						MakeUpperRus ( &sWord );
						sSubstring += sWord;
					}
					else if ( sSymbol.FindOneOf ( m_sRusAlphabetLower + m_sEngAlphabetLower ) != -1 )
					{
						CString sWord ( (LPCTSTR) sSubstring );
						sSubstring.Delete( dwSymbAdded, sSubstring.GetLength() - dwSymbAdded );
						sWord.MakeLower();
						MakeLowerRus ( &sWord );
						sSubstring += sWord;
					}
				}
				else if ( bNewSentance )
				{
					// Если это новое предложение - то делаем 1-ю букву большой
					CString sFirstLetter ( L"" );
					sFirstLetter.AppendChar ( sSubstring[0] );
					sFirstLetter.MakeUpper();
					MakeUpperRus ( &sFirstLetter );
					sSubstring.SetAt ( 0, sFirstLetter[0] );
				}

				// Добавим шанс, что слово будет заглавными
				CRandomGenerator RNG;
				if ( RNG.ChanceChecker ( m_fCapitalizationChance ) )
				{
					sSubstring.MakeUpper();
					MakeUpperRus ( &sSubstring );
				}

				svResult.push_back (sSubstring);
			}

			bNewSentance = FALSE;
		}
		else if ( !sSymbol.FindOneOf ( m_sNumber ) )
		{
			// Если цифра - тогда если больше опред. значения - то меняем
			sSubstring = sText.SpanIncluding ( m_sNumber );
			sText.Delete ( 0, sSubstring.GetLength() );
			if ( _wtof( (LPCTSTR) sSubstring ) >= m_fNumToRep )
			{
				CRandomGenerator RNG;

				if ( RNG.ChanceChecker ( m_fNumRepChance ) )
					sSubstring = m_sNumRepString;
			}
			svResult.push_back (sSubstring);
		}
		else
		{
			// Если ни один из наборов - тупо копируем без изменений
			sSubstring = sText.SpanExcluding ( sAlphabet + m_sSeparatorsChangeable + m_sSeparatorsNotForChange );
			sText.Delete ( 0, sSubstring.GetLength() );
			svResult.push_back (sSubstring);
		}
	}

	return svResult;
}

std::vector <CString> CConfig::GenerateText ( DWORD dwZlogenAmount )
{
	std::vector <CString> svResult;
	CString	sOneString;

	for ( UINT i = 0 ; i < dwZlogenAmount ; i++ )
	{
		sOneString = L"";
		GenerateAdditions ( &sOneString, 1 );
		svResult.push_back ( sOneString );
	}

	return svResult;
}

// Расстановка тэгов по вектору строк
std::vector <CString> CConfig::AddTags ( std::vector <CString> svVector )
{
	std::vector <CString> svResult;

	CString sSubstring ( L"" );

	std::vector <UINT> vecnOpenedTags;

	for ( int j = 0 ; j < svVector.size() ; j++ )
	{
		// Проверяем, к какому набору относится следующий символ
		// После этого выделяем эту подстроку полностью
		// Если слово - тогда есть шанс что мы вставим перед ним тэг (или несколько)

		sSubstring = svVector.at( j );

		CRandomGenerator RNG;

		// unWhere - чтобы, если уже был вставлен тэг перед этим словом,
		// вставлять не до него, а после
		UINT unWhere = 0;

		// Перед каждым элементом массива имеется некоторый шанс, что тэг(и) откроется
		// Проверяем все тэги, которые не открыты
		for ( UINT i = 0 ; i < m_Tags.size() ; i++ )
		{
			if ( !m_Tags[i].IsOpened() )
			{
				if ( RNG.ChanceChecker ( m_Tags[i].GetOpenTagChance() ) )
				{
					sSubstring.Insert ( unWhere, m_Tags[i].GetOpenTag() );

					// Заносим индекс вставленного тэга, чтобы правильно закрывать их
					vecnOpenedTags.push_back ( i );
					m_Tags[i].SetStatus ( TRUE );

					// Смещение следующей вставки на длину вставленного тэга
					unWhere += m_Tags[i].GetOpenTag().GetLength();
				}
			}
		}

		// После каждого слова имеется некоторый шанс, что тэг(и) закроется

		UINT unQuantOpenedTags = vecnOpenedTags.size();
		while ( unQuantOpenedTags )
		{
			// Эта страшная конструкция - взятие сначала последнего элемента из вектора
			// открытых тэгов. Там элементы - это идексы открытых тэгов из вектора тэгов
			// То есть можно взять эл-т из вектора тэгов по этому индексу - и получим нужный тэг
			if ( RNG.ChanceChecker ( m_Tags[ vecnOpenedTags[vecnOpenedTags.size() - 1] ].GetCloseTagChance() ) )
			{
				sSubstring.Insert ( sSubstring.GetLength(), m_Tags[ vecnOpenedTags[vecnOpenedTags.size() - 1] ].GetCloseTag() );
				m_Tags[ vecnOpenedTags[vecnOpenedTags.size() - 1] ].SetStatus( FALSE );
				vecnOpenedTags.pop_back();
				unQuantOpenedTags--;
			}
			else
				unQuantOpenedTags = 0;
		}

		svResult.push_back( sSubstring );
	}

	// Нужно закрыть все открытые теги. В этот раз без шансов

	UINT unQuantOpenedTags = vecnOpenedTags.size();
	while ( unQuantOpenedTags )
	{
		svResult.push_back ( m_Tags[ vecnOpenedTags[vecnOpenedTags.size() - 1] ].GetCloseTag() );
		m_Tags[ vecnOpenedTags[vecnOpenedTags.size() - 1] ].SetStatus( FALSE );
		vecnOpenedTags.pop_back();
		unQuantOpenedTags--;
	}

	return svResult;
}

CString CConfig::VectorToString ( std::vector <CString> svVector )
{
	CString sResult ( L"" );
	
	for ( int i = 0 ; i < svVector.size() ; i++ )
	{
		sResult += svVector.at(i);
	}

	return sResult;
}