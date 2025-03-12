#include "show4.h"
#include "control.h"

//�������ID 
void show_ID_uart4(void);

//����4��ʼ��
void show_init_uart4(void)
{

}

//����������һ�Ƚϵ�ѹ
void show_PdsComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N067:");
//	send_uart4_string(DataChangeNumberToString(PdsComparisonVoltage1));
	send_uart4('*');
}
//�������������Ƚϵ�ѹ
void show_PdsComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N069:");
//	send_uart4_string(DataChangeNumberToString(PdsComparisonVoltage2));
	send_uart4('*');	
}
//����ӫ�⵵һ�Ƚϵ�ѹ
void show_PmtFComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N071:");
//	send_uart4_string(DataChangeNumberToString(PmtFComparisonVoltage1));
	send_uart4('*');
}
//����ӫ�⵵���Ƚϵ�ѹ
void show_PmtFComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N073:");
	//send_uart4_string(DataChangeNumberToString(PmtFComparisonVoltage2));
	send_uart4('*');	
}

//��������ӫ�⵵���Ƶ�ѹ����
void show_PmtFResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N084:");
	send_uart4_string(DataChangeNumberToString(PmtFResitor));
	send_uart4('*');		
}
//����ӫ����Ƶ�ѹ
void show_PmtFControlVoltage_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N086:");
	send_uart4_string(DataChangeNumberToString(PmtFControlVoltage));
	send_uart4('*');		
}

//�����������ù����ѹ����
void show_PumpResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N087:");
	send_uart4_string(DataChangeNumberToString(PumpResitor));
	send_uart4('*');	
}
//���Ͳ������ù����ѹ
void show_PumpPowerVoltage_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N089:");
	send_uart4_string(DataChangeNumberToString(PumpPowerVoltage));
	send_uart4('*');
}
//��ʾϵͳʱ��
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
//��ʾ����ʱ��
void show_SetSysTime_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N090*");	
}

//��������ID
void show_Equi_ID_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N063:");
	show_ID_uart4();
	send_uart4_string("*");
}
//��������ID
void show_SetEqui_ID_uart4(void)
{
		send_uart4_string("N062OK");
}

//�������ID 
void show_ID_uart4(void)
{
	send_uart4_string(Equipment_ID);
}


void show_all_uart4(void)
{
	
}


//�����ݷ��͸���λ��
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

//���Ϳ�������
void show_monitor_start_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N001OK*");	
}
//���͹ر�����
void show_monitor_close_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N002OK*");
}
//���ͱ�����������
void show_alarm_en_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N005OK*");
}
//���ͱ�����������
void show_alarm_en_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N006OK*");	
}

//������ʾ��������
void show_buzzer_en_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N007OK*");	
}
//������ʾ��������
void show_buzzer_en_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N008OK*");	
}

//��ʾ���ȿ�
void show_fan_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N009OK*");	
}
//��ʾ���ȹ�
void show_fan_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N010OK*");	
}
//��������
void show_laser_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N011OK*");	
}
//��������
void show_laser_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N012OK*");
}

//�������ÿ�
void show_pump_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N013OK*");
}
//�������ù�
void show_pump_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N014OK*");
}

//��ʾ������·ѹ����ֵ��
void show_setPressureFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N038*");
}
//��ʾ������·ѹ����ֵ��
void show_setPressureFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N039*");
}

//��ʾ��·ѹ����ֵ��
void show_PressureFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N040:");
	send_uart4_string(DataChangeNumberToString(PressureFaultParameter_Low));
	send_uart4_string("*");
}

//��ʾ��·ѹ����ֵ��
void show_PressureFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N041:");
	send_uart4_string(DataChangeNumberToString(PressureFaultParameter_High));
	send_uart4_string("*");
}

//��ʾ��·ѹ��
void show_PneumaticPressure_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N042:");
	send_uart4_string(DataChangeNumberToString(PneumaticPressure));
	send_uart4_string("*");
}

//��ȡ���ü������¶���ֵ
void show_setLaserTemperatureParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N044*");
}
//��ȡ�������¶���ֵ
void show_LaserTemperatureParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N046:");
	send_uart4_string(DataChangeNumberToString(LaserTemperatureParameter));
	send_uart4_string("*");
}
//��ȡ�������¶�ֵ
void show_LaserTemperature_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N047:");
	send_uart4_string(DataChangeNumberToString(LaserTemperature));
	send_uart4_string("*");
}

//��ʾ��������������������ֵ��
void show_setLaserFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N048*");
}
//��ʾ��������������������ֵ��
void show_setLaserFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N049*");
}
//��ʾ����������������ֵ��
void show_LaserFaultParameter_Low_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N050:");
	send_uart4_string(DataChangeNumberToString(LaserFaultParameter_Low));
	send_uart4_string("*");
}
//��ʾ����������������ֵ��
void show_LaserFaultParameter_High_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N051:");
	send_uart4_string(DataChangeNumberToString(LaserFaultParameter_High));
	send_uart4_string("*");
}

//��ʾ��������������ֵ
void show_setSaturationParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N054*");
}
//��ʾ����������ֵ
void show_SaturationParameter_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N056:");
	send_uart4_string(DataChangeNumberToString(SaturationParameter));
	send_uart4_string("*");
}

