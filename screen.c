#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Quickdraw.h>
#include <MacMemory.h>
#include <Sound.h>
#include <Events.h>
#include <Fonts.h>
#include <NumberFormatting.h>
#include <Devices.h>
#include "screen.h"
#include "font.h"
#include "protocol.h"
#include "io.h"

#define true 1
#define false 0
#define FONTPTR(a) (a<<4)
#define X(x) (x)
#define Y(y) (y^0x1FF)

char tmp[64];
int previousMode;
unsigned char CharWide=8;
unsigned char CharHigh=16;
padPt TTYLoc;
padPt statusLoc={0,0};
unsigned char fontm23[2048];
extern padBool FastText; /* protocol.c */
padRGB palette[16];
unsigned long current_foreground=1;
unsigned long current_background=0;
padRGB current_foreground_rgb={255,255,255};
padRGB current_background_rgb={0,0,0};
int highest_color_index;
padRGB palette_help[16];
padRGB palette_backup[16];
unsigned long current_foreground_backup=1;
unsigned long current_background_backup=0;
padRGB current_foreground_rgb_backup={255,255,255};
padRGB current_background_rgb_backup={0,0,0};
int highest_color_index_backup;
unsigned char help_active=false;
Rect screenRect;
BitMap globalBitmap;
WindowPtr win;
EventRecord theEvent;
unsigned char is_mono=true;
SysEnvRec environment;
Handle menuBar;

/**
 * screen_init() - Set up the screen
 */
void screen_init(void)
{
  InitGraf(&qd.thePort);
  InitFonts();
  InitWindows();
  InitMenus();

  SetMenuBar(GetNewMBar(128));
  AppendResMenu(GetMenu(128),'DRVR');
  DrawMenuBar();
  
  screenRect=qd.screenBits.bounds;
  SetRect(&screenRect,screenRect.left+5,screenRect.top+45,screenRect.left+517,screenRect.top+557);

  if (SysEnvirons(1,&environment) == noErr)
    is_mono=!environment.hasColorQD;
  else
    is_mono=true;
  
  if (is_mono==true)
    {
      NewWindow(NULL, &screenRect, "\pPLATOTerm", true, 0, (WindowPtr)-1, false, 0);
    }
  else
    {
      NewCWindow(NULL, &screenRect, "\pColor PLATOTerm", true, 0, (WindowPtr)-1, false, 0);      
    }

  SetPort(win);
  screenRect=win->portRect;
}

/**
 * screen_update_menus() - Update menu state
 */
void screen_update_menus(void)
{
}

/**
 * screen_menu_command(menuCommand) - Do menu command.
 */
void screen_menu_command(long menu_command)
{
  Str255 str;
  WindowRef w;
  short menuID = menu_command >> 16;
  short menuItem = menu_command & 0xFFFF;
  if(menuID == 128)
    {
      if(menuItem == 1)
	{
	}
      else
        {
	  GetMenuItemText(GetMenu(128), menuItem, str);
	  OpenDeskAcc(str);
        }
    }
  else if(menuID == 129)
    {
      switch(menuItem)
        {

	case 1:
	  ExitToShell();
	  break;
        }
    }
  
  HiliteMenu(0);
}

/**
 * screen_main(void)
 */
void screen_main(void)
{
  WindowRef currentWindow;
  SystemTask();
  if (GetNextEvent(everyEvent,&theEvent))
    {
      switch(theEvent.what)
	{
	case mouseDown:
	  switch(FindWindow(theEvent.where,&currentWindow))
	    {
	    case inGoAway:
	      if (TrackGoAway(currentWindow,theEvent.where))
		DisposeWindow(currentWindow);
	      break;
	    case inDrag:
	      DragWindow(currentWindow,theEvent.where,&qd.screenBits.bounds);
	      break;
	    case inMenuBar:
	      screen_update_menus();
	      screen_menu_command(MenuSelect(theEvent.where));
	      break;
	    case inContent:
	      SelectWindow(currentWindow);
	      break;
	    case inSysWindow:
	      SystemClick(&theEvent,currentWindow);
	      break;
	    }
	case updateEvt:
	  break;
	}
    }
}

/**
 * screen_update_colors() - Set the terminal colors
 */
void screen_update_colors(void)
{
}

/**
 * screen_clear_palette - Clear the palette
 */
