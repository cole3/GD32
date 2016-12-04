/**
  ******************************************************************************
  * @file    DFU/readme.txt
  * @author  MCU SD 
  * @version V1.0.0
  * @date    26-Dec-2014 
  * @brief   Description of the USB DFU(Device Firmware Upgrade) demo.
  ******************************************************************************
  */

  @brief
    This demo is based on the GD3210x-EVAL board,it presents the implementation 
  of a device firmware upgrade (DFU) capability in the GD32 USB device.

    It follows the DFU class specification defined by the USB Implementers Forum for 
  reprogramming an application through USB-FS-Device.
 
    The DFU principle is particularly well suited to USB-FS-Device applications that 
  need to be reprogrammed in the field.

    To test the demo, you need a configuration hex image. The hex image should set
  application address at 0x8003200. You can refer to "../Utilities/Binary/DFU_Images"
  folder and use the hex images in it.

    You need install the corresponding GD DFU Driver with your PC operation system. 

    Once the configuration *.hex image is generated, it can be downloaded into 
  internal flash memory using the GD tool "GD MCU Dfu Tool" available for download 
  from www.gd32mcu.21ic.com.

    The supported memory for this example is the internal flash memory, you can also
 add a new memory interface if you have extral memory.

  @note
    After each device reset, hold down the TAMPER key on the GD32150R-EVAL board 
 

/****************** (C) COPYRIGHT 2014 GIGADEVICE *********END OF FILE*********/