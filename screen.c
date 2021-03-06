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
#include <Gestalt.h>
#include "screen.h"
#include "font.h"
#include "protocol.h"
#include "io.h"
#include "keyboard.h"
#include "touch.h"
#include "config.h"
#include "terminal.h"

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
int windowWidth;
int windowHeight;
static AEEventHandlerUPP        oappUPP, odocUPP, pdocUPP, quitUPP;
extern unsigned char running;
static long sysv;
extern void done(void);
extern ConfigInfo config;

/* Apple Event Handler callbacks */

static pascal OSErr     AEOpenApplication(const AppleEvent *theAE, AppleEvent *reply, UInt32 refCon)
{
  return noErr;
}

static pascal OSErr     AEOpenDocuments(const AppleEvent *theAE, AppleEvent *reply, UInt32 refCon)
{
  return errAEEventNotHandled;
}

static pascal OSErr     AEPrintDocuments(const AppleEvent *theAE, AppleEvent *reply, UInt32 refCon)
{
  return errAEEventNotHandled;
}

static pascal OSErr     AEQuitApplication(const AppleEvent *theAE, AppleEvent *reply, UInt32 refCon)
{
  running=false;
  return noErr;
}

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
  TEInit();
  InitDialogs(NULL);
  InitCursor();
  
  /* Attach Apple Event handler callbacks */
  Gestalt('sysv',&sysv);
  if (sysv>0x6FF)
    {
      oappUPP = NewAEEventHandlerUPP(AEOpenApplication);
      AEInstallEventHandler(kCoreEventClass, kAEOpenApplication, oappUPP, 0L, false);
      odocUPP = NewAEEventHandlerUPP(AEOpenDocuments);
      AEInstallEventHandler(kCoreEventClass, kAEOpenDocuments, odocUPP, 0L, false);
      pdocUPP = NewAEEventHandlerUPP(AEPrintDocuments);
      AEInstallEventHandler(kCoreEventClass, kAEPrintDocuments, pdocUPP, 0L, false);
      quitUPP = NewAEEventHandlerUPP(AEQuitApplication);
      AEInstallEventHandler(kCoreEventClass, kAEQuitApplication, quitUPP, 0L, false);
    }
  
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
  windowRect.right=512;

  /* Set window size depending on screen size. */
  if (screenRect.bottom < 468)
    {
      /* Mac Plus sized screen */
      windowRect.top=20;
      windowRect.bottom=windowRect.top+320;
      CharHigh=10;
    }
  else if (screenRect.bottom < 532)
    {
      /* 640x480 screen */
      windowRect.top=20;
      windowRect.bottom=windowRect.top+448;
      CharHigh=14;
    }
  else
    {
      /* Larger */
      windowRect.top=45;
      windowRect.bottom=windowRect.top+512;
      windowRect.left+=5; /* scooch the content area inward slightly. */
      windowRect.right+=5; /* scooch */
    }

  windowWidth=windowRect.right-windowRect.left;
  windowHeight=windowRect.bottom-windowRect.top;
  verticalScaleFactor=((double)windowRect.bottom-(double)windowRect.top)/(double)512.0;
  
  if (SysEnvirons(1,&environment) == noErr)
    is_mono=!environment.hasColorQD;
  else
    is_mono=true;
  
  if (is_mono==true)
    win = NewWindow(NULL, &windowRect, "\pPLATOTerm", true, 0, (WindowPtr)-1, false, 0);
  else
    win = NewCWindow(NULL, &windowRect, "\pColor PLATOTerm", true, 0, (WindowPtr)-1, false, 0);      

  SetPort(win);
  
}

/**
 * screen_about_dialog() - Do dialog box
 */
void screen_about_dialog(void)
{
  DialogPtr dlg = GetNewDialog(128,0,(WindowPtr)-1);
  short item;

  while (item != 6)
    {
      ModalDialog(NULL, &item);
    }
  DisposeDialog(dlg);
}

/**
 * screen_update_menus() - Update menu state
 */
