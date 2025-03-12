#include "show4.h"
#include "control.h"

//输出仪器ID 
void show_ID_uart4(void);

//串口4初始化
void show_init_uart4(void)
{

}

//发送粒径档一比较电压
void show_PdsComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N067:");
//	send_uart4_string(DataChangeNumberToString(PdsComparisonVoltage1));
	send_uart4('*');
}
//发送粒径档二比较电压
void show_PdsComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N069:");
//	send_uart4_string(DataChangeNumberToString(PdsComparisonVoltage2));
	send_uart4('*');	
}
//发送荧光档一比较电压
void show_PmtFComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N071:");
//	send_uart4_string(DataChangeNumberToString(PmtFComparisonVoltage1));
	send_uart4('*');
}
//发送荧光档二比较电压
void show_PmtFComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N073:");
	//send_uart4_string(DataChangeNumberToString(PmtFComparisonVoltage2));
	send_uart4('*');	
}

//发送设置荧光档控制电压电阻
void show_PmtFResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N084:");
	send_uart4_string(DataChangeNumberToString(PmtFResitor));
	send_uart4('*');		
}
//发送荧光控制电压
void show_PmtFControlVoltage_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N086:");
	send_uart4_string(DataChangeNumberToString(PmtFControlVoltage));
	send_uart4('*');		
}

//发送设置气泵供电电压电阻
void show_PumpResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N087:");
	send_uart4_string(DataChangeNumberToString(PumpResitor));
	send_uart4('*');	
}
//发送采样气泵供电电压
void show_PumpPowerVoltage_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N089:");
	send_uart4_string(DataChangeNumberToString(PumpPowerVoltage));
	send_uart4('*');
}
//显示系统时间
void show_SysTime_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N091:");
	send_uart4_string(DataChangeNumberToString(Sys_Second));
	send_uart4(',');
	send_uart4_string(DataChangeNumberToString(Sys_Minute));
	send_uart4(',');
	send_uart4_string(DataChangeNumberToString(Sys_Hour));
	send_uart4(',');
	send_uart4_string(DataChangeNumberToString(Sys_Date));
	send_uart4(',');
	send_uart4_string(DataChangeNumberToString(Sys_Month));
	send_uart4(',');
	send_uart4_string(DataChangeNumberToString(SYs_Year));
	send_uart4(';');
	send_uart4('*');	
}
//显示设置时间
void show_SetSysTime_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N090*");	
}

//发送仪器ID
void show_Equi_ID_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N063:");
	show_ID_uart4();
	send_uart4_string("*");
}
//设置仪器ID
void show_SetEqui_ID_uart4(void)
{
		send_uart4_string("N062OK");
}

//输出仪器ID 
void show_ID_uart4(void)
{
	send_uart4_string(Equipment_ID);
}


void show_all_uart4(void)
{
	
}


//将数据发送给上位机
void ShowData_uart4(void)
{
	send_uart4_string(Equipment_ID);
	send_uart4_string("N064:");
	send_uart4_string(DataChangeNumberToString(Particle1));
	send_uart4(',');  
	send_uart4_string(DataChangeNumberToString(Particle2));	
	send_uart4(','); 	
	send_uart4_string(DataChangeNumberToString(Fluorescence1));	
	send_uart4(','); 
	send_uart4_string(DataChangeNumberToString(Fluorescence2));	
	send_uart4(','); 
	send_uart4_string(DataChangeNumberToString(Biology1));	
	send_uart4(','); 
	send_uart4_string(DataChangeNumberToString(Biology2));	
	send_uart4_string(";*");
	/**********************************************************************/	
}

//发送开启仪器
void show_monitor_start_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N001OK*");	
}
//发送关闭仪器
void show_monitor_close_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N002OK*");
}
//发送报警蜂鸣器开
void show_alarm_en_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N005OK*");
}
//发送报警蜂鸣器开
void show_alarm_en_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N006OK*");	
}

//发送提示蜂鸣器开
void show_buzzer_en_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N007OK*");	
}
//发送提示蜂鸣器关
void show_buzzer_en_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N008OK*");	
}

//显示风扇开
void show_fan_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N009OK*");	
}
//显示风扇关
void show_fan_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N010OK*");	
}
//激光器开
void show_laser_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N011OK*");	
}
//激光器关
void show_laser_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N012OK*");
}

