/**
  ******************************************************************************
  * @file    usbd_cdc_vcp.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB virtual ComPort media access layer header file
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USBD_CDC_VCP_H
#define __GD32F10X_USBD_CDC_VCP_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_cdc_core.h"

/* Exported type ------------------------------------------------------------*/

/* Virtual ComPort configured parameters */
typedef struct
{
    uint32_t dwDTERate;   /* Data terminal rate */
    uint8_t  bCharFormat; /* Stop bits */
    uint8_t  bParityType; /* Parity */
    uint8_t  bDataBits;   /* Data bits */
}
LINE_CODING;

/* Exported constants --------------------------------------------------------*/

/* The ComPort IRQ handler function is implemented not in gd32it.c, but in the usbd_cdc_vcp.c file. */
#define GDEVAL_COM1_IRQHandler           USART1_IRQHandler
#define GDEVAL_COM2_IRQHandler           USART2_IRQHandler

#define DEFAULT_CONFIG                  0
#define SETTING_CONFIG                  1

/* Exported functions ------------------------------------------------------- */
void  GDEVAL_COM1_IRQHandler (void);
void  GDEVAL_COM2_IRQHandler (void);

#endif /* __GD32F10X_USBD_CDC_VCP_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
