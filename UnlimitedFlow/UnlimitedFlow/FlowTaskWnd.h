#pragma once
#include "FlowTaskBrowserEventHandler.h"

class CFlowTaskWnd : public WindowImplBase
{
public:
    CFlowTaskWnd();
    ~CFlowTaskWnd();

    LPCTSTR GetWindowClassName() const { return _T("FlowTaskWnd"); };
    virtual CDuiString GetSkinFolder() override { return _T("Skin"); };
    virtual CDuiString GetSkinFile() override { return _T("FlowTask.xml"); };

    void OnFinalMessage(HWND /*hWnd*/) { delete this; };

    virtual void InitWindow() override;

    virtual void Notify(TNotifyUI& msg) override;

private:
    CWebBrowserUI* m_pWebBrowser;
    CFlowTaskBrowserEventHandler m_taskEventHandler;
};

