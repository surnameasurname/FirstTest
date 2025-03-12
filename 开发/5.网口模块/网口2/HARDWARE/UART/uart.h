#ifndef  _uart_h_
#define  _uart_h_
#include "sys.h"

#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
#define EN_USART2_RX 			1		//ʹ�ܣ�1��/��ֹ��0������2����
#define EN_USART3_RX 			1		//ʹ�ܣ�1��/��ֹ��0������3����
#define EN_USART4_RX 			1		//ʹ�ܣ�1��/��ֹ��0������4����
#define EN_USART5_RX 			1		//ʹ�ܣ�1��/��ֹ��0������5����

void uart1_init(u32 pclk2,u32 bound);
void send_uart1(u8 u1data);
void uart2_init(u32 pclk1,u32 bound);
void send_uart2(u8 u2data);
void uart3_init(u32 pclk1,u32 bound);
void send_uart3(u8 u3data);
void uart4_init(u32 pclk1,u32 bound);
void send_uart4(u8 u4data);
void uart5_init(u32 pclk1,u32 bound);
void send_uart5(u8 u5data);
//����1����һ���ַ���
void send_uart1_string(u8 *s);
//����2����һ���ַ���
void send_uart2_string(u8 *s);
//����3����һ���ַ���
void send_uart3_string(u8 *s);
//����4����һ���ַ���
void send_uart4_string(u8 *s);
//����5����һ���ַ���
void send_uart5_string(u8 *s);
//RS485����len���ֽ�.
//buf:�������׵�ַ
//len:���͵��ֽ���(Ϊ�˺ͱ�����Ľ���ƥ��,���ｨ�鲻Ҫ����64���ֽ�)
void RS485_Send_Data(u8 *buf,u8 len);

#endif

