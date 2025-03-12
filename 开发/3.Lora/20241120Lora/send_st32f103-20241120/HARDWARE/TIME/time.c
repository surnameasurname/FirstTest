#include "time.h"
#include "communication1.h"

u8 SendTime = 0;
//定时器2中断服务程序
void TIM2_IRQHandler(void)
{

    if (TIM2->SR & 0X0001) //溢出中断 ,modbus使用，一条指令接收完成
    {
        if (ModbusRx.ModbusReceDoneNum != 0) //不为0则开始累积
        {
            ModbusRx.ModbusReceDoneNum++;
        }
//      if(ModbusRx.ModbusReceDoneNum > 100)
//      {
//          ModbusRx.ModbusReceDoneNum=10;

//      }


    }
    TIM2->SR &= ~(1 << 0); //清除中断标志位
}
//通用定时器2中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void TIM2_Int_Init(u16 arr, u16 psc)
{
    RCC->APB1ENR |= 1 << 0;           //TIM2时钟使能
    TIM2->ARR = arr;                  //设定计数器自动重装值//刚好1ms
    TIM2->PSC = psc;                  //预分频器7200,得到10Khz的计数时钟
    TIM2->DIER |= 1 << 0;         //允许更新中断
    TIM2->CR1 &= ~(1 << 4);     //向上计数模式
    TIM2->CR1 |= (1 << 0);      //开启定时器二
    TIM2->CR1 |= (1 << 2);      //只有计数器溢出/下溢才产生更新中断或DMA请求
    MY_NVIC_Init(1, 2, TIM2_IRQn, 2); //组2
}

//定时器3中断服务程序
void TIM3_IRQHandler(void)
{
    if (TIM3->SR & 0X0001) //溢出中断
    {
        SendTime++;
    }
    TIM3->SR &= ~(1 << 0); //清除中断标志位
}
//通用定时器3中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void TIM3_Int_Init(u16 arr, u16 psc)
{
    RCC->APB1ENR |= 1 << 1;           //TIM3时钟使能
    TIM3->ARR = arr;                  //设定计数器自动重装值//刚好1ms
    TIM3->PSC = psc;                  //预分频器7200,得到10Khz的计数时钟
    TIM3->DIER |= 1 << 0;         //允许更新中断
    TIM3->CR1 &= ~(1 << 0);     //禁止定时器3
    MY_NVIC_Init(3, 2, TIM3_IRQn, 2); //抢占3，子优先级2，组2
}

//信号定时器控制
//0,禁止；其他，开启
void Time3En(u8 time_contorl)
{
    if (time_contorl == 0x00)
    {
        TIM3->CR1 &= ~(1 << 0);      //禁止定时器3
    }
    else
    {
        TIM3->CR1 |= (1 << 0);      //打开定时器3
    }
}

