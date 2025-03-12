#include "timer.h"
#include "communication1.h"

/* ������ʱ��5��ʼ������
 * ������  psr:ʱ��Ԥ��Ƶϵ����Ԥ��Ƶֵ=psr+1
           arr:�Զ���װ��ֵ����������=arr+1
 * ����ֵ����   */
uint8_t NumTest;                   //��¼���ն�   ���͵�ʱ��
uint16_t Timcounter = 0;                   //��¼���ն�   ���͵�ʱ��

extern uint16_t countnum;
extern uint16_t countnum1;
extern uint16_t countnum2;
void timer1_init(void)
{
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER1);
    timer_deinit(TIMER1);
    //timer_struct_para_init(&timer_initpara);

    /* TIMER1 configuration */
    timer_initpara.prescaler         = 11999;//108M��Ƶ����Ƶ�����1MƵ��
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 9999;//1MƵ�ʣ�����1000�Σ�����1ms
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1, &timer_initpara);
    //nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
    nvic_irq_enable(TIMER1_IRQn, 0, 1);
    timer_interrupt_enable(TIMER1, TIMER_INT_UP);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER1);
    /* auto-reload preload enable */
    timer_enable(TIMER1);

}

void TIMER1_IRQHandler(void)
{
    timer_flag_clear(TIMER1, TIMER_FLAG_UP);
    Timcounter++;
    if (Timcounter >= 8)//
    {
        NumTest++;
        Timcounter = 0;
    }

}



void timer5_init(uint32_t psr, uint32_t arr)
{
    /* ����һ����ʱ����ʼ���ṹ�� */
    timer_parameter_struct timer_init_struct;

    /* ������ʱ��ʱ�� */
    rcu_periph_clock_enable(RCU_TIMER5);

    /* ��ʼ����ʱ�� */
    timer_deinit(TIMER5);
    timer_init_struct.prescaler         = psr;  /* Ԥ��Ƶϵ�� */
    timer_init_struct.period            = arr;  /* �Զ���װ��ֵ */
    timer_init_struct.alignedmode       = TIMER_COUNTER_EDGE;   /* ����������ģʽ�����ض��루��ʱ��5��Ч��*/
    timer_init_struct.counterdirection  = TIMER_COUNTER_UP;     /* �����������������ϣ���ʱ��5��Ч��*/
    timer_init_struct.clockdivision     = TIMER_CKDIV_DIV1;     /* DTSʱ���Ƶֵ����ʱ��5��Ч�� */
    timer_init_struct.repetitioncounter = 0;                    /* �ظ���������ֵ����ʱ��5��Ч��*/
    timer_init(TIMER5, &timer_init_struct);

    /* Timer5�ж����ã���ռ���ȼ�0�������ȼ�0 */
    nvic_irq_enable(TIMER5_IRQn, 1, 1);
    /* ʹ��Timer5�����ж� */
    timer_interrupt_enable(TIMER5, TIMER_INT_UP);
    /* ʹ��Timer5 */
    timer_enable(TIMER5);
}

void TIMER5_IRQHandler(void)
{
    if (timer_interrupt_flag_get(TIMER5, TIMER_INT_FLAG_UP))
    {
        /* ���TIMER5 �жϱ�־λ */
        timer_interrupt_flag_clear(TIMER5, TIMER_INT_FLAG_UP);
        if (ModbusRx.ModbusReceDoneNum != 0) //��Ϊ0��ʼ�ۻ�
        {
            ModbusRx.ModbusReceDoneNum++;
        }
    }
}

