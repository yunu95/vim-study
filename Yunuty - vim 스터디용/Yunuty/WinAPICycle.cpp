// 1. ������ ������ ���ÿ�.
// 3. 50��° �ٷ� ���ÿ�.
#include "WinAPICycle.h"
#include "WinAPICamera2D.h"
#include "WinAPIInput.h" 
#include "Time.h"
#include "Camera.h"

using namespace YunutyEngine;
using namespace YunutyEngine::WinAPI;

WinAPICycle* YunutyEngine::WinAPI::WinAPICycle::_instance = nullptr;

BOOL YunutyEngine::WinAPI::WinAPICycle::InitInstance()
{
    if (!hInstance)
        return false;

    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}
WinAPICycle& YunutyEngine::WinAPI::WinAPICycle::GetInstance()
{
    if (!_instance)
        _instance = new WinAPICycle();

    return *_instance;
}
BOOL YunutyEngine::WinAPI::WinAPICycle::Initialize(HINSTANCE hInstance, const WNDCLASSEXW& wcex, _In_ int nCmdShow, _In_ UINT uID_TITLE, _In_ UINT uID_wndCLASS)
{
    this->wcex = wcex;
    this->nCmdShow = nCmdShow;
    this->hInstance = hInstance;
    new WinAPIInput();

    LoadStringW(hInstance, uID_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, uID_wndCLASS, szWindowClass, MAX_LOADSTRING);

    customWndProc = wcex.lpfnWndProc;
    // 4. z�� �ι� ������ Ŀ���� ȭ���� �߾ӿ� ������ �Ͻÿ�.
    // 5. �� �ּ��� ������ �� ���ÿ�. 8. 119��° �ٷ� �̵��Ͻÿ�. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 7. �� ���� ó�� �κ����� �̵��Ͻÿ�.  6. b�� ��� ������ 7�� �������� Ŀ���� �̵��Ͻÿ�.
    this->wcex.lpfnWndProc = WndProc;
    this->wcex.lpszClassName = szWindowClass;
    RegisterClassExW(&this->wcex);
    return InitInstance();
}
void YunutyEngine::WinAPI::WinAPICycle::ThreadUpdate()
{
    YunutyCycle::ThreadUpdate();
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
}






HWND YunutyEngine::WinAPI::WinAPICycle::GetMainWindow()
{
    return hWnd;
}








LRESULT CALLBACK YunutyEngine::WinAPI::WinAPICycle::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
// ��!
{ // 10. z�� �ι� ���� Ŀ���� ȭ�� �߾ӿ� ��ġ��Ű�ÿ�.
    WinAPICycle::GetInstance().hWnd = hWnd;
    if (WinAPICycle::GetInstance().customWndProc)
        WinAPICycle::GetInstance().customWndProc(hWnd, message, wParam, lParam);
    if (WinAPIInput::instance)
        WinAPIInput::instance->WndProc(hWnd, message, wParam, lParam);

    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
            /*case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;*/
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
        if (dynamic_cast<WinAPICamera2D*>(WinAPICamera2D::GetMainCamera()))
            dynamic_cast<WinAPICamera2D*>(WinAPICamera2D::GetMainCamera())->Render(hWnd, message, wParam, lParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
} // 9. �� ���� �ݴ� �߰�ȣ }�� �����Ǵ� ���� �߰�ȣ�� ã�ư��ÿ�. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 
// 2. ���� ó������ ���ÿ�
