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
	//Ԥ��Ƶ 119
    timer_initpara.prescaler         = 119;
	//���ش���
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
	//װ��ֵ 500  CAR
    timer_initpara.period            = 500;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER2,&timer_initpara);

     /* CH1 configuration in PWM mode */
		//ʹ��ͨ�����
		timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
	 //����Ҫͨ������
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
	 //ͨ��������� Ϊ�ߵ�ƽ
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
	 //ͨ������������� �ߵ�ƽ
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
	 //ͨ���������״̬ �͵�ƽ
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
	 //ͨ�������������״̬ �͵�ƽ
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER4,TIMER_CH_1,&timer_ocintpara);

	//����TIMERͨ���������ֵ Ҳ���� CHX_CVֵ
    timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,250);
	//���ö�ʱ��ͨ��1-2���ΪPWMģʽ
    timer_channel_output_mode_config(TIMER4,TIMER_CH_1,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER4,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);
		
		timer_channel_output_mode_config(TIMER4,TIMER_CH_2,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER4,TIMER_CH_2,TIMER_OC_SHADOW_DISABLE);

    timer_primary_output_config(TIMER4,ENABLE);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER4);
    timer_enable(TIMER4);
}
