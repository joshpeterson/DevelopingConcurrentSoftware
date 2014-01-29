// This scratch program is taken from http://blogs.msdn.com/b/oldnewthing/archive/2003/07/23/54576.aspx.
// I have slightly modified it.
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>
#include "pi_calculator.h"
#include <sstream>
#include <future>
#include <chrono>
#include <condition_variable>

BOOL PumpMessage();

HINSTANCE g_hinst;
HWND g_hwndChild;
HWND hwndMain;
HWND hwndButton;
HWND hwndEdit;
bool window_closed = false;

void HandleButtonClick()
{
    char text[100];
    Edit_GetText(hwndEdit, text, 100);
    int number_of_iterations = atoi(text);

    std::condition_variable exit_condition;
    calculate_pi pi_calculator(&exit_condition, &window_closed);
    auto pi = pi_calculator(number_of_iterations);

    /*auto pi = std::async(pi_calculator, number_of_iterations);

    while (pi.wait_for(std::chrono::milliseconds(100)) != std::future_status::ready)
    {
        auto shouldContinue = PumpMessage();
        if (!shouldContinue)
        {
            window_closed = true;
            exit_condition.notify_one();
            pi.wait();
            break;
        }
    }*/

    if (!window_closed)
    {
        std::stringstream message;
        message.precision(15);
        message << "The value of pi is: " << pi;

        MessageBox(hwndMain, message.str().c_str(), "pi", 0);
    }
}

// The code below is necessary, but not too interesting for this example. It can be safely ignored.

void OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    if (g_hwndChild)
        MoveWindow(g_hwndChild, 0, 0, cx, cy, TRUE);
}

BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpcs)
{
    return TRUE;
}

void OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

void PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
}

void OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    BeginPaint(hwnd, &ps);
    PaintContent(hwnd, &ps);
    EndPaint(hwnd, &ps);
}

void OnPrintClient(HWND hwnd, HDC hdc)
{
    PAINTSTRUCT ps;
    ps.hdc = hdc;
    GetClientRect(hwnd, &ps.rcPaint);
    PaintContent(hwnd, &ps);

}

BOOL PumpMessage()
{
    if (window_closed)
        return FALSE;

    MSG msg;

    BOOL shouldContinue = GetMessage(&msg, NULL, 0, 0);
    TranslateMessage(&msg);
    DispatchMessage(&msg);

    return shouldContinue;
}

void OnCommand(HWND hwndControl)
{
    if (hwndControl == hwndButton)
        HandleButtonClick();
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
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

BOOL InitApp(void)
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

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev, LPSTR lpCmdLine, int nShowCmd)
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
        TEXT("BUTTON"),                 // Predefined class; Unicode assumed 
        TEXT("Calculate pi"),           // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10,                             // x position 
        40,                             // y position 
        100,                            // Button width
        100,                            // Button height
        hwndMain,
        NULL,
        (HINSTANCE)GetWindowLong(hwndMain, GWL_HINSTANCE), 
        NULL);

    hwndEdit = CreateWindowEx(
        0, TEXT("EDIT"),                // predefined class 
        NULL,                           // no window title 
        WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER,
        10, 10, 100, 20,                // set size and position
        hwndMain,
        NULL,
        (HINSTANCE) GetWindowLong(hwndMain, GWL_HINSTANCE), 
        NULL);

    ShowWindow(hwndMain, nShowCmd);

    while (PumpMessage());

    return 0;
}
