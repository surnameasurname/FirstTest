#ifndef __communication1_h_
#define __communication1_h_

#include "sys.h"


#define MoubusReceArrLength	250			//接收数组长度
#define ModbusReceOrderMinLength			//接收数组最小长度

//支持的modebus指令
#define ModbusOrder_03		0x03									//modbus通信03号命令
#define ModbusOrder_06		0x06									//modbus通信06号命令
#define ModbusOrder_16		0x10									//modbus通信16号命令

#define  ModbusBroadcastAddress			252		//广播地址，通用设备号

extern u8 DataReceive[250];
extern u8 DataReceive6[20];
//modbus帧定义
typedef struct
{ 
	u8 EquipmentNum;													//设备号
	u8 ModbusOrder;														//功能码，0~255
	u16 StartAddress;													//开始地址
	u16 RegisterNum;													//寄存器数量
	u16 Txlen;																//数据长度
	u8 Txbuf[MoubusReceArrLength];						//发送缓冲区
	u16 CrcData;															//校验值 
}ModbusSend_typedef;
extern ModbusSend_typedef ModbusTx;					//Modbus发送

//类modbus协议管理器
typedef  struct
{ 
	u8 EquipmentNum;													//设备号
	u8 ModbusOrder;														//功能码
	u16 StartAddress;													//开始地址
	u16 RegisterNum;													//寄存器数量
	u8 Rxbuf[MoubusReceArrLength];						//接收缓冲区
	u8 Rxlen;																//接收数据的长度
	u8 ModbusReceDoneNum;											//大于等于3数据接收完成;														//一帧数据接收完成标记：0，还没完成；1，完成了一帧数据的接收
}ModbusReceive_typedef; 
extern ModbusReceive_typedef ModbusRx;			//Modbus接收



//Modebus数据初始化
void ModbusDataInit(void);

void communication1_init(void);
//CRC校验码，高字节在前，低字节在后
u16 crc16(u8 *puchMsg, u16 usDataLen);
//Modbus发送指令
void ModbusSendOrder(void);
//Modbus发送指令
void ModbusSendOrder1(void);

//Modbus接收指令解析
//返回值：解析结果
//0,数据长度错误
//0xFF,检查正确
u8 ModbusReceiveOrderCheck(void);
u8 ModbusReceiveOrderCheck3(void);
u8 ModbusReceiveOrderCheck16(void);
//设备监测

//每秒读一次数值
void EqipmentModbusMonitor_1(void);

//485接收
void RS485_Read(void);
//485发送
void RS485_Send(void);

//Modbus事件处理函数
void Modbus_Event_1(void);
void ModbusFun6_1(void);
void showData1_1(void);



#endif
