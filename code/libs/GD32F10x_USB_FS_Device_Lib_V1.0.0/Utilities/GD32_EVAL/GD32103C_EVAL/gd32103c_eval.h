/**
  ******************************************************************************
  * @file    gd32103c_eval.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   GD32103C_EVAL's Leds, Keys and COM ports hardware resources defines.
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_GD32F103C_EVAL_H
#define __GD32F10X_GD32F103C_EVAL_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gd32f10x.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup GD32_EVAL
  * @{
  */

/** @addtogroup GD32103C_EVAL
  * @{
  */
      
/** @addtogroup GD32103C_EVAL_LOW_LEVEL
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
typedef enum 
{
    LED1 = 0,
    LED2 = 1,
    LED3 = 2,
    LED4 = 3
} 
Led_TypeDef;

typedef enum 
{
    KEY_TAMPER = 0,
    KEY_RIGHT = 1,
    KEY_LEFT = 2,
    KEY_DOWN = 3
}
Key_TypeDef;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
}
KeyMode_TypeDef;

typedef enum 
{
    MOUSE_NONE = 0,
    MOUSE_DOWN = 1,
    MOUSE_LEFT = 2,
    MOUSE_RIGHT = 3
}
MOUSEState_TypeDef;

typedef enum 
{
  COM1 = 0,
  COM2 = 1
}
COM_TypeDef;

/* Exported constants --------------------------------------------------------*/
/** @defgroup GD32103C_EVAL_LOW_LEVEL_Exported_Constants
  * @{
  */ 

/** 
  * @brief  Define for GD32103C_EVAL board
  */

/** @addtogroup GD32103C_EVAL_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             4

#define LED1_PIN                         GPIO_PIN_0
#define LED1_GPIO_PORT                   GPIOC
#define LED1_GPIO_CLK                    RCC_APB2PERIPH_GPIOC
  
#define LED2_PIN                         GPIO_PIN_2
#define LED2_GPIO_PORT                   GPIOC
#define LED2_GPIO_CLK                    RCC_APB2PERIPH_GPIOC
  
#define LED3_PIN                         GPIO_PIN_0
#define LED3_GPIO_PORT                   GPIOE
#define LED3_GPIO_CLK                    RCC_APB2PERIPH_GPIOE
  
#define LED4_PIN                         GPIO_PIN_1
#define LED4_GPIO_PORT                   GPIOE
#define LED4_GPIO_CLK                    RCC_APB2PERIPH_GPIOE

/**
  * @}
  */ 

/** @addtogroup GD32103C_EVAL_LOW_LEVEL_BUTTON
  * @{
  */  
#define KEYn                             4

/**
 * @brief Tamper push-button
 */
#define TAMPER_KEY_PIN                   GPIO_PIN_13
#define TAMPER_KEY_GPIO_PORT             GPIOC
#define TAMPER_KEY_GPIO_CLK              RCC_APB2PERIPH_GPIOC
#define TAMPER_KEY_EXTI_LINE             EXTI_LINE13
#define TAMPER_KEY_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOC
#define TAMPER_KEY_EXTI_PIN_SOURCE       GPIO_PINSOURCE13
#define TAMPER_KEY_EXTI_IRQn             EXTI15_10_IRQn

/**
 * @brief Right push-button
 */
#define RIGHT_KEY_PIN                    GPIO_PIN_13
#define RIGHT_KEY_GPIO_PORT              GPIOC
#define RIGHT_KEY_GPIO_CLK               RCC_APB2PERIPH_GPIOC
#define RIGHT_KEY_EXTI_LINE              EXTI_LINE13
#define RIGHT_KEY_EXTI_PORT_SOURCE       GPIO_PORT_SOURCE_GPIOC
#define RIGHT_KEY_EXTI_PIN_SOURCE        GPIO_PINSOURCE13
#define RIGHT_KEY_EXTI_IRQn              EXTI15_10_IRQn

/**
 * @brief Left push-button
 */
#define LEFT_KEY_PIN                     GPIO_PIN_0
#define LEFT_KEY_GPIO_PORT               GPIOA
#define LEFT_KEY_GPIO_CLK                RCC_APB2PERIPH_GPIOA
#define LEFT_KEY_EXTI_LINE               EXTI_LINE0
#define LEFT_KEY_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOA
#define LEFT_KEY_EXTI_PIN_SOURCE         GPIO_PINSOURCE0
#define LEFT_KEY_EXTI_IRQn               EXTI0_IRQn

/**
 * @brief Down push-button
 */  
#define DOWN_KEY_PIN                     GPIO_PIN_14
#define DOWN_KEY_GPIO_PORT               GPIOB
#define DOWN_KEY_GPIO_CLK                RCC_APB2PERIPH_GPIOB
#define DOWN_KEY_EXTI_LINE               EXTI_LINE14
#define DOWN_KEY_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOB
#define DOWN_KEY_EXTI_PIN_SOURCE         GPIO_PINSOURCE14
#define DOWN_KEY_EXTI_IRQn               EXTI15_10_IRQn

/**
  * @}
  */ 


/** @addtogroup GD32103C_EVAL_LOW_LEVEL_COM
  * @{
  */

#define COMn                             2

/**
 * @brief Definition for COM port1, connected to USART1
 */ 
#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCC_APB2PERIPH_USART1

#define EVAL_COM1_TX_PIN                 GPIO_PIN_9
#define EVAL_COM1_TX_GPIO_PORT           GPIOA
#define EVAL_COM1_TX_GPIO_CLK            RCC_APB2PERIPH_GPIOA

