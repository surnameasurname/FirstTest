#ifndef _show5_h_
#define _show5_h_
#include "sys.h"

//读取算法灵敏度
void show_Sensitivity_uart5(void);
//设置算法灵敏度
void show_SetSensitivity_uart5(void);
//读取荧光信号本底值
void show_PmtFSignalBack_uart5(void);
//读取散射光信号本底值
void show_PdSSignalBack_uart5(void);
//设置档一比较电压
void show_SetComparisonVoltage1_uart5(void);
//读取档一比较电压
void show_ComparisonVoltage1_uart5(void);
//设置档二比较电压
void show_SetComparisonVoltage2_uart5(void);
//读取档二比较电压
void show_ComparisonVoltage2_uart5(void);
//设置档三比较电压
void show_SetComparisonVoltage3_uart5(void);
//读取档三比较电压
void show_ComparisonVoltage3_uart5(void);
//设置档四比较电压
void show_SetComparisonVoltage4_uart5(void);
//读取档四比较电压
void show_ComparisonVoltage4_uart5(void);
//设置档五比较电压
void show_SetComparisonVoltage5_uart5(void);
//读取档五比较电压
void show_ComparisonVoltage5_uart5(void);
//设置档六比较电压
void show_SetComparisonVoltage6_uart5(void);
//读取档六比较电压
void show_ComparisonVoltage6_uart5(void);
//设置档七比较电压
void show_SetComparisonVoltage7_uart5(void);
//读取档七比较电压
void show_ComparisonVoltage7_uart5(void);
//设置档八比较电压
void show_SetComparisonVoltage8_uart5(void);
//读取档八比较电压
void show_ComparisonVoltage8_uart5(void);



//发送关闭仪器
void show_monitor_close_uart5(void);
//发送开启仪器
void show_monitor_start_uart5(void);
//间断模式下，打开
void show_WorkMode_ON_uart5(void);
//间断模式下，关闭
void show_WorkMode_OFF_uart5(void);
void showAll_uart5(void);
#endif

