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
#include "Tags.h"

CTags::CTags(void)
{
	m_sOpenTag = L"";
	m_fOpenTagChance = 0;
	m_sCloseTag = L"";
	m_fCloseTagChance = 0;
	m_bOpen = FALSE;
}

CTags::~CTags(void)
{
}

CString CTags::GetOpenTag ()
{
	return m_sOpenTag;
}

FLOAT CTags::GetOpenTagChance ()
{
	return m_fOpenTagChance;
}

CString CTags::GetCloseTag ()
{
	return m_sCloseTag;
}

FLOAT CTags::GetCloseTagChance ()
{
	return m_fCloseTagChance;
}

bool CTags::IsOpened ()
{
	return m_bOpen;
}

bool CTags::SetOpenTag ( const CString sNewOpenTag )
{
	m_sOpenTag = sNewOpenTag;
	return 0;
}

bool CTags::SetOpenTagChance ( const FLOAT fNewOpenTagChance )
{
	m_fOpenTagChance = fNewOpenTagChance;
	return 0;
}

bool CTags::SetCloseTag ( const CString sNewCloseTag )
{
	m_sCloseTag = sNewCloseTag;
	return 0;
}

bool CTags::SetCloseTagChance ( const FLOAT fNewCloseTagChance )
{
	m_fCloseTagChance = fNewCloseTagChance;
	return 0;
}

bool CTags::SetStatus ( const bool bOpen )
{
	m_bOpen = bOpen;
	return 0;
}