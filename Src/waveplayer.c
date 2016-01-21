#include "waveplayer.h"

#define BUFLEN 1024
extern FATFS fatfs;
extern I2S_HandleTypeDef hi2s3;
FIL fr;
uint16_t buf1[BUFLEN]={0};
uint16_t buf2[BUFLEN]={0};
UINT bytesRead1=0,bytesRead2=0;
uint8_t bufSwitch=0;

int8_t WavePlayerStart(char *fname)
{
	bufSwitch = 0;
	if(f_open(&fr, fname , FA_READ) != FR_OK)
	{
		return -1;
	}else
	{
		f_read (&fr, buf1, BUFLEN, &bytesRead1);
		HAL_I2S_Transmit_DMA(&hi2s3, buf1, bytesRead1);
	}
	return 1;
}

void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef *hi2s)
{
	bufSwitch = !bufSwitch;
	
	if(bufSwitch)
	{
		f_read (&fr, buf2, BUFLEN, &bytesRead2);
	}else
	{
		f_read (&fr, buf1, BUFLEN, &bytesRead1);
	}
}

 void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef *hi2s)
{
	if(bufSwitch)
	{
		HAL_I2S_Transmit_DMA(&hi2s3, buf2, bytesRead2);
	}else
	{
		HAL_I2S_Transmit_DMA(&hi2s3, buf1, bytesRead1);
	}
}
