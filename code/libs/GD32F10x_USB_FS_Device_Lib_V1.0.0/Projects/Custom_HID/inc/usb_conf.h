/**
  ******************************************************************************
  * @file    usb_conf.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB device driver basic configuration
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USB_CONF_H
#define __GD32F10X_USB_CONF_H

/* Includes ------------------------------------------------------------------*/
#include "gd32f10x.h"

#if defined(USE_GD32F103B_EVAL)
    #include "gd32103b_eval.h"
#elif defined(USE_GD32F103C_EVAL)
    #include "gd32103c_eval.h"
#elif defined(USE_GD32F103E_EVAL)
    #include "gd32103e_eval.h"
#else
    #error "Missing define: USE_GD32F103B_EVAL or USE_GD32F103C_EVAL or USE_GD32F103E_EVAL"
#endif

/* Exported constants --------------------------------------------------------*/
/* Define if low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event and wakes up after the USB wakeup event is received. */
/* #define USB_DEVICE_LOW_PWR_MODE_SUPPORT */

/* Endpoint count used by the custom HID device */
#define EP_COUNT         (2)

/* Base address of the allocation buffer, used for buffer descriptor table and packet memory */
#define BUFFER_ADDRESS   (0x0000)

/* Endpoint0, Rx/Tx buffers address */
#define EP0_RX_ADDRESS   (0x40)
#define EP0_TX_ADDRESS   (0x80)

/* Custom HID Tx buffer address */
#define HID_TX_ADDRESS   (0x150)

/* Custom HID Rx buffer address */
#define HID_RX_ADDRESS   (0x160)

#if defined(USE_GD32F103B_EVAL)
    #define USB_PULLUP                      GPIOD
    #define USB_PULLUP_PIN                  GPIO_PIN_9
    #define RCC_APB2Periph_GPIO_PULLUP      RCC_APB2PERIPH_GPIOD
#endif

#if defined(USE_GD32F103C_EVAL)
    #define USB_PULLUP                      GPIOD
    #define USB_PULLUP_PIN                  GPIO_PIN_13
    #define RCC_APB2Periph_GPIO_PULLUP      RCC_APB2PERIPH_GPIOD
#endif

#if defined(USE_GD32F103E_EVAL)
    #define USB_PULLUP                      GPIOG
    #define USB_PULLUP_PIN                  GPIO_PIN_8
    #define RCC_APB2Periph_GPIO_PULLUP      RCC_APB2PERIPH_GPIOG
#endif

#endif /* __GD32F10X_USB_CONF_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
