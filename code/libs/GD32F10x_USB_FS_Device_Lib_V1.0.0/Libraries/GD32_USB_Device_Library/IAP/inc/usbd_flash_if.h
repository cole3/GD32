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
#ifndef __GD32F1X0_USBD_FLASH_IF_H
#define __GD32F1X0_USBD_FLASH_IF_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_iap_mal.h"

/** @addtogroup GD32F1x0_Firmware
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

#if defined(USE_GD32F103E_EVAL)
    #define FLASH_END_ADDR                0x08040000

    #define FLASH_IF_STRING               (uint8_t*) "@Internal Flash   /0x08000000/6*002Ka,122*002Kg"
#endif

#if defined(USE_GD32F103C_EVAL)
    #define FLASH_END_ADDR                0x08020000

    #define FLASH_IF_STRING               (uint8_t*) "@Internal Flash   /0x08000000/12*001Ka,116*001Kg"
#endif

#define OB_RDPT                           0x1ffff800

/**
  * @}
  */

/** @defgroup USB_DFU_FlashIf_Exported_Variables
  * @{
  */
extern IAP_MAL_Property_TypeDef IAP_Flash_cb;

/**
  * @}
  */

#endif /* __GD32F1X0_USBD_FLASH_IF_H */

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
