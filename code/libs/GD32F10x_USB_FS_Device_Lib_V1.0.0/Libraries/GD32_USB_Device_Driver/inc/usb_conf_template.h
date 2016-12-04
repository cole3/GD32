/**
  ******************************************************************************
  * @file    usb_conf_template.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   General low level driver configuration
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USB_CONF_TEMPLATE_H
#define __GD32F10X_USB_CONF_TEMPLATE_H

/* Includes ------------------------------------------------------------------*/
#include "gd32f10x.h"
#include "gd32105c_eval.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Driver
  * @{
  */

/** @defgroup USB_Configure_Exported_Defines
  * @{
  */

/* Define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
/* #define USB_DEVICE_LOW_PWR_MGMT_SUPPORT */

/* Endpoints used by the device */
#define EP_NUM              (3) 

/* Buffer table base address */
#define BTABLE_ADDRESS      (0x0000)

/* Endpoint 0 Rx/Tx buffers base address */
#define ENDP0_RX_ADDRESS    (0x18)
#define ENDP0_TX_ADDRESS    (0x58)

/* Device endpoint Tx buffer base address */
#define MSC_TX_ADDRESS      (0x98)
    
/* Device endpoint Rx buffer base address */
#define MSC_RX_ADDRESS      (0xD8)

/**
  * @}
  */

#endif /* __GD32F10X_USB_CONF_TEMPLATE_H */

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
