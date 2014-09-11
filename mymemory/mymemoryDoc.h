// mymemoryDoc.h : interface of the CMymemoryDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMEMORYDOC_H__C15FEBF6_9CA4_449B_92FC_C195897C9100__INCLUDED_)
#define AFX_MYMEMORYDOC_H__C15FEBF6_9CA4_449B_92FC_C195897C9100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMymemoryDoc : public CDocument
{
protected: // create from serialization only
	CMymemoryDoc();
	DECLARE_DYNCREATE(CMymemoryDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMymemoryDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMymemoryDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMymemoryDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEMORYDOC_H__C15FEBF6_9CA4_449B_92FC_C195897C9100__INCLUDED_)
