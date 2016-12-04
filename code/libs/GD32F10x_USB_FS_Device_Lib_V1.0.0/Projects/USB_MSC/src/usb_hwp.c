/**
  ******************************************************************************
  * @file    usb_hwp.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Hardware platform configuration functions
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------ */
#include "usb_hwp.h"

/* Private functions --------------------------------------------------------- */

/**
  * @brief  Initialize hardware platform
  * @param  None
  * @retval None
  */
void  USB_HWP_Init (void)
{
    GPIO_InitPara GPIO_InitStructure;

#ifdef USB_DEVICE_LOW_PWR_MODE_SUPPORT
    EXTI_InitPara EXTI_InitStructure;
#endif

    /* Enable usb pull-up pin clock */ 
    RCC_APB2PeriphClock_Enable(RCC_APB2Periph_GPIO_PULLUP, ENABLE);

    /* Configure usb pull-up pin */
    GPIO_InitStructure.GPIO_Pin = USB_PULLUP_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUT_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_Init(USB_PULLUP, &GPIO_InitStructure);

#ifdef USB_DEVICE_LOW_PWR_MODE_SUPPORT

    /* Enable the power clock */
    RCC_APB1PeriphClock_Enable(RCC_APB1Periph_PWR, ENABLE);

    /* USB wakeup EXTI line configuration */
    EXTI_ClearITPendingBit(EXTI_LINE18);
    EXTI_InitStructure.EXTI_LINE = EXTI_LINE18;
    EXTI_InitStructure.EXTI_Trigger = EXTI_TRIGGER_RISING;
    EXTI_InitStructure.EXTI_Mode = EXTI_MODE_INTERRUPT;
    EXTI_InitStructure.EXTI_LINEEnable = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

#endif
}

/**
  * @brief  Configure usb cable
  * @param  NewState: cable state
  * @Retval None
  */
void  USB_Cable_Config (TypeState NewState)
{
    if (NewState == ENABLE)
    {
        GPIO_SetBits(USB_PULLUP, USB_PULLUP_PIN);
    }
    else
    {
        GPIO_ResetBits(USB_PULLUP, USB_PULLUP_PIN);
    }
}

/**
  * @brief  Enable usb clock
  * @param  None
  * @retval None
  */
void  USB_HWP_ClockConfig (void)
{
    /* Configure USB model clock from PLL clock */
    RCC_USBCLKConfig(RCC_USBCLK_PLL_DIV1_5);

    /* Enable USB APB1 clock */
    RCC_APB1PeriphClock_Enable(RCC_APB1PERIPH_USB, ENABLE);
}

/**
  * @brief  Configure usb global interrupt
  * @param  None
  * @retval None
  */
void  USB_HWP_USBINTConfig (void)
{
    NVIC_InitPara NVIC_InitStructure;

    /* 1 bit for pre-emption priority, 3 bits for subpriority */
    NVIC_PRIGroup_Enable(NVIC_PRIGROUP_1);

    /* Enable the USB low priority interrupt */
    NVIC_InitStructure.NVIC_IRQ = USB_LP_CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQPreemptPriority = 1;
    NVIC_InitStructure.NVIC_IRQSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQEnable = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

#ifdef USB_DEVICE_LOW_PWR_MODE_SUPPORT

    /* Enable the USB Wake-up interrupt */
    NVIC_InitStructure.NVIC_IRQ = USBWakeUp_IRQn;
    NVIC_InitStructure.NVIC_IRQPreemptPriority = 0;
    NVIC_InitStructure.NVIC_IRQSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQEnable = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

#endif
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
