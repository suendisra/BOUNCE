/**
  @file     bounce-draw.c
  @brief    Source file for OpenGL BOUNCE demo drawing
*/
#include "bounce.h"

#include <gph-pool.h>

#include <ogl-std.h>
#include <ogl-view.h>

enum COLORS
{
    COLOR_INVAL = -1,
    COLOR_BACK,
    COLOR_LAST
};

static VIEW     view = NULL;
static CLRPOOL  colors = NULL;

/* draw scene */
void Draw(void)
{
    // prepare the world scene
    ClearGL(PoolColor(COLOR_BACK, colors));
    ViewSet(&view);

    // TODO - draw the scene

    PresentGL();
}

/* load or unload graphics */
BOOL Graphics(const BOOL load)
{
    BOOL    success = FALSE;

    if(load)
    {
        // start OpenGL and create the primary view
        if(OpenGL(wnd.handl, FALSE) && View(wnd.client, FALSE, &view))
        {
            // create a color pool and assign colors
            if(Pool(&colors))
            {
                PoolClear(colors);
                PoolAdd(GCOAL, COLOR_BACK, colors);

                // TODO - fill in logic to load/destroy graphics
                success = TRUE;
            }
        }
    }else{
        // destroy everything and exit
        PoolKill(&colors);
        ViewKill(&view);
        success = KillGL();
    }

    return(success);
}
