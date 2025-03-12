#include "TIM.h"
#include "LED.h"
#include "uart.h"
/************************通用定时器2~5初始化************************/
//--TIMx---TIM2~TIM5
//--Tout-定时器溢出时间
#define TIMx_PSC 7199	//分频系数-=7199时，ms级定时；=71时，us级定时

void TIMx_Init(TIM_TypeDef* TIMx,u16 Tout)
{
	u16 arr=0;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue;
	NVIC_InitTypeDef NVIC_InitStructure;
//--使能TIMx外设时钟
	if(TIMx==TIM2)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	else if(TIMx==TIM3)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	else if(TIMx==TIM4)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	else if(TIMx==TIM5)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
//--定时器初始化
	if(TIMx_PSC==7199)		arr=Tout*10-1;	//ms级定时
	else if(TIMx_PSC==71) 	arr=Tout-1;		//us级定时
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1;		//设置时钟分割:TDTS = Tck_tim,
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up;	//计数器模式，向上，向下，向上/向下
	TIM_TimeBaseInitStrue.TIM_Period=arr;		//重装值
	TIM_TimeBaseInitStrue.TIM_Prescaler=TIMx_PSC;	//预分频系数
	TIM_TimeBaseInit(TIMx,&TIM_TimeBaseInitStrue);
//--使能TIM2中断
	TIM_ITConfig(TIMx,TIM_IT_Update,ENABLE);
//--NVIC分配
	if(TIMx==TIM2)
	{
		NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority=0; 
	}
	else if(TIMx==TIM3)
	{
		NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority=1; 
	}
	else if(TIMx==TIM4)
	{
		NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority=2; 
	}
	else if(TIMx==TIM5)
	{
		NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority=3; 
	}
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_Init(&NVIC_InitStructure);
	
//--使能定时器
	TIM_Cmd(TIMx,ENABLE);
}

/******定时器2中断服务程序*****/
void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update))
	{	
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);	//清中断
		if( Uart_dat.Receive_Byte_Flag )
		{
			Uart_dat.WaitTime++;
			if( Uart_dat.WaitTime > Uart_dat.WaitTime_Max )
				Uart_dat.Receive_OK = 1;
		}      
	}
}

/******定时器3中断服务程序*****/
void TIM3_IRQHandler()
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update))
	{	
		LED0=!LED0;
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);	//清中断
	}
}
/******定时器4中断服务程序*****/
void TIM4_IRQHandler()
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update))
	{	
		LED1=!LED1;
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);	//清中断
	}
}

/******定时器5中断服务程序*****/
void TIM5_IRQHandler()
{
	if(TIM_GetITStatus(TIM5,TIM_IT_Update))
	{	
		LED1=!LED1;
		TIM_ClearITPendingBit(TIM5,TIM_IT_Update);	//清中断
	}
}
