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

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
