// Copyright (C) 2009 Blade <rygzengrho@yandex.ru>
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

#include "Config.h"
#include <QTextCodec>

CConfig::CConfig(void)
{
    m_fCapitalizationChance = 0;
    m_f3AdditionsChance = 0;
    m_f2AdditionsChance = 0;
    m_f1AdditionChance = 0;
    m_fNumToRep = 0;
    m_sNumRepString = "";
    m_fNumRepChance = 0;
    m_ulMinLengthForAddition = 0;

    ResetStrings();
}

CConfig::~CConfig(void)
{
}

void CConfig::ResetStrings()
{
    // Не стоит забывать о том, что это - по-сути чарсеты и используются в регулярных выражениях, так что необходимо делать экранировку спецсимволов
    m_sComment = "/";
    m_sBlockCommentSymbol = "\\*";
    m_sEndSymbol = "\n";
    m_sSpaces = " \t";
    m_sEquals = "=";
    m_sStringID = "\"";
    m_sMacroID = "*";
    m_sStyleID = "&";
    m_sChanceSeparator = ":";
    m_sResultsSeparator = ",";
    m_sNumber = "1234567890";
    m_sDecimalPoint = ".";
    m_sEngAlphabetLower = "abcdefghijklmnopqrstuvwxyz";
    m_sEngAlphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    m_sRusAlphabetLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    m_sRusAlphabetUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    m_sDash = ( "\\-" );
    m_sSeparatorsNotForChange = ",;:'`\"~$%\\^&*\\(\\)_=+/<>{}\\[\\]№";
    m_sSeparatorsChangeable = ".!?";
    m_sRandAddID = "~";
    m_sTagID = "|";

    // Tags
    m_sUpMacro = "UP";
    m_sSaveMacro = "SAVE";
}

// Функция выделяет подстроку до заданного символа, после чего обрезает символы из m_sSpaces справа и слева и возвращает полученную подстроку
// Из исходной строки удаляются первые n символов, где n - длина выделенной строки
QString CConfig::ParseString( QString* String, const QString sWhereToStop, bool* ok ) const
{
    QString sResult = String->left ( String->indexOf( QRegExp ( "[" + sWhereToStop + m_sEndSymbol + "]" ) ));
    String->remove( 0, sResult.length() );
    sResult.remove ( QRegExp ( "(^[" + m_sSpaces + "]*)|([" + m_sSpaces + "]*$)" ) );

    if ( sResult.isEmpty() )
    {
	if (ok)
	    *ok = false;
    }

    return sResult;
}

// Функция выделяет подстроку, находящуюся между ограничительных символов, и возвращает ее
// Из исходной строки удаляется слева все до второго ограничительного символа, включительно
QString CConfig::ParseStringDelim( QString* String, const QString sDelimiters, bool* ok ) const
{
    String->remove ( QRegExp ( "^[^" + sDelimiters + m_sEndSymbol + "]*" ));
    String->remove ( 0, 1 );
    QString sResult = String->left ( String->indexOf( QRegExp ( "[" + sDelimiters + m_sEndSymbol + "]" ) ));
    String->remove( 0, sResult.length() + 1 );

    if ( sResult.isEmpty() )
    {
	if (ok)
	    *ok = false;
    }

    return sResult;
}

// Функция ищет число в строке, парсит его как целое и возвращает полученное значение
// Из исходной строки удаляются первые n символов, где n - длина выделенной строки
uint CConfig::ParseUInt( QString* String, bool* ok ) const
{
    String->remove ( QRegExp ( "^[^" + m_sNumber + m_sEndSymbol + "]*" ));
    QString sSubstring = String->left ( String->indexOf( QRegExp ( "[^" + m_sNumber + m_sDecimalPoint + m_sEndSymbol + "]" ) ));
    String->remove( 0, sSubstring.length() );
    if ( sSubstring.isEmpty() )
    {
	*ok = false;
	return 0;
    }
    else
	return sSubstring.toInt( ok, 10 );
}

// Функция ищет число в строке, парсит его как число с плавающей запятой и возвращает полученное значение
// Из исходной строки удаляются первые n символов, где n - длина выделенной строки
float CConfig::ParseFloat( QString* String, bool* ok ) const
{
    String->remove ( QRegExp ( "^[^" + m_sNumber + m_sDecimalPoint + m_sEndSymbol + "]*" ));
    QString sSubstring = String->left ( String->indexOf( QRegExp ( "[^" + m_sNumber + m_sDecimalPoint + m_sEndSymbol + "]" ) ));
    String->remove( 0, sSubstring.length() );
    if ( sSubstring.isEmpty() )
    {
	*ok = false;
	return 0;
    }
    else
	return sSubstring.toFloat( ok );
}

// Хинт:
// sConfig->contains( QRegExp ( "^[" + chars + "]" ) ); - проверка на то, что первый символ есть в наборе chars
// sSubstring = sConfig->left ( sConfig->indexOf( QRegExp ( "[" + chars + "]" ) )); - Выбор всего из строки до тех пор, пока не встретятся заданные символы. Замена SpanExcluding
// sSubstring = sConfig->left ( sConfig->indexOf( QRegExp ( "[^" + chars + "]" ) )); - Выбор всего из строки до тех пор, пока не встретятся символы, отличные от заданных. Замена SpanIncluding
// sConfig->remove ( QRegExp ( "^[^" + chars + "]*" )); - удаление ненужных символов до тех пор, пока не встретим символ из chars
// sSubstring.remove ( QRegExp ( "(^[" + chars + "]*)|([" + chars + "]*$)" ) ) - Удаление символов chars из начала и из конца. Замена Trim

