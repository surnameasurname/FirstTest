#include "uart.h"





//初始化IO 串口1
//pclk2:PCLK2时钟频率(Mhz)
//bound:波特率
void uart1_init(u32 pclk2,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk2*1000000)/(bound*16);//得到USARTDIV
	mantissa=temp;				 //得到整数部分
	fraction=(temp-mantissa)*16; //得到小数部分	 
  mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<2;   //使能PORTA口时钟  
	RCC->APB2ENR|=1<<14;  //使能串口时钟 
	GPIOA->CRH&=0XFFFFF00F;//IO状态设置
	GPIOA->CRH|=0X000008B0;//IO状态设置
		  
	RCC->APB2RSTR|=1<<14;   //复位串口1
	RCC->APB2RSTR&=~(1<<14);//停止复位	   	   
	//波特率设置
 	USART1->BRR=mantissa; // 波特率设置	 
	USART1->CR1|=0X200C;  //1位停止,无校验位.	
	
#if EN_USART1_RX		  //如果使能了接收
	//使能接收中断
	USART1->CR1|=1<<8;    //PE中断使能
	USART1->CR1|=1<<5;    //接收缓冲区非空中断使能	    	
	MY_NVIC_Init(0,0,USART1_IRQn,2);//组2，抢占优先级为3，响应优先级为3 
#endif
}

//初始化串口2
//pclk1:PCLK1时钟频率(Mhz)
//bound:波特率
void uart2_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk1*1000000)/(bound*16);//得到USARTDIV
	mantissa=temp;				 //得到整数部分
	fraction=(temp-mantissa)*16; //得到小数部分	 
    mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<2;   //使能PORTA口时钟  
	RCC->APB1ENR|=1<<17;  //使能串口时钟 
	
	GPIOA->CRL&=0XFFFF00FF;//PA2推挽输出
	GPIOA->CRL|=0X00008B00;//PA3上下拉输入
	//GPIOA->CRL|=0X00004B00;//PA3上下拉输入
	//GPIOA->ODR|=1<<3;
		  
	RCC->APB1RSTR|=1<<17;   //复位串口2
	RCC->APB1RSTR&=~(1<<17);//停止复位	   	   
	//波特率设置
 	USART2->BRR=mantissa; // 波特率设置	 
	USART2->CR1|=0X200C;  //1位停止,无校验位.
#if EN_USART2_RX		  //如果使能了接收
	//使能接收中断
	USART2->CR1|=1<<8;    //PE中断使能
	USART2->CR1|=1<<5;    //接收缓冲区非空中断使能	    	
	MY_NVIC_Init(1,3,USART2_IRQn,2);////组2，抢占优先级为1，响应优先级为3
#endif
}

//初始化串口3
//pclk1:PCLK1时钟频率(Mhz)
//bound:波特率
void uart3_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk1*1000000)/(bound*16);//得到USARTDIV
	mantissa=temp;				 //得到整数部分
	fraction=(temp-mantissa)*16; //得到小数部分	 
	mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<3;   //使能PORTB口时钟  
	RCC->APB1ENR|=1<<18;  //使能串口时钟 
	
	GPIOB->CRH&=0XFFFF00FF;//PB10推挽输出
	GPIOB->CRH|=0X00008B00;//PB11上下拉输入
		  
	RCC->APB1RSTR|=1<<18;   //复位串口3
	RCC->APB1RSTR&=~(1<<18);//停止复位	   	   
	//波特率设置
 	USART3->BRR=mantissa; // 波特率设置	 
	USART3->CR1|=0X200C;  //1位停止,无校验位.
	//
//	USART3->CR1|=1<<10;//使能校验控制
//	USART3->CR1 &=~(1<<9);//偶校验
//	USART3->CR1 |=(1<<12);//一个起始位，9个数据位，n个停止位

#if EN_USART3_RX		  //如果使能了接收
	//使能接收中断
	USART3->CR1|=1<<8;    //PE中断使能
	USART3->CR1|=1<<5;    //接收缓冲区非空中断使能	    	
	MY_NVIC_Init(1,1,USART3_IRQn,1);////组2，抢占优先级为2，响应优先级为3 
#endif
}
//初始化串口
//pclk1:PCLK1时钟频率(Mhz)
//bound:波特率
void uart4_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk1*1000000)/(bound*16);//得到USARTDIV
	mantissa=temp;				 //得到整数部分
	fraction=(temp-mantissa)*16; //得到小数部分	 
    mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<4;   //使能PORTC口时钟  
	RCC->APB1ENR|=1<<19;  //使能串口时钟 
	
	GPIOC->CRH&=0XFFFF00FF;//PC10推挽输出
	GPIOC->CRH|=0X00008B00;//PC11上下拉输入
		  
	RCC->APB1RSTR|=1<<19;   //复位串口4
	RCC->APB1RSTR&=~(1<<19);//停止复位	   	   
	//波特率设置
 	UART4->BRR=mantissa; // 波特率设置	 
	UART4->CR1|=0X200C;  //1位停止,无校验位.
		
#if EN_USART4_RX		  //如果使能了接收
	//使能接收中断
	UART4->CR1|=1<<8;    //PE中断使能
	UART4->CR1|=1<<5;    //接收缓冲区非空中断使能	    	
	MY_NVIC_Init(1,0,UART4_IRQn,2);////组2，抢占优先级为3，响应优先级为2 