//采样气泵开
void show_pump_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N013OK*");
}
//采样气泵关
void show_pump_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N014OK*");
}

//显示设置气路压力阈值低
void show_setPressureFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N038*");
}
//显示设置气路压力阈值高
void show_setPressureFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N039*");
}

//显示气路压力阈值低
void show_PressureFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N040:");
	send_uart4_string(DataChangeNumberToString(PressureFaultParameter_Low));
	send_uart4_string("*");
}

//显示气路压力阈值高
void show_PressureFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N041:");
	send_uart4_string(DataChangeNumberToString(PressureFaultParameter_High));
	send_uart4_string("*");
}

//显示气路压力
void show_PneumaticPressure_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N042:");
	send_uart4_string(DataChangeNumberToString(PneumaticPressure));
	send_uart4_string("*");
}

//读取设置激光器温度阈值
void show_setLaserTemperatureParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N044*");
}
//读取激光器温度阈值
void show_LaserTemperatureParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N046:");
	send_uart4_string(DataChangeNumberToString(LaserTemperatureParameter));
	send_uart4_string("*");
}
//读取激光器温度值
void show_LaserTemperature_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N047:");
	send_uart4_string(DataChangeNumberToString(LaserTemperature));
	send_uart4_string("*");
}

//显示设置仪器激光器功率阈值低
void show_setLaserFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N048*");
}
//显示设置仪器激光器功率阈值高
void show_setLaserFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N049*");
}
//显示仪器激光器功率阈值低
void show_LaserFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N050:");
	send_uart4_string(DataChangeNumberToString(LaserFaultParameter_Low));
	send_uart4_string("*");
}
//显示仪器激光器功率阈值高
void show_LaserFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N051:");
	send_uart4_string(DataChangeNumberToString(LaserFaultParameter_High));
	send_uart4_string("*");
}

//显示设置仪器饱和阈值
void show_setSaturationParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N054*");
}
//显示仪器饱和阈值
void show_SaturationParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N056:");
	send_uart4_string(DataChangeNumberToString(SaturationParameter));
	send_uart4_string("*");
}

//显示仪器饱和阈值
void show_SaturationValue_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N057:");
	send_uart4_string(DataChangeNumberToString(SaturationValue));
	send_uart4_string("*");
}
//读取设置生物粒子报警值
void show_SetBiology_Alarm_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N060*");
}
//读取生物粒子报警值
void show_Biology_Alarm_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N061:");
	send_uart4_string(DataChangeNumberToString(BiologyAlarmParameter));
	send_uart4_string("*");
}


//显示仪器激光器本底
void show_LaserBackground_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N052:");
	send_uart4_string(DataChangeNumberToString(LaserBackground));
	send_uart4_string("*");
}

//发送设置粒径档一比较电压
void show_SetPdsComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N066OK*");
}
//发送设置粒径档二比较电压
void show_SetPdsComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N068OK*");
}

//发送设置荧光档一比较电压
void show_SetPmtFComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N070OK*");
}
//发送设置荧光档二比较电压
void show_SetPmtFComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N072OK*");
}

//发送设置(设置荧光档控制电压电阻)
void show_SetPmtFResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N085OK*");
}