void screen_clear_palette(void)
{
  int i;
  for (i=0;i<8;i++)
    {
      palette[i].red=0;
      palette[i].green=0;
      palette[i].blue=0;
    }
}


/**
 * screen_wait(void) - Sleep for approx 16.67ms
 */
void screen_wait(void)
{
}

/**
 * screen_beep(void) - Beep the terminal
 */
void screen_beep(void)
{
}

/**
 * screen_clear - Clear the screen
 */
void screen_clear(void)
{
}

/**
 * screen_color_matching(color) - return index of matching color, or a new index, 
 * if not found.
 */
unsigned char screen_color_matching(padRGB* theColor)
{
  unsigned char i;
  for (i=0;i<8;i++)
    {
      if (i>highest_color_index)
	{
	  palette[i].red=theColor->red;
	  palette[i].green=theColor->green;
	  palette[i].blue=theColor->blue;
	  highest_color_index++;
	  return i;
	}
      else
	{
	  if ((palette[i].red==theColor->red) && 
	      (palette[i].green==theColor->green) && 
	      (palette[i].blue==theColor->blue))
	    {
	      return i;
	    }
	}
    }
}

/**
 * screen_foreground - set foreground color
 */
void screen_foreground(padRGB* theColor)
{
  current_foreground_rgb.red=theColor->red;
  current_foreground_rgb.green=theColor->green;
  current_foreground_rgb.blue=theColor->blue;
  current_foreground=screen_color_matching(theColor);
  screen_update_colors();
}

/**
 * screen_background - set background_color
 */
void screen_background(padRGB* theColor)
{
  current_background_rgb.red=theColor->red;
  current_background_rgb.green=theColor->green;
  current_background_rgb.blue=theColor->blue;
  current_background=screen_color_matching(theColor);
  screen_update_colors();
}

/**
 * screen_current_color(void) - Set the current pen mode
 */
int screen_current_color(void)
{
  if (CurMode==ModeInverse || CurMode==ModeErase)
    return current_background;
  else
    return current_foreground;
}

/**
 * screen_block_draw(Coord1, Coord2) - Perform a block fill from Coord1 to Coord2
 */
void screen_block_draw(padPt* Coord1, padPt* Coord2)
{
}

/**
 * screen_dot_draw(Coord) - Plot a mode 0 pixel
 */
void screen_dot_draw(padPt* Coord)
{
}

/**
 * screen_line_draw(Coord1, Coord2) - Draw a mode 1 line
 */
void screen_line_draw(padPt* Coord1, padPt* Coord2)
{
}

/**
 * screen_char_draw(Coord, ch, count) - Output buffer from ch* of length count as PLATO characters
 */
