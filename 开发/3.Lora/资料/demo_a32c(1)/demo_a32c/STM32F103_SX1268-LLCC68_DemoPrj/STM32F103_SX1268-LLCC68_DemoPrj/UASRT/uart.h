#ifndef __uart_H
#define __uart_H

#include "stdio.h"	
#include "stm32f10x.h"

#define UART_BUFF_MAX_SIZE	255		//缓存的最大容量

typedef struct
{
	uint8_t Receive_Byte_Flag ;		//接收到一字节标志
	uint8_t Receive_OK ;			//接收一帧数据完成
	uint8_t WaitTime_Max;			//接收最大等待时间
	uint8_t WaitTime;				//实际接收等待时间
	uint16_t Receive_Num;			//实际接收到字节数
	uint8_t Recv_Buff[ UART_BUFF_MAX_SIZE ];			//接收缓存
	uint8_t Send_Buff[ UART_BUFF_MAX_SIZE ];			//发送缓存
}Uart_Data_Struct;

extern Uart_Data_Struct Uart_dat;

void USART1_Init(u32 Baud);
void Clear_Uart_Dat( Uart_Data_Struct *uart_dat_struct );
void USART_SendBuffDat(USART_TypeDef* uartx, u8 *BUFF, u8 len);
void USART_SendString( USART_TypeDef * pUSARTx, char *str);
void USART_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);

#endif
