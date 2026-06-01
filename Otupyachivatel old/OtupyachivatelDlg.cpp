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

// OtupyachivatelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Otupyachivatel.h"
#include "OtupyachivatelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// COtupyachivatelDlg dialog

COtupyachivatelDlg::COtupyachivatelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COtupyachivatelDlg::IDD, pParent)
	, m_sInputText(_T(""))
	, m_sOutputText(_T(""))
	, m_bOKWasClicked(false)
	, m_uiClipbMode (0)
	, m_bClipbEditEntered (false)
	, m_sOutputTagsText(_T(""))
	, m_bZlogenMode(false)
	, m_sZlogenAmount(_T("10"))
	, m_sZlogenInterval(_T("1000"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COtupyachivatelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sInputText);
	DDX_Text(pDX, IDC_EDIT2, m_sOutputText);
	DDX_Text(pDX, IDC_EDIT3, m_sOutputTagsText);
	DDX_Text(pDX, IDC_EditZlogenAmount, m_sZlogenAmount);
	DDX_Text(pDX, IDC_EditZlogenInterval, m_sZlogenInterval);
	DDX_Check(pDX, IDC_CheckZlogenMode, m_bZlogenMode);
	DDX_Control(pDX, IDC_EDIT1, m_InputEdit);
	DDX_Control(pDX, IDC_EDIT2, m_OutputEdit);
	DDX_Control(pDX, IDC_EDIT3, m_OutputTagsEdit);
	DDX_Control(pDX, IDOK, m_OKButton);
	DDX_Control(pDX, IDC_ClipbMode1, m_ClipbRadio);
	DDX_Control(pDX, IDC_EditZlogenAmount, m_EditZlogenAmount);
	DDX_Control(pDX, IDC_EditZlogenInterval, m_ZlogenInterval);
}

BEGIN_MESSAGE_MAP(COtupyachivatelDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DRAWCLIPBOARD()
	ON_WM_CHANGECBCHAIN()
	ON_WM_DESTROY()
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &COtupyachivatelDlg::OnBnClickedOk)
	ON_EN_MAXTEXT(IDC_EDIT1, &COtupyachivatelDlg::OnEnMaxtextEdit1)
	ON_EN_CHANGE(IDC_EDIT1, &COtupyachivatelDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTONOPENFILE, &COtupyachivatelDlg::OnBnClickedButtonopenfile)
	ON_EN_CHANGE(IDC_EDIT2, &COtupyachivatelDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &COtupyachivatelDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_ClipbMode1, &COtupyachivatelDlg::OnBnClickedClipbmode1)
	ON_BN_CLICKED(IDC_ClipbMode2, &COtupyachivatelDlg::OnBnClickedClipbmode2)
	ON_BN_CLICKED(IDC_ClipbMode3, &COtupyachivatelDlg::OnBnClickedClipbmode3)
	ON_BN_CLICKED(IDC_CheckTopmost, &COtupyachivatelDlg::OnBnClickedChecktopmost)
	ON_BN_CLICKED(IDC_CheckZlogenMode, &COtupyachivatelDlg::OnBnClickedCheckzlogenmode)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EditZlogenAmount, &COtupyachivatelDlg::OnEnChangeEditzlogenamount)
	ON_EN_CHANGE(IDC_EditZlogenInterval, &COtupyachivatelDlg::OnEnChangeEditzlogeninterval)
END_MESSAGE_MAP()


// COtupyachivatelDlg message handlers

