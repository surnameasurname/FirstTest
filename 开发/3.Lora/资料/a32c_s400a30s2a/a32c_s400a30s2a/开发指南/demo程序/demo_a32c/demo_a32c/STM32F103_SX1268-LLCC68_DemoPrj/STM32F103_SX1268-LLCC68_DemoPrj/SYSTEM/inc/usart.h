#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
#define EN_USART2_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
extern u8	USART1_RX_BUF[USART_REC_LEN];	//UART1���ջ�����
extern u8	USART2_RX_BUF[USART_REC_LEN];	//USART2���ջ�����

extern u16 USART_RX_STA;         		//����״̬���	

void uart1_init(u32 bound);	//USATT1��ʼ������
void uart2_init(u32 bound);	//USART2��ʼ������
void uart3_init(u32 bound);	//USART3��ʼ������
void uart4_init(u32 bound);	//USART4��ʼ������
void uart5_init(u32 bound);	//USART5��ʼ������

void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif


