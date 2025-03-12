#include "usart0.h"

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







