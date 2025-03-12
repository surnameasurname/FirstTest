#ifndef __communication1_h_
#define __communication1_h_

#include "sys.h"


#define MoubusReceArrLength	250			//�������鳤��
#define ModbusReceOrderMinLength			//����������С����

//֧�ֵ�modebusָ��
#define ModbusOrder_03		0x03									//modbusͨ��03������
#define ModbusOrder_06		0x06									//modbusͨ��06������
#define ModbusOrder_16		0x10									//modbusͨ��16������

#define  ModbusBroadcastAddress			252		//�㲥��ַ��ͨ���豸��

extern u8 DataReceive[250];
extern u8 DataReceive6[20];
//modbus֡����
typedef struct
{ 
	u8 EquipmentNum;													//�豸��
	u8 ModbusOrder;														//�����룬0~255
	u16 StartAddress;													//��ʼ��ַ
	u16 RegisterNum;													//�Ĵ�������
	u16 Txlen;																//���ݳ���
	u8 Txbuf[MoubusReceArrLength];						//���ͻ�����
	u16 CrcData;															//У��ֵ 
}ModbusSend_typedef;
extern ModbusSend_typedef ModbusTx;					//Modbus����

//��modbusЭ�������
typedef  struct
{ 
	u8 EquipmentNum;													//�豸��
	u8 ModbusOrder;														//������
	u16 StartAddress;													//��ʼ��ַ
	u16 RegisterNum;													//�Ĵ�������
	u8 Rxbuf[MoubusReceArrLength];						//���ջ�����
	u8 Rxlen;																//�������ݵĳ���
	u8 ModbusReceDoneNum;											//���ڵ���3���ݽ������;														//һ֡���ݽ�����ɱ�ǣ�0����û��ɣ�1�������һ֡���ݵĽ���
}ModbusReceive_typedef; 
extern ModbusReceive_typedef ModbusRx;			//Modbus����



//Modebus���ݳ�ʼ��
void ModbusDataInit(void);

void communication1_init(void);
//CRCУ���룬���ֽ���ǰ�����ֽ��ں�
u16 crc16(u8 *puchMsg, u16 usDataLen);
//Modbus����ָ��
void ModbusSendOrder(void);
//Modbus����ָ��
void ModbusSendOrder1(void);

//Modbus����ָ�����
//����ֵ���������
//0,���ݳ��ȴ���
//0xFF,�����ȷ
u8 ModbusReceiveOrderCheck(void);
u8 ModbusReceiveOrderCheck3(void);
u8 ModbusReceiveOrderCheck16(void);
//�豸���

//ÿ���һ����ֵ
void EqipmentModbusMonitor_1(void);

//485����
void RS485_Read(void);
//485����
void RS485_Send(void);

//Modbus�¼�������
void Modbus_Event_1(void);
void ModbusFun6_1(void);
void showData1_1(void);



#endif
