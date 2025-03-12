#include "usart0.h"
#include "communication1.h"

#define MSTART1 0xDF
#define MEND1 0xEF

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


extern uint8_t uart2_rcev_buff[100];
extern uint8_t uart2_rcev_index;
extern uint8_t receive_done;
extern uint8_t receive_flag;

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

///* retarget the C library printf function to the USART */
//int fputc(int ch, FILE *f)
//{
//    EN485();
//    usart_data_transmit(USART0, (uint8_t)ch);
//    while (RESET == usart_flag_get(USART0, USART_FLAG_TBE));
//    Dis485();
//    return ch;
//}




void usart2_config(uint32_t u32uaud_mode)
{
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOB);

    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART2);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

    /* connect port to USARTx_Rx */
    gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_11);

    /* USART configure */
    usart_deinit(USART2);
    usart_baudrate_set(USART2, u32uaud_mode);
    usart_parity_config(USART2, USART_PM_NONE);
    usart_word_length_set(USART2, USART_WL_8BIT);
    usart_stop_bit_set(USART2, USART_STB_1BIT);

    usart_receive_config(USART2, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART2, USART_TRANSMIT_ENABLE);

    usart_interrupt_enable(USART2, USART_INT_RBNE);
    nvic_irq_enable(USART2_IRQn, 0, 0);
    usart_enable(USART2);

}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART2, (uint8_t)ch);
    while(RESET == usart_flag_get(USART2, USART_FLAG_TBE));
    return ch;
}

void uart2_send_byte(uint8_t ch)
{
    usart_data_transmit(USART2, (uint8_t)ch);
    while (RESET == usart_flag_get(USART2, USART_FLAG_TBE));
}

void uart2_send_string(uint8_t *str)
{
    uint8_t *p = str;
    while (*p)
    {
        uart2_send_byte(*p);
        p++;
    }
}



void uart2_send_data(uint8_t *data, int len)
{
    int i;
    for (i = 0; i < len; i++)
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

void USART2_IRQHandler(void)  //串口0中断服务程序
{
    if (usart_interrupt_flag_get(USART2, USART_INT_FLAG_RBNE) == SET)
    {
        usart_interrupt_flag_clear(USART2, USART_INT_FLAG_RBNE);
        uart2_rcev_buff[uart2_rcev_index] = usart_data_receive(USART2);

        if (uart2_rcev_buff[0]==0x01)
        {
            uart2_rcev_index++;
        }

        if (uart2_rcev_index > 1)
        {
            if (uart2_rcev_buff[1] == 0x03 && ReceiveMode==1)
            {
                if (uart2_rcev_index >= 8)
                {
                    u16RxcheckSum = crc16(uart2_rcev_buff, 7);
                    
                    if (uart2_rcev_buff[7] == (u16RxcheckSum >> 8) && (uart2_rcev_buff[8] == (u16RxcheckSum & 0xff)))
                    {
                        receive_done = 0x03;
                    }
                    else
                    {
                        receive_done = 0;
                    }
                    u16RxcheckSum = 0;
                    uart2_rcev_index = 0;
                }
            }
            else if (uart2_rcev_buff[1] == 0x06 && ReceiveMode==2)
            {
                if (uart2_rcev_index >= 8)
                {
                    u16RxcheckSum = crc16(uart2_rcev_buff, 7);

                    if (uart2_rcev_buff[7] == (u16RxcheckSum >> 8) && (uart2_rcev_buff[8] == (u16RxcheckSum & 0xff)))
                    {
                        receive_done = 0x06;
                    }
                    else
                    {
                        receive_done = 0;
                    }
                    u16RxcheckSum = 0;
                    uart2_rcev_index = 0;
                }
            }
            else
            {
                uart2_rcev_index = 0;
            }
        }
    }
}



