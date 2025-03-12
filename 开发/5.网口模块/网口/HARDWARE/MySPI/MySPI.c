#include "MySPI.h"
#include "delay.h"


void SPI_Init(void)
{
	RCC->APB2ENR|=1<<3;   //使能PORTB口时钟 
	GPIOB->CRL &=0x0000FFFF;
	GPIOB->CRL |=0x33330000;//PORTB4,5,6,7推挽输出
	GPIOB->ODR =GPIOB->ODR| (1<<4)|(1<<5)|(1<<6)|(1<<7);
//	GPIOB->ODR &=~(1<<4);
//	GPIOB->ODR &=~(1<<5);
//	GPIOB->ODR &=~(1<<6);
//	GPIOB->ODR &=~(1<<7);
}

//SPI发送数据
void SPI_SendByte(u8 data)
{
	u8 i;
	for(i=0; i<8; i++){
		if(data & 0x80){
				DACDATA = 1;
		}else{
				DACDATA = 0;
		}
		//切换SKL
		DACSCK = 1;
		delay_us(10);
		DACSCK = 0;
		data<<=1;
	}
	
}



//DAC

void Choose4(u8 cs)
{
	if(cs==0)
	{
		DAC1CS = 0;
	}
	else
	{
		DAC1CS = 1;
	}
}

void Choose5(u8 cs)
{
	if(cs==0)
	{
		DAC2CS = 0;
	}
	else
	{
		DAC2CS = 1;
	}
}

void SetDac4(u16 dac_value)
{
	if(dac_value>4095)
	{
		dac_value=dac_value-4095;
		dac_value=dac_value|(0x1<<12);
	}
	
	
	Choose4(0);
	delay_us(1);
	SPI_SendByte(dac_value>>8);
	SPI_SendByte(dac_value);
	delay_us(1);
	Choose4(1);	
}

void SetDac5(u16 dac_value)
{
	if(dac_value>4095)
	{
		dac_value=dac_value-4095;
		dac_value=dac_value|(0x1<<12);
	}
	Choose5(0);
	delay_us(1);
	SPI_SendByte(dac_value>>8);
	SPI_SendByte(dac_value);
	delay_us(1);
	Choose5(1);	
}



