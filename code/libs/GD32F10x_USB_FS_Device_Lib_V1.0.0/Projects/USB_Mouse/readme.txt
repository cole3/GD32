/**
  ******************************************************************************
  * @file    USB_Mouse/readme.txt
  * @author  MCU SD 
  * @version V1.0.0
  * @date    26-Dec-2014 
  * @brief   Description of the USB Mouse demo.
  ******************************************************************************
  */

  @brief
    This demo is based on the GD32103xx-EVAL board,it provides a description of 
  how to use the USB-FS-Device peripheral.

    The GD32 device is enumerated as an USB Mouse, that uses the native PC Host
  HID driver.

    The USB Mouse use three key(wakeup key, tamper key and user key) to move in
  three directions(left, up and right).It has no left button, right button and
  roller.

    This demo supports remote wakeup (which is the ability of a USB device to 
  bring a suspended bus back to the active condition), and the tamper key is 
  used as the remote wakeup source.

    In order to test USB remote wakeup function, you can do as follows:

        - Manually switch PC to standby mode

        - Wait for PC to fully enter the standby mode

	- Push the tamper key

        - If PC is ON, remote wakeup is OK, else failed.
    

/****************** (C) COPYRIGHT 2014 GIGADEVICE *********END OF FILE*********/