bool CConfig::ParseConfig( QString* sConfig )
{
    // Строка для хранения значения предыдущей парсимой строки в случае замен. Используется для макроса *UP*
    QString sPrevious ( "" );

    // Флаг того, что произошла какая-то ошибка и что нужно вывести пользователю предупреждение
    bool	bWarning = false;

    m_Style.Clear();

    while ( !sConfig->isEmpty() )
    {
	// Проверяем, к какому набору относится следующий символ
	// После этого выделяем эту подстроку полностью

	qDebug() << "ParseConfig current line: " + sConfig->left( sConfig->indexOf( QRegExp ( "[" + m_sEndSymbol + "]" )));

	// Если это коммент в одну строку (2 символа m_sComment подряд) - тогда забиваем на все до конца строки
	if ( sConfig->contains( QRegExp ( "^" + m_sComment.repeated(2) + "" )))
	{
	    // На случай, если это последняя строка в файле и после нее нет символа конца строки
	    int nCount = sConfig->indexOf( QRegExp ( "[" + m_sEndSymbol + "]" ));
	    if ( nCount == -1 )
		nCount = sConfig->length();

	    sConfig->remove ( 0, nCount + 1 );
	}
	// Если это блоковый коммент (начинается с "m_sComment + m_sBlockCommentSymbol" и заканчивается "m_sBlockCommentSymbol + m_sComment") - тогда забиваем на все, что внутри
	else if ( sConfig->contains( QRegExp ( "^" + m_sComment + m_sBlockCommentSymbol + "" )) )
	{
	    // Если закрывающих символов нет - считаем, что коммент - это все до конца файла
	    int nCount = sConfig->indexOf( QRegExp ( "" + m_sBlockCommentSymbol + m_sComment + "" ) );
	    if ( nCount == -1 )
		nCount = sConfig->length();

	    sConfig->remove ( 0, nCount + 1 );
	}
	// Если есть символы отступа - отбрасываем их
	else if ( sConfig->contains( QRegExp ( "^[" + m_sSpaces + "]" ) ) )
	{
	    sConfig->remove ( QRegExp ( "^[" + m_sSpaces + "]*" ) );
	}
	// Если символ конца - тупо переходим на след. строку
	else if ( sConfig->contains( QRegExp ( "^[" + m_sEndSymbol + "]" ) ))
	{
	    sConfig->remove ( 0, 1 );
	}
	// Если символ из алфавита без указателя строки - парсим как переменную
	else if ( sConfig->contains ( QRegExp ( "^[" + m_sEngAlphabetLower + m_sEngAlphabetUpper + "]" ) ))
	{
	    bool ok = true;

	    QString sLine = sConfig->left ( sConfig->indexOf( QRegExp ( "[" + m_sEndSymbol + "]" ) ));
	    sConfig->remove ( 0, sLine.length() + 1 );

	    QString sSubstring = ParseString ( &sLine, m_sEquals, &ok );

	    qDebug() << "ParseConfig var name: " + sSubstring;

	    // Отрезаем знак равенства
	    sLine.remove( 0, sLine.indexOf(  QRegExp ( "[" + m_sEquals + "]" ) ) + 1 );

	    if ( sSubstring == "Capitalization Chance" )
	    {
		float fResult = ParseFloat ( &sLine, &ok );
		if ( ok )
		    m_fCapitalizationChance = fResult;
		else
		    bWarning = true;
	    }
	    else if ( sSubstring == "Three Additions Chance" )
	    {
		float fResult = ParseFloat ( &sLine, &ok );
		if ( ok )
		    m_f3AdditionsChance = fResult;
		else
		    bWarning = true;
	    }
	    else if ( sSubstring == "Two Additions Chance" )
	    {
		float fResult = ParseFloat ( &sLine, &ok );
		if ( ok )
		    m_f2AdditionsChance = fResult;
		else
		    bWarning = true;
	    }
	    else if ( sSubstring == "One Addition Chance" )
	    {
		float fResult = ParseFloat ( &sLine, &ok );
		if ( ok )
		    m_f1AdditionChance = fResult;
		else
		    bWarning = true;
	    }
	    else if ( sSubstring == "Number To Replace" )
	    {
		float fResult = ParseFloat ( &sLine, &ok );
		if ( ok )
		    m_fNumToRep = fResult;
		else
		    bWarning = true;
	    }
	    else if ( sSubstring == "Number Replacement String" )
	    {
		sSubstring = ParseString ( &sLine, m_sEndSymbol, &ok );
		if ( ok )
		    m_sNumRepString = sSubstring;
		else
		    bWarning = true;
	    }
	    else if ( sSubstring == "Number Replacement Chance" )
	    {
		float fResult = ParseFloat ( &sLine, &ok );
		if ( ok )
		    m_fNumRepChance = fResult;
		else
		    bWarning = true;
	    }
	    else if ( sSubstring == "Min Word Length For Addition" )
	    {
		uint unResult = ParseUInt ( &sLine, &ok );
		if ( ok )
		    m_ulMinLengthForAddition = unResult;
		else
		    bWarning = true;
	    }
	}
	// Если указатель на то, что будет строка -
	// тогда парсим как действительно нужное нам выражение
	else if ( sConfig->contains( QRegExp ( "^[" + m_sStringID + "]" ) ) )
	{
	    CReplacer   TempReplacer;
	    bool ok = true;

	    QString sLine = sConfig->left ( sConfig->indexOf( QRegExp ( "[" + m_sEndSymbol + "]" ) ));
	    sConfig->remove ( 0, sLine.length() + 1 );

	    // Сначала копируем заменяемую строку
	    QString sSubstring = ParseStringDelim ( &sLine, m_sStringID, &ok );

	    qDebug() << "ParseConfig replacer string to change: " + sSubstring;

	    if ( ok )
		TempReplacer.SetStrToChange ( sSubstring );
	    else
		bWarning = true;

	    // Потом ищем начало строки, на которую возможна замена
	    bool bMacro = false;
	    QString sDelimiter = m_sStringID + m_sMacroID;	    
	    sLine.remove ( QRegExp ( "^[^" + sDelimiter + "]*" ));

	    if ( sLine.contains( QRegExp ( "^[" + m_sMacroID + "]" ) ) )
		bMacro = true;

	    // Проверяем, не является ли строка замены макросом
	    if ( bMacro )
	    {
		sSubstring = sLine;
		sSubstring = ParseStringDelim ( &sSubstring, m_sMacroID, &ok );
		if ( sSubstring == m_sUpMacro )
		{
		    // Копируем предыдущую строку результатов и ее обрабатываем
		    // TODO: Поменять на копирование значений из пред. элемента вектора
		    sLine = sPrevious;
		}
		else if ( sSubstring == m_sSaveMacro )
		{
		    // Делаем шанс замены равным нулю и сразу записываем в вектор замен
		    sLine.clear();
		    TempReplacer.SetResult ( TempReplacer.GetStrToChange(), 0 );
		}
	    }
	    else
	    {
		// Используем эту строку
		sPrevious = sLine;
	    }

	    // Средний шанс вставки
	    float fAverageChance;
	    fAverageChance = 100 / (sLine.count( m_sResultsSeparator ) + 1);

	    // Идем пока не кончится строка, пока не соберем все варианты замены
	    while ( !sLine.isEmpty() )
	    {
		// Сначала идет название результата
		QString sNewResult;

		sSubstring = ParseStringDelim ( &sLine, m_sStringID, &ok );
		if ( ok )
		    sNewResult = sSubstring;

		qDebug() << "ParseConfig replacement string: " + sSubstring;

		// Обрезаем лишнее до шанса, или до следующего
		sLine.remove ( QRegExp ( "^[^" + m_sNumber + m_sStringID + m_sEndSymbol + "]*" ));

		// Потом идет шанс
		sSubstring = sLine.left ( sLine.indexOf( QRegExp ( "[^" + m_sNumber + m_sDecimalPoint + "]" ) ));

		qDebug() << "ParseConfig replacement chance: " + sSubstring;

		float fNewChance;

		if ( sSubstring.isEmpty() )
		{
		    // Если шанс явно не указан - делаем его равным среднему значению
		    fNewChance = fAverageChance;
		}
		else
		    fNewChance = sSubstring.toFloat( );

		//Добавляем во временную переменную
		TempReplacer.SetResult ( sNewResult, fNewChance );

		// Обрезаем лишнее
		sLine.remove ( QRegExp ( "^[^" + m_sStringID + m_sEndSymbol + "]*" ));
	    }
	    m_Replacer.push_back ( TempReplacer );
	}
	// Случайная вставка
	else if ( sConfig->contains( QRegExp ( "^[" + m_sRandAddID + "]" ) ) )
	{
	    // Эл-т для рандомной вставки
	    CRandomAdder	TempRandAdder;

	    bool ok = true;

	    QString sLine = sConfig->left ( sConfig->indexOf( QRegExp ( "[" + m_sEndSymbol + "]" ) ));
	    sConfig->remove ( 0, sLine.length() + 1 );

	    QString sSubstring = ParseStringDelim ( &sLine, m_sRandAddID, &ok );

	    qDebug() << "ParseConfig random addition string: " + sSubstring;

	    if ( ok )
		TempRandAdder.SetStrToAdd ( sSubstring );
	    else
		bWarning = true;

	    // Шанс вставки по-умолчанию
	    const float fDefaultChance = 1;

	    float fNewChance = ParseFloat ( &sLine, &ok );

	    qDebug() << "ParseConfig random addition chance: " + QString( "%1" ).arg( fNewChance );

	    if ( !ok )
		// Если шанс явно не указан - делаем его равным дефолтному значению
		TempRandAdder.SetChance ( fDefaultChance );
	    else
		TempRandAdder.SetChance ( fNewChance );

	    m_RandomAdder.push_back ( TempRandAdder );
	}
	// Тэг
	else if ( sConfig->contains( QRegExp ( "^[" + m_sTagID + "]" ) ) )
	{
	    bool ok = true;

	    QString sLine = sConfig->left ( sConfig->indexOf( QRegExp ( "[" + m_sEndSymbol + "]" ) ));
	    sConfig->remove ( 0, sLine.length() + 1 );

	    CTags TempTag;
	    uint unTagGroup = 0;

	    QString sSubstring = sLine;

	    // Сначала считываем инфу о группе тэга
	    sSubstring.remove( 0, 1 );
	    sSubstring = sSubstring.left ( sSubstring.indexOf( QRegExp ( "[^" + m_sNumber + "]" ) ));
	    if ( !sSubstring.isEmpty() )
	    {
		unTagGroup = sSubstring.toUInt();
		// Если явно указана группа тегов - значит в исходной строке необходимоее удалить, чтобы она не мешалась
		sLine.remove( QRegExp ( "^[^" + m_sNumber + "]*" ) );
		sLine.remove( QRegExp ( "^[" + m_sNumber + "]*" ) );
	    }

	    // Считываем открывающий тэг
	    sSubstring = ParseStringDelim ( &sLine, m_sTagID, &ok );

	    qDebug() << "ParseConfig open tag: " + sSubstring;

	    if ( ok )
		TempTag.SetOpenTag ( sSubstring );

	    // Потом идет шанс того, что тэг откроется
	    float fNewChance = ParseFloat ( &sLine, &ok );

	    qDebug() << "ParseConfig open tag chance: " + QString( "%1" ).arg( fNewChance );

	    if ( ok )
		TempTag.SetOpenTagChance ( fNewChance );
	    else
	    {
		TempTag.SetOpenTagChance ( 0 );
		bWarning = true;
	    }

	    // Потом закрывающий тэг
	    sSubstring = ParseStringDelim ( &sLine, m_sTagID, &ok );

	    qDebug() << "ParseConfig close tag: " + sSubstring;

	    if ( ok )
		TempTag.SetCloseTag ( sSubstring );

	    // Потом идет шанс того, что тэг закроется
	    fNewChance = ParseFloat ( &sLine, &ok );

	    qDebug() << "ParseConfig close tag chance: " + QString( "%1" ).arg( fNewChance );

	    if ( ok )
		TempTag.SetCloseTagChance ( fNewChance );
	    else
	    {
		TempTag.SetCloseTagChance ( 0 );
		bWarning = true;
	    }

	    // Тут мы проверяем, не выходит ли номер группы из конфига за пределы вектора.
	    // Если нет - то просто записываем в элемент вектора с нужным номером еще одно значение тэга
	    if ( m_TagsVec.size() > (int) unTagGroup )
		m_TagsVec[unTagGroup].m_TagsVector.push_back( TempTag );
	    else
	    {
		// Если выходит - то мы выделяем память для нужного количества элементов в векторе
		for ( int i = m_TagsVec.size() ; i < (int) unTagGroup - 1 ; i++ )
		    m_TagsVec.push_back( CTagsVector ());
		// И в последний записываем значение тэга
		m_TagsVec.push_back( CTagsVector ( &TempTag ));
	    }
	}
	// Стиль
	else if ( sConfig->contains( QRegExp ( "^[" + m_sStyleID + "]" ) ) )
	{
	    bool ok = true;
	    QString sLine = sConfig->left ( sConfig->indexOf( QRegExp ( "[" + m_sEndSymbol + "]" ) ));
	    sConfig->remove ( 0, sLine.length() + 1 );

	    // Считываем открывающий тэг
	    QString sSubstring = ParseStringDelim ( &sLine, m_sStyleID, &ok );

	    qDebug() << "ParseConfig style open tag: " + sSubstring;

	    if ( ok )
		m_Style.SetOpenTag ( sSubstring );

	    // Потом закрывающий тэг
	    sSubstring = ParseStringDelim ( &sLine, m_sStyleID, &ok );

	    qDebug() << "ParseConfig style close tag: " + sSubstring;

	    if ( ok )
		m_Style.SetCloseTag ( sSubstring );

	    // Нам не важны шансы, так как стили применяются всегда
	}
	else
	    sConfig->remove ( 0, 1 );
    }

    if ( bWarning )
	return true;
    else
	return false;
}

