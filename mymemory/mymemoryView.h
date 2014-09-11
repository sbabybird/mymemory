// mymemoryView.h : interface of the CMymemoryView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMEMORYVIEW_H__2AAEF751_E1B3_404C_9F34_20FD3FB1FACF__INCLUDED_)
#define AFX_MYMEMORYVIEW_H__2AAEF751_E1B3_404C_9F34_20FD3FB1FACF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PicButton.h"
#include <Afxtempl.h>

const int wCount = 6;

const int hCount = 6;

class CMymemoryView : public CView
{
protected: // create from serialization only
	CMymemoryView();
	DECLARE_DYNCREATE(CMymemoryView)

// Attributes
public:
	CMymemoryDoc* GetDocument();

// Operations
public:

	CPicButton* m_pButtons[wCount][hCount];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymemoryView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMymemoryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPicButton* m_pCurPB;

	CArray<CPicButton*, CPicButton*> m_arrHelp;

	int m_iPlayCount;

	BOOL IsAllOK();

	void InitGame();

// Generated message map functions
protected:
	//{{AFX_MSG(CMymemoryView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPbClicked(WPARAM w, LPARAM l);
	afx_msg void OnDestroy();	
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	LRESULT OnHotKey( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mymemoryView.cpp
inline CMymemoryDoc* CMymemoryView::GetDocument()
   { return (CMymemoryDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEMORYVIEW_H__2AAEF751_E1B3_404C_9F34_20FD3FB1FACF__INCLUDED_)
