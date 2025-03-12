#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define USART_REC_LEN  			200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
#define EN_USART2_RX 			1		//使能（1）/禁止（0）串口1接收
extern u8	USART1_RX_BUF[USART_REC_LEN];	//UART1接收缓冲区
extern u8	USART2_RX_BUF[USART_REC_LEN];	//USART2接收缓冲区

extern u16 USART_RX_STA;         		//接收状态标记	

void uart1_init(u32 bound);	//USATT1初始化函数
void uart2_init(u32 bound);	//USART2初始化函数
void uart3_init(u32 bound);	//USART3初始化函数
void uart4_init(u32 bound);	//USART4初始化函数
void uart5_init(u32 bound);	//USART5初始化函数

void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif


