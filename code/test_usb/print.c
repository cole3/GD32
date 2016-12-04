#include <stdarg.h>
#include "gd32f10x.h"
#include "gd32f10x_rcc.h"
#include "gd32f10x_gpio.h"
#include "gd32f10x_usart.h"


static char usart1_enable;

static void usart1_init(void)
{
    GPIO_InitPara GPIO_InitStructure;
    USART_InitPara USART_InitStructure;

    RCC_APB2PeriphClock_Enable( RCC_APB2PERIPH_GPIOA , ENABLE );
    RCC_APB2PeriphClock_Enable( RCC_APB2PERIPH_USART1 , ENABLE );

    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_9 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_Init(GPIOA , &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_PIN_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE_IN_FLOATING;;
    GPIO_Init(GPIOA , &GPIO_InitStructure);

    USART_DeInit( USART1 );
    USART_InitStructure.USART_BRR = 115200;
    USART_InitStructure.USART_WL = USART_WL_8B;
    USART_InitStructure.USART_STBits = USART_STBITS_1;
    USART_InitStructure.USART_Parity = USART_PARITY_RESET;
    USART_InitStructure.USART_HardwareFlowControl = USART_HARDWAREFLOWCONTROL_NONE;
    USART_InitStructure.USART_RxorTx = USART_RXORTX_RX | USART_RXORTX_TX;
    USART_Init(USART1, &USART_InitStructure);
    USART_Enable(USART1, ENABLE);
}

static void printch(char ch)
{
    USART_DataSend(USART1, ch);
    while(USART_GetBitState(USART1, USART_FLAG_TC) == RESET);
}

static void printdec(int dec)
{
    if(dec==0) {
        return;
    }
    printdec(dec/10);
    printch((char)(dec%10 + '0'));
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
    if(hex%16 < 10) {
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


