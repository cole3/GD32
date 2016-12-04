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

/* Define if Low power mode is enabled; it allows entering the device into DEEP_SLEEP mode
   following USB suspend event, and wakes up after the USB wakeup event is received. */
/* #define USB_DEVICE_LOW_PWR_MODE_SUPPORT */

/* Endpoint count used by the MSC device */
#define EP_COUNT                      (3)

/* Base address of the allocation buffer, used for buffer descriptor table and packet memory */
#define BUFFER_ADDRESS                (0x0000)

/* Endpoint0, Rx/Tx buffers address */
#define EP0_RX_ADDRESS                (0x18)
#define EP0_TX_ADDRESS                (0x58)

/* Mass storage device Tx buffer address */
#define MSC_TX_ADDRESS                (0x98)

/* Mass storage device Rx buffer address */
#define MSC_RX_ADDRESS                (0xD8)

#if defined(USE_GD32F103B_EVAL)
    #define USB_PULLUP                      GPIOD
    #define USB_PULLUP_PIN                  GPIO_PIN_9
    #define RCC_APB2Periph_GPIO_PULLUP      RCC_APB2PERIPH_GPIOD

    #define PAGE_SIZE                       ((uint32_t)(1024))
    #define NAND_FLASH_BASE_ADDRESS         ((uint32_t)(0x08000000 + 0x04000))
    #define NAND_FLASH_END_ADDRESS          ((uint32_t)(0x08000000 + 0x10000))

#elif defined(USE_GD32F103C_EVAL)
    #define USB_PULLUP                      GPIOD
    #define USB_PULLUP_PIN                  GPIO_PIN_13
    #define RCC_APB2Periph_GPIO_PULLUP      RCC_APB2PERIPH_GPIOD

    #define PAGE_SIZE                       ((uint32_t)(2048))
    #define NAND_FLASH_BASE_ADDRESS         ((uint32_t)(0x08000000 + 0x04000))
    #define NAND_FLASH_END_ADDRESS          ((uint32_t)(0x08000000 + 0x24000))

#elif defined(USE_GD32F103E_EVAL)
    #define USB_PULLUP                      GPIOG
    #define USB_PULLUP_PIN                  GPIO_PIN_8
    #define RCC_APB2Periph_GPIO_PULLUP      RCC_APB2PERIPH_GPIOG

    #define PAGE_SIZE                       ((uint32_t)(2048))
    #define NAND_FLASH_BASE_ADDRESS         ((uint32_t)(0x08000000 + 0x04000))
    #define NAND_FLASH_END_ADDRESS          ((uint32_t)(0x08000000 + 0x24000))

#elif defined(USE_GD32F103K_EVAL)
    #define USB_PULLUP                      GPIOD
    #define USB_PULLUP_PIN                  GPIO_PIN_9
    #define RCC_APB2Periph_GPIO_PULLUP      RCC_APB2PERIPH_GPIOD

    #define PAGE_SIZE                       ((uint32_t)(2048))
    #define NAND_FLASH_BASE_ADDRESS         ((uint32_t)(0x08000000 + 0x04000))
    #define NAND_FLASH_END_ADDRESS          ((uint32_t)(0x08000000 + 0xF4000))

#else
    #error "Missing define: USE_GD32F103B_EVAL or USE_GD32F103C_EVAL or USE_GD32F103E_EVAL or USE_GD32F103K_EVAL"
#endif

#define BLOCK_SIZE                    (PAGE_SIZE / 2)
#define BLOCK_NUM                     ((NAND_FLASH_END_ADDRESS - NAND_FLASH_BASE_ADDRESS) / BLOCK_SIZE)

#endif /* __GD32F10X_USB_CONF_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
