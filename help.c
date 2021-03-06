#include "help.h"
#include "screen.h"

/**
 * Help screen PLATO stream, drawn to page 2
 */
padByte help[] =
  {
   0x1b,
   0x02,
0x1b,
0x0c,
0x1b,
0x12,
0x1b,
0xd1,
0xc0,
0x50,
0xc0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0xe2,
0xc0,
0xc0,
0xc0,
0xc0,
0x1b,
0x0c,
0x1b,
0x12,
0x1d,
0xaf,
0xf0,
0xa0,
0xc0,
0x1b,
0x5a,
0x1b,
0xd1,
0xc0,
0x44,
0x41,
0x1d,
0x21,
0x60,
0x22,
0x50,
0x1b,
0x5a,
0x9f,
0x1b,
0x12,
0x1b,
0xcc,
0x1b,
0xcf,
0x1b,
0xca,
0x4b,
0xc5,
0x59,
0x42,
0xcf,
0x41,
0xd2,
0x44,
0xa0,
0x48,
0xc5,
0xcc,
0x50,
0x1d,
0x2e,
0xf0,
0xa0,
0xd8,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x9f,
0x1b,
0x12,
0x1b,
0xcc,
0x1b,
0x4e,
0x1b,
0xca,
0x50,
0xcc,
0x41,
0xd4,
0xcf,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xd8,
0x36,
0xb8,
0x30,
0x30,
0x30,
0x1d,
0xf0,
0x24,
0x50,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x9f,
0x1b,
0x12,
0x50,
0xcc,
0x41,
0xd4,
0xcf,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xd8,
0x36,
0xb8,
0x30,
0x30,
0x30,
0x1d,
0xf0,
0x28,
0x50,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x9f,
0x1b,
0x12,
0x50,
0xcc,
0x41,
0xd4,
0xcf,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xd8,
0x36,
0xb8,
0x30,
0x30,
0x30,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xc0,
0xc0,
0x1d,
0x22,
0x60,
0xa0,
0x50,
0x1b,
0x12,
0x60,
0x24,
0x48,
0x2e,
0xf0,
0x48,
0xf0,
0xa0,
0x50,
0x22,
0x60,
0x50,
0x1d,
0x60,
0x24,
0x48,
0x60,
0x28,
0x48,
0x2e,
0xf0,
0x48,
0xf0,
0x24,
0x48,
0x22,
0x60,
0x48,
0x1d,
0x60,
0x28,
0x48,
0x60,
0xac,
0x48,
0x2e,
0xf0,
0x48,
0xf0,
0x28,
0x48,
0x22,
0x60,
0x48,
0x1d,
0x2e,
0xf0,
0xa0,
0x50,
0xf0,
0x24,
0x48,
0xaf,
0x60,
0x48,
0x60,
0xa0,
0x50,
0x2e,
0xf0,
0x50,
0x1d,
0xf0,
0x24,
0x48,
0xf0,
0x28,
0x48,
0xaf,
0x60,
0x48,
0x60,
0x24,
0x48,
0x2e,
0xf0,
0x48,
0x1d,
0xf0,
0x28,
0x48,
0xf0,
0xac,
0x48,
0xaf,
0x60,
0x48,
0x60,
0x28,
0x48,
0x2e,
0xf0,
0x48,
0x1d,
0x2d,
0xf0,
0xa0,
0xd8,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x9f,
0x1b,
0x12,
0x41,
0x4e,
0x53,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x41,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x42,
0x41,
0xc3,
0x4b,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x42,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xcf,
0x50,
0x59,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xc3,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x44,
0x41,
0xd4,
0x41,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x44,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xc5,
0x44,
0xc9,
0xd4,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xc5,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xc6,
0xcf,
0x4e,
0xd4,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xc6,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xaf,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x47,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x48,
0xc5,
0xcc,
0x50,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x48,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x4d,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x4d,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x4e,
0xc5,
0xd8,
0xd4,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc5,
0x4e,
0xd4,
0xc5,
0xd2,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x53,
0xd1,
0x55,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xd1,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xc5,
0xd2,
0x41,
0x53,
0xc5,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x42,
0x41,
0xc3,
0x4b,
0x53,
0x50,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x53,
0xd4,
0xcf,
0x50,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x53,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xd4,
0xc5,
0xd2,
0x4d,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xd4,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x53,
0x55,
0x50,
0xc5,
0xd2,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x50,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x53,
0x55,
0x42,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x59,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x53,
0xc9,
0x47,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x2b,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x44,
0xcc,
0xd4,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x2d,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x24,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0xc5,
0x53,
0xc3,
0x1d,
0xf0,
0x24,
0x50,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x9f,
0x1b,
0x12,
0x1b,
0xc3,
0x30,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xe1,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xb1,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xe2,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xa0,
0x88,
0x1b,
0xc3,
0x47,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x63,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xb2,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xe4,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xa0,
0x88,
0x1b,
0xc3,
0xc6,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x65,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xe1,
0x1d,
0x2b,
0x60,
0xd4,
0x9f,
0x65,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xe7,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x6f,
0x88,
0xaf,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xe8,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xe1,
0x88,
0x1d,
0xaa,
0xe2,
0x50,
0x9f,
0x1b,
0xc3,
0xbd,
0x1d,
0x60,
0xd8,
0x9f,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x6a,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xe1,
0x88,
0x1b,
0xc3,
0x41,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xeb,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x33,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x6c,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xb4,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xed,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xa0,
0x88,
0x1b,
0xc3,
0xa3,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xee,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xbd,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0x59,
0x50,
0x41,
0xc0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x6f,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x35,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xf0,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xa0,
0x88,
0x60,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x71,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x36,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x72,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xb7,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xf3,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xbb,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x74,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xa0,
0x88,
0x1b,
0xc3,
0x41,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xf5,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xa0,
0x88,
0x1b,
0xc3,
0x48,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xf6,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xb8,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x77,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xa0,
0x88,
0xde,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x78,
0x1d,
0x2d,
0xf0,
0x28,
0x50,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x9f,
0x1b,
0x12,
0x6f,
0x88,
0x1b,
0xc3,
0x41,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xf9,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xcc,
0xc5,
0x4d,
0x42,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x30,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xd2,
0xc5,
0x4d,
0x42,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xb1,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x3f,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x36,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xc3,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x33,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xc9,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xac,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xa5,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xbd,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xa9,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x41,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x28,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xd8,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x27,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x44,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xa6,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xd7,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x28,
0x1b,
0xc3,
0xc0,
0x1b,
0x42,
0xa9,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xc3,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x44,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xc6,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x41,
0x1d,
0x27,
0x60,
0xd4,
0x9f,
0xc5,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x47,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xcf,
0x88,
0x1d,
0xa6,
0x71,
0x50,
0x9f,
0xaf,
0x1d,
0xf0,
0xd8,
0x9f,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x48,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0xca,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xc9,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x41,
0x88,
0x1d,
0xa5,
0xf5,
0x50,
0x9f,
0x1b,
0xc3,
0xbd,
0x1b,
0x41,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xca,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x41,
0x88,
0x1d,
0x63,
0x50,
0x9f,
0x1b,
0xc3,
0x41,
0x1d,
0x60,
0xd8,
0x9f,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x4b,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x42,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x6f,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0xcf,
0x88,
0x1d,
0x24,
0x63,
0x50,
0x9f,
0x1b,
0xc3,
0x41,
0x1d,
0x60,
0xd8,
0x9f,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x59,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x39,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0x3c,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x3a,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xbe,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0xc3,
0x22,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xc0,
0xfc,
0xcf,
0xc0,
0x1b,
0x12,
0x1b,
0x42,
0x4d,
0xc9,
0xc3,
0xd2,
0xcf,
0xa0,
0xa9,
0x1d,
0x2e,
0xf0,
0x2d,
0xc0,
0x1b,
0x5a,
0x1b,
0xe1,
0xc0,
0xfc,
0xff,
0xff,
0xff,
0xff,
0x9f,
0x1b,
0x12,
0xd4,
0xd4,
0x59,
0xa0,
0x4b,
0x65,
0xf9,
0xf3,
0x1d,
0x2d,
0xf0,
0xac,
0x50,
0x1b,
0x5a,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x9f,
0x1b,
0x12,
0xc6,
0xb1,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xd4,
0xd4,
0x59,
0xa0,
0x4d,
0x6f,
0xe4,
0x65,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc6,
0xb2,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0x50,
0xcc,
0x41,
0xd4,
0xcf,
0xa0,
0x4d,
0x6f,
0xe4,
0x65,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc6,
0xb1,
0x30,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xd1,
0xf5,
0x69,
0x74,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0x42,
0xd2,
0xc5,
0x41,
0x4b,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0x48,
0xe1,
0xee,
0xe7,
0xa0,
0x55,
0xf0,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x44,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0x44,
0x69,
0xe1,
0x6c,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x33,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x33,
0x30,
0x30,
0xa0,
0x42,
0xe1,
0xf5,
0xe4,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xb1,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xb1,
0xb2,
0x30,
0x30,
0xa0,
0x42,
0xe1,
0xf5,
0xe4,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xb2,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xb2,
0xb4,
0x30,
0x30,
0xa0,
0x42,
0xe1,
0xf5,
0xe4,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x36,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x39,
0x36,
0x30,
0x30,
0xa0,
0x42,
0xe1,
0xf5,
0xe4,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x39,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0xb1,
0x39,
0xb2,
0x30,
0x30,
0xa0,
0x42,
0xe1,
0xf5,
0xe4,
0x8d,
0x1b,
0x59,
0x50,
0x41,
0xc0,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0xb8,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xa0,
0xa0,
0xa0,
0x33,
0xb8,
0xb4,
0x30,
0x30,
0xa0,
0x42,
0xe1,
0xf5,
0xe4,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x53,
0x48,
0xc9,
0xc6,
0xd4,
0x2d,
0x44,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xc5,
0xe4,
0x69,
0x74,
0xa0,
0x44,
0x69,
0xe1,
0x6c,
0xa0,
0x53,
0x74,
0x72,
0x8d,
0x1b,
0xe1,
0xff,
0xff,
0xc3,
0xf0,
0xff,
0xff,
0x1b,
0x12,
0xc3,
0xd4,
0xd2,
0xcc,
0x2d,
0x53,
0x48,
0xc9,
0xc6,
0xd4,
0x2d,
0xc9,
0xa0,
0x1b,
0xe1,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0x1b,
0x12,
0xa0,
0x8d,
0xa0,
0xc5,
0xe4,
0x69,
0x74,
0xa0,
0xc9,
0xee,
0x69,
0x74,
0xa0,
0x53,
0x74,
0x72,
0x1b,
0x59,
0x50,
0x41,
0xc0,   
0x1b,
0x03,
  };

/**
 * help_init(void) - Initialize and draw help
 */
void help_init(void)
{
}
