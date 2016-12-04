/**
  ******************************************************************************
  * @file    usbd_custom_hid_core.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Custom HID device class core functions
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "usbd_keyboard_core.h"

/** @addtogroup GD32F10x_Firmware
  * @{
  */

/** @addtogroup USB
  * @{
  */

/** @addtogroup USB_Device_Class_Library
  * @{
  */

/** @addtogroup USB_HID_Class
  * @{
  */
static uint8_t  USBD_CUSTOMHID_Init               (void *pudev, uint8_t ConfigIndex);
static uint8_t  USBD_CUSTOMHID_DeInit             (void *pudev, uint8_t ConfigIndex);
static uint8_t  USBD_CUSTOMHID_GetClassDescriptor (void *pudev, USB_DEVICE_REQ *req);
static uint8_t  USBD_CUSTOMHID_ClassReqHandle     (void *pudev, USB_DEVICE_REQ *req);
static uint8_t  USBD_CUSTOMHID_GetInterface       (void *pudev, USB_DEVICE_REQ *req);
static uint8_t  USBD_CUSTOMHID_SetInterface       (void *pudev, USB_DEVICE_REQ *req);
static uint8_t  USBD_CUSTOMHID_EP0_RxReady        (void *pudev);
static uint8_t  USBD_CUSTOMHID_DataIn             (void *pudev, uint8_t EpID);
static uint8_t  USBD_CUSTOMHID_DataOut            (void *pudev, uint8_t EpID);
static uint8_t* USBD_CUSTOMHID_GetCfgDesc         (uint8_t USBSpeed, uint16_t *len);

/** @defgroup USB_CustomHID_Private_Variables
  * @{
  */
uint8_t Report_buf[8];
uint8_t USBD_CUSTOMHID_Report_ID = 0;
uint8_t flag = 0;

static uint32_t  USBD_CUSTOMHID_AltSet = 0;
static uint32_t  USBD_CUSTOMHID_Protocol = 0;
static uint32_t  USBD_CUSTOMHID_IdleState = 0;

USBD_Class_cb_TypeDef  USBD_CUSTOMHID_cb = 
{
    USBD_CUSTOMHID_Init,
    USBD_CUSTOMHID_DeInit,
    USBD_CUSTOMHID_GetClassDescriptor,
    USBD_CUSTOMHID_ClassReqHandle,
    USBD_CUSTOMHID_GetInterface,
    USBD_CUSTOMHID_SetInterface,
    NULL, /* EP0_TxSent */
    USBD_CUSTOMHID_EP0_RxReady,
    USBD_CUSTOMHID_DataIn,
    USBD_CUSTOMHID_DataOut,
    NULL, /* SOF */
    USBD_CUSTOMHID_GetCfgDesc,
};

/* USB HID device Configuration Descriptor */
const uint8_t USBD_CUSTOMHID_CfgDesc[CUSTOMHID_CONFIG_DESC_SIZE] =
{
    0x09,         /* bLength: Configuration Descriptor size */
    USB_DESCTYPE_CONFIGURATION, /* bDescriptorType: Configuration */
    CUSTOMHID_CONFIG_DESC_SIZE, /* wTotalLength: configuration descriptor set total length */
    0x00,
    0x01,         /* bNumInterfaces: 1 interface */
    0x01,         /* bConfigurationValue: configuration value */
    0x00,         /* iConfiguration: index of string descriptor describing the configuration */
    0xA0,         /* bmAttributes: device attributes (bus powered and not support remote wakeup) */
    0x32,         /* bMaxPower 100 mA: this current is used for detecting Vbus */

    /************** Custom HID interface descriptor ****************/
    0x09,         /* bLength: interface descriptor size */
    USB_DESCTYPE_INTERFACE,/* bDescriptorType: interface descriptor type */
    0x00,         /* bInterfaceNumber: number of interface */
    0x00,         /* bAlternateSetting: alternate setting */
    0x02,         /* bNumEndpoints: 2 endpoints */
    0x03,         /* bInterfaceClass: HID */
    0x01,         /* bInterfaceSubClass: 1 = BIOS boot, 0 = no boot */
    0x01,         /* nInterfaceProtocol: 0 = none, 1 = keyboard, 2 = mouse */
    0x00,         /* iInterface: index of string descriptor */

    /******************** HID descriptor ********************/
    0x09,         /* bLength: HID descriptor size */
    0x21,         /* bDescriptorType: HID */
    0x11,         /* bcdHID: HID class protocol(HID1.11) */
    0x01,
    0x21,         /* bCountryCode: device country code */
    0x01,         /* bNumDescriptors: number of HID class descriptors to follow */
    0x22,         /* bDescriptorType: followed class descriptor type(report descriptor) */
    CUSTOMHID_REPORT_DESC_SIZE, /* wDescriptorLength: total length of report descriptor */
    0x00,

    /******************** Custom HID endpoints descriptor ***********/
    0x07,                  /* bLength: Endpoint Descriptor size */
    USB_DESCTYPE_ENDPOINT, /* bDescriptorType: endpoint descriptor type */
    HID_IN_EP,             /* bEndpointAddress: endpoint address (IN) */
    0x03,                  /* bmAttributes: endpoint attribute(interrupt endpoint) */
    CUSTOMHID_IN_PACKET,   /* wMaxPacketSize: 2 bytes max */
    0x00,
    0x0A,                  /* bInterval: Polling Interval (32 ms) */

    0x07,                  /* bLength: endpoint descriptor size */
    USB_DESCTYPE_ENDPOINT, /* bDescriptorType: endpoint descriptor type */
    EP1_OUT,               /* bEndpointAddress: endpoint address (OUT) */
    0x03,                  /* bmAttributes: endpoint attribute(interrupt endpoint) */
    CUSTOMHID_OUT_PACKET,  /* wMaxPacketSize: 2 Bytes max */
    0x00,
    0x0A,                  /* bInterval: Polling Interval (32 ms) */
};

