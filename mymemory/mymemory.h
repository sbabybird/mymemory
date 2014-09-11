// mymemory.h : main header file for the MYMEMORY application
//

#if !defined(AFX_MYMEMORY_H__2EA99DB4_6863_465C_B8BB_93761ACB81CC__INCLUDED_)
#define AFX_MYMEMORY_H__2EA99DB4_6863_465C_B8BB_93761ACB81CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#define PB_CLICKED (WM_USER+100)
/////////////////////////////////////////////////////////////////////////////
// CMymemoryApp:
// See mymemory.cpp for the implementation of this class
//

class CMymemoryApp : public CWinApp
{
public:
	CMymemoryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymemoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMymemoryApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEMORY_H__2EA99DB4_6863_465C_B8BB_93761ACB81CC__INCLUDED_)
