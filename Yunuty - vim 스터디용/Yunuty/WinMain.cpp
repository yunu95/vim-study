// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <SDKDDKVer.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "WinAPI_resources.h"
#include "WinAPICycle.h"
#include "YunutyEngine.h"
#include "WinAPIGraphic.h"
#include "WinAPIBitmapImage.h"
#include "WinAPICircle.h"
#include "WinAPICamera2D.h"

#include "WinAPICircle.h"
#include <ObjIdl.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

using namespace Gdiplus;

using namespace YunutyEngine;
using namespace YunutyEngine::WinAPI;


// Global Variables:
HINSTANCE hInst;                                // current instance

// Forward declarations of functions included in this code module:
void SetWCEX(HINSTANCE hInstance, WNDCLASSEXW& wcex);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings

    WNDCLASSEXW wcex;
    SetWCEX(hInstance, wcex);

    // Perform application initialization:
    if (!WinAPICycle::GetInstance().Initialize(hInstance, wcex, nCmdShow, IDS_APP_TITLE, IDR_MAINMENU))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_MAINMENU));

    MSG msg;

    Scene scene;
    scene.AddGameObject()->AddComponent<WinAPICircle>();
    scene.AddGameObject()->AddComponent<WinAPICamera2D>();

    Scene::LoadScene(&scene);
    WinAPICycle::GetInstance().Play();

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
void SetWCEX(HINSTANCE hInstance, WNDCLASSEXW& wcex)
{
    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAIN));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MAINMENU);
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_MAIN));
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_SETTINGS:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
            /*case IDM_EXIT:
                DestroyWindow(hWnd);
                break;*/
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        //HDC hdc, MemDC;
        //PAINTSTRUCT ps;
        //HBITMAP MyBitmap, OldBitmap;

        //hdc = GetDC(hWnd);
        //MemDC = CreateCompatibleDC(hdc);
        //SelectObject(hdc, (HBRUSH)GetStockObject(BLACK_BRUSH));
        //Ellipse(hdc, -400, 400, 400, -400);

        //MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDI_ICON1));
        //OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);
        //BitBlt(hdc, 0, 0, 123, 160, MemDC, 0, 0, SRCCOPY);
        //StretchBlt(hdc, 50, 0, 296, 320, MemDC, 0, 0, 123, 160, DSTINVERT);
        /*SelectObject(MemDC, OldBitmap);
        DeleteObject(MyBitmap);*/
        //EndPaint(hWnd, &ps);
        return 0;

        break;
    }
    case WM_DESTROY:
        //DeleteObject(hBitmap);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