// Очистка конфига
void CConfig::Clear ()
{
    m_fCapitalizationChance = 0;
    m_f3AdditionsChance = 0;
    m_f2AdditionsChance = 0;
    m_f1AdditionChance = 0;
    m_fNumToRep = 0;
    m_sNumRepString = "";
    m_fNumRepChance = 0;
    m_ulMinLengthForAddition = 0;

    m_Replacer.clear();
    m_RandomAdder.clear();
    this->m_TagsVec.clear();
}

// Дефолтные QString-овские toLower и toUpper не умеют работать
// с русскими буквами
void CConfig::MakeLowerRus ( QString* sString )
{
     for ( int i = 0 ; i < sString->length() ; i++ )
    {
	if ( sString->at(i) == 'А' )
	    (*sString)[i] = 'а';
	else if ( sString->at(i) == 'Б' )
	    (*sString)[i] = 'б';
	else if ( sString->at(i) == 'В' )
	    (*sString)[i] = 'в';
	else if ( sString->at(i) == 'Г' )
	    (*sString)[i] = 'г';
	else if ( sString->at(i) == 'Д' )
	    (*sString)[i] = 'д';
	else if ( sString->at(i) == 'Е' )
	    (*sString)[i] = 'е';
	else if ( sString->at(i) == 'Ё' )
	    (*sString)[i] = 'ё';
	else if ( sString->at(i) == 'Ж' )
	    (*sString)[i] = 'ж';
	else if ( sString->at(i) == 'З' )
	    (*sString)[i] = 'з';
	else if ( sString->at(i) == 'И' )
	    (*sString)[i] = 'и';
	else if ( sString->at(i) == 'Й' )
	    (*sString)[i] = 'й';
	else if ( sString->at(i) == 'К' )
	    (*sString)[i] = 'к';
	else if ( sString->at(i) == 'Л' )
	    (*sString)[i] = 'л';
	else if ( sString->at(i) == 'М' )
	    (*sString)[i] = 'м';
	else if ( sString->at(i) == 'Н' )
	    (*sString)[i] = 'н';
	else if ( sString->at(i) == 'О' )
	    (*sString)[i] = 'о';
	else if ( sString->at(i) == 'П' )
	    (*sString)[i] = 'п';
	else if ( sString->at(i) == 'Р' )
	    (*sString)[i] = 'р';
	else if ( sString->at(i) == 'С' )
	    (*sString)[i] = 'с';
	else if ( sString->at(i) == 'Т' )
	    (*sString)[i] = 'т';
	else if ( sString->at(i) == 'У' )
	    (*sString)[i] = 'у';
	else if ( sString->at(i) == 'Ф' )
	    (*sString)[i] = 'ф';
	else if ( sString->at(i) == 'Х' )
	    (*sString)[i] = 'х';
	else if ( sString->at(i) == 'Ц' )
	    (*sString)[i] = 'ц';
	else if ( sString->at(i) == 'Ч' )
	    (*sString)[i] = 'ч';
	else if ( sString->at(i) == 'Ш' )
	    (*sString)[i] = 'ш';
	else if ( sString->at(i) == 'Щ' )
	    (*sString)[i] = 'щ';
	else if ( sString->at(i) == 'Ъ' )
	    (*sString)[i] = 'ъ';
	else if ( sString->at(i) == 'Ы' )
	    (*sString)[i] = 'ы';
	else if ( sString->at(i) == 'Ь' )
	    (*sString)[i] = 'ь';
	else if ( sString->at(i) == 'Э' )
	    (*sString)[i] = 'э';
	else if ( sString->at(i) == 'Ю' )
	    (*sString)[i] = 'ю';
	else if ( sString->at(i) == 'Я' )
	    (*sString)[i] = 'я';
    }
}