BOOL COtupyachivatelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon

	m_ClipbRadio.SetCheck ( TRUE );

	// Сидинг РНГ от времени
	srand ( UINT ( time ( 0 )));

	CFilePtr File;
	try
	{
		File.OpenFile (
		L"default.ini",
		GENERIC_READ,
		0,
		0,
		OPEN_EXISTING,
		0,
		0
		);
	}
	catch ( CFilePtr )
	{
		ErrorOutput ( L"CreateFile" );
	}

	CString sConfig = File.ReadEntireFile ( );

	if ( m_Config.ParseConfig ( &sConfig ) )
	{
		CString sWarning;
		sWarning.LoadStringW ( IDS_ConfigWarning );
		MessageBox ( sWarning );
	}

	m_hNextWinCBChain = SetClipboardViewer();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COtupyachivatelDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COtupyachivatelDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc( this ); // device context for painting

		SendMessage( WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0 );

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COtupyachivatelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COtupyachivatelDlg::OnDrawClipboard()
{
 	if ( m_uiClipbMode && !m_bZlogenMode && !m_bClipbEditEntered && IsClipboardFormatAvailable( CF_TEXT ) )
	{
		m_bClipbEditEntered = TRUE;

		CClipboard Clipboard ( m_hNextWinCBChain );

		if ( !OpenClipboard() )
		{
			m_bClipbEditEntered = FALSE;
			//AfxMessageBox( L"Не получилось открыть буфер обмена" );
			return;
		}

		// Отметка об открытии клипборда
		Clipboard.SetState ( TRUE );

		HGLOBAL hglbData;

		hglbData = GetClipboardData( CF_UNICODETEXT );

		if ( hglbData == NULL )
		{
			m_bClipbEditEntered = FALSE;
			CString sWarning;
			sWarning.LoadStringW ( IDS_ClipbGetDataFail );
			MessageBox ( sWarning );
			return;
		}

		LPTSTR lpData = (LPTSTR) GlobalLock( hglbData );

		if ( lpData == NULL )
		{
			m_bClipbEditEntered = FALSE;
			CString sWarning;
			sWarning.LoadStringW ( IDS_StringMemAllocFail );
			MessageBox ( sWarning );
			return;
		}

		CString sData ( lpData ) ;

		GlobalUnlock( hglbData );

		CloseClipboard ();
		Clipboard.SetState ( FALSE );

		UpdateData(TRUE);

		m_sInputText = sData;

		std::vector <CString> svVector;

		svVector = m_Config.OtupyachitText ( m_sInputText );
		m_sOutputText = m_Config.VectorToString ( svVector );
		m_sOutputTagsText = m_Config.VectorToString ( m_Config.AddTags ( svVector ));

		UpdateData(FALSE);

		// Автоматически OnChange в этом случае не вызывается, так что вызываем его вручную
		OnEnChangeEdit1 ();
		OnEnChangeEdit2 ();
		OnEnChangeEdit3 ();

		m_bOKWasClicked = TRUE;

		CString sOut;

		sOut.LoadString( IDS_OkMore );
		SetDlgItemTextW( IDOK, sOut );
		sOut.LoadString( IDS_CancelMore );
		SetDlgItemTextW( IDCANCEL, sOut );

		// А теперь запись в буфер
		if ( !OpenClipboard() )
		{
			m_bClipbEditEntered = FALSE;
			//AfxMessageBox( L"Не получилось открыть буфер обмена" );
			return;
		}

		Clipboard.SetState ( TRUE );

		if ( m_uiClipbMode == 1 )
		{
			if ( !Clipboard.CopyToClipboard ( &m_sOutputText ) )
			{
				m_bClipbEditEntered = FALSE;
				CString sWarning;
				sWarning.LoadStringW ( IDS_ClipbWriteFail );
				MessageBox ( sWarning );
			}
		}
		else if ( m_uiClipbMode == 2 )
		{
			if ( !Clipboard.CopyToClipboard ( &m_sOutputTagsText ) )
			{
				m_bClipbEditEntered = FALSE;
				CString sWarning;
				sWarning.LoadStringW ( IDS_ClipbWriteFail );
				MessageBox ( sWarning );
			}
		}

		CloseClipboard();
		Clipboard.SetState( FALSE );
		m_bClipbEditEntered = FALSE;
	}
	else
		::SendMessage ( m_hNextWinCBChain, WM_DRAWCLIPBOARD, 0, 0 );
}

// Вызывается в случае изменения порядка окон в последовательности ClipboardViewers
void COtupyachivatelDlg::OnChangeCbChain( HWND wParam, HWND lParam )
{
	if ( wParam == m_hNextWinCBChain )
		m_hNextWinCBChain = lParam;
	else
		::SendMessage (
		m_hNextWinCBChain,
		WM_CHANGECBCHAIN,
		(WPARAM) wParam,
		(LPARAM) lParam
		);
}

void COtupyachivatelDlg::OnDestroy()
{
	ChangeClipboardChain ( m_hNextWinCBChain );
}

