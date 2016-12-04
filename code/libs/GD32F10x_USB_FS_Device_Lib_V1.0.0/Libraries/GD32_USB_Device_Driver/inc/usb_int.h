/**
  ******************************************************************************
  * @file    usb_int.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB device interrupt management header file
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USB_INT_H
#define __GD32F10X_USB_INT_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_it.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Driver
  * @{
  */

/** @defgroup USB_Interrupt_Exported_Functions
  * @{
  */
void  USB_Ifr (void);

/**
  * @}
  */

#endif /* __GD32F10X_USB_INT_H */

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
