/**
  ******************************************************************************
  * @file    usbd_desc.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Internal flash functions
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"
#include "flash_msd.h"

/* Private variables ---------------------------------------------------------*/

/* Pages 0 and 1 base and end addresses */
uint32_t bak[HP_WCOUNT];

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initialize the nand flash
  * @param  None
  * @retval Status
  */
uint32_t  Flash_Init ()
{
    FMC_Unlock();

    return 0;
}

/**
  * @brief  Read data from multiple blocks of nand flash
  * @param  pBuf: pointer to user buffer
  * @param  ReadAddr: address to be read
  * @param  BlkSize: size of block
  * @param  BlkNum: number of block
  * @retval Status
  */
uint32_t  Flash_ReadMultiBlocks (uint8_t *pBuf,
                             uint32_t ReadAddr,
                             uint16_t BlkSize,
                             uint32_t BlkNum)
{
    uint32_t i;
    uint8_t *pSource = (uint8_t *)(ReadAddr + NAND_FLASH_BASE_ADDRESS);

    /* Data transfer */
    while (BlkNum--)
    {
        for (i = 0; i < BlkSize; i++)
        {
            *pBuf++ = *pSource++;
        }
    }

    return 0;
}

/**
  * @brief  Write data to multiple blocks of flash
  * @param  pBuf: pointer to user buffer
  * @param  WriteAddr: address to be write
  * @param  BlkSize: block size
  * @param  BlkNum: number of block
  * @retval Status
  */
uint32_t Flash_WriteMultiBlocks(uint8_t *pBuf,
                           uint32_t WriteAddr,
                           uint16_t BlkSize,
                           uint32_t BlkNum)
{
    uint32_t i, page;
    uint32_t start_page = (WriteAddr / PAGE_SIZE) * PAGE_SIZE + NAND_FLASH_BASE_ADDRESS;
    uint32_t *ptr_start = (uint32_t *)start_page, *ptrs = (uint32_t *)pBuf;

    if((WriteAddr + NAND_FLASH_BASE_ADDRESS) > start_page)
    {
        for(i = 0; i < HP_WCOUNT; i++)
        {
            bak[i] = *ptr_start++;
        }

        FMC_ErasePage(start_page);

        i = 0;

        do
        {
            FMC_ProgramWord(start_page, bak[i]);
            start_page += 4;
        }while(++i < HP_WCOUNT);

        i = 0;

        do
        {
            FMC_ProgramWord(start_page, *ptrs++);
            start_page += 4;
        }while(++i < HP_WCOUNT);

        BlkNum--;
    }

    page = BlkNum >> 1;

    for(; page > 0; page--)
    {
        FMC_ErasePage(start_page);

        i = 0;

        do
        {
            FMC_ProgramWord(start_page, *ptrs++);
            start_page += 4;
        }while(++i < OP_WCOUNT);

    }

    if(BlkNum & 0x01)
    {
        for(i = 0; i < HP_WCOUNT; i++)
        {
            bak[i] = ptrs[HP_WCOUNT + i];
        }

        FMC_ErasePage(start_page);

        for(i = 0; i < HP_WCOUNT; i++)
        {
            FMC_ProgramWord(start_page, ptrs[i]);

            start_page += 4;
        }

        for(i = 0; i < HP_WCOUNT; i++)
        {
            FMC_ProgramWord(start_page, bak[i]);

            start_page += 4;
        }
    }

    return 0;
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
