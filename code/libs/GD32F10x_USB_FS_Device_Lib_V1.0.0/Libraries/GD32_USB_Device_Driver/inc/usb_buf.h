/**
  ******************************************************************************
  * @file    usb_buf.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB buffer interface functions prototypes
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USB_BUF_H
#define __GD32F10X_USB_BUF_H

/* Includes ------------------------------------------------------------------*/
#include "usb_regs.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Driver
  * @{
  */

/** @defgroup USB_Buffer_Exported_Functions
  * @{
  */
void  FreeUserBuffer   (uint8_t  EpID,  uint8_t Dir);
void  UserCopyToBuffer (uint8_t *UsrBuf, uint16_t BufAddr, uint16_t Bytes);
void  BufferCopyToUser (uint8_t *UsrBuf, uint16_t BufAddr, uint16_t Bytes);

/**
  * @}
  */

#endif /* __GD32F10X_USB_BUF_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
