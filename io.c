#include "io.h"
#include "protocol.h"
#include "terminal.h"

#define true 1
#define false 0

extern unsigned char trace_active;

void io_init(void)
{
}

void io_send_byte(unsigned char b)
{
}

void io_main(void)
{
}

/**
 * io_send_string(str,len)
 * Send string to port.
 */
void io_send_string(const char* str, int len)
{
}

/**
 * io_set_baud(int baud) - Set baud rate
 */
void io_set_baud(int baud)
{
}

/**
 * io_hang_up(void) - Hang up modem
 */
void io_hang_up(void)
{
}

/**
 * io_send_cr(void)
 */
void io_send_cr(void)
{
}

/**
 * io_send_dial(void) - Send dial string to modem
 */
void io_send_dial(void)
{
}

/**
 * io_send_back_out(void) - send back out
 */
void io_send_back_out(void)
{
}

void io_done()
{
}
