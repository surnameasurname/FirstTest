#include "drv_pwm.h"


/*!
    \brief      configure the GPIO ports
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_gpio_config(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_AF);

    /*Configure PA0 PA1 PA2(TIMER1 CH1 CH2) as alternate function*/
    gpio_init(GPIOA,GPIO_MODE_AF_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_1);
    gpio_init(GPIOA,GPIO_MODE_AF_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_2);
}

/*!
    \brief      configure the TIMER peripheral
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_timer_config(void)
{
    /* -----------------------------------------------------------------------
    TIMER1 configuration: generate 3 PWM signals with 3 different duty cycles:
    TIMER1CLK = SystemCoreClock / 120 = 1MHz

    TIMER1 channel0 duty cycle = (4000/ 16000)* 100  = 25%
    TIMER1 channel1 duty cycle = (8000/ 16000)* 100  = 50%
    TIMER1 channel2 duty cycle = (12000/ 16000)* 100 = 75%
    TIMER1 channel1 duty cycle = (4800/ 16000)* 100  = 30%
    
    
    
    TIMER1 channel0 duty cycle = (500/ 2000)* 100  = 25%
    TIMER1 channel1 duty cycle = (1000/ 2000)* 100  = 50%
    TIMER1 channel2 duty cycle = (1500/ 2000)* 100 = 75%
    TIMER1 channel1 duty cycle = (600/ 2000)* 100  = 30%
    ----------------------------------------------------------------------- */
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;

    rcu_periph_clock_enable(RCU_TIMER1);

    timer_deinit(TIMER1);

    /* TIMER1 configuration */
    timer_initpara.prescaler         = 119;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 1999;//15999;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1,&timer_initpara);

    /* CH0,CH1 and CH2 configuration in PWM mode */
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;

    timer_channel_output_config(TIMER1,TIMER_CH_1,&timer_ocintpara);
    timer_channel_output_config(TIMER1,TIMER_CH_2,&timer_ocintpara);

    /* CH1 configuration in PWM mode0,duty cycle 50% */
    //timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_1,4799);  //7999
    //timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_1,599);  //30%
    //timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_1,199);  //10%
    timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_1,399);  //20%
    //timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_1,599);  //30%
    //timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_1,1799);  //90%
    timer_channel_output_mode_config(TIMER1,TIMER_CH_1,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);

    /* CH2 configuration in PWM mode0,duty cycle 75% */
    //timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_2,11999);
    timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_2,1499);
    timer_channel_output_mode_config(TIMER1,TIMER_CH_2,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1,TIMER_CH_2,TIMER_OC_SHADOW_DISABLE);

    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER1);
    /* auto-reload preload enable */
    timer_enable(TIMER1);
}
