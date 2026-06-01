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

// OtupyachivatelDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Config.h"
#include "FilePtr.h"
#include "Clipboard.h"

const DWORD BUFFER_SIZE = 32767;

// COtupyachivatelDlg dialog
class COtupyachivatelDlg : public CDialog
{
// Construction
public:
	COtupyachivatelDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_OTUPYACHIVATEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand( UINT nID, LPARAM lParam );
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDrawClipboard();
	afx_msg void OnChangeCbChain(  HWND wParam, HWND lParam );
	afx_msg void OnDestroy();
	afx_msg void OnDropFiles( HDROP hDropInfo );
	
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();

protected:
	// Text to process
	CString m_sInputText;
	// Processed text
	CString m_sOutputText;
	CString m_sOutputTagsText;
	CString m_sZlogenAmount;
	CString m_sZlogenInterval;
	BOOL m_bZlogenMode;
public:
	afx_msg void OnEnMaxtextEdit1();
protected:
	// OK already was clicked before and content
	// of input window was not changed after that.
	// Serves to change button texts
	void ErrorOutput( CString sFunction );
	void OnClipbModeChanged();
	void OnClipbZlogenModeChanged();
	CString TestRNG ();

	// Флаг, что была нажата до этого кнопка ОК и после этого не было изменений
	// Отвечает за изменение текста кнопок
	bool m_bOKWasClicked;
	// Режим буфера обмена
	UINT m_uiClipbMode;
	// Флаг, что мы уже получили и обрабатываем сообщение WM_DRAWCLIPBOARD
	bool m_bClipbEditEntered;
	// Указатель на следующее окно в цепочке ClipboardViewers
	HWND m_hNextWinCBChain;

public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	CEdit m_InputEdit;
	CEdit m_OutputEdit;
	CEdit m_OutputTagsEdit;
	CButton m_OKButton;
	CButton m_ClipbRadio;
	CEdit m_EditZlogenAmount;
	CEdit m_ZlogenInterval;

	CConfig m_Config;

	afx_msg void OnBnClickedButtonopenfile();
	afx_msg void OnBnClickedClipbmode1();
	afx_msg void OnBnClickedClipbmode2();
	afx_msg void OnBnClickedClipbmode3();
	afx_msg void OnBnClickedChecktopmost();
	afx_msg void OnBnClickedCheckzlogenmode();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEditzlogenamount();
	afx_msg void OnEnChangeEditzlogeninterval();
};