#include "usart0.h"

#define MSTART1 0xDF
#define MEND1 0xEF

extern uint8_t uart2_rcev_buff[100];
extern uint8_t uart2_rcev_index;
extern uint8_t receive_done;
extern uint8_t receive_flag;


extern int order_res_finish;
extern int urx_len;
//extern uint8_t urx_buff[100];
extern int start1;
extern int end1;
extern uint8_t u8UsartRxData[100];
extern uint8_t u8UsartRxCnt;
extern uint8_t u8fReceiveStart;
extern uint16_t u16RxcheckSum;
extern uint8_t u8RxFinished;

uint8_t res_data = 0;
int data_len = 0;
uint8_t re_buff_encrypt[40];

void usart0_config(uint32_t u32uaud_mode)
{
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART0);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

    /* USART configure */
    usart_deinit(USART0);
    usart_baudrate_set(USART0, u32uaud_mode);
    usart_parity_config(USART0, USART_PM_NONE);
    usart_word_length_set(USART0, USART_WL_8BIT);
    usart_stop_bit_set(USART0, USART_STB_1BIT);

    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);

    usart_interrupt_enable(USART0, USART_INT_RBNE);
    nvic_irq_enable(USART0_IRQn, 0, 0);
    usart_enable(USART0);


    //    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_8);

}

void EN485(void)
{
    gpio_bit_set(GPIOA, GPIO_PIN_8);
}
void Dis485(void)
{
    gpio_bit_reset(GPIOA, GPIO_PIN_8);
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    EN485();
    usart_data_transmit(USART0, (uint8_t)ch);
    while (RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    Dis485();
    return ch;
}







void uart2_init (void)
{
	/* ʹ�� GPIO ʱ�� */
	rcu_periph_clock_enable(RCU_GPIOB);
	/* ʹ�� uart ʱ�� */
	rcu_periph_clock_enable(RCU_USART2);
	/* �� GPIO B10 ���Ÿ���Ϊ USARTx_Tx */
	gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);
	/* �� GPIO B11 ���Ÿ���Ϊ USARTx_Rx */
	gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ,GPIO_PIN_11);
	/* USART ȥ��ʼ�� */
	usart_deinit(USART2);
	//����������
	usart_baudrate_set(USART2, 115200U);
	//����ʹ��
	usart_receive_config(USART2, USART_RECEIVE_ENABLE);
	//����ʹ��
	usart_transmit_config(USART2, USART_TRANSMIT_ENABLE);
	//ʹ�ܴ���2
	usart_enable(USART2);
}

void uart2_send_byte(uint8_t ch)
{
	usart_data_transmit(USART2, (uint8_t)ch);
	while(RESET == usart_flag_get(USART2, USART_FLAG_TBE));
}

void uart2_send_string(uint8_t *str)
{
	uint8_t *p = str;
	while(*p)
	{
		uart2_send_byte(*p);
		p++;
	}
}



void uart2_send_data(uint8_t *data, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		uart2_send_byte(data[i]);
	}
}



/*!
\brief this function handles USART0 exception
\param[in] none
\param[out] none
\retval none
*/
void USART2_IRQHandler(void)
{
	uint8_t ch = 0;
	if(RESET != usart_interrupt_flag_get(USART2, USART_INT_FLAG_RBNE))
	{
		/* Read one byte from the receive data register */
		ch = (uint8_t)usart_data_receive(USART2);
		//1.�ַ��ͻ��ǽ���   �����ڹ�����
		//10 д����Ĵ���
		//03 �����ּĴ���
		uart2_rcev_buff[uart2_rcev_index ++] = ch;
		if(uart2_rcev_buff[1] == 10){//��
			receive_flag = 10;
			uart2_rcev_buff[1] = 1;
		}
		if(uart2_rcev_buff[1] == 3){//��
			receive_flag = 3;
			uart2_rcev_buff[1] = 1;
		}
		if(receive_flag == 10 && (uart2_rcev_buff[6]+9)==uart2_rcev_index)
		{
			receive_done = 10;
			uart2_rcev_index = 0; 
			receive_flag = 0;
		}
		if(receive_flag == 3 && 8 == uart2_rcev_index)
		{
			uart2_rcev_index = 0;
			receive_done = 3;
			receive_flag = 0;
		}
		
		
//		if(uart2_rcev_index < sizeof(uart2_rcev_buff))
//		{
//			uart2_rcev_buff[uart2_rcev_index ++] = ch;
//		}
	}
}



















