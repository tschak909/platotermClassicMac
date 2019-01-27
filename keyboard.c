#include "keyboard.h"
#include "key.h"
#include "protocol.h"
#include "io.h"
#include "screen.h"
#include "trace.h"

#define true 1
#define false 0

extern unsigned char running;
extern unsigned char help_active;
extern char tmp[64];

void keyboard_out(int platoKey)
{
  if (platoKey==0xff)
    {
      return;
    }
  
  if (platoKey>0x7F)
    {
      Key(ACCESS);
      Key(ACCESS_KEYS[platoKey-0x80]);
      return;
    }
  Key(platoKey);
  return;
}

void keyboard_main(EventRecord* e)
{
  if (TTY)
    {
      keyboard_out_tty(e->message&0x7F);
    }
  else
    {

    }
}

void keyboard_out_tty(padByte ch)
{
  ShowPLATO(&ch,1);
  io_send_byte(ch);
}

