#include "sys.h"
#include "uart.h"
#include "delay.h"
#include "stmflash.h" 
#include "time.h"
#include "equipment.h"
#include "show1.h"
#include "wdg.h"

int main(void)
{

	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72); //延时初始化
	TIM3_Int_Init(9999,7199);//1秒
	Time3En(1);
	uart1_init(72,9600);
	Starinit();
	IWDG_Init(4,625);				 //看门狗与分频数为 64,重载值为 625,溢出时间为 1s
	ReadAllData();
	while(1)
	{
		
		if(SendTime != 0)
		{
				SendTime = 0;
				WorkCount++;
				LED = ~LED;
				if(WorkCount == 5)
				{
					//WorkJudge();
					WorkCount = 0;
					send();
				}		
				
		}
		PortJudge();
		IWDG_Feed();						//喂狗
	}
	
}
