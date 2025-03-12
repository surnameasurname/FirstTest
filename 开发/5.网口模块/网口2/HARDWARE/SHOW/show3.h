#ifndef _show3_h_
#define _show3_h_
#include "sys.h"

//输出数据
void showData_1(void);
//输出数据
void showData1_1(void);
//输出数据
void showData_2(void);
//输出数据
void showData1_2(void);
//输出数据
void showData_3(void);
//输出数据
void showData1_3(void);
//输出数据
void showData_4(void);
//输出数据
void showData1_4(void);
//输出数据
void showData_5(void);
//输出数据
void showData1_5(void);
//输出数据
void showData_6(void);
//输出数据
void showData1_6(void);
//一键设置
void showSetAll(void);
//开机
void showOpen_uart3(void);
//关机
void showClose_uart3(void);
//设置地址
void showSetAddress_uart3(u8 r_data);
//调试开
void showSetDebugStateON(void);
//调试关
void showSetDebugStateOFF(void);
//设置波特率
void showSetBaudRate(u8 r_data);
void showSetBaudRate_1(u8 r_data);
void showSetBaudRate_2(u8 r_data);
void showSetBaudRate_3(u8 r_data);
void showSetBaudRate_4(u8 r_data);
void showSetBaudRate_5(u8 r_data);
void showSetBaudRate_6(u8 r_data);


//设置PWM
void showSetPumpPwm(u8 r_data);
//更新倒计时
void showSetUpdateCountdown(u8 r_data);
//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后
void showCommunicationCheck(u8 r_data);
//工作累加次数
void showCumulativeFrequency(u16 r_data);
//设置运行周期
void showSetWorkTime(u16 r_data);
//计数器当前计数累计时
void showReadAccumulatedTime(u16 r_data);
//通信校验
void showCommunicationCheck(u8 r_data);
//设置启动延时
void showSetWorkDelay(u16 r_data);
//设置档一比较电压
void showSetComparisonVoltage1(u16 r_data);
//设置档二比较电压
void showSetComparisonVoltage2(u16 r_data);
//设置档三比较电压
void showSetComparisonVoltage3(u16 r_data);
//设置档四比较电压
void showSetComparisonVoltage4(u16 r_data);
//设置档五比较电压
void showSetComparisonVoltage5(u16 r_data);
//设置档六比较电压
void showSetComparisonVoltage6(u16 r_data);
//设置档七比较电压
void showSetComparisonVoltage7(u16 r_data);
//设置档八比较电压
void showSetComparisonVoltage8(u16 r_data);
//气压阈值低
void showSetPressureLow(u16 r_data);
//气压阈值高
void showSetPressureHigh(u16 r_data);
//气路压力故障,0无故障，1过低，2过高
void showAirPressureState(u16 r_data);
//气压读数
void showAirPressureNub(u16 r_data);
//光源阈值
void showLightThreshold(u16 r_data);
//光源故障状态
void showLightState(u16 r_data);
//光源读数
void showLightReading(u16 r_data);
//饱和阈值
void showSaturationThreshold(u16 r_data);
//饱和状态
void showSaturationState(u16 r_data);
//0.3um  周期数据 低16位
void showData1Low(u32 r_data1);
//0.3um  周期数据 高16位
void showData1High(u32 r_data1);
//0.5um  周期数据 低16位
void showData2Low(u32 r_data1);
//0.5um  周期数据 高16位
void showData2High(u32 r_data1);
//1.0um  周期数据 低16位
void showData3Low(u32 r_data1);
//1.0um  周期数据 高16位
void showData3High(u32 r_data1);
//3.0um  周期数据 低16位
void showData4Low(u32 r_data1);
//3.0um  周期数据 高16位
void showData4High(u32 r_data1);
//5.0um  周期数据 低16位
void showData5Low(u32 r_data1);
//5.0um  周期数据 高16位
void showData5High(u32 r_data1);
//10.0um  周期数据 低16位
void showData6Low(u32 r_data1);
//10.0um  周期数据 高16位
void showData6High(u32 r_data1);
//饱和报警计数低16位
void showData7Low(u32 r_data1);
//饱和报警计数高16位
void showData7High(u32 r_data1);
//光源故障判断计数低16位
void showData8Low(u32 r_data1);
//光源故障判断计数高16位
void showData8High(u32 r_data1);
//气压阈值
void showSetPressureThreshold(u16 r_data);
//IP
void showSetIP(u16 r_data1,u16 r_data2,u16 r_data3,u16 r_data4);
//IP和端口的修改位
void showSetPort(u16 r_data);
//IP和端口的修改位
void showSetIPAndPort(u16 r_data);
//更新正计时
void showSetUpdateTiming(u16 r_data);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//0.1界面
//设置地址
void showSetAddress_uart3_1(u8 r_data);
//设置波特率
void showSetBaudRate_1(u8 r_data);
//开机
void showOpen_uart3_1(void);
//关机
void showClose_uart3_1(void);
//调试开
void showSetDebugStateON_1(void);
//调试关
void showSetDebugStateOFF_1(void);
//设置PWM
void showSetPumpPwm_1(u8 r_data);
//通信校验
void showCommunicationCheck_1(u8 r_data);
//气压阈值低
void showSetPressureLow_1(u16 r_data);
//气压阈值高
void showSetPressureHigh_1(u16 r_data);
//气泵电阻
void showSetAirPumpResistance_1(u16 r_data);
//设置工作时间
void showSetWorkTime_1(u16 r_data);
//设置启动延时
void showSetWorkDelay_1(u16 r_data);
//设置档一比较电压
void showSetComparisonVoltage1_1(u16 r_data);
//设置档二比较电压
void showSetComparisonVoltage2_1(u16 r_data);
//设置档三比较电压
void showSetComparisonVoltage3_1(u16 r_data);
//设置档四比较电压
void showSetComparisonVoltage4_1(u16 r_data);
//设置档五比较电压
void showSetComparisonVoltage5_1(u16 r_data);
//设置档六比较电压
void showSetComparisonVoltage6_1(u16 r_data);
//设置档七比较电压
void showSetComparisonVoltage7_1(u16 r_data);
//————————————————————————————————————————————————
//3.生物气溶胶

