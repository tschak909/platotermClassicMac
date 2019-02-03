#include <Devices.h>
#include <Serial.h>
#include <OSUtils.h>
#include "io.h"
#include "protocol.h"
#include "terminal.h"
#include "config.h"

#define true 1
#define false 0

#define SERIAL_BUFFER_SIZE 16000

extern unsigned char trace_active;
extern ConfigInfo config;
extern void done(void);

short driverIn;
short driverOut;
SerShk handshake;
Ptr serial_buffer;
CntrlParam paramBlock;

void io_init(void)
{
  if (OpenDriver("\p.AOut",&driverOut) != noErr)
    done();
  if (OpenDriver("\p.AIn",&driverIn) != noErr)
    done();

  handshake.fXOn=0;
  handshake.fCTS=1;
  handshake.errs=0;
  handshake.evts=0;
  handshake.fInX=0;

  SerHShake(driverIn,&handshake);
  io_set_baud(config.baud);
  serial_buffer=NewPtr(SERIAL_BUFFER_SIZE);

  SerSetBuf(driverIn,serial_buffer,SERIAL_BUFFER_SIZE);
}

void io_send_byte(unsigned char b)
{
  long count=1;
  /* if (NoEcho==padF) */
  /*   return; */

  FSWrite(driverOut,&count,&b);
}

void io_main(void)
{
  long count;
  padByte inBuff[SERIAL_BUFFER_SIZE];
  SerGetBuf(driverIn,&count);
  if (count>0)
    {
      FSRead(driverIn,&count,inBuff);
      ShowPLATO(inBuff,(short)count);
    }
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
  SerReset(driverOut,baud+stop10+noParity+data8);
  paramBlock.ioCRefNum=driverIn;
  paramBlock.csCode=kSERDHandshakeRS232;
  PBControl((ParmBlkPtr)&paramBlock,false);
  paramBlock.csCode=kSERDAssertDTR;
  PBControl((ParmBlkPtr)&paramBlock,false);
  config.baud=baud;
}

/**
 * io_hang_up(void) - Hang up modem
 */
void io_hang_up(void)
{
  paramBlock.csCode=kSERDNegateDTR;
  PBControl((ParmBlkPtr)&paramBlock,false);    
  Delay(100,NULL);
  paramBlock.csCode=kSERDAssertDTR;
  PBControl((ParmBlkPtr)&paramBlock,false);  
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
  if (serial_buffer!=NULL)
    {
      io_hang_up();
      SerSetBuf(driverIn,NULL,0);
      DisposePtr(serial_buffer);
      serial_buffer=NULL;
    }
}
