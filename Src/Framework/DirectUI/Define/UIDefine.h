#ifndef UIDefine_h__
#define UIDefine_h__
/*/////////////////////////////////////////////////////////////
//
// �ļ�����	:	UIDefine.h
// ������	: 	daviyang35@gmail.com
// ����ʱ��	:	2014-11-07 17:01:26
// ˵��		:	
/////////////////////////////////////////////////////////////*/
#pragma once

// namespace Micro
#if 1
#define DIRECTUI_BEGIN_NAMESPCE namespace DirectUI {
#define DIRECTUI_END_NAMESPCE }
#define DIRECTUI_USING_NAMESPACE using namespace DirectUI;
#else
#define DIRECTUI_BEGIN_NAMESPCE 
#define DIRECTUI_END_NAMESPCE
#define DIRECTUI_USING_NAMESPACE
#endif

// compiler output Micro
#define chSTR(x)	   #x
#define chSTR2(x)	chSTR(x)
#define TODO(desc) message(__FILE__ "(" chSTR2(__LINE__) ") : TODO ==> " #desc)
#define FIXED(desc) message(__FILE__ "(" chSTR2(__LINE__) ") : FIXED ==> " #desc)

#ifndef CDuiString
#ifdef _UNICODE
#define CDuiString std::wstring
#else
#define CDuiString std::string
#endif // _UNICODE
#endif // CDuiString

#define CDuiStringA	std::string
#define CDuiStringW	std::wstring

#ifndef ASSERT
#define ASSERT(expr)  _ASSERTE(expr)
#endif

#ifndef GET_WPARAM
#define GET_WPARAM(wp, lp)                      (wp)
#endif // !GET_WPARAM
#ifndef GET_LPARAM
#define GET_LPARAM(wp, lp)                      (lp)
#endif // !GET_LPARAM
#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#endif // !GET_X_LPARAM
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))
#endif // !GET_Y_LPARAM
#ifndef GetAValue
#define GetAValue(rgb)      (LOBYTE((rgb)>>24))
#endif // !GetAValue
#ifndef GetWindowOwner
#define     GetWindowOwner(hwnd)    GetWindow(hwnd, GW_OWNER)
#endif // !GetWindowOwner


class CControlUI;
class IUIRender;
class CObjectUI;
class ImageObject;
class FontObject;
class TemplateObject;

#define UI_DECLARE_DYNCREATE() \
	static CControlUI* CreateObject()\

#define UI_IMPLEMENT_DYNCREATE(ClassName)\
	CControlUI* ClassName::CreateObject()\
{ return new ClassName; }\

#define UI_REGISTER_DYNCREATE(ControlName, ClassName)\
	CUIEngine::GetInstance()->RegisterControl(ControlName, &ClassName::CreateObject)

#define UI_UNREGISTER_DYNCREATE(ControlName)\
	CUIEngine::GetInstance()->UnregisterControl(ControlName)

typedef CControlUI* (_cdecl *PROCCONTROLCREATE)();
typedef std::vector<CDuiString> VecString;
typedef std::map<CDuiString,CDuiString> StringMap;
typedef StringMap AttributeMap;
typedef std::map<CDuiString,TemplateObject*> TemplateMap;
typedef std::map<CDuiString,ImageObject*>	ImagePoolMap;
typedef std::vector<FontObject*>		FontPoolVector;

static DWORD WM_DIRECTUI_MESSAGE	= ::RegisterWindowMessage(_T("WM_DIRECTUI_MESSAGE"));


static UINT MapKeyState()
{
	UINT uState = 0;
	if( ::GetKeyState(VK_CONTROL) < 0 )
		uState |= MK_CONTROL;
	if( ::GetKeyState(VK_RBUTTON) < 0 )
		uState |= MK_LBUTTON;
	if( ::GetKeyState(VK_LBUTTON) < 0 )
		uState |= MK_RBUTTON;
	if( ::GetKeyState(VK_SHIFT) < 0 )
		uState |= MK_SHIFT;
	if( ::GetKeyState(VK_MENU) < 0 )
		uState |= MK_ALT;
	return uState;
}

typedef struct _stTFontInfo
{
	HFONT hFont;
	CDuiString strFaceName;
	int iSize;
	bool bBold;
	bool bUnderline;
	bool bItalic;
	TEXTMETRIC tm;
} TFontInfo;

typedef struct _stTImageInfo
{
	HBITMAP hBitmap;
	int nX;
	int nY;
	int delay;
	bool alphaChannel;
	CDuiString strResType;
	DWORD dwMask;
} TImageInfo;

typedef struct _stFindTabInfo
{
	CControlUI* pFocus;	// ��ǰ����ؼ�
	CControlUI* pLast;		
	bool bForward;			// true ��һ���ؼ���false ��һ���ؼ�
	bool bNextIsIt;
} FindTabInfo;

typedef struct _stFindShortCut
{
	TCHAR ch;
	bool bPickNext;
} FindShortCut;

