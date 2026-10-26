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

static inline void GPIO_Pinmode(GPIO_typedef *gpio,uint8_t pin, gpio_mode_t mode, gpio_type_t type){
    uint32 shift = (pin & 0x7u)<<2; //it calculates how many bits to shift a configuartion value so it lands in the correct 4 bit slot for the chosen pin
    volatile uint32_t *reg= (pin<8u)?&gpio->CRL : &gpio->CHL; //points reg to the correct register based on their pin number
    uint32_t config = ((uint32_t)mode | (uint32_t)type)<<shift; //combines integer from mode and type and uses <<shift to move those bits into the right positions in the register
    *reg = (*reg & ~(0xFU << shift)) | config;
}
static inline void GPIO_PullupEnable(GPIO_Typedef *gpio, uint8_t pin){
    gpio->ODR|=(1<<pin);
}
static inline void GPIO_PulldownEnable(GPIO_Typedef *gpio, uint8_t pin){
    gpio->ODR &= ~(1<<pin);
}
static inline void GPIO_WritePin(GPIO_TypeDef *gpio, uint8_t pin, gpio_value_t value){
    gpio->ODR = (gpio->ODR &~(1<<pin))|((uint32_t)(!value)<<(pin+16));
}
static inline void GPIO_WritePin_Atomic(GPIO_TypeDef *gpio, uint8_t pin, gpio_value_t value){
    gpio->BSRR = ((uint32_t)value << pin) | ((uint32_t)(!value) << (pin + 16));
}
static inline void GPIO_WriterPort(GPIO_TypeDef *gpio, uint16_t value){
    gpio->ODR = value;
}
static inline void GPIO_TogglePin(GPIO_TypeDef *gpio, uint8_t value){
    gpio->ODR ^= (1<<pin)
}
static inline void GPIO_TogglePin_Atomic(GPIO_TypeDef *gpio, uint8_t vlaue){
    uint32_t mask = (1<<pin);
    gpio->BSRR = (gpio-> & mask)?(mask<<16):mask;
}
static inline void GPIO_SetPin(GPIO_TypeDef *gpio, uint8_t pin){
    gpio->ODR |=(1<<pin)
}
static inline void GPIO_SetPin_Atomic(GPIO_TypeDef *gpio, uint8 pin){
    gpio->BSRR = (1<<pin);
}
static inline void GPIO_ClearPin(GPIO_TypeDef *gpio, uint8_t pin){
    gpio->ODR &=~(1<<pin);
}
static inline void GPIO_ClearPin_Atomic(GPIO_TypeDef *gpio, uint8_t value){
    gpio->BSRR = (1<<pin);
}
//loading...
