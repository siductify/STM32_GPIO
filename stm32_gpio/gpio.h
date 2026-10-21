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

//loading...
