#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"


#define RED_LED_PORT    GPIOC
#define RED_LED_PIN     GPIO_Pin_7
#define BLUE_LED_PORT   GPIOB
#define BLUE_LED_PIN    GPIO_Pin_4



static void delay(void)
{
    unsigned int n = 10000000;
    while (n--);
}

void usart_init(void)
{
    USART_InitTypeDef USART_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Configure USART Rx as input floating */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART1, &USART_InitStruct);

    USART_Cmd(USART1, ENABLE);
}

void gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
    
    // PB4 & JTAG PIN same
    GPIO_InitStruct.GPIO_Pin = RED_LED_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(RED_LED_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = BLUE_LED_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(BLUE_LED_PORT, &GPIO_InitStruct);
}


int main()
{
    char c = 'A';

    gpio_init();
    usart_init();

    while(1) {
        if (c == 'Z') {
            c = 'A';
        }

        USART_SendData(USART1, c++);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
        GPIO_WriteBit(RED_LED_PORT, RED_LED_PIN, Bit_SET);
        GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_RESET);
        delay();
        GPIO_WriteBit(RED_LED_PORT, RED_LED_PIN, Bit_RESET);
        GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_SET);
        delay();
    }
}



