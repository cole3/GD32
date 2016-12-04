/**
  ******************************************************************************
  * @file    gd32f10x_it.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Main interrupt service routines
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gd32_it.h"
#include "usbd_keyboard_core.h"

/* Private define ------------------------------------------------------------*/
#define CURSOR_STEP     6

/* Private function prototypes -----------------------------------------------*/
//static uint8_t *USBD_MOUSE_GetPos(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void  NMI_Handler (void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void  HardFault_Handler (void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void  SVC_Handler (void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void  PendSV_Handler (void)
{
}

uint8_t KEY_Buffer[8] = {0, 0, 0x04, 0, 0, 0, 0, 0};

/**
  * @brief  This function sends the input report repeatedly.
  * @param  None
  * @retval None
  */
void  SysTick_Handler (void)
{

    USBD_CUSTOMHID_SendReport (&USB_Device_dev, KEY_Buffer, 8);

#if 0
    /* Get usb mouse position */
    buf = USBD_MOUSE_GetPos();

    /* Change the cursor position */
    if((buf[0] != 0) || (buf[1] != 0))
    {
        /* Send mouse report */
        USBD_HID_SendReport (&USB_Device_dev, buf, 2);
    }
#endif
}

/**
  * @brief  This function handles USB FS Handler.
  * @param  None
  * @retval None
  */
void  USB_LP_CAN1_RX0_IRQHandler (void)
{
    USB_Ifr();
}

/**
  * @brief  This function handles EXTI14_15_IRQ Handler.
  * @param  None
  * @retval None
  */
void  EXTI15_10_IRQHandler (void)
{
    if (EXTI_GetIntBitState(TAMPER_KEY_EXTI_LINE) != RESET)
    {
        /* Check if the remote wakeup feature is enabled */
        if (USB_Device_dev.dev.DevRemoteWakeup)
        {
            /* Exit low power mode and re-configure clocks */
            USBD_Resume(RESUME_INTERNAL);
            USB_Device_dev.dev.device_cur_status = USB_Device_dev.dev.device_old_status;

            /*Disable Remote wakeup Feature*/
            USB_Device_dev.dev.DevRemoteWakeup = 0;
        }

        /* Clear the EXTI line pending bit */
        EXTI_ClearIntBitState(TAMPER_KEY_EXTI_LINE);
    }
}

#ifdef USB_DEVICE_LOW_PWR_MODE_SUPPORT
/**
  * @brief  This function handles USB WakeUp interrupt request.
  * @param  None
  * @retval None
  */
void  USBWakeUp_IRQHandler (void)
{
    EXTI_ClearIntBitState(EXTI_LINE18);
}

#endif

#if 0
/**
  * @brief  To get usb mouse state
  * @param  None
  * @retval The direction value
*/
uint8_t  MouseState (void)
{
    /* Have pressed "right" key */
    if (!GD_EVAL_KeyGetState(KEY_RIGHT))
    {
        return MOUSE_RIGHT;
    }

    /* Have pressed "left" key */
    if (!GD_EVAL_KeyGetState(KEY_LEFT))
    {
        return MOUSE_LEFT;
    }

    /* Have pressed "down" key */
    if (!GD_EVAL_KeyGetState(KEY_DOWN))
    {
        return MOUSE_DOWN;
    }

#if defined(USE_GD32F103E_EVAL)
    /* Have pressed "up" key */
    if (!GD_EVAL_KeyGetState(KEY_UP))
    {
        return MOUSE_UP;
    }
#endif

    /* No pressed any key */
    return 0;

}

/**
  * @brief  Get usb mouse position
  * @param  None
  * @retval Pointer to report buffer
*/
static uint8_t  *USBD_MOUSE_GetPos (void)
{
    int8_t x = 0, y = 0;
    static uint8_t MOUSE_Buffer[2];

    switch (MouseState())
    {
        case MOUSE_LEFT:
            x -= CURSOR_STEP;
            break;

        case MOUSE_RIGHT:
            x += CURSOR_STEP;
            break;

        case MOUSE_DOWN:
            y += CURSOR_STEP;
            break;

#if defined(USE_GD32F103E_EVAL)
        case MOUSE_UP:
            y -= CURSOR_STEP;
            break;
#endif

        default:
            break;
    }

    MOUSE_Buffer[0] = x;
    MOUSE_Buffer[1] = y;

    return MOUSE_Buffer; 
}

#endif

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
