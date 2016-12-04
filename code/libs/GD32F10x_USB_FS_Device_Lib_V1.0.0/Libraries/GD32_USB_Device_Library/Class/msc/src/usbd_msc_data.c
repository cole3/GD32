/**
  ******************************************************************************
  * @file    usbd_msc_data.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   This file provides all the vital inquiry pages and sense data.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usbd_msc_data.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Class_Library
  * @{
  */

/** @addtogroup USB_MSC_Class
  * @{
  */

/** @defgroup USB_MSC_Data_Private_Variables
  * @{
  */

/* USB Mass storage Page 0 Inquiry Data */
const uint8_t  MSC_Page00_Inquiry_Data[] = 
{
    0x00,
    0x00,
    0x00,
    (INQUIRY_PAGE00_LENGTH - 4),
    0x00,
    0x80,
    0x83
};

/* USB Mass storage sense 6  Data */
const uint8_t  MSC_Mode_Sense6_data[] = 
{
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00
};

/* USB Mass storage sense 10  Data */
const uint8_t  MSC_Mode_Sense10_data[] = 
{
    0x00,
    0x06,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00
};

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

/**
  * @}
  */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
