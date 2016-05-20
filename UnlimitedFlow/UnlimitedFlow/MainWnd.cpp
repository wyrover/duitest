#include "stdafx.h"
#include "MainWnd.h"
#include "FlowTaskWnd.h"

CMainWnd::CMainWnd()
{
}

CMainWnd::~CMainWnd()
{
}

void CMainWnd::Notify(TNotifyUI& msg)
{
    if (msg.sType == DUI_MSGTYPE_WINDOWINIT)
    {
        OnPrepare();
    }
    else if (msg.sType == DUI_MSGTYPE_CLICK)
    {
        if (msg.pSender == m_pCloseBtn)
        {
            PostQuitMessage(0);
            return;
        }
        //这里只保证点X退出应用程序，基类已经实现了最小化，最大化，还原，点X退出窗口等
    }
    else if (msg.sType == DUI_MSGTYPE_SELECTCHANGED)
    {
        CDuiString name = msg.pSender->GetName();
        CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("switch")));
        if (name == _T("option_homepage"))
            pControl->SelectItem(m_pHomePageUI);
        else if (name == _T("option_flow"))
            pControl->SelectItem(m_pPhoneFlowPageUI);
        else if (name == _T("option_push"))
            pControl->SelectItem(2);
        else if (name == _T("option_account"))
            pControl->SelectItem(3);
        else if (name == _T("option_pay"))
        {
            auto pFrame = new CFlowTaskWnd;
            ASSERT(pFrame);
            pFrame->Create(GetHWND(), _T("流量任务"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 800, 672);
            pFrame->CenterWindow();
            pFrame->ShowModal();
            
        }
            //pControl->SelectItem(4);
    }

    WindowImplBase::Notify(msg);
}

void CMainWnd::OnPrepare()
{
    int i = 0;
}

CControlUI* CMainWnd::CreateControl(LPCTSTR pstrClass)
{
    if (_tcscmp(pstrClass, _T("HomePage")) == 0)
    {
        if (m_pHomePageUI == NULL)
        {
            m_pHomePageUI = new CHomePageUI;
        }
        return m_pHomePageUI;
    }
    else if (_tcscmp(pstrClass, _T("PhoneFlowPage")) == 0)
    {
        if (m_pPhoneFlowPageUI == NULL)
        {
            m_pPhoneFlowPageUI = new CPhoneFlowPageUI;
        }
        return m_pPhoneFlowPageUI;
    }
    return NULL;
}

void CMainWnd::InitWindow()
{
    m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("closebtn")));
    
}

