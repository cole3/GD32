/**
  ******************************************************************************
  * @file    gd32103b_eval.c
  * @author  MCU SD
  * @version V1.0.0
  * @date    26-Dec-2014
  * @brief   Firmware functions to manage Leds, Keys, COM ports
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "gd32103b_eval.h"


/** @addtogroup Utilities
  * @{
  */

/** @addtogroup GD32_EVAL
  * @{
  */

/** @addtogroup GD32103B_EVAL
  * @{
  */

/** @defgroup GD32103B_EVAL_LOW_LEVEL
  * @brief This file provides firmware functions to manage Leds, Keys, COM ports
  * @{
  */

/* Private variables ---------------------------------------------------------*/
GPIO_TypeDef* GPIO_PORT[LEDn] = {LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT, LED4_GPIO_PORT};
const uint16_t GPIO_PIN[LEDn] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
const uint32_t GPIO_CLK[LEDn] = {LED1_GPIO_CLK, LED2_GPIO_CLK, LED3_GPIO_CLK, LED4_GPIO_CLK};

GPIO_TypeDef* KEY_PORT[KEYn] = {TAMPER_KEY_GPIO_PORT, RIGHT_KEY_GPIO_PORT,
                                LEFT_KEY_GPIO_PORT, DOWN_KEY_GPIO_PORT};

const uint16_t KEY_PIN[KEYn] = {TAMPER_KEY_PIN, RIGHT_KEY_PIN,
                                LEFT_KEY_PIN, DOWN_KEY_PIN};

const uint32_t KEY_CLK[KEYn] = {TAMPER_KEY_GPIO_CLK, RIGHT_KEY_GPIO_CLK,
                                LEFT_KEY_GPIO_CLK, DOWN_KEY_GPIO_CLK};

const uint16_t KEY_EXTI_LINE[KEYn] = {TAMPER_KEY_EXTI_LINE,
                                      RIGHT_KEY_EXTI_LINE,
                                      LEFT_KEY_EXTI_LINE,
                                      DOWN_KEY_EXTI_LINE};

const uint16_t KEY_PORT_SOURCE[KEYn] = {TAMPER_KEY_EXTI_PORT_SOURCE,
                                        RIGHT_KEY_EXTI_PORT_SOURCE,
                                        LEFT_KEY_EXTI_PORT_SOURCE,
                                        DOWN_KEY_EXTI_PORT_SOURCE};

const uint16_t KEY_PIN_SOURCE[KEYn] = {TAMPER_KEY_EXTI_PIN_SOURCE,
                                       RIGHT_KEY_EXTI_PIN_SOURCE,
                                       LEFT_KEY_EXTI_PIN_SOURCE,
                                       DOWN_KEY_EXTI_PIN_SOURCE};

const uint16_t KEY_IRQn[KEYn] = {TAMPER_KEY_EXTI_IRQn, RIGHT_KEY_EXTI_IRQn,
                                 LEFT_KEY_EXTI_IRQn, DOWN_KEY_EXTI_IRQn};

USART_TypeDef* COM_USART[COMn] = {EVAL_COM1, EVAL_COM2};

GPIO_TypeDef* COM_TX_PORT[COMn] = {EVAL_COM1_TX_GPIO_PORT, EVAL_COM2_TX_GPIO_PORT};
 
GPIO_TypeDef* COM_RX_PORT[COMn] = {EVAL_COM1_RX_GPIO_PORT, EVAL_COM2_RX_GPIO_PORT};
 
const uint32_t COM_USART_CLK[COMn] = {EVAL_COM1_CLK, EVAL_COM2_CLK};

const uint32_t COM_TX_PORT_CLK[COMn] = {EVAL_COM1_TX_GPIO_CLK, EVAL_COM2_TX_GPIO_CLK};
 
const uint32_t COM_RX_PORT_CLK[COMn] = {EVAL_COM1_RX_GPIO_CLK, EVAL_COM2_RX_GPIO_CLK};

const uint16_t COM_TX_PIN[COMn] = {EVAL_COM1_TX_PIN, EVAL_COM2_TX_PIN};

const uint16_t COM_RX_PIN[COMn] = {EVAL_COM1_RX_PIN, EVAL_COM2_RX_PIN};

const uint16_t COM_IRQn[COMn] = {EVAL_COM1_IRQn, EVAL_COM2_IRQn};

/* Private functions ---------------------------------------------------------*/ 

/** @defgroup GD32103B_EVAL_LOW_LEVEL_Private_Functions
  * @{
  */

/**
  * @brief  Configures LED GPIO
  * @param  LedNum: Specifies the Led to be configured
  * @retval None
  */
void  GD_EVAL_LEDInit (Led_TypeDef LedNum)
{
    GPIO_InitPara  GPIO_InitStructure;

    /* Enable the LED Clock */
    RCC_APB2PeriphClock_Enable(GPIO_CLK[LedNum], ENABLE);

    /* Configure the LED pin */
    GPIO_InitStructure.GPIO_Pin = GPIO_PIN[LedNum];
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUT_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_Init(GPIO_PORT[LedNum], &GPIO_InitStructure);
    GPIO_PORT[LedNum]->BCR = GPIO_PIN[LedNum];
}

/**
  * @brief  Turn on selected LED 
  * @param  LedNum: Specifies the Led to be turn on
  * @retval None
  */
void GD_EVAL_LEDOn(Led_TypeDef LedNum)
{
    GPIO_PORT[LedNum]->BOR = GPIO_PIN[LedNum];
}

/**
  * @brief  Turn off selected LED
  * @param  Led: Specifies the Led to be turn off 
  * @retval None
  */
