#include "stdafx.h"
#include "PhoneFlowPageUI.h"


CPhoneFlowPageUI::CPhoneFlowPageUI()
{
    CDialogBuilder builder;
    CContainerUI* m_pHomePage = static_cast<CContainerUI*>(builder.Create(_T("PhoneFlowPage.xml"), (UINT)0));
    if (m_pHomePage)
    {
        this->Add(m_pHomePage);
    }
    else
    {
        this->RemoveAll();
    }
}


CPhoneFlowPageUI::~CPhoneFlowPageUI()
{
}

LPVOID CPhoneFlowPageUI::GetInterface(LPCTSTR pstrName)
{
    if (_tcscmp(pstrName, _T("PhoneFlow")) == 0) return static_cast<CPhoneFlowPageUI*>(this);
    return CControlUI::GetInterface(pstrName);
}

void CPhoneFlowPageUI::DoInit()
{
    m_pWebBrowser = static_cast<CWebBrowserUI*>(FindSubControl(_T("phoneFlowBrowser")));
    ASSERT(m_pWebBrowser);
    m_pWebBrowser->SetWebBrowserEventHandler((CWebBrowserEventHandler*)&m_eventHandler);
    m_pWebBrowser->SetDelayCreate(false);//在初始化的时候执行创建，保证我们的EventHandler可以正式生效
    m_pWebBrowser->Navigate2(strPhoneFlowPageUrl);
}

void CPhoneFlowPageUI::DoEvent(TEventUI& event)
{
    CContainerUI::DoEvent(event);
}
