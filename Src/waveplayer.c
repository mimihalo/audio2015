#include "waveplayer.h"

#define BUFLEN 1024
#define BUFLEN_BYTE (BUFLEN*sizeof(uint16_t))
extern FATFS fatfs;
extern I2S_HandleTypeDef hi2s2;
FIL fr;
uint16_t buf1[BUFLEN]={0};
uint16_t buf2[BUFLEN]={0};
UINT bytesRead1=0,bytesRead2=0;
uint8_t bufSwitch=0,playing=0;
uint16_t AUDIO_SAMPLE[32]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

void WavePlayerStartSample()
{
	while(1)
	{
		HAL_I2S_Transmit(&hi2s2, (uint16_t*)AUDIO_SAMPLE, 32,32768);
	}
}
	
int8_t WavePlayerStart(char *fname)
{
	bufSwitch = 0;
	if(f_open(&fr, fname , FA_READ) != FR_OK)
	{
		return -1;
	}else
	{
		playing=1;
		do
		{
			f_read (&fr, buf1, BUFLEN_BYTE, &bytesRead1);
			if(bytesRead1>0)
				HAL_I2S_Transmit(&hi2s2, (uint16_t*)buf1, BUFLEN,1000000);
		}while(bytesRead1>0);
		playing=0;
	}
	return 1;
}

int8_t WavePlayerStart_DMA(char *fname)
{
	
	if(f_open(&fr, fname , FA_READ) != FR_OK)
	{
		return -1;
	}else
	{
		playing=1;
		f_read (&fr, buf1, BUFLEN_BYTE, &bytesRead1);
		f_read (&fr, buf2, BUFLEN_BYTE, &bytesRead2);
		HAL_I2S_Transmit_DMA(&hi2s2, (uint16_t*)buf1, BUFLEN);
		bufSwitch = 1;
	}
	return 1;
}

void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef *hi2s)
{
	
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
	
	if(bufSwitch)
	{
		f_read (&fr, buf1, BUFLEN_BYTE, &bytesRead1);
		bufSwitch = 0;
		if(bytesRead2<=0)
		{
			playing=0;
		}
	}else
	{
		f_read (&fr, buf2, BUFLEN_BYTE, &bytesRead2);
		bufSwitch = 1;
		if(bytesRead1<=0)
		{
			playing=0;
		}
	}
}