//发送设置(设置气泵供电电压电阻)
void show_SetPumpResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N088OK*");
}
//发送散射光信号本底值
void show_PdSSignalBack_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N080:");
	send_uart4_string(DataChangeNumberToString(PdSSignalBack));
	send_uart4_string("*");
}
//发送荧光信号本底值
void show_PmtFSignalBack_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N081:");
	send_uart4_string(DataChangeNumberToString(PmtFSignalBack));
	send_uart4_string("*");
}
//发送运行周期
void show_WorkPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N031:");
	send_uart4_string(DataChangeNumberToString(WorkPeriod));
	send_uart4_string("*");
}
//发送设置运行周期
void show_SetWorkPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N030OK*");
}
//发送显示周期
void show_CommunicationPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N035:");
	send_uart4_string(DataChangeNumberToString(CommunicationPeriod));
	send_uart4_string("*");
}
//发送设置显示周期
void show_SetCommunicationPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N034OK*");
}
//发送所有数据
void showAll_uart4(void)
{
	show_Equi_ID_uart4();
	show_PdsComparisonVoltage1_uart4();
	show_PdsComparisonVoltage2_uart4();
	show_PmtFComparisonVoltage1_uart4();
	show_PmtFComparisonVoltage2_uart4();
	show_PmtFResitor_uart4();
	show_PmtFControlVoltage_uart4();
	show_PumpResitor_uart4();
	show_PumpPowerVoltage_uart4();
	show_SysTime_uart4();
	show_PdSSignalBack_uart4();
	show_PmtFSignalBack_uart4();
	show_WorkPeriod_uart4();
	show_CommunicationPeriod_uart4();
	show_Biology_Alarm_uart4();
	show_PressureFaultParameter_Low_uart4();
	show_PressureFaultParameter_High_uart4();
	show_LaserBackground_uart4();
	show_SaturationValue_uart4();
	show_SaturationParameter_uart4();
	show_LaserFaultParameter_High_uart4();
	show_LaserFaultParameter_Low_uart4();
	show_LaserTemperature_uart4();
	show_LaserTemperatureParameter_uart4();
	show_PneumaticPressure_uart4();
	show_EnrichmentTimethreshold_Read_uart4();
	show_RTC_PLL_Read_uart4();
	show_Sensitivity_uart4();
	
}
//报警蜂鸣器启用
void show_AlarmBuzzerEn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N102OK*");
}
//报警蜂鸣器未启用
void show_AlarmBuzzerEn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N103OK*");
}
//提示蜂鸣器启用
void show_BuzzerEn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N104OK*");
}
//提示蜂鸣器未启用
void show_BuzzerEn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N105OK*");
}
//生物粒子报警
void show_BiologyAlarm_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N095OK*");
}
//饱和报警
void show_Saturation_ON_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N094OK*");
}
//饱和未报警
void show_Saturation_OFF_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N098OK*");
}

//激光器故障
void show_LaserFault_ON_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N093OK*");	
}

//激光器未故障
void show_LaserFault_OFF_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N097OK*");	
}
//气压故障
void show_PressureFault_ON_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N092OK*");	
}
//气压未故障
void show_PressureFault_OFF_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N096OK*");	
}

//主动推送数据
void show_PushState_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N106OK*");	
}
//不主动推送数据
void show_PushState_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N107OK*");	
}
//富集开启
void show_Enrichment_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N003OK*");	
}
//富集关闭
void show_Enrichment_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N004OK*");	
}
//富集启用
void show_EnrichmentEn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N108OK*");	
}
//富集不启用
void show_EnrichmentEn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N109OK*");	
}
//主动推送报警信息
void show_PushAlarmState_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N110OK*");	
}
//不主动推送报警信息
void show_PushAlarmState_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N111OK*");
}
//主动推送故障信息
void show_PushFaultState_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N112OK*");
}
//不主动推送故障信息
void show_PushFaultState_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N113OK*");
}
//设置RTC的PLL值
void show_RTC_PLL_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N120OK*");	
}
//读取RTC的PLL值
void show_RTC_PLL_Read_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N121:");	
	send_uart4_string(DataChangeNumberToString(RtcPll));
	send_uart4_string("*");
}

//设置富集采样时间阈值
void show_EnrichmentTimethreshold_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N115OK*");
}
//读取富集采样时间阈值
void show_EnrichmentTimethreshold_Read_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N116:");	
	send_uart4_string(DataChangeNumberToString(EnrichmentTimethreshold));
	send_uart4_string("*");
}
//读取富集采样时间
void show_EnrichmentTime_Read_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N117:");	
	send_uart4_string(DataChangeNumberToString(EnrichmentTime));
	send_uart4_string("*");
}
//电源未插入
void show_PowerIn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N123OK*");
}
//电源插入
void show_PowerIn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N124OK*");	
}
//按键未按下
void show_PowerKey_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N125OK*");
}
//按键按下
void show_PowerKey_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N126OK*");
}
//显示电池电量
void show_PowerEnergy_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N127:");	
	send_uart4_string(DataChangeNumberToString(PowerEnergy));
	send_uart4_string("*");
}
//设置算法灵敏度
void show_SetSensitivity_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N200OK*");
}
//读取算法灵敏度
void show_Sensitivity_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N201:");	
	send_uart4_string(DataChangeNumberToString(Sensitivity));
	send_uart4_string("*");
}

