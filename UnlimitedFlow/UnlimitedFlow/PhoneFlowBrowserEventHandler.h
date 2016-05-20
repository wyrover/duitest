#pragma once
class CPhoneFlowBrowserEventHandler : public CWebBrowserEventHandler
{
public:
    CPhoneFlowBrowserEventHandler();
    ~CPhoneFlowBrowserEventHandler();

    // interface IDocHostUIHandler
    virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(
        /* [in] */ DWORD dwID,
        /* [in] */ POINT __RPC_FAR *ppt,
        /* [in] */ IUnknown __RPC_FAR *pcmdtReserved,
        /* [in] */ IDispatch __RPC_FAR *pdispReserved)
    {
        //return E_NOTIMPL;
        //���� E_NOTIMPL ��������ϵͳ�Ҽ��˵�
        return S_OK;
        //����S_OK �������ϵͳ�Ҽ��˵�
    }

    virtual HRESULT STDMETHODCALLTYPE GetHostInfo(
        /* [out][in] */ DOCHOSTUIINFO __RPC_FAR *pInfo)
    {
        if (pInfo != NULL)
        {
            //���ι�����
            pInfo->dwFlags |= DOCHOSTUIFLAG_SCROLL_NO | DOCHOSTUIFLAG_NO3DBORDER;
        }
        return S_OK;
    }

    virtual void NavigateComplete2(IDispatch *pDisp, VARIANT *&url) override;

    virtual void BeforeNavigate2(IDispatch *pDisp, VARIANT *&url, VARIANT *&Flags, VARIANT *&TargetFrameName, VARIANT *&PostData, VARIANT *&Headers, VARIANT_BOOL *&Cancel) override;

    virtual void NavigateError(IDispatch *pDisp, VARIANT * &url, VARIANT *&TargetFrameName, VARIANT *&StatusCode, VARIANT_BOOL *&Cancel) override;

};