void CConfig::MakeUpperRus ( QString* sString )
{
    for ( int i = 0 ; i < sString->length() ; i++ )
    {
	if ( sString->at(i) == 'а' )
	    (*sString)[i] = 'А';
	else if ( sString->at(i) == 'б' )
	    (*sString)[i] = 'Б';
	else if ( sString->at(i) == 'в' )
	    (*sString)[i] = 'В';
	else if ( sString->at(i) == 'г' )
	    (*sString)[i] = 'Г';
	else if ( sString->at(i) == 'д' )
	    (*sString)[i] = 'Д';
	else if ( sString->at(i) == 'е' )
	    (*sString)[i] = 'Е';
	else if ( sString->at(i) == 'ё' )
	    (*sString)[i] = 'Ё';
	else if ( sString->at(i) == 'ж' )
	    (*sString)[i] = 'Ж';
	else if ( sString->at(i) == 'з' )
	    (*sString)[i] = 'З';
	else if ( sString->at(i) == 'и' )
	    (*sString)[i] = 'И';
	else if ( sString->at(i) == 'й' )
	    (*sString)[i] = 'Й';
	else if ( sString->at(i) == 'к' )
	    (*sString)[i] = 'К';
	else if ( sString->at(i) == 'л' )
	    (*sString)[i] = 'Л';
	else if ( sString->at(i) == 'м' )
	    (*sString)[i] = 'М';
	else if ( sString->at(i) == 'н' )
	    (*sString)[i] = 'Н';
	else if ( sString->at(i) == 'о' )
	    (*sString)[i] = 'О';
	else if ( sString->at(i) == 'п' )
	    (*sString)[i] = 'П';
	else if ( sString->at(i) == 'р' )
	    (*sString)[i] = 'Р';
	else if ( sString->at(i) == 'с' )
	    (*sString)[i] = 'С';
	else if ( sString->at(i) == 'т' )
	    (*sString)[i] = 'Т';
	else if ( sString->at(i) == 'у' )
	    (*sString)[i] = 'У';
	else if ( sString->at(i) == 'ф' )
	    (*sString)[i] = 'Ф';
	else if ( sString->at(i) == 'х' )
	    (*sString)[i] = 'Х';
	else if ( sString->at(i) == 'ц' )
	    (*sString)[i] = 'Ц';
	else if ( sString->at(i) == 'ч' )
	    (*sString)[i] = 'Ч';
	else if ( sString->at(i) == 'ш' )
	    (*sString)[i] = 'Ш';
	else if ( sString->at(i) == 'щ' )
	    (*sString)[i] = 'Щ';
	else if ( sString->at(i) == 'ъ' )
	    (*sString)[i] = 'Ъ';
	else if ( sString->at(i) == 'ы' )
	    (*sString)[i] = 'Ы';
	else if ( sString->at(i) == 'ь' )
	    (*sString)[i] = 'Ь';
	else if ( sString->at(i) == 'э' )
	    (*sString)[i] = 'Э';
	else if ( sString->at(i) == 'ю' )
	    (*sString)[i] = 'Ю';
	else if ( sString->at(i) == 'я' )
	    (*sString)[i] = 'Я';
    }
}