//��ʾ����������ֵ
void show_SaturationValue_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N057:");
	send_uart4_string(DataChangeNumberToString(SaturationValue));
	send_uart4_string("*");
}
//��ȡ�����������ӱ���ֵ
void show_SetBiology_Alarm_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N060*");
}
//��ȡ�������ӱ���ֵ
void show_Biology_Alarm_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N061:");
	send_uart4_string(DataChangeNumberToString(BiologyAlarmParameter));
	send_uart4_string("*");
}


//��ʾ��������������
void show_LaserBackground_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N052:");
	send_uart4_string(DataChangeNumberToString(LaserBackground));
	send_uart4_string("*");
}

//��������������һ�Ƚϵ�ѹ
void show_SetPdsComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N066OK*");
}
//�����������������Ƚϵ�ѹ
void show_SetPdsComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N068OK*");
}

//��������ӫ�⵵һ�Ƚϵ�ѹ
void show_SetPmtFComparisonVoltage1_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N070OK*");
}
//��������ӫ�⵵���Ƚϵ�ѹ
void show_SetPmtFComparisonVoltage2_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N072OK*");
}

//��������(����ӫ�⵵���Ƶ�ѹ����)
void show_SetPmtFResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N085OK*");
}

//��������(�������ù����ѹ����)
void show_SetPumpResitor_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N088OK*");
}
//����ɢ����źű���ֵ
void show_PdSSignalBack_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N080:");
	send_uart4_string(DataChangeNumberToString(PdSSignalBack));
	send_uart4_string("*");
}
//����ӫ���źű���ֵ
void show_PmtFSignalBack_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N081:");
	send_uart4_string(DataChangeNumberToString(PmtFSignalBack));
	send_uart4_string("*");
}
//������������
void show_WorkPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N031:");
	send_uart4_string(DataChangeNumberToString(WorkPeriod));
	send_uart4_string("*");
}
//����������������
void show_SetWorkPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N030OK*");
}
//������ʾ����
void show_CommunicationPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N035:");
	send_uart4_string(DataChangeNumberToString(CommunicationPeriod));
	send_uart4_string("*");
}
//����������ʾ����
void show_SetCommunicationPeriod_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N034OK*");
}
//������������
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
//��������������
void show_AlarmBuzzerEn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N102OK*");
}
//����������δ����
void show_AlarmBuzzerEn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N103OK*");
}
//��ʾ����������
void show_BuzzerEn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N104OK*");
}
//��ʾ������δ����
void show_BuzzerEn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N105OK*");
}
//�������ӱ���
void show_BiologyAlarm_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N095OK*");
}
//���ͱ���
void show_Saturation_ON_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N094OK*");
}
//����δ����
void show_Saturation_OFF_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N098OK*");
}

//����������
void show_LaserFault_ON_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N093OK*");	
}

//������δ����
void show_LaserFault_OFF_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N097OK*");	
}
//��ѹ����
void show_PressureFault_ON_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N092OK*");	
}
//��ѹδ����
void show_PressureFault_OFF_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N096OK*");	
}

//������������
void show_PushState_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N106OK*");	
}
//��������������
void show_PushState_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N107OK*");	
}
//��������
void show_Enrichment_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N003OK*");	
}
//�����ر�
void show_Enrichment_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N004OK*");	
}
//��������
void show_EnrichmentEn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N108OK*");	
}
//����������
void show_EnrichmentEn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N109OK*");	
}
//�������ͱ�����Ϣ
void show_PushAlarmState_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N110OK*");	
}
//���������ͱ�����Ϣ
void show_PushAlarmState_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N111OK*");
}
//�������͹�����Ϣ
void show_PushFaultState_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N112OK*");
}
//���������͹�����Ϣ
void show_PushFaultState_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N113OK*");
}
//����RTC��PLLֵ
void show_RTC_PLL_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N120OK*");	
}
//��ȡRTC��PLLֵ
void show_RTC_PLL_Read_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N121:");	
	send_uart4_string(DataChangeNumberToString(RtcPll));
	send_uart4_string("*");
}

//���ø�������ʱ����ֵ
void show_EnrichmentTimethreshold_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N115OK*");
}
//��ȡ��������ʱ����ֵ
void show_EnrichmentTimethreshold_Read_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N116:");	
	send_uart4_string(DataChangeNumberToString(EnrichmentTimethreshold));
	send_uart4_string("*");
}
//��ȡ��������ʱ��
void show_EnrichmentTime_Read_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N117:");	
	send_uart4_string(DataChangeNumberToString(EnrichmentTime));
	send_uart4_string("*");
}
//��Դδ����
void show_PowerIn_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N123OK*");
}
//��Դ����
void show_PowerIn_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N124OK*");	
}
//����δ����
void show_PowerKey_on_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N125OK*");
}
//��������
void show_PowerKey_off_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N126OK*");
}
//��ʾ��ص���
void show_PowerEnergy_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N127:");	
	send_uart4_string(DataChangeNumberToString(PowerEnergy));
	send_uart4_string("*");
}
//�����㷨������
void show_SetSensitivity_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N200OK*");
}
//��ȡ�㷨������
void show_Sensitivity_uart4(void)
{
	show_ID_uart4();
	send_uart4_string("N201:");	
	send_uart4_string(DataChangeNumberToString(Sensitivity));
	send_uart4_string("*");
}

