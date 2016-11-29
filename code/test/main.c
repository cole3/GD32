#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "print.h"


#define RED_LED_PORT    GPIOC
#define RED_LED_PIN     GPIO_Pin_7
#define BLUE_LED_PORT   GPIOB
#define BLUE_LED_PIN    GPIO_Pin_4


static void delay(void)
{
    unsigned int n = 10000000;
    while (n--);
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

void led_trigger(void)
{
    static int flag = 0;

    if (flag) {
        GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_RESET);
    } else {
        GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_SET);
    }

    flag = !flag;
}

int main()
{
    char c = 'A';

    gpio_init();

    while(1) {
        if (c > 'Z') {
            c = 'A';
        }

        print("Send: %c\n", c++);

        //USART_SendData(USART1, c++);
        //while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
        GPIO_WriteBit(RED_LED_PORT, RED_LED_PIN, Bit_SET);
        //GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_RESET);
        delay();
        GPIO_WriteBit(RED_LED_PORT, RED_LED_PIN, Bit_RESET);
        //GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_SET);
        delay();
    }
}