// При дропе файла на окно
void COtupyachivatelDlg::OnDropFiles( HDROP hDropInfo )
{
	// Очистка старого конфига
	m_Config.Clear();

	LPTSTR lpszFileName;

	// Получение инфы о кол-ве символов в имени файла
	UINT uiSize = DragQueryFile(
		hDropInfo,
		0,
		0,
		0
	);

	lpszFileName = new TCHAR [uiSize+1];

	// Получение имени файла
	DragQueryFile(
		hDropInfo,
		0,
		lpszFileName,
		uiSize+1
	);

	CString sExtension ( lpszFileName );

	CString sCheck;

	// Проверка, что это валидный файл
	if ( sExtension.GetLength() >= 4 )
		sCheck = sExtension.Right ( 4 );
	else
	{
		CString sWarning;
		sWarning.LoadStringW ( IDS_ClipbWriteFail );
		MessageBox ( sWarning );
		return;
	}

	if ( sCheck != L".ini" )
	{
		CString sWarning;
		sWarning.LoadStringW ( IDS_ClipbWriteFail );
		MessageBox ( sWarning );
		return;
	}

	CFilePtr File;
	try
	{
		File.OpenFile (
		lpszFileName,
		GENERIC_READ,
		0,
		0,
		OPEN_EXISTING,
		0,
		0
		);
	}
	catch ( CFilePtr )
	{
		ErrorOutput ( L"CreateFile" );
	}

	CString sConfig = File.ReadEntireFile ( );

	if ( m_Config.ParseConfig ( &sConfig ) )
	{
		CString sWarning;
		sWarning.LoadStringW ( IDS_ConfigWarning );
		MessageBox ( sWarning );
	}

	// Освобождение системной памяти
	DragFinish ( hDropInfo );

	delete[] lpszFileName;
}

// Функция принимает указатель на название
// функции, в которой произошла ошибка.
// Выводит название ф-ции, номер ошибки и ее расшифровку
void COtupyachivatelDlg::ErrorOutput( CString sFunction )
{
	DWORD	dwError = GetLastError();
	LPVOID	lpMsgBuf;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
		0,
		NULL
		);

	LPTSTR lpszErrorNumber = new TCHAR[64];
	_itow_s( dwError, lpszErrorNumber, 32, 10 );

	MessageBox ( sFunction + L" failed with error " + lpszErrorNumber + L": " + (LPTSTR)lpMsgBuf );
	delete[] lpszErrorNumber;
	ExitProcess( dwError );
}

CString COtupyachivatelDlg::TestRNG()
{
	CString sResult ( L"" );

	CRandomGenerator RNG;

	for ( UINT i = 0 ; i < 100 ; i++ )
	{
		FLOAT fRandNum = RNG.RandomGenerator ( 99, 100 );

		INT dec, sign;

		char* pszNumberChar = new char[64];
		LPTSTR lpszNumber = new TCHAR[64];

		_ecvt_s( 
		   pszNumberChar,
		   32,
		   fRandNum,
		   16,
		   &dec,
		   &sign
		);

		CString sTemp( pszNumberChar );

		sResult += sTemp;
		sResult += L"  ";

		delete[] pszNumberChar;
		delete[] lpszNumber;
	}

	return sResult;
}

