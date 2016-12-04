/**
  ******************************************************************************
  * @file    usbd_conf_template.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB device configuration template file
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_USBD_CONF_TEMPLATE_H
#define __GD32F10X_USBD_CONF_TEMPLATE_H

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Core_Library
  * @{
  */

/** @defgroup USBD_Configure_Exported_Defines
  * @{
  */

/*Common Defines*/
#define USBD_SELF_POWERED 
#define USBD_CFG_MAX_NUM                1 

/*Audio Class user defines*/
#define AUDIO_TOTAL_IF_NUM              0x02
#define USBD_ITF_MAX_NUM                1
#define USB_STR_DESC_MAX_SIZE           200 
#define AUDIO_OUT_EP                    EP1_OUT

/*CCID Class user defines*/
#define USBD_ITF_MAX_NUM                1
#define USB_MAX_STR_DESC_SIZ            64               
#define CCID_BULK_EP_MAX_PACKET         64
#define CCID_INTR_EP_MAX_PACKET         8
#define CCID_BULK_IN_EP                 EP1_IN
#define CCID_BULK_OUT_EP                EP1_OUT
#define CCID_INTR_IN_EP                 EP2_IN
#define USB_SUPPORT_USER_STRING_DESC

/*Composite HID + CDC Classes user defines*/
#define USBD_ITF_MAX_NUM           	    1
#define USB_STR_DESC_MAX_SIZE           64               
#define CUSTOMHID_REPORT_DESC_SIZE      163
#define CUSTOMHID_CONFIG_DESC_SIZE      41
#define HID_IN_EP                       EP1_IN
#define HID_OUT_EP                      EP1_OUT

/*2 Bytes max*/
#define HID_IN_PACKET                   2 
#define HID_OUT_PACKET                  2 
#define CDC_IN_EP                       EP1_IN  /*!< EP1 for data IN */
#define CDC_OUT_EP                      EP3_OUT /*!< EP3 for data OUT */
#define CDC_CMD_EP                      EP2_IN  /*!< EP2 for CDC commands */

/* CDC endpoints parameters: you can fine tune these values depending on the needed baudrate and performance. */
#define CDC_DATA_MAX_PACKET_SIZE       	64   /*!< Endpoint IN & OUT Packet size */
#define CDC_CMD_PACKET_SIZE             8    /*!< Control Endpoint Packet size */
#define CDC_IN_FRAME_INTERVAL          	5    /*!< Number of frames between IN transfers */
#define APP_RX_DATA_SIZE               	2048 /*!< Total size of IN buffer: APP_RX_DATA_SIZE*8/MAX_BAUDARATE*1000 
                                                  should be > CDC_IN_FRAME_INTERVAL */
#define APP_FOPS                        VCP_fops

/* Composite HID + MSC class user defines */
#define USBD_ITF_MAX_NUM           	    1
#define USB_MAX_STR_DESC_SIZE           64             
#define CUSTOMHID_REPORT_DESC_SIZE      163
#define CUSTOMHID_CONFIG_DESC_SIZE      41
#define HID_IN_EP                       EP1_IN
#define HID_OUT_EP                      EP1_OUT

/* HID class user defines */
#define HID_IN_PACKET                   4 
#define HID_OUT_PACKET                  4 
#define MSC_MAX_PACKET                  64
#define MSC_MEDIA_PACKET                512
#define MSC_IN_EP                       EP2_IN
#define MSC_OUT_EP                      EP2_OUT

/* Custom HID class user defines */
#define USBD_ITF_MAX_NUM                1
#define USB_STR_DESC_MAX_SIZE           64              
#define CUSTOMHID_REPORT_DESC_SIZE      163
#define CUSTOMHID_CONFIG_DESC_SIZE      41
#define HID_IN_PACKET                   2
#define HID_OUT_PACKET                  2
#define HID_IN_EP                       EP1_IN
#define HID_OUT_EP                      EP1_OUT

/*DFU class user defines*/
#define USBD_ITF_MAX_NUM                MAX_USED_MEDIA
#define USB_MAX_STR_DESC_SIZE           200 
#define XFERSIZE                        1024   /*!< Max DFU Packet Size   = 1024 bytes */
#define MAX_USED_MEDIA                  1      /*!< Maximum number of supported media (Flash) */
#define DFU_IN_EP                       EP0_IN
#define DFU_OUT_EP                      EP0_OUT
#define USB_SUPPORT_USER_STRING_DESC
 
/* Flash memory address from where user application will be loaded 
   This address represents the DFU code protected against write and erase operations.*/
#define APP_DEFAULT_ADD                 0x08003000
#define DFU_MAL_IS_PROTECTED_AREA(add)  (uint8_t)(((add >= 0x08000000) && (add < (APP_DEFAULT_ADD)))? 1:0)
#define TRANSFER_SIZE_BYTES(size)       ((uint8_t)(size)), \
                                        ((uint8_t)(size >> 8))

/*MSC Class user defines*/	
#define USBD_ITF_MAX_NUM           	    1
#define USB_STR_DESC_MAX_SIZE           64 
#define MSC_MAX_PACKET                  64
#define MSC_MEDIA_PACKET                512
#define MSC_IN_EP                       EP1_IN
#define MSC_OUT_EP                      EP2_OUT
                                            
/*VCP Class user defines*/	
#define USBD_ITF_MAX_NUM                1
#define USB_MAX_STR_DESC_SIZ            255 	
#define CDC_IN_EP                       EP1_IN   /*!< EP1 for data IN */
#define CDC_OUT_EP                      EP3_OUT  /*!< EP3 for data OUT */
#define CDC_CMD_EP                      EP2_IN   /*!< EP2 for CDC commands */

/* CDC Endpoints parameters: you can fine tune these values depending on the needed baudrate and performance. */
#define CDC_DATA_MAX_PACKET_SIZE        64   /*!< Endpoint IN & OUT Packet size */
#define CDC_CMD_PACKET_SZE              8    /*!< Control Endpoint Packet size */
#define CDC_IN_FRAME_INTERVAL           5    /*!< Number of frames between IN transfers */
#define APP_RX_DATA_SIZE                2048 /*!< Total size of IN buffer: 
                                                  APP_RX_DATA_SIZE*8/MAX_BAUDARATE*1000 should be > CDC_IN_FRAME_INTERVAL */
#define APP_FOPS                        VCP_fops					  

/**
  * @}
  */

#endif /* __GD32F10X_USBD_CONF_TEMPLATE_H */

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
