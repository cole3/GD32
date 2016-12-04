/**
  ******************************************************************************
  * @file    usbd_desc.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB descriptor defines and function prototype
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USBD_DESC_H
#define __GD32F10X_USBD_DESC_H

/* Includes ------------------------------------------------------------------*/
#include "usb_core.h"
#include "usbd_def.h"
#include "usbd_enum.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Core_Library
  * @{
  */

/** @defgroup USBD_Descriptor_Exported_Constants
  * @{
  */
#define USB_DEVICE_DESC_SIZE             0x12
#define USB_LANGID_STRING_SIZE           0x04
#define USB_SERIAL_STRING_SIZE           0x06

#define DEVICE_ID                        (0x40022100)

/**
  * @}
  */

/** @defgroup USBD_Descriptor_Exported_Variables
  * @{
  */
extern  uint8_t USBD_StrDesc[USB_STR_DESC_MAX_SIZE];
extern  USBD_Desc_cb_TypeDef USER_desc;

/**
  * @}
  */

/** @defgroup USBD_Descriptor_Exported_Functions
  * @{
  */
void Get_SerialString(void);

uint8_t*  USBD_USER_DevDesc        (uint8_t USBSpeed, uint16_t *len);
uint8_t*  USBD_USER_LANGIDStrDesc  (uint8_t USBSpeed, uint16_t *len);
uint8_t*  USBD_USER_MFCStrDesc     (uint8_t USBSpeed, uint16_t *len);
uint8_t*  USBD_USER_ProdStrDesc    (uint8_t USBSpeed, uint16_t *len);
uint8_t*  USBD_USER_SerialStrDesc  (uint8_t USBSpeed, uint16_t *len);
uint8_t*  USBD_USER_ConfigStrDesc  (uint8_t USBSpeed, uint16_t *len);
uint8_t*  USBD_USER_ItfStrDesc     (uint8_t USBSpeed, uint16_t *len);

#ifdef USB_SUPPORT_USER_STRING_DESC
uint8_t*  USBD_USER_UserStringDesc (uint8_t USBSpeed, uint8_t idx, uint16_t *len);
#endif 

/**
  * @}
  */

#endif /* __GD32F10X_USBD_DESC_H */

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
