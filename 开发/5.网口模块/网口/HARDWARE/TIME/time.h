#ifndef _time_h_
#define _time_h_

#include "sys.h"

extern void TIM2_Int_Init(u16 arr,u16 psc); //��ʱ����ʼ��
extern void TIM3_Int_Init(u16 arr,u16 psc); //��ʱ����ʼ
extern u8 SendTime;

//�źŶ�ʱ������
//0,��ֹ������������
void Time3En(u8 time_contorl);
//�źŶ�ʱ������
//0,��ֹ������������
void Time2En(u8 time_contorl);
#endif

