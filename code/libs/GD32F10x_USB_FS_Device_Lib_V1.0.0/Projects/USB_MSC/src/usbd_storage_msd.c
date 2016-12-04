/**
  ******************************************************************************
  * @file    usbd_storage_msd.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   This file provides the disk operations functions.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usbd_msc_mem.h"
#include "flash_msd.h"

/* Private define ------------------------------------------------------------*/
#define STORAGE_LUN_NUM                  1

/* USB Mass storage Standard Inquiry Data */
const int8_t STORAGE_InquiryData[] = 
{
    /* LUN 0 */
    0x00,
    0x80,
    0x00,
    0x01,
    (USBD_STD_INQUIRY_LENGTH - 5),
    0x00,
    0x00,
    0x00,
    'G', 'D', '3', '2', ' ', ' ', ' ', ' ', /* Manufacturer : 8 bytes */
    'I', 'n', 't', 'e', 'r', 'n', 'a', 'l', /* Product      : 16 Bytes */
    'F', 'l', 'a', 's', 'h', ' ', ' ', ' ',
    '1', '.', '0' ,'0',                     /* Version      : 4 Bytes */
}; 

/* Private function prototypes -----------------------------------------------*/
static int8_t  STORAGE_Init             (uint8_t Lun);
static int8_t  STORAGE_IsReady          (uint8_t Lun);
static int8_t  STORAGE_IsWriteProtected (uint8_t Lun);
static int8_t  STORAGE_GetMaxLun        (void);

static int8_t  STORAGE_GetCapacity      (uint8_t Lun,
                                 uint32_t *block_num,
                                 uint32_t *block_size);

static int8_t  STORAGE_Read             (uint8_t Lun,
                                        uint8_t *buf,
                                        uint32_t BlkAddr,
                                        uint16_t BlkLen);

static int8_t  STORAGE_Write            (uint8_t Lun,
                                        uint8_t *buf,
                                        uint32_t BlkAddr,
                                        uint16_t BlkLen);

USBD_STORAGE_cb_TypeDef USBD_Internal_Flash_fops =
{
    STORAGE_Init,
    STORAGE_GetCapacity,
    STORAGE_IsReady,
    STORAGE_IsWriteProtected,
    STORAGE_Read,
    STORAGE_Write,
    STORAGE_GetMaxLun,
    (int8_t *)STORAGE_InquiryData,
};

USBD_STORAGE_cb_TypeDef *USBD_STORAGE_fops = &USBD_Internal_Flash_fops;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initialize the storage medium
  * @param  Lun: logical unit number
  * @retval Status
  */
static int8_t  STORAGE_Init (uint8_t Lun)
{
    if(Flash_Init() != 0)
    {
        return -1;
    }

    return 0;
}

/**
  * @brief  Get block number and block size
  * @param  Lun: logical unit number
  * @param  block_num: pointer to number of physical block
  * @param  block_size: pointer to size of a physical block
  * @retval Status
  */
static int8_t  STORAGE_GetCapacity (uint8_t Lun, uint32_t *block_num, uint32_t *block_size)
{
    *block_num = BLOCK_NUM;

    *block_size = BLOCK_SIZE;

    return 0;
}

/**
  * @brief  Check whether the medium is ready
  * @param  Lun: Logical unit number
  * @retval Status
  */
static int8_t  STORAGE_IsReady (uint8_t Lun)
{
    return 0;
}

/**
  * @brief  Check whether the medium is write-protected
  * @param  Lun: logical unit number
  * @retval Status
  */
static int8_t  STORAGE_IsWriteProtected (uint8_t Lun)
{
    return 0;
}

/**
  * @brief  Read data from the medium
  * @param  Lun: logical unit number
  * @param  buf: pointer to the buffer to save data
  * @param  BlkAddr: address of 1st block to be read
  * @param  BlkLen: number of blocks to be read
  * @retval Status
  */
static int8_t  STORAGE_Read (uint8_t Lun,
                            uint8_t *buf,
                            uint32_t BlkAddr,
                            uint16_t BlkLen)
{
    if(Flash_ReadMultiBlocks(buf,
                             BlkAddr,
                             BLOCK_SIZE,
                             BlkLen) != 0)
    {
        return 5;
    }

    return 0;
}
/**
  * @brief  Write data to the medium
  * @param  Lun: logical unit number
  * @param  buf: pointer to the buffer to write
  * @param  BlkAddr: address of blocks to be written
  * @param  BlkLen: number of blocks to be read
  * @retval Status
  */
static int8_t  STORAGE_Write (uint8_t Lun,
                             uint8_t *buf,
                             uint32_t BlkAddr,
                             uint16_t BlkLen)
{
    if(Flash_WriteMultiBlocks(buf,
                              BlkAddr,
                              BLOCK_SIZE,
                              BlkLen) != 0)
    {
        return 5;
    }

    return (0);
}

/**
  * @brief  Get number of supported logical unit
  * @param  None
  * @retval Number of logical unit
  */
static int8_t STORAGE_GetMaxLun (void)
{
    return (STORAGE_LUN_NUM - 1);
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