void COtupyachivatelDlg::OnBnClickedOk()
{
	CString sOut;

	UpdateData(TRUE);

	std::vector <CString> svVector;

	if ( !m_bZlogenMode )
	{
		svVector = m_Config.OtupyachitText ( m_sInputText );
		m_sOutputText = m_Config.VectorToString ( svVector );
		m_sOutputTagsText = m_Config.VectorToString (  m_Config.AddTags ( svVector ));
	}
	else
	{
		DWORD dwZlogenAmount;
		m_Config.ParseVariableDWORD ( &dwZlogenAmount, &m_sZlogenAmount );
		svVector = m_Config.GenerateText ( dwZlogenAmount );
		m_sOutputText = m_Config.VectorToString ( svVector );
		m_sOutputTagsText = m_Config.VectorToString ( m_Config.AddTags ( svVector ));
	}

	if ( m_uiClipbMode )
	{
		m_bClipbEditEntered = TRUE;

		CClipboard Clipboard ( m_hNextWinCBChain );

		if ( !OpenClipboard() )
		{
			m_bClipbEditEntered = FALSE;
			AfxMessageBox( L"Не получилось открыть буфер обмена" );
			return;
		}

		Clipboard.SetState ( TRUE );

		if ( m_uiClipbMode == 1 )
		{
			if ( !Clipboard.CopyToClipboard ( &m_sOutputText ) )
			{
				m_bClipbEditEntered = FALSE;
				AfxMessageBox( L"Не удалась запись в буфер обмена" );
			}
		}
		else if ( m_uiClipbMode == 2 )
		{
			if ( !Clipboard.CopyToClipboard ( &m_sOutputTagsText ) )
			{
				m_bClipbEditEntered = FALSE;
				AfxMessageBox( L"Не удалась запись в буфер обмена" );
			}
		}

		CloseClipboard();
		Clipboard.SetState( FALSE );
		m_bClipbEditEntered = FALSE;
	}

	m_bOKWasClicked = TRUE;

	sOut.LoadString( IDS_OkMore );
	SetDlgItemTextW( IDOK, sOut );
	sOut.LoadString( IDS_CancelMore );
	SetDlgItemTextW( IDCANCEL, sOut );

	UpdateData(FALSE);

	OnEnChangeEdit2 ();
	OnEnChangeEdit3 ();
}

void COtupyachivatelDlg::OnEnMaxtextEdit1()
{
	CString sOut;
	
	sOut.LoadString( IDS_TooMuchText );

	MessageBox ( sOut );
}

void COtupyachivatelDlg::OnEnChangeEdit1()
{
	// If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// If OK button was pressed before, but after that
	// text in the input window was changed (this means that it's a new or edited text),
	// it changes the buttons texts back and removes the flag

	if ( m_bOKWasClicked )
	{
		CString sOut;

		m_bOKWasClicked = FALSE;
		sOut.LoadString( IDS_OkText );
		SetDlgItemTextW( IDOK, sOut );
		sOut.LoadString( IDS_CancelText );
		SetDlgItemTextW( IDCANCEL, sOut );
	}

	// Toggle the scroll bar if text is not fitting in the window
	if ( m_InputEdit.GetLineCount() > 7 )
	{
		m_InputEdit.ShowScrollBar( SB_VERT );
	}
	else
		m_InputEdit.ShowScrollBar( SB_VERT, FALSE );
}

void COtupyachivatelDlg::OnBnClickedButtonopenfile()
{
	CFileDialog dlgFileOpen(
		TRUE,
		L".ini",
		0,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"Config Files (*.ini)|*.ini|All Files (*.*)|*.*||"
		);

	if ( dlgFileOpen.DoModal() == IDOK )
	{
		m_Config.Clear();
		CString sPathName = dlgFileOpen.GetPathName();

		CString sCheck;

		if ( sPathName.GetLength() >= 4 )
			sCheck = sPathName.Right ( 4 );
		else
		{
			CString sWarning;
			sWarning.LoadStringW ( IDS_WrongFile );
			MessageBox ( sWarning );
			return;
		}

		if ( sCheck != L".ini" )
		{
			CString sWarning;
			sWarning.LoadStringW ( IDS_WrongFile );
			MessageBox ( sWarning );
			return;
		}

		CFilePtr File;
		try
		{
			File.OpenFile (
			sPathName,
			GENERIC_READ,
			0,
			0,
			OPEN_EXISTING,
			0,
			0
			);
		}
		catch ( CFilePtr )
		{
			ErrorOutput ( L"CreateFile" );
		}

		CString sConfig = File.ReadEntireFile ( );

		if ( m_Config.ParseConfig ( &sConfig ) )
		{
			CString sWarning;
			sWarning.LoadStringW ( IDS_ConfigWarning );
			MessageBox ( sWarning );
		}
  
	}
}

