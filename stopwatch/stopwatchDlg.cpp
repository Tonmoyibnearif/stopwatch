
// stopwatchDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "stopwatch.h"
#include "stopwatchDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CstopwatchDlg dialog



CstopwatchDlg::CstopwatchDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STOPWATCH_DIALOG, pParent) // dialouge resource file
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CstopwatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, editbox, m_editbox);
	DDX_Control(pDX, ID_WIZFINISH, m_checkbox);
	DDX_Control(pDX, IDC_STARTBUTTON, m_start);
	DDX_Control(pDX, IDC_STOPBUTTON, m_stop);
}

BEGIN_MESSAGE_MAP(CstopwatchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(editbox, &CstopwatchDlg::OnEnChangeeditbox)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STOPBUTTON, &CstopwatchDlg::OnBnClickedStopbutton)
	ON_BN_CLICKED(IDC_STARTBUTTON, &CstopwatchDlg::OnBnClickedStartbutton)
END_MESSAGE_MAP()


// CstopwatchDlg message handlers

BOOL CstopwatchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CstopwatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CstopwatchDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.




void CstopwatchDlg::OnEnChangeeditbox()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

// Timer function 
void CstopwatchDlg::OnTimer(UINT_PTR nIDEvent)
{
	 static long cout=0; // unsigned makes the viriable positive / non negative 
	if(m_checkbox.GetCheck() & BST_CHECKED){
	CString str;
	str.Format(_T("%lu"),cout);
	m_editbox.SetWindowText(str);
	cout++;
	CDialogEx::OnTimer(nIDEvent);
	}
}


void CstopwatchDlg::OnBnClickedStopbutton()
{
	KillTimer(1);
}


void CstopwatchDlg::OnBnClickedStartbutton()
{
	SetTimer(1, 1000, NULL);
}
