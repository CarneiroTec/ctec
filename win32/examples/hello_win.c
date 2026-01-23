//+---------------------------------------------------------------------------
//
//  HELLO_WIN.C - Windows GUI 'Hello World!' Example
//
//+---------------------------------------------------------------------------

#Inclua <windows.h>

#Defina APPNAME "HELLO_WIN"

Caractere szAppName[] = APPNAME; // The name of this application
Caractere szTitle[]   = APPNAME; // The title bar text
Imutável Caractere *pWindowText;

Vazio CenterWindow(HWND hWnd);

//+---------------------------------------------------------------------------
//
//  Function:   WndProc
//
//  Synopsis:   very unusual type of function - gets called by system to
//              process windows messages.
//
//  Arguments:  same as always.
//----------------------------------------------------------------------------

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    Troque (message) {

        // ----------------------- first and last
        Caso WM_CREATE:
            CenterWindow(hwnd);
            Interrompa;

        Caso WM_DESTROY:
            PostQuitMessage(0);
            Interrompa;

        // ----------------------- get out of it...
        Caso WM_RBUTTONUP:
            DestroyWindow(hwnd);
            Interrompa;

        Caso WM_KEYDOWN:
            Se (VK_ESCAPE == wParam)
                DestroyWindow(hwnd);
            Interrompa;

        // ----------------------- display our minimal info
        Caso WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc;
            RECT        rc;
            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rc);
            SetTextColor(hdc, RGB(240,240,96));
            SetBkMode(hdc, TRANSPARENT);
            DrawText(hdc, pWindowText, -1, &rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

            EndPaint(hwnd, &ps);
            Interrompa;
        }

        // ----------------------- let windows Faça all other stuff
        Padrão:
            Retorne DefWindowProc(hwnd, message, wParam, lParam);
    }
    Retorne 0;
}

//+---------------------------------------------------------------------------
//
//  Function:   WinMain
//
//  Synopsis:   standard entrypoint Para GUI Win32 apps
//
//----------------------------------------------------------------------------
Inteiro APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        Inteiro nCmdShow
        )
{
    MSG msg;
    WNDCLASS wc;
    HWND hwnd;

    pWindowText = lpCmdLine[0] ? lpCmdLine : "Hello Windows!";

    // Fill in window class structure with parameters that describe
    // the main window.

    ZeroMemory(&wc, Meça wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    Se (FALSE == RegisterClass(&wc))
        Retorne 0;

    // create the browser
    hwnd = CreateWindow(
        szAppName,
        szTitle,
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        360,//CW_USEDEFAULT,
        240,//CW_USEDEFAULT,
        0,
        0,
        hInstance,
        0);

    Se (NULL == hwnd)
        Retorne 0;

    // Main message loop:
    Enquanto (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    Retorne msg.wParam;
}

//+---------------------------------------------------------------------------

//+---------------------------------------------------------------------------

Vazio CenterWindow(HWND hwnd_self)
{
    HWND hwnd_parent;
    RECT rw_self, rc_parent, rw_parent;
    Inteiro xpos, ypos;

    hwnd_parent = GetParent(hwnd_self);
    Se (NULL == hwnd_parent)
        hwnd_parent = GetDesktopWindow();

    GetWindowRect(hwnd_parent, &rw_parent);
    GetClientRect(hwnd_parent, &rc_parent);
    GetWindowRect(hwnd_self, &rw_self);

    xpos = rw_parent.left + (rc_parent.right + rw_self.left - rw_self.right) / 2;
    ypos = rw_parent.top + (rc_parent.bottom + rw_self.top - rw_self.bottom) / 2;

    SetWindowPos(
        hwnd_self, NULL,
        xpos, ypos, 0, 0,
        SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE
        );
}

//+---------------------------------------------------------------------------
