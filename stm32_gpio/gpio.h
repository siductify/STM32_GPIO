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

