#pragma once
#ifndef __DEFAINE_HPP_2014_03_20
#define __DEFAINE_HPP_2014_03_20


#include <tchar.h>
#include <string>
#include <sstream> // wstringstream


#define DUI_CTR_MUTIBTNLAYOUT					(_T("MutiBtnLayout"))				// ��״̬��ť����
#define DUI_CTR_SLOCKBTNLAYOUT					(_T("SLockBtnLayout"))				// ������ť����
#define DUI_CTR_SRESETBTNLAYOUT					(_T("SResetBtnLayout"))				// �Ը�λ��ť����
#define DUI_CTR_HORSLIDEBTNLAYOUT				(_T("HorSlideBtnLayout"))			// ˮƽ�϶���ť����
#define DUI_CTR_VERSLIDEBTNLAYOUT				(_T("VerSlideBtnLayout"))			// ˮƽ�϶���ť����
#define DUI_CTR_BTNLAYOUTITEM					(_T("BtnLayoutItem"))				// ��ť����ITEM
#define DUI_CTR_METERPOINTER					(_T("MeterPointer"))				// �Ǳ�ָ��
#define DUI_CTR_ALERT							(_T("AlertPage"))					// ���洰��
#define DUI_CTR_LAYERED							(_T("Layered"))						// �ֲ㴰��
#define DUI_CTR_CURVE							(_T("Curve"))						// ��ά���߱�
#define DUI_CTR_SLIDELIST						(_T("SlideList"))					// ���϶����б�
#define DUI_CTR_LISTPURECONTAINERELEMENT		(_T("ListPureContainerElement"))	// �����������б��¼���������б������õı�����ɫ��ͼƬ��Ӱ��
#define DUI_CTR_SLIDETILELAYOUT					(_T("SlideTileLayout"))				// ���϶��Ĵ�ש����
#define DUI_CTR_SLIDEHORIZONTALLAYOUT			(_T("SlideHorizontalLayout"))		// ���϶���ˮƽ����
#define DUI_CTR_SLIDEVERTICALLAYOUT				(_T("SlideVerticalLayout"))			// ���϶��Ĵ�ֱ����
#define DUI_CTR_SLIDECONTAINERITEM				(_T("SlideContainerItem"))			// ���϶����������������������ø�������϶�����
#define DUI_CTR_SLIDENUMBERLABEL				(_T("SlideNumberLabel"))			// ���϶���������ʾ
#define DUI_CTR_GIF								(_T("Gif"))							// GIF�ؼ�
#define DUI_CTR_GIFBUTTON						(_T("GifButton"))					// GIF��ť�ؼ�
#define DUI_CTR_VERTICALLAYOUTEX				(_T("VerticalLayoutEx"))			// ��չ�Ĵ�ֱ����
#define DUI_CTR_HORIZONTALLAYOUTEX				(_T("HorizontalLayoutEx"))			// ��չ��ˮƽ����
#define DUI_CTR_SLIDECONTAINERITEMEX			(_T("SlideContainerItemEx"))		// ��չ�Ŀ��϶����������������������ø�������϶�����
#define DUI_CTR_PERCENTHORIZONTALLAYOUT			(_T("PercentHorizontalLayout"))		// �������ؼ����аٷֱȿ��Ƶ�����
#define DUI_CTR_PERCENTHORIZONTALLAYOUTEX		(_T("PercentHorizontalLayoutEx"))	// �������ؼ����аٷֱȿ��ƣ����ұ�����԰ٷֱ����ô�С������
#define DUI_CTR_TABCHAGEBUTTON					(_T("TabChangeButton"))				// �л�TabLayout��Button
#define DUI_CTR_TABCHAGEOPTION					(_T("TabChangeOption"))				// �л�TabLayout��Option
#define DUI_CTR_LISTEX							(_T("ListEx"))						// ��չ��LIST 	
#define DUI_CTR_LISTEXCONTAINERELEMENT			(_T("ListExContainerElement"))		// ��չ��LIST

// Flags for CControlUI::GetControlFlags()
#define UIFLAG_DISLABLESLIDE    0x00100000		// ��������ӵĻ������ܣ�ʹ��ԭʼ��������
#define UIFLAG_ANIMATION		0x00200000		// ���ն�����ʱ����Ϣ

namespace DuiLib
{
	typedef enum SLIDETYPE
	{
		SLIDETYPE_NULL,
		SLIDETYPE_HORIZONTAL,
		SLIDETYPE_VERTICAL,
	};
	typedef enum EVENTTYPE_UI_EX
	{
		UIEVENT_EX__FIRST = UIEVENT__LAST,
		UIEVENT_RBUTTONUP,
		UIEVENT_MBUTTONDOWN,
		UIEVENT_MBUTTONUP,
		UIEVENT_SLIDE__FIRST,
		UIEVENT_SLIDEBEGIN,
		UIEVENT_SLIDEHORIZONTAL,
		UIEVENT_SLIDEVERTICAL,
		UIEVENT_SLIDEEND,
		UIEVENT_SLIDE__LAST,
		UIEVENT_LBUTTONLONGPRESS,
		UIEVENT_ANIMATION,
		UIEVENT_EX__LAST,
	};
	template<typename T_DST, typename T_SRC>
	T_DST xk_cast(T_SRC _src)
	{
#	ifdef UNICODE
		std::wstringstream ss;
#	else
		std::stringstream ss;
#	endif
		ss << _src;
		T_DST dst;
		ss >> dst;
		return dst;
	}
}

#define  DUILIB_ATOI(str){}

#endif