//设置地址
void showSetAddress_uart3_3(u8 r_data);
//波特率
void showSetBaudRate_3(u8 r_data);
//开机
void showOpen_uart3_3(void);
//关机
void showClose_uart3_3(void);
//调试开
void showSetDebugStateON_3(void);
//调试关
void showSetDebugStateOFF_3(void);

//________________________________________________________________
//5.高压0.1
void ShowLightFailureMeasurement(u16 r_data);
//温度阈值
void ShowTemperatureThreshold(u16 r_data);
//设定粒子通道数
void ShowSetNumberChannels(u16 r_data);
//采样间隔
void ShowSamplingInterval(u16 r_data);
//采样次数
void ShowSamplingFrequency(u16 r_data);
//设定流量
void ShowSetFlow(u16 r_data);
//设定气体系数
void ShowSetGasCoefficient(u16 r_data);
//PMT控制电压
void ShowPMTControlVoltage(u16 r_data);
//PMT电阻
void ShowPMTResistance(u16 r_data);
//气泵PWM
void ShowAirPumpPWM(u16 r_data);
//报警阈值
void ShowAlarmThreshold(u32 r_data1);
//报警阈值高
void ShowAlarmThresholdHigh(u16 r_data);
//报警阈值低
void ShowAlarmThresholdLow(u16 r_data);
//IP
void showSetIP_5(u16 r_data1,u16 r_data2,u16 r_data3,u16 r_data4);
//端口
void ShowPortData_5(u16 r_data);
//IP端口修改位
void ShowIPAndPortChange_5(u16 r_data);
//序列号1
void ShowSerialNumber1_5(u16 r_data);
//序列号2
void ShowSerialNumber2_5(u16 r_data);
//序列号3
void ShowSerialNumber3_5(u16 r_data);
//序列号4
void ShowSerialNumber4_5(u16 r_data);
//序列号5
void ShowSerialNumber5_5(u16 r_data);
//序列号6
void ShowSerialNumber6_5(u16 r_data);
//序列号7
void ShowSerialNumber7_5(u16 r_data);
//序列号8
void ShowSerialNumber8_5(u16 r_data);
//序列号设置
void ShowSetSerialNumber_5(u16 r_data);
//设定Modbus版本
void ShowSetModbusVersion(u16 r_data);
//设定设备版本号
void ShowSetDeviceVersion(u16 r_data);

//---------------------------------------------------------------


#endif

