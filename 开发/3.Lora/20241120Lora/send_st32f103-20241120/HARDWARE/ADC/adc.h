#ifndef __ADC_H
#define __ADC_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板V3
//ADC 代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2015/1/14
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

#define ADC_CH1  1                  //通道1(连接在PA1)  
#define ADC_CH2  2
//#define ADC_CH1  1

void AdcInit(void);                 //ADC通道初始化
u16  Get_Adc(u8 ch);                //获得某个通道值
u16 GetAdcAverage(u8 ch, u16 times); //得到某个通道10次采样的平均值
#endif















