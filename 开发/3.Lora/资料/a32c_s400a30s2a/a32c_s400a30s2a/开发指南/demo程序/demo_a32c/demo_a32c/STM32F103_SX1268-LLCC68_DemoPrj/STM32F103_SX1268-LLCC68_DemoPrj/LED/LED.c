#include "LED.h"

void LEDGPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC ,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3 | GPIO_Pin_2 ;	//--LED0-PC3	LED1-PC2
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

    LED0 = 1;
    LED1 = 1;
}

void LED_Toogle( uint8_t cnt)
{
    uint8_t num = cnt*2;
    while( num-- )
    {
        GPIOC->ODR ^= GPIO_Pin_2;
        GPIOC->ODR ^= GPIO_Pin_3;
        delay_ms(400);
    }
}
