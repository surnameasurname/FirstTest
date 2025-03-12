#define __KEY_C__

#include <gd32f30x.h>
#include "led.h"


void  key_init (void)
{
	
    /* 使能 GPIOC 时钟源 */
    rcu_periph_clock_enable(RCU_GPIOC);

    /* 配置按键为 浮空输入 */
    gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_13);	
}

void  key_exit_mode_init (void)
{

	/* 配置中断优先级 */
	nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);

	/* 把对应的引脚连接到 exit外部中断  */
	gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOC, GPIO_PIN_SOURCE_13);

	/* 配置外部中断13 */
	exti_init(EXTI_13, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
	exti_interrupt_flag_clear(EXTI_13);
}


uint8_t key_state_get(void)
{
    return gpio_input_bit_get(GPIOC, GPIO_PIN_13);
}

