#include "uart.h"
#include "TIM.h"

Uart_Data_Struct Uart_dat = { 0 ,0 , 1 , 0 ,0 , 0 , 0 };

void USART1_Init(u32 Baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	//--使能串口IO时钟，串口外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	//--配置PA9-UART1-TX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;		//PA9
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	//复用推挽输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//--配置PA10-UART1-RX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;	//PA10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//--USART1-NVIC优先级配置
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;		//中断通道号
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority/=3;		//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;	//响应优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;		//使能IRQ中断
	NVIC_Init(&NVIC_InitStructure);
	//--USART1-参数配置
	USART_InitStructure.USART_BaudRate=Baud;		//波特率
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;	//无硬件数据流控制
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;	//收发模式
	USART_InitStructure.USART_Parity=USART_Parity_No;	//无奇偶校验
	USART_InitStructure.USART_StopBits=USART_StopBits_1;	//一位停止位
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;	//8位数据格式
	USART_Init(USART1,&USART_InitStructure);
	//--使能USART1接收中断
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//--使能USART1
	USART_Cmd(USART1,ENABLE);
}

//--发送一个字符--
/*****************  发送一个字符 **********************/
void USART_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
	/* 发送一个字节数据到USART */
	USART_SendData(pUSARTx,ch);		
	/* 等待发送数据寄存器为空 */
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}
/*****************  发送字符串 **********************/
void USART_SendString( USART_TypeDef * pUSARTx, char *str)
{
	while( *str)
	{
		USART_SendByte(pUSARTx,*str++);
	}
}

/********USART发送一个缓冲区的数据**********/
void USART_SendBuffDat(USART_TypeDef* uartx, u8 *BUFF, u8 len)
{
	while(len--)
	{
		USART_SendByte(uartx,*BUFF++);
	}
}

/*----清除UART结构体的属性----*/
void Clear_Uart_Dat( Uart_Data_Struct *uart_dat_struct )
{
	uint16_t i ;
	for( i = 0; i < uart_dat_struct->Receive_Num ; i++)
	{
		uart_dat_struct->Recv_Buff[i] = 0;
		uart_dat_struct->Send_Buff[i] = 0;
	}
	uart_dat_struct->Receive_OK = 0;
	uart_dat_struct->Receive_Num = 0;
	uart_dat_struct->Receive_Byte_Flag = 0;
	uart_dat_struct->WaitTime = 0;
}

/*******串口1中断服务函数******/
void USART1_IRQHandler(void)		//函数在启动头文件中
{
    //--接收中断发生
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		USART_ClearFlag(USART1,USART_IT_RXNE);	//清中断
        Uart_dat.WaitTime = 0;
        if(( Uart_dat.Receive_Num < UART_BUFF_MAX_SIZE ) && (!Uart_dat.Receive_OK) )
        {
            Uart_dat.Recv_Buff[ Uart_dat.Receive_Num++ ] = USART_ReceiveData( USART1 );
            Uart_dat.Receive_Byte_Flag = 1;
        }		
	}
}












