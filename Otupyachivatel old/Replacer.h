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
#include "RandomGenerator.h"

struct CReplacerResult
{
public:
	CString m_sResultStr;
	FLOAT	m_fResultChance;

	CReplacerResult();
	CReplacerResult( CString sNewString, FLOAT fNewChance );
	~CReplacerResult();
};

class CReplacer
{
protected:
	CString m_sStrToChange;
	std::vector <CReplacerResult> m_Result;

public:
	CReplacer(void);
	~CReplacer(void);

	CString GetStrToChange ();
	CString GetResultString ( UINT unIndex );
	FLOAT GetResultChance ( UINT unIndex );

	bool SetStrToChange ( const CString sNewStrToChange );
	bool SetResult ( const CString sNewResult, const FLOAT fNewChance );

	bool AttemptToChange ( CString* String );
};
