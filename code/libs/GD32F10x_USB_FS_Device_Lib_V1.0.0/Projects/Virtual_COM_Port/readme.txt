/**
  ******************************************************************************
  * @file    Virtual_COM_Port/readme.txt
  * @author  MCU SD 
  * @version V1.0.0
  * @date    26-Dec-2014 
  * @brief   Description of the USB Virtual Com Port demo.
  ******************************************************************************
  */

  @brief
    This demo is based on the GD32103xx-EVAL board,it provides a description of 
  how to use the USB-FS-Device peripheral.

    It illustrates an implementation of the CDC class following the PSTN subprotocol.

    The VCP example allows the GD32 device to behave as a USB-to-RS232 bridge:

      - On one side, the GD32 communicates with host (PC) through USB interface in
        Device mode.

      - On the other side, the GD32 communicates with other devices(same host,other
        host,other devices) through the USART interface (RS232).

    The support of the VCP interface is managed through the GD Virtual Com Port driver
  available for download from www.gd32mcu.21ic.com.

    When the VCP application starts,the USB device is enumerated as serial communication
  port and can be configured in the same way(baudrate,data format,parity,stop bit length).

  To test the demo, you can use one of the following configurations:

      - Configuration 1: Connect USB cable to host and USART (RS232) to a different host
        (PC or other device) or to the same host. In this case, you can open two hyperterminal-like
        terminals to send/receive data from/to host to/from device.

      - Configuration 2: Connect USB cable to Host and connect USART TX pin to USART
        RX pin on the evaluation board (Loopback mode). In this case, you can open one
        terminal (relative to USB com port or USART com port) and all data sent from this
        terminal will be received by the same terminal in loopback mode. This mode is useful
        for test and performance measurements.

  @note 
    When transferring a big file (USB OUT transfer) user has to adapt the size
  of IN buffer, for more details refer to usbd_conf.h file (APP_RX_DATA_SIZE constant). 

/****************** (C) COPYRIGHT 2014 GIGADEVICE *********END OF FILE*********/