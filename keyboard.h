/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * keyboard.h - Keyboard functions
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Events.h>
#include "protocol.h"

/**
 * keyboard_out - If platoKey < 0x7f, pass off to protocol
 * directly. Otherwise, platoKey is an access key, and the
 * ACCESS key must be sent, followed by the particular
 * access key from PTAT_ACCESS.
 */
void keyboard_out(int platoKey);

/**
 * keyboard_main - Handle the keyboard presses
 */
void keyboard_main(EventRecord* e);

/**
 * keyboard_out_tty - keyboard output to serial I/O in TTY mode
 */
void keyboard_out_tty(padByte ch);

#endif
