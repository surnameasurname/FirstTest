#include "lora.h"
#include "equipment.h"
#include "uart.h"
#include "DataChange.h"
#include "delay.h"
#include "MySPI.h"

u8 communication_array_data_u1[100];
u8 communication_index_u1=0;


void InitLora(void){
		uart1_init(72,9600);
		InitLoraGpio();
		LED = 1;
}



void InitLoraGpio(void){
		//MD0
		//MD1
		//AUX
		RCC->APB2ENR|=1<<2;   //ʹ��PORTA��ʱ�� 
		GPIOA->CRH&=0XFFF00FFF;//PA11�������
		GPIOA->CRH|=0X00033000;//PA12�������
		
		RCC->APB2ENR|=1<<3;   //ʹ��PORTB��ʱ�� 
		GPIOB->CRH&=0XFF0FFF0F;//PB9�������
		GPIOB->CRH|=0X00800030;//PB13����
		GPIOB->ODR |= 1<<13; //PB13 ����	
	
		
}









