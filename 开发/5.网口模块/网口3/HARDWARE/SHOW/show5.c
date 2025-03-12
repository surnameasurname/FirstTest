#include "show5.h"
#include "uart.h"
#include "DataChange.h"
#include "equipment.h"

//发送开启仪器
void show_monitor_start_uart5(void)
{
	send_uart5_string("N001*");	
}
//发送关闭仪器
void show_monitor_close_uart5(void)
{
	send_uart5_string("N002*");
}


//设置档一比较电压
void show_SetComparisonVoltage1_uart5(void)
{
	send_uart5_string("N202:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage1));
	send_uart5('*');
}	
//读取档一比较电压
void show_ComparisonVoltage1_uart5(void)
{
	send_uart5_string("N203*");
}

//设置档二比较电压
void show_SetComparisonVoltage2_uart5(void)
{
	send_uart5_string("N204:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage2));
	send_uart5('*');	
}
//读取档二比较电压
void show_ComparisonVoltage2_uart5(void)
{
	send_uart5_string("N205*");
}
//设置档三比较电压
void show_SetComparisonVoltage3_uart5(void)
{
	send_uart5_string("N206:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage3));
	send_uart5('*');	
}
//读取档三比较电压
void show_ComparisonVoltage3_uart5(void)
{
	send_uart5_string("N207*");
}//设置档四比较电压
void show_SetComparisonVoltage4_uart5(void)
{
	send_uart5_string("N208:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage4));
	send_uart5('*');	
}
//读取档四比较电压
void show_ComparisonVoltage4_uart5(void)
{
	send_uart5_string("N209*");
}
//设置档五比较电压
void show_SetComparisonVoltage5_uart5(void)
{
	send_uart5_string("N210:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage5));
	send_uart5('*');	
}
//读取档五比较电压
void show_ComparisonVoltage5_uart5(void)
{
	send_uart5_string("N211*");
}
//设置档六比较电压
void show_SetComparisonVoltage6_uart5(void)
{
	send_uart5_string("N212:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage6));
	send_uart5('*');	
}
//读取档六比较电压
void show_ComparisonVoltage6_uart5(void)
{
	send_uart5_string("N213*");
}
//设置档七比较电压
void show_SetComparisonVoltage7_uart5(void)
{
	send_uart5_string("N214:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage7));
	send_uart5('*');	
}
//读取档七比较电压
void show_ComparisonVoltage7_uart5(void)
{
	send_uart5_string("N215*");
}
//设置档八比较电压
void show_SetComparisonVoltage8_uart5(void)
{
	send_uart5_string("N216:");
	send_uart5_string(DataChangeNumberToString(ComparisonVoltage8));
	send_uart5('*');	
}
//读取档八比较电压
void show_ComparisonVoltage8_uart5(void)
{
	send_uart5_string("N217*");
}


//设置算法灵敏度
void show_SetSensitivity_uart5(void)
{
	send_uart5_string("N200:");
	send_uart5_string(DataChangeNumberToString(Sensitivity));
	send_uart5_string("*");
}
//读取算法灵敏度
void show_Sensitivity_uart5(void)
{
	send_uart5_string("N201*");
}

//间断模式下，打开
void show_WorkMode_ON_uart5(void)
{
	send_uart5_string("N203*");
}
//间断模式下，关闭
void show_WorkMode_OFF_uart5(void)
{
	send_uart5_string("N202*");
}
void showAll_uart5(void)
{
	send_uart5_string("N888*");
}


