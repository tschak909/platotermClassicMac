#include "protocol.h"
#include "screen.h"
#include "io.h"
#include "terminal.h"
#include "keyboard.h"
#include "touch.h"
#include "splash.h"
#include "help.h"

#define true 1
#define false 0

unsigned char already_started=false;
unsigned char running=false;

void done(void)
{
  io_done();
  touch_done();
  screen_done();
}

void main(void)
{
  screen_init();
  touch_init();
  help_init();
  NoEcho=padT;
  ShowPLATO(splash,sizeof(splash));
  NoEcho=padF;
  terminal_initial_position();
  io_init();
  running=true;
  while (running==true)
    {
      screen_main(); /* keyboard_main() and touch_main() are called in here. */
      io_main();
    }
}