bool CConfig::CheckAndChangeSubstring ( QString* sStrToCheck )
{
    int nIndex = 0;

    for ( ; nIndex < m_Replacer.size() && !m_Replacer.isEmpty() ; nIndex++ )
    {
	QString sStrToCompareWith = m_Replacer[nIndex].GetStrToChange();

	if ( sStrToCheck->contains( QRegExp ( sStrToCompareWith, Qt::CaseInsensitive ) ))
	{
	    break;
	}
    }

    bool bNotChanged = true;

    if ( nIndex < m_Replacer.size() && !m_Replacer.isEmpty() )
    {
	bNotChanged = AttemptToChangeString ( sStrToCheck, nIndex );
    }

    return !bNotChanged;
}

// Функция перебирает шансы на замену и если этот шанс сбывается - обрабатывает строку
bool CConfig::AttemptToChangeString ( QString* String, int nIndex )
{
    float fRandNum = CRandomGenerator::GenerateNumber( 0, 100 );

    float fSumm = 0;

    for ( int i = 0 ; i < m_Replacer[nIndex].Size() && fSumm <= 100 ; i++ )
    {
	fSumm += m_Replacer[nIndex].GetResultChance( i );

	if ( fRandNum <= fSumm )
	{
	    QRegExp RegExp( m_Replacer[nIndex].GetStrToChange() );
	    RegExp.setCaseSensitivity( Qt::CaseInsensitive );
	    String->replace( RegExp, m_Replacer[nIndex].GetResultString( i ) );
	    return false;
	}
    }

    return true;
}

