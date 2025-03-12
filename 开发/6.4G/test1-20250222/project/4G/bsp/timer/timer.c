#define __TIMER_C__

#include <gd32f30x.h>
#include "led.h"


//1�����һ���ж� int_time = CLK / (prescaler *clockdivision *  period)
//CLK = 60MHz
void timer1_init(void)
{
    timer_parameter_struct timer_parameter;

	rcu_periph_clock_enable(RCU_TIMER1);

	//Ԥ��Ƶ
    timer_parameter.prescaler = 2000,
    //����ģʽ
    timer_parameter.alignedmode = TIMER_COUNTER_EDGE,
    //��ʱ����������
    timer_parameter.counterdirection = TIMER_COUNTER_UP,
    //��ʱ���Զ�����ֵ
    timer_parameter.period = 60000,
    //ʱ�ӷ�Ƶֵ
    timer_parameter.clockdivision = TIMER_CKDIV_DIV1,

    timer_init(TIMER1, &timer_parameter);
   
    timer_interrupt_enable(TIMER1, TIMER_INT_UP);
    nvic_irq_enable(TIMER1_IRQn, 0, 2);
  
    timer_enable(TIMER1);
}


int flg = 0;
void TIMER1_IRQHandler()
{
    if (timer_interrupt_flag_get(TIMER1, TIMER_INT_UP) != RESET)
	{
			if(flg == 1)
			{
				flg = 0;
				led_on(1);
				led_on(2);
				led_on(3);
			}else{
				flg = 1;
				led_off(1);
				led_off(2);
				led_off(3);
			}
    	timer_interrupt_flag_clear(TIMER1, TIMER_INT_UP);
    }
}

