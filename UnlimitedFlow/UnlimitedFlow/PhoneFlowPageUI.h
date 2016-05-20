#pragma once
#include "PhoneFlowBrowserEventHandler.h"

class CPhoneFlowPageUI : public CContainerUI
{
public:
    CPhoneFlowPageUI();
    ~CPhoneFlowPageUI();

    virtual LPCTSTR GetClass() const override { return _T("PhoneFlowPageUI"); };
    virtual LPVOID GetInterface(LPCTSTR pstrName) override;

    virtual void DoInit() override;

    virtual void DoEvent(TEventUI& event) override;


private:
    CWebBrowserUI* m_pWebBrowser;

    CPhoneFlowBrowserEventHandler m_eventHandler;
};

