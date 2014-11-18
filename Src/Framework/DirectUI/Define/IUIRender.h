#ifndef IDirectUIRender_h__
#define IDirectUIRender_h__
/*/////////////////////////////////////////////////////////////
//
// �ļ�����	:	IDirectUIRender.h
// ������	: 	daviyang35@gmail.com
// ����ʱ��	:	2014-11-08 21:23:38
// ˵��		:	Render�ӿ�
/////////////////////////////////////////////////////////////*/
#pragma once
#include "Utils/UIUtils.h"

class CRenderClip;
class ImageObject;
class FontObject;

class DIRECTUI_API CMemDC
{
public:
	CMemDC();
	~CMemDC();

public:
	void Create(HDC hDC,int cx,int cy);
	void Clear();

	BOOL IsValid();
	HDC GetSafeHdc();
	HBITMAP GetHBitmap();
	int GetWidth();;
	int GetHeight();;

private:
	HDC m_hMemDC;
	HBITMAP m_hMemBmp;
	HBITMAP m_hOldBmp;
	int m_cx;
	int m_cy;
};

class DIRECTUI_API IUIRender
{
public:
	IUIRender();
	virtual ~IUIRender();

public:
	virtual void SetDevice(CMemDC *memDC);
	virtual void SetDevice(HDC hDc);
	virtual HDC GetPaintDC();

	virtual void SetInvalidateRect(RECT& rect);
	virtual RECT GetInvalidateRect();

public:	// ��ͼ����Ӧ�øɵ����飺�����֣���ͼƬ�����ߣ�������
	// �����ɫ
	virtual void DrawColor(LPCRECT rcSrc,DWORD dwColor);

	virtual void DrawImage(ImageObject* pImageObj, int nAlpha, int x, int y, int nIndex = 0, bool bHole =false);
	virtual void DrawImage9Gird(ImageObject* pImageObj,LPCRECT lp9Gird, int nAlpha, int x, int y, int nIndex = 0, bool bHole =false);
	virtual void DrawImage(ImageObject* pImageObj, int nAlpha, RECT& rect, int nIndex = 0, bool bHole =false);
	virtual void DrawImage(ImageObject* pImageObj, RECT& rcSrc,  RECT& rcDest, int nIndex = 0);

	void DrawText();
	void DrawLine();
	void DrawRect();
protected:
	HDC m_hDC;
	CMemDC *m_pMemDC;
	CDuiRect m_rcInvalidate;
};

class DIRECTUI_API ITextRender
{

};

class DIRECTUI_API CRenderClip
{
public:
	CRenderClip();
	~CRenderClip();
	RECT rcItem;
	HDC hDC;
	HRGN hRgn;
	HRGN hOldRgn;

	// ����һ���������򣬽���ͼ������rc������
	static void GenerateClip(HDC hDC, RECT rc, CRenderClip& clip);

	// ����һ��Բ�Ǽ������򣬽���ͼ������rc������
	// width��height ��/����Բ�ǻ���
	static void GenerateRoundClip(HDC hDC, RECT rc, RECT rcItem, int width, int height, CRenderClip& clip);

	// ʹ�û�Ծ������Ϊ��ͼ��
	static void UseOldClipBegin(HDC hDC, CRenderClip& clip);

	// �ָ��ؼ�������Ծ��
	static void UseOldClipEnd(HDC hDC, CRenderClip& clip);
};

#endif // IDirectUIRender_h__