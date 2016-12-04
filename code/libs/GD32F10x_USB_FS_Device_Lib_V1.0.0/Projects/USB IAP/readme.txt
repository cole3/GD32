/**
  ******************************************************************************
  * @file    USB IAP/readme.txt
  * @author  MCU SD 
  * @version V1.0
  * @date    6-Sep-2014 
  * @brief   Description of the USB Custom HID device for IAP demo.
  ******************************************************************************
  */

  @brief
    This demo is based on the GD32103xx-EVAL board,it provides a description of 
  how to use the USB-FS-Device peripheral.

    The GD32 device is enumerated as an USB Custom HID device for IAP, that uses the 
  native PC Host HID driver.

    To test the demo, you need a configuration hex image. The hex image should set
  application address at 0x8003200. You can refer to "../Utilities/Binary/DFU_Images"
  folder and use the hex images in it.

  To test the demo, you need to:

      - Download the "USB IAP Client" PC applet

      - Start the "USB IAP Client" PC applet and connect GD32 USB to PC (Note: maybe
	the driver installion is failed in the first time, try reseating again.)

      - The device should be detected and shown in the PC applet

      - Select the hex image and download it to the flash

      - After each device reset, the mcu will run the new application
   
      - After each device reset, hold down the TAMPER key on the GD32103xx-EVAL board 
	to enter IAP mode

/****************** (C) COPYRIGHT 2014 GIGADEVICE *********END OF FILE*********/