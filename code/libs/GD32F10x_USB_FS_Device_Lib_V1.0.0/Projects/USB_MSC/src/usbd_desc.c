/**
  ******************************************************************************
  * @file    usbd_desc.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   USB descriptors and strings formating method
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usbd_desc.h"

/* Private define ------------------------------------------------------------*/
#define USBD_VID                     0x28e9
#define USBD_PID                     0x0299

#define USBD_LANGID_STRING           0x409
#define USBD_MFC_STRING              "GD32Microelectronics"
#define USBD_PRODUCT_STRING          "Mass Storage in FS Mode"
#define USBD_CONFIGURATION_STRING    "MSC Config"
#define USBD_INTERFACE_STRING        "MSC Interface"

/* Private variables ---------------------------------------------------------*/
char USBD_SERIALNUMBER_FS_STRING[26];

USBD_Desc_cb_TypeDef USER_desc =
{
    USBD_USER_DevDesc,
    USBD_USER_LANGIDStrDesc,
    USBD_USER_MFCStrDesc,
    USBD_USER_ProdStrDesc,
    USBD_USER_SerialStrDesc,
    USBD_USER_ConfigStrDesc,
    USBD_USER_ItfStrDesc,
};

/* USB standard device descriptor */
const uint8_t USBD_DeviceDesc[USB_DEVICE_DESC_SIZE] =
{
    0x12,                       /* bLength: device descriptor length */
    USB_DESCTYPE_DEVICE,        /* bDescriptorType: device descriptor type */
    0x00,                       /* bcdUSB: USB2.0 */
    0x02,
    0x00,                       /* bDeviceClass: no set */
    0x00,                       /* bDeviceSubClass: no set */
    0x00,                       /* bDeviceProtocol: no set */
    USB_EP0_MAX_SIZE,           /* bMaxPacketSize0: endpoint 0 max packet size */
    LOWBYTE(USBD_VID),          /* idVendor low byte */
    HIGHBYTE(USBD_VID),         /* idVendor high byte */
    LOWBYTE(USBD_PID),          /* idProduct low byte */
    HIGHBYTE(USBD_PID),         /* idProduct high byte */
    0x00,                       /* bcdDevice: GD32 USB device(rel. 1.0) */
    0x01,
    USBD_MFC_STR_IDX,           /* iManufacturer: index of manufacturer string */
    USBD_PRODUCT_STR_IDX,       /* iProduct: index of product string */
    USBD_SERIAL_STR_IDX,        /* iSerialNumber: index of serial number string */
    USBD_CFG_MAX_NUM            /* bNumConfigurations: only one configuration */
};

/* USB language ID Descriptor */
const uint8_t USBD_LANGIDDesc[USB_LANGID_STRING_SIZE] =
{
    USB_LANGID_STRING_SIZE,
    USB_DESCTYPE_STRING,
    LOWBYTE(USBD_LANGID_STRING),
    HIGHBYTE(USBD_LANGID_STRING),
};

/* USB serial string */
uint8_t USBD_SerialString[USB_SERIAL_STRING_SIZE] =
{
    USB_SERIAL_STRING_SIZE,       /* bLength */
    USB_DESCTYPE_STRING,          /* bDescriptorType */
};

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Get the device descriptor
  * @param  USBSpeed: usb device speed
  * @param  len: data length pointer
  * @retval Descriptor buffer pointer
  */
uint8_t *  USBD_USER_DevDesc (uint8_t USBSpeed, uint16_t *len)
{
    *len = sizeof(USBD_DeviceDesc);

    return (uint8_t*)USBD_DeviceDesc;
}

/**
  * @brief  Get the language ID string descriptor
  * @param  USBSpeed: usb device speed
  * @param  len: data length pointer
  * @retval Descriptor buffer pointer
  */
uint8_t *  USBD_USER_LANGIDStrDesc (uint8_t USBSpeed, uint16_t *len)
{
    *len = sizeof(USBD_LANGIDDesc);

    return (uint8_t*)USBD_LANGIDDesc;
}

/**
  * @brief  Get the product string descriptor
  * @param  USBSpeed: usb device speed
  * @param  len: data length pointer
  * @retval Descriptor buffer pointer
  */
uint8_t *  USBD_USER_ProdStrDesc (uint8_t USBSpeed, uint16_t *len)
{
    USBD_GetUnicodeString((uint8_t*)USBD_PRODUCT_STRING, USBD_StrDesc, len);

    return USBD_StrDesc;
}

/**
  * @brief  Get the manufacturer string descriptor
  * @param  USBSpeed: usb device speed
  * @param  len: data length pointer
  * @retval Descriptor buffer pointer
  */
uint8_t *  USBD_USER_MFCStrDesc (uint8_t USBSpeed, uint16_t *len)
{
    USBD_GetUnicodeString((uint8_t*)USBD_MFC_STRING, USBD_StrDesc, len);

    return USBD_StrDesc;
}

/**
  * @brief  Get the serial number string descriptor
  * @param  USBSpeed: usb device speed
  * @param  len: data length pointer
  * @retval Descriptor buffer pointer
  */
uint8_t *  USBD_USER_SerialStrDesc (uint8_t USBSpeed, uint16_t *len)
{
    *len = USB_SERIAL_STRING_SIZE;

    return USBD_SerialString;
}

/**
  * @brief  Get the configuration string descriptor
  * @param  USBSpeed: usb device speed
  * @param  len: data length pointer
  * @retval Descriptor buffer pointer
  */
uint8_t *  USBD_USER_ConfigStrDesc (uint8_t USBSpeed, uint16_t *len)
{
    USBD_GetUnicodeString((uint8_t*)USBD_CONFIGURATION_STRING, USBD_StrDesc, len);

    return USBD_StrDesc;  
}

/**
  * @brief  Get the interface string descriptor
  * @param  USBSpeed: usb device speed
  * @param  len: data length pointer
  * @retval Descriptor buffer pointer
  */
uint8_t *  USBD_USER_ItfStrDesc (uint8_t USBSpeed, uint16_t *len)
{
    USBD_GetUnicodeString((uint8_t*)USBD_INTERFACE_STRING, USBD_StrDesc, len);

    return USBD_StrDesc;
}

/**
  * @brief  Create the serial number string descriptor 
  * @param  None
  * @retval None
  */
void  Get_SerialString (void)
{
    uint32_t DeviceSerial = *(uint32_t*)DEVICE_ID;

    if(DeviceSerial != 0)
    {
        USBD_SerialString[2] = (uint8_t)DeviceSerial;
        USBD_SerialString[3] = (uint8_t)(DeviceSerial >> 8);
        USBD_SerialString[4] = (uint8_t)(DeviceSerial >> 16);
        USBD_SerialString[5] = (uint8_t)(DeviceSerial >> 24);
    }
}

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
