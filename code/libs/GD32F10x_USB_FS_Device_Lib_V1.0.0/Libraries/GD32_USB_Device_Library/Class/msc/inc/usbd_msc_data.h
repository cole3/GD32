/**
  ******************************************************************************
  * @file    usbd_msc_data.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Header file for the usbd_msc_data.c file
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USBD_MSC_DATA_H
#define __GD32F10X_USBD_MSC_DATA_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_conf.h"

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

/** @defgroup USB_MSC_Data_Exported_Defines
  * @{
  */
#define MODE_SENSE6_LENGTH                 8
#define MODE_SENSE10_LENGTH                8
#define INQUIRY_PAGE00_LENGTH              7
#define FORMAT_CAPACITIES_LENGTH           20

/**
  * @}
  */

/** @defgroup USB_MSC_Data_Exported_Variables
  * @{
  */
extern const uint8_t MSC_Page00_Inquiry_Data[];
extern const uint8_t MSC_Mode_Sense6_data[];
extern const uint8_t MSC_Mode_Sense10_data[];

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

#endif /* __GD32F10X_USBD_MSC_DATA_H */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
