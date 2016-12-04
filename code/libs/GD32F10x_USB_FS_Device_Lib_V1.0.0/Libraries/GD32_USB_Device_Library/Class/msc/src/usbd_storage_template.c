/**
  ******************************************************************************
  * @file    usbd_storage_template.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Memory management layer
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "usbd_msc_mem.h"

/* Private define ------------------------------------------------------------*/
#define STORAGE_LUN_NBR                  1   

/* Private variables ---------------------------------------------------------*/
/* USB Mass storage Standard Inquiry Data */
const int8_t  STORAGE_Inquirydata[] = 
{ //36  
  	/* LUN 0 */
  	0x00,		
  	0x80,		
  	0x02,		
  	0x02,
  	(USBD_STD_INQUIRY_LENGTH - 5),
  	0x00,
 	 	0x00,	
 	 	0x00,
  	'G', 'D', '3', '2', ' ', ' ', ' ', ' ', /* Manufacturer : 8 bytes */
  	'P', 'r', 'o', 'd', 'u', 't', ' ', ' ', /* Product      : 16 Bytes */
  	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
  	'1', '.', '0' ,'0',                     /* Version      : 4 Bytes */
}; 

USBD_STORAGE_cb_TypeDef USBD_MICRO_SDIO_fops =
{
 	 	STORAGE_Init,
  	STORAGE_GetCapacity,
  	STORAGE_IsReady,
  	STORAGE_IsWriteProtected,
  	STORAGE_Read,
  	STORAGE_Write,
  	STORAGE_GetMaxLun,
  	STORAGE_Inquirydata,
};

USBD_STORAGE_cb_TypeDef  *USBD_STORAGE_fops = &USBD_MICRO_SDIO_fops;

/* Private function prototypes -----------------------------------------------*/
int8_t STORAGE_Init (uint8_t lun);

int8_t STORAGE_GetCapacity (uint8_t lun, 
                           uint32_t *block_num, 
                           uint16_t *block_size);

int8_t  STORAGE_IsReady (uint8_t lun);

int8_t  STORAGE_IsWriteProtected (uint8_t lun);

int8_t STORAGE_Read (uint8_t lun, 
                        uint8_t *buf, 
                        uint32_t blk_addr,
                        uint16_t blk_len);

int8_t STORAGE_Write (uint8_t lun, 
                        uint8_t *buf, 
                        uint32_t blk_addr,
                        uint16_t blk_len);

int8_t STORAGE_GetMaxLun (void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initialize the storage medium
  * @param  lun : logical unit number
  * @retval Status
  */
int8_t STORAGE_Init (uint8_t lun)
{
  	return (0);
}

/**
  * @brief  return medium capacity and block size
  * @param  lun : logical unit number
  * @param  block_num :  number of physical block
  * @param  block_size : size of a physical block
  * @retval Status
  */
int8_t STORAGE_GetCapacity (uint8_t lun, uint32_t *block_num, uint16_t *block_size)
{
  	return (0);
}

/**
  * @brief  check whether the medium is ready
  * @param  lun : logical unit number
  * @retval Status
  */
int8_t  STORAGE_IsReady (uint8_t lun)
{
  	return (0);
}

/**
  * @brief  check whether the medium is write-protected
  * @param  lun : logical unit number
  * @retval Status
  */
int8_t  STORAGE_IsWriteProtected (uint8_t lun)
{
  	return  0;
}

/**
  * @brief  Read data from the medium
  * @param  lun : logical unit number
  * @param  buf : Pointer to the buffer to save data
  * @param  blk_addr :  address of 1st block to be read
  * @param  blk_len : nmber of blocks to be read
  * @retval Status
  */
int8_t STORAGE_Read (uint8_t lun, 
                 uint8_t *buf, 
                 uint32_t blk_addr,                       
                 uint16_t blk_len)
{
  	return 0;
}

/**
  * @brief  Write data to the medium
  * @param  lun : logical unit number
  * @param  buf : Pointer to the buffer to write from
  * @param  blk_addr :  address of 1st block to be written
  * @param  blk_len : nmber of blocks to be read
  * @retval Status
  */
int8_t STORAGE_Write (uint8_t lun, 
                  uint8_t *buf, 
                  uint32_t blk_addr,
                  uint16_t blk_len)
{
  	return (0);
}

/**
  * @brief  Return number of supported logical unit
  * @param  None
  * @retval number of logical unit
  */
int8_t STORAGE_GetMaxLun (void)
{
  	return (STORAGE_LUN_NBR - 1);
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
