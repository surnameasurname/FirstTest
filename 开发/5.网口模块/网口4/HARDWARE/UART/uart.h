#ifndef  _uart_h_
#define  _uart_h_
#include "sys.h"

#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
#define EN_USART2_RX 			1		//使能（1）/禁止（0）串口2接收
#define EN_USART3_RX 			1		//使能（1）/禁止（0）串口3接收
#define EN_USART4_RX 			1		//使能（1）/禁止（0）串口4接收
#define EN_USART5_RX 			1		//使能（1）/禁止（0）串口5接收

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
//串口1发送一个字符串
void send_uart1_string(u8 *s);
//串口2发送一个字符串
void send_uart2_string(u8 *s);
//串口3发送一个字符串
void send_uart3_string(u8 *s);
//串口4发送一个字符串
void send_uart4_string(u8 *s);
//串口5发送一个字符串
void send_uart5_string(u8 *s);
//RS485发送len个字节.
//buf:发送区首地址
//len:发送的字节数(为了和本代码的接收匹配,这里建议不要超过64个字节)
void RS485_Send_Data(u8 *buf,u8 len);

#endif

