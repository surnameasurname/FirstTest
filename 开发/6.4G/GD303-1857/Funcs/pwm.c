#include "pwm.h"


void gpio_pwm_config(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    
    /*Configure PA8(TIMER0_CH0) as alternate function*/
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1|GPIO_PIN_2);
}

//120MHz
void timer_CH2_3_pwm_config(void)
{
    /* TIMER0 configuration: generate PWM signals with different duty cycles:
       TIMER0CLK = SystemCoreClock / 120 = 1MHz */
    timer_oc_parameter_struct timer_ocintpara;
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
    timer_init(TIMER2,&timer_initpara);

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
	//设置定时器通道1-2输出为PWM模式
    timer_channel_output_mode_config(TIMER4,TIMER_CH_1,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER4,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);
		
		timer_channel_output_mode_config(TIMER4,TIMER_CH_2,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER4,TIMER_CH_2,TIMER_OC_SHADOW_DISABLE);

    timer_primary_output_config(TIMER4,ENABLE);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER4);
    timer_enable(TIMER4);
}
