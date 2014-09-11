#if !defined(AFX_PICBUTTON_H__06A7D28E_D479_4931_BDA7_E783F1649EDC__INCLUDED_)
#define AFX_PICBUTTON_H__06A7D28E_D479_4931_BDA7_E783F1649EDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PicButton.h : header file
//
#include "Picture.h"
/////////////////////////////////////////////////////////////////////////////
// CPicButton window

class CPicButton : public CButton
{
// Construction
public:
	CPicButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicButton)
	//}}AFX_VIRTUAL

	CPicture m_pic;
	long m_lPicID;
// Implementation
public:
	virtual ~CPicButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPicButton)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnClicked();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICBUTTON_H__06A7D28E_D479_4931_BDA7_E783F1649EDC__INCLUDED_)
