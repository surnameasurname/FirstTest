#ifndef __communication1_h_
#define __communication1_h_

#include "gd32f30x.h"


#define MoubusReceArrLength	250			//�������鳤��
#define ModbusReceOrderMinLength			//����������С����

//֧�ֵ�modebusָ��
#define ModbusOrder_03		0x03									//modbusͨ��03������
#define ModbusOrder_06		0x06									//modbusͨ��06������
#define ModbusOrder_16		0x10									//modbusͨ��16������

#define  ModbusBroadcastAddress			252		//�㲥��ַ��ͨ���豸��

extern uint8_t DataReceive[250];
extern uint8_t DataReceive6[20];
extern uint16_t ReceiveOrSend;


extern uint8_t ReceiveBuff[10];
extern uint8_t DataNum;
extern uint16_t ReceiveMode;				//����ģʽ
extern uint16_t Address1;				//
extern uint16_t Address2;				//


//modbus֡����
typedef struct
{ 
	uint8_t EquipmentNum;													//�豸��
	uint8_t ModbusOrder;														//�����룬0~255
	uint16_t StartAddress;													//��ʼ��ַ
	uint16_t RegisterNum;													//�Ĵ�������
	uint16_t Txlen;																//���ݳ���
	uint8_t Txbuf[MoubusReceArrLength];						//���ͻ�����
	uint16_t CrcData;															//У��ֵ 
}ModbusSend_typedef;
extern ModbusSend_typedef ModbusTx;					//Modbus����

//��modbusЭ�������
typedef  struct
{ 
	uint8_t EquipmentNum;													//�豸��
	uint8_t ModbusOrder;														//������
	uint16_t StartAddress;													//��ʼ��ַ
	uint16_t RegisterNum;													//�Ĵ�������
	uint8_t Rxbuf[MoubusReceArrLength];						//���ջ�����
	uint8_t Rxlen;																//�������ݵĳ���
	uint8_t ModbusReceDoneNum;											//���ڵ���3���ݽ������;														//һ֡���ݽ�����ɱ�ǣ�0����û��ɣ�1�������һ֡���ݵĽ���
}ModbusReceive_typedef; 
extern ModbusReceive_typedef ModbusRx;			//Modbus����



//Modebus���ݳ�ʼ��
void ModbusDataInit(void);

void communication1_init(void);
//CRCУ���룬���ֽ���ǰ�����ֽ��ں�
uint16_t crc16(uint8_t *puchMsg, uint16_t usDataLen);
//Modbus����ָ��
void ModbusSendOrder(void);
//Modbus����ָ��
void ModbusSendOrder1(void);

//Modbus����ָ�����
//����ֵ���������
//0,���ݳ��ȴ���
//0xFF,�����ȷ
uint8_t ModbusReceiveOrderCheck(void);
uint8_t ModbusReceiveOrderCheck3(void);
uint8_t ModbusReceiveOrderCheck16(void);
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


void RS485_Send_Data(uint8_t *buf,uint8_t len);

void Modbus2_Receive(void);
void Modbus2_Send(void);

#endif