// Вызывается когда происходит нажатие по любой из радиокнопок
void COtupyachivatelDlg::OnClipbModeChanged()
{
	if ( IsDlgButtonChecked( IDC_ClipbMode1 ) == BST_CHECKED )
	{
		// Влом было биндить на DDX
		m_uiClipbMode = 0;

		if ( !m_bZlogenMode )
		{
			// Вот через такую жопу в MFC меняются стили (да и то не все)
			// элементов управления
			::SendMessage(
			   m_InputEdit,
			   EM_SETREADONLY,
			   (WPARAM) FALSE,
			   0
			);
		}
	}
	else if ( IsDlgButtonChecked( IDC_ClipbMode2 ) == BST_CHECKED )
	{
		m_uiClipbMode = 1;

		if ( !m_bZlogenMode )
		{
			::SendMessage(
			   m_InputEdit,
			   EM_SETREADONLY,
			   (WPARAM) TRUE,
			   0
			);
		}
	}
	else if ( IsDlgButtonChecked( IDC_ClipbMode3 ) == BST_CHECKED )
	{
		m_uiClipbMode = 2;

		if ( !m_bZlogenMode )
		{
			::SendMessage(
			   m_InputEdit,
			   EM_SETREADONLY,
			   (WPARAM) TRUE,
			   0
			);
		}
	}

	OnClipbZlogenModeChanged();
}

// Вызывается, когда возможно изменение режима злогена в совокупности с режимом
// буфера обмена
void COtupyachivatelDlg::OnClipbZlogenModeChanged()
{
	if ( m_bZlogenMode && m_uiClipbMode )
	{
		::EnableWindow ( m_ZlogenInterval, 1 );

		DWORD dwZlogenInterval;
		m_Config.ParseVariableDWORD ( &dwZlogenInterval, &m_sZlogenInterval );
		SetTimer( 1, dwZlogenInterval, 0 );
	}
	else
	{
		::EnableWindow ( m_ZlogenInterval, 0 );

		KillTimer( 1 );
	}
}

// Вызывается при изменении в поле Edit2
void COtupyachivatelDlg::OnEnChangeEdit2()
{
	// If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// Если текста больше, чем видимых линий - включаем полосу вертикальной прокрутки
	if ( m_OutputEdit.GetLineCount() > 7 )
	{
		m_OutputEdit.ShowScrollBar( SB_VERT );
	}
	else
		m_OutputEdit.ShowScrollBar( SB_VERT, FALSE );
}

// Вызывается при изменении в поле Edit3
void COtupyachivatelDlg::OnEnChangeEdit3()
{
	// If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// Если текста больше, чем видимых линий - включаем полосу вертикальной прокрутки
	if ( m_OutputTagsEdit.GetLineCount() > 7 )
	{
		m_OutputTagsEdit.ShowScrollBar( SB_VERT );
	}
	else
		m_OutputTagsEdit.ShowScrollBar( SB_VERT, FALSE );
}

void COtupyachivatelDlg::OnBnClickedClipbmode1()
{
	OnClipbModeChanged();
}

void COtupyachivatelDlg::OnBnClickedClipbmode2()
{
	OnClipbModeChanged();
}

void COtupyachivatelDlg::OnBnClickedClipbmode3()
{
	OnClipbModeChanged();
}

// При нажатии на кнопку "Всегда наверху"
void COtupyachivatelDlg::OnBnClickedChecktopmost()
{
	if ( IsDlgButtonChecked( IDC_CheckTopmost ) == BST_CHECKED )
	{
		::SetWindowPos(
			*this,
			HWND_TOPMOST,
			0,
			0,
			0,
			0,
			SWP_NOMOVE | SWP_NOSIZE
		);
	}
	else if ( IsDlgButtonChecked( IDC_CheckTopmost ) == BST_UNCHECKED )
	{
		::SetWindowPos(
			*this,
			HWND_NOTOPMOST,
			0,
			0,
			0,
			0,
			SWP_NOMOVE | SWP_NOSIZE
		);
	}
}

