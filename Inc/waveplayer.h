#ifndef WAVEPLAYER_H
#define WAVEPLAYER_H

#include "ff.h"
#include "stm32f4xx_hal.h"

void WavePlayerStartSample(void);
int8_t WavePlayerStart(char *fname);
int8_t WavePlayerStart_DMA(char *fname);

#endif
