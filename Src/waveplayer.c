#include "waveplayer.h"

#define BUFLEN 1024
#define BUFLEN_BYTE 4096
extern FATFS fatfs;
extern I2S_HandleTypeDef hi2s2;
FIL fr;
uint32_t buf1[BUFLEN]={0};
uint32_t buf2[BUFLEN]={0};
UINT bytesRead1=0,bytesRead2=0;
uint8_t bufSwitch=0,playing=0;

int8_t WavePlayerStart(char *fname)
{
	bufSwitch = 0;
	if(f_open(&fr, fname , FA_READ) != FR_OK)
	{
		return -1;
	}else
	{
		playing=1;
		f_read (&fr, buf1, BUFLEN_BYTE, &bytesRead1);
		HAL_I2S_Transmit_DMA(&hi2s2, (uint16_t*)buf1, BUFLEN);
	}
	return 1;
}

void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef *hi2s)
{
	bufSwitch = !bufSwitch;
	
	if(bufSwitch)
	{
		f_read (&fr, buf2, BUFLEN_BYTE, &bytesRead2);
		if(bytesRead2<=0)
		{
			playing=0;
		}
	}else
	{
		f_read (&fr, buf1, BUFLEN_BYTE, &bytesRead1);
		if(bytesRead1<=0)
		{
			playing=0;
		}
	}
}

 void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef *hi2s)
{
	if(bufSwitch && playing)
	{
		HAL_I2S_Transmit_DMA(&hi2s2, (uint16_t*)buf2, BUFLEN);
	}else if(playing)
	{
		HAL_I2S_Transmit_DMA(&hi2s2, (uint16_t*)buf1, BUFLEN);
	}else
	{
		HAL_I2S_DMAStop(&hi2s2);
	}
}
