/**
  ******************************************************************************
  * @file    Custom_HID/readme.txt
  * @author  MCU SD 
  * @version V1.0.0
  * @date    26-Dec-2014 
  * @brief   Description of the USB Custom HID device demo.
  ******************************************************************************
  */

  @brief
    This demo is based on the GD32103xx-EVAL board,it provides a description of 
  how to use the USB-FS-Device peripheral.

    The GD32 device is enumerated as an USB Custom HID device, that uses the 
  native PC Host HID driver.

  To test the demo, you need to:

      - Download the "Custom_HID Client" PC applet

      - Start the "Custom_HID Client" PC applet and connect GD32 USB to PC

      - The device should be detected and shown in the PC applet
   
      - Make sure that following report ID are configured: LED1 ID (0x11),
        LED2 ID(0x12), LED3 ID(0x13), LED4 ID(0x14), BUTTON1_ID(0x15) and
        BUTTON2_ID(0x16).

      - Select Leds in the applet to switch on/off on the EVAL board 

      - Press the Wakeup key and Tamper key on the EVAL board to switch on
        /off the button1/button2 status in the PC applet

/****************** (C) COPYRIGHT 2014 GIGADEVICE *********END OF FILE*********/