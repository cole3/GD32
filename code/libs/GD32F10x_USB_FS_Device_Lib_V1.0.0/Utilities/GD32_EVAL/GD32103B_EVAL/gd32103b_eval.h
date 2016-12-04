/**
  ******************************************************************************
  * @file    gd32103b_eval.h
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   GD32103B_EVAL's Leds, Keys and COM ports hardware resources defines.
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_GD32F103B_EVAL_H
#define __GD32F10X_GD32F103B_EVAL_H

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

/** @addtogroup GD32103B_EVAL
  * @{
  */
      
/** @addtogroup GD32103B_EVAL_LOW_LEVEL
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
/** @defgroup GD32103B_EVAL_LOW_LEVEL_Exported_Constants
  * @{
  */ 

/** 
  * @brief  Define for GD32103B_EVAL board
  */

/** @addtogroup GD32103B_EVAL_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             4

#define LED1_PIN                         GPIO_PIN_6
#define LED1_GPIO_PORT                   GPIOC
#define LED1_GPIO_CLK                    RCC_APB2PERIPH_GPIOC
  
#define LED2_PIN                         GPIO_PIN_7
#define LED2_GPIO_PORT                   GPIOC
#define LED2_GPIO_CLK                    RCC_APB2PERIPH_GPIOC
  
#define LED3_PIN                         GPIO_PIN_8
#define LED3_GPIO_PORT                   GPIOC
#define LED3_GPIO_CLK                    RCC_APB2PERIPH_GPIOC
  
#define LED4_PIN                         GPIO_PIN_9
#define LED4_GPIO_PORT                   GPIOC
#define LED4_GPIO_CLK                    RCC_APB2PERIPH_GPIOC

/**
  * @}
  */ 

/** @addtogroup GD32103B_EVAL_LOW_LEVEL_BUTTON
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
#define DOWN_KEY_PIN                     GPIO_PIN_9
#define DOWN_KEY_GPIO_PORT               GPIOB
#define DOWN_KEY_GPIO_CLK                RCC_APB2PERIPH_GPIOB
#define DOWN_KEY_EXTI_LINE               EXTI_LINE9
#define DOWN_KEY_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOB
#define DOWN_KEY_EXTI_PIN_SOURCE         GPIO_PINSOURCE9
#define DOWN_KEY_EXTI_IRQn               EXTI9_5_IRQn

/**
  * @}
  */ 


/** @addtogroup GD32103B_EVAL_LOW_LEVEL_COM
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
 * @brief Definition for COM port2, connected to USART2
 */ 
#define EVAL_COM2                        USART2
#define EVAL_COM2_CLK                    RCC_APB1PERIPH_USART2

#define EVAL_COM2_TX_PIN                 GPIO_PIN_5
#define EVAL_COM2_TX_GPIO_PORT           GPIOD
#define EVAL_COM2_TX_GPIO_CLK            RCC_APB2PERIPH_GPIOD

#define EVAL_COM2_RX_PIN                 GPIO_PIN_6
#define EVAL_COM2_RX_GPIO_PORT           GPIOD
#define EVAL_COM2_RX_GPIO_CLK            RCC_APB2PERIPH_GPIOD

#define EVAL_COM2_IRQn                   USART2_IRQn

/**
  * @}
  */

extern USART_TypeDef* COM_USART[COMn]; 

/** @defgroup GD32103B_EVAL_LOW_LEVEL_Exported_Functions
  * @{
  */
void GD_EVAL_LEDInit          (Led_TypeDef LedNum);
void GD_EVAL_LEDOn            (Led_TypeDef LedNum);
void GD_EVAL_LEDOff           (Led_TypeDef LedNum);
void GD_EVAL_LEDToggle        (Led_TypeDef LedNum);
void GD_EVAL_KeyInit          (Key_TypeDef KeyNum, KeyMode_TypeDef Key_Mode);
uint8_t GD_EVAL_KeyGetState   (Key_TypeDef KeyNum);
void GD_EVAL_COMInit          (COM_TypeDef ComNum, USART_InitPara* USART_InitStruct);

/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __GD32F10X_GD32F103B_EVAL_H */

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
