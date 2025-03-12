#include "TIM.h"
#include "LED.h"
#include "uart.h"
/************************ͨ�ö�ʱ��2~5��ʼ��************************/
//--TIMx---TIM2~TIM5
//--Tout-��ʱ�����ʱ��
#define TIMx_PSC 7199	//��Ƶϵ��-=7199ʱ��ms����ʱ��=71ʱ��us����ʱ

void TIMx_Init(TIM_TypeDef* TIMx,u16 Tout)
{
	u16 arr=0;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue;
	NVIC_InitTypeDef NVIC_InitStructure;
//--ʹ��TIMx����ʱ��
	if(TIMx==TIM2)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	else if(TIMx==TIM3)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	else if(TIMx==TIM4)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	else if(TIMx==TIM5)
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
//--��ʱ����ʼ��
	if(TIMx_PSC==7199)		arr=Tout*10-1;	//ms����ʱ
	else if(TIMx_PSC==71) 	arr=Tout-1;		//us����ʱ
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1;		//����ʱ�ӷָ�:TDTS = Tck_tim,
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up;	//������ģʽ�����ϣ����£�����/����
	TIM_TimeBaseInitStrue.TIM_Period=arr;		//��װֵ
	TIM_TimeBaseInitStrue.TIM_Prescaler=TIMx_PSC;	//Ԥ��Ƶϵ��
	TIM_TimeBaseInit(TIMx,&TIM_TimeBaseInitStrue);
//--ʹ��TIM2�ж�
	TIM_ITConfig(TIMx,TIM_IT_Update,ENABLE);
//--NVIC����
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
	
//--ʹ�ܶ�ʱ��
	TIM_Cmd(TIMx,ENABLE);
}

/******��ʱ��2�жϷ������*****/
void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update))
	{	
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);	//���ж�
		if( Uart_dat.Receive_Byte_Flag )
		{
			Uart_dat.WaitTime++;
			if( Uart_dat.WaitTime > Uart_dat.WaitTime_Max )
				Uart_dat.Receive_OK = 1;
		}      
	}
}

/******��ʱ��3�жϷ������*****/
void TIM3_IRQHandler()
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update))
	{	
		LED0=!LED0;
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);	//���ж�
	}
}
/******��ʱ��4�жϷ������*****/
void TIM4_IRQHandler()
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update))
	{	
		LED1=!LED1;
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);	//���ж�
	}
}

/******��ʱ��5�жϷ������*****/
void TIM5_IRQHandler()
{
	if(TIM_GetITStatus(TIM5,TIM_IT_Update))
	{	
		LED1=!LED1;
		TIM_ClearITPendingBit(TIM5,TIM_IT_Update);	//���ж�
	}
}
