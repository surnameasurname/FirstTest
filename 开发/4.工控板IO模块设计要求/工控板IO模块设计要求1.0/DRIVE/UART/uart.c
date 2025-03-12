#include "uart.h"





//��ʼ��IO ����1
//pclk2:PCLK2ʱ��Ƶ��(Mhz)
//bound:������
void uart1_init(u32 pclk2,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk2*1000000)/(bound*16);//�õ�USARTDIV
	mantissa=temp;				 //�õ���������
	fraction=(temp-mantissa)*16; //�õ�С������	 
  mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<2;   //ʹ��PORTA��ʱ��  
	RCC->APB2ENR|=1<<14;  //ʹ�ܴ���ʱ�� 
	GPIOA->CRH&=0XFFFFF00F;//IO״̬����
	GPIOA->CRH|=0X000008B0;//IO״̬����
		  
	RCC->APB2RSTR|=1<<14;   //��λ����1
	RCC->APB2RSTR&=~(1<<14);//ֹͣ��λ	   	   
	//����������
 	USART1->BRR=mantissa; // ����������	 
	USART1->CR1|=0X200C;  //1λֹͣ,��У��λ.	
	
#if EN_USART1_RX		  //���ʹ���˽���
	//ʹ�ܽ����ж�
	USART1->CR1|=1<<8;    //PE�ж�ʹ��
	USART1->CR1|=1<<5;    //���ջ������ǿ��ж�ʹ��	    	
	MY_NVIC_Init(0,0,USART1_IRQn,2);//��2����ռ���ȼ�Ϊ3����Ӧ���ȼ�Ϊ3 
#endif
}

//��ʼ������2
//pclk1:PCLK1ʱ��Ƶ��(Mhz)
//bound:������
void uart2_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk1*1000000)/(bound*16);//�õ�USARTDIV
	mantissa=temp;				 //�õ���������
	fraction=(temp-mantissa)*16; //�õ�С������	 
    mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<2;   //ʹ��PORTA��ʱ��  
	RCC->APB1ENR|=1<<17;  //ʹ�ܴ���ʱ�� 
	
	GPIOA->CRL&=0XFFFF00FF;//PA2�������
	GPIOA->CRL|=0X00008B00;//PA3����������
	//GPIOA->CRL|=0X00004B00;//PA3����������
	//GPIOA->ODR|=1<<3;
		  
	RCC->APB1RSTR|=1<<17;   //��λ����2
	RCC->APB1RSTR&=~(1<<17);//ֹͣ��λ	   	   
	//����������
 	USART2->BRR=mantissa; // ����������	 
	USART2->CR1|=0X200C;  //1λֹͣ,��У��λ.
#if EN_USART2_RX		  //���ʹ���˽���
	//ʹ�ܽ����ж�
	USART2->CR1|=1<<8;    //PE�ж�ʹ��
	USART2->CR1|=1<<5;    //���ջ������ǿ��ж�ʹ��	    	
	MY_NVIC_Init(1,3,USART2_IRQn,2);////��2����ռ���ȼ�Ϊ1����Ӧ���ȼ�Ϊ3
#endif
}

//��ʼ������3
//pclk1:PCLK1ʱ��Ƶ��(Mhz)
//bound:������
void uart3_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk1*1000000)/(bound*16);//�õ�USARTDIV
	mantissa=temp;				 //�õ���������
	fraction=(temp-mantissa)*16; //�õ�С������	 
	mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<3;   //ʹ��PORTB��ʱ��  
	RCC->APB1ENR|=1<<18;  //ʹ�ܴ���ʱ�� 
	
	GPIOB->CRH&=0XFFFF00FF;//PB10�������
	GPIOB->CRH|=0X00008B00;//PB11����������
		  
	RCC->APB1RSTR|=1<<18;   //��λ����3
	RCC->APB1RSTR&=~(1<<18);//ֹͣ��λ	   	   
	//����������
 	USART3->BRR=mantissa; // ����������	 
	USART3->CR1|=0X200C;  //1λֹͣ,��У��λ.
	//
