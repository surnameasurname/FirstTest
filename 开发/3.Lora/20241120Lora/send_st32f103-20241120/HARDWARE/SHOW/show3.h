#ifndef _show3_h_
#define _show3_h_
#include "sys.h"

//�������
void showData_1(void);
//�������
void showData1_1(void);
//�������
void showData_2(void);
//�������
void showData1_2(void);
//�������
void showData_3(void);
//�������
void showData1_3(void);
//�������
void showData_4(void);
//�������
void showData1_4(void);
//�������
void showData_5(void);
//�������
void showData1_5(void);
//�������
void showData_6(void);
//�������
void showData1_6(void);
//һ������
void showSetAll(void);
//����
void showOpen_uart3(void);
//�ػ�
void showClose_uart3(void);
//���õ�ַ
void showSetAddress_uart3(u8 r_data);
//���Կ�
void showSetDebugStateON(void);
//���Թ�
void showSetDebugStateOFF(void);
//���ò�����
void showSetBaudRate(u8 r_data);
void showSetBaudRate_1(u8 r_data);
void showSetBaudRate_2(u8 r_data);
void showSetBaudRate_3(u8 r_data);
void showSetBaudRate_4(u8 r_data);
void showSetBaudRate_5(u8 r_data);
void showSetBaudRate_6(u8 r_data);


//����PWM
void showSetPumpPwm(u8 r_data);
//���µ���ʱ
void showSetUpdateCountdown(u8 r_data);
//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
void showCommunicationCheck(u8 r_data);
//�����ۼӴ���
void showCumulativeFrequency(u16 r_data);
//������������
void showSetWorkTime(u16 r_data);
//��������ǰ�����ۼ�ʱ
void showReadAccumulatedTime(u16 r_data);
//ͨ��У��
void showCommunicationCheck(u8 r_data);
//����������ʱ
void showSetWorkDelay(u16 r_data);
//���õ�һ�Ƚϵ�ѹ
void showSetComparisonVoltage1(u16 r_data);
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage2(u16 r_data);
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage3(u16 r_data);
//���õ��ıȽϵ�ѹ
void showSetComparisonVoltage4(u16 r_data);
//���õ���Ƚϵ�ѹ
void showSetComparisonVoltage5(u16 r_data);
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage6(u16 r_data);
//���õ��߱Ƚϵ�ѹ
void showSetComparisonVoltage7(u16 r_data);
//���õ��˱Ƚϵ�ѹ
void showSetComparisonVoltage8(u16 r_data);
//��ѹ��ֵ��
void showSetPressureLow(u16 r_data);
//��ѹ��ֵ��
void showSetPressureHigh(u16 r_data);
//��·ѹ������,0�޹��ϣ�1���ͣ�2����
void showAirPressureState(u16 r_data);
//��ѹ����
void showAirPressureNub(u16 r_data);
//��Դ��ֵ
void showLightThreshold(u16 r_data);
//��Դ����״̬
void showLightState(u16 r_data);
//��Դ����
void showLightReading(u16 r_data);
//������ֵ
void showSaturationThreshold(u16 r_data);
//����״̬
void showSaturationState(u16 r_data);
//0.3um  �������� ��16λ
void showData1Low(u32 r_data1);
//0.3um  �������� ��16λ
void showData1High(u32 r_data1);
//0.5um  �������� ��16λ
void showData2Low(u32 r_data1);
//0.5um  �������� ��16λ
void showData2High(u32 r_data1);
//1.0um  �������� ��16λ
void showData3Low(u32 r_data1);
//1.0um  �������� ��16λ
void showData3High(u32 r_data1);
//3.0um  �������� ��16λ
void showData4Low(u32 r_data1);
//3.0um  �������� ��16λ
void showData4High(u32 r_data1);
//5.0um  �������� ��16λ
void showData5Low(u32 r_data1);
//5.0um  �������� ��16λ
void showData5High(u32 r_data1);
//10.0um  �������� ��16λ
void showData6Low(u32 r_data1);
//10.0um  �������� ��16λ
void showData6High(u32 r_data1);
//���ͱ���������16λ
void showData7Low(u32 r_data1);
//���ͱ���������16λ
void showData7High(u32 r_data1);
//��Դ�����жϼ�����16λ
void showData8Low(u32 r_data1);
//��Դ�����жϼ�����16λ
void showData8High(u32 r_data1);
//��ѹ��ֵ
void showSetPressureThreshold(u16 r_data);
//IP
void showSetIP(u16 r_data1,u16 r_data2,u16 r_data3,u16 r_data4);
//IP�Ͷ˿ڵ��޸�λ
void showSetPort(u16 r_data);
//IP�Ͷ˿ڵ��޸�λ
void showSetIPAndPort(u16 r_data);
//��������ʱ
void showSetUpdateTiming(u16 r_data);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//0.1����
//���õ�ַ
void showSetAddress_uart3_1(u8 r_data);
//���ò�����
void showSetBaudRate_1(u8 r_data);
//����
void showOpen_uart3_1(void);
//�ػ�
void showClose_uart3_1(void);
//���Կ�
void showSetDebugStateON_1(void);
//���Թ�
void showSetDebugStateOFF_1(void);
//����PWM
void showSetPumpPwm_1(u8 r_data);
//ͨ��У��
void showCommunicationCheck_1(u8 r_data);
//��ѹ��ֵ��
void showSetPressureLow_1(u16 r_data);
//��ѹ��ֵ��
void showSetPressureHigh_1(u16 r_data);
//���õ���
void showSetAirPumpResistance_1(u16 r_data);
//���ù���ʱ��
void showSetWorkTime_1(u16 r_data);
//����������ʱ
void showSetWorkDelay_1(u16 r_data);
//���õ�һ�Ƚϵ�ѹ
void showSetComparisonVoltage1_1(u16 r_data);
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage2_1(u16 r_data);
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage3_1(u16 r_data);
//���õ��ıȽϵ�ѹ
void showSetComparisonVoltage4_1(u16 r_data);
//���õ���Ƚϵ�ѹ
void showSetComparisonVoltage5_1(u16 r_data);
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage6_1(u16 r_data);
//���õ��߱Ƚϵ�ѹ
void showSetComparisonVoltage7_1(u16 r_data);
//������������������������������������������������������������������������������������������������
//3.�������ܽ�

