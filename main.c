#include "protocol.h"
#include "screen.h"
#include "io.h"
#include "terminal.h"
#include "keyboard.h"
#include "touch.h"
#include "splash.h"
#include "config.h"

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
  config_init();
  screen_init();
  touch_init();
  NoEcho=padT;
  ShowPLATO(splash,sizeof(splash));
  NoEcho=padF;
  terminal_initial_position();
  io_init();
  screen_update_menus();
  running=true;
  while (running==true)
    {
      screen_main(); /* keyboard_main() and touch_main() are called in here. */
      io_main();
    }
  done();
}

