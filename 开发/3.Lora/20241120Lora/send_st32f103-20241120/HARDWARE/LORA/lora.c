//#include "lora.h"
//#include "equipment.h"
//#include "uart.h"
//#include "DataChange.h"
//#include "delay.h"
//#include "MySPI.h"

//u8 communication_array_data_u1[100];
//u8 communication_index_u1=0;


//void InitLora(void){
//	
//		uart1_init(72,9600);
//		
//		RCC->APB2ENR|=1<<2;  		//PORTB时钟使能 	  
//		GPIOA->CRL&=0XFFFFFFFF; 
//		GPIOA->CRL|=0X00030000;		//PB12推挽输出	
//		
//		InitLoraGpio();
//	
//		
//}



//void InitLoraGpio(void){
//		//PB9		LED
//		//PB10	NRST		OUT
//		//PB11	BUSY
//		//PB12	TXEN		OUT
//		//PB13	RXEN		OUT
//		RCC->APB2ENR|=1<<3;   //使能PORTB口时钟 
//		GPIOB->CRH&=0XFFF00000;
//		GPIOB->CRH|=0X00033333;
//		
//	
//		SPI1_Init();
//		
//}

////void SetLora(void){

////	delay_ms(120);
//////	if(Mode == 1){			//定点
////		
////		//配置
////		
////		send_uart1(0x80);
////		send_uart1(0x07);
////		send_uart1(0x01);
////		send_uart1(0x00);
////		send_uart1(0x02);

////		
////	}
////	if(Mode == 0)	//中继
////	{
////		send_uart1(0x80);
////		send_uart1(0x07);
////		send_uart1(0x01);
////		send_uart1(0x00);
////		send_uart1(0x21);
////	}
////	if(Mode == 2){	//透明传输
////		send_uart1(0x80);
////		send_uart1(0x07);
////		send_uart1(0x01);
////		send_uart1(0x00);
////		send_uart1(0x01);
////	
////	}
////	M0 = 1;
////	M1 = 0;
////	delay_ms(120);
//	
////}


////void SetLocGro(void)				//设置本地组号
////{
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x18);
////		send_uart1(0x01);
////		send_uart1(LocalGroupNumber);
////		
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////}
////void SetLocAdd(void)				//设置本地地址
////{
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x19);
////		send_uart1(0x01);
////		send_uart1(LocalAddress);
////		delay_ms(120);
////		M0 = 1;
////		M1 = 0;
////}
////void SetArmLocGro(void)			//设置目标组号
////{
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x1A);
////		send_uart1(0x01);
////		send_uart1(TargetGroupNumber);
////		delay_ms(120);
////		M0 = 1;
////		M1 = 0;
////}

////void SetArmLocAdd(void)			//设置目标地址
////{
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x1B);
////		send_uart1(0x01);
////		send_uart1(DestinationAddress);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////}

////void SetTempChannel(void)			//设置临时信道
////{
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x20);
////		send_uart1(0x01);
////		send_uart1(TempChannel);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////}

////void SetTempChannelTime(void)			//设置临时信道时间
////{
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x21);
////		send_uart1(0x01);
////		send_uart1(0x10);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////}


////void Lora_SetChannelAdd(u8 Chan){	//设置信道
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		Chan = Chan & 0x1F;
////		Channel = Chan;
////		//默认寄存器0x02FA值   bit10-bit5 10111（23）信道默认值
////		u8 Qian = 0x00;
////		u8 Hou = 0x1A;
////		Qian = Chan>>3 | Qian;
////		Chan = Chan<<5 & 0xE0;
////		Hou = Chan | Hou;
////		
////	
////		 
////		send_uart1(0x80);
////		send_uart1(0x06);
////		send_uart1(0x01);
////		send_uart1(Qian);
////		send_uart1(Hou);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////	
////}

////void Lora_SetPathGroupANumber(void)
////{
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x1C);
////		send_uart1(0x01);
////		send_uart1(PathGroupANumber);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);

////}
////void Lora_SetPathAAddress(void){
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x1D);
////		send_uart1(0x01);
////		send_uart1(PathAAddress);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////}

////void Lora_SetPathGroupBNumber(void){
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x1E);
////		send_uart1(0x01);
////		send_uart1(PathGroupBNumber);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////}

