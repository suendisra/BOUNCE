/**
  @file     bounce.c
  @brief    Source file for OpenGL BOUNCE demo
*/
#include "bounce.h"

#include <util-str.h>
#include <win-std.h>

#define APP_COPYRIGHT   L"© 2026"
#define APP_PATH_DAT    L"bounce.dat"
#define APP_SCALE       0.96
#define APP_TITLE       L"BOUNCE"
#define APP_VERSION     L"0.0.0"

// static prototypes
static void Run(void);
static BOOL Settings(const BOOL read);
static BOOL Start(void);
static void Stop(void);

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
        WindowPeek(&app.over, &wnd);
        Loop(wnd);
    }

    return(0);
}

/* perform game algorithm */
static void Run(void)
{
    Draw();
    Input();
    Update();
    Benchmark(&bench);
}

/* load or save game settings */
static BOOL Settings(const BOOL read)
{
    CFILE   cf = {0};
    wchar_t dir[STR_PATH] = {0};
    long    mode = ((read == TRUE) ? FILE_READ : FILE_WRITE);
    BOOL    success = FALSE;

    if(FolderApp(dir, sizeof(dir), L"%s", APP_PATH_DAT) == TRUE)
    {
        if(FileOpen(mode, dir, &cf) == TRUE)
        {
            if(read == TRUE)
            {
                success = (FileRead(cf, &app, sizeof(app)) == sizeof(app));
            }else{
                app.over = FALSE;
                success = (FileWrite(cf, &app, sizeof(app)) == sizeof(app));
            }

            FileClose(&cf);
        }
    }

    return(success);
}

/* initialize the game and all the necessary resources */
static BOOL Start(void)
{
    BOOL    success = FALSE;

    // open the log file
    if(Logging(TRUE))
    {
        // apply application icon to window
        if(WindowIcon(IDI_CUBED, &wnd))
        {
            // set up the game struct based off saved settings
            if(Settings(TRUE) == FALSE)
            {
                // unable to load saved settings, use defaults
                Defaults();
            }

            // set up graphics, audio, and bluetooth
            if(Graphics(TRUE) == TRUE)
            {
                Logic();
                Blu(TRUE);
                Audio(TRUE);
                app.debug = TRUE;
                success = TRUE;
            }
        }
    }

    return(success);
}

/* perform game cleanup */
static void Stop(void)
{
    Audio(FALSE);
    Blu(FALSE);

    Graphics(FALSE);
    StateClear();
    Settings(FALSE);
    WindowKill(&wnd);
    LogFile(NULL);
}
