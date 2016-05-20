#pragma once
#include "HomePageUI.h"
#include "PhoneFlowPageUI.h"

class CMainWnd : public WindowImplBase
{
public:
    CMainWnd();
    virtual ~CMainWnd();

    LPCTSTR GetWindowClassName() const { return _T("MainWnd"); };
    virtual CDuiString GetSkinFolder() override { return _T("Skin"); };
    virtual CDuiString GetSkinFile() override { return _T("Main.xml"); };

    void OnFinalMessage(HWND /*hWnd*/) { delete this; };

    virtual void Notify(TNotifyUI& msg) override;
    virtual void InitWindow() override;
    virtual CControlUI* CreateControl(LPCTSTR pstrClass) override;

public:
    void OnPrepare();

private:
    CButtonUI* m_pCloseBtn;

    CHomePageUI* m_pHomePageUI;
    CPhoneFlowPageUI* m_pPhoneFlowPageUI;
};

