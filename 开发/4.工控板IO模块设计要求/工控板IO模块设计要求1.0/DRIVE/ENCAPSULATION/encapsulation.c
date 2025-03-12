#include "encapsulation.h"


u8 ChangeLog1 = 0;
u8 ChangeLog2 = 0;
u8 first1 = 0;
u8 first2 = 0;

void Sys_Init(void)
{
	uart2_init(36,9600);
	
	//PA1			485使能
	//PA4     LED
	RCC->APB2ENR |= 1 << 2; //使能端口PORTA口时钟
  GPIOA->CRL &= 0xFFF0FF0F;
  GPIOA->CRL |= 0x00030030;
	//PA8输入脚		设备2机器状态			低电平有效
	//PA9输出脚		设备2，自动暂停信号	高电平有效
	//PA10输出脚		设备2，手动暂停信号	高电平有效
	RCC->APB2ENR |= 1 << 2; //使能端口PORTA口时钟
  GPIOA->CRH &= 0xFFFFF000;
  GPIOA->CRH |= 0x00000338;
	
	
	//PB4   接网口模块的重置信号
	//PB5		接网口模块的复位信号
//	RCC->APB2ENR |= 1 << 3; //使能端口PORTB口时钟
//  GPIOB->CRL &= 0xFF00FFFF;
//  GPIOB->CRL |= 0x00330000;
	

	//PB12、13、14红黄绿  
	//PB15输入脚，设备1：机器状态，手动		低电平有效
	//uart3_init(36,9600);
	RCC->APB2ENR |= 1 << 3; //使能端口PORTB口时钟
  GPIOB->CRH &= 0x0000FFFF;
  GPIOB->CRH |= 0x83330000;

	//PC6输入脚	设备1,机器状态：自动	低电平有效
	//PC7输出脚	设备1,自动暂停信号	高电平有效
	//PC8输出脚	设备1,手动暂停信号	高电平有效
	//PC9输入脚	设备2,机器状态：手动	低电平有效
	//U4-TX	接网口模块的RX信号	备用
	//U4-RX	接网口模块的TX信号	备用
	RCC->APB2ENR |= 1 << 4; //使能端口PORTC口时钟
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

