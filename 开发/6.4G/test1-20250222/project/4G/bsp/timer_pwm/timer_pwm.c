#define __TIMER_PWM_C__

#include <gd32f30x.h>

void gpio_pwm_config(void);
void timer_pwm_config(void);
/**
设置引脚为PWM模式
  */
void gpio_pwm_config(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    
    /*Configure PA8(TIMER0_CH0) as alternate function*/
//    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1 | GPIO_PIN_2);
		gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
	
		gpio_bit_set(GPIOA, GPIO_PIN_1);
		//gpio_bit_reset(GPIOA, GPIO_PIN_1);
}

/**
    \brief      configure the TIMER peripheral
    \param[in]  none
    \param[out] none
    \retval     none
  */
//120MHz
void timer_pwm_config(void)
{
    /* TIMER4 configuration: generate PWM signals with different duty cycles:
       TIMER4CLK = SystemCoreClock / 120 = 1MHz */
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;

		gpio_pwm_config();
	
    rcu_periph_clock_enable(RCU_TIMER4);
    timer_deinit(TIMER4);

    /* TIMER4 configuration */
	//预分频 119
    //timer_initpara.prescaler         = 119;
	timer_initpara.prescaler         = 799;
	//边沿触发
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
	//装载值 500  CAR
    timer_initpara.period            = 500;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER4,&timer_initpara);



     /* CH1 configuration in PWM mode */
	//使能通道输出
	timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
	 //不需要通道互补
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
	 //通道输出极性 为高电平
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
	 //通道互补输出极性 高电平
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
	 //通道输出空闲状态 低电平
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
	 //通道互补输出空闲状态 低电平
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER4,TIMER_CH_1,&timer_ocintpara);

	//配置TIMER通道输出脉冲值 也就是 CHX_CV值
    timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,250);
	//设置定时器通道0输出为PWM模式
    timer_channel_output_mode_config(TIMER4,TIMER_CH_1,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER4,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);
		
		
		
		/*-----------------------------------------------------*/
		
		
		
		
		
		/*-----------------------------------------------------*/

    timer_primary_output_config(TIMER4,ENABLE);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER4);
    timer_enable(TIMER4);
}

void timer_pwm_two_config(void)
{
    /* TIMER4 configuration: generate PWM signals with different duty cycles:
       TIMER4CLK = SystemCoreClock / 120 = 1MHz */
    timer_oc_parameter_struct timer_ocintpara1,timer_ocintpara2;
    timer_parameter_struct timer_initpara;

	gpio_pwm_config();
	
    rcu_periph_clock_enable(RCU_TIMER4);
    timer_deinit(TIMER4);

    /* TIMER4 configuration */
	//预分频 119
    timer_initpara.prescaler         = 119;
	//边沿触发
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
	//装载值 500  CAR
    timer_initpara.period            = 500;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER4,&timer_initpara);



     /* CH1 configuration in PWM mode */
	//使能通道输出
	timer_ocintpara1.outputstate  = TIMER_CCX_ENABLE;
	 //不需要通道互补
    timer_ocintpara1.outputnstate = TIMER_CCXN_DISABLE;
	 //通道输出极性 为高电平
    timer_ocintpara1.ocpolarity   = TIMER_OC_POLARITY_HIGH;
	 //通道互补输出极性 高电平
    timer_ocintpara1.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
	 //通道输出空闲状态 低电平
    timer_ocintpara1.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
	 //通道互补输出空闲状态 低电平
    timer_ocintpara1.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER4,TIMER_CH_1,&timer_ocintpara1);

	//配置TIMER通道输出脉冲值 也就是 CHX_CV值
    timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,250);
	//设置定时器通道0输出为PWM模式
    timer_channel_output_mode_config(TIMER4,TIMER_CH_1,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER4,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);
		
		
		
		/*-----------------------------------------------------*/
		timer_ocintpara1 = timer_ocintpara2;
		timer_channel_output_pulse_value_config(TIMER4, TIMER_CH_2, 125);
		timer_channel_output_config(TIMER4, TIMER_CH_2, &timer_ocintpara2); // 应用配置到CH2
		timer_channel_output_mode_config(TIMER4, TIMER_CH_2, TIMER_OC_MODE_PWM0); // 设置CH2为PWM模式
		
		/*-----------------------------------------------------*/

    timer_primary_output_config(TIMER4,ENABLE);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER4);
    timer_enable(TIMER4);
}

