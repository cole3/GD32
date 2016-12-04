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
#define USBD_CFG_MAX_NUM                   1
#define USBD_ITF_MAX_NUM                   1
#define USB_STR_DESC_MAX_SIZE              64

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* USB user string supported */
/* #define USB_SUPPORT_USER_STRING_DESC */

#define CUSTOMHID_IN_EP                    EP1_IN
#define CUSTOMHID_OUT_EP                   EP1_OUT

#define CUSTOMHID_IN_PACKET                2
#define CUSTOMHID_OUT_PACKET               2


#endif /* __GD32F10X_USBD_CONF_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
