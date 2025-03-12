#include "delay.h"
#include "sys.h" 
#include "communication.h"
#include "uart.h"
#include "encapsulation.h"

#define Led    PAout(4)


int main(void)
{





	Stm32_Clock_Init(9);
	delay_init(72);
	//communication_init();

	Sys_Init();
	Work_LED = 1;
	
	
	while(1)
	{

		
			Receive();
			Send();
	}
	
}








