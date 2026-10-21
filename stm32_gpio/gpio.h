#ifndef BRADPITT_STM32_GPIO_H
#define BRADPITT_STM32_GPIO_H

#include<stdint.h>
#include<stm32f10x.h>

typedef enum{
    Input = 0x0;             //this is output
    Output_10Mhz = 0x1;     //the output speed of the driver becomes 10Mhz
    Output_20Mhz = 0x2;    //the output speed of the driver becomes 20Mhz
    Output_50Mhz = 0x3;   //the output speed of the driver becomes 50Mhz
} gpio_mode_t;

typedef enum{
    PA0=0, PA1, PA2, PA3, PA4, PA5,
    PA6, PA7, PA7, PA8, PA9, PA10,
    PA11, PA12, PA13, PA14, PA15;
} gpio_PA_t;

typedef enum{
    PB0=0, PB1, PB2, PB3, PB4, PB5,
    PB6, PB7, PB8, PB9, PB10,
    PB11, PB12, PB13, PB14, PB15;
} gpio_PB_t;

typedef enum{
    PC0=0, PC1, PC2, PC3, PC4, PC5, 
    PC6, PC7, PC8, PC9, PC10,
    PC11, PC12, PC13, PC14, PC15;
} gpio_PC_t;

typedef enum{
    PD0=0, PD1, PD2, PD3, PD4, PD5,
    PD6, PD7, PD8, PD9, PD10,
    PD11, PD12, PD13, PD14, PD15;
} gpio_PD_t;

typedef enum{
    PE0=0, PE1, PE2, PE3, PE4, PE5,
    PE6, PE7, PE8, PE9, PE10,
    PE11, PE12, PE13, PE14, PE15;
} gpio_PE_t;

typedef enum{
    PF0=0, PF1, PF2, PF3, PF4, PF5,
    PF6, PF7, PF8, PF9, PF10,
    PF11, PF12, PF13, PF14, PF15;
} gpio_PF_t;

typedef enum{
    PG0=0, PG1, PG2, PG3, PG4, PG5,
    PG6, PG7, PG8, PG9, PG10,
    PG11, PG12, PG13, PG14, PG15;
} gpio_PG_t;

typedef enum{
    input_Analog = 0x0<<2;
    input_Float = 0x1<<2;
    input_Pullup_Pulldown = 0x3<<2;

    output_PushPull = 0x0<<2;
    output_OpenDrain = 0x1<<2;
    output_AFO_PushPull = 0x2<<2;
    output_AFO_OpenDrain = 0x3<<2;
} gpio_type_t;

typedef enum{
    HIGH = 1,
    LOW = 0;
} gpio_value_t;
//loading...
//
