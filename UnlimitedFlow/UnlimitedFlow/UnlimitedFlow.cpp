// UnlimitedFlow.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "UnlimitedFlow.h"
#include "MainWnd.h"


/** 枚举桌面窗口并激活流量神器窗口
在InitializeMutex检测到互斥体已经存在的时候
调用EnumWindows并以此为回调
*/
static HANDLE g_hMutex = NULL;
const LPCTSTR g_strMutex = _T("淘宝无线手机流量");
static BOOL CALLBACK MutexActivePreWindow(HWND hWnd, LPARAM lParam)
{
    if (::GetProp(hWnd, g_strMutex) != 0)
    {
        ::ShowWindow(hWnd, ::IsIconic(hWnd) ? SW_SHOWNORMAL : SW_SHOW);
        ::SetForegroundWindow(hWnd);

        ASSERT(NULL != lParam);
        if (NULL != lParam)
        {
            *(BOOL*)lParam = TRUE;
        }
        return FALSE;
    }
    return TRUE;
}

BOOL InitializeMutex(void)
{
    if (NULL != g_hMutex)
    {
        ASSERT(FALSE);
        return FALSE;
    }

    g_hMutex = ::CreateMutex(NULL, FALSE, g_strMutex);
    if (::GetLastError() == ERROR_ALREADY_EXISTS)
    {
        /** 已经存在互斥对象 */
        if (NULL != g_hMutex)
        {
            ::CloseHandle(g_hMutex);
            g_hMutex = NULL;
        }

        /** 激活上一次启动的程序 */
        BOOL bRet = FALSE;
        ::EnumWindows(MutexActivePreWindow, (LPARAM)&bRet);

        return FALSE;
    }
    return TRUE;
}

BOOL TerminateMutex(void)
{
    if (NULL == g_hMutex)
    {
        return FALSE;
    }

    if (::CloseHandle(g_hMutex))
    {
        g_hMutex = NULL;
        return TRUE;
    }

    return FALSE;
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

    if (!InitializeMutex())
    {
        return -1;
    }
    
    CPaintManagerUI::SetInstance(hInstance);// 加载XML的时候，需要使用该句柄去定位EXE的路径，才能加载XML的路径
    //CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));
    //CPaintManagerUI::SetResourceZip(_T("360SafeRes.zip"));

    HRESULT Hr = ::CoInitialize(NULL);
    if (FAILED(Hr)) return 0;

    auto pFrame = new CMainWnd();
    if (pFrame == NULL)
    {
        return 0;
    }
    pFrame->Create(NULL, XHDTITLE, UI_WNDSTYLE_FRAME, 0L, 0, 0, 0, 0);
    pFrame->CenterWindow();
    ::ShowWindow(*pFrame, SW_SHOW);

    CPaintManagerUI::MessageLoop();

    ::CoUninitialize();
    TerminateMutex();
    return 0;
}
