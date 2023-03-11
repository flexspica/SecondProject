// HtmlAppView.cpp : implementation file
//

#include "stdafx.h"
#include "HtmlApp.h"
#include "HtmlAppView.h"

#include "HtmlAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern HWND hDlgWnd;
/////////////////////////////////////////////////////////////////////////////
// CHtmlAppView

IMPLEMENT_DYNCREATE(CHtmlAppView, CHtmlView)

CHtmlAppView::CHtmlAppView()
{
	//{{AFX_DATA_INIT(CHtmlAppView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CHtmlAppView::~CHtmlAppView()
{
}

void CHtmlAppView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHtmlAppView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHtmlAppView, CHtmlView)
	//{{AFX_MSG_MAP(CHtmlAppView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlAppView diagnostics

#ifdef _DEBUG
void CHtmlAppView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CHtmlAppView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHtmlAppView message handlers

BOOL CHtmlAppView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_LBUTTONDOWN))
	{
		::KillTimer(hDlgWnd, HTML_APP_TIMER);
		::SendMessage(hDlgWnd, WM_USER_MESSAGE, NULL, NULL);
	}

	return CHtmlView::PreTranslateMessage(pMsg);
}
