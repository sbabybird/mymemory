// mymemoryView.cpp : implementation of the CMymemoryView class
//

#include "stdafx.h"
#include "mymemory.h"

#include "mymemoryDoc.h"
#include "mymemoryView.h"

#include "MemDC.h"
#include "Picture.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CMymemoryView
BOOL PlaySoundWithName(LPCSTR sName)
{
	HINSTANCE hRes=AfxGetInstanceHandle();
	
	HRSRC hr=FindResource(hRes,sName,"WAVE");
	
	HGLOBAL hg=LoadResource(hRes,hr);
	
	LPSTR lp=(LPSTR)LockResource(hg);
	
	BOOL bRet = sndPlaySound(lp,SND_MEMORY|SND_ASYNC);
	
	FreeResource(hg);
	
	return bRet;
}

IMPLEMENT_DYNCREATE(CMymemoryView, CView)

BEGIN_MESSAGE_MAP(CMymemoryView, CView)
	//{{AFX_MSG_MAP(CMymemoryView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_MESSAGE(PB_CLICKED, OnPbClicked)
	ON_WM_DESTROY()
	ON_MESSAGE(WM_HOTKEY, OnHotKey)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMymemoryView construction/destruction

CMymemoryView::CMymemoryView()
{
	m_pCurPB = NULL;

	m_iPlayCount = 0;
}

CMymemoryView::~CMymemoryView()
{
	for (int i = 0; i<wCount; i++)
		for (int j = 0; j<hCount; j++)
		{
			if (m_pButtons[i][j] != NULL)
			{
				delete m_pButtons[i][j];

				m_pButtons[i][j] = NULL;
			}
		}
}

BOOL CMymemoryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMymemoryView drawing

void CMymemoryView::OnDraw(CDC* pDC)
{
	CMymemoryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMemDC pMemDC(pDC);

	for (int i = 0; i<wCount; i++)
		for (int j = 0; j<hCount; j++)
		{
			CRect btRect;
			m_pButtons[i][j]->GetClientRect(&btRect);
			m_pButtons[i][j]->ClientToScreen(&btRect);
			this->ScreenToClient(&btRect);
			m_pButtons[i][j]->m_pic.Draw(pMemDC, CPoint(btRect.left,btRect.top), CSize(btRect.Width(), btRect.Height()));
		}
}

/////////////////////////////////////////////////////////////////////////////
// CMymemoryView diagnostics

#ifdef _DEBUG
void CMymemoryView::AssertValid() const
{
	CView::AssertValid();
}

void CMymemoryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMymemoryDoc* CMymemoryView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMymemoryDoc)));
	return (CMymemoryDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMymemoryView message handlers

void CMymemoryView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	// TODO: Add your specialized code here and/or call the base class
	AfxGetMainWnd()->SetMenu(NULL);
	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

int CMymemoryView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	srand(unsigned(time(0)));

	CArray<int, int> tmpArr;

	for (int t = 1; t<=18; t++)
	{
		tmpArr.Add(t);
		tmpArr.Add(t);
	}

	const int iCount = wCount*hCount;
	int m[iCount];
	for(int k=0;k<iCount;k++)m[k]=k;//填充数组
	srand(time(NULL));
	for(int p=0;p<iCount;p++)
	{
		t=rand()%(iCount-p);
		int itmp = m[p];
		m[p] = m[t+p];
		m[t+p] = itmp;
	}

	CString strPic;

	long lPicID = 0;
	
	for (int i = 0; i<wCount; i++)
		for (int j = 0; j<hCount; j++)
		{
			CPicButton* pButton = new CPicButton;

			pButton->Create("", WS_VISIBLE, CRect(0, 0, 0, 0), this, 0);

			pButton->m_lPicID = tmpArr.GetAt(m[lPicID++]);

			strPic.Format("IDR_PIC%d", pButton->m_lPicID);
			pButton->m_pic.Load("PIC", strPic);

			m_pButtons[i][j] = pButton;
		}

	RegisterHotKey( m_hWnd, 1001, MOD_CONTROL|MOD_ALT, 0x48/*VK_H*/ );
		
	RegisterHotKey( m_hWnd, 1002, MOD_CONTROL|MOD_ALT, 0x53/*VK_S*/ );

	return 0;
}

void CMymemoryView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	int iWidth = cx/wCount;
	
	int iHeight = cy/hCount;

	for (int i = 0; i<wCount; i++)
		for (int j = 0; j<hCount; j++)
		{
			m_pButtons[i][j]->MoveWindow(CRect(i*iWidth, j*iHeight, i*iWidth+iWidth, j*iHeight+iHeight));
		}
	
}

