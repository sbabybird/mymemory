// PicButton.cpp : implementation file
//

#include "stdafx.h"
#include "mymemory.h"
#include "PicButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPicButton

CPicButton::CPicButton()
{
}

CPicButton::~CPicButton()
{
}


BEGIN_MESSAGE_MAP(CPicButton, CButton)
	//{{AFX_MSG_MAP(CPicButton)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPicButton message handlers

void CPicButton::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CButton::OnLButtonDblClk(nFlags, point);
}

void CPicButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CButton::OnLButtonUp(nFlags, point);
}

void CPicButton::OnClicked() 
{
	/*if (this->GetCheck() == 1)
	{
		this->SetCheck(0);
	}
	else
	{
		this->SetCheck(1);
	}
	this->ShowWindow(SW_HIDE);*/

	this->GetParent()->SendMessage(PB_CLICKED, WPARAM(0), LPARAM(this));
}