void screen_char_draw(padPt* Coord, unsigned char* ch, unsigned char count)
{
  short offset; /* due to negative offsets */
  unsigned short x;      /* Current X and Y coordinates */
  unsigned short y;
  unsigned short* px;   /* Pointers to X and Y coordinates used for actual plotting */
  unsigned short* py;
  unsigned char i; /* current character counter */
  unsigned char a; /* current character byte */
  unsigned char j,k; /* loop counters */
  char b; /* current character row bit signed */
  unsigned char width=8;
  unsigned char height=16;
  unsigned char FONT_SIZE_X=8;
  unsigned char FONT_SIZE_Y=16;
  unsigned short deltaX=1;
  unsigned short deltaY=1;
  unsigned char mainColor=1;
  unsigned char altColor=0;
  unsigned char *p;
  unsigned char* curfont;
  
  switch(CurMem)
    {
    case M0:
      curfont=font;
      offset=-32;
      break;
    case M1:
      curfont=font;
      offset=64;
      break;
    case M2:
      curfont=fontm23;
      offset=-32;
      break;
    case M3:
      curfont=fontm23;
      offset=32;      
      break;
    }

  if (CurMode==ModeRewrite)
    {
      altColor=current_background;
    }
  else if (CurMode==ModeInverse)
    {
      altColor=current_foreground;
    }
  
  if (CurMode==ModeErase || CurMode==ModeInverse)
    mainColor=current_background;
  else
    mainColor=current_foreground;

  x=X(Coord->x&0x1FF);

  if (ModeBold)
    y=Y((Coord->y)+30&0x1FF);
  else
    y=Y((Coord->y)+15&0x1FF);
  
  if (FastText==padF)
    {
      goto chardraw_with_fries;
    }

  /* the diet chardraw routine - fast text output. */
  
  for (i=0;i<count;++i)
    {
      a=*ch;
      ++ch;
      a+=offset;
      p=&curfont[FONTPTR(a)];
      
      for (j=0;j<FONT_SIZE_Y;++j)
  	{
  	  b=*p;
	  
  	  for (k=0;k<FONT_SIZE_X;++k)
  	    {
  	      if (b<0) /* check sign bit. */
		{
		  /* pset(x,y,mainColor); */
		}

	      ++x;
  	      b<<=1;
  	    }

	  ++y;
	  x-=width;
	  ++p;
  	}

      x+=width;
      y-=height;
    }

  return;

 chardraw_with_fries:
  if (Rotate)
    {
      deltaX=-abs(deltaX);
      width=-abs(width);
      px=&y;
      py=&x;
    }
    else
    {
      px=&x;
      py=&y;
    }
  
  if (ModeBold)
    {
      deltaX = deltaY = 2;
      width<<=1;
      height<<=1;
    }
  
  for (i=0;i<count;++i)
    {
      a=*ch;
      ++ch;
      a+=offset;
      p=&curfont[FONTPTR(a)];
      for (j=0;j<FONT_SIZE_Y;++j)
  	{
  	  b=*p;

	  if (Rotate)
	    {
	      px=&y;
	      py=&x;
	    }
	  else
	    {
	      px=&x;
	      py=&y;
	    }

  	  for (k=0;k<FONT_SIZE_X;++k)
  	    {
  	      if (b<0) /* check sign bit. */
		{
		  if (ModeBold)
		    {
		      /* pset(*px+1,*py,mainColor); */
		      /* pset(*px,*py+1,mainColor); */
		      /* pset(*px+1,*py+1,mainColor); */
		    }
		  /* pset(*px,*py,mainColor); */
		}
	      else
		{
		  if (CurMode==ModeInverse || CurMode==ModeRewrite)
		    {
		      if (ModeBold)
			{
			  /* pset(*px+1,*py,altColor); */
			  /* pset(*px,*py+1,altColor); */
			  /* pset(*px+1,*py+1,altColor); */
			}
		      /* pset(*px,*py,altColor);  */
		    }
		}

	      x += deltaX;
  	      b<<=1;
  	    }

	  y+=deltaY;
	  x-=width;
	  ++p;
  	}

      Coord->x+=width;
      x+=width;
      y-=height;
    }

  return;
  
}

/**
 * screen_tty_char - Called to plot chars when in tty mode
 */
void screen_tty_char(padByte theChar)
{
  if ((theChar >= 0x20) && (theChar < 0x7F)) {
    screen_char_draw(&TTYLoc, &theChar, 1);
    TTYLoc.x += CharWide;
  }
  else if ((theChar == 0x0b)) /* Vertical Tab */
    {
      TTYLoc.y += CharHigh;
    }
  else if ((theChar == 0x08) && (TTYLoc.x > 7))	/* backspace */
    {
      padPt ec1,ec2;
      TTYLoc.x -= CharWide;
      ec1.x=TTYLoc.x;
      ec1.y=TTYLoc.y;
      ec2.x=TTYLoc.x+CharWide;
      ec2.y=TTYLoc.y+CharHigh;
      CurMode=ModeErase;
      screen_block_draw(&ec1,&ec2);
      CurMode=ModeRewrite;
   }
  else if (theChar == 0x0A)			/* line feed */
    TTYLoc.y -= CharHigh;
  else if (theChar == 0x0D)			/* carriage return */
    TTYLoc.x = 0;
  
  if (TTYLoc.x + CharWide > 511) {	/* wrap at right side */
    TTYLoc.x = 0;
    TTYLoc.y -= CharHigh;
  }
  
  if (TTYLoc.y < 0) {
    screen_clear();
    TTYLoc.y=495;
  }

}

/**
 * screen_paint - Called to paint at location.
 */
void screen_paint(padPt* Coord)
{
}

/**
 * screen_clear_status(void)
 * Clear status area
 */
void screen_clear_status(void)
{
}

/**
 * screen_show_status(msg)
 */
