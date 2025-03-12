#include "show1.h"
#include "uart.h"
#include "DataChange.h"
#include "equipment.h"
#include "delay.h"
#include "stmflash.h"
#include "lora.h"

void Starinit(void)
{
	//LED
	RCC->APB2ENR|=1<<3;   //使能PORTB口时钟 
	GPIOB->CRH&=0XFFFFFF0F;//PB9推挽输出
	GPIOB->CRH|=0X00000030;
	//PB3-PB7
	RCC->APB2ENR|=1<<3;   //使能PORTB口时钟 
	GPIOB->CRL&=0X00000FFF;//输入
	GPIOB->CRL|=0X88888000;
	
	//ReadAllData();
	LED = 1;
	PB4Current = PB4;
	PB5Current = PB5;
	PB6Current = PB6;
	PB7Current = PB7;
	ReadAllData();
}



void WorkJudge(void)
{
	//PB3New = PB3;
	send_uart1_string("N001*");
}
void PortJudge(void)
{
	PB4New = PB4;
	PB5New = PB5;
	PB6New = PB6;
	PB7New = PB7;
	if(PB4New==0 && PB4Current==1)
	{
		PB4Count++;
		
		//记录PB4Count
		WritePB4();
		send_uart1_string("N002:");
		send_uart1_string(DataChangeNumberToString(PB4Count));
		send_uart1_string("*");
	}
	if(PB5New ==0 && PB5Current == 1)
	{
		PB5Count++;
		
		//记录PB5Count
		WritePB5();
		send_uart1_string("N003:");
		send_uart1_string(DataChangeNumberToString(PB5Count));
		send_uart1_string("*");
		
	}
	if(PB6New ==0 && PB6Current == 1)
	{
		PB6Count++;
		
		//记录PB6Count
		WritePB6();
		send_uart1_string("N004:");
		send_uart1_string(DataChangeNumberToString(PB6Count));
		send_uart1_string("*");
		
	}
	if(PB7New ==0 && PB7Current == 1)
	{
		PB7Count++;
		
		//记录PB7Count
		WritePB7();
		send_uart1_string("N005:");
		send_uart1_string(DataChangeNumberToString(PB7Count));
		send_uart1_string("*");
	}
	PB4Current = PB4New;
	PB5Current = PB5New;
	PB6Current = PB6New;
	PB7Current = PB7New;
	
}