typedef struct _stTimerInfo
{
	CControlUI* pSender;
	UINT nLocalID;
	HWND hWnd;
	UINT uWinTimer;
	bool bKilled;
} TimerInfo;

// Structure for notifications from the system
// to the control implementation.
typedef struct _stTEventUI
{
	DWORD dwType;
	CControlUI* pSender;
	DWORD dwTimestamp;
	POINT ptMouse;
	TCHAR chKey;
	WORD wKeyState;
	WPARAM wParam;
	LPARAM lParam;

	_stTEventUI()
		: dwType(0)
		, pSender(NULL)
		, dwTimestamp(0)
		, chKey(0)
		, wKeyState(0)
		, wParam(0)
		, lParam(0)
	{
		ptMouse.x = 0;
		ptMouse.y = 0;
	}
} TEventUI;

// Structure for notifications to the outside world
typedef struct _stTNotifyUI 
{
	DWORD dwType;
	CControlUI* pSender;
	DWORD dwTimestamp;	// ʱ���
	POINT ptMouse;
	WPARAM wParam;
	LPARAM lParam;
	_stTNotifyUI()
		: pSender(NULL)
		, dwTimestamp(0)
		, wParam(0)
		, lParam(0)
	{
		ptMouse.x = 0;
		ptMouse.y = 0;
	}
} TNotifyUI;

// Listener interface
class INotifyUI
{
public:
	virtual void Notify(TNotifyUI *pMsg) = 0;
};

// MessageFilter interface
class IMessageFilterUI
{
public:
	virtual LRESULT MessageFilter(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled) = 0;
};

class ITranslateAccelerator
{
public:
	virtual LRESULT TranslateAccelerator(MSG *pMsg) = 0;
};

class IContainerUI
{
public:
	virtual CControlUI* GetItemAt(int iIndex) const = 0;
	virtual int GetItemIndex(CControlUI* pControl) const  = 0;
	virtual bool SetItemIndex(CControlUI* pControl, int iIndex)  = 0;
	virtual int GetCount() const = 0;
	virtual bool Add(CControlUI* pControl) = 0;
	virtual bool AddAt(CControlUI* pControl, int iIndex)  = 0;
	virtual bool Remove(CControlUI* pControl) = 0;
	virtual bool RemoveAt(int iIndex)  = 0;
	virtual void RemoveAll() = 0;
};

// INotify�ӿ�ʹ�õ�Type
typedef enum _enUINOTIFY
{
	UINOTIFY__FIRST,

	// �����¼�
	UINOTIFY_WindowInit,
	UINOTIFY_WindowPaint,

	// ͨ���¼�
	UINOTIFY_LBTNCLICK,
	UINOTIFY_RBTNCLICK,
	UINOTIFY_LDBCLICK,
	UINOTIFY_RDBCLICK,
	UINOTIFY_SELCHANGE,//selchange
	UINOTIFY_SETFOCUS,//setfocus
	UINOTIFY_KILLFOCUS,//killfocus
	UINOTIFY_HOVER,//houver
	UINOTIFY_TIMER,//timer
	UINOTIFY_CONTEXTMENU,
	UINOTIFY_DROPFILES,//dropfiles
	// �༭���¼�
	UINOTIFY_EN_CHANGE,//change
	UINOTIFY_EN_IMESTART,//imestart
	UINOTIFY_EN_IMEEND,//imeend
	UINOTIFY_EN_IMEING,//imeing
	UINOTIFY_EN_LIMIT,//limit
	UINOTIFY_EN_KEYDOWN,  // keydouwn add by zhangxin 2011.9.7
	UINOTIFY_EN_LISTCLICK,//listclick
	UINOTIFY_EN_LISTRETURN,//listreturn
	// ���οؼ��¼�
	UINOTIFY_TVN_ITEMEXPENDED,
	UINOTIFY_TVN_ITEMEXPENDING,
	UINOTIFY_TVN_BEGINDRAG,
	UINOTIFY_TVN_ENDDRAG,
	UINOTIFY_TVN_CHECK,
	// Slider�¼�poschange   selchange beginchange endchange
	UINOTIFY_TRBN_POSCHANGE,
	UINOTIFY_TRBN_SELCHANGE,
	UINOTIFY_TRBN_BEGINCHANGE,
	UINOTIFY_TRBN_ENDCHANGE,
	// richedit�ؼ��¼� 
	UINOTIFY_RE_DBCLICK_IMAGE,
	UINOTIFY_RE_CLICK_IMAGE_THUMBNAIL_BTN,
	UINOTIFY_RE_CLICK_LINK,
	// ActiveX�ؼ�
	UINOTIFY_ACTIVEX_SHOW,
	UINOTIFY_ACTIVEX_NAVIGATE_BEFORE,
	UINOTIFY_ACTIVEX_NAVIGATE_AFTER,
	UINOTIFY_ACTIVEX_LODING,
	UINOTIFY_ACTIVEX_LODE_DONE,
	UINOTIFY_ACTIVEX_LOAD_ERROR,
	UINOTIFY_ACTIVEX_CLOSE,
	// Animation
	UINOTIFY_ANIMATION_END,
	// ComboBox
	UINOTIFY_CBN_BEFOREDROPDOWN,
	UINOTIFY_CBN_DROPDOWN,
	UINOTIFY_CBN_CHECK,
	// Tab
	UINOTIFY_TAB_ADD,
	UINOTIFY_TAB_CLOSE,
	UINOTIFY_TAB_Ext,
	UINOTIFY_TAB_DBCLICK,
	//�ȼ�
	UINOTIFY_HOTKEY, 
	// ���ڻ�ԭʱ����Ϣ

	UINOTIFY__LAST = UINOTIFY__FIRST + 1000,
	UINOTIFY__USER,	/// �����Զ���ؼ���Ϣ�����.
	UINOTIFY__USER_LAST = UINOTIFY__USER + 1000,
	// Ƥ���¼�

}UINOTIFY;

