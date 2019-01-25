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
}

padBool touch_lmb(void)
{
}

void touch_main(void)
{
}

/**
 * touch done
 */
void touch_done(void)
{
}
