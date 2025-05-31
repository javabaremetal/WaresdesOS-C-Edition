#include "types.h"

#ifndef __WARESDES_DEFINES__
#define __WARESDES_DEFINES__

#define MAIN void
#define DOWNLOAD char
#define MUSIC short
#define VIDEO int

typedef unsigned int format32Bits;
typedef unsigned int format16Bits;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef unsigned char _DEF;

typedef unsigned short int16;
typedef unsigned char int8;

typedef unsigned long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;


#endif

int MouseIn(int x,int y,int lar,int alt);
