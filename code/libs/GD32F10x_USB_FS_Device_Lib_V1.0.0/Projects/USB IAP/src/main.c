/**
  ******************************************************************************
  * @file    app.c
  * @author  MCU SD
  * @version V1.0
  * @date    6-Sep-2014
  * @brief   Main routine
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include  "usbd_iap_core.h"
#include  "usbd_user.h"

/* Private variables ---------------------------------------------------------*/
USB_DEVICE_HANDLE  USB_Device_dev;
pAppFunction Application;
uint32_t AppAddress;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main routine will construct a custom HID device
  * @param  None
  * @retval None
  */
int main(void)
{
    /* Configure Tamper key to run firmware */
    GD_EVAL_KeyInit(KEY_TAMPER, KEY_MODE_GPIO);

    /* Tamper key must be pressed on GD321x0-EVAL when power on */
    if(GD_EVAL_KeyGetState(KEY_TAMPER) != 0)
    {
        /* Test if user code is programmed starting from address 0x8003200 */
        if (((*(__IO uint32_t*)APP_LOADED_ADDR) & 0x2FFE0000 ) == 0x20000000)
        {
            AppAddress = *(__IO uint32_t*) (APP_LOADED_ADDR + 4);
            Application = (pAppFunction) AppAddress;

            /* Initialize user application's stack pointer */
            __set_MSP(*(__IO uint32_t*) APP_LOADED_ADDR);

            /* Jump to user application */
            Application();
        }
    }

    /* Hardware platform initialization */
    USB_HWP_Init();

    /* Configure usb clock */
    USB_HWP_ClockConfig();

    /* Configure USB interrupt */
    USB_HWP_USBINTConfig();

    /* USB device configuration */
    USBD_Init(&USB_Device_dev,
              &USER_desc,
              &USBD_CUSTOMHID_cb,
              &USER_cb);

    /* Connect the USB device */
    USBD_Connect(&USB_Device_dev);

    while (1)
    {
    }
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