void screen_show_status(unsigned char* msg)
{
  int previous_foreground=current_foreground;
  int previous_background=current_background;
  padPt coord={0,0};
  screen_clear_status();
  current_foreground=0;
  current_background=1;
  screen_char_draw(&coord,msg,strlen(msg));
  current_foreground=previous_foreground;
  current_background=previous_background;
}

/**
 * screen_show_baud_rate - Show baud rate
 */
void screen_show_baud_rate(int baud)
{
  sprintf(tmp,"%d Baud",baud);
  screen_show_status(tmp);
}

/**
 * screen_show_dial - Show dial in TTY mode
 */
void screen_show_dial(void)
{
}

/**
 * screen_show_hang_up - Show hang-up message
 */
void screen_show_hang_up(void)
{
  screen_show_status("Hanging up...");
}

/**
 * screen_show_dialing_status - Show dialing status.
 */
void screen_show_dialing_status(void)
{
  screen_show_status("Dialing...");
}

/**
 * screen_help_save_palette(void) - Save initial help palette
 * for future restore by screen_help_restore_palette(void)
 */
void screen_help_save_palette(void)
{
  int i;
  for (i=0;i<16;i++)
    {
      palette_help[i].red=palette[i].red;
      palette_help[i].green=palette[i].green;
      palette_help[i].blue=palette[i].blue;
    }
}

/**
 * screen_help_restore_palette(void) - Restore the help
 * palette, because the help screen is visible.
 */
void screen_help_restore_palette(void)
{
  int i;
  for (i=0;i<16;i++)
    {
      palette[i].red=palette_help[i].red;
      palette[i].green=palette_help[i].green;
      palette[i].blue=palette_help[i].blue;
    }
  screen_update_colors();
}

/**
 * screen_save_palette(void) - Save current screen palette state
 * for restore by screen_restore_palette(void)
 */
void screen_save_palette(void)
{
  int i;

  current_foreground_backup=current_foreground;
  current_background_backup=current_background;
  current_foreground_rgb_backup.red=current_foreground_rgb.red;
  current_foreground_rgb_backup.green=current_foreground_rgb.green;
  current_foreground_rgb_backup.blue=current_foreground_rgb.blue;
  current_background_rgb_backup.red=current_background_rgb.red;
  current_background_rgb_backup.green=current_background_rgb.green;
  current_background_rgb_backup.blue=current_background_rgb.blue;
  highest_color_index_backup=highest_color_index;
  
  for (i=0;i<16;i++)
    {
      palette_backup[i].red=palette[i].red;
      palette_backup[i].green=palette[i].green;
      palette_backup[i].blue=palette[i].blue;
    }
  
}

/**
 * screen_restore_palette(void) - Restore current screen palette
 * upon return from help screen.
 */
void screen_restore_palette(void)
{
  int i;

  current_foreground=current_foreground_backup;
  current_background=current_background_backup;
  current_foreground_rgb.red=current_foreground_rgb_backup.red;
  current_foreground_rgb.green=current_foreground_rgb_backup.green;
  current_foreground_rgb.blue=current_foreground_rgb_backup.blue;
  current_background_rgb.red=current_background_rgb_backup.red;
  current_background_rgb.green=current_background_rgb_backup.green;
  current_background_rgb.blue=current_background_rgb_backup.blue;
  highest_color_index=highest_color_index_backup;
  
  for (i=0;i<16;i++)
    {
      palette[i].red=palette_backup[i].red;
      palette[i].green=palette_backup[i].green;
      palette[i].blue=palette_backup[i].blue;
    }

  screen_update_colors();
  
}

/**
 * screen_show_help - SHow help
 */
void screen_show_help(void)
{
}

/**
 * screen_trace_status - Show trace status
 */
void screen_trace_status(const char* status)
{
  char tmp_status_msg[13];
  sprintf(tmp_status_msg,"TRACE: %s",status);
  screen_show_status(tmp_status_msg);
}

/**
 * screen_help_mode_status(void)
 * Put help mode status at bottom of help screen
 */
void screen_help_mode_status(void)
{
  screen_show_status("HELP Mode - Press any key to return to terminal.");
}

/**
 * screen_greeting(void)
 * show initial greeting
 */
void screen_greeting(void)
{
  /* sprintf(tmp,"v1.0 Ready - %5d baud - Press HELP for keys.",config.baud); */
  screen_show_status(tmp);
}

/**
 * screen_done()
 * Close down TGI
 */
void screen_done(void)
{
}
