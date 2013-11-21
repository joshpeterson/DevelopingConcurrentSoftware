// This scratch program is taken from http://blogs.msdn.com/b/oldnewthing/archive/2003/07/23/54576.aspx
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

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

/*
 *  OnCommand
 *      Called when the button is clicked.
 */
void
OnCommand()
{
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
        case WM_COMMAND: OnCommand(); return 0;
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
    MSG msg;
    HWND hwnd;

    g_hinst = hinst;

    if (!InitApp()) return 0;

    hwnd = CreateWindow(
        TEXT("Scratch"),                /* Class Name */
        TEXT("Scratch"),                /* Title */
        WS_OVERLAPPEDWINDOW,            /* Style */
        CW_USEDEFAULT, CW_USEDEFAULT,   /* Position */
        CW_USEDEFAULT, CW_USEDEFAULT,   /* Size */
        NULL,                           /* Parent */
        NULL,                           /* No menu */
        hinst,                          /* Instance */
        0);                             /* No special parameters */

    HWND hwndButton = CreateWindow( 
        TEXT("BUTTON"),  // Predefined class; Unicode assumed 
        TEXT("OK"),      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        10,         // x position 
        10,         // y position 
        100,        // Button width
        100,        // Button height
        hwnd,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), 
        NULL);      // Pointer not needed

    HWND hwndEdit = CreateWindowEx(
        0, TEXT("EDIT"),   // predefined class 
        NULL,         // no window title 
        WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER,
        10, 150, 100, 20,   // set size in WM_SIZE message 
        hwnd,         // parent window 
        NULL,  // edit control ID 
        (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), 
        NULL);        // pointer not needed

    ShowWindow(hwnd, nShowCmd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
