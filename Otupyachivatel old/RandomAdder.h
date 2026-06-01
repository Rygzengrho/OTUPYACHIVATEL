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

class CRandomAdder
{
protected:
	CString m_sStrToAdd;
	FLOAT	m_fChance;

public:
	CRandomAdder(void);
	~CRandomAdder(void);

	CString GetStrToAdd ();
	FLOAT GetChance ();
	bool SetStrToAdd ( const CString sNewStrToAdd );
	bool SetChance ( const FLOAT fNewChance );

	bool Add ( CString* String );
};