#endif
}

////初始化串口
////pclk1:PCLK1时钟频率(Mhz)
////bound:波特率
//void uart5_init(u32 pclk1,u32 bound)
//{
//	float temp;
//	u16 mantissa;
//	u16 fraction;	   
//	temp=(float)(pclk1*1000000)/(bound*16);//得到USARTDIV
//	mantissa=temp;				 //得到整数部分
//	fraction=(temp-mantissa)*16; //得到小数部分	 
//    mantissa<<=4;
//	mantissa+=fraction; 
//	RCC->APB2ENR|=1<<4;   //使能PORTC口时钟 
//	RCC->APB2ENR|=1<<5;   //使能PORTD口时钟 	
//	RCC->APB1ENR|=1<<20;  //使能串口时钟 
//	
//	GPIOC->CRH&=0XFFF0FFFF;//
//	GPIOC->CRH|=0X000B0000;//PC12推挽输出
//	
//	GPIOD->CRL&=0XFFFFF0FF;
//	GPIOD->CRL|=0X00000800;//PD2上下拉输入
//		  
//	RCC->APB1RSTR|=1<<20;   //复位串口5
//	RCC->APB1RSTR&=~(1<<20);//停止复位	   	   
//	//波特率设置
// 	UART5->BRR=mantissa; // 波特率设置	 
//	UART5->CR1|=0X200C;  //1位停止,无校验位.
//#if EN_USART5_RX		  //如果使能了接收
//	//使能接收中断
//	UART5->CR1|=1<<8;    //PE中断使能
//	UART5->CR1|=1<<5;    //接收缓冲区非空中断使能	    	
//	MY_NVIC_Init(3,3,UART5_IRQn,2);////组2，抢占优先级为3，响应优先级为3 
//#endif
//}

//串口1发送一个字节
void send_uart1(u8 u1data)
{
	RS485_Send();
	USART1->DR=u1data;
	while((USART1->SR&0x40)==0);
	//USART1->SR &=0x40;
	RS485_Read();
}
//串口1发送一个字符串
void send_uart1_string(u8 *s)
{
	while(*(s) !='\0')
	{
		send_uart1(*s++);
	}
}
//串口2发送一个字节
void send_uart2(u8 u2data)
{
	USART2->DR=u2data;
	while((USART2->SR&0x40)==0);
	USART2->SR &=0x40;
}
//串口2发送一个字符串
void send_uart2_string(u8 *s)
{
	RS485_Send();
	while(*(s) !='\0')
	{
		send_uart2(*s++);
	}
	RS485_Read();
}
//串口3发送一个字节
void send_uart3(u8 u3data)
{
	USART3->DR=u3data;
	while((USART3->SR&0x40)==0);
	USART3->SR &=0x40;
}
//串口3发送一个字符串
void send_uart3_string(u8 *s)
{
	while(*(s) !='\0')
	{
		send_uart3(*s++);
	}
}
//串口4发送一个字节
void send_uart4(u8 u4data)
{
//	UART4->DR=u4data;
//	while((UART4->SR&0x40)==0);
//	UART4->SR &=0x40;
}
//串口4发送一个字符串
void send_uart4_string(u8 *s)
{
//	while(*(s) !='\0')
//	{
//		send_uart4(*s++);
//	}
}
//串口5发送一个字节
void send_uart5(u8 u5data)
{
	UART5->DR=u5data;
	while((UART5->SR&0x40)==0);
	UART5->SR &=0x40;
}

//串口5发送一个字符串
void send_uart5_string(u8 *s)
{
	while(*(s) !='\0')
	{
		send_uart5(*s++);
	}
}
////串口1中断函数
//void USART1_IRQHandler(void)
//{
//	if(USART1->SR&(1<<5))//接收到数据
//	{
//		//send_uart1(USART1->DR);
//		//执行代码
//	}
//}

//串口2中断函数
//void USART2_IRQHandler(void)
//{
//	if(USART2->SR&(1<<5))//接收到数据
//	{
//		send_uart2(USART2->DR);
//		//执行代码
//	}
//}

////串口3中断函数
//void USART3_IRQHandler(void)
//{
//	if(USART3->SR&(1<<5))//接收到数据
//	{
//		send_uart3(USART3->DR);
//		//执行代码
//	}
//}
//串口4中断函数

//void UART4_IRQHandler(void)
//{
//	if(UART4->SR&(1<<5))//接收到数据
//	{
//		send_uart4(UART4->DR);
//		//执行代码
//	}
//}
//串口5中断函数
//void UART5_IRQHandler(void)
//{
//	if(UART5->SR&(1<<5))//接收到数据
//	{
//		send_uart5(UART5->DR);
//		//执行代码
//	}
//}


//485接收
void RS485_Read(void)
{
    RS485_TX_EN = 0;
}
//485发送
void RS485_Send(void)
{
    RS485_TX_EN = 1;
}

void RS485_Send_Data(u8 *buf, u8 len)
{
    u8 t;
   RS485_Send();        //设置为发送模式
    for (t = 0; t < len; t++) //循环发送数据
    {
        while ((USART2->SR & 0X40) == 0); //等待发送结束
        USART2->DR = buf[t];
    }
    while ((USART2->SR & 0X40) == 0); //等待发送结束

   RS485_Read();          //设置为接收模式
}





