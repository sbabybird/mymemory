// mymemoryDoc.cpp : implementation of the CMymemoryDoc class
//

#include "stdafx.h"
#include "mymemory.h"

#include "mymemoryDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMymemoryDoc

IMPLEMENT_DYNCREATE(CMymemoryDoc, CDocument)

BEGIN_MESSAGE_MAP(CMymemoryDoc, CDocument)
	//{{AFX_MSG_MAP(CMymemoryDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymemoryDoc construction/destruction

CMymemoryDoc::CMymemoryDoc()
{
	// TODO: add one-time construction code here

}

CMymemoryDoc::~CMymemoryDoc()
{
}

BOOL CMymemoryDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMymemoryDoc serialization

void CMymemoryDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMymemoryDoc diagnostics

#ifdef _DEBUG
void CMymemoryDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMymemoryDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMymemoryDoc commands
