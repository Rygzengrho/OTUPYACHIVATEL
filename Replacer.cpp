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

#include "Replacer.h"

CReplacerResult::CReplacerResult(void)
{
    m_sResultStr = "";
    m_fResultChance = 0;
}

CReplacerResult::CReplacerResult( QString sNewString, float fNewChance )
{
    m_sResultStr = sNewString;
    m_fResultChance = fNewChance;
}

CReplacerResult::~CReplacerResult(void)
{
}

CReplacer::CReplacer(void)
{
    m_sStrToChange = "";
}

CReplacer::~CReplacer(void)
{
}

QString CReplacer::GetStrToChange () const
{
    return m_sStrToChange;
}

QString CReplacer::GetResultString ( const unsigned int unIndex ) const
{
    return m_Result[unIndex].m_sResultStr;
}

float CReplacer::GetResultChance ( const unsigned int unIndex ) const
{
    return m_Result[unIndex].m_fResultChance;
}

bool CReplacer::SetStrToChange ( const QString sNewStrToChange )
{
    m_sStrToChange = sNewStrToChange;
    return 0;
}
bool CReplacer::SetResult ( const QString sNewResult, const float fNewChance )
{
    m_Result.push_back ( CReplacerResult( sNewResult, fNewChance ) );
    return 0;
}

int CReplacer::Size ()
{
   return m_Result.size();
}
