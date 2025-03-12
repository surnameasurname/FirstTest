#include "encapsulation.h"


u8 ChangeLog1 = 0;
u8 ChangeLog2 = 0;
u8 first1 = 0;
u8 first2 = 0;

void Sys_Init(void)
{
	uart2_init(36,9600);
	
	//PA1			485ʹ��
	//PA4     LED
	RCC->APB2ENR |= 1 << 2; //ʹ�ܶ˿�PORTA��ʱ��
  GPIOA->CRL &= 0xFFF0FF0F;
  GPIOA->CRL |= 0x00030030;
	//PA8�����		�豸2����״̬			�͵�ƽ��Ч
	//PA9�����		�豸2���Զ���ͣ�ź�	�ߵ�ƽ��Ч
	//PA10�����		�豸2���ֶ���ͣ�ź�	�ߵ�ƽ��Ч
	RCC->APB2ENR |= 1 << 2; //ʹ�ܶ˿�PORTA��ʱ��
  GPIOA->CRH &= 0xFFFFF000;
  GPIOA->CRH |= 0x00000338;
	
	
	//PB4   ������ģ��������ź�
	//PB5		������ģ��ĸ�λ�ź�
//	RCC->APB2ENR |= 1 << 3; //ʹ�ܶ˿�PORTB��ʱ��
//  GPIOB->CRL &= 0xFF00FFFF;
//  GPIOB->CRL |= 0x00330000;
	

	//PB12��13��14�����  
	//PB15����ţ��豸1������״̬���ֶ�		�͵�ƽ��Ч
	//uart3_init(36,9600);
	RCC->APB2ENR |= 1 << 3; //ʹ�ܶ˿�PORTB��ʱ��
  GPIOB->CRH &= 0x0000FFFF;
  GPIOB->CRH |= 0x83330000;

	//PC6�����	�豸1,����״̬���Զ�	�͵�ƽ��Ч
	//PC7�����	�豸1,�Զ���ͣ�ź�	�ߵ�ƽ��Ч
	//PC8�����	�豸1,�ֶ���ͣ�ź�	�ߵ�ƽ��Ч
	//PC9�����	�豸2,����״̬���ֶ�	�͵�ƽ��Ч
	//U4-TX	������ģ���RX�ź�	����
	//U4-RX	������ģ���TX�ź�	����
	RCC->APB2ENR |= 1 << 4; //ʹ�ܶ˿�PORTC��ʱ��
  GPIOC->CRL &= 0x00FFFFFF;
  GPIOC->CRL |= 0x38000000;
		
	GPIOC->CRH &= 0xFFFFFF00;
  GPIOC->CRH |= 0x00000083;
	
//	uart4_init(36,9600);
	communication2_init();
	
	Device1_Status_ManualOperation = 1;
	Device1_Status_Auto = 1;
	
	
	Device2_Status_Auto = 1;
	Device2_Status_ManualOperation = 1;
	
	
	
	
	Work_LED = 1;
	Device2_ManualOperation_Pause = 0;
	Device2_Auto_Pause = 0;
	Device1_Auto_Pause = 0;
	Device1_ManualOperation_Pause = 0;
	
	
	LED_Red = 0;
	LED_Yellow = 0;
	LED_Green = 0;
	

}




void Receive(void)
{
		order_dispose_u2();
}
void Send(void)
{
	if(Device1_Status_ManualOperation == 0)
	{
		if(first1 == 0)
		{
			first1 = 1;
			ChangeLog1 = 1;
			send_uart2_string("ID:N020*");
		}
		if(ChangeLog1 != 1)
		{
			ChangeLog1 = 1;
			send_uart2_string("ID:N020*");
		}
	}
	if(Device1_Status_Auto == 0)
	{
		if(first1 == 0)
		{
			first1 = 1;
			ChangeLog1 = 2;
			send_uart2_string("ID:N021*");
		}
		if(ChangeLog1 != 2)
		{
			ChangeLog1 = 2;
			send_uart2_string("ID:N021*");
		}		
	}
	
	
	if(Device2_Status_ManualOperation == 0)
	{
		if(first2 == 0)
		{
			first2 = 1;
			ChangeLog2 = 1;
			send_uart2_string("ID:N040*");
		}
		if(ChangeLog2 != 1)
		{
			ChangeLog2 = 1;
			send_uart2_string("ID:N040*");
		}
	}
	if(Device2_Status_Auto == 0)
	{
		if(first2 == 0)
		{
			first2 = 1;
			ChangeLog2 = 2;
			send_uart2_string("ID:N041*");
		}
		if(ChangeLog2 != 2)
		{
			ChangeLog2 = 2;
			send_uart2_string("ID:N041*");
		}		
	}
	
	
}

