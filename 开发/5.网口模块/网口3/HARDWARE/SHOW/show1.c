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
	
}



void WorkJudge(void)
{
	//PB3New = PB3;
	//send_uart1_string("N001*");
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
		if(PB4Count == 4294967295)
		{
			PB4Count = 0;
		}
		//记录PB4Count
		WritePB4();
		number1 = count_digits(PB4Count);
		
		//send();

	}
	if(PB5New ==0 && PB5Current == 1)
	{
		PB5Count++;
		if(PB5Count == 4294967295)
		{
			PB5Count = 0;
		}
		number2 = count_digits(PB5Count);
		//send();
		//记录PB5Count
		WritePB5();
		
	}
	if(PB6New ==0 && PB6Current == 1)
	{
		PB6Count++;
		if(PB6Count == 4294967295)
		{
			PB6Count = 0;
		}
		number3 = count_digits(PB6Count);
		//send();
		//记录PB6Count
		WritePB6();

		
	}
	if(PB7New ==0 && PB7Current == 1)
	{
		PB7Count++;
		if(PB7Count == 4294967295)
		{
			PB7Count = 0;
		}
		number4 = count_digits(PB7Count);
		//send();
		//记录PB7Count
		WritePB7();

	}
	PB4Current = PB4New;
	PB5Current = PB5New;
	PB6Current = PB6New;
	PB7Current = PB7New;
	
}


void send(void)
{
	  send_uart1_string("\":\",100,");
		sendzero(number1);
		send_uart1_string(DataChangeNumberToString(PB4Count));
		send_uart1_string(",");
		sendzero(number2);
		send_uart1_string(DataChangeNumberToString(PB5Count));
		send_uart1_string(",");
		sendzero(number3);
		send_uart1_string(DataChangeNumberToString(PB6Count));
		send_uart1_string(",");
		sendzero(number4);
		send_uart1_string(DataChangeNumberToString(PB7Count));
		send_uart1_string(",2A<CR>");
	
}


//判断位数
u8 count_digits(u32 num) 
{
	u8 digit_count = 0;
    if (num == 0) {
				digit_count = 1;
        return 1; // 特殊处理0的情况，0有1位
    }
 
    
//    while (num > 0) {
//        num /= 10;
//        digit_count++;
//    } 
		if(num >= 1000000000)
		{
			digit_count = 10;
			return digit_count;
		}
		if(num >= 100000000)
		{
			digit_count = 9;
			return digit_count;
		}
		if(num >= 10000000)
		{
			digit_count = 8;
			return digit_count;
		}
		if(num >= 1000000)
		{
			digit_count = 7;
			return digit_count;
		}
		if(num >= 100000)
		{
			digit_count = 6;
			return digit_count;
		}
		if(num >= 10000)
		{
			digit_count = 5;
			return digit_count;
		}
		if(num >= 1000)
		{
			digit_count = 4;
			return digit_count;
		}
		if(num >= 100)
		{
			digit_count = 3;
			return digit_count;
		}
		if(num >= 10)
		{
			digit_count = 2;
			return digit_count;
		}
		else
		{
			digit_count = 1;
			return digit_count;
		}
 
    
}

void sendzero(u8 count)
{
	u8 i = 0;
	count = 10 - count;
	for(i = 0;i < count; i++)
	{
		send_uart1_string("0");
	}
	

}


