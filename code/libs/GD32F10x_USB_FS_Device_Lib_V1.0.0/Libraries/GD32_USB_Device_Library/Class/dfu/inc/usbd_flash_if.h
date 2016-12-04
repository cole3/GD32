/**
  ******************************************************************************
  * @file    usbd_flash_if.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB DFU device flash interface header file
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USBD_FLASH_IF_H
#define __GD32F10X_USBD_FLASH_IF_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_dfu_mal.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Class_Library
  * @{
  */

/** @addtogroup USB_DFU_Class
  * @{
  */

/** @defgroup USB_DFU_FlashIf_Exported_Defines
  * @{
  */
#define FLASH_START_ADDR                  0x08000000
#define FLASH_END_ADDR                    0x08020000

#define OB_RDPT                           0x1ffff800

#define FLASH_IF_STRING                   (uint8_t*) "@Internal Flash   /0x08000000/12*001Ka,116*001Kg"

/**
  * @}
  */

/** @defgroup USB_DFU_FlashIf_Exported_Variables
  * @{
  */
extern DFU_MAL_Property_TypeDef DFU_Flash_cb;

/**
  * @}
  */

#endif /* __GD32F10X_USBD_FLASH_IF_H */

/**
  * @}
  */

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
