/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * trace.c - Trace output functions.
 */

#include <string.h>
#include "protocol.h"

#define true 1
#define false 0

#define TRACE_FILE "trace.txt"

unsigned char trace_active=false;

static int trace_handle;

/**
 * trace_open(void)
 * Open trace file trace.txt
 */
void trace_open(void)
{
}

/**
 * trace_append(buf, len)
 * Append data from ShowPLATO into buffer
 */
void trace_append(padByte* buf, int len)
{
}

/**
 * trace_close(void)
 * Close trace file.
 */
void trace_close(void)
{
}

/**
 * trace_toggle(void)
 * Toggle trace on/off
 */
void trace_toggle(void)
{
}
