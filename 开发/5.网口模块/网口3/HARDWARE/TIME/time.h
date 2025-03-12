#ifndef _time_h_
#define _time_h_

#include "sys.h"

extern void TIM2_Int_Init(u16 arr,u16 psc); //定时器初始化
extern void TIM3_Int_Init(u16 arr,u16 psc); //定时器初始
extern u8 SendTime;

//信号定时器控制
//0,禁止；其他，开启
void Time3En(u8 time_contorl);
//信号定时器控制
//0,禁止；其他，开启
void Time2En(u8 time_contorl);
#endif

