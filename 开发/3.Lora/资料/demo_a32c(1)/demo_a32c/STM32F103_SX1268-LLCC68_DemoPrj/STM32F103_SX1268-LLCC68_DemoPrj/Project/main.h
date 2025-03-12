#ifndef _MAIN_H_
#define _MAIN_H_

#include "LED.h"
#include "delay.h"
#include "uart.h"
#include "TIM.h"

#include "radio.h"

/** 发送模式定义 */
enum
{
	TX_MODE_1 = 0,		//发送模式1，发送固定的字符串
	TX_MODE_2			//发送模式2，发送串口接收到的数据
};

#endif
