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

#include "Tags.h"

CTags::CTags(void)
{
    m_sOpenTag = "";
    m_fOpenTagChance = 0;
    m_sCloseTag = "";
    m_fCloseTagChance = 0;
    m_bOpen = false;
}

CTags::~CTags(void)
{
}

QString CTags::GetOpenTag () const
{
    return m_sOpenTag;
}

float CTags::GetOpenTagChance () const
{
    return m_fOpenTagChance;
}

QString CTags::GetCloseTag () const
{
    return m_sCloseTag;
}

float CTags::GetCloseTagChance () const
{
    return m_fCloseTagChance;
}

bool CTags::IsOpened () const
{
    return m_bOpen;
}

void CTags::SetOpenTag ( const QString sNewOpenTag )
{
    m_sOpenTag = sNewOpenTag;
}

void CTags::SetOpenTagChance ( const float fNewOpenTagChance )
{
    m_fOpenTagChance = fNewOpenTagChance;
}

void CTags::SetCloseTag ( const QString sNewCloseTag )
{
    m_sCloseTag = sNewCloseTag;
}

void CTags::SetCloseTagChance ( const float fNewCloseTagChance )
{
    m_fCloseTagChance = fNewCloseTagChance;
}

// Смена статуса флага о том, что этот тег открыт
void CTags::SetStatus ( const bool bOpen )
{
    m_bOpen = bOpen;
}

// Очистка переменных
void CTags::Clear ()
{
    m_sOpenTag = "";
    m_fOpenTagChance = 0;
    m_sCloseTag = "";
    m_fCloseTagChance = 0;
    m_bOpen = false;
}

CTagsVector::CTagsVector(void)
{
}

CTagsVector::CTagsVector( CTags* Tag )
{
    m_TagsVector.push_back( *Tag );
}

CTagsVector::~CTagsVector(void)
{
}