// Control�ڲ����ݵ�EventHandler
typedef enum _UIEVENT
{
	UIEVENT__FIRST = 0,
	UIEVENT__KEYBEGIN,			// Keyboard Begin
	UIEVENT_KEYDOWN,			// KeyDown
	UIEVENT_KEYUP,					// KeyUp
	UIEVENT_CHAR,					// Char
	UIEVENT_IME_CHAR,			// IME Char
	UIEVENT_IME_START,
	UIEVENT_IME_END,
	UIEVENT_IME_ING,
	UIEVENT_SYSKEY,				// SystemKey
	UIEVENT__KEYEND,				// Keyboard End

	UIEVENT__MOUSEBEGIN,	// Mouse Begin
	UIEVENT_MOUSEMOVE,		// MouseMove
	UIEVENT_MOUSELEAVE,		// MouseLeave
	UIEVENT_MOUSEENTER,		// MouseEnter
	UIEVENT_MOUSEHOVER,	// MouseHover
	UIEVENT_LBUTTONDOWN,// MouseLeftButtonDown
	UIEVENT_LBUTTONUP,		// MouseLeftButtonUp
	UIEVENT_LDBLCLICK,			// MouseLeftButtonDoubleClick
	UIEVENT_RBUTTONDOWN,// MouseRightButtonDown
	UIEVENT_RBUTTONUP,		// MouseRightButtonup
	UIEVENT_RDBLCLICK,			// MouseRightButtonDoubleClick
	UIEVENT_SCROLLWHEEL,	// MouseMiddleScrollWheel
	UIEVENT__MOUSEEND,		// Mouse End

	UIEVENT_CONTEXTMENU,
	UIEVENT_KILLFOCUS,
	UIEVENT_SETFOCUS,
	UIEVENT_VSCROLL,
	UIEVENT_HSCROLL,
	UIEVENT_WINDOWSIZE,
	UIEVENT_SETCURSOR,
	UIEVENT_TIMER,
	UIEVENT_NOTIFY,
	UIEVENT_COMMAND,
	UIEVENT_DROPFILES,
	UIEVENT_MENUITEM_CLICK,
	UIEVENT__LAST,
}UIEVENT;

// Flags for CControlUI::GetControlFlags()
#define UIFLAG_TABSTOP       0x00000001
#define UIFLAG_SETCURSOR     0x00000002
#define UIFLAG_WANTRETURN    0x00000004

// Flags for FindControl()
#define UIFIND_ALL           0x00000000
#define UIFIND_VISIBLE       0x00000001
#define UIFIND_ENABLED       0x00000002
#define UIFIND_HITTEST       0x00000004
#define UIFIND_TOP_FIRST     0x00000008
#define UIFIND_ME_FIRST      0x80000000

// Flags for the CDialogLayout stretching
#define UISTRETCH_NEWGROUP   0x00000001
#define UISTRETCH_NEWLINE    0x00000002
#define UISTRETCH_MOVE_X     0x00000004
#define UISTRETCH_MOVE_Y     0x00000008
#define UISTRETCH_SIZE_X     0x00000010
#define UISTRETCH_SIZE_Y     0x00000020

#define UISTATE_ALL 0x80000000

// Flags used for controlling the paint
#define UISTATE_Normal		0x00000000		// Normal
#define UISTATE_Hover			0x00000001		// Hover
#define UISTATE_Pushed		0x00000002		// Pushed
#define UISTATE_Focused		0x00000004		// Focused
#define UISTATE_Selected		0x00000008		// Selected
#define UISTATE_Disabled		0x00000010		// Disabled
#define UISTATE_Checked		0x00000020		// CheckBox RadioButton Selected Flag
#define UISTATE_ReadOnly		0x00000040
#define UISTATE_Captured		0x00000080

#endif // UIDefine_h__