#define EVAL_COM1_RX_PIN                 GPIO_PIN_10
#define EVAL_COM1_RX_GPIO_PORT           GPIOA
#define EVAL_COM1_RX_GPIO_CLK            RCC_APB2PERIPH_GPIOA
   
#define EVAL_COM1_IRQn                   USART1_IRQn

/**
 * @brief Definition for COM port2, connected to USART2 (USART2 pins remapped on GPIOA)
 */ 
#define EVAL_COM2                        USART2
#define EVAL_COM2_CLK                    RCC_APB1PERIPH_USART2

#define EVAL_COM2_TX_PIN                 GPIO_PIN_2
#define EVAL_COM2_TX_GPIO_PORT           GPIOA
#define EVAL_COM2_TX_GPIO_CLK            RCC_APB2PERIPH_GPIOA

#define EVAL_COM2_RX_PIN                 GPIO_PIN_3
#define EVAL_COM2_RX_GPIO_PORT           GPIOA
#define EVAL_COM2_RX_GPIO_CLK            RCC_APB2PERIPH_GPIOA

#define EVAL_COM2_IRQn                   USART2_IRQn

/**
  * @}
  */

/** @addtogroup GD32103C_EVAL_LOW_LEVEL_SD_FLASH
  * @{
  */

/**
  * @brief  SD FLASH SDIO Interface
  */ 

#define SD_DETECT_PIN                    GPIO_PIN_11                 /* PF.11 */
#define SD_DETECT_GPIO_PORT              GPIOF                       /* GPIOF */
#define SD_DETECT_GPIO_CLK               RCC_APB2PERIPH_GPIOF

#define SDIO_FIFO_ADDRESS                ((uint32_t)0x40018080)

/** 
  * @brief  SDIO Intialization Frequency (400KHz max)
  */
#define SDIO_INIT_CLK_DIV                ((uint8_t)0xB2)

/** 
  * @brief  SDIO Data Transfer Frequency (25MHz max) 
  */
#define SDIO_TRANSFER_CLK_DIV            ((uint8_t)0x01)

#define SD_SDIO_DMA                      DMA2
#define SD_SDIO_DMA_CLK                  RCC_AHBPERIPH_DMA2
#define SD_SDIO_DMA_CHANNEL              DMA2_CHANNEL4
#define SD_SDIO_DMA_FLAG_TC              DMA2_FLAG_TC4
#define SD_SDIO_DMA_FLAG_TE              DMA2_FLAG_TE4
#define SD_SDIO_DMA_FLAG_HT              DMA2_FLAG_HT4
#define SD_SDIO_DMA_FLAG_GL              DMA2_FLAG_GL4
#define SD_SDIO_DMA_IRQn                 DMA2_Channel4_5_IRQn
#define SD_SDIO_DMA_IRQHANDLER           DMA2_Channel4_5_IRQHandler

/**
  * @}
  */

/**
  * @brief  M25P FLASH SPI Interface pins
  */  
#define sFLASH_SPI                       SPI1
#define sFLASH_SPI_CLK                   RCC_APB2PERIPH_SPI1

#define sFLASH_SPI_SCK_PIN               GPIO_PIN_5                  /* PA.05 */
#define sFLASH_SPI_SCK_GPIO_PORT         GPIOA                       /* GPIOA */
#define sFLASH_SPI_SCK_GPIO_CLK          RCC_APB2PERIPH_GPIOA

#define sFLASH_SPI_MISO_PIN              GPIO_PIN_6                  /* PA.06 */
#define sFLASH_SPI_MISO_GPIO_PORT        GPIOA                       /* GPIOA */
#define sFLASH_SPI_MISO_GPIO_CLK         RCC_APB2PERIPH_GPIOA

#define sFLASH_SPI_MOSI_PIN              GPIO_PIN_7                  /* PA.07 */
#define sFLASH_SPI_MOSI_GPIO_PORT        GPIOA                       /* GPIOA */
#define sFLASH_SPI_MOSI_GPIO_CLK         RCC_APB2PERIPH_GPIOA

#define sFLASH_CS_PIN                    GPIO_PIN_3                  /* PA.04 */
#define sFLASH_CS_GPIO_PORT              GPIOE                       /* GPIOE */
#define sFLASH_CS_GPIO_CLK               RCC_APB2PERIPH_GPIOE

/**
  * @}
  */

extern USART_TypeDef* COM_USART[COMn]; 

/** @defgroup GD32103C_EVAL_LOW_LEVEL_Exported_Functions
  * @{
  */
void GD_EVAL_LEDInit          (Led_TypeDef LedNum);
void GD_EVAL_LEDOn            (Led_TypeDef LedNum);
void GD_EVAL_LEDOff           (Led_TypeDef LedNum);
void GD_EVAL_LEDToggle        (Led_TypeDef LedNum);
void GD_EVAL_KeyInit          (Key_TypeDef KeyNum, KeyMode_TypeDef Key_Mode);
uint8_t GD_EVAL_KeyGetState   (Key_TypeDef KeyNum);
void GD_EVAL_COMInit          (COM_TypeDef ComNum, USART_InitPara* USART_InitStruct);
void SD_LowLevel_DeInit       (void);
void SD_LowLevel_Init         (void); 
void SD_LowLevel_DMA_TxConfig (uint32_t *BufferSRC, uint32_t BufferSize);
void SD_LowLevel_DMA_RxConfig (uint32_t *BufferDST, uint32_t BufferSize);
void sFLASH_LowLevel_DeInit   (void);
void sFLASH_LowLevel_Init     (void);

/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __GD32F10X_GD32F103C_EVAL_H */
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
