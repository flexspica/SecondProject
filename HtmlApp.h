// HtmlApp.h : main header file for the HTMLAPP application
//

#if !defined(AFX_HTMLAPP_H__E825C986_B715_4A03_B120_C359554392CA__INCLUDED_)
#define AFX_HTMLAPP_H__E825C986_B715_4A03_B120_C359554392CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHtmlAppApp:
// See HtmlApp.cpp for the implementation of this class
//

class CHtmlAppApp : public CWinApp
{
public:
	CHtmlAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHtmlAppApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLAPP_H__E825C986_B715_4A03_B120_C359554392CA__INCLUDED_)