//���õ�ַ
void showSetAddress_uart3_3(u8 r_data);
//������
void showSetBaudRate_3(u8 r_data);
//����
void showOpen_uart3_3(void);
//�ػ�
void showClose_uart3_3(void);
//���Կ�
void showSetDebugStateON_3(void);
//���Թ�
void showSetDebugStateOFF_3(void);

//________________________________________________________________
//5.��ѹ0.1
void ShowLightFailureMeasurement(u16 r_data);
//�¶���ֵ
void ShowTemperatureThreshold(u16 r_data);
//�趨����ͨ����
void ShowSetNumberChannels(u16 r_data);
//�������
void ShowSamplingInterval(u16 r_data);
//��������
void ShowSamplingFrequency(u16 r_data);
//�趨����
void ShowSetFlow(u16 r_data);
//�趨����ϵ��
void ShowSetGasCoefficient(u16 r_data);
//PMT���Ƶ�ѹ
void ShowPMTControlVoltage(u16 r_data);
//PMT����
void ShowPMTResistance(u16 r_data);
//����PWM
void ShowAirPumpPWM(u16 r_data);
//������ֵ
void ShowAlarmThreshold(u32 r_data1);
//������ֵ��
void ShowAlarmThresholdHigh(u16 r_data);
//������ֵ��
void ShowAlarmThresholdLow(u16 r_data);
//IP
void showSetIP_5(u16 r_data1,u16 r_data2,u16 r_data3,u16 r_data4);
//�˿�
void ShowPortData_5(u16 r_data);
//IP�˿��޸�λ
void ShowIPAndPortChange_5(u16 r_data);
//���к�1
void ShowSerialNumber1_5(u16 r_data);
//���к�2
void ShowSerialNumber2_5(u16 r_data);
//���к�3
void ShowSerialNumber3_5(u16 r_data);
//���к�4
void ShowSerialNumber4_5(u16 r_data);
//���к�5
void ShowSerialNumber5_5(u16 r_data);
//���к�6
void ShowSerialNumber6_5(u16 r_data);
//���к�7
void ShowSerialNumber7_5(u16 r_data);
//���к�8
void ShowSerialNumber8_5(u16 r_data);
//���к�����
void ShowSetSerialNumber_5(u16 r_data);
//�趨Modbus�汾
void ShowSetModbusVersion(u16 r_data);
//�趨�豸�汾��
void ShowSetDeviceVersion(u16 r_data);

//---------------------------------------------------------------


#endif