// Функция проверяет шансы на добавление рандомной вставки (или нескольких)
// Сначала проверются шансы на то, сколько вставок будет сделано, в порядке убывания
// Потом, исходя из этого количества, генерируется такое кол-во вставок
// Возвращает 0 в случае успешного добавления вставки
uint CConfig::GenerateAdditionsAmount () const
{
    uint unAmount = 0;

    if ( CRandomGenerator::CheckChance ( m_f3AdditionsChance ) )
	unAmount = 3;
    else
    {
	if ( CRandomGenerator::CheckChance ( m_f2AdditionsChance ) )
	    unAmount = 2;
	else
	{
	    if ( CRandomGenerator::CheckChance ( m_f1AdditionChance ) )
		unAmount = 1;
	}
    }

    return unAmount;
}

// Главная функция. Идет по тексту, проверяет его посимвольно на принадлежность к разным
// группам символов из чарсетов. Группирует по чарсетам. Слова, что логично их двух предыдущих
// предложений, разбирает по-одному (потому, что между словами есть символы из других чарсетов).
QVector <QString> CConfig::OtupyachitText ( QString sText )
{
    QString sAlphabet = m_sEngAlphabetLower + m_sEngAlphabetUpper + m_sRusAlphabetUpper + m_sRusAlphabetLower;
    QVector <QString> svResult;
    QString sSubstring ( "" );

    // Флаг нового предложения. Служит для делания первой буквы заглавной
    bool bNewSentance = true;

    while ( !sText.isEmpty() )
    {
	qDebug() << "OtupyachitText current line: " + sText.left( sText.indexOf( QRegExp ( "[" + m_sEndSymbol + "]" )));

	// Проверяем, к какому набору относится следующий символ
	// После этого выделяем эту подстроку полностью
	if ( sText.contains( QRegExp ( "^[" + m_sSeparatorsNotForChange + "]" ) ) )
	{
	    // Если неизменяемый разделитель - ничего не делаем
	    sSubstring = sText.left ( sText.indexOf( QRegExp ( "[^" + m_sSeparatorsNotForChange + m_sDash + "]" ) ));
	    sText.remove ( 0, sSubstring.length() );
	    svResult.push_back( sSubstring );
	}
	else if ( sText.contains( QRegExp ( "^[" + m_sSeparatorsChangeable + "]" ) ) )
	{
	    // Если изменяемый разделитель - изменяем
	    sSubstring = sText.left ( sText.indexOf( QRegExp ( "[^" + m_sSeparatorsChangeable + "]" ) ));
	    sText.remove ( 0, sSubstring.length() );
	    CheckAndChangeSubstring ( &sSubstring );
	    svResult.push_back (sSubstring);

	    bNewSentance = true;
	}
	else if ( sText.contains( QRegExp ( "^[" + sAlphabet + "]" ) ) )
	{
	    // Если буква из алфавита - изменяем и пробуем вставить перед словом рандомную
	    // вставку
	    sSubstring = sText.left ( sText.indexOf( QRegExp ( "[^" + sAlphabet + m_sDash + "]" ) ));
	    sText.remove ( 0, sSubstring.length() );
	    CheckAndChangeSubstring ( &sSubstring );

	    // Количество символов, добавленных рандомной вставкой
	    long lSymbAdded = 0;

	    // Если слово не меньше заданного кол-ва символов - то пробуем сделать вставку
	    if ( sSubstring.length() >= int(m_ulMinLengthForAddition) )
	    {
		uint unAmount = GenerateAdditionsAmount ();
		lSymbAdded = GenerateAdditionsText ( &sSubstring, unAmount );
	    }

	    // Все дальнейшее имеет смысл только если получилась не нулевая строка
	    if ( !sSubstring.isEmpty() )
	    {
		// Проверим, не было ли до этого вставки, и не различается ли
		// она регистром с измененным словом. Если различается - изменяем регистр
		// измененного слова
		QString sSymbol;
		if ( lSymbAdded > 0 )
		{
		    sSymbol = sSubstring.at ( lSymbAdded - 1 );

		    if ( sSymbol.contains( QRegExp ( "^[" + m_sRusAlphabetUpper + m_sEngAlphabetUpper + "]" ) ) )
		    {
			QString sWord ( sSubstring.right ( sSubstring.length() - lSymbAdded ));
			sSubstring.remove( lSymbAdded, sSubstring.length() - lSymbAdded );
			sWord = sWord.toUpper();
			MakeUpperRus ( &sWord );
			sSubstring += sWord;
		    }
		    else if ( sSymbol.contains( QRegExp ( "^[" + m_sRusAlphabetLower + m_sEngAlphabetLower + "]" ) ))
		    {
			QString sWord ( sSubstring.right ( sSubstring.length() - lSymbAdded ));
			sSubstring.remove( lSymbAdded, sSubstring.length() - lSymbAdded );
			sWord = sWord.toLower();
			MakeLowerRus ( &sWord );
			sSubstring += sWord;
		    }
		}
		if ( bNewSentance )
		{
		    // Если это новое предложение - то делаем 1-ю букву большой
		    QString sLetter = sSubstring.left(1);
		    sLetter = sLetter.toUpper();
		    MakeUpperRus ( &sLetter );

		    sSubstring[0] = sLetter[0];
		}

		// Добавим шанс, что слово будет заглавными
		if ( CRandomGenerator::CheckChance( m_fCapitalizationChance ) )
		{
		    sSubstring = sSubstring.toUpper();
		    MakeUpperRus ( &sSubstring );
		}

		svResult.push_back (sSubstring);
	    }

	    bNewSentance = false;
	}
	else if ( sText.contains( QRegExp ( "^[" + m_sNumber + "]" ) ) )
	{
	    // Если цифра - тогда если больше опред. значения - то меняем
	    sSubstring = sText.left ( sText.indexOf( QRegExp ( "[^" + m_sNumber + m_sDecimalPoint + "]" ) ));
	    sText.remove ( 0, sSubstring.length() );
	    if ( sSubstring.toFloat() >= m_fNumToRep )
	    {
		if ( CRandomGenerator::CheckChance( m_fNumRepChance ) )
		    sSubstring = m_sNumRepString;
	    }
	    svResult.push_back (sSubstring);
	}
	else
	{
	    // Если ни один из наборов - тупо копируем без изменений
	    sSubstring = sText.left ( sText.indexOf( QRegExp ( "[" + sAlphabet + m_sSeparatorsChangeable + m_sSeparatorsNotForChange + "]" ) ));
	    sText.remove ( 0, sSubstring.length() );
	    svResult.push_back (sSubstring);
	}
    }
    return svResult;
}

