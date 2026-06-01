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
#include "Replacer.h"

CReplacerResult::CReplacerResult(void)
{
	m_sResultStr = L"";
	m_fResultChance = 0;
}

CReplacerResult::CReplacerResult( CString sNewString, FLOAT fNewChance )
{
	m_sResultStr = sNewString;
	m_fResultChance = fNewChance;
}

CReplacerResult::~CReplacerResult(void)
{
}

CReplacer::CReplacer(void)
{
	m_sStrToChange = L"";
}

CReplacer::~CReplacer(void)
{
}

CString CReplacer::GetStrToChange ()
{
	return m_sStrToChange;
}

CString CReplacer::GetResultString ( UINT unIndex )
{
	return m_Result[unIndex].m_sResultStr;
}

FLOAT CReplacer::GetResultChance ( UINT unIndex )
{
	return m_Result[unIndex].m_fResultChance;
}

bool CReplacer::SetStrToChange ( const CString sNewStrToChange )
{
	m_sStrToChange = sNewStrToChange;
	return 0;
}
bool CReplacer::SetResult ( const CString sNewResult, const FLOAT fNewChance )
{
	m_Result.push_back ( CReplacerResult( sNewResult, fNewChance ) );
	return 0;
}

bool CReplacer::AttemptToChange ( CString* String )
{
	CRandomGenerator RNG;
	FLOAT fRandNum = RNG.RandomGenerator( 0, 100 );

	FLOAT fSumm = 0;

	for ( UINT unIndex = 0 ; unIndex < m_Result.size() && fSumm <= 100 ; unIndex++ )
	{
		fSumm += m_Result[unIndex].m_fResultChance;

		if ( fRandNum <= fSumm )
		{
			*String = m_Result[unIndex].m_sResultStr;
			return 0;
		}
	}

	return 1;
}