// Вызывается, когда, возможно, изменился режим работы программы как Злогена
void COtupyachivatelDlg::OnBnClickedCheckzlogenmode()
{
	if ( IsDlgButtonChecked( IDC_CheckZlogenMode ) == BST_CHECKED )
	{
		CString sOut;

		sOut.LoadString( IDS_ModeOn );
		SetDlgItemTextW( IDC_CheckZlogenMode, sOut );
		sOut.LoadString( IDS_OkZlogen );
		SetDlgItemTextW( IDOK, sOut );

		// Вот через такую жопу в MFC меняются стили (да и то не все)
		// элементов управления
		::SendMessage(
		   m_InputEdit,
		   EM_SETREADONLY,
		   (WPARAM) TRUE,
		   0
		);

		m_sInputText = L"";

		::EnableWindow ( m_EditZlogenAmount, 1 );
	}
	else if ( IsDlgButtonChecked( IDC_CheckZlogenMode ) == BST_UNCHECKED )
	{
		CString sOut;

		sOut.LoadString( IDS_ModeOff );
		SetDlgItemTextW( IDC_CheckZlogenMode, sOut );
		sOut.LoadString( IDS_OkText );
		SetDlgItemTextW( IDOK, sOut );

		if ( !m_uiClipbMode )
		{
			::SendMessage(
			   m_InputEdit,
			   EM_SETREADONLY,
			   (WPARAM) FALSE,
			   0
			);
		}

		::EnableWindow ( m_EditZlogenAmount, 0 );
	}

	UpdateData(TRUE);

	OnClipbZlogenModeChanged();
}

// Вызывается если включен таймер и если время таймера истекло
void COtupyachivatelDlg::OnTimer(UINT_PTR nIDEvent)
{
	// Убийство таймера со старым интервалом
	KillTimer(1);

	UpdateData(TRUE);

	DWORD dwZlogenInterval;
	m_Config.ParseVariableDWORD ( &dwZlogenInterval, &m_sZlogenInterval );

	// Установка нового таймера с новым интервалом
	SetTimer( 1, dwZlogenInterval, 0 );

	DWORD dwZlogenAmount;
	m_Config.ParseVariableDWORD ( &dwZlogenAmount, &m_sZlogenAmount );

	std::vector <CString> svVector;

	svVector = m_Config.GenerateText ( dwZlogenAmount );
	m_sOutputText = m_Config.VectorToString ( svVector );
	m_sOutputTagsText = m_Config.VectorToString ( m_Config.AddTags ( svVector ));

	CClipboard Clipboard ( m_hNextWinCBChain );

	if ( !OpenClipboard() )
	{
		m_bClipbEditEntered = FALSE;
		//AfxMessageBox( L"Не получилось открыть буфер обмена" );
		return;
	}

	Clipboard.SetState ( TRUE );

	if ( m_uiClipbMode == 1 )
	{
		if ( !Clipboard.CopyToClipboard ( &m_sOutputText ) )
		{
			m_bClipbEditEntered = FALSE;
			AfxMessageBox( L"Не удалась запись в буфер обмена" );
		}
	}
	else if ( m_uiClipbMode == 2 )
	{
		if ( !Clipboard.CopyToClipboard ( &m_sOutputTagsText ) )
		{
			m_bClipbEditEntered = FALSE;
			AfxMessageBox( L"Не удалась запись в буфер обмена" );
		}
	}

	CloseClipboard();
	Clipboard.SetState( FALSE );

	m_bOKWasClicked = TRUE;

	CString sOut;

	sOut.LoadString( IDS_OkMore );
	SetDlgItemTextW( IDOK, sOut );
	sOut.LoadString( IDS_CancelMore );
	SetDlgItemTextW( IDCANCEL, sOut );

	UpdateData(FALSE);

	OnEnChangeEdit2 ();
	OnEnChangeEdit3 ();

	CDialog::OnTimer(nIDEvent);
}

// Вызывается при изменении в поле ZlogenAmount
void COtupyachivatelDlg::OnEnChangeEditzlogenamount()
{
	// If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// Проверка верности вводимых данных
	UpdateData(TRUE);

	DWORD dwZlogenAmount;
	m_Config.ParseVariableDWORD ( &dwZlogenAmount, &m_sZlogenAmount );
	if ( dwZlogenAmount > 255 )
		m_sZlogenAmount = L"255";

	UpdateData(FALSE);
}

// Вызывается при изменении в поле ZlogenInterval
void COtupyachivatelDlg::OnEnChangeEditzlogeninterval()
{
	// If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// Проверка верности вводимых данных
	UpdateData(TRUE);

	DWORD dwZlogenInterval;
	m_Config.ParseVariableDWORD ( &dwZlogenInterval, &m_sZlogenInterval );
	if ( dwZlogenInterval > 10000 )
	{
		m_sZlogenInterval = L"10000";
	}
	if ( dwZlogenInterval < 100 )
	{
		m_sZlogenInterval = L"100";
	}

	UpdateData(FALSE);
}