////void Lora_SetPathBAddress(void){
////		if(AUX == 0){
////			while(!AUX);
////		}
////		M1 = 0;
////		M0 = 0;
////		delay_ms(120);
////		send_uart1(0x80);
////		send_uart1(0x1F);
////		send_uart1(0x01);
////		send_uart1(PathBAddress);
////		M0 = 1;
////		M1 = 0;
////		delay_ms(120);
////		
////}

////void Lora_SendAdc(void)
////{
////		u8 QianA = ADC_1>>8;
////		u8 HouA = ADC_1;
////		u8 QianB = ADC_2>>8;
////		u8 HouB = ADC_2;
////		
////	if(Mode == 1){
////			if(ArmChannel == Channel){
////					send_uart1(0xFF);
////					send_uart1(0xFF);
////			}
////			if(ArmChannel != Channel){
////					send_uart1(TargetGroupNumber);
////					send_uart1(DestinationAddress);
////			}
////	}
////	if(Mode == 2){
////				send_uart1(TargetGroupNumber);
////				send_uart1(DestinationAddress);
////	
////	}
////	
////		send_uart1(ArmChannel);
////		send_uart1('A');
////		send_uart1(':');
//////		send_uart1_string(DataChangeNumberToString(ADC_1));
////		send_uart1(QianA);
////		send_uart1(HouA);
////		send_uart1(',');
////		send_uart1('B');
////		send_uart1(':');
//////		send_uart1_string(DataChangeNumberToString(ADC_1));
////		send_uart1(QianB);
////		send_uart1(HouB);
////		send_uart1('*');

////}


////void Lora_SendDac(void)
////{
////		u8 QianA = TempDac_1>>8;
////		u8 HouA = TempDac_1;
////		u8 QianB = TempDac_2>>8;
////		u8 HouB = TempDac_2;

////		send_uart1(0xFF);
////		send_uart1(0xFF);
////		send_uart1(ArmChannel);
////		send_uart1('A');
////		send_uart1(':');
////		send_uart1(QianA);
////		send_uart1(HouA);
////		send_uart1(',');
////		send_uart1('B');
////		send_uart1(':');
////		send_uart1(QianB);
////		send_uart1(HouB);
////		send_uart1('*');

////}

//////串口1中断函数
////void USART1_IRQHandler(void)
////{
////	u8 res;
////	if(USART1->SR&(1<<5))//接收到数据
////	{
////		res=USART1->DR;
////		if(ReceiveOrSend == 0){
////			res=USART1->DR;
////			communication_array_data_u1[communication_index_u1++]=res;
////			if(res == '*'){
////				communication_done = 1;
////			}
////		}
////		//send_uart1(USART1->DR);
////		//执行代码
////	}

////}


////void DAC_Receive(void)
////{
////	if(communication_done == 1){
////		if(Mode == 0){
////			if(communication_array_data_u1[0] == 'A'){
////				DAC_1 = communication_array_data_u1[2];
////				DAC_1 = DAC_1<<8 | communication_array_data_u1[3];
////				TempDac_1 = DAC_1;
////				

////				DAC_2 = communication_array_data_u1[7];
////				DAC_2 = DAC_2<<8 | communication_array_data_u1[8];
////				TempDac_2 = DAC_2;
////			}
////			if(communication_array_data_u1[9] == '*'){
////				Lora_SendDac();
////				LED = ~LED;
////			}
////		}
////		if(Mode != 0){
////			if(communication_array_data_u1[0] == 'A'){
////				DAC_1 = communication_array_data_u1[2];
////				DAC_1 = DAC_1<<8 | communication_array_data_u1[3];
////				TempDac_1 = DAC_1;
////				
////				
////				DAC_2 = communication_array_data_u1[7];
////				DAC_2 = DAC_2<<8 | communication_array_data_u1[8];
////				TempDac_2 = DAC_2;
////			}
////			if(communication_array_data_u1[9] == '*'){
////					SetDac4(DAC_1);
////					SetDac5(DAC_2);
////					LED = ~LED;	
////			}else{
////					SetDac4(0);
////					SetDac5(0);
////			}
////		}
////			communication_done = 0;
////			communication_index_u1=0;
////			
////	
////	}
////	

////}








