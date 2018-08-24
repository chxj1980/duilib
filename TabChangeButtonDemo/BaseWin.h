#pragma once
#include "..\DuiLib\UIlib.h"
using namespace DuiLib;

// ��Ϣ���࣬���е�duilib���ڵ��¼������࣬���������Ϣ
class CBaseNotify
{
public:
	virtual ~CBaseNotify(){};
	// ��Ϣ��Ӧ
	virtual void Notify(TNotifyUI& msg,bool& bHandle) = 0;
};

class CBaseWin :
	public WindowImplBase
//	, public CControlUI
{
protected:
	CBaseWin();
public:
	virtual ~CBaseWin();
public:
	// ��Ϣ·��
	virtual void Notify(TNotifyUI& msg);
	// Ĭ������Ϊ skin
	virtual CDuiString GetSkinFolder();
	// ָ��xml·�������������д
	virtual CDuiString GetSkinFile() = 0;
	// ָ�򴰿����������������д
	virtual LPCTSTR GetWindowClassName() const = 0;
	HWND GetHWnd() const;
	// ��ȡ�����ھ��
	HWND GetParent();
public:
	// ��duilib����Win32������ʾ����
	//virtual void SetInternVisible(bool bVisible = true);
	// ��duilib����Win32������ʾλ��
	//virtual void SetPos(RECT rc);
protected:
	// ��Ϣ·�ɣ������ഴ����ɾ��
	CBaseNotify*	m_pBaseNotify;
};

