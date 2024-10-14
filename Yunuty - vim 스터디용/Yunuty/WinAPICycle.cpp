// 1. 문서의 끝으로 가시오.
// 3. 50번째 줄로 가시오.
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
    // 4. z를 두번 눌러서 커서가 화면의 중앙에 오도록 하시오.
    // 5. 이 주석의 끝으로 가 보시오. 8. 119번째 줄로 이동하시오. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 7. 이 줄의 처음 부분으로 이동하시오.  6. b를 계속 눌러서 7번 지문으로 커서를 이동하시오.
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
// 끝!
{ // 10. z를 두번 눌러 커서를 화면 중앙에 위치시키시오.
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
} // 9. 이 줄의 닫는 중괄호 }에 대응되는 여는 중괄호를 찾아가시오. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 
// 2. 글의 처음으로 가시오