void GD_EVAL_LEDOff(Led_TypeDef LedNum)
{
    GPIO_PORT[LedNum]->BCR = GPIO_PIN[LedNum];
}

/**
  * @brief  Toggle the selected LED.
  * @param  Led: Specifies the Led to be toggled
  * @retval None
  */
void GD_EVAL_LEDToggle(Led_TypeDef LedNum)
{
    GPIO_PORT[LedNum]->DOR ^= GPIO_PIN[LedNum];
}

/**
  * @brief  Configure Key
  * @param  KeyNum: Specifies the key to be configured.
  *         This parameter can be one of following parameters:
  *            @arg KEY_TAMPER: Tamper key
  *            @arg KEY_RIGHT: Right key 
  *            @arg KEY_LEFT: Left key 
  *            @arg KEY_DOWN: Down key
  * @param  Button_Mode: Specifies Button mode.
  *         This parameter can be one of following parameters:   
  *            @arg KEY_MODE_GPIO: key will be used as simple IO 
  *            @arg KEY_MODE_EXTI: Key will be connected to EXTI line with interrupt
  *                                generation capability
  * @retval None
  */
void GD_EVAL_KeyInit(Key_TypeDef KeyNum, KeyMode_TypeDef Key_Mode)
{
    GPIO_InitPara GPIO_InitStructure;
    EXTI_InitPara EXTI_InitStructure;
    NVIC_InitPara NVIC_InitStructure;

    /* Enable the KEY Clock */
    RCC_APB2PeriphClock_Enable(KEY_CLK[KeyNum] | RCC_APB2PERIPH_AF, ENABLE);

    /* Configure Button pin as input */
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_IPD;
    GPIO_InitStructure.GPIO_Pin = KEY_PIN[KeyNum];
    GPIO_Init(KEY_PORT[KeyNum], &GPIO_InitStructure);

    if (Key_Mode == KEY_MODE_EXTI)
    {
        /* Connect Button EXTI Line to Button GPIO Pin */
        GPIO_EXTILineConfig(KEY_PORT_SOURCE[KeyNum], KEY_PIN_SOURCE[KeyNum]);

        /* Enable and set key EXTI Interrupt to the lowest priority */
        NVIC_InitStructure.NVIC_IRQ = KEY_IRQn[KeyNum];
        NVIC_InitStructure.NVIC_IRQPreemptPriority = 2;
        NVIC_InitStructure.NVIC_IRQSubPriority = 0;
        NVIC_InitStructure.NVIC_IRQEnable = ENABLE;
        NVIC_Init(&NVIC_InitStructure);

        /* Configure key EXTI line */
        EXTI_InitStructure.EXTI_LINE = KEY_EXTI_LINE[KeyNum];
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
        EXTI_InitStructure.EXTI_LINEEnable = ENABLE;
        EXTI_Init(&EXTI_InitStructure);

        EXTI_ClearIntBitState(KEY_EXTI_LINE[KeyNum]);
    }
}

/**
  * @brief  Returns the selected Button state.
  * @param  Button: Specifies the Button to be checked.
  *         This parameter can be one of following parameters:
  *            @arg KEY_TAMPER: Tamper key
  *            @arg KEY_RIGHT: Right key
  *            @arg KEY_LEFT: Left key
  *            @arg KEY_DOWN: Down key
  * @retval The Button GPIO pin value.
  */
uint8_t GD_EVAL_KeyGetState(Key_TypeDef Button)
{
    return GPIO_ReadInputBit(KEY_PORT[Button], KEY_PIN[Button]);
}

/**
  * @brief  Configures COM port
  * @param  ComNum: Specifies the COM port to be configured
  *         This parameter can be one of following parameters:
  *              @arg COM1
  * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure that
  *         contains the configuration information for the specified USART peripheral
  * @retval None
  */
void GD_EVAL_COMInit(COM_TypeDef ComNum, USART_InitPara *USART_InitStruct)
{
    GPIO_InitPara GPIO_InitStructure;
    NVIC_InitPara NVIC_InitStructure;

    /* Enable GPIO clock */
    RCC_APB2PeriphClock_Enable(COM_TX_PORT_CLK[ComNum] | COM_RX_PORT_CLK[ComNum] | RCC_APB2PERIPH_AF, ENABLE);

    /* Connect PXx to USARTx_Tx */
    if(ComNum == COM1)
    {
        /* Enable USART1 clock */
        RCC_APB2PeriphClock_Enable(EVAL_COM1_CLK, ENABLE); 
    }
    else if(ComNum == COM2)
    {
        /* Enable USART2 clock */
        RCC_APB1PeriphClock_Enable(EVAL_COM2_CLK, ENABLE);

#if defined(USE_GD32F103B_EVAL)
        GPIO_PinRemapConfig(GPIO_REMAP_USART2, ENABLE);
#endif
    }

    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = COM_TX_PIN[ComNum];
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;;
    GPIO_Init(COM_TX_PORT[ComNum], &GPIO_InitStructure);

    /* Configure USART Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = COM_RX_PIN[ComNum];
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_IN_FLOATING;
    GPIO_Init(COM_RX_PORT[ComNum], &GPIO_InitStructure);

    /* USART configuration */
    USART_Init(COM_USART[ComNum], USART_InitStruct);

    /* Enable USART */
    USART_Enable(COM_USART[ComNum], ENABLE);

    /* Enable the usart receive interrupt */
    USART_INT_Set(COM_USART[ComNum], USART_INT_RBNE, ENABLE);

    /* Configure usart receive interrupt */
    NVIC_InitStructure.NVIC_IRQ = COM_IRQn[ComNum];
    NVIC_InitStructure.NVIC_IRQPreemptPriority = 0;
    NVIC_InitStructure.NVIC_IRQSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQEnable = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
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

