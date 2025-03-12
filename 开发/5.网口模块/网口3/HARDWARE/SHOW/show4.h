#ifndef _show4_h_
#define _show4_h_
#include "sys.h"

//串口4初始化
void show_init_uart4(void);
//发送开机
void show_monitor_start_uart4(void);
//发送关机
void show_monitor_close_uart4(void);
//发送报警蜂鸣器开
void show_alarm_en_on_uart4(void);
//发送报警蜂鸣器开
void show_alarm_en_off_uart4(void);
//发送提示蜂鸣器开
void show_buzzer_en_on_uart4(void);
//发送提示蜂鸣器关
void show_buzzer_en_off_uart4(void);
//显示风扇开
void show_fan_on_uart4(void);
//显示风扇关
void show_fan_off_uart4(void);
//激光器开
void show_laser_on_uart4(void);
//激光器关
void show_laser_off_uart4(void);
//采样气泵开
void show_pump_on_uart4(void);
//采样气泵关
void show_pump_off_uart4(void);
//显示气路压力阈值低
void show_PressureFaultParameter_Low_uart4(void);
//显示气路压力阈值高
void show_PressureFaultParameter_High_uart4(void);
//显示设置气路压力阈值低
void show_setPressureFaultParameter_Low_uart4(void);
//显示设置气路压力阈值高
void show_setPressureFaultParameter_High_uart4(void);
//显示气路压力
void show_PneumaticPressure_uart4(void);
//设置激光器温度阈值
void show_LaserTemperatureParameter_uart4(void);
//读取设置激光器温度阈值
void show_setLaserTemperatureParameter_uart4(void);
//读取激光器温度值
void show_LaserTemperature_uart4(void);
//显示设置仪器激光器功率阈值低
void show_setLaserFaultParameter_Low_uart4(void);
//显示设置仪器激光器功率阈值高
void show_setLaserFaultParameter_High_uart4(void);
//显示仪器激光器功率阈值低
void show_LaserFaultParameter_Low_uart4(void);
//显示仪器激光器功率阈值高
void show_LaserFaultParameter_High_uart4(void);
//显示仪器激光器本底
void show_LaserBackground_uart4(void);
//显示设置仪器饱和阈值
void show_setSaturationParameter_uart4(void);
//显示仪器饱和阈值
void show_SaturationParameter_uart4(void);
//显示仪器饱和阈值
void show_SaturationValue_uart4(void);
//读取生物粒子报警值
void show_Biology_Alarm_uart4(void);
//读取设置生物粒子报警值
void show_SetBiology_Alarm_uart4(void);


//发送粒径档一比较电压
void show_PdsComparisonVoltage1_uart4(void);
//发送粒径档二比较电压
void show_PdsComparisonVoltage2_uart4(void);
//发送荧光档一比较电压
void show_PmtFComparisonVoltage1_uart4(void);
//发送荧光档二比较电压
void show_PmtFComparisonVoltage2_uart4(void);
//发送设置荧光档控制电压电阻
void show_PmtFResitor_uart4(void);
//发送散射光控制电压
void show_PmtFControlVoltage_uart4(void);
//发送设置气泵供电电压电阻
void show_PumpResitor_uart4(void);
//发送采样气泵供电电压
void show_PumpPowerVoltage_uart4(void);
//将数据发送给上位机
void ShowData_uart4(void);

//显示系统时间
void show_SysTime_uart4(void);
//显示设置时间
void show_SetSysTime_uart4(void);

//发送设置粒径档一比较电压
void show_SetPdsComparisonVoltage1_uart4(void);
//发送设置粒径档二比较电压
void show_SetPdsComparisonVoltage2_uart4(void);
//发送设置荧光档一比较电压
void show_SetPmtFComparisonVoltage1_uart4(void);
//发送设置荧光档二比较电压
void show_SetPmtFComparisonVoltage2_uart4(void);
//发送设置(设置荧光档控制电压电阻)
void show_SetPmtFResitor_uart4(void);
//发送设置(设置气泵供电电压电阻)
void show_SetPumpResitor_uart4(void);
//发送散射光信号本底值
void show_PdSSignalBack_uart4(void);
//发送荧光信号本底值
void show_PmtFSignalBack_uart4(void);

//发送运行周期
void show_WorkPeriod_uart4(void);
//发送设置运行周期
void show_SetWorkPeriod_uart4(void);
//发送显示周期
void show_CommunicationPeriod_uart4(void);
//发送设置显示周期
void show_SetCommunicationPeriod_uart4(void);
//发送所有数据
void showAll_uart4(void);
//显示仪器ID
void show_Equi_ID_uart4(void);
//设置仪器ID
void show_SetEqui_ID_uart4(void);

//报警蜂鸣器启用
void show_AlarmBuzzerEn_on_uart4(void);
//报警蜂鸣器未启用
void show_AlarmBuzzerEn_off_uart4(void);
//提示蜂鸣器启用
void show_BuzzerEn_on_uart4(void);
//提示蜂鸣器未启用
void show_BuzzerEn_off_uart4(void);

//生物粒子报警
void show_BiologyAlarm_uart4(void);
//饱和报警
void show_Saturation_ON_uart4(void);
//饱和未报警
void show_Saturation_OFF_uart4(void);
//激光器故障
void show_LaserFault_ON_uart4(void);
//激光器未故障
void show_LaserFault_OFF_uart4(void);
//气压故障
void show_PressureFault_ON_uart4(void);
//气压未故障
void show_PressureFault_OFF_uart4(void);

//主动推送数据
void show_PushState_on_uart4(void);
//不主动推送数据
void show_PushState_off_uart4(void);
//富集开启
void show_Enrichment_on_uart4(void);
//富集关闭
void show_Enrichment_off_uart4(void);

//富集启用
void show_EnrichmentEn_on_uart4(void);
//富集不启用
void show_EnrichmentEn_off_uart4(void);

//主动推送报警信息
void show_PushAlarmState_on_uart4(void);
//不主动推送报警信息
void show_PushAlarmState_off_uart4(void);
//主动推送故障信息
void show_PushFaultState_on_uart4(void);
//不主动推送故障信息
void show_PushFaultState_off_uart4(void);
//设置RTC的PLL值
void show_RTC_PLL_uart4(void);
//读取RTC的PLL值
void show_RTC_PLL_Read_uart4(void);
//设置富集采样时间阈值
void show_EnrichmentTimethreshold_uart4(void);
//读取富集采样时间阈值
void show_EnrichmentTimethreshold_Read_uart4(void);
//读取富集采样时间阈值
void show_EnrichmentTime_Read_uart4(void);

//电源未插入
void show_PowerIn_on_uart4(void);
//电源插入
void show_PowerIn_off_uart4(void);
//电源按键未按下
void show_PowerKey_on_uart4(void);
//电源按键按下
void show_PowerKey_off_uart4(void);
//电池电量
void show_PowerEnergy_uart4(void);
//设置算法灵敏度
void show_SetSensitivity_uart4(void);
//读取算法灵敏度
void show_Sensitivity_uart4(void);
#endif

