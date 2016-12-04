/**
  ******************************************************************************
  * @file    app.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Main routine
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/ 
#include "usbd_cdc_core.h"
#include "usbd_user.h"

/* Private variables ---------------------------------------------------------*/
USB_DEVICE_HANDLE  USB_Device_dev;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main routine will construct a USB virtual ComPort device
  * @param  None
  * @retval None
  */
void Virtual_COM_Port_Init(void)
{
    /* Hardware platform initialization */
    USB_HWP_Init();

    /* Configure usb clock */
    USB_HWP_ClockConfig();

    /* Configure USB interrupt */
    USB_HWP_USBINTConfig();

    /* USB device configuration */
    USBD_Init(&USB_Device_dev,
              &USER_desc,
              &USBD_CDC_cb,
              &USER_cb);

    /* Connect the USB device */
    USBD_Connect(&USB_Device_dev);
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
