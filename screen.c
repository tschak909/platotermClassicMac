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
#include <Palettes.h>
#include "screen.h"
#include "font.h"
#include "protocol.h"
#include "io.h"
#include "keyboard.h"

#define true 1
#define false 0
#define FONTPTR(a) (a<<4)

char tmp[64];
int previousMode;
unsigned char CharWide=8;
unsigned char CharHigh=16;
padPt TTYLoc;
padPt statusLoc={0,0};
unsigned char fontm23[2048];
extern padBool FastText; /* protocol.c */
Rect screenRect;
Rect windowRect;
double verticalScaleFactor;
WindowPtr win;
EventRecord theEvent;
unsigned char is_mono=true;
SysEnvRec environment;
Handle menuBar;
RGBColor current_foreground;
RGBColor current_background;

/**
 * screen_init() - Set up the screen
 */
void screen_init(void)
{
  InitGraf(&qd.thePort);
  InitFonts();
  InitWindows();
  InitMenus();
  InitPalettes();

  current_foreground.red=255;
  current_foreground.green=255;
  current_foreground.blue=255;
  current_background.red=0;
  current_background.green=0;
  current_background.blue=0;
  
  SetMenuBar(GetNewMBar(128));
  AppendResMenu(GetMenu(128),'DRVR');
  DrawMenuBar();
  
  screenRect=qd.screenBits.bounds;
  windowRect.left=0;
  windowRect.right=511;

  /* Set window size depending on screen size. */
  if (screenRect.bottom < 468)
    {
      /* Mac Plus sized screen */
      windowRect.top=20;
      windowRect.bottom=windowRect.top+320;
    }
  else if (screenRect.bottom < 532)
    {
      /* 640x480 screen */
      windowRect.top=20;
      windowRect.bottom=windowRect.top+448;
    }
  else
    {
      /* Larger */
      windowRect.top=45;
      windowRect.bottom=windowRect.top+512;
      windowRect.left+=5; /* scooch the content area inward slightly. */
      windowRect.right+=5; /* scooch */
    }

  verticalScaleFactor=((double)windowRect.bottom-(double)windowRect.top)/(double)512.0;
  
  if (SysEnvirons(1,&environment) == noErr)
    is_mono=!environment.hasColorQD;
  else
    is_mono=true;
  
  if (is_mono==true)
    {
      win = NewWindow(NULL, &windowRect, "\pPLATOTerm", true, 0, (WindowPtr)-1, false, 0);
    }
  else
    {
      win = NewCWindow(NULL, &windowRect, "\pColor PLATOTerm", true, 0, (WindowPtr)-1, false, 0);      
    }

  SetPort(win);
  
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
	case keyDown:
	case autoKey:
	  keyboard_main(&theEvent);
	  break;
	case updateEvt:
	  /* To be implemented, somehow... */
	  break;
	}
    }
}

/**
 * screen_scale_x(x) - Scale PLATO X coordinate to screen
 */
short screen_scale_x(short x)
{
  return (x);
}

/**
 * screen_scale_y(y) - Scale PLATO Y coordinate to screen
 */
short screen_scale_y(short y)
{
  y=y^0x1FF;
  return round(y*verticalScaleFactor);
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
  SetPort(win);
  EraseRect(&win->portRect);
}

/**
 * screen_color_transform - Map PLATO color to 
 * QuickDraw color
 */
void screen_color_transform(padRGB* theColor, RGBColor* newColor)
{
  newColor->red = (theColor->red << 8) | ((theColor->red & 0x80)? 0xFF : 0x00);
  newColor->green = (theColor->green << 8) | ((theColor->green & 0x80)? 0xFF : 0x00);
  newColor->blue = (theColor->blue << 8) | ((theColor->blue & 0x80)? 0xFF : 0x00);
}

/**
 * screen_foreground - set foreground color
 */
void screen_foreground(padRGB* theColor)
{
  if (is_mono)
    return;
  screen_color_transform(theColor,&current_foreground);
  SetPort(win);
  RGBForeColor(&current_foreground);
}

/**
 * screen_background - set background_color
 */
void screen_background(padRGB* theColor)
{
  if (is_mono)
    return;
  screen_color_transform(theColor,&current_background);
  SetPort(win);
  RGBBackColor(&current_background);
}

/**
 * screen_current_mode(void) - Return current drawing mode
 */
short screen_current_mode(void)
{
  if ((CurMode == ModeWrite) || (CurMode == ModeRewrite))
    PenMode(patOr);
  else
    PenMode(patBic);
}

/**
 * screen_block_draw(Coord1, Coord2) - Perform a block fill from Coord1 to Coord2
 */
void screen_block_draw(padPt* Coord1, padPt* Coord2)
{
  Rect tmpRect;
  SetPort(win);
  tmpRect.left=screen_scale_x(Coord1->x);
  tmpRect.top=screen_scale_y(Coord1->y);
  tmpRect.right=screen_scale_x(Coord2->x);
  tmpRect.bottom=screen_scale_y(Coord2->y);
  screen_current_mode();
  PaintRect(&tmpRect);
}

/**
 * screen_dot_draw(Coord) - Plot a mode 0 pixel
 */
