/**
  ******************************************************************************
  * @file    gd32_it.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Main interrupt service routines
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gd32_it.h"

/* Private variables ---------------------------------------------------------*/
uint8_t Send_Buffer[4] = {0x00, 0x01, 0x00, 0x01};

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

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void  SysTick_Handler (void)
{
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

#ifdef USB_DEVICE_LOW_PWR_MODE_SUPPORT

/**
  * @brief  This function handles USB WakeUp interrupt request.
  * @param  None
  * @retval None
  */
void  USBWakeUp_IRQHandler (void)
{
    EXTI_ClearITPendingBit(EXTI_Line18);
}

#endif

/**
  * @brief  This function handles EXTI0_1_IRQ Handler.
  * @param  None
  * @retval None
  */
void  EXTI0_IRQHandler (void)
{
    if (EXTI_GetIntBitState(LEFT_KEY_EXTI_LINE) != RESET)
    {
        if(USB_Device_dev.dev.device_cur_status == USB_STATUS_CONFIGURED)
        {
            Send_Buffer[0] = 0x15; 

            if (GD_EVAL_KeyGetState(KEY_LEFT) == Bit_RESET)
            {
                if(Send_Buffer[1])
                {
                    Send_Buffer[1] = 0x00;
                }
                else
                {
                    Send_Buffer[1] = 0x01;
                }
            }

            USBD_CUSTOMHID_SendReport (&USB_Device_dev, Send_Buffer, 2);

        }

        /* Clear the EXTI line pending bit */
        EXTI_ClearIntBitState(LEFT_KEY_EXTI_LINE);
    }
}


/**
  * @brief  This function handles EXTI14_15_IRQ Handler.
  * @param  None
  * @retval None
  */
void  EXTI15_10_IRQHandler (void)
{
    if (EXTI_GetIntBitState(RIGHT_KEY_EXTI_LINE) != RESET)
    {
        if(USB_Device_dev.dev.device_cur_status == USB_STATUS_CONFIGURED)
        {
            Send_Buffer[2] = 0x16; 

            if (GD_EVAL_KeyGetState(KEY_RIGHT) == Bit_RESET)
            {
                if(Send_Buffer[3])
                {
                    Send_Buffer[3] = 0x00;
                }
                else
                {
                    Send_Buffer[3] = 0x01;
                }
            }

            USBD_CUSTOMHID_SendReport (&USB_Device_dev, &Send_Buffer[2], 2);
        }

        /* Clear the EXTI line pending bit */
        EXTI_ClearIntBitState(TAMPER_KEY_EXTI_LINE);
    }
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
