/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * screen.h - Display output functions
 */

#ifndef SCREEN_H
#define SCREEN_H

#include "protocol.h"

/**
 * screen_init() - Set up the screen
 */
void screen_init(void);

/**
 * screen_update_menus() - Update menu state
 */
void screen_update_menus(void);

/**
 * screen_menu_command(menuCommand) - Do menu command.
 */
void screen_menu_command(long menu_command);


/**
 * screen_main(void)
 */
void screen_main(void);

/**
 * screen_update_colors() - Set the terminal colors
 */
void screen_update_colors(void);

/**
 * screen_wait(void) - Sleep for approx 16.67ms
 */
void screen_wait(void);

/**
 * screen_beep(void) - Beep the terminal
 */
void screen_beep(void);

/**
 * screen_clear_palette - Clear the palette
 */
void screen_clear_palette(void);

/**
 * screen_clear - Clear the screen
 */
void screen_clear(void);

/**
 * screen_current_color(void) - Set the current pen mode
 */
int screen_current_color(void);

/**
 * screen_block_draw(Coord1, Coord2) - Perform a block fill from Coord1 to Coord2
 */
void screen_block_draw(padPt* Coord1, padPt* Coord2);

/**
 * screen_dot_draw(Coord) - Plot a mode 0 pixel
 */
void screen_dot_draw(padPt* Coord);

/**
 * screen_line_draw(Coord1, Coord2) - Draw a mode 1 line
 */
void screen_line_draw(padPt* Coord1, padPt* Coord2);

/**
 * screen_char_draw(Coord, ch, count) - Output buffer from ch* of length count as PLATO characters
 */
void screen_char_draw(padPt* Coord, unsigned char* ch, unsigned char count);

/**
 * screen_tty_char - Called to plot chars when in tty mode
 */
void screen_tty_char(unsigned char theChar);

/**
 * screen_color_matching(color) - return index of matching color, or a new index, 
 * if not found.
 */
unsigned char screen_color_matching(padRGB* theColor);

/**
 * screen_foreground - Called to set foreground color.
 */
void screen_foreground(padRGB* theColor);

/**
 * screen_background - Called to set foreground color.
 */
void screen_background(padRGB* theColor);

/**
 * screen_paint - Called to paint at location.
 */
void screen_paint(padPt* Coord);

/**
 * screen_show_status(msg)
 */
void screen_show_status(unsigned char* msg);

/**
 * screen_show_baud_rate - Show baud rate
 */
void screen_show_baud_rate(int baud);

/**
 * screen_show_hang_up - Show hang-up message
 */
void screen_show_hang_up(void);

/**
 * screen_show_dial - Show dial in TTY mode
 */
void screen_show_dial(void);

/**
 * screen_show_dialing_status - Show dialing status.
 */
void screen_show_dialing_status(void);

/**
 * screen_help_save_palette(void) - Save initial help palette
 * for future restore by screen_help_restore_palette(void)
 */
void screen_help_save_palette(void);

/**
 * screen_help_restore_palette(void) - Restore the help
 * palette, because the help screen is visible.
 */
void screen_help_restore_palette(void);

/**
 * screen_save_palette(void) - Save current screen palette state
 * for restore by screen_restore_palette(void)
 */
void screen_save_palette(void);

/**
 * screen_restore_palette(void) - Restore current screen palette
 * upon return from help screen.
 */
void screen_restore_palette(void);

/**
 * screen_show_help - SHow help
 */
void screen_show_help(void);

/**
 * screen_trace_status - Show trace status
 */
void screen_trace_status(const char* status);

/**
 * screen_help_mode_status(void)
 * Put help mode status at bottom of help screen
 */
void screen_help_mode_status(void);

/**
 * screen_greeting(void)
 * show initial greeting
 */
void screen_greeting(void);

/**
 * screen_done()
 * Close down TGI
 */
void screen_done(void);

#endif /* SCREEN_H */