void screen_dot_draw(padPt* Coord)
{
  SetPort(win);
  MoveTo(screen_scale_x(Coord->x),screen_scale_y(Coord->y));
  screen_current_mode();
  Line(0,0);
}

/**
 * screen_line_draw(Coord1, Coord2) - Draw a mode 1 line
 */
void screen_line_draw(padPt* Coord1, padPt* Coord2)
{
  SetPort(win);
  MoveTo(screen_scale_x(Coord1->x),screen_scale_y(Coord1->y));
  screen_current_mode();
  LineTo(screen_scale_x(Coord2->x),screen_scale_y(Coord2->y));
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
  RGBColor mainColor;
  RGBColor altColor;
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
  
  SetPort(win);

  if (CurMode==ModeRewrite)
    {
      altColor.red=current_background.red;
      altColor.green=current_background.green;
      altColor.blue=current_background.blue;
    }
  else if (CurMode==ModeInverse)
    {
      altColor.red=current_foreground.red;
      altColor.green=current_foreground.green;
      altColor.blue=current_foreground.blue;

    }
  
  if (CurMode==ModeErase || CurMode==ModeInverse)
    {
      mainColor.red=current_background.red;
      mainColor.green=current_background.green;
      mainColor.blue=current_background.blue;
    }
  else
    {
      mainColor.red=current_foreground.red;
      mainColor.green=current_foreground.green;
      mainColor.blue=current_foreground.blue;
    }

  x=screen_scale_x(Coord->x&0x1FF);

  if (ModeBold)
    y=screen_scale_y((Coord->y)+30&0x1FF);
  else
    y=screen_scale_y((Coord->y)+15&0x1FF);
  
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
		  RGBForeColor(&mainColor);
		  MoveTo(x,y);
		  Line(0,0);
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
		      RGBForeColor(&mainColor);
		      MoveTo(*px+1,*py);
		      Line(0,0);
		      MoveTo(*px,*py+1);
		      Line(0,0);
		      MoveTo(*px+1,*py+1);
		      Line(0,0);
		    }
		  MoveTo(*px,*py);
		}
	      else
		{
		  if (CurMode==ModeInverse || CurMode==ModeRewrite)
		    {
		      if (ModeBold)
			{
			  RGBForeColor(&altColor);
			  MoveTo(*px+1,*py);
			  MoveTo(*px,*py+1);
			  MoveTo(*px+1,*py+1);
			}
		      MoveTo(*px,*py); 
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
 * is pixel set to specified color?
 */
unsigned char screen_is_pixel_color(int x, int y, RGBColor* color)
{
  RGBColor currentPixelColor;
  GetCPixel(x,y,&currentPixelColor);
  return ((currentPixelColor.red==color->red) &&
	  (currentPixelColor.green==color->green) &&
	  (currentPixelColor.blue==color->blue));
}

/**
 * Are two pixel colors the same?
 */
unsigned char screen_pixel_colors_same(RGBColor* firstColor, RGBColor* secondColor)
{
  return ((firstColor->red==secondColor->red) &&
	  (firstColor->green==secondColor->green) &&
	  (firstColor->blue==secondColor->blue));
}

/**
 * screen_paint - Called to paint at location.
 */
void screen_paint(padPt* Coord)
{
  static unsigned short xStack[512];
  static unsigned short yStack[512];
  int x=screen_scale_x(Coord->x);
  int y=screen_scale_y(Coord->y);
  unsigned char stackentry = 1;
  unsigned short spanAbove, spanBelow;
  RGBColor oldColor;
  GetCPixel(x,y,&oldColor);

  if ((oldColor.red == current_foreground.red) &&
      (oldColor.green == current_foreground.green) &&
      (oldColor.blue == current_foreground.blue))
    return;
  
  do
    {
      unsigned short startx;
      while (x > 0 && screen_is_pixel_color(x-1,y,&oldColor))
        --x;

      spanAbove = spanBelow = false;
      startx=x;

      while(screen_is_pixel_color(x,y,&oldColor))
        {
          if (y < (512))
            {
              RGBColor belowColor;
  	      GetCPixel(x, y+1,&belowColor);
              if (!spanBelow  && screen_pixel_colors_same(&belowColor,&oldColor))
                {
                  xStack[stackentry]  = x;
                  yStack[stackentry]  = y+1;
                  ++stackentry;
                  spanBelow = true;
                }
              else if (spanBelow && !screen_pixel_colors_same(&belowColor,&oldColor))
                spanBelow = false;
            }

          if (y > 0)
            {
              RGBColor aboveColor;
  	      GetCPixel(x, y-1,&aboveColor);
              if (!spanAbove  && screen_pixel_colors_same(&aboveColor,&oldColor))
                {
                  xStack[stackentry]  = x;
                  yStack[stackentry]  = y-1;
                  ++stackentry;
                  spanAbove = true;
                }
              else if (spanAbove && !screen_pixel_colors_same(&aboveColor,&oldColor))
                spanAbove = false;
            }

          ++x;
        }
      MoveTo(startx,y);
      LineTo(x-1,y);
      --stackentry;
      x = xStack[stackentry];
      y = yStack[stackentry];
    }
  while (stackentry);
}

/**
 * screen_done()
 * Close down TGI
 */
void screen_done(void)
{
}
