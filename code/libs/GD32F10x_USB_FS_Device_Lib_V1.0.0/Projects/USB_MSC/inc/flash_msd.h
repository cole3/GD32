/**
  ******************************************************************************
  * @file    flash_msd.h 
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Header file for flash_msd.c
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_FLASH_MSD_H
#define __GD32F10X_FLASH_MSD_H

/* Includes ------------------------------------------------------------------*/
#include "gd32f10x.h"

/* Exported defines --------------------------------------------------------- */

/* Word count in half page and one page */
#if defined(USE_GD32F103B_EVAL)
    #define HP_WCOUNT 128
    #define OP_WCOUNT 256
#else
    #define HP_WCOUNT 256
    #define OP_WCOUNT 512
#endif

/* Exported functions ------------------------------------------------------- */
uint32_t  Flash_Init             (void);

uint32_t  Flash_ReadMultiBlocks  (uint8_t* pBuf,
                                 uint32_t ReadAddr,
                                 uint16_t BlkSize,
                                 uint32_t BlkNum);

uint32_t  Flash_WriteMultiBlocks (uint8_t* pBuf,
                                uint32_t WriteAddr,
                                uint16_t BlkSize,
                                uint32_t BlkNum);

#endif /* __GD32F10X_FLASH_MSD_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
