// UnlimitedFlow.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "UnlimitedFlow.h"
#include "MainWnd.h"


/** ö�����洰�ڲ�����������������
��InitializeMutex��⵽�������Ѿ����ڵ�ʱ��
����EnumWindows���Դ�Ϊ�ص�
*/
static HANDLE g_hMutex = NULL;
const LPCTSTR g_strMutex = _T("�Ա������ֻ�����");
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
        /** �Ѿ����ڻ������ */
        if (NULL != g_hMutex)
        {
            ::CloseHandle(g_hMutex);
            g_hMutex = NULL;
        }

        /** ������һ�������ĳ��� */
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
    
    CPaintManagerUI::SetInstance(hInstance);// ����XML��ʱ����Ҫʹ�øþ��ȥ��λEXE��·�������ܼ���XML��·��
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
