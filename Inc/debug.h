#ifndef DEBUG_H
#define DEBUG_H

#include "stm32f4xx_hal.h"

#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

struct __FILE { int handle; /* Add whatever is needed */ };
extern FILE __stdout;
extern FILE __stdin;

int fputc(int ch, FILE *f);

#endif
