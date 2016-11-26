#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"


//#define RCC_APB2Periph(port) RCC_APB2Periph_##port

#define LED_PORT    GPIOC
#define LED_PIN     GPIO_Pin_12

static void delay(void)
{
    unsigned int n = 10000000;
    while (n--);
}

int main()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = LED_PIN; // GPIO No. 12
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; // slow rise time
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // push-pull output
    GPIO_Init(LED_PORT, &GPIO_InitStructure); // GPIOC init

    while(1)
    {
        //GPIOC->BSRR = GPIO_BSRR_BS12; // GPIO PC12 set, pin=high, LED STAT off
        GPIO_WriteBit(LED_PORT, LED_PIN, Bit_SET); // GPIO PC12 set, pin=high, LED STAT off
        delay(); // delay --> not much compiler optimizer settings dependent
        //GPIOC->BSRR = GPIO_BSRR_BR12; // GPIO PC12 reset, pin=low, LED STAT on
        GPIO_WriteBit(LED_PORT, LED_PIN, Bit_RESET); // GPIO PC12 reset, pin=low, LED STAT on
        delay(); // delay --> not much compiler optimizer settings dependent
    }
}