//	USART3->CR1|=1<<10;//ʹ��У�����
//	USART3->CR1 &=~(1<<9);//żУ��
//	USART3->CR1 |=(1<<12);//һ����ʼλ��9������λ��n��ֹͣλ

#if EN_USART3_RX		  //���ʹ���˽���
	//ʹ�ܽ����ж�
	USART3->CR1|=1<<8;    //PE�ж�ʹ��
	USART3->CR1|=1<<5;    //���ջ������ǿ��ж�ʹ��	    	
	MY_NVIC_Init(1,1,USART3_IRQn,1);////��2����ռ���ȼ�Ϊ2����Ӧ���ȼ�Ϊ3 
#endif
}
//��ʼ������
//pclk1:PCLK1ʱ��Ƶ��(Mhz)
//bound:������
void uart4_init(u32 pclk1,u32 bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;	   
	temp=(float)(pclk1*1000000)/(bound*16);//�õ�USARTDIV
	mantissa=temp;				 //�õ���������
	fraction=(temp-mantissa)*16; //�õ�С������	 
    mantissa<<=4;
	mantissa+=fraction; 
	RCC->APB2ENR|=1<<4;   //ʹ��PORTC��ʱ��  
	RCC->APB1ENR|=1<<19;  //ʹ�ܴ���ʱ�� 
	
	GPIOC->CRH&=0XFFFF00FF;//PC10�������
	GPIOC->CRH|=0X00008B00;//PC11����������
		  
	RCC->APB1RSTR|=1<<19;   //��λ����4
	RCC->APB1RSTR&=~(1<<19);//ֹͣ��λ	   	   
	//����������
 	UART4->BRR=mantissa; // ����������	 
	UART4->CR1|=0X200C;  //1λֹͣ,��У��λ.
		
#if EN_USART4_RX		  //���ʹ���˽���
	//ʹ�ܽ����ж�
	UART4->CR1|=1<<8;    //PE�ж�ʹ��
	UART4->CR1|=1<<5;    //���ջ������ǿ��ж�ʹ��	    	
	MY_NVIC_Init(1,0,UART4_IRQn,2);////��2����ռ���ȼ�Ϊ3����Ӧ���ȼ�Ϊ2 
#endif
}

////��ʼ������
////pclk1:PCLK1ʱ��Ƶ��(Mhz)
////bound:������
//void uart5_init(u32 pclk1,u32 bound)
//{
//	float temp;
//	u16 mantissa;
//	u16 fraction;	   
//	temp=(float)(pclk1*1000000)/(bound*16);//�õ�USARTDIV
//	mantissa=temp;				 //�õ���������
//	fraction=(temp-mantissa)*16; //�õ�С������	 
//    mantissa<<=4;
//	mantissa+=fraction; 
//	RCC->APB2ENR|=1<<4;   //ʹ��PORTC��ʱ�� 
//	RCC->APB2ENR|=1<<5;   //ʹ��PORTD��ʱ�� 	
//	RCC->APB1ENR|=1<<20;  //ʹ�ܴ���ʱ�� 
//	
//	GPIOC->CRH&=0XFFF0FFFF;//
//	GPIOC->CRH|=0X000B0000;//PC12�������
//	
//	GPIOD->CRL&=0XFFFFF0FF;
//	GPIOD->CRL|=0X00000800;//PD2����������
//		  
//	RCC->APB1RSTR|=1<<20;   //��λ����5
//	RCC->APB1RSTR&=~(1<<20);//ֹͣ��λ	   	   
//	//����������
// 	UART5->BRR=mantissa; // ����������	 
//	UART5->CR1|=0X200C;  //1λֹͣ,��У��λ.
//#if EN_USART5_RX		  //���ʹ���˽���
//	//ʹ�ܽ����ж�
//	UART5->CR1|=1<<8;    //PE�ж�ʹ��
//	UART5->CR1|=1<<5;    //���ջ������ǿ��ж�ʹ��	    	
//	MY_NVIC_Init(3,3,UART5_IRQn,2);////��2����ռ���ȼ�Ϊ3����Ӧ���ȼ�Ϊ3 
//#endif
//}

