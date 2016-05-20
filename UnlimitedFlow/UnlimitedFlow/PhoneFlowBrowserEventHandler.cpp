#include "stdafx.h"
#include "PhoneFlowBrowserEventHandler.h"


CPhoneFlowBrowserEventHandler::CPhoneFlowBrowserEventHandler()
{
}


CPhoneFlowBrowserEventHandler::~CPhoneFlowBrowserEventHandler()
{
}

void CPhoneFlowBrowserEventHandler::NavigateComplete2(IDispatch *pDisp, VARIANT *&url)
{
    //throw std::logic_error("The method or operation is not implemented.");
}

void CPhoneFlowBrowserEventHandler::BeforeNavigate2(IDispatch *pDisp, VARIANT *&url, VARIANT *&Flags, VARIANT *&TargetFrameName, VARIANT *&PostData, VARIANT *&Headers, VARIANT_BOOL *&Cancel)
{
    //throw std::logic_error("The method or operation is not implemented.");
}

void CPhoneFlowBrowserEventHandler::NavigateError(IDispatch *pDisp, VARIANT * &url, VARIANT *&TargetFrameName, VARIANT *&StatusCode, VARIANT_BOOL *&Cancel)
{
    //throw std::logic_error("The method or operation is not implemented.");
}
