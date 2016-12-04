/**
  ******************************************************************************
  * @file    usbd_msc_scsi.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Header file for the usbd_msc_scsi.c file
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USBD_MSC_SCSI_H
#define __GD32F10X_USBD_MSC_SCSI_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_msc_data.h"
#include "usbd_msc_bot.h"

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

/** @defgroup USB_MSC_Scsi_Exported_Defines
  * @{
  */
#define SENSE_LIST_DEEPTH                           4

/* SCSI Commands */
#define SCSI_FORMAT_UNIT                            0x04
#define SCSI_INQUIRY                                0x12
#define SCSI_MODE_SELECT6                           0x15
#define SCSI_MODE_SELECT10                          0x55
#define SCSI_MODE_SENSE6                            0x1A
#define SCSI_MODE_SENSE10                           0x5A
#define SCSI_ALLOW_MEDIUM_REMOVAL                   0x1E
#define SCSI_READ6                                  0x08
#define SCSI_READ10                                 0x28
#define SCSI_READ12                                 0xA8
#define SCSI_READ16                                 0x88

#define SCSI_READ_CAPACITY10                        0x25
#define SCSI_READ_CAPACITY16                        0x9E

#define SCSI_REQUEST_SENSE                          0x03
#define SCSI_START_STOP_UNIT                        0x1B
#define SCSI_TEST_UNIT_READY                        0x00
#define SCSI_WRITE6                                 0x0A
#define SCSI_WRITE10                                0x2A
#define SCSI_WRITE12                                0xAA
#define SCSI_WRITE16                                0x8A

#define SCSI_VERIFY10                               0x2F
#define SCSI_VERIFY12                               0xAF
#define SCSI_VERIFY16                               0x8F

#define SCSI_SEND_DIAGNOSTIC                        0x1D
#define SCSI_READ_FORMAT_CAPACITIES                 0x23

#define NO_SENSE                                    0
#define RECOVERED_ERROR                             1
#define NOT_READY                                   2
#define MEDIUM_ERROR                                3
#define HARDWARE_ERROR                              4
#define ILLEGAL_REQUEST                             5
#define UNIT_ATTENTION                              6
#define DATA_PROTECT                                7
#define BLANK_CHECK                                 8
#define VENDOR_SPECIFIC                             9
#define COPY_ABORTED                                10
#define ABORTED_COMMAND                             11
#define VOLUME_OVERFLOW                             13
#define MISCOMPARE                                  14


#define INVALID_CDB                                 0x20
#define INVALID_FIELED_IN_COMMAND                   0x24
#define PARAMETER_LIST_LENGTH_ERROR                 0x1A
#define INVALID_FIELD_IN_PARAMETER_LIST             0x26
#define ADDRESS_OUT_OF_RANGE                        0x21
#define MEDIUM_NOT_PRESENT                          0x3A
#define MEDIUM_HAVE_CHANGED                         0x28
#define WRITE_PROTECTED                             0x27 
#define UNRECOVERED_READ_ERROR                      0x11
#define WRITE_FAULT                                 0x03

#define READ_FORMAT_CAPACITY_DATA_LEN               0x0C
#define READ_CAPACITY10_DATA_LEN                    0x08
#define MODE_SENSE10_DATA_LEN                       0x08
#define MODE_SENSE6_DATA_LEN                        0x04
#define REQUEST_SENSE_DATA_LEN                      0x12
#define STANDARD_INQUIRY_DATA_LEN                   0x24
#define BLKVFY                                      0x04

/**
  * @}
  */

/** @defgroup USB_MSC_Scsi_Exported_Types
  * @{
  */
typedef struct _SENSE_ITEM
{
    uint8_t  SenseKey;
    uint32_t Information;
    uint8_t  ASC;
    uint8_t  ASCQ;
} SCSI_Sense_TypeDef;

/**
  * @}
  */

/** @defgroup USB_MSC_Scsi_Exported_Variables
  * @{
  */
extern uint8_t Page00_Inquiry_Data[];
extern uint8_t Standard_Inquiry_Data[];
extern uint8_t Standard_Inquiry_Data2[];
extern uint8_t Mode_Sense6_data[];
extern uint8_t Mode_Sense10_data[];
extern uint8_t Scsi_Sense_Data[];
extern uint8_t ReadCapacity10_Data[];
extern uint8_t ReadFormatCapacity_Data[];

extern SCSI_Sense_TypeDef   SCSI_Sense[SENSE_LIST_DEEPTH]; 
extern uint8_t   SCSI_Sense_Head;
extern uint8_t   SCSI_Sense_Tail;

/**
  * @}
  */

/** @defgroup USB_MSC_Scsi_Exported_Functions
  * @{
  */
int8_t  SCSI_ProcessCmd (USB_DEVICE_HANDLE *pudev,
                                      uint8_t Lun,
                                      uint8_t *cmd);

void    SCSI_SenseCode (uint8_t Lun,
                       uint8_t SKey,
                       uint8_t ASC);

int8_t  SCSI_ProcessRead  (uint8_t Lun);
int8_t  SCSI_ProcessWrite (uint8_t Lun);

/**
  * @}
  */

#endif /* __GD32F10X_USBD_MSC_SCSI_H */

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

