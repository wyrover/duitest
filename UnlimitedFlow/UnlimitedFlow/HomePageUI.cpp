#include "stdafx.h"
#include "HomePageUI.h"


CHomePageUI::CHomePageUI()
{
    CDialogBuilder builder;
    CContainerUI* m_pHomePage = static_cast<CContainerUI*>(builder.Create(_T("HomePage.xml"), (UINT)0));
    if (m_pHomePage)
    {
        this->Add(m_pHomePage);
    }
    else
    {
        this->RemoveAll();
    }
}


CHomePageUI::~CHomePageUI()
{
}

LPVOID CHomePageUI::GetInterface(LPCTSTR pstrName)
{
    if (_tcscmp(pstrName, _T("HomePage")) == 0) return static_cast<CHomePageUI*>(this);
    return CControlUI::GetInterface(pstrName);
}

void CHomePageUI::DoInit()
{
    
}

void CHomePageUI::DoEvent(TEventUI& event)
{
    CContainerUI::DoEvent(event);
}