// Генерирует определенное кол-во вставок и добавляет их в строку
// Возвращает кол-во вставленных символов, или -1 в случае ошибки
long CConfig::GenerateAdditionsText ( QString* sSubstring, uint unAmount )
{
    if ( !unAmount )
	return 0;

    // -1 means error
    long lSymbAdded = 0;

    float fSummaryChance = 0;

    for ( int nIndex = 0 ; nIndex < m_RandomAdder.size() ; nIndex++ )
	fSummaryChance += m_RandomAdder[nIndex].GetChance();

    if ( !fSummaryChance )
    {
	return -1;
    }

    while ( unAmount > 0 )
    {
	float fRandNum = CRandomGenerator::GenerateNumber( 0, fSummaryChance );
	float fSumm = 0;

	for ( int nIndex = 0 ; nIndex < m_RandomAdder.size() ; nIndex++ )
	{
	    fSumm += m_RandomAdder[nIndex].GetChance();

	    if ( fRandNum <= fSumm )
	    {
		sSubstring->insert( 0, m_RandomAdder[nIndex].GetStrToAdd() );

		qDebug() << "GenerateAdditionsText string with inserted addition: " + *sSubstring;

		lSymbAdded += m_RandomAdder[nIndex].GetStrToAdd().size();
		unAmount--;

		break;
	    }
	}
    }

    return lSymbAdded;
}

