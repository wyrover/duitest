#include "stdafx.h"
#include "FlowTaskWnd.h"


CFlowTaskWnd::CFlowTaskWnd()
{
}


CFlowTaskWnd::~CFlowTaskWnd()
{
    int i = 0;
}

void CFlowTaskWnd::InitWindow()
{
    m_pWebBrowser = static_cast<CWebBrowserUI*>(m_PaintManager.FindControl(_T("flowTaskBrowser")));
    ASSERT(m_pWebBrowser);
    m_pWebBrowser->SetWebBrowserEventHandler((CWebBrowserEventHandler*)&m_taskEventHandler);
    m_pWebBrowser->SetDelayCreate(false);
    m_pWebBrowser->Navigate2(strAddFlowUrl);
}

void CFlowTaskWnd::Notify(TNotifyUI& msg)
{
    WindowImplBase::Notify(msg);
}
