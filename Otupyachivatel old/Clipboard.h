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

// CClipboard нужен для того, чтобы вызвать CloseClipboard()
// и переслать сообщение WM_DRAWCLIPBOARD дальше независимо
// от результата работа функций, работающий с буфером.
// Это происходит при деструкции объекта, так что валидное
// завершение гарантировано
class CClipboard
{
	bool m_bOpen;
	HWND m_hNextWinCBChain;

public:
	CClipboard( void );
	CClipboard( HWND hNextWinCBChainNew );
	~CClipboard(void);

	bool GetState();
	void SetState ( bool bNewState );
	HWND GetNextWinCBChain();
	void SetNextWinCBChain( HWND hNextWinCBChainNew );

	bool CopyToClipboard ( CString* sStringToCopy );
};
