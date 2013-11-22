// This scratch program is taken from http://blogs.msdn.com/b/oldnewthing/archive/2003/07/23/54576.aspx
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>
#include "pi_calculator.h"
#include <sstream>
#include <future>
#include <chrono>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */
HWND hwndMain;
HWND hwndButton;
HWND hwndEdit;

/*
 *  OnSize
 *      If we have an inner child, resize it to fit.
 */
void
OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    if (g_hwndChild) {
        MoveWindow(g_hwndChild, 0, 0, cx, cy, TRUE);
    }
}

/*
 *  OnCreate
 *      Applications will typically override this and maybe even
 *      create a child window.
 */
BOOL
OnCreate(HWND hwnd, LPCREATESTRUCT lpcs)
{
    return TRUE;
}

/*
 *  OnDestroy
 *      Post a quit message because our application is over when the
 *      user closes this window.
 */
void
OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

/*
 *  PaintContent
 *      Interesting things will be painted here eventually.
 */
void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
}

/*
 *  OnPaint
 *      Paint the content as part of the paint cycle.
 */
void
OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    BeginPaint(hwnd, &ps);
    PaintContent(hwnd, &ps);
    EndPaint(hwnd, &ps);
}

/*
 *  OnPrintClient
 *      Paint the content as requested by USER.
 */
void
OnPrintClient(HWND hwnd, HDC hdc)
{
    PAINTSTRUCT ps;
    ps.hdc = hdc;
    GetClientRect(hwnd, &ps.rcPaint);
    PaintContent(hwnd, &ps);

}

BOOL PumpMessage()
{
    MSG msg;

    BOOL shouldContinue = GetMessage(&msg, NULL, 0, 0);
    TranslateMessage(&msg);
    DispatchMessage(&msg);

    return shouldContinue;
}

/*
 *  OnCommand
 *      Called when the button is clicked.
 */
void
OnCommand(HWND hwndControl)
{
    if (hwndControl == hwndButton)
    {
        char text[100];
        Edit_GetText(hwndEdit, text, 100);
        int number_of_iterations = atoi(text);
        auto pi = std::async(calculate_pi, number_of_iterations);

        bool window_closed = false;
        while (window_closed || pi.wait_for(std::chrono::milliseconds(100)) != std::future_status::ready)
        {
            auto shouldContinue = PumpMessage();
            if (!shouldContinue)
                window_closed = true;
        }

        if (!window_closed)
        {
            std::stringstream message;
            message.precision(15);
            message << "The value of pi is: " << pi.get();

            MessageBox(hwndMain, message.str().c_str(), "pi", 0);
        }
    }
}

/*
 *  Window procedure
 */
LRESULT CALLBACK
WndProc(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uiMsg) {

        HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
        HANDLE_MSG(hwnd, WM_SIZE, OnSize);
        HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
        HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
        case WM_PRINTCLIENT: OnPrintClient(hwnd, (HDC)wParam); return 0;
        case WM_COMMAND: OnCommand((HWND)lParam); return 0;
    }

    return DefWindowProc(hwnd, uiMsg, wParam, lParam);
}

BOOL
InitApp(void)
{
    WNDCLASS wc;

    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = g_hinst;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = TEXT("Scratch");

    if (!RegisterClass(&wc)) return FALSE;

    return TRUE;
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
    g_hinst = hinst;

    if (!InitApp()) return 0;

    hwndMain = CreateWindow(
        TEXT("Scratch"),                /* Class Name */
        TEXT("Pi Calculator"),          /* Title */
        WS_OVERLAPPEDWINDOW,            /* Style */
        CW_USEDEFAULT, CW_USEDEFAULT,   /* Position */
        135, 180,                       /* Size */
        NULL,                           /* Parent */
        NULL,                           /* No menu */
        hinst,                          /* Instance */
        0);                             /* No special parameters */

    hwndButton = CreateWindow( 
        TEXT("BUTTON"),  // Predefined class; Unicode assumed 
        TEXT("Calculate pi"),      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        10,         // x position 
        40,         // y position 
        100,        // Button width
        100,        // Button height
        hwndMain,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLong(hwndMain, GWL_HINSTANCE), 
        NULL);      // Pointer not needed

    hwndEdit = CreateWindowEx(
        0, TEXT("EDIT"),   // predefined class 
        NULL,         // no window title 
        WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER,
        10, 10, 100, 20,   // set size and position
        hwndMain,         // parent window 
        NULL,  // edit control ID 
        (HINSTANCE) GetWindowLong(hwndMain, GWL_HINSTANCE), 
        NULL);        // pointer not needed

    ShowWindow(hwndMain, nShowCmd);

    while (PumpMessage());

    return 0;
}
