/**
  @file     bounce.c
  @brief    Source file for OpenGL BOUNCE demo
*/
#include "bounce.h"

#include <util-str.h>
#include <win-std.h>

#define APP_COPYRIGHT   L"© 2026"
#define APP_PATH_DAT    L"bounce.dat"
#define APP_PATH_LOG    L"bounce.log"
#define APP_SCALE       0.96
#define APP_TITLE       L"BOUNCE"
#define APP_VERSION     L"0.0.0"

/* WinMain */
int WINAPI wWinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR cmd, int show)
{
    long    dim = 0;
    wchar_t title[STR_SMALL] = {0};

    // create an almost full-sized window
    WinInit(instance, previous, cmd, show);
    dim = (long)(APP_SCALE * min(win.client.cx, win.client.cy));
    QuadCentered(win.client.mx, win.client.my, dim, dim, &wnd.client);

    StrFormat(title, sizeof(title), L"%s %s", APP_TITLE, APP_VERSION);
    if(Window(title, wnd.client, NULL, &wnd))
    {
        WindowConfig(Start, Run, Stop, &wnd);
        WindowFunc(WM_TIMER, BluTimerStop, &wnd);
        WindowFunc(WOM_DONE, AudioDone, &wnd);
        WindowPeek(&app.over, &wnd);
        Loop(wnd);
    }

    return(0);
}
