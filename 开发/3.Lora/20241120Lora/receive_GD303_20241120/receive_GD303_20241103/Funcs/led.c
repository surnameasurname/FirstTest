#include "led.h"

void delay_mine(uint32_t tt)
{
    int i;
    i = tt;

    while (i >= 0)
        i--;
}


void led_init()
{
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOB);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

    led_on();
}


void led_on()
{
    gpio_bit_set(GPIOB, GPIO_PIN_9);
}

void led_off()
{
    gpio_bit_reset(GPIOB, GPIO_PIN_9);
}
