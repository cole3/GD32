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
#define USBD_ITF_MAX_NUM                1
#define USB_STR_DESC_MAX_SIZE           255

/* USB feature -- Self Powered */
/* #define USBD_SELF_POWERED */

/* USB user string supported */
/* #define USB_SUPPORT_USER_STRING_DESC */

#define CDC_DATA_IN_EP                  EP1_IN
#define CDC_DATA_OUT_EP                 EP3_OUT
#define CDC_CMD_EP                      EP2_IN

/* CDC class endpoints data packet size parameters: 
   you can fine tune these values depending on the needed baudrates and performance */
#define USB_CDC_DATA_PACKET_SIZE        64   /*!< Data endpoint IN/OUT data packet size */
#define USB_CDC_CMD_PACKET_SIZE         8    /*!< Control endpoint data packet size */

#define APP_RX_DATA_SIZE                1024 /*!< Be handled total size of application IN buffer: 
                                                  APP_RX_DATA_SIZE*8/MAX_BAUDARATE*1000 > CDC_IN_FRAME_INTERVAL */

#define CDC_IN_FRAME_INTERVAL           4    /*!< Interval of two IN transfers (in number of frames) */

#define APP_FOPS                        VCP_fops


#endif /* __GD32F10X_USBD_CONF_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
