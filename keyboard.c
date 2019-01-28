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
  unsigned char key;
  key=e->message&0x7F;
  if (TTY)
    {
      keyboard_out_tty(key);
    }
  else
    {
      if (e->modifiers & 4096) /* CTRL key*/
	{
	  if (e->modifiers & 512)
	    key|=0x80;
	  keyboard_out(ctrl_key_to_pkey[key]);
	}
      else
	keyboard_out(key_to_pkey[key]);
    }
}

void keyboard_out_tty(padByte ch)
{
  io_send_byte(ch);
}

