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
#include "Clipboard.h"

CClipboard::CClipboard(void)
{
	m_bOpen = FALSE;
	m_hNextWinCBChain = 0;
}

CClipboard::CClipboard( HWND hNextWinCBChainNew )
{
	m_bOpen = FALSE;
	m_hNextWinCBChain = hNextWinCBChainNew;
}

CClipboard::~CClipboard(void)
{
	if ( m_bOpen )
		CloseClipboard();
	SendMessage ( m_hNextWinCBChain, WM_DRAWCLIPBOARD, 0, 0 );
}

bool CClipboard::GetState()
{
	return m_bOpen;
}

void CClipboard::SetState ( bool bNewState )
{
	m_bOpen = bNewState;
}

HWND CClipboard::GetNextWinCBChain()
{
	return m_hNextWinCBChain;
}

void CClipboard::SetNextWinCBChain( HWND hNextWinCBChainNew )
{
	m_hNextWinCBChain = hNextWinCBChainNew;
}

bool CClipboard::CopyToClipboard ( CString* sStringToCopy )
{
	EmptyClipboard();

	HGLOBAL hglbData;

	hglbData = GlobalAlloc( GMEM_MOVEABLE,
		(sStringToCopy->GetLength() + 1) * sizeof(TCHAR));
	if ( hglbData == NULL )
	{
		return 0 ;
	}

	// Lock the handle and copy the text to the buffer.

	LPTSTR lpData = (LPTSTR) GlobalLock( hglbData );

	memcpy( lpData, *sStringToCopy,
		sStringToCopy->GetLength() * sizeof( TCHAR ) );
	lpData[sStringToCopy->GetLength()] = (TCHAR) 0;    // null character

	GlobalUnlock( hglbData );

	// Place the handle on the clipboard.

	if ( !SetClipboardData( CF_UNICODETEXT, hglbData ) )
	{
		return 0;
	}

	return 1;
}