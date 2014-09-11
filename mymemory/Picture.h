// Picture.h: interface for the CPicture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICTURE_H__6C920FA9_BC68_405E_B222_B60BD3ACC903__INCLUDED_)
#define AFX_PICTURE_H__6C920FA9_BC68_405E_B222_B60BD3ACC903__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPicture  
{
public:
	CPicture();
	virtual ~CPicture();

	bool			Load(CString sResourceType, CString sResource);
	bool			Load(CString sFileName);
	bool			Draw(CDC* pDC);
	bool			Draw(CDC* pDC, CPoint Pos);
	bool			Draw(CDC* pDC, CPoint Pos, CSize Size);
	bool			Draw(CDC* pDC, double nSizeRatio);
	bool			Draw(CDC* pDC, CPoint Pos, double nSizeRatio);
	CSize			GetSize(CDC* pDC);
private:
	static	bool	GetResource(LPSTR lpName, LPSTR lpType, void* pResource, int& nBufSize);
	void			UnLoad();
	bool			LoadFromBuffer(BYTE* pBuff, int nSize);
	bool			Draw(CDC* pDC, int x, int y, int cx, int cy);
	IPicture*		m_pPicture;
	enum
	{
		HIMETRIC_INCH	= 2540
	};
};

#endif // !defined(AFX_PICTURE_H__6C920FA9_BC68_405E_B222_B60BD3ACC903__INCLUDED_)
