/**
  @file     bounce.h
  @brief    Header file for OpenGL BOUNCE demo
*/
#ifndef _BOUNCE_H_
#define _BOUNCE_H_

#include <util-std.h>
#include <win-std.h>

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

#endif
