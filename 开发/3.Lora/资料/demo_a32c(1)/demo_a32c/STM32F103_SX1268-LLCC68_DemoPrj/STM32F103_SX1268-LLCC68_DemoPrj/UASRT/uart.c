#include "uart.h"
#include "TIM.h"

Uart_Data_Struct Uart_dat = { 0 ,0 , 1 , 0 ,0 , 0 , 0 };

void USART1_Init(u32 Baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	//--ʹ�ܴ���IOʱ�ӣ���������ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	//--����PA9-UART1-TX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;		//PA9
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	//�����������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//--����PA10-UART1-RX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;	//PA10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//--USART1-NVIC���ȼ�����
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;		//�ж�ͨ����
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority/=3;		//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;	//��Ӧ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;		//ʹ��IRQ�ж�
	NVIC_Init(&NVIC_InitStructure);
	//--USART1-��������
	USART_InitStructure.USART_BaudRate=Baud;		//������
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;	//��Ӳ������������
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;	//�շ�ģʽ
	USART_InitStructure.USART_Parity=USART_Parity_No;	//����żУ��
	USART_InitStructure.USART_StopBits=USART_StopBits_1;	//һλֹͣλ
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;	//8λ���ݸ�ʽ
	USART_Init(USART1,&USART_InitStructure);
	//--ʹ��USART1�����ж�
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//--ʹ��USART1
	USART_Cmd(USART1,ENABLE);
}

//--����һ���ַ�--
/*****************  ����һ���ַ� **********************/
void USART_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
	/* ����һ���ֽ����ݵ�USART */
	USART_SendData(pUSARTx,ch);		
	/* �ȴ��������ݼĴ���Ϊ�� */
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}
/*****************  �����ַ��� **********************/
void USART_SendString( USART_TypeDef * pUSARTx, char *str)
{
	while( *str)
	{
		USART_SendByte(pUSARTx,*str++);
	}
}

/********USART����һ��������������**********/
void USART_SendBuffDat(USART_TypeDef* uartx, u8 *BUFF, u8 len)
{
	while(len--)
	{
		USART_SendByte(uartx,*BUFF++);
	}
}

/*----���UART�ṹ�������----*/
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

/*******����1�жϷ�����******/
void USART1_IRQHandler(void)		//����������ͷ�ļ���
{
    //--�����жϷ���
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		USART_ClearFlag(USART1,USART_IT_RXNE);	//���ж�
        Uart_dat.WaitTime = 0;
        if(( Uart_dat.Receive_Num < UART_BUFF_MAX_SIZE ) && (!Uart_dat.Receive_OK) )
        {
            Uart_dat.Recv_Buff[ Uart_dat.Receive_Num++ ] = USART_ReceiveData( USART1 );
            Uart_dat.Receive_Byte_Flag = 1;
        }		
	}
}