// Генерирует вектор из дополнений, сгенерированных функцией GenerateAdditionsText
QVector <QString> CConfig::GenerateAdditionsVector ( const ulong ulZlogenAmount )
{
    QVector <QString> svResult;
    QString sOneString;

    for ( uint i = 0 ; i < ulZlogenAmount ; i++ )
    {
	sOneString = "";
	GenerateAdditionsText ( &sOneString, 1 );
	svResult.push_back ( sOneString );
    }

    return svResult;
}

// Расстановка тэгов по вектору строк
QVector <QString> CConfig::AddTags ( QVector <QString>* svVector, const uint unTagsGroup )
{
    QVector <QString> svResult;

    QString sSubstring ( "" );

    QVector <uint> vecnOpenedTags;

    // Current tags group that we are using
    QVector <CTags> *Tags = &m_TagsVec[unTagsGroup].m_TagsVector;

    for ( int j = 0 ; j < svVector->size() ; j++ )
    {
	if ( !svVector->at(j).isEmpty() )
	{
	    // Проверяем, к какому набору относится следующий символ
	    // После этого выделяем эту подстроку полностью
	    // Если слово - тогда есть шанс что мы вставим перед ним тэг (или несколько)

	    sSubstring = (*svVector)[j];

	    // unWhere - чтобы, если уже был вставлен тэг перед этим словом,
	    // вставлять не до него, а после
	    uint unWhere = 0;

	    // Перед каждым элементом массива имеется некоторый шанс, что тэг(и) откроется
	    // Проверяем все тэги, которые не открыты
	    for ( int i = 0 ; i < Tags->size() ; i++ )
	    {
		if ( !(*Tags)[i].IsOpened() )
		{
		    if ( CRandomGenerator::CheckChance( (*Tags)[i].GetOpenTagChance() ) )
		    {
			sSubstring.insert( unWhere, (*Tags)[i].GetOpenTag() );

			// Заносим индекс вставленного тэга, чтобы правильно закрывать их
			vecnOpenedTags.push_back ( i );
			(*Tags)[i].SetStatus ( true );

			// Смещение следующей вставки на длину вставленного тэга
			unWhere += (*Tags)[i].GetOpenTag().size();
		    }
		}
	    }

	    // После каждого слова имеется некоторый шанс, что тэг(и) закроется

	    uint unQuantOpenedTags = vecnOpenedTags.size();

	    while ( unQuantOpenedTags )
	    {
		// Эта страшная конструкция - взятие сначала последнего элемента из вектора
		// открытых тэгов. Там элементы - это идексы открытых тэгов из вектора тэгов
		// То есть можно взять эл-т из вектора тэгов по этому индексу - и получим нужный тэг
		if ( CRandomGenerator::CheckChance( (*Tags)[vecnOpenedTags[vecnOpenedTags.size() - 1]].GetCloseTagChance() ) )
		{
		    sSubstring.insert ( sSubstring.size(), (*Tags)[vecnOpenedTags[vecnOpenedTags.size() - 1]].GetCloseTag() );
		    (*Tags)[vecnOpenedTags[vecnOpenedTags.size() - 1]].SetStatus( false );
		    vecnOpenedTags.pop_back();
		    unQuantOpenedTags--;
		}
		else
		    unQuantOpenedTags = 0;
	    }

	    svResult.push_back( sSubstring );
	}
    }

    // Нужно закрыть все открытые теги. В этот раз без шансов

    uint unQuantOpenedTags = vecnOpenedTags.size();
    while ( unQuantOpenedTags )
    {
	svResult.push_back ( (*Tags)[ vecnOpenedTags[vecnOpenedTags.size() - 1] ].GetCloseTag() );
	(*Tags)[ vecnOpenedTags[vecnOpenedTags.size() - 1] ].SetStatus( false );
	vecnOpenedTags.pop_back();
	unQuantOpenedTags--;
    }

    return svResult;
}

// Добавление стиля в вектор строк
// Следует вызывать эту функцию последней, после обработки текста и простановки тегов
// Возвращает указатель на вектор
QVector <QString>* CConfig::AddStyle ( QVector <QString>* svVector )
{
    // Имеет смысл добавлять только если есть, что
    if ( !m_Style.GetOpenTag().isEmpty() || !m_Style.GetCloseTag().isEmpty() )
    {
	// Добавление стиля
	svVector->push_front( m_Style.GetOpenTag() );
	svVector->push_back ( m_Style.GetCloseTag() );
    }
    return svVector;
}

void CConfig::TestRegExp ( QString* sConfig )
{
    qDebug() << "TestRegExp string to test: " + *sConfig;

    QString sCharset ( "\\[\\]№.!?" );

    QString Result = ( sConfig->contains( QRegExp ( "^[" + sCharset + "]" )) ? "true" : "false" );

    qDebug() << "TestRegExp output: " + Result;
}

QString CConfig::VectorToString ( QVector <QString>* svVector )
{
    QString sResult = ("");

    for ( int i = 0 ; i < svVector->size() ; i++ )
    {
	sResult += (*svVector)[i];
    }

    return sResult;
}

int CConfig::GetTagsVectorSize () const
{
    return m_TagsVec.size();
}