void screen_update_menus(void)
{
  int i;

  /* Update PLATO/TTY mode selector. */
  CheckItem(GetMenuHandle(129),1,false);
  CheckItem(GetMenuHandle(129),2,false);

  if (TTY)
    {
      CheckItem(GetMenuHandle(129),2,true);
    }
  else
    {
      CheckItem(GetMenuHandle(129),1,true);
    }
  
  /* Update baud rate selector. */
  for (i=1;i<8;i++)
    {
      CheckItem(GetMenuHandle(131),i,false);
    }
  switch (config.baud)
    {
    case 300:
      CheckItem(GetMenuHandle(131),1,true);
      break;
    case 1200:
      CheckItem(GetMenuHandle(131),2,true);
      break;
    case 2400:
      CheckItem(GetMenuHandle(131),3,true);
      break;
    case 9600:
      CheckItem(GetMenuHandle(131),4,true);
      break;
    case 19200:
      CheckItem(GetMenuHandle(131),5,true);
      break;
    case 38400:
      CheckItem(GetMenuHandle(131),6,true);
      break;
    case 57600:
      CheckItem(GetMenuHandle(131),7,true);
      break;
    }
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
	  screen_about_dialog();
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
	  terminal_set_plato();
	  break;
	case 2:
	  terminal_set_tty();
	  break;
	case 4:
	  io_hang_up();
	  break;
	case 5:
	  done();
	  break;
        }
    }
  else if (menuID == 131)
    {
      switch(menuItem)
	{
	case 1:
	  io_set_baud(300);
	  break;
	case 2:
	  io_set_baud(1200);
	  break;
	case 3:
	  io_set_baud(2400);
	  break;
	case 4:
	  io_set_baud(9600);
	  break;
	case 5:
	  io_set_baud(19200);
	  break;
	case 6:
	  io_set_baud(38400);
	  break;
	case 7:
	  io_set_baud(57600);
	  break;
	}
    }
  HiliteMenu(0);
  screen_update_menus();
}

/**
 * screen_handle_touch(where) - Handle touch events
 */
void screen_handle_touch(Point* where)
{
  padPt temp;
  SetPort(win);
  GlobalToLocal(where);
  temp.x = ((long)where->h * PLATOSize.x) / windowWidth;
  temp.y = (PLATOSize.y - 1) - (((long)where->v * PLATOSize.y) /
				windowHeight);
  
  touch_main(&temp);
}

/**
 * screen_show_cursor - Hide mouse cursor
 */
void screen_show_cursor(padBool show)
{
  if (show==padT)
    ShowCursor();
  else if (show==padF)
    ObscureCursor();
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
	      if (FrontWindow()!=currentWindow)
		SelectWindow(currentWindow);
	      else
		screen_handle_touch(&theEvent.where);
	      break;
	    case inSysWindow:
	      SystemClick(&theEvent,currentWindow);
	      break;
	    }
	case keyDown:
	case autoKey:
	  screen_show_cursor(padF);
	  keyboard_main(&theEvent);
	  break;
	case updateEvt:
	  BeginUpdate((WindowPtr)theEvent.message);
	  EndUpdate((WindowPtr)theEvent.message);
	case kHighLevelEvent:
	  if (sysv>0x6FF)
	    AEProcessAppleEvent(&theEvent);
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
  SysBeep(5);
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
  BitMap drawMap;
  char drawBits[64][16];
  char* chPt;
  char* drawFrom;
  char* drawTo;
  int offset;
  short Mode;
  Point charSize;
  Rect fromRect;
  Rect toRect;
  int chNum;
  int direction;
  int row;
  
  SetPort(win);

  /* Set up staging bitmap */
  drawMap.baseAddr=&drawBits[0][0];
  drawMap.rowBytes=64;
  drawMap.bounds.top=0;
  drawMap.bounds.bottom=16;
  drawMap.bounds.left=0;
  drawMap.bounds.right=512;

  /* Select appropriate font memory */
  switch (CurMem)
    {
    case M0:
      chPt = font;
      offset = -32;
      break;
    case M1:
      chPt = font;
      offset = 64;
      break;
    case M2:
      chPt = fontm23;
      offset = -32;
      break;
    case M3:
      chPt = fontm23;
      offset = 32;
      break;
    }

  /* Select appropriate bitmap transfer mode */
  switch(CurMode)
    {
    case ModeWrite:
      Mode = srcOr;
      break;
    case ModeRewrite:
      Mode = srcCopy;
      break;
    case ModeErase:
      Mode = srcBic;
      break;
    case ModeInverse:
      Mode = notSrcCopy;
      break;
    }

  /* Set up character size */
  charSize.h = CharWide;
  charSize.v = CharHigh;

  if (ModeBold)
    {
      charSize.h<<=1;
      charSize.v<<=1;
    }

  /* Set up transfer rects */
  fromRect.top=0;
  fromRect.bottom=16;
  fromRect.left=0;
  fromRect.right = count << 3;

  toRect.bottom = screen_scale_y(Coord->y+1);
  toRect.top = toRect.bottom - charSize.v;
  if (Reverse)
    {
      chNum = count - 1;
      direction = -1;
      toRect.right = screen_scale_x(Coord->x);
      toRect.left = toRect.right - charSize.h * count;
    }
  else /* forward */
    {
      chNum=0;
      direction = 1;
      toRect.left = screen_scale_x(Coord->x);
      toRect.right = toRect.left + charSize.h * count;
    }

  /* plot the bitmap. */
  while (count--)
    {
      drawFrom = chPt + ((*ch++ + offset) << 4);
      drawTo = &drawBits[0][chNum];
      chNum+=direction;
      for (row=1; row <= 16; row++)
	{
	  *drawTo = *drawFrom++;
	  drawTo += 64;
	}
    }

  /* Finally, blit it to the window. */
  CopyBits(&drawMap, &(win->portBits), &fromRect, &toRect, Mode, NULL);

  if (toRect.top < 0)
    {
      toRect.top = windowHeight;
      toRect.bottom+=windowHeight;
      CopyBits(&drawMap, &(win->portBits), &fromRect, &toRect, Mode, NULL);
    }

  if (toRect.right > windowWidth)
    {
      toRect.right -= windowWidth;
      toRect.left -= windowWidth;
      CopyBits(&drawMap, &(win->portBits), &fromRect, &toRect, Mode, NULL);

      if (toRect.bottom > windowHeight)
	{
	  toRect.bottom -= windowHeight;
	  toRect.top -= windowHeight;
	  CopyBits(&drawMap, &(win->portBits), &fromRect, &toRect, Mode, NULL);
	}
    }
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
  if (is_mono==1)
    screen_mono_paint(Coord);
  else
    screen_color_paint(Coord);
}

