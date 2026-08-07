/**
  @file     bounce.h
  @brief    Header file for OpenGL BOUNCE demo
*/
#ifndef _BOUNCE_H_
#define _BOUNCE_H_

#include <util-std.h>
#include <win-std.h>

// bring in appropriate version of library
#ifndef _DEBUG
#pragma comment(lib, "UTIL.lib")
#pragma comment(lib, "GPH.lib")
#pragma comment(lib, "NET.lib")
#pragma comment(lib, "WIN.lib")
#pragma comment(lib, "OGL.lib")
#else
#pragma comment(lib, "UTILD.lib")
#pragma comment(lib, "GPHD.lib")
#pragma comment(lib, "NETD.lib")
#pragma comment(lib, "WIND.lib")
#pragma comment(lib, "OGLD.lib")
#endif

struct
{
    BOOL    over;
}app;

WNDW    wnd;

/**
  @fn               void Draw(void)
  @brief            draws the scene as needed
*/
void Draw(void);

/**
  @brief            load or unload graphics
  @param[in]        load boolean value to load or destroy graphics abilities
  @return           TRUE if successfully loaded or destroyed graphics; FALSE otherwise
*/
BOOL Graphics(const BOOL load);

/**
  @fn               void Update(void)
  @brief            update logic for the next scene to draw

  */
void Update(void);

#endif
