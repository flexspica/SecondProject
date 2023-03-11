// HtmlAppDlg.h : header file
//

#if !defined(AFX_HTMLAPPDLG_H__1C8606B7_E070_443F_9F35_34F2D4423D0E__INCLUDED_)
#define AFX_HTMLAPPDLG_H__1C8606B7_E070_443F_9F35_34F2D4423D0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHtmlAppDlg dialog
#include "HtmlAppView.h"

class CHtmlAppDlg : public CDialog
{
// Construction
public:
	CHtmlAppDlg(CWnd* pParent = NULL);	// standard constructor
	CHtmlAppView *m_pWeb;

	LRESULT CHtmlAppDlg::OnTaskbar(WPARAM wParam, LPARAM lParam);
	void CHtmlAppDlg::OnWrite();
	void CHtmlAppDlg::OnRemove();
	void CHtmlAppDlg::OnUserMessage();

// Dialog Data
	//{{AFX_DATA(CHtmlAppDlg)
	enum { IDD = IDD_HTMLAPP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlAppDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHtmlAppDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLAPPDLG_H__1C8606B7_E070_443F_9F35_34F2D4423D0E__INCLUDED_)
