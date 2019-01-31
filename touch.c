#include "touch.h"
#include "screen.h"

#define X(x) (x)
#define Y(y) (y^0x1FF)

padBool lmb=padF;
padBool lastlmb=padF; /* left mouse button state */
padBool isAllowed;

/**
 * touch_init(void)
 * Initiialize mouse
 */
void touch_init(void)
{
}

/**
 * enable/disable mouse cursor
 */
void touch_allow(padBool allow)
{
  isAllowed=allow;
  if (isAllowed==padT)
    screen_show_cursor(padT);
  else
    screen_show_cursor(padF);
}

void touch_main(padPt* Coord)
{
  if (isAllowed==padF)
    return;
  Touch(Coord);
}

/**
 * touch done
 */
void touch_done(void)
{
}
