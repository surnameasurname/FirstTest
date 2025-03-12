#include "timer.h"
#include "communication1.h"

/* 基本定时器5初始化函数
 * 参数：  psr:时钟预分频系数，预分频值=psr+1
           arr:自动重装载值，计数次数=arr+1
 * 返回值：无   */
uint8_t NumTest;                   //记录接收端   发送的时间
uint16_t Timcounter = 0;                   //记录接收端   发送的时间

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
    timer_initpara.prescaler         = 11999;//108M主频，分频后就是1M频率
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 9999;//1M频率，计数1000次，就是1ms
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
    /* 定义一个定时器初始化结构体 */
    timer_parameter_struct timer_init_struct;

    /* 开启定时器时钟 */
    rcu_periph_clock_enable(RCU_TIMER5);

    /* 初始化定时器 */
    timer_deinit(TIMER5);
    timer_init_struct.prescaler         = psr;  /* 预分频系数 */
    timer_init_struct.period            = arr;  /* 自动重装载值 */
    timer_init_struct.alignedmode       = TIMER_COUNTER_EDGE;   /* 计数器对齐模式，边沿对齐（定时器5无效）*/
    timer_init_struct.counterdirection  = TIMER_COUNTER_UP;     /* 计数器计数方向，向上（定时器5无效）*/
    timer_init_struct.clockdivision     = TIMER_CKDIV_DIV1;     /* DTS时间分频值（定时器5无效） */
    timer_init_struct.repetitioncounter = 0;                    /* 重复计数器的值（定时器5无效）*/
    timer_init(TIMER5, &timer_init_struct);

    /* Timer5中断设置，抢占优先级0，子优先级0 */
    nvic_irq_enable(TIMER5_IRQn, 1, 1);
    /* 使能Timer5更新中断 */
    timer_interrupt_enable(TIMER5, TIMER_INT_UP);
    /* 使能Timer5 */
    timer_enable(TIMER5);
}

void TIMER5_IRQHandler(void)
{
    if (timer_interrupt_flag_get(TIMER5, TIMER_INT_FLAG_UP))
    {
        /* 清除TIMER5 中断标志位 */
        timer_interrupt_flag_clear(TIMER5, TIMER_INT_FLAG_UP);
        if (ModbusRx.ModbusReceDoneNum != 0) //不为0则开始累积
        {
            ModbusRx.ModbusReceDoneNum++;
        }
    }
}