/**
 * color_screen_paint - Called to paint at location.
 */
void screen_mono_paint(padPt* Coord)
{
/*   static unsigned short xStack[512]; */
/*   static unsigned short yStack[512]; */
/*   int x=screen_scale_x(Coord->x); */
/*   int y=screen_scale_y(Coord->y); */
/*   unsigned char stackentry = 1; */
/*   unsigned short spanAbove, spanBelow; */
/*   unsigned char oldColor=GetPixel(x,y); */
 
/*   if (oldColor==1) */
/*     return; */
  
/*   do */
/*     { */
/*       unsigned short startx; */
/*       while (x > 0 && GetPixel(x-1,y)==oldColor) */
/*         --x; */

/*       spanAbove = spanBelow = false; */
/*       startx=x; */

      
/*       while(GetPixel(x,y)==oldColor) */
/*         { */
/*           if (y < (512)) */
/*             { */
/* 	      unsigned char belowColor=GetPixel(x,y); */
/*               if (!spanBelow  && belowColor==oldColor) */
/*                 { */
/*                   xStack[stackentry]  = x; */
/*                   yStack[stackentry]  = y+1; */
/*                   ++stackentry; */
/*                   spanBelow = true; */
/*                 } */
/*               else if (spanBelow && belowColor!=oldColor) */
/*                 spanBelow = false; */
/*             } */

/*           if (y > 0) */
/*             { */
/* 	      unsigned char aboveColor=GetPixel(x,y); */
/*               if (!spanAbove  && aboveColor==oldColor) */
/*                 { */
/*                   xStack[stackentry]  = x; */
/*                   yStack[stackentry]  = y-1; */
/*                   ++stackentry; */
/*                   spanAbove = true; */
/*                 } */
/*               else if (spanAbove && aboveColor!=oldColor) */
/*                 spanAbove = false; */
/*             } */
/*           ++x; */
/*         } */
/*       MoveTo(startx,y); */
/*       LineTo(x-1,y); */
/*       --stackentry; */
/*       x = xStack[stackentry]; */
/*       y = yStack[stackentry]; */
/*     } */
/*   while (stackentry); */
}

/**
 * color_screen_paint - Called to paint at location.
 */
void screen_color_paint(padPt* Coord)
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
  ExitToShell();
}