/* USB custom HID device report descriptor */
const uint8_t CustomHID_ReportDescriptor[CUSTOMHID_REPORT_DESC_SIZE] =
{
    0x05, 0x01,     /* USAGE_PAGE (Generic Desktop) */
    0x09, 0x06,     /* USAGE (keyboard)        */
    0xa1, 0x01,     /* COLLECTION (Application)     */
    0x05, 0x07,     /* USAGE_PAGE (Keyboard/Keypad) */

    0x19, 0xe0, //     USAGE_MINIMUM (Keyboard LeftControl) 
    0x29, 0xe7, //     USAGE_MAXIMUM (Keyboard Right GUI) 
    0x15, 0x00, //     LOGICAL_MINIMUM (0) 
    0x25, 0x01, //     LOGICAL_MAXIMUM (1) 

    0x95, 0x08, //     REPORT_COUNT (8) 
    0x75, 0x01, //     REPORT_SIZE (1) 
    0x81, 0x02, //     INPUT (Data,Var,Abs) 
    
    0x95, 0x01, //     REPORT_COUNT (1) 
    0x75, 0x08, //     REPORT_SIZE (8) 
    0x81, 0x03, //     INPUT (Cnst,Var,Abs) 

    0x95, 0x06, //   REPORT_COUNT (6) 
    0x75, 0x08, //   REPORT_SIZE (8) 
    0x25, 0xFF, //   LOGICAL_MAXIMUM (255) 
    0x19, 0x00, //   USAGE_MINIMUM (Reserved (no event indicated)) 
    0x29, 0x65, //   USAGE_MAXIMUM (Keyboard Application) 
    0x81, 0x00, //     INPUT (Data,Ary,Abs) 
    
    0x25, 0x01, //     LOGICAL_MAXIMUM (1) 
    0x95, 0x02, //   REPORT_COUNT (2) 
    0x75, 0x01, //   REPORT_SIZE (1) 
    0x05, 0x08, //   USAGE_PAGE (LEDs) 
    0x19, 0x01, //   USAGE_MINIMUM (Num Lock) 
    0x29, 0x02, //   USAGE_MAXIMUM (Caps Lock) 
    0x91, 0x02, //   OUTPUT (Data,Var,Abs) 

    0x95, 0x01, //   REPORT_COUNT (1) 
    0x75, 0x06, //   REPORT_SIZE (6) 
    0x91, 0x03, //   OUTPUT (Cnst,Var,Abs) 

    0xc0            /* END_COLLECTION            */
}; 

/**
  * @}
  */

/** @defgroup USB_CustomHID_Handle_Function
  * @{
  */

/**
  * @brief  Initialize the custom HID device
  * @param  pudev: pointer to usb device instance
  * @param  ConfigIndex: configuration index
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_Init (void *pudev, uint8_t ConfigIndex)
{
    USB_EP_BufConfig(pudev, EP1_IN, USB_SNG_BUFTYPE, HID_TX_ADDRESS);
    USB_EP_BufConfig(pudev, EP1_OUT, USB_SNG_BUFTYPE, HID_RX_ADDRESS);

    /* Initialize Tx endpoint */
    USB_EP_Init(pudev,
                EP1_IN,
                USB_EPTYPE_INT,
                CUSTOMHID_IN_PACKET);

    /* Initialize Rx endpoint */
    USB_EP_Init(pudev,
                EP1_OUT,
                USB_EPTYPE_INT,
                CUSTOMHID_OUT_PACKET);

    /* Prepare receive Data */
    USB_EP_Rx(pudev, EP1_OUT, Report_buf, 1);

    return USBD_OK;
}

/**
  * @brief  De-Initialize the custom HID device
  * @param  pudev: pointer to usb device instance
  * @param  ConfigIndex: configuration index
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_DeInit (void *pudev, uint8_t ConfigIndex)
{
    /* Deinitialize the custom HID endpoints */
    USB_EP_DeInit (pudev, EP1_IN);
    USB_EP_DeInit (pudev, EP1_OUT);

    return USBD_OK;
}

