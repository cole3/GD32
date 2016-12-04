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
#include  "usbd_hid_core.h"
#include  "usbd_user.h"

/* Private variables ---------------------------------------------------------*/
USB_DEVICE_HANDLE  USB_Device_dev;

/* Private functions ---------------------------------------------------------*/
extern void print(char* fmt, ...);
/**
  * @brief  Main routine will construct a USB mouse
  * @param  None
  * @retval None
  */
void USB_Mouse_Init(void)
{
    print("enter\n");
    /* Hardware platform initialization */
    USB_HWP_Init();
    print("%d\n", __LINE__);
    /* Configure usb clock */
    USB_HWP_ClockConfig();
    print("%d\n", __LINE__);
    /* Configure USB interrupt */
    USB_HWP_USBINTConfig();
  
    print("%d\n", __LINE__);

    /* USB device configuration */
    USBD_Init(&USB_Device_dev,
              &USER_desc,
              &USBD_HID_cb,
              &USER_cb);
    print("%d\n", __LINE__);

    /* Connect the USB device */
    USBD_Connect(&USB_Device_dev);
    print("%d\n", __LINE__);
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
