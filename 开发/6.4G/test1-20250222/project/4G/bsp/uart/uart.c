#define __UART_C__

#include <gd32f30x.h>
#include "led.h"


void  uart0_init (void)
{
	/* 使能 GPIO 时钟 */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* 使能 uart 时钟 */
    rcu_periph_clock_enable(RCU_USART0);

    /* 将GPIO A9 引脚复用为 USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

    /* 将GPIO A10 引脚复用为 USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

    /* USART 去初始化 */
    usart_deinit(USART0);
	//波特率设置
    usart_baudrate_set(USART0, 115200U);
	//接受使能
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
	//发送使能
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
	//使能串口0
    usart_enable(USART0);

	/* 中断配置 */
	
	/* 使能串口中断 */
    nvic_irq_enable(USART0_IRQn, 0, 0);
	/* 使能 USART0 接收中断 */
    usart_interrupt_enable(USART0, USART_INT_RBNE);
}

void uart0_send_byte(uint8_t ch)
{
	usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
}

void uart0_send_string(uint8_t *str)
{
	uint8_t *p = str;
	while(*p)
	{
		uart0_send_byte(*p);
		p++;
	}
}


void uart0_send_data(uint8_t *data, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		uart0_send_byte(data[i]);
	}
}



static uint8_t uart0_rcev_buff[100];
static uint8_t uart0_rcev_index = 0;

/*!
    \brief      this function handles USART0 exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USART0_IRQHandler(void)
{
	uint8_t ch = 0;
	if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_RBNE))
	{
		/* Read one byte from the receive data register */
		ch = (uint8_t)usart_data_receive(USART0);

		if(uart0_rcev_index < sizeof(uart0_rcev_buff))
		{
			uart0_rcev_buff[uart0_rcev_index ++] = ch;
		}
	}
}