//����1����һ���ֽ�
void send_uart1(u8 u1data)
{
	RS485_Send();
	USART1->DR=u1data;
	while((USART1->SR&0x40)==0);
	//USART1->SR &=0x40;
	RS485_Read();
}
//����1����һ���ַ���
void send_uart1_string(u8 *s)
{
	while(*(s) !='\0')
	{
		send_uart1(*s++);
	}
}
//����2����һ���ֽ�
void send_uart2(u8 u2data)
{
	USART2->DR=u2data;
	while((USART2->SR&0x40)==0);
	USART2->SR &=0x40;
}
//����2����һ���ַ���
void send_uart2_string(u8 *s)
{
	RS485_Send();
	while(*(s) !='\0')
	{
		send_uart2(*s++);
	}
	RS485_Read();
}
//����3����һ���ֽ�
void send_uart3(u8 u3data)
{
	USART3->DR=u3data;
	while((USART3->SR&0x40)==0);
	USART3->SR &=0x40;
}
//����3����һ���ַ���
void send_uart3_string(u8 *s)
{
	while(*(s) !='\0')
	{
		send_uart3(*s++);
	}
}
//����4����һ���ֽ�
void send_uart4(u8 u4data)
{
//	UART4->DR=u4data;
//	while((UART4->SR&0x40)==0);
//	UART4->SR &=0x40;
}
//����4����һ���ַ���
void send_uart4_string(u8 *s)
{
//	while(*(s) !='\0')
//	{
//		send_uart4(*s++);
//	}
}
//����5����һ���ֽ�
void send_uart5(u8 u5data)
{
	UART5->DR=u5data;
	while((UART5->SR&0x40)==0);
	UART5->SR &=0x40;
}

//����5����һ���ַ���
void send_uart5_string(u8 *s)
{
	while(*(s) !='\0')
	{
		send_uart5(*s++);
	}
}
////����1�жϺ���
//void USART1_IRQHandler(void)
//{
//	if(USART1->SR&(1<<5))//���յ�����
//	{
//		//send_uart1(USART1->DR);
//		//ִ�д���
//	}
//}

//����2�жϺ���
//void USART2_IRQHandler(void)
//{
//	if(USART2->SR&(1<<5))//���յ�����
//	{
//		send_uart2(USART2->DR);
//		//ִ�д���
//	}
//}

////����3�жϺ���
//void USART3_IRQHandler(void)
//{
//	if(USART3->SR&(1<<5))//���յ�����
//	{
//		send_uart3(USART3->DR);
//		//ִ�д���
//	}
//}
//����4�жϺ���

//void UART4_IRQHandler(void)
//{
//	if(UART4->SR&(1<<5))//���յ�����
//	{
//		send_uart4(UART4->DR);
//		//ִ�д���
//	}
//}
//����5�жϺ���
//void UART5_IRQHandler(void)
//{
//	if(UART5->SR&(1<<5))//���յ�����
//	{
//		send_uart5(UART5->DR);
//		//ִ�д���
//	}
//}


//485����
void RS485_Read(void)
{
    RS485_TX_EN = 0;
}
//485����
void RS485_Send(void)
{
    RS485_TX_EN = 1;
}

void RS485_Send_Data(u8 *buf, u8 len)
{
    u8 t;
   RS485_Send();        //����Ϊ����ģʽ
    for (t = 0; t < len; t++) //ѭ����������
    {
        while ((USART2->SR & 0X40) == 0); //�ȴ����ͽ���
        USART2->DR = buf[t];
    }
    while ((USART2->SR & 0X40) == 0); //�ȴ����ͽ���

   RS485_Read();          //����Ϊ����ģʽ
}





