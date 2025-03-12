#ifndef _show4_h_
#define _show4_h_
#include "sys.h"

//����4��ʼ��
void show_init_uart4(void);
//���Ϳ���
void show_monitor_start_uart4(void);
//���͹ػ�
void show_monitor_close_uart4(void);
//���ͱ�����������
void show_alarm_en_on_uart4(void);
//���ͱ�����������
void show_alarm_en_off_uart4(void);
//������ʾ��������
void show_buzzer_en_on_uart4(void);
//������ʾ��������
void show_buzzer_en_off_uart4(void);
//��ʾ���ȿ�
void show_fan_on_uart4(void);
//��ʾ���ȹ�
void show_fan_off_uart4(void);
//��������
void show_laser_on_uart4(void);
//��������
void show_laser_off_uart4(void);
//�������ÿ�
void show_pump_on_uart4(void);
//�������ù�
void show_pump_off_uart4(void);
//��ʾ��·ѹ����ֵ��
void show_PressureFaultParameter_Low_uart4(void);
//��ʾ��·ѹ����ֵ��
void show_PressureFaultParameter_High_uart4(void);
//��ʾ������·ѹ����ֵ��
void show_setPressureFaultParameter_Low_uart4(void);
//��ʾ������·ѹ����ֵ��
void show_setPressureFaultParameter_High_uart4(void);
//��ʾ��·ѹ��
void show_PneumaticPressure_uart4(void);
//���ü������¶���ֵ
void show_LaserTemperatureParameter_uart4(void);
//��ȡ���ü������¶���ֵ
void show_setLaserTemperatureParameter_uart4(void);
//��ȡ�������¶�ֵ
void show_LaserTemperature_uart4(void);
//��ʾ��������������������ֵ��
void show_setLaserFaultParameter_Low_uart4(void);
//��ʾ��������������������ֵ��
void show_setLaserFaultParameter_High_uart4(void);
//��ʾ����������������ֵ��
void show_LaserFaultParameter_Low_uart4(void);
//��ʾ����������������ֵ��
void show_LaserFaultParameter_High_uart4(void);
//��ʾ��������������
void show_LaserBackground_uart4(void);
//��ʾ��������������ֵ
void show_setSaturationParameter_uart4(void);
//��ʾ����������ֵ
void show_SaturationParameter_uart4(void);
//��ʾ����������ֵ
void show_SaturationValue_uart4(void);
//��ȡ�������ӱ���ֵ
void show_Biology_Alarm_uart4(void);
//��ȡ�����������ӱ���ֵ
void show_SetBiology_Alarm_uart4(void);


//����������һ�Ƚϵ�ѹ
void show_PdsComparisonVoltage1_uart4(void);
//�������������Ƚϵ�ѹ
void show_PdsComparisonVoltage2_uart4(void);
//����ӫ�⵵һ�Ƚϵ�ѹ
void show_PmtFComparisonVoltage1_uart4(void);
//����ӫ�⵵���Ƚϵ�ѹ
void show_PmtFComparisonVoltage2_uart4(void);
//��������ӫ�⵵���Ƶ�ѹ����
void show_PmtFResitor_uart4(void);
//����ɢ�����Ƶ�ѹ
void show_PmtFControlVoltage_uart4(void);
//�����������ù����ѹ����
void show_PumpResitor_uart4(void);
//���Ͳ������ù����ѹ
void show_PumpPowerVoltage_uart4(void);
//�����ݷ��͸���λ��
void ShowData_uart4(void);

//��ʾϵͳʱ��
void show_SysTime_uart4(void);
//��ʾ����ʱ��
void show_SetSysTime_uart4(void);

//��������������һ�Ƚϵ�ѹ
void show_SetPdsComparisonVoltage1_uart4(void);
//�����������������Ƚϵ�ѹ
void show_SetPdsComparisonVoltage2_uart4(void);
//��������ӫ�⵵һ�Ƚϵ�ѹ
void show_SetPmtFComparisonVoltage1_uart4(void);
//��������ӫ�⵵���Ƚϵ�ѹ
void show_SetPmtFComparisonVoltage2_uart4(void);
//��������(����ӫ�⵵���Ƶ�ѹ����)
void show_SetPmtFResitor_uart4(void);
//��������(�������ù����ѹ����)
void show_SetPumpResitor_uart4(void);
//����ɢ����źű���ֵ
void show_PdSSignalBack_uart4(void);
//����ӫ���źű���ֵ
void show_PmtFSignalBack_uart4(void);

//������������
void show_WorkPeriod_uart4(void);
//����������������
void show_SetWorkPeriod_uart4(void);
//������ʾ����
void show_CommunicationPeriod_uart4(void);
//����������ʾ����
void show_SetCommunicationPeriod_uart4(void);
//������������
void showAll_uart4(void);
//��ʾ����ID
void show_Equi_ID_uart4(void);
//��������ID
void show_SetEqui_ID_uart4(void);

//��������������
void show_AlarmBuzzerEn_on_uart4(void);
//����������δ����
void show_AlarmBuzzerEn_off_uart4(void);
//��ʾ����������
void show_BuzzerEn_on_uart4(void);
//��ʾ������δ����
void show_BuzzerEn_off_uart4(void);

//�������ӱ���
void show_BiologyAlarm_uart4(void);
//���ͱ���
void show_Saturation_ON_uart4(void);
//����δ����
void show_Saturation_OFF_uart4(void);
//����������
void show_LaserFault_ON_uart4(void);
//������δ����
void show_LaserFault_OFF_uart4(void);
//��ѹ����
void show_PressureFault_ON_uart4(void);
//��ѹδ����
void show_PressureFault_OFF_uart4(void);

//������������
void show_PushState_on_uart4(void);
//��������������
void show_PushState_off_uart4(void);
//��������
void show_Enrichment_on_uart4(void);
//�����ر�
void show_Enrichment_off_uart4(void);

//��������
void show_EnrichmentEn_on_uart4(void);
//����������
void show_EnrichmentEn_off_uart4(void);

//�������ͱ�����Ϣ
void show_PushAlarmState_on_uart4(void);
//���������ͱ�����Ϣ
void show_PushAlarmState_off_uart4(void);
//�������͹�����Ϣ
void show_PushFaultState_on_uart4(void);
//���������͹�����Ϣ
void show_PushFaultState_off_uart4(void);
//����RTC��PLLֵ
void show_RTC_PLL_uart4(void);
//��ȡRTC��PLLֵ
void show_RTC_PLL_Read_uart4(void);
//���ø�������ʱ����ֵ
void show_EnrichmentTimethreshold_uart4(void);
//��ȡ��������ʱ����ֵ
void show_EnrichmentTimethreshold_Read_uart4(void);
//��ȡ��������ʱ����ֵ
void show_EnrichmentTime_Read_uart4(void);

//��Դδ����
void show_PowerIn_on_uart4(void);
//��Դ����
void show_PowerIn_off_uart4(void);
//��Դ����δ����
void show_PowerKey_on_uart4(void);
//��Դ��������
void show_PowerKey_off_uart4(void);
//��ص���
void show_PowerEnergy_uart4(void);
//�����㷨������
void show_SetSensitivity_uart4(void);
//��ȡ�㷨������
void show_Sensitivity_uart4(void);
#endif

