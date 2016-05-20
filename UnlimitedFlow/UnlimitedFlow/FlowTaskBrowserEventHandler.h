#pragma once
class CFlowTaskBrowserEventHandler : public CWebBrowserEventHandler
{
public:
    CFlowTaskBrowserEventHandler();
    ~CFlowTaskBrowserEventHandler();

    virtual HRESULT STDMETHODCALLTYPE GetHostInfo(
        /* [out][in] */ DOCHOSTUIINFO __RPC_FAR *pInfo)
    {
        if (pInfo != NULL)
        {
            //ÆÁ±Î¹ö¶¯Ìõ
            pInfo->dwFlags |= DOCHOSTUIFLAG_SCROLL_NO | DOCHOSTUIFLAG_NO3DBORDER;
        }
        return S_OK;
    }
};

