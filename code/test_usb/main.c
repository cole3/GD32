#include "gd32f10x.h"
#include "gd32f10x_rcc.h"
#include "gd32f10x_gpio.h"
#include "gd32f10x_usart.h"
#include "print.h"


#define RED_LED_PORT    GPIOC
#define RED_LED_PIN     GPIO_PIN_7
#define BLUE_LED_PORT   GPIOB
#define BLUE_LED_PIN    GPIO_PIN_4



static void delay(void)
{
    unsigned int n = 10000000;
    while (n--);
}

void gpio_init(void)
{
    GPIO_InitPara GPIO_InitStructure;

    RCC_APB2PeriphClock_Enable(RCC_APB2PERIPH_GPIOB | RCC_APB2PERIPH_GPIOC, ENABLE);
    RCC_APB2PeriphClock_Enable(RCC_APB2PERIPH_AF, ENABLE);
    GPIO_PinRemapConfig(GPIO_REMAP_SWJ_JTAGDISABLE, ENABLE);

    // PB4 & JTAG PIN same
    GPIO_InitStructure.GPIO_Pin = RED_LED_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUT_PP;
    GPIO_Init(RED_LED_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BLUE_LED_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_OUT_PP;
    GPIO_Init(BLUE_LED_PORT, &GPIO_InitStructure);

    GPIO_SetBits(RED_LED_PORT, RED_LED_PIN);
    GPIO_SetBits(BLUE_LED_PORT, BLUE_LED_PIN);
}

void led_trigger(void)
{
    static int flag = 0;

    if (flag) {
        GPIO_ResetBits(BLUE_LED_PORT, BLUE_LED_PIN);
    } else {
        GPIO_SetBits(BLUE_LED_PORT, BLUE_LED_PIN);
    }

    flag = !flag;
}

extern void USB_Mouse_Init(void);
//extern void USB_MSC_Init(void);
//extern void Virtual_COM_Port_Init(void);

int main()
{
    char c = 'A';

    gpio_init();

    print("start\n");
    USB_Mouse_Init();
    //USB_MSC_Init();
    //Virtual_COM_Port_Init();
    GPIO_ResetBits(BLUE_LED_PORT, BLUE_LED_PIN);
    print("end\n");

    while(1) {
        if (c > 'Z') {
            c = 'A';
        }

        print("Send: %c\n", c++);

        //USART_SendData(USART1, c++);
        //while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
        //GPIO_WriteBit(RED_LED_PORT, RED_LED_PIN, Bit_SET);
        //GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_RESET);
        led_trigger();
        delay();
        //GPIO_WriteBit(RED_LED_PORT, RED_LED_PIN, Bit_RESET);
        //GPIO_WriteBit(BLUE_LED_PORT, BLUE_LED_PIN, Bit_SET);
        //delay();
    }
}


