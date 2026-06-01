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

#pragma once

#include <vector>
#include "resource.h"
#include "Replacer.h"
#include "RandomAdder.h"
#include "Tags.h"

class CConfig
{
private:
	std::vector <CReplacer> m_Replacer;
	std::vector <CRandomAdder> m_RandomAdder;
	std::vector <CTags> m_Tags;

	// Config variables
	FLOAT m_fCapitalizationChance;
	FLOAT m_f3AdditionsChance;
	FLOAT m_f2AdditionsChance;
	FLOAT m_f1AdditionChance;
	FLOAT m_fNumToRep;
	CString m_sNumRepString;
	FLOAT m_fNumRepChance;
	DWORD m_dwMinLengthForAddition;

	// Charsets
	CString m_sComment;
	CString m_sBlockCommentSymbol;
	CString m_sEndSymbol;
	CString m_sSpaces;
	CString m_sEquals;
	CString m_sStringID;
	CString m_sMacroID;
	CString m_sChanceSeparator;
	CString m_sResultsSeparator;
	CString m_sNumber;
	CString m_sDecimalPoint;
	CString m_sEngAlphabetLower;
	CString m_sEngAlphabetUpper;
	CString m_sRusAlphabetLower;
	CString m_sRusAlphabetUpper;
	CString m_sRandAddID;
	CString m_sTagID;
	CString m_sSeparatorsNotForChange;
	CString m_sSeparatorsChangeable;

	// Tags
	CString m_sUpTag;
	CString m_sSaveTag;

	bool SearchAmper ( CString* sStrToCheck, CString* sStrToCompareWith );
	bool SearchStar ( CString* sStrToCheck, CString* sStrToCompareWith );
	bool CheckAndChangeSubstring ( CString* sStrToCheck );

public:
	CConfig(void);
	~CConfig(void);

	bool ResetStrings ();
	bool ParseConfig ( CString* sConfig );
	bool Clear ();

	bool ParseVariableString( CString* sVariable, CString* sString );
	bool ParseVariableFloat( FLOAT* fVariable, CString* sString );
	bool ParseVariableDWORD( DWORD* dwVariable, CString* sString );

	bool MakeLowerRus ( CString* sString );
	bool MakeUpperRus ( CString* sString );
	DWORD Count ( const CString* sString, const CString* sSymbol );

	UINT GenerateAdditionsAmount ();
	DWORD GenerateAdditions ( CString* sSubstring, UINT unAmount );
	std::vector <CString> OtupyachitText ( CString sText );
	std::vector <CString> GenerateText ( DWORD dwZlogenAmount );
	std::vector <CString> AddTags( std::vector <CString> svVector );

	CString VectorToString ( std::vector <CString> svVector );
};