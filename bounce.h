/**
  @file     bounce.h
  @brief    Header file for OpenGL BOUNCE demo
*/
#ifndef _BOUNCE_H_
#define _BOUNCE_H_

#include <util-std.h>

// bring in appropriate version of library
#ifndef _DEBUG
#pragma comment(lib, "UTIL.lib")
#pragma comment(lib, "GPH.lib")
#pragma comment(lib, "WIN.lib")
#pragma comment(lib, "OGL.lib")
#else
#pragma comment(lib, "UTILD.lib")
#pragma comment(lib, "GPHD.lib")
#pragma comment(lib, "WIND.lib")
#pragma comment(lib, "OGLD.lib")
#endif

struct
{
    BOOL    over;
}app;

WNDW    wnd;

#endif
