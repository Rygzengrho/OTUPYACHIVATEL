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

class CTags
{
	CString m_sOpenTag;
	FLOAT	m_fOpenTagChance;
	CString m_sCloseTag;
	FLOAT	m_fCloseTagChance;
	// Флаг того, что тэг уже был открыт
	bool	m_bOpen;

public:
	CTags(void);
	~CTags(void);

	CString GetOpenTag ();
	FLOAT GetOpenTagChance ();
	CString GetCloseTag ();
	FLOAT GetCloseTagChance ();
	bool IsOpened ();
	bool SetOpenTag ( const CString sNewOpenTag );
	bool SetOpenTagChance ( const FLOAT fNewOpenTagChance );
	bool SetCloseTag ( const CString sNewCloseTag );
	bool SetCloseTagChance ( const FLOAT fNewCloseTagChance );
	bool SetStatus ( const bool bOpen );
};
