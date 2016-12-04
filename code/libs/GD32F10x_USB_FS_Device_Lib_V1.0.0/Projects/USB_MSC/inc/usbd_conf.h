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
#define USBD_CFG_MAX_NUM                        1
#define USBD_ITF_MAX_NUM                        1
#define USB_STR_DESC_MAX_SIZE                   64

/* #define USBD_SELF_POWERED */

/* Class Layer Parameter */
#define MSC_IN_EP                               EP1_IN
#define MSC_OUT_EP                              EP2_OUT
#define MSC_DATA_PACKET_SIZE                    64

#if defined(USE_GD32F103B_EVAL)
    #define MSC_MEDIA_PACKET_SIZE                 512
#else
    #define MSC_MEDIA_PACKET_SIZE                 1024
#endif

#endif /* __GD32F10X_OTG_FS_USBD_CONF_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
