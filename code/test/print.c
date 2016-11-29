#include <stdarg.h>
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"


static char usart1_enable;

static void usart1_init(void)
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

static void printch(char ch)
{
    USART_SendData(USART1, ch);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
}

static void printdec(int dec)
{
    if(dec==0) {
        return;
    }
    printdec(dec/10);
    printch( (char)(dec%10 + '0'));
}

static void printflt(double flt)
{
    int icnt = 0;
    int tmpint = 0;

    tmpint = (int)flt;
    printdec(tmpint);
    printch('.');
    flt = flt - tmpint;
    tmpint = (int)(flt * 1000000);
    printdec(tmpint);
}

static void printstr(char* str)
{
    while(*str) {
        printch(*str++);
    }
}

static void printbin(int bin)
{
    if(bin == 0) {
        printstr("0b");
        return;
    }
    printbin(bin/2);
    printch( (char)(bin%2 + '0'));
}

static void printhex(int hex)
{
    if(hex==0) {
        printstr("0x");
        return;
    }
    printhex(hex/16);
    if(hex < 10) {
        printch((char)(hex%16 + '0'));
    } else {
        printch((char)(hex%16 - 10 + 'a' ));
    }
}

void print(char* fmt, ...)
{
    double vargflt = 0;
    int  vargint = 0;
    char *vargpch;
    char vargch = 0;
    char *pfmt;
    va_list vp;

    if (!usart1_enable) {
        usart1_enable = 1; 
        usart1_init();
    }

    va_start(vp, fmt);
    pfmt = fmt;

    while(*pfmt) {
        if(*pfmt == '%') {
            switch(*(++pfmt)) {
            case 'c':
                vargch = va_arg(vp, int);
                printch(vargch);
                break;
            case 'd':
            case 'i':
                vargint = va_arg(vp, int);
                printdec(vargint);
                break;
            case 'f':
                vargflt = va_arg(vp, double);
                printflt(vargflt);
                break;
            case 's':
                vargpch = va_arg(vp, char*);
                printstr(vargpch);
                break;
            case 'b':
            case 'B':
                vargint = va_arg(vp, int);
                printbin(vargint);
                break;
            case 'x':
            case 'X':
                vargint = va_arg(vp, int);
                printhex(vargint);
                break;
            case '%':
                printch('%');
                break;
            default:
                break;
            }
            pfmt++;
        } else {
            if (*pfmt == '\n') {
                printch('\r');
            }
            printch(*pfmt++);
        }
    }
    va_end(vp);
}


