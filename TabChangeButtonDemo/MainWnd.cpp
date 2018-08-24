#include "MainWnd.h"
#include "resource.h"
#include <vector>


extern wchar_t g_newsListHeader[12][20];
extern wchar_t g_newsHeader[12][20];
extern wchar_t g_newsJsonHeader[12][40];

#include "TabChangeButton.hpp"
#include "ContainerEx.hpp"


// duilib �ײ����Ϣû�зַ����޷����ú���
CControlUI*  CMainWnd::CreateControl(LPCTSTR pstrClass)
{
	// ��Ҫ�ַ���Ϣ UIEVENT_SLIDEVERTICAL
	if (_tcsicmp(pstrClass, _T("SlideList")) == 0)
	{
		return new CSlideListUI();
	}
	// ûɶ�仯
	else if (_tcsicmp(pstrClass, _T("ListPureContainerElement")) == 0)
	{
		return new CListPureContainerElementUI();
	}
	// ��Ҫ�ַ���Ϣ UIEVENT_SLIDEVERTICAL
	else if (_tcsicmp(pstrClass, _T("SlideTileLayout")) == 0)
	{
		return new CSlideTileLayoutUI();
	}
	else if (_tcsicmp(pstrClass, _T("SlideHorizontalLayout")) == 0)
	{
		return new CSlideHorizontalLayoutUI();
	}
	else if (_tcsicmp(pstrClass, _T("SlideVerticalLayout")) == 0)
	{
		return new CSlideVerticalLayoutUI();
	}
	else if (_tcsicmp(pstrClass, _T("SlideContainerItem")) == 0)
	{
		return new CSlideContainerItemUI();
	}
	//else if (_tcsicmp(pstrClass, _T("SlideNumberLabel")) == 0)
	//{
	//	return new CSlideTileLayoutUI();
	//}
	else if (_tcsicmp(pstrClass, _T("VerticalLayoutEx")) == 0)
	{
		return new CVerticalLayoutExUI();
	}

	else if (_tcsicmp(pstrClass, _T("HorizontalLayoutEx")) == 0)
	{
		return new CHorizontalLayoutExUI();
	}
	else if (_tcsicmp(pstrClass, _T("SlideContainerItemEx")) == 0)
	{
		return new CSlideContainerItemExUI();
	}
	else if (_tcsicmp(pstrClass, _T("PercentHorizontalLayout")) == 0)
	{
		return new CPercentHorizontalLayoutUI();
	}
	else if (_tcsicmp(pstrClass, _T("PercentHorizontalLayoutEx")) == 0)
	{
		return new CPercentHorizontalLayoutUIEx();
	}
	// ����
	else if (_tcsicmp(pstrClass, _T("TabChangeButton")) == 0)
	{
		return new CTabChangeButtonUI();
	}
	// ����
	else if (_tcsicmp(pstrClass, _T("TabChangeOption")) == 0)
	{
		return new  CTabChangeOptionUI();
	}
	//else if (_tcsicmp(pstrClass, _T("ListEx")) == 0)
	//{
	//	return new CSlideTileLayoutUI();
	//}
	//else if (_tcsicmp(pstrClass, _T("ListExContainerElement")) == 0)
	//{
	//	return new CSlideTileLayoutUI();
	//}

	return NULL;
}

CMainWnd::CMainWnd()
{
}


CMainWnd::~CMainWnd()
{
}

CDuiString CMainWnd::GetSkinFolder()
{
	return L"TabChangeButtonDemo\\skin";
}

CDuiString CMainWnd::GetSkinFile()
{
	return L"main.xml";
}

LPCTSTR CMainWnd::GetWindowClassName()const
{
	return  L"MainWnd_WOW-TREND";
}



#ifdef ZIP_SKIN
UILIB_RESOURCETYPE CMainWnd::GetResourceType() const
{
	return UILIB_ZIPRESOURCE;
}

LPCTSTR CMainWnd::GetResourceID() const
{
	return MAKEINTRESOURCE(IDR_ZIP1);
}
#endif

void CMainWnd::Notify(TNotifyUI& msg)
{
	__super::Notify(msg);
}

void CMainWnd::InitWindow()
{
	return;
}