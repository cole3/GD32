/**
  ******************************************************************************
  * @file    usb_int.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB device interrupt routines
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usb_int.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Driver
  * @{
  */

/** @defgroup USB_Interrupt_Private_Variables
  * @{
  */
extern uint32_t InterruptMask;
extern USB_CORE_HANDLE USB_Device_dev;
extern USB_INTHandler_TypeDef *USB_INT_fops;

/**
  * @}
  */

/** @defgroup USB_Interrupt_Private_functions
  * @{
  */

/**
  * @brief  USB interrupt events service routine
  * @param  None
  * @retval None
  */
void  USB_Ifr (void)
{
    __IO uint16_t Ifr = 0; 
    //__IO uint16_t Ctlr = 0;

    Ifr = _GetIFR();

    if (Ifr & IFR_STIF & InterruptMask)
    {
        /* The endpoint successful transfer interrupt service */
        USB_INT_fops->LP_ST(&USB_Device_dev);
    }

    if (Ifr & IFR_RSTIF & InterruptMask)
    {
        /* Clear reset interrupt flag in IFR */
        _SetIFR((uint16_t)CLR_RSTIF);

        /* USB reset interrupt handle */
        USB_INT_fops->Reset(&USB_Device_dev);
    }

    if (Ifr & IFR_PMOUIF & InterruptMask)
    {
        /* Clear packet memory overrun/underrun interrupt flag in IFR */
        _SetIFR((uint16_t)CLR_PMOUIF);

        /* USB packet memory overrun/underrun interrrupt handle */
        USB_INT_fops->PMOU(&USB_Device_dev);
    }

    if (Ifr & IFR_ERRIF & InterruptMask)
    {
        /* Clear error interrupt flag in IFR */
        _SetIFR((uint16_t)CLR_ERRIF);

        /* USB error interrupt handle */
        USB_INT_fops->Error(&USB_Device_dev);
    }

    if (Ifr & IFR_WKUPIF & InterruptMask)
    {
        /* Clear wakeup interrupt flag in IFR */
        _SetIFR((uint16_t)CLR_WKUPIF);

        /* USB wakeup interrupt handle */
        USB_INT_fops->WakeUp(&USB_Device_dev);
    }

    if (Ifr & IFR_SPSIF & InterruptMask)
    {
        /* Process library core layer suspend routine*/
        USB_INT_fops->Suspend(&USB_Device_dev);

        /* Clear of suspend interrupt flag bit must be done after setting of CTLR_SETSPS */
        _SetIFR((uint16_t)CLR_SPSIF);
    }

    if (Ifr & IFR_SOFIF & InterruptMask)
    {
        /* clear SOF interrupt flag in IFR */
        _SetIFR((uint16_t)CLR_SOFIF);

        /* USB SOF interrupt handle */
        USB_INT_fops->SOF(&USB_Device_dev);
    }

    if (Ifr & IFR_ESOFIF & InterruptMask)
    {
        /* clear ESOF interrupt flag in IFR */
        _SetIFR((uint16_t)CLR_ESOFIF);

        /* USB ESOF interrupt handle */
        USB_INT_fops->ESOF(&USB_Device_dev);
    }
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
