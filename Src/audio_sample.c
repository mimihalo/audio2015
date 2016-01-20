/**
  ******************************************************************************
  * @file    Audio_playback_and_record/src/audio_sample.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-October-2011
  * @brief   audio sample file
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

#if 1
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/** @addtogroup STM32F4-Discovery_Audio_Player_Recorder
  * @{
  */


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/*
  The provided sample audio file (stored in internal flash memory) is extracted from:
   - Title: artofgardens-instr 
   - Artist/Composer: Dan O'Connor
   - Creative Commons license: Attribution 3.0 United States
     Please read the license following this link:
     http://creativecommons.org/licenses/by/3.0/us/
*/     

const uint16_t AUDIO_SAMPLE[88] = {
0x4952, 0x4646, 0x4f6e, 0xf, 0x4157, 0x4556, 0x6d66, 0x2074, 0x12, 0, 0x1, 
0xfdcf, 0xff5d, 0xfdcf, 0xff5d, 0xfd88, 0xff05, 0xfd88, 0xff05, 0xfd88, 0xff05, 0xfd95, 
0xfefe, 0xfd95, 0xfefe, 0xfd99, 0xfeeb, 0xfd99, 0xfeeb, 0xfdf9, 0xff33, 0xfdf9, 0xff33, 
0xfda8, 0xfec7, 0xfda8, 0xfec7, 0xfcd2, 0xfdd5, 0xfcd2, 0xfdd5, 0xfcd2, 0xfdd5, 0xfc9f, 
0xfd84, 0xfc9f, 0xfd84, 0xfce6, 0xfdad, 0xfce6, 0xfdad, 0xfd67, 0xfe0f, 0xfd67, 0xfe0f, 
0xfd82, 0xfe0a, 0xfd82, 0xfe0a, 0xfd92, 0xfdf9, 0xfd92, 0xfdf9, 0xfd9d, 0xfde3, 0xfd9d, 
0xfde3, 0xfd9d, 0xfde3, 0xfd81, 0xfda4, 0xfd81, 0xfda4, 0xfe17, 0xfe16, 0xfe17, 0xfe16, 
0xfeae, 0xfe87, 0xfeae, 0xfe87, 0xff94, 0xff45, 0xff94, 0xff45, 0xd7, 0x5e, 0xd7
};
#endif


/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