/**
  * @brief  Handle the custom HID class-specific request
  * @param  pudev: pointer to usb device instance
  * @param  req: device class request
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_ClassReqHandle (void *pudev, USB_DEVICE_REQ *req)
{
    uint8_t USBD_CUSTOMHID_Report_LENGTH = 0;

    switch (req->bRequest)
    {
        case GET_REPORT:
            /* No use for this driver */
            break;

        case GET_IDLE:
            USB_CtlTx (pudev, (uint8_t *)&USBD_CUSTOMHID_IdleState, 1);
            break;

        case GET_PROTOCOL:
            USB_CtlTx (pudev, (uint8_t *)&USBD_CUSTOMHID_Protocol, 1);
            break;

        case SET_REPORT:
            flag = 1;
            USBD_CUSTOMHID_Report_ID = (uint8_t)(req->wValue);
            USBD_CUSTOMHID_Report_LENGTH = (uint8_t)(req->wLength);
            USB_CtlRx (pudev, Report_buf, USBD_CUSTOMHID_Report_LENGTH);
            break;

        case SET_IDLE:
            USBD_CUSTOMHID_IdleState = (uint8_t)(req->wValue >> 8);
            break;

        case SET_PROTOCOL:
            USBD_CUSTOMHID_Protocol = (uint8_t)(req->wValue);
            break;

        default:
            USBD_EnumError (pudev, req);
            return USBD_FAIL; 
    }

    return USBD_OK;
}

/**
  * @brief  Get custom HID class special descriptor(Report descriptor)
  * @param  pudev: pointer to usb device instance
  * @param  req: device class request
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_GetClassDescriptor (void *pudev, USB_DEVICE_REQ *req)
{
    uint16_t len = 0;
    uint8_t  *pbuf = NULL;

    switch(req->wValue >> 8)
    {
        case CUSTOMHID_REPORT_DESCTYPE:
            len = MIN(CUSTOMHID_REPORT_DESC_SIZE, req->wLength);
            pbuf = (uint8_t *)CustomHID_ReportDescriptor;
            break;

        case CUSTOMHID_DESC_TYPE:
            len = MIN(USB_CUSTOMHID_DESC_SIZE, req->wLength);
            pbuf = (uint8_t *)USBD_CUSTOMHID_CfgDesc + 0x12;
            break;

        default:
            break;
    }

    USB_CtlTx (pudev, pbuf, len);

    return USBD_OK;
}

/**
  * @brief  Handle standard device request--Get Interface
  * @param  pudev: pointer to usb device instance
  * @param  req: standard device request
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_GetInterface (void *pudev, USB_DEVICE_REQ *req)
{
    USB_CtlTx (pudev, (uint8_t *)&USBD_CUSTOMHID_AltSet, 1);

    return USBD_OK;
}

/**
  * @brief  Handle standard device request--Set Interface
  * @param  pudev: pointer to usb device instance
  * @param  req: standard device request
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_SetInterface (void *pudev, USB_DEVICE_REQ *req)
{
    USBD_CUSTOMHID_AltSet = (uint8_t)(req->wValue);

    return USBD_OK;	
}

/**
  * @brief  Send custom HID Report
  * @param  pudev: pointer to usb device instance
  * @param  report: pointer to report
  * @param  Len: data length
  * @retval usb device operation status
  */
uint8_t USBD_CUSTOMHID_SendReport (USB_DEVICE_HANDLE *pudev,
                                            uint8_t *report,
                                            uint16_t Len)
{
    if (pudev->dev.device_cur_status == USB_STATUS_CONFIGURED)
    {
        USB_EP_Tx (pudev, EP1_IN, report, Len);
    }

    return USBD_OK;
}

/**
  * @brief  Get custom HID device configuration descriptor
  * @param  USBSpeed: current device speed
  * @param  len: pointer to data length
  * @retval Pointer to descriptor buffer
  */
uint8_t  *USBD_CUSTOMHID_GetCfgDesc (uint8_t USBSpeed, uint16_t *len)
{
    *len = sizeof (USBD_CUSTOMHID_CfgDesc);

    return (uint8_t*)USBD_CUSTOMHID_CfgDesc;
}

extern void print(char* fmt, ...);

static uint8_t  USBD_CUSTOMHID_EP0_RxReady (void *pudev)
{
    print("USBD_CUSTOMHID_EP0_RxReady val %x\n", Report_buf[0]);

    return USBD_OK;
}

/**
  * @brief  Handle custom HID device data IN stage
  * @param  pudev: pointer to usb device instance
  * @param  EpID: endpoint identifier which is in (0..7)
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_DataIn (void *pudev, uint8_t EpID)
{
    return USBD_OK;
}


/**
  * @brief  Handle custom HID device data OUT stage
  * @param  pudev: pointer to usb device instance
  * @param  EpID: endpoint identifier  which is in (0..7)
  * @retval usb device operation status
  */
uint8_t  USBD_CUSTOMHID_DataOut (void *pudev, uint8_t EpID)
{ 
    //if (EpID == 1) 
    {  
        print("USBD_CUSTOMHID_DataOut EpID %d val %x\n", EpID, Report_buf[0]);
    }

    USB_EP_Rx(pudev, EP1_IN, Report_buf, 1);

    return USBD_OK;
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

/**
  * @}
  */

/************************ (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/
