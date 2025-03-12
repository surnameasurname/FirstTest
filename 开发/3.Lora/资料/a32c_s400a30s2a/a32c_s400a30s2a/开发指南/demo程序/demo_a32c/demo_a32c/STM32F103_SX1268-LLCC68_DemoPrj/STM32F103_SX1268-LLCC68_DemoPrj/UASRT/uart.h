#ifndef __uart_H
#define __uart_H

#include "stdio.h"	
#include "stm32f10x.h"

#define UART_BUFF_MAX_SIZE	255		//������������

typedef struct
{
	uint8_t Receive_Byte_Flag ;		//���յ�һ�ֽڱ�־
	uint8_t Receive_OK ;			//����һ֡�������
	uint8_t WaitTime_Max;			//�������ȴ�ʱ��
	uint8_t WaitTime;				//ʵ�ʽ��յȴ�ʱ��
	uint16_t Receive_Num;			//ʵ�ʽ��յ��ֽ���
	uint8_t Recv_Buff[ UART_BUFF_MAX_SIZE ];			//���ջ���
	uint8_t Send_Buff[ UART_BUFF_MAX_SIZE ];			//���ͻ���
}Uart_Data_Struct;

extern Uart_Data_Struct Uart_dat;

void USART1_Init(u32 Baud);
void Clear_Uart_Dat( Uart_Data_Struct *uart_dat_struct );
void USART_SendBuffDat(USART_TypeDef* uartx, u8 *BUFF, u8 len);
void USART_SendString( USART_TypeDef * pUSARTx, char *str);
void USART_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);

#endif
