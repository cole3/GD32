/**
  ******************************************************************************
  * @file    usbd_conf.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB device configuration header file
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USBD_CONF_H
#define __GD32F10X_USBD_CONF_H

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"

/* Exported constants --------------------------------------------------------*/
#define USBD_CFG_MAX_NUM                1
#define USBD_ITF_MAX_NUM                MAX_USED_MEMORY_MEDIA
#define USB_STR_DESC_MAX_SIZE           200

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* USB user string supported */
#define USB_SUPPORT_USER_STRING_DESC

#define TRANSFER_SIZE                   1024   /* DFU maximum data packet size */

/* Maximum number of supported memory media (Flash, RAM or EEPROM and so on) */
#define MAX_USED_MEMORY_MEDIA           1

/* Memory address from where user application will be loaded, which represents 
   the DFU code protected against write and erase operations.*/
#define APP_LOADED_ADDR                 0x08003200

/* Exported macro ------------------------------------------------------------*/

/* Make sure the corresponding memory where the DFU code should not be loaded
   cannot be erased or overwritten by DFU application. */
#define IS_PROTECTED_AREA(addr)  (uint8_t)(((addr >= 0x08000000) && (addr < (APP_LOADED_ADDR)))? 1 : 0)

#endif /* __GD32F10X_USBD_CONF_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