BOOL CMymemoryView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return FALSE;

	//return CView::OnEraseBkgnd(pDC);
}

void CMymemoryView::OnPbClicked(WPARAM w, LPARAM l)
{
	CPicButton* pPB = (CPicButton*)l;

	if (m_pCurPB == NULL)
	{
		m_pCurPB = pPB;

		pPB->ShowWindow(SW_HIDE);

		PlaySoundWithName("IDR_TOCK");
	}
	else
	{
		if (m_pCurPB->m_lPicID == pPB->m_lPicID)
		{
			pPB->ShowWindow(SW_HIDE);
			m_pCurPB = NULL;
			PlaySoundWithName("IDR_SHIELDSDOWN");
		}
		else
		{
			pPB->ShowWindow(SW_HIDE);
			m_pCurPB->ShowWindow(SW_SHOW);
			m_pCurPB = pPB;
			PlaySoundWithName("IDR_TOCK");
		}
	}

	if (IsAllOK())
	{
		m_iPlayCount++;

		PlaySoundWithName("IDR_CHEER");

		if (m_iPlayCount>2)
		{
			CString strMsg;

			strMsg.Format("你已经玩了%d盘儿了\n还要再玩一盘儿吗？", m_iPlayCount);

			if (MessageBox(strMsg, "恭喜，你赢了!", MB_ICONQUESTION|MB_YESNO) == IDYES)
			{
				if (m_iPlayCount == 5)
				{
					MessageBox("你都连续玩了5盘儿了，不让你玩儿了", "注意休息", MB_ICONINFORMATION);
					exit(0);
				}
				InitGame();
			}
		}

		if (MessageBox("还要再玩一盘儿吗？", "恭喜，你赢了!", MB_ICONQUESTION|MB_YESNO) == IDYES)
		{
			InitGame();
		}
		else
		{
			exit(0);
		}
	}
}

void CMymemoryView::InitGame()
{
	srand(unsigned(time(0)));
	
	CArray<int, int> tmpArr;
	
	for (int t = 1; t<=18; t++)
	{
		tmpArr.Add(t);
		tmpArr.Add(t);
	}
	
	const int iCount = 36;
	int m[iCount];
	for(int k=0;k<iCount;k++)m[k]=k;//填充数组
	for(int p=0;p<iCount;p++)
	{
		t=rand()%(iCount-p);
		int itmp = m[p];
		m[p] = m[t+p];
		m[t+p] = itmp;
	}
	
	CString strPic;
	
	long lPicID = 0;
	
	for (int i = 0; i<wCount; i++)
		for (int j = 0; j<hCount; j++)
		{
			CPicButton* pButton = m_pButtons[i][j];
			
			pButton->m_lPicID = tmpArr.GetAt(m[lPicID++]);
			
			strPic.Format("IDR_PIC%d", pButton->m_lPicID);
			pButton->m_pic.Load("PIC", strPic);
			
			pButton->ShowWindow(SW_SHOW);
		}
}

BOOL CMymemoryView::IsAllOK()
{
	for (int i = 0; i<wCount; i++)
		for (int j = 0; j<hCount; j++)
		{
			if (m_pButtons[i][j]->IsWindowVisible())
			{
				return FALSE;
			}
		}
	return TRUE;
}

void CMymemoryView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	CMymemoryDoc *pdoc=(CMymemoryDoc*)GetDocument();
	
	pdoc->SetTitle("煦筵小朋友6.1快乐");
}

void CMymemoryView::OnDestroy() 
{
	UnregisterHotKey( m_hWnd, 1001 );
	
	UnregisterHotKey( m_hWnd, 1002 );

	CView::OnDestroy();	
}

LRESULT CMymemoryView::OnHotKey(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 1001)
	{
		for (int i = 0; i<wCount; i++)
			for (int j = 0; j<hCount; j++)
			{
				if (m_pButtons[i][j]->IsWindowVisible())
				{
					m_arrHelp.Add(m_pButtons[i][j]);
					m_pButtons[i][j]->ShowWindow(SW_HIDE);
					SetTimer(1, 5000, NULL);
				}
		}
	}
	else if (wParam == 1002)
	{
		MessageBox("谁知盘中餐粒粒皆辛苦");
	}

	return S_OK;
}

void CMymemoryView::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		KillTimer(1);

		for (int i = 0; i<m_arrHelp.GetSize(); i++)
		{
			m_arrHelp.GetAt(i)->ShowWindow(SW_SHOW);
		}

		m_arrHelp.RemoveAll();
	}

	CView::OnTimer(nIDEvent);
}
