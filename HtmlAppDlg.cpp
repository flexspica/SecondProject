// HtmlAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HtmlApp.h"
#include "HtmlAppDlg.h"    

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



HWND hDlgWnd;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)

	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlAppDlg dialog

CHtmlAppDlg::CHtmlAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHtmlAppDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHtmlAppDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHtmlAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHtmlAppDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHtmlAppDlg, CDialog)
	//{{AFX_MSG_MAP(CHtmlAppDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_MESSAGE(WM_USER_MESSAGE, OnUserMessage)
	ON_MESSAGE(WM_TASKBAR, OnTaskbar) 
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlAppDlg message handlers

BOOL CHtmlAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

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
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	hDlgWnd = this->m_hWnd;

	CCreateContext pContext;
    CWnd* pFrameWnd = this;
    pContext.m_pCurrentDoc = new CDocument; //  µµ±Ô¸àÆ® 
    pContext.m_pNewViewClass = RUNTIME_CLASS(CHtmlAppView);
    m_pWeb =(CHtmlAppView*) ((CFrameWnd*)pFrameWnd)->CreateView(&pContext);

    ASSERT(m_pWeb);

	CRect rect;
	GetClientRect(&rect);
	m_pWeb->SetWindowPos(NULL, rect.left, rect.top, rect.right, rect.bottom, NULL);
    m_pWeb->ShowWindow(TRUE);

	SetWindowText("KOSPI");
	m_pWeb->Navigate("http://stockdata.joins.com/graph/kospi01.png", 0, NULL, NULL);

	SetTimer(HTML_APP_TIMER, 1500, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHtmlAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if((nID & 0xFFF0) == IDM_ABOUTBOX)
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
void CHtmlAppDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHtmlAppDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

UINT SeqNo = 20;

void CHtmlAppDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == HTML_APP_TIMER)
	{
		switch(SeqNo)  
		{
			case 10:
				m_pWeb->Navigate("http://stockdata.joins.com/graph/kospi01.png", 0, NULL, NULL);
				SetWindowText("KOSPI");
				SeqNo = 10;
				break;
		}
	}	

	CDialog::OnTimer(nIDEvent);
}

void CHtmlAppDlg::OnWrite() 
{
	// handle to icon
    HICON hIcon;
	// text for tool tip
    char lpszTip[] = "ICON-1";

    HINSTANCE hInst = AfxFindResourceHandle(MAKEINTRESOURCE(IDI_ICON1), RT_GROUP_ICON);
    hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
    
	// set NOTIFYCONDATA structure

    NOTIFYICONDATA tnid;

    tnid.cbSize = sizeof(NOTIFYICONDATA);
    tnid.hWnd = m_hWnd;
    tnid.uID = IDI_ICON1;
    tnid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
	tnid.uCallbackMessage = WM_TASKBAR;							// my user message
    tnid.hIcon = hIcon;

    if(lpszTip)
       lstrcpyn(tnid.szTip, lpszTip, sizeof(tnid.szTip));
    else
       tnid.szTip[0] = '\0';

	// call to Shell_NotifyIcon with NIM_ADD parameter
    Shell_NotifyIcon(NIM_ADD, &tnid);
 
	// free icon 
    if(hIcon) 
		DestroyIcon(hIcon); 
}

void CHtmlAppDlg::OnRemove() 
{
	// for remove, only provide cbSize, hWnd and uID!
    NOTIFYICONDATA tnid;

    tnid.cbSize = sizeof(NOTIFYICONDATA);	
    tnid.hWnd = m_hWnd; 
    tnid.uID = IDI_ICON1; 

	// call to Shell_NotifyIcon with NIM_DEL parameter
    Shell_NotifyIcon(NIM_DELETE, &tnid); 
}

LRESULT CHtmlAppDlg::OnTaskbar(WPARAM wParam, LPARAM lParam)
{
    UINT uMouseMsg = (UINT)lParam;

    switch(uMouseMsg)
	{
		case WM_LBUTTONDBLCLK: 
			SetTimer(HTML_APP_TIMER, 1500, NULL);
			OnRemove();
			ShowWindow(SW_SHOW);

			m_pWeb->Navigate("http://stockdata.joins.com/graph/kospi01.png", 0, NULL, NULL);
			SetWindowText("KOSPI");
			SeqNo = 20;
            break;
		default:  
			break;
    }
	return 0;
}

void CHtmlAppDlg::OnUserMessage()
{
	OnWrite();
	ShowWindow(SW_HIDE);
}


