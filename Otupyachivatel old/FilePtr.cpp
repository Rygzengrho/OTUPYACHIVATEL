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
#include "FilePtr.h"

CFilePtr::CFilePtr (void)
{
	m_hFile = INVALID_HANDLE_VALUE;
}

CFilePtr::~CFilePtr(void)
{
	if ( m_hFile != INVALID_HANDLE_VALUE )
		CloseHandle ( m_hFile );
}

bool CFilePtr::OpenFile( LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile)
{
	if (( m_hFile = CreateFile(
		lpFileName,
		dwDesiredAccess,
		dwShareMode,
		lpSecurityAttributes,
		dwCreationDisposition,
		dwFlagsAndAttributes,
		hTemplateFile
		)
	) == INVALID_HANDLE_VALUE )
	throw *this;

	return 0;
}

CString CFilePtr::ReadEntireFile ()
{
	SetFilePointer(
				m_hFile,
				0,
				0,
				FILE_BEGIN
				);

	DWORD dwRead;
	DWORD dwSize = GetFileSize ( m_hFile, 0 );

	CString sResult;

	// Reads all data from file to buffer
	// Делим на 2 потому, что каждый символ занимает 2 слота (в Юникоде)
	// Если нужно в другой кодировке - дописываем код определения, в какой кодировке файл,
	// и выделяем соотв. кол-во памяти.
	// Ну, или создаем для этого отдельную функцию.
	ReadFile ( m_hFile, (LPVOID) sResult.GetBuffer( dwSize / 2 ), dwSize, &dwRead, 0 );

	sResult.ReleaseBuffer( dwRead / 2 );

	return sResult;
}