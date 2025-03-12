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

	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72); //��ʱ��ʼ��
	TIM3_Int_Init(9999,7199);//1��
	Time3En(1);
	uart1_init(72,9600);
	Starinit();
	IWDG_Init(4,625);				 //���Ź����Ƶ��Ϊ 64,����ֵΪ 625,���ʱ��Ϊ 1s
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
		IWDG_Feed();						//ι��
	}
	
}
