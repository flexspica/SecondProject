#if !defined(AFX_HTMLAPPVIEW_H__40EDD609_EB51_4AD0_B7AE_B194071C5C35__INCLUDED_)
#define AFX_HTMLAPPVIEW_H__40EDD609_EB51_4AD0_B7AE_B194071C5C35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HtmlAppView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHtmlAppView html view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>

class CHtmlAppView : public CHtmlView
{
protected:
	CHtmlAppView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CHtmlAppView)

// html Data
public:
	//{{AFX_DATA(CHtmlAppView)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlAppView)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CHtmlAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CHtmlAppView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLAPPVIEW_H__40EDD609_EB51_4AD0_B7AE_B194071C5C35__INCLUDED_)
