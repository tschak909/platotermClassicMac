#include "keyboard.h"
#include "key.h"
#include "protocol.h"
#include "io.h"
#include "screen.h"
#include "trace.h"
#include "terminal.h"

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
  unsigned char code;
  key=e->message&0x7F;
  code=((e->message)>>8)&0x7F;
  if (TTY)
    {
      if (e->modifiers & cmdKey)
	{
	  if (key=='h')
	    {
	      TTY=padT;
	      io_hang_up();
	    }
	  else if (key=='t')
	    {
	      terminal_set_tty();
	    }
	  else if (key=='p')
	    {
	      terminal_set_plato();
	    }
	}
      else
	keyboard_out_tty(key);
    }
  else
    {
      if (e->modifiers & cmdKey)
	{
	  if (key=='h')
	    {
	      terminal_set_tty();
	      io_hang_up();
	    }
	  else if (key=='t')
	    {
	      terminal_set_tty();
	    }
	  else if (key=='p')
	    {
	      terminal_set_plato();
	    }
	}
      else if (e->modifiers & 4096) /* CTRL key*/
	{
	  if (e->modifiers & 512)
	    key|=0x80;
	  keyboard_out(ctrl_key_to_pkey[key]);
	}
      else if ((e->modifiers & 512) && key==0x0d)
	{
	  keyboard_out(PKEY_NEXT1);
	}
      else if ((e->modifiers & 512) && key==0x08)
	{
	  keyboard_out(PKEY_ERASE1);
	}
      else if ((e->modifiers & 4096) && code==0x04)
	{
	  if (e->modifiers & 512)
	    keyboard_out(PKEY_HELP1);
	  else
	    keyboard_out(PKEY_HELP);
	}
      else if ((e->modifiers & 4096) && code==0x2E)
	{
	  keyboard_out(PKEY_MICRO);
	}
      else
	keyboard_out(key_to_pkey[key]);
    }
}

void keyboard_out_tty(padByte ch)
{
  io_send_byte(ch);
}

