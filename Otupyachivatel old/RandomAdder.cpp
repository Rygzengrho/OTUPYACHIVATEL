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
#include "RandomAdder.h"

CRandomAdder::CRandomAdder(void)
{
	m_sStrToAdd = L"";
	m_fChance = 0;
}

CRandomAdder::~CRandomAdder(void)
{
}

CString CRandomAdder::GetStrToAdd ()
{
	return m_sStrToAdd;
}

FLOAT CRandomAdder::GetChance ()
{
	return m_fChance;
}

bool CRandomAdder::SetStrToAdd ( const CString sNewStrToAdd )
{
	m_sStrToAdd = sNewStrToAdd;
	return 0;
}
bool CRandomAdder::SetChance ( const FLOAT fNewChance )
{
	m_fChance = fNewChance;
	return 0;
}

bool CRandomAdder::Add ( CString* String )
{
	String->Insert ( 0, m_sStrToAdd );
	return 0;
}