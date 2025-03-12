#ifndef __LED_H
#define __LED_H

#include "sys.h"
#include "delay.h"

#define LED0   PCout(3)
#define LED1   PCout(2)

#define LED0_TOOGLE     GPIOC->ODR ^= GPIO_Pin_3;       //∑¢ÀÕ
#define LED1_TOOGLE     GPIOC->ODR ^= GPIO_Pin_2;       //Ω” ’

void LEDGPIO_Init(void);
void LED_Toogle( uint8_t cnt);


#endif

