#include "show3.h"
#include "uart.h"
#include "communication.h"
#include "DataChange.h"
#include "show1.h"
#include "delay.h"
#include "equipment.h"
#include "conflash.h"
//�������ID 
void show_ID_uart3(void)
{
	send_uart3_string("ID:SSS202005");
}


//���õ�ַ
void showSetAddress_uart3(u8 r_data)
{
	u16 crc;
//	u16 val;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x00; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}


//1.����1-9600��2-19200(����Ĭ��)��3-38400
//2.0.3��510��1-9600��2-19200������Ĭ��2����3-38400��4-57600��5-115200
//3.���ܽ�1-9600��2-19200������Ĭ�ϣ���3-38400
//4.0.1 ������ 1-9600��2-19200������Ĭ�ϣ���3-38400


//���ò�����
void showSetBaudRate(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder1();//
	
	SetBaudRate(r_data);
	delay_ms(1000);
	delay_ms(1000);
	//�޸��겨���ʣ��ٷ�һ��
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
void showSetBaudRate_1(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder1();//
	
	SetBaudRate_1(r_data);
	delay_ms(1000);
	delay_ms(1000);
	//�޸��겨���ʣ��ٷ�һ��
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
void showSetBaudRate_2(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder1();//
	
	SetBaudRate_2(r_data);
	delay_ms(1000);
	delay_ms(1000);
	//�޸��겨���ʣ��ٷ�һ��
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}



void showSetBaudRate_4(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder1();//
	
	SetBaudRate_4(r_data);
	delay_ms(1000);
	delay_ms(1000);
	//�޸��겨���ʣ��ٷ�һ��
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
void showSetBaudRate_5(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder1();//
	
	SetBaudRate_5(r_data);
	delay_ms(1000);
	delay_ms(1000);
	//�޸��겨���ʣ��ٷ�һ��
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
void showSetBaudRate_6(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder1();//
	
	SetBaudRate_6(r_data);
	delay_ms(1000);
	delay_ms(1000);
	//�޸��겨���ʣ��ٷ�һ��
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}


//����
void showOpen_uart3(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x02; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x01; 
	ModbusTx.Txbuf[6]=0xFC; 
	ModbusTx.Txbuf[7]=0x27;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//�ػ�
void showClose_uart3(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x02; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x00; 
	ModbusTx.Txbuf[6]=0x3D; 
	ModbusTx.Txbuf[7]=0xE7;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}


//���ù���ʱ��
void showSetWorkTime(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x03; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//����������ʱ
void showSetWorkDelay(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x04; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//��������ǰ�����ۼ�ʱ
void showReadAccumulatedTime(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x05; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set005();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}
//���Կ�
void showSetDebugStateON(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x06; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=0x01;
	ModbusTx.Txbuf[6]=0xBD;
	ModbusTx.Txbuf[7]=0xE6;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//���Թ�
void showSetDebugStateOFF(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x06; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=0x00;
	ModbusTx.Txbuf[6]=0x7C;
	ModbusTx.Txbuf[7]=0x26;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//����PWM
void showSetPumpPwm(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x07; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//���µ���ʱ
void showSetUpdateCountdown(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x08; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
					//ͨ�ųɹ�����λ����ʾ
			Set008();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//ͨ��У��
void showCommunicationCheck(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x09; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//�����ۼӴ���
void showCumulativeFrequency(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x0A; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���õ�һ�Ƚϵ�ѹ
void showSetComparisonVoltage1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x0B; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage2(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x0C; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage3(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x0D; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//���õ��ıȽϵ�ѹ
void showSetComparisonVoltage4(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x0E; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ���Ƚϵ�ѹ
void showSetComparisonVoltage5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x0F; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage6(u16 r_data)
{
		u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x10; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//���õ��߱Ƚϵ�ѹ
void showSetComparisonVoltage7(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x11; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ��˱Ƚϵ�ѹ
void showSetComparisonVoltage8(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x12; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

////һ������
//void showSetAll(void)
//{ 
//	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;//FC 10 00 00 00 14 28 00 01
//	ModbusTx.Txbuf[1]=0x10;
//	ModbusTx.Txbuf[2]=0x00;
//	ModbusTx.Txbuf[3]=0x00; 
//	ModbusTx.Txbuf[4]=0x00;
//	ModbusTx.Txbuf[5]=0x14;
//	ModbusTx.Txbuf[6]=0x28;
//	ModbusTx.Txbuf[7]=0x00;
//	ModbusTx.Txbuf[8]=0x01;
//	ModbusTx.Txbuf[9]=0x00;	//00 02 00 00 00 06 00 05 00 
//	ModbusTx.Txbuf[10]=0x02;
//	ModbusTx.Txbuf[11]=0x00;
//	ModbusTx.Txbuf[12]=0x00;
//	ModbusTx.Txbuf[13]=0x00;
//	ModbusTx.Txbuf[14]=0x06;
//	ModbusTx.Txbuf[15]=0x00;
//	ModbusTx.Txbuf[16]=0x05;
//	ModbusTx.Txbuf[17]=0x00;
//	ModbusTx.Txbuf[18]=0x00;//00 00 00 00 50 00 00 00 00
//	ModbusTx.Txbuf[19]=0x00;
//	ModbusTx.Txbuf[20]=0x00;
//	ModbusTx.Txbuf[21]=0x00;
//	ModbusTx.Txbuf[22]=0x50;
//	ModbusTx.Txbuf[23]=0x00;
//	ModbusTx.Txbuf[24]=0x00;
//	ModbusTx.Txbuf[25]=0x00;
//	ModbusTx.Txbuf[26]=0x00;
//	ModbusTx.Txbuf[27]=0x00;//00 00 00 3C 00 C8 03 E8 07
//	ModbusTx.Txbuf[28]=0x00;
//	ModbusTx.Txbuf[29]=0x00;
//	ModbusTx.Txbuf[30]=0x3C;
//	ModbusTx.Txbuf[31]=0x00;
//	ModbusTx.Txbuf[32]=0xC8;
//	ModbusTx.Txbuf[33]=0x03;
//	ModbusTx.Txbuf[34]=0xE8;
//	ModbusTx.Txbuf[35]=0x07;
//	ModbusTx.Txbuf[36]=0xD0;//D0 0B B8 0F A0 13 88 17 70 
//	ModbusTx.Txbuf[37]=0x0B;
//	ModbusTx.Txbuf[38]=0xB8;
//	ModbusTx.Txbuf[39]=0x0F;
//	ModbusTx.Txbuf[40]=0xA0;
//	ModbusTx.Txbuf[41]=0x13;
//	ModbusTx.Txbuf[42]=0x88;
//	ModbusTx.Txbuf[43]=0x17;
//	ModbusTx.Txbuf[44]=0x70;
//	ModbusTx.Txbuf[45]=0x00;//00 F2 C9
//	ModbusTx.Txbuf[46]=0x00;
//	ModbusTx.Txbuf[47]=0xF2;
//	ModbusTx.Txbuf[48]=0xC9;
//	
//	ModbusTx.Txlen=49;
//	ModbusSendOrder();//
////	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
////	{
////			u8 res;
////			ModbusRx.ModbusReceDoneNum=0;
////			res=ModbusReceiveOrderCheck16();		//���Ӧ��ָ��
////			if(res==0xff)											//ָ����ȷ
////			{
////					//ͨ�ųɹ�����λ����ʾ
////					SetData();
////			}
////	}
////	else	//ͨ�ų�ʱ
////	{
////		
////	}
//}
//һ������
void showSetAll(void)
{ 
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;//FC 10 00 00 00 3C 78 00 01
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x00; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x3C;
	ModbusTx.Txbuf[6]=0x78;
	ModbusTx.Txbuf[7]=0x00;
	ModbusTx.Txbuf[8]=0x01;
	ModbusTx.Txbuf[9]=0x00;	//00 02 00 00 00 06 00 05 00 
	ModbusTx.Txbuf[10]=0x02;
	ModbusTx.Txbuf[11]=0x00;
	ModbusTx.Txbuf[12]=0x00;
	ModbusTx.Txbuf[13]=0x00;
	ModbusTx.Txbuf[14]=0x06;
	ModbusTx.Txbuf[15]=0x00;
	ModbusTx.Txbuf[16]=0x05;
	ModbusTx.Txbuf[17]=0x00;
	ModbusTx.Txbuf[18]=0x00;//00 00 00 00 50 00 00 00 00
	ModbusTx.Txbuf[19]=0x00;
	ModbusTx.Txbuf[20]=0x00;
	ModbusTx.Txbuf[21]=0x00;
	ModbusTx.Txbuf[22]=0x50;
	ModbusTx.Txbuf[23]=0x00;
	ModbusTx.Txbuf[24]=0x00;
	ModbusTx.Txbuf[25]=0x00;
	ModbusTx.Txbuf[26]=0x00;
	ModbusTx.Txbuf[27]=0x00;//00 00 00 3C 00 C8 03 E8 07
	ModbusTx.Txbuf[28]=0x00;
	ModbusTx.Txbuf[29]=0x00;
	ModbusTx.Txbuf[30]=0x3C;
	ModbusTx.Txbuf[31]=0x00;
	ModbusTx.Txbuf[32]=0xC8;
	ModbusTx.Txbuf[33]=0x03;
	ModbusTx.Txbuf[34]=0xE8;
	ModbusTx.Txbuf[35]=0x07;
	ModbusTx.Txbuf[36]=0xD0;//D0 0B B8 0F A0 13 88 17 70 
	ModbusTx.Txbuf[37]=0x0B;
	ModbusTx.Txbuf[38]=0xB8;
	ModbusTx.Txbuf[39]=0x0F;
	ModbusTx.Txbuf[40]=0xA0;
	ModbusTx.Txbuf[41]=0x13;
	ModbusTx.Txbuf[42]=0x88;
	ModbusTx.Txbuf[43]=0x17;
	ModbusTx.Txbuf[44]=0x70;
	ModbusTx.Txbuf[45]=0x00;//00 00 00 00 00 00 00 00 
	ModbusTx.Txbuf[46]=0x00;		//--45-46��������20
	ModbusTx.Txbuf[47]=0x00;
	ModbusTx.Txbuf[48]=0x00;
	ModbusTx.Txbuf[49]=0x00;
	ModbusTx.Txbuf[50]=0x00;
	ModbusTx.Txbuf[51]=0x00;
	ModbusTx.Txbuf[52]=0x00;
	ModbusTx.Txbuf[53]=0x00;//00 00 00 00 00 00 00 00
	ModbusTx.Txbuf[54]=0x00;
	ModbusTx.Txbuf[55]=0x00;
	ModbusTx.Txbuf[56]=0x00;
	ModbusTx.Txbuf[57]=0x00;
	ModbusTx.Txbuf[58]=0x00;
	ModbusTx.Txbuf[59]=0x00;
	ModbusTx.Txbuf[60]=0x00;
	ModbusTx.Txbuf[61]=0x00;//00 00 00 00 00 00 00 00
	ModbusTx.Txbuf[62]=0x00;
	ModbusTx.Txbuf[63]=0x00;
	ModbusTx.Txbuf[64]=0x00;
	ModbusTx.Txbuf[65]=0x00;
	ModbusTx.Txbuf[66]=0x00;
	ModbusTx.Txbuf[67]=0x00;
	ModbusTx.Txbuf[68]=0x00;
	ModbusTx.Txbuf[69]=0x00;//00 00 00 00 00 00 00 00
	ModbusTx.Txbuf[70]=0x00;
	ModbusTx.Txbuf[71]=0x00;
	ModbusTx.Txbuf[72]=0x00;
	ModbusTx.Txbuf[73]=0x00;
	ModbusTx.Txbuf[74]=0x00;
	ModbusTx.Txbuf[75]=0x00;
	ModbusTx.Txbuf[76]=0x00;
	ModbusTx.Txbuf[77]=0x00;//00 00 00 00 00 00 00 00
	ModbusTx.Txbuf[78]=0x00;
	ModbusTx.Txbuf[79]=0x00;
	ModbusTx.Txbuf[80]=0x00;
	ModbusTx.Txbuf[81]=0x00;
	ModbusTx.Txbuf[82]=0x00;
	ModbusTx.Txbuf[83]=0x00;
	ModbusTx.Txbuf[84]=0x00;
	ModbusTx.Txbuf[85]=0x00;//00 00 00 00 00 00 00 00
	ModbusTx.Txbuf[86]=0x00;
	ModbusTx.Txbuf[87]=0x00;
	ModbusTx.Txbuf[88]=0x00;
	ModbusTx.Txbuf[89]=0x00;
	ModbusTx.Txbuf[90]=0x00;
	ModbusTx.Txbuf[91]=0x00;
	ModbusTx.Txbuf[92]=0x00;
	ModbusTx.Txbuf[93]=0x00;//00 00 00 00 00 00 00 00
	ModbusTx.Txbuf[94]=0x00;
	ModbusTx.Txbuf[95]=0x00;
	ModbusTx.Txbuf[96]=0x00;
	ModbusTx.Txbuf[97]=0x00;
	ModbusTx.Txbuf[98]=0x00;
	ModbusTx.Txbuf[99]=0x00;
	ModbusTx.Txbuf[100]=0x00;
	ModbusTx.Txbuf[101]=0x00;//00 00 00 00 00 00 00
	ModbusTx.Txbuf[102]=0x00;
	ModbusTx.Txbuf[103]=0x00;
	ModbusTx.Txbuf[104]=0x00;
	ModbusTx.Txbuf[105]=0x00;
	ModbusTx.Txbuf[106]=0x00;
	ModbusTx.Txbuf[107]=0x00;
	ModbusTx.Txbuf[108]=0x00;
	ModbusTx.Txbuf[109]=0x00;
	ModbusTx.Txbuf[110]=0x00;
	ModbusTx.Txbuf[111]=0x00;//00 00 00 00 00 00 00
	ModbusTx.Txbuf[112]=0x00;
	ModbusTx.Txbuf[113]=0x00;
	ModbusTx.Txbuf[114]=0x00;
	ModbusTx.Txbuf[115]=0x00;
	ModbusTx.Txbuf[116]=0x00;
	ModbusTx.Txbuf[117]=0x00;
	ModbusTx.Txbuf[118]=0x00;
	ModbusTx.Txbuf[119]=0x00;
	ModbusTx.Txbuf[120]=0x00;
	ModbusTx.Txbuf[121]=0x00;//00 00 00 00 00 00 00
	ModbusTx.Txbuf[122]=0x00;
	ModbusTx.Txbuf[123]=0x00;
	ModbusTx.Txbuf[124]=0x00;
	ModbusTx.Txbuf[125]=0x00;
	ModbusTx.Txbuf[126]=0x00;
	ModbusTx.Txbuf[127]=0xE3;
	ModbusTx.Txbuf[128]=0x36;
	//FC 10 00 00 00 3C 78 
	//00 01 00 02 00 00 00 06 00 05 00 00 00 00 00 50 00 00 00 00 
	//00 00 00 3C 00 C8 03 E8 07 D0 0B B8 0F A0 13 88 17 70 00 00 
	//00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
	//00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
	//00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	//00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	ModbusTx.Txlen=129;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
					//ͨ�ųɹ�����λ����ʾ
			//ShowDataforAll();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

////�������
//void showData(void)
//{
//	u16 d;
//	u32 d2;
//	
////	show_ID_uart3();
////	send_uart3_string("N064:");
////	for(d=0;d<100;d++)
////	{
////		send_uart3_string(DataChangeNumberToString(d+1));
////		send_uart3(',');
////	}
////	send_uart3_string("12354;*");
//	
//	show_ID_uart3();
//	send_uart3_string("N064:");
//	d=(ModbusRx.Rxbuf[3]<<8)|ModbusRx.Rxbuf[4];
//	send_uart3_string(DataChangeNumberToString(d));//�豸�ţ���ַ
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[5]<<8)|ModbusRx.Rxbuf[6];
//	send_uart3_string(DataChangeNumberToString(d));//������
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[7]<<8)|ModbusRx.Rxbuf[8];
//	send_uart3_string(DataChangeNumberToString(d));//����״̬��������ֹͣ
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[9]<<8)|ModbusRx.Rxbuf[10];
//	send_uart3_string(DataChangeNumberToString(d));//������������
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[11]<<8)|ModbusRx.Rxbuf[12];
//	send_uart3_string(DataChangeNumberToString(d));//��������������ʱ
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[13]<<8)|ModbusRx.Rxbuf[14];
//	send_uart3_string(DataChangeNumberToString(d));//��ǰ�ۼƼ�ʱ
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[15]<<8)|ModbusRx.Rxbuf[16];
//	send_uart3_string(DataChangeNumberToString(d));//����ģʽ
//	send_uart3(',');	
//	
//	d=(ModbusRx.Rxbuf[17]<<8)|ModbusRx.Rxbuf[18];
//	send_uart3_string(DataChangeNumberToString(d));//��������PWM
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[19]<<8)|ModbusRx.Rxbuf[20];
//	send_uart3_string(DataChangeNumberToString(d));//���µ���ʱ
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[21]<<8)|ModbusRx.Rxbuf[22];
//	send_uart3_string(DataChangeNumberToString(d));//ͨ��У��λ
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[23]<<8)|ModbusRx.Rxbuf[24];
//	send_uart3_string(DataChangeNumberToString(d));//�����ۼӴ���
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[25]<<8)|ModbusRx.Rxbuf[26];
//	send_uart3_string(DataChangeNumberToString(d));//���õ�һ�Ƚϵ�ѹ��0.3
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[27]<<8)|ModbusRx.Rxbuf[28];
//	send_uart3_string(DataChangeNumberToString(d));//���õ����Ƚϵ�ѹ��0.5
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[29]<<8)|ModbusRx.Rxbuf[30];
//	send_uart3_string(DataChangeNumberToString(d));//���õ����Ƚϵ�ѹ��1.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[31]<<8)|ModbusRx.Rxbuf[32];
//	send_uart3_string(DataChangeNumberToString(d));//���õ��ıȽϵ�ѹ��3.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[33]<<8)|ModbusRx.Rxbuf[34];
//	send_uart3_string(DataChangeNumberToString(d));//���õ���Ƚϵ�ѹ��5.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[35]<<8)|ModbusRx.Rxbuf[36];
//	send_uart3_string(DataChangeNumberToString(d));//���õ����Ƚϵ�ѹ��10.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[37]<<8)|ModbusRx.Rxbuf[38];
//	send_uart3_string(DataChangeNumberToString(d));//���õ��߱Ƚϵ�ѹ
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[39]<<8)|ModbusRx.Rxbuf[40];
//	send_uart3_string(DataChangeNumberToString(d));//���õ��˱Ƚϵ�ѹ
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[41]<<8)|ModbusRx.Rxbuf[42];
//	send_uart3_string(DataChangeNumberToString(d));//��ѹ��ֵ��
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[43]<<8)|ModbusRx.Rxbuf[44];
//	send_uart3_string(DataChangeNumberToString(d));//��ѹ��ֵ��
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[45]<<8)|ModbusRx.Rxbuf[46];
//	send_uart3_string(DataChangeNumberToString(d));//��ѹ����״̬
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[47]<<8)|ModbusRx.Rxbuf[48];
//	send_uart3_string(DataChangeNumberToString(d));//��ѹ����
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[49]<<8)|ModbusRx.Rxbuf[50];
//	send_uart3_string(DataChangeNumberToString(d));//��Դ��ֵ
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[51]<<8)|ModbusRx.Rxbuf[52];
//	send_uart3_string(DataChangeNumberToString(d));//��Դ����״̬
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[53]<<8)|ModbusRx.Rxbuf[54];
//	send_uart3_string(DataChangeNumberToString(d));//��Դ����
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[55]<<8)|ModbusRx.Rxbuf[56];
//	send_uart3_string(DataChangeNumberToString(d));//������ֵ
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[57]<<8)|ModbusRx.Rxbuf[58];
//	send_uart3_string(DataChangeNumberToString(d));//����״̬
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[59]<<8)|ModbusRx.Rxbuf[60]))|((((u32)ModbusRx.Rxbuf[61]<<8)|(ModbusRx.Rxbuf[62]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//��һ��ֵ��0.3
//	send_uart3(',');	
//	
//	d2=((((u32)ModbusRx.Rxbuf[63]<<8)|ModbusRx.Rxbuf[64]))|((((u32)ModbusRx.Rxbuf[65]<<8)|(ModbusRx.Rxbuf[66]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//������ֵ��0.5
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[67]<<8)|ModbusRx.Rxbuf[68]))|((((u32)ModbusRx.Rxbuf[69]<<8)|(ModbusRx.Rxbuf[70]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//������ֵ��1.0
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[71]<<8)|ModbusRx.Rxbuf[72]))|((((u32)ModbusRx.Rxbuf[73]<<8)|(ModbusRx.Rxbuf[74]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//������ֵ��3.0
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[75]<<8)|ModbusRx.Rxbuf[76]))|((((u32)ModbusRx.Rxbuf[77]<<8)|(ModbusRx.Rxbuf[78]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//������ֵ��5.0
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[79]<<8)|ModbusRx.Rxbuf[80]))|((((u32)ModbusRx.Rxbuf[81]<<8)|(ModbusRx.Rxbuf[82]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//������ֵ��10.0
//	send_uart3(',');

//	d2=((((u32)ModbusRx.Rxbuf[83]<<8)|ModbusRx.Rxbuf[84]))|((((u32)ModbusRx.Rxbuf[85]<<8)|(ModbusRx.Rxbuf[86]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//����Ԥ��
//	send_uart3(',');	

//	d2=((((u32)ModbusRx.Rxbuf[87]<<8)|ModbusRx.Rxbuf[88]))|((((u32)ModbusRx.Rxbuf[89]<<8)|(ModbusRx.Rxbuf[90]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//����Ԥ��
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[91]<<8)|ModbusRx.Rxbuf[92];
//	send_uart3_string(DataChangeNumberToString(d));//��������ʱ
//	send_uart3_string(";*");
//	
//	//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,0,0,");//��ַ44-61��Ԥ����8�����ۼ�����
//	
////	send_uart3(ModbusRx.Rxbuf[89]);//���Ӽ������豸ΨһID������Y 2020 05 20 001
//}
//�������
void showData_1(void)
{
	u32 d;
	if(EquipmentState == 1){
			d=(DataReceive[7]<<8)|DataReceive[8];				//��ʱ
			DelayTime = d;
			ShowLongOrder(N1460,d);
			//��������
			d=((((u32)DataReceive[11]<<8)|DataReceive[12]))|((((u32)DataReceive[13]<<24)|(DataReceive[14]))<<16);	
			Particle1_Ins = d;
			ShowLongOrder(N1468,d);
			 
			d=((((u32)DataReceive[15]<<8)|DataReceive[16]))|((((u32)DataReceive[17]<<24)|(DataReceive[18]))<<16);
			ShowLongOrder(N1470,d);
			 
			d=((((u32)DataReceive[19]<<8)|DataReceive[20]))|((((u32)DataReceive[21]<<24)|(DataReceive[22]))<<16);
			ShowLongOrder(N1478,d);
			 
			d=((((u32)DataReceive[23]<<8)|DataReceive[24]))|((((u32)DataReceive[25]<<24)|(DataReceive[26]))<<16);
			ShowLongOrder(N1480,d);
			 
			d=((((u32)DataReceive[27]<<8)|DataReceive[28]))|((((u32)DataReceive[29]<<24)|(DataReceive[30]))<<16);
			ShowLongOrder(N1488,d);
			 
			d=((((u32)DataReceive[31]<<8)|DataReceive[32]))|((((u32)DataReceive[33]<<24)|(DataReceive[34]))<<16);
			ShowLongOrder(N1490,d);
			 
			d=((((u32)DataReceive[35]<<8)|DataReceive[36]))|((((u32)DataReceive[37]<<24)|(DataReceive[38]))<<16);
			ShowLongOrder(N1498,d);
			 
			d=((((u32)DataReceive[39]<<8)|DataReceive[40]))|((((u32)DataReceive[41]<<24)|(DataReceive[42]))<<16);
			ShowLongOrder(N14A0,d);
			//�۲�����
			d=((((u32)DataReceive[43]<<8)|DataReceive[44]))|((((u32)DataReceive[45]<<24)|(DataReceive[46]))<<16);	
			ShowLongOrder(N14A8,d);
			 
			d=((((u32)DataReceive[47]<<8)|DataReceive[48]))|((((u32)DataReceive[49]<<24)|(DataReceive[50]))<<16);
			ShowLongOrder(N14B0,d);
			 
			d=((((u32)DataReceive[51]<<8)|DataReceive[52]))|((((u32)DataReceive[53]<<24)|(DataReceive[54]))<<16);
			ShowLongOrder(N14B8,d);
			 
			d=((((u32)DataReceive[55]<<8)|DataReceive[56]))|((((u32)DataReceive[57]<<24)|(DataReceive[58]))<<16);
			ShowLongOrder(N14C0,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);
			ShowLongOrder(N14C8,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(N14D0,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(N14D8,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(N14E0,d);


			d=(DataReceive[81]<<8)|DataReceive[82];					//���µ���ʱ
			UpdataTimeDownNum = d;
			ShowLongOrder(N1420,d);
			d=(DataReceive[83]<<8)|DataReceive[84];					//��������ʱ		
			ShowLongOrder(N1450,d);		 
			d=(DataReceive[93]<<8)|DataReceive[94];//��ѹ����
			ShowLongOrder(N1440,d);
			
			if(DelayTime == 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}if(DelayTime != 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times-1);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}
				
	}else{
//			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
//			ShowLongOrder(N1400,d);
			d=(DataReceive[5]<<8)|DataReceive[6];				//����
			ShowLongOrder(N1458,d);
			d=(DataReceive[7]<<8)|DataReceive[8];				//��ʱ
			ShowLongOrder(N1460,d);
//			d=(DataReceive[9]<<8)|DataReceive[10];				//��������
//			ShowOrder(N1411,d);
			//��������
			d=((((u32)DataReceive[11]<<8)|DataReceive[12]))|((((u32)DataReceive[13]<<24)|(DataReceive[14]))<<16);	
			ShowLongOrder(N1468,d);
			 
			d=((((u32)DataReceive[15]<<8)|DataReceive[16]))|((((u32)DataReceive[17]<<24)|(DataReceive[18]))<<16);
			ShowLongOrder(N1470,d);
			 
			d=((((u32)DataReceive[19]<<8)|DataReceive[20]))|((((u32)DataReceive[21]<<24)|(DataReceive[22]))<<16);
			ShowLongOrder(N1478,d);
			 
			d=((((u32)DataReceive[23]<<8)|DataReceive[24]))|((((u32)DataReceive[25]<<24)|(DataReceive[26]))<<16);
			ShowLongOrder(N1480,d);
			 
			d=((((u32)DataReceive[27]<<8)|DataReceive[28]))|((((u32)DataReceive[29]<<24)|(DataReceive[30]))<<16);
			ShowLongOrder(N1488,d);
			 
			d=((((u32)DataReceive[31]<<8)|DataReceive[32]))|((((u32)DataReceive[33]<<24)|(DataReceive[34]))<<16);
			ShowLongOrder(N1490,d);
			 
			d=((((u32)DataReceive[35]<<8)|DataReceive[36]))|((((u32)DataReceive[37]<<24)|(DataReceive[38]))<<16);
			ShowLongOrder(N1498,d);
			 
			d=((((u32)DataReceive[39]<<8)|DataReceive[40]))|((((u32)DataReceive[41]<<24)|(DataReceive[42]))<<16);
			ShowLongOrder(N14A0,d);
			//�۲�����
			d=((((u32)DataReceive[43]<<8)|DataReceive[44]))|((((u32)DataReceive[45]<<24)|(DataReceive[46]))<<16);	
			ShowLongOrder(N14A8,d);
			 
			d=((((u32)DataReceive[47]<<8)|DataReceive[48]))|((((u32)DataReceive[49]<<24)|(DataReceive[50]))<<16);
			ShowLongOrder(N14B0,d);
			 
			d=((((u32)DataReceive[51]<<8)|DataReceive[52]))|((((u32)DataReceive[53]<<24)|(DataReceive[54]))<<16);
			ShowLongOrder(N14B8,d);
			 
			d=((((u32)DataReceive[55]<<8)|DataReceive[56]))|((((u32)DataReceive[57]<<24)|(DataReceive[58]))<<16);
			ShowLongOrder(N14C0,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);
			ShowLongOrder(N14C8,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(N14D0,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(N14D8,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(N14E0,d);
	
			d=(DataReceive[75]<<8)|DataReceive[76];				//������
			ShowLongOrder(N1408,d);
			 
			d=(DataReceive[77]<<8)|DataReceive[78];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			ShowLongOrder(N1428,d);
			d=(DataReceive[79]<<8)|DataReceive[80];					//PWM
			ShowLongOrder(N1418,d);
			d=(DataReceive[81]<<8)|DataReceive[82];					//���µ���ʱ
			ShowLongOrder(N1420,d);
			d=(DataReceive[83]<<8)|DataReceive[84];					//��������ʱ		
			ShowLongOrder(N1450,d);		 
//			d=(DataReceive[85]<<8)|DataReceive[86];				//����
//			ShowOrder(N1413,d);
			d=(DataReceive[87]<<8)|DataReceive[88];					//���õ���
			ShowLongOrder(N1448,d);
			d=(DataReceive[89]<<8)|DataReceive[90];//��ѹ��ֵ��
			ShowLongOrder(N1430,d);
			 
			d=(DataReceive[91]<<8)|DataReceive[92];//��ѹ��ֵ��
			ShowLongOrder(N1438,d);
			 
			d=(DataReceive[93]<<8)|DataReceive[94];//��ѹ����
			ShowLongOrder(N1440,d);
			
//		46-59
//		95-122
			d=(DataReceive[123]<<8)|DataReceive[124];				//��ַ
			Address = d;
			ShowLongOrder(N1400,d);
			d=(DataReceive[125]<<8)|DataReceive[126];					//�Ƚϵ�ѹ1
			ShowOrder(N14E8,d);
			 
			d=(DataReceive[127]<<8)|DataReceive[128];					//�Ƚϵ�ѹ2
			ShowOrder(N14F0,d);
			 
			d=(DataReceive[129]<<8)|DataReceive[130];					//�Ƚϵ�ѹ3
			ShowOrder(N14F8,d);
			 
			d=(DataReceive[131]<<8)|DataReceive[132];					//�Ƚϵ�ѹ4
			ShowOrder(N1500,d);
			 
			d=(DataReceive[133]<<8)|DataReceive[134];					//�Ƚϵ�ѹ5
			ShowOrder(N1508,d);
			 
			d=(DataReceive[135]<<8)|DataReceive[136];					//�Ƚϵ�ѹ6
			ShowOrder(N1510,d);
			 
			d=(DataReceive[137]<<8)|DataReceive[138];					//�Ƚϵ�ѹ7
			ShowOrder(N1518,d);
			 		
			d=(DataReceive[139]<<8)|DataReceive[140];					//�Ƚϵ�ѹ8
			ShowOrder(N1520,d);
			
			FlagVoltage = d;
	}
	
	
}
//�������
void showData1_1(void)
{
	u32 d;
			
			
			d=(DataReceive[5]<<8)|DataReceive[6];				//����
			WorkPeriod = d;
			ShowLongOrder(N1458,d);
			d=(DataReceive[7]<<8)|DataReceive[8];				//��ʱ
			DelayTime = d;
			ShowLongOrder(N1460,d);
//			d=(DataReceive[9]<<8)|DataReceive[10];				//��������
//			ShowOrder(N1411,d);
			//��������
			d=((((u32)DataReceive[11]<<8)|DataReceive[12]))|((((u32)DataReceive[13]<<24)|(DataReceive[14]))<<16);	
			
			ShowLongOrder(N1468,d);
			 
			d=((((u32)DataReceive[15]<<8)|DataReceive[16]))|((((u32)DataReceive[17]<<24)|(DataReceive[18]))<<16);
			ShowLongOrder(N1470,d);
			 
			d=((((u32)DataReceive[19]<<8)|DataReceive[20]))|((((u32)DataReceive[21]<<24)|(DataReceive[22]))<<16);
			ShowLongOrder(N1478,d);
			 
			d=((((u32)DataReceive[23]<<8)|DataReceive[24]))|((((u32)DataReceive[25]<<24)|(DataReceive[26]))<<16);
			ShowLongOrder(N1480,d);
			 
			d=((((u32)DataReceive[27]<<8)|DataReceive[28]))|((((u32)DataReceive[29]<<24)|(DataReceive[30]))<<16);
			ShowLongOrder(N1488,d);
			 
			d=((((u32)DataReceive[31]<<8)|DataReceive[32]))|((((u32)DataReceive[33]<<24)|(DataReceive[34]))<<16);
			ShowLongOrder(N1490,d);
			 
			d=((((u32)DataReceive[35]<<8)|DataReceive[36]))|((((u32)DataReceive[37]<<24)|(DataReceive[38]))<<16);
			ShowLongOrder(N1498,d);
			 
			d=((((u32)DataReceive[39]<<8)|DataReceive[40]))|((((u32)DataReceive[41]<<24)|(DataReceive[42]))<<16);
			ShowLongOrder(N14A0,d);
			//�۲�����
			d=((((u32)DataReceive[43]<<8)|DataReceive[44]))|((((u32)DataReceive[45]<<24)|(DataReceive[46]))<<16);	
			ShowLongOrder(N14A8,d);
			 
			d=((((u32)DataReceive[47]<<8)|DataReceive[48]))|((((u32)DataReceive[49]<<24)|(DataReceive[50]))<<16);
			ShowLongOrder(N14B0,d);
			 
			d=((((u32)DataReceive[51]<<8)|DataReceive[52]))|((((u32)DataReceive[53]<<24)|(DataReceive[54]))<<16);
			ShowLongOrder(N14B8,d);
			 
			d=((((u32)DataReceive[55]<<8)|DataReceive[56]))|((((u32)DataReceive[57]<<24)|(DataReceive[58]))<<16);
			ShowLongOrder(N14C0,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);
			ShowLongOrder(N14C8,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(N14D0,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(N14D8,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(N14E0,d);
	
			d=(DataReceive[75]<<8)|DataReceive[76];				//������
			BTL = d;
			ShowLongOrder(N1408,d);
			 
			d=(DataReceive[77]<<8)|DataReceive[78];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			CommunicationCheck = d;
			ShowLongOrder(N1428,d);
			d=(DataReceive[79]<<8)|DataReceive[80];					//PWM
			PumpPWM = d;
			ShowLongOrder(N1418,d);
			d=(DataReceive[81]<<8)|DataReceive[82];					//���µ���ʱ
			ShowLongOrder(N1420,d);
			d=(DataReceive[83]<<8)|DataReceive[84];					//��������ʱ		
			ShowLongOrder(N1450,d);		 
//			d=(DataReceive[85]<<8)|DataReceive[86];				//����
//			ShowOrder(N1413,d);
			d=(DataReceive[87]<<8)|DataReceive[88];					//���õ���
			AirPumpResistance = d;
			ShowLongOrder(N1448,d);
			d=(DataReceive[89]<<8)|DataReceive[90];//��ѹ��ֵ��
			PressureLow = d;
			ShowLongOrder(N1430,d);
			 
			d=(DataReceive[91]<<8)|DataReceive[92];//��ѹ��ֵ��
			PressureHigh = d;
			ShowLongOrder(N1438,d);
			 
			d=(DataReceive[93]<<8)|DataReceive[94];//��ѹ����
			ShowLongOrder(N1440,d);
			
//		46-59
//		95-122
			d=(DataReceive[123]<<8)|DataReceive[124];				//��ַ
			Address = d;
			ShowLongOrder(N1400,d);
			d=(DataReceive[125]<<8)|DataReceive[126];					//�Ƚϵ�ѹ1
			ComparisonVoltage1 = d;
			ShowOrder(N14E8,d);
			 
			d=(DataReceive[127]<<8)|DataReceive[128];					//�Ƚϵ�ѹ2
			ComparisonVoltage2 = d;
			ShowOrder(N14F0,d);
			 
			d=(DataReceive[129]<<8)|DataReceive[130];					//�Ƚϵ�ѹ3
			ComparisonVoltage3 = d;
			ShowOrder(N14F8,d);
			 
			d=(DataReceive[131]<<8)|DataReceive[132];					//�Ƚϵ�ѹ4
			ComparisonVoltage4 = d;
			ShowOrder(N1500,d);
			 
			d=(DataReceive[133]<<8)|DataReceive[134];					//�Ƚϵ�ѹ5
			ComparisonVoltage5 = d;
			ShowOrder(N1508,d);
			 
			d=(DataReceive[135]<<8)|DataReceive[136];					//�Ƚϵ�ѹ6
			ComparisonVoltage6 = d;
			ShowOrder(N1510,d);
			 
			d=(DataReceive[137]<<8)|DataReceive[138];					//�Ƚϵ�ѹ7
			ComparisonVoltage7 = d;
			ShowOrder(N1518,d);
			 		
			d=(DataReceive[139]<<8)|DataReceive[140];					//�Ƚϵ�ѹ8
			ComparisonVoltage8 = d;
			ShowOrder(N1520,d);
			 
	}
//�������
void showData_2(void)
{
	u32 d;
	if(EquipmentState == 1){
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
//			ShowLongOrder(N1068,d);
//			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];//���µ���ʱ
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);			
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			DelayTime = d;
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];//��������ǰ�ۼ�ʱ
			ShowLongOrder(N1010,d);
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			Particle1_Ins = d;
			ShowLongOrder(SoursData1,d);
			
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			Particle2_Ins = d;
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			Particle3_Ins = d;
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			Particle4_Ins = d;
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			Particle5_Ins = d;
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			Particle6_Ins = d;
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			Particle7_Ins = d;
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			Particle8_Ins = d;
			ShowLongOrder(SoursData8,d);
			 
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[116];	//��������ʱ
			ShowLongOrder(N1078,d);
			//�ۼ���
			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
			ShowLongOrder(CumulativeData1,d);
			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
			ShowLongOrder(CumulativeData2,d);
			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
			ShowLongOrder(CumulativeData3,d);
			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
			ShowLongOrder(CumulativeData4,d);
			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
			ShowLongOrder(CumulativeData5,d);
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
			ShowLongOrder(CumulativeData6,d);
			
			if(Particle1_Ins==0)		//��ʱ
			{
					Times++;
					ShowLongOrder(N1148,Times);
			}else{
					Times = 0;
					ShowLongOrder(N1148,Times);
			}
			
			//			//����ʱ
			if(DelayTime == 0){
					
					if(UpdataTimeDownNum == 1){
							//�洢
						//RememberNum++;
						WriteNumber();
					}
			}
			//����ʱ
			if(DelayTime != 0){

					if(RememberTimes == 1){

						if(UpdataTimeDownNum == 1){
							//�洢
							//RememberNum++;
							WriteNumber();
						}
					
					}
					
					if(UpdataTimeDownNum == 1){
							RememberTimes = 1;
					}
				}	
			
			
			
			
//			//����ʱ
//			if(DelayTime == 0){

//					if(Particle1_Ins==0){
//						Times++;
//						ShowLongOrder(N1148,Times);
//					}else{
//						Times = 0;
//						ShowLongOrder(N1148,Times);
//					}
//					
//					if(UpdataTimeDownNum == 1){
//							//�洢
//					}
//			}
//			//����ʱ
//			if(DelayTime != 0){

//					if(RememberTimes == 1){
//						if(Particle1_Ins==0){
//							Times++;
//							ShowLongOrder(N1148,Times);
//						}else{
//							Times = 0;
//							ShowLongOrder(N1148,Times);
//						}
//						if(UpdataTimeDownNum == 1){
//							//�洢
//						}
//					
//					}
//					
//					if(UpdataTimeDownNum == 1){
//							RememberTimes = 1;
//					}
//				}	
	}else{
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
			ShowLongOrder(N1138,d);
			
			
			d=(DataReceive[103]<<8)|DataReceive[104];	//IP1
			ShowLongOrder(IP1,d);
			d=(DataReceive[105]<<8)|DataReceive[106];	//IP2
			ShowLongOrder(IP2,d);
			d=(DataReceive[107]<<8)|DataReceive[108];	//IP3
			ShowLongOrder(IP3,d);
			d=(DataReceive[109]<<8)|DataReceive[110];	//IP4
			ShowLongOrder(IP4,d);
			d=(DataReceive[111]<<8)|DataReceive[112];	//Port
			ShowLongOrder(Port,d);
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP�Ͷ˿ڵ��޸�λ
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//��������ʱ
			//�ۼ���
			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
			ShowLongOrder(CumulativeData1,d);
			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
			ShowLongOrder(CumulativeData2,d);
			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
			ShowLongOrder(CumulativeData3,d);
			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
			ShowLongOrder(CumulativeData4,d);
			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
			ShowLongOrder(CumulativeData5,d);
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
			ShowLongOrder(CumulativeData6,d);
		}
	
}
//�������
void showData1_2(void)
{
			u32 d;
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			 
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			 
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
			ShowLongOrder(N1138,d);
			
			d=(DataReceive[103]<<8)|DataReceive[104];	//IP1
			ShowLongOrder(IP1,d);
			d=(DataReceive[105]<<8)|DataReceive[106];	//IP2
			ShowLongOrder(IP2,d);
			d=(DataReceive[107]<<8)|DataReceive[108];	//IP3
			ShowLongOrder(IP3,d);
			d=(DataReceive[109]<<8)|DataReceive[110];	//IP4
			ShowLongOrder(IP4,d);
			d=(DataReceive[111]<<8)|DataReceive[112];	//Port
			ShowLongOrder(Port,d);
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP�Ͷ˿ڵ��޸�λ
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//��������ʱ
			//�ۼ���
			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
			ShowLongOrder(CumulativeData1,d);
			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
			ShowLongOrder(CumulativeData2,d);
			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
			ShowLongOrder(CumulativeData3,d);
			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
			ShowLongOrder(CumulativeData4,d);
			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
			ShowLongOrder(CumulativeData5,d);
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
			ShowLongOrder(CumulativeData6,d);
}	
	//�������
void showData_3(void)
{
	u32 d;
	if(EquipmentState == 1){
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
//			ShowLongOrder(N1068,d);
//			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];//���µ���ʱ
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);			
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			DelayTime = d;
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];//��������ǰ�ۼ�ʱ
			ShowLongOrder(N1010,d);
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			Particle1_Ins = d;
			ShowLongOrder(SoursData1,d);
			
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			 
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[116];	//��������ʱ
			ShowLongOrder(N1078,d);
			//�ۼ���
			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
			ShowLongOrder(CumulativeData1,d);
			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
			ShowLongOrder(CumulativeData2,d);
			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
			ShowLongOrder(CumulativeData3,d);
			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
			ShowLongOrder(CumulativeData4,d);
			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
			ShowLongOrder(CumulativeData5,d);
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
			ShowLongOrder(CumulativeData6,d);
			
			if(DelayTime == 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}if(DelayTime != 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times-1);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}
				
	}else{
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
			ShowLongOrder(N1138,d);
			
			
			d=(DataReceive[103]<<8)|DataReceive[104];	//IP1
			ShowLongOrder(IP1,d);
			d=(DataReceive[105]<<8)|DataReceive[106];	//IP2
			ShowLongOrder(IP2,d);
			d=(DataReceive[107]<<8)|DataReceive[108];	//IP3
			ShowLongOrder(IP3,d);
			d=(DataReceive[109]<<8)|DataReceive[110];	//IP4
			ShowLongOrder(IP4,d);
			d=(DataReceive[111]<<8)|DataReceive[112];	//Port
			ShowLongOrder(Port,d);
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP�Ͷ˿ڵ��޸�λ
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//��������ʱ
			//�ۼ���
			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
			ShowLongOrder(CumulativeData1,d);
			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
			ShowLongOrder(CumulativeData2,d);
			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
			ShowLongOrder(CumulativeData3,d);
			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
			ShowLongOrder(CumulativeData4,d);
			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
			ShowLongOrder(CumulativeData5,d);
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
			ShowLongOrder(CumulativeData6,d);
	}
	
	
}
//�������
void showData1_3(void)
{
	u32 d;
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			 
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			 
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
			ShowLongOrder(N1138,d);
			
			
			d=(DataReceive[103]<<8)|DataReceive[104];	//IP1
			ShowLongOrder(IP1,d);
			d=(DataReceive[105]<<8)|DataReceive[106];	//IP2
			ShowLongOrder(IP2,d);
			d=(DataReceive[107]<<8)|DataReceive[108];	//IP3
			ShowLongOrder(IP3,d);
			d=(DataReceive[109]<<8)|DataReceive[110];	//IP4
			ShowLongOrder(IP4,d);
			d=(DataReceive[111]<<8)|DataReceive[112];	//Port
			ShowLongOrder(Port,d);
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP�Ͷ˿ڵ��޸�λ
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//��������ʱ
			//�ۼ���
			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
			ShowLongOrder(CumulativeData1,d);
			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
			ShowLongOrder(CumulativeData2,d);
			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
			ShowLongOrder(CumulativeData3,d);
			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
			ShowLongOrder(CumulativeData4,d);
			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
			ShowLongOrder(CumulativeData5,d);
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
			ShowLongOrder(CumulativeData6,d);
		
	}

	
	//�������
void showData_4(void)
{
	u32 d;
	if(EquipmentState == 1){

			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
//			ShowLongOrder(N1068,d);
//			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];//���µ���ʱ
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);			
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			DelayTime = d;
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];//��������ǰ�ۼ�ʱ
			ShowLongOrder(N1010,d);
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			Particle1_Ins = d;
			ShowLongOrder(SoursData1,d);
			
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			 
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[116];	//��������ʱ
			ShowLongOrder(N1078,d);
			//�ۼ���
			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
			ShowLongOrder(CumulativeData1,d);
			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
			ShowLongOrder(CumulativeData2,d);
			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
			ShowLongOrder(CumulativeData3,d);
			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
			ShowLongOrder(CumulativeData4,d);
			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
			ShowLongOrder(CumulativeData5,d);
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
			ShowLongOrder(CumulativeData6,d);
			
			if(DelayTime == 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}if(DelayTime != 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times-1);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}
				
	}else{
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
			ShowLongOrder(N1138,d);
			

			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//��������ʱ
			//�ۼ���
//			d=((((u32)DataReceive[123]<<8)|DataReceive[124]))|((((u32)DataReceive[125]<<24)|(DataReceive[126]))<<16);
//			ShowLongOrder(CumulativeData1,d);
//			d=((((u32)DataReceive[127]<<8)|DataReceive[128]))|((((u32)DataReceive[129]<<24)|(DataReceive[130]))<<16);
//			ShowLongOrder(CumulativeData2,d);
//			d=((((u32)DataReceive[131]<<8)|DataReceive[132]))|((((u32)DataReceive[133]<<24)|(DataReceive[134]))<<16);
//			ShowLongOrder(CumulativeData3,d);
//			d=((((u32)DataReceive[135]<<8)|DataReceive[136]))|((((u32)DataReceive[137]<<24)|(DataReceive[138]))<<16);
//			ShowLongOrder(CumulativeData4,d);
//			d=((((u32)DataReceive[139]<<8)|DataReceive[140]))|((((u32)DataReceive[141]<<24)|(DataReceive[142]))<<16);
//			ShowLongOrder(CumulativeData5,d);
//			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);
//			ShowLongOrder(CumulativeData6,d);
	}
	
	
}
//�������
void showData1_4(void)
{
	u32 d;
			d=(DataReceive[57]<<8)|DataReceive[58];			//����״̬
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			 
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			 
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
			ShowLongOrder(N1070,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
			ShowLongOrder(N1138,d);
			
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//��������ʱ
		
	}	

	
	//�������
void showData_5(void)
{
	u32 d;
	if(EquipmentState == 1){
			//ShowLongOrder(N1088,d);
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);

			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			//44-50����
//			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//�۲�����
			d=((((u32)DataReceive[105]<<8)|DataReceive[106]))|((((u32)DataReceive[107]<<24)|(DataReceive[108]))<<16);	
			ShowLongOrder(N1600,d);
			Particle1_Ins = d;
			d=((((u32)DataReceive[109]<<8)|DataReceive[110]))|((((u32)DataReceive[111]<<24)|(DataReceive[112]))<<16);	
			ShowLongOrder(N1608,d);
			d=((((u32)DataReceive[113]<<8)|DataReceive[114]))|((((u32)DataReceive[115]<<24)|(DataReceive[116]))<<16);	
			ShowLongOrder(N1610,d);
			d=((((u32)DataReceive[117]<<8)|DataReceive[118]))|((((u32)DataReceive[119]<<24)|(DataReceive[120]))<<16);	
			ShowLongOrder(N1618,d);
			d=((((u32)DataReceive[121]<<8)|DataReceive[122]))|((((u32)DataReceive[123]<<24)|(DataReceive[124]))<<16);	
			ShowLongOrder(N1620,d);
			d=((((u32)DataReceive[125]<<8)|DataReceive[126]))|((((u32)DataReceive[127]<<24)|(DataReceive[128]))<<16);	
			ShowLongOrder(N1628,d);
			d=((((u32)DataReceive[129]<<8)|DataReceive[130]))|((((u32)DataReceive[131]<<24)|(DataReceive[132]))<<16);	
			ShowLongOrder(N1630,d);
			d=((((u32)DataReceive[133]<<8)|DataReceive[134]))|((((u32)DataReceive[135]<<24)|(DataReceive[136]))<<16);	
			ShowLongOrder(N1638,d);
			//67-69����
			//��Դ�����ж�
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//�¶�ֵ
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//����ʱ��
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1378,d);
			//˲ʱ����
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//�ۼ�����
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//��ѹ����ֵ
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86����PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//����״̬
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//�ۼ�����
			d=((((u32)DataReceive[183]<<8)|DataReceive[184]))|((((u32)DataReceive[185]<<24)|(DataReceive[186]))<<16);	
			ShowLongOrder(N16D0,d);
			d=((((u32)DataReceive[187]<<8)|DataReceive[188]))|((((u32)DataReceive[189]<<24)|(DataReceive[190]))<<16);	
			ShowLongOrder(N16D8,d);
			d=((((u32)DataReceive[191]<<8)|DataReceive[192]))|((((u32)DataReceive[193]<<24)|(DataReceive[194]))<<16);	
			ShowLongOrder(N16E0,d);
			d=((((u32)DataReceive[195]<<8)|DataReceive[196]))|((((u32)DataReceive[197]<<24)|(DataReceive[198]))<<16);	
			ShowLongOrder(N16E8,d);
			d=((((u32)DataReceive[199]<<8)|DataReceive[200]))|((((u32)DataReceive[201]<<24)|(DataReceive[202]))<<16);	
			ShowLongOrder(N16F0,d);
			d=((((u32)DataReceive[203]<<8)|DataReceive[204]))|((((u32)DataReceive[205]<<24)|(DataReceive[206]))<<16);	
			ShowLongOrder(N16F8,d);
			d=((((u32)DataReceive[207]<<8)|DataReceive[208]))|((((u32)DataReceive[209]<<24)|(DataReceive[210]))<<16);	
			ShowLongOrder(N1700,d);
			d=((((u32)DataReceive[211]<<8)|DataReceive[212]))|((((u32)DataReceive[213]<<24)|(DataReceive[214]))<<16);	
			ShowLongOrder(N1708,d);
			if(DelayTime == 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}if(DelayTime != 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times-1);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}
				
	}else{
			
			 
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			DelayTime = d;
			 
//			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
//			ShowLongOrder(N1070,d);
			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			//44-50����
//			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//�۲�����
			d=((((u32)DataReceive[105]<<8)|DataReceive[106]))|((((u32)DataReceive[107]<<24)|(DataReceive[108]))<<16);	
			ShowLongOrder(N1600,d);
			d=((((u32)DataReceive[109]<<8)|DataReceive[110]))|((((u32)DataReceive[111]<<24)|(DataReceive[112]))<<16);	
			ShowLongOrder(N1608,d);
			d=((((u32)DataReceive[113]<<8)|DataReceive[114]))|((((u32)DataReceive[115]<<24)|(DataReceive[116]))<<16);	
			ShowLongOrder(N1610,d);
			d=((((u32)DataReceive[117]<<8)|DataReceive[118]))|((((u32)DataReceive[119]<<24)|(DataReceive[120]))<<16);	
			ShowLongOrder(N1618,d);
			d=((((u32)DataReceive[121]<<8)|DataReceive[122]))|((((u32)DataReceive[123]<<24)|(DataReceive[124]))<<16);	
			ShowLongOrder(N1620,d);
			d=((((u32)DataReceive[125]<<8)|DataReceive[126]))|((((u32)DataReceive[127]<<24)|(DataReceive[128]))<<16);	
			ShowLongOrder(N1628,d);
			d=((((u32)DataReceive[129]<<8)|DataReceive[130]))|((((u32)DataReceive[131]<<24)|(DataReceive[132]))<<16);	
			ShowLongOrder(N1630,d);
			d=((((u32)DataReceive[133]<<8)|DataReceive[134]))|((((u32)DataReceive[135]<<24)|(DataReceive[136]))<<16);	
			ShowLongOrder(N1638,d);
			//67-69����
			//��Դ�����ж�
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//��Դ���ϲ���
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
			//�¶���ֵ
			d=(DataReceive[149]<<8)|DataReceive[150];
			ShowLongOrder(N1650,d);
			//�¶�ֵ
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//�趨����ͨ����
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//�������
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//��������
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//����ʱ��
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1378,d);
			//˲ʱ����
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//�ۼ�����
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//�趨����
			d=(DataReceive[165]<<8)|DataReceive[166];
			ShowLongOrder(N1688,d);
			//�趨����ϵ��
			d=(DataReceive[167]<<8)|DataReceive[168];
			ShowLongOrder(N1690,d);
			//PMT���Ƶ�ѹ
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT����
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
			//��ѹ����ֵ
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86����PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//������ֵ
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);
			ShowLongOrder(N16B8,d);
			//����״̬
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//�ۼ�����
			d=((((u32)DataReceive[183]<<8)|DataReceive[184]))|((((u32)DataReceive[185]<<24)|(DataReceive[186]))<<16);	
			ShowLongOrder(N16D0,d);
			d=((((u32)DataReceive[187]<<8)|DataReceive[188]))|((((u32)DataReceive[189]<<24)|(DataReceive[190]))<<16);	
			ShowLongOrder(N16D8,d);
			d=((((u32)DataReceive[191]<<8)|DataReceive[192]))|((((u32)DataReceive[193]<<24)|(DataReceive[194]))<<16);	
			ShowLongOrder(N16E0,d);
			d=((((u32)DataReceive[195]<<8)|DataReceive[196]))|((((u32)DataReceive[197]<<24)|(DataReceive[198]))<<16);	
			ShowLongOrder(N16E8,d);
			d=((((u32)DataReceive[199]<<8)|DataReceive[200]))|((((u32)DataReceive[201]<<24)|(DataReceive[202]))<<16);	
			ShowLongOrder(N16F0,d);
			d=((((u32)DataReceive[203]<<8)|DataReceive[204]))|((((u32)DataReceive[205]<<24)|(DataReceive[206]))<<16);	
			ShowLongOrder(N16F8,d);
			d=((((u32)DataReceive[207]<<8)|DataReceive[208]))|((((u32)DataReceive[209]<<24)|(DataReceive[210]))<<16);	
			ShowLongOrder(N1700,d);
			d=((((u32)DataReceive[211]<<8)|DataReceive[212]))|((((u32)DataReceive[213]<<24)|(DataReceive[214]))<<16);	
			ShowLongOrder(N1708,d);
			//IP1
			d=(DataReceive[215]<<8)|DataReceive[216];
			ShowLongOrder(N15D0,d);
			d=(DataReceive[217]<<8)|DataReceive[218];
			ShowLongOrder(N15D8,d);
			d=(DataReceive[219]<<8)|DataReceive[220];
			ShowLongOrder(N15E0,d);
			d=(DataReceive[221]<<8)|DataReceive[222];
			ShowLongOrder(N15E8,d);
			//Port
			d=(DataReceive[223]<<8)|DataReceive[224];
			ShowLongOrder(N15F0,d);
			//IP�˿��޸�λ
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//���к�
			d=(DataReceive[227]<<8)|DataReceive[228];
			ShowLongOrder(N1710,d);
			
			d=(DataReceive[229]<<8)|DataReceive[230];
			ShowLongOrder(N1718,d);
			
			d=(DataReceive[231]<<8)|DataReceive[232];
			ShowLongOrder(N1720,d);
			
			d=(DataReceive[233]<<8)|DataReceive[234];
			ShowLongOrder(N1728,d);
			
			d=(DataReceive[235]<<8)|DataReceive[236];
			ShowLongOrder(N1730,d);
			
			d=(DataReceive[237]<<8)|DataReceive[238];
			ShowLongOrder(N1738,d);
			
			d=(DataReceive[239]<<8)|DataReceive[240];
			ShowLongOrder(N1740,d);
			
			d=(DataReceive[241]<<8)|DataReceive[242];
			ShowLongOrder(N1748,d);
			//���к�����
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//�趨Modbus�汾
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//�趨�豸�汾��
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);
	}
	
	
}
//�������
void showData1_5(void)
{
	u32 d;
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			DelayTime = d;
//			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
//			ShowLongOrder(N1070,d);
			 //��������
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			//44-50����
//			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//�۲�����
			d=((((u32)DataReceive[105]<<8)|DataReceive[106]))|((((u32)DataReceive[107]<<24)|(DataReceive[108]))<<16);	
			ShowLongOrder(N1600,d);
			d=((((u32)DataReceive[109]<<8)|DataReceive[110]))|((((u32)DataReceive[111]<<24)|(DataReceive[112]))<<16);	
			ShowLongOrder(N1608,d);
			d=((((u32)DataReceive[113]<<8)|DataReceive[114]))|((((u32)DataReceive[115]<<24)|(DataReceive[116]))<<16);	
			ShowLongOrder(N1610,d);
			d=((((u32)DataReceive[117]<<8)|DataReceive[118]))|((((u32)DataReceive[119]<<24)|(DataReceive[120]))<<16);	
			ShowLongOrder(N1618,d);
			d=((((u32)DataReceive[121]<<8)|DataReceive[122]))|((((u32)DataReceive[123]<<24)|(DataReceive[124]))<<16);	
			ShowLongOrder(N1620,d);
			d=((((u32)DataReceive[125]<<8)|DataReceive[126]))|((((u32)DataReceive[127]<<24)|(DataReceive[128]))<<16);	
			ShowLongOrder(N1628,d);
			d=((((u32)DataReceive[129]<<8)|DataReceive[130]))|((((u32)DataReceive[131]<<24)|(DataReceive[132]))<<16);	
			ShowLongOrder(N1630,d);
			d=((((u32)DataReceive[133]<<8)|DataReceive[134]))|((((u32)DataReceive[135]<<24)|(DataReceive[136]))<<16);	
			ShowLongOrder(N1638,d);
			//67-69����
			//��Դ�����ж�
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//��Դ���ϲ���
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
			//�¶���ֵ
			d=(DataReceive[149]<<8)|DataReceive[150];
			ShowLongOrder(N1650,d);
			//�¶�ֵ
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//�趨����ͨ����
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//�������
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//��������
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//����ʱ��
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1678,d);
			//˲ʱ����
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//�ۼ�����
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//�趨����
			d=(DataReceive[165]<<8)|DataReceive[166];
			ShowLongOrder(N1688,d);
			//�趨����ϵ��
			d=(DataReceive[167]<<8)|DataReceive[168];
			ShowLongOrder(N1690,d);
			//PMT���Ƶ�ѹ
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT����
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
			//��ѹ����ֵ
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86����PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//������ֵ
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);	
			ShowLongOrder(N16B8,d);
			//����״̬
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//�ۼ�����
			d=((((u32)DataReceive[183]<<8)|DataReceive[184]))|((((u32)DataReceive[185]<<24)|(DataReceive[186]))<<16);	
			ShowLongOrder(N16D0,d);
			d=((((u32)DataReceive[187]<<8)|DataReceive[188]))|((((u32)DataReceive[189]<<24)|(DataReceive[190]))<<16);	
			ShowLongOrder(N16D8,d);
			d=((((u32)DataReceive[191]<<8)|DataReceive[192]))|((((u32)DataReceive[193]<<24)|(DataReceive[194]))<<16);	
			ShowLongOrder(N16E0,d);
			d=((((u32)DataReceive[195]<<8)|DataReceive[196]))|((((u32)DataReceive[197]<<24)|(DataReceive[198]))<<16);	
			ShowLongOrder(N16E8,d);
			d=((((u32)DataReceive[199]<<8)|DataReceive[200]))|((((u32)DataReceive[201]<<24)|(DataReceive[202]))<<16);	
			ShowLongOrder(N16F0,d);
			d=((((u32)DataReceive[203]<<8)|DataReceive[204]))|((((u32)DataReceive[205]<<24)|(DataReceive[206]))<<16);	
			ShowLongOrder(N16F8,d);
			d=((((u32)DataReceive[207]<<8)|DataReceive[208]))|((((u32)DataReceive[209]<<24)|(DataReceive[210]))<<16);	
			ShowLongOrder(N1700,d);
			d=((((u32)DataReceive[211]<<8)|DataReceive[212]))|((((u32)DataReceive[213]<<24)|(DataReceive[214]))<<16);	
			ShowLongOrder(N1708,d);
			//IP1
			d=(DataReceive[215]<<8)|DataReceive[216];
			ShowLongOrder(N15D0,d);
			d=(DataReceive[217]<<8)|DataReceive[218];
			ShowLongOrder(N15D8,d);
			d=(DataReceive[219]<<8)|DataReceive[220];
			ShowLongOrder(N15E0,d);
			d=(DataReceive[221]<<8)|DataReceive[222];
			ShowLongOrder(N15E8,d);
			//Port
			d=(DataReceive[223]<<8)|DataReceive[224];
			ShowLongOrder(N15F0,d);
			//IP�˿��޸�λ
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//���к�
			d=(DataReceive[227]<<8)|DataReceive[228];
			ShowLongOrder(N1710,d);
			
			d=(DataReceive[229]<<8)|DataReceive[230];
			ShowLongOrder(N1718,d);
			
			d=(DataReceive[231]<<8)|DataReceive[232];
			ShowLongOrder(N1720,d);
			
			d=(DataReceive[233]<<8)|DataReceive[234];
			ShowLongOrder(N1728,d);
			
			d=(DataReceive[235]<<8)|DataReceive[236];
			ShowLongOrder(N1730,d);
			
			d=(DataReceive[237]<<8)|DataReceive[238];
			ShowLongOrder(N1738,d);
			
			d=(DataReceive[239]<<8)|DataReceive[240];
			ShowLongOrder(N1740,d);
			
			d=(DataReceive[241]<<8)|DataReceive[242];
			ShowLongOrder(N1748,d);
			//���к�����
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//�趨Modbus�汾
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//�趨�豸�汾��
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);
		
	}	

	
	
	//�������
void showData_6(void)
{
	u32 d;
	if(EquipmentState == 1){
			//ShowLongOrder(N1088,d);
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);

			 
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			//44-50����
//			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//�۲�����
			d=((((u32)DataReceive[105]<<8)|DataReceive[106]))|((((u32)DataReceive[107]<<24)|(DataReceive[108]))<<16);	
			ShowLongOrder(N1600,d);
			Particle1_Ins = d;
			d=((((u32)DataReceive[109]<<8)|DataReceive[110]))|((((u32)DataReceive[111]<<24)|(DataReceive[112]))<<16);	
			ShowLongOrder(N1608,d);
			d=((((u32)DataReceive[113]<<8)|DataReceive[114]))|((((u32)DataReceive[115]<<24)|(DataReceive[116]))<<16);	
			ShowLongOrder(N1610,d);
			d=((((u32)DataReceive[117]<<8)|DataReceive[118]))|((((u32)DataReceive[119]<<24)|(DataReceive[120]))<<16);	
			ShowLongOrder(N1618,d);
			d=((((u32)DataReceive[121]<<8)|DataReceive[122]))|((((u32)DataReceive[123]<<24)|(DataReceive[124]))<<16);	
			ShowLongOrder(N1620,d);
			d=((((u32)DataReceive[125]<<8)|DataReceive[126]))|((((u32)DataReceive[127]<<24)|(DataReceive[128]))<<16);	
			ShowLongOrder(N1628,d);
			d=((((u32)DataReceive[129]<<8)|DataReceive[130]))|((((u32)DataReceive[131]<<24)|(DataReceive[132]))<<16);	
			ShowLongOrder(N1630,d);
			d=((((u32)DataReceive[133]<<8)|DataReceive[134]))|((((u32)DataReceive[135]<<24)|(DataReceive[136]))<<16);	
			ShowLongOrder(N1638,d);
			//67-69����
			//��Դ�����ж�
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//�¶�ֵ
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//����ʱ��
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1378,d);
			//˲ʱ����
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//�ۼ�����
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//��ѹ����ֵ
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86����PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//����״̬
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//�ۼ�����
			d=((((u32)DataReceive[183]<<8)|DataReceive[184]))|((((u32)DataReceive[185]<<24)|(DataReceive[186]))<<16);	
			ShowLongOrder(N16D0,d);
			d=((((u32)DataReceive[187]<<8)|DataReceive[188]))|((((u32)DataReceive[189]<<24)|(DataReceive[190]))<<16);	
			ShowLongOrder(N16D8,d);
			d=((((u32)DataReceive[191]<<8)|DataReceive[192]))|((((u32)DataReceive[193]<<24)|(DataReceive[194]))<<16);	
			ShowLongOrder(N16E0,d);
			d=((((u32)DataReceive[195]<<8)|DataReceive[196]))|((((u32)DataReceive[197]<<24)|(DataReceive[198]))<<16);	
			ShowLongOrder(N16E8,d);
			d=((((u32)DataReceive[199]<<8)|DataReceive[200]))|((((u32)DataReceive[201]<<24)|(DataReceive[202]))<<16);	
			ShowLongOrder(N16F0,d);
			d=((((u32)DataReceive[203]<<8)|DataReceive[204]))|((((u32)DataReceive[205]<<24)|(DataReceive[206]))<<16);	
			ShowLongOrder(N16F8,d);
			d=((((u32)DataReceive[207]<<8)|DataReceive[208]))|((((u32)DataReceive[209]<<24)|(DataReceive[210]))<<16);	
			ShowLongOrder(N1700,d);
			d=((((u32)DataReceive[211]<<8)|DataReceive[212]))|((((u32)DataReceive[213]<<24)|(DataReceive[214]))<<16);	
			ShowLongOrder(N1708,d);
			if(DelayTime == 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}if(DelayTime != 0){
				if(UpdataTimeDownNum == 1 && Particle1_Ins==0){
					Times++;
					ShowLongOrder(N1148,Times-1);
				}if(UpdataTimeDownNum && Particle1_Ins!=0){
					Times=0;
					ShowLongOrder(N1148,Times);
				}
			}
				
	}else{
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			DelayTime = d;
//			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
//			ShowLongOrder(N1070,d);
			 //��������
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			//44-50����
//			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//�۲�����
			d=((((u32)DataReceive[105]<<8)|DataReceive[106]))|((((u32)DataReceive[107]<<24)|(DataReceive[108]))<<16);	
			ShowLongOrder(N1600,d);
			d=((((u32)DataReceive[109]<<8)|DataReceive[110]))|((((u32)DataReceive[111]<<24)|(DataReceive[112]))<<16);	
			ShowLongOrder(N1608,d);
			d=((((u32)DataReceive[113]<<8)|DataReceive[114]))|((((u32)DataReceive[115]<<24)|(DataReceive[116]))<<16);	
			ShowLongOrder(N1610,d);
			d=((((u32)DataReceive[117]<<8)|DataReceive[118]))|((((u32)DataReceive[119]<<24)|(DataReceive[120]))<<16);	
			ShowLongOrder(N1618,d);
			d=((((u32)DataReceive[121]<<8)|DataReceive[122]))|((((u32)DataReceive[123]<<24)|(DataReceive[124]))<<16);	
			ShowLongOrder(N1620,d);
			d=((((u32)DataReceive[125]<<8)|DataReceive[126]))|((((u32)DataReceive[127]<<24)|(DataReceive[128]))<<16);	
			ShowLongOrder(N1628,d);
			d=((((u32)DataReceive[129]<<8)|DataReceive[130]))|((((u32)DataReceive[131]<<24)|(DataReceive[132]))<<16);	
			ShowLongOrder(N1630,d);
			d=((((u32)DataReceive[133]<<8)|DataReceive[134]))|((((u32)DataReceive[135]<<24)|(DataReceive[136]))<<16);	
			ShowLongOrder(N1638,d);
			//67-69����
			//��Դ�����ж�
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//��Դ���ϲ���
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
//			//�¶���ֵ
//			d=(DataReceive[149]<<8)|DataReceive[150];
//			ShowLongOrder(N1650,d);
//			//�¶�ֵ
//			d=(DataReceive[151]<<8)|DataReceive[152];
//			ShowLongOrder(N1658,d);
			//�趨����ͨ����
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//�������
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//��������
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//����ʱ��
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1678,d);
//			//˲ʱ����
//			d=(DataReceive[161]<<8)|DataReceive[162];
//			ShowLongOrder(N1680,d);
//			//�ۼ�����
//			d=(DataReceive[163]<<8)|DataReceive[164];
//			ShowLongOrder(N1768,d);
//			//�趨����
//			d=(DataReceive[165]<<8)|DataReceive[166];
//			ShowLongOrder(N1688,d);
//			//�趨����ϵ��
//			d=(DataReceive[167]<<8)|DataReceive[168];
//			ShowLongOrder(N1690,d);
			//PMT���Ƶ�ѹ
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT����
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
//			//��ѹ����ֵ
//			d=(DataReceive[173]<<8)|DataReceive[174];
//			ShowLongOrder(N16A8,d);
			//86����PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//������ֵ
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);	
			ShowLongOrder(N16B8,d);
			//����״̬
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//�ۼ�����
			d=((((u32)DataReceive[183]<<8)|DataReceive[184]))|((((u32)DataReceive[185]<<24)|(DataReceive[186]))<<16);	
			ShowLongOrder(N16D0,d);
			d=((((u32)DataReceive[187]<<8)|DataReceive[188]))|((((u32)DataReceive[189]<<24)|(DataReceive[190]))<<16);	
			ShowLongOrder(N16D8,d);
			d=((((u32)DataReceive[191]<<8)|DataReceive[192]))|((((u32)DataReceive[193]<<24)|(DataReceive[194]))<<16);	
			ShowLongOrder(N16E0,d);
			d=((((u32)DataReceive[195]<<8)|DataReceive[196]))|((((u32)DataReceive[197]<<24)|(DataReceive[198]))<<16);	
			ShowLongOrder(N16E8,d);
			d=((((u32)DataReceive[199]<<8)|DataReceive[200]))|((((u32)DataReceive[201]<<24)|(DataReceive[202]))<<16);	
			ShowLongOrder(N16F0,d);
			d=((((u32)DataReceive[203]<<8)|DataReceive[204]))|((((u32)DataReceive[205]<<24)|(DataReceive[206]))<<16);	
			ShowLongOrder(N16F8,d);
			d=((((u32)DataReceive[207]<<8)|DataReceive[208]))|((((u32)DataReceive[209]<<24)|(DataReceive[210]))<<16);	
			ShowLongOrder(N1700,d);
			d=((((u32)DataReceive[211]<<8)|DataReceive[212]))|((((u32)DataReceive[213]<<24)|(DataReceive[214]))<<16);	
			ShowLongOrder(N1708,d);
			//IP1
			d=(DataReceive[215]<<8)|DataReceive[216];
			ShowLongOrder(N15D0,d);
			d=(DataReceive[217]<<8)|DataReceive[218];
			ShowLongOrder(N15D8,d);
			d=(DataReceive[219]<<8)|DataReceive[220];
			ShowLongOrder(N15E0,d);
			d=(DataReceive[221]<<8)|DataReceive[222];
			ShowLongOrder(N15E8,d);
			//Port
			d=(DataReceive[223]<<8)|DataReceive[224];
			ShowLongOrder(N15F0,d);
			//IP�˿��޸�λ
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//���к�
			d=(DataReceive[227]<<8)|DataReceive[228];
			ShowLongOrder(N1710,d);
			
			d=(DataReceive[229]<<8)|DataReceive[230];
			ShowLongOrder(N1718,d);
			
			d=(DataReceive[231]<<8)|DataReceive[232];
			ShowLongOrder(N1720,d);
			
			d=(DataReceive[233]<<8)|DataReceive[234];
			ShowLongOrder(N1728,d);
			
			d=(DataReceive[235]<<8)|DataReceive[236];
			ShowLongOrder(N1730,d);
			
			d=(DataReceive[237]<<8)|DataReceive[238];
			ShowLongOrder(N1738,d);
			
			d=(DataReceive[239]<<8)|DataReceive[240];
			ShowLongOrder(N1740,d);
			
			d=(DataReceive[241]<<8)|DataReceive[242];
			ShowLongOrder(N1748,d);
			//���к�����
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//�趨Modbus�汾
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//�趨�豸�汾��
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);



	}
	
	
}
//�������
void showData1_6(void)
{
	u32 d;
			d=(DataReceive[3]<<8)|DataReceive[4];				//��ַ
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//������
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//��������
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//����
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//��ʱ
			ShowLongOrder(N1088,d);
			DelayTime = d;
//			d=(DataReceive[13]<<8)|DataReceive[14];				//��������ǰ�����ۼ�ʱ(��)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//����
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//���µ���ʱ
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//ͨ��У��λ��0-��У�飬1-żУ�飬2-��У�飨����λ�̶�8λ��У��λ��������λ֮��
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//�����ۼӴ�����1-200������������ϣ�һ�ξ���һ����
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//�Ƚϵ�ѹ1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//�Ƚϵ�ѹ2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//�Ƚϵ�ѹ3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//�Ƚϵ�ѹ4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//�Ƚϵ�ѹ5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//�Ƚϵ�ѹ6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//�Ƚϵ�ѹ7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//�Ƚϵ�ѹ8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//��ѹ��ֵ��
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//��ѹ��ֵ��
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//��ѹ����״̬
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//��ѹ����
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//��Դ��ֵ
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//��Դ����״̬
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//��Դ����
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//������ֵ
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//����״̬
//			ShowLongOrder(N1070,d);
			 //��������
			d=((((u32)DataReceive[59]<<8)|DataReceive[60]))|((((u32)DataReceive[61]<<24)|(DataReceive[62]))<<16);	
			ShowLongOrder(SoursData1,d);
			 
			d=((((u32)DataReceive[63]<<8)|DataReceive[64]))|((((u32)DataReceive[65]<<24)|(DataReceive[66]))<<16);
			ShowLongOrder(SoursData2,d);
			 
			d=((((u32)DataReceive[67]<<8)|DataReceive[68]))|((((u32)DataReceive[69]<<24)|(DataReceive[70]))<<16);
			ShowLongOrder(SoursData3,d);
			 
			d=((((u32)DataReceive[71]<<8)|DataReceive[72]))|((((u32)DataReceive[73]<<24)|(DataReceive[74]))<<16);
			ShowLongOrder(SoursData4,d);
			 
			d=((((u32)DataReceive[75]<<8)|DataReceive[76]))|((((u32)DataReceive[77]<<24)|(DataReceive[78]))<<16);
			ShowLongOrder(SoursData5,d);
			 
			d=((((u32)DataReceive[79]<<8)|DataReceive[80]))|((((u32)DataReceive[81]<<24)|(DataReceive[82]))<<16);
			ShowLongOrder(SoursData6,d);
			 
			d=((((u32)DataReceive[83]<<8)|DataReceive[84]))|((((u32)DataReceive[85]<<24)|(DataReceive[86]))<<16);
			ShowLongOrder(SoursData7,d);
			 
			d=((((u32)DataReceive[87]<<8)|DataReceive[88]))|((((u32)DataReceive[89]<<24)|(DataReceive[90]))<<16);
			ShowLongOrder(SoursData8,d);
			//44-50����
//			d=(DataReceive[91]<<8)|DataReceive[92];	//��ѹ��ֵ
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//�۲�����
			d=((((u32)DataReceive[105]<<8)|DataReceive[106]))|((((u32)DataReceive[107]<<24)|(DataReceive[108]))<<16);	
			ShowLongOrder(N1600,d);
			d=((((u32)DataReceive[109]<<8)|DataReceive[110]))|((((u32)DataReceive[111]<<24)|(DataReceive[112]))<<16);	
			ShowLongOrder(N1608,d);
			d=((((u32)DataReceive[113]<<8)|DataReceive[114]))|((((u32)DataReceive[115]<<24)|(DataReceive[116]))<<16);	
			ShowLongOrder(N1610,d);
			d=((((u32)DataReceive[117]<<8)|DataReceive[118]))|((((u32)DataReceive[119]<<24)|(DataReceive[120]))<<16);	
			ShowLongOrder(N1618,d);
			d=((((u32)DataReceive[121]<<8)|DataReceive[122]))|((((u32)DataReceive[123]<<24)|(DataReceive[124]))<<16);	
			ShowLongOrder(N1620,d);
			d=((((u32)DataReceive[125]<<8)|DataReceive[126]))|((((u32)DataReceive[127]<<24)|(DataReceive[128]))<<16);	
			ShowLongOrder(N1628,d);
			d=((((u32)DataReceive[129]<<8)|DataReceive[130]))|((((u32)DataReceive[131]<<24)|(DataReceive[132]))<<16);	
			ShowLongOrder(N1630,d);
			d=((((u32)DataReceive[133]<<8)|DataReceive[134]))|((((u32)DataReceive[135]<<24)|(DataReceive[136]))<<16);	
			ShowLongOrder(N1638,d);
			//67-69����
			//��Դ�����ж�
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//��Դ���ϲ���
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
//			//�¶���ֵ
//			d=(DataReceive[149]<<8)|DataReceive[150];
//			ShowLongOrder(N1650,d);
//			//�¶�ֵ
//			d=(DataReceive[151]<<8)|DataReceive[152];
//			ShowLongOrder(N1658,d);
			//�趨����ͨ����
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//�������
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//��������
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//����ʱ��
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1678,d);
//			//˲ʱ����
//			d=(DataReceive[161]<<8)|DataReceive[162];
//			ShowLongOrder(N1680,d);
//			//�ۼ�����
//			d=(DataReceive[163]<<8)|DataReceive[164];
//			ShowLongOrder(N1768,d);
//			//�趨����
//			d=(DataReceive[165]<<8)|DataReceive[166];
//			ShowLongOrder(N1688,d);
//			//�趨����ϵ��
//			d=(DataReceive[167]<<8)|DataReceive[168];
//			ShowLongOrder(N1690,d);
			//PMT���Ƶ�ѹ
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT����
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
//			//��ѹ����ֵ
//			d=(DataReceive[173]<<8)|DataReceive[174];
//			ShowLongOrder(N16A8,d);
			//86����PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//������ֵ
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);	
			ShowLongOrder(N16B8,d);
			//����״̬
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//�ۼ�����
			d=((((u32)DataReceive[183]<<8)|DataReceive[184]))|((((u32)DataReceive[185]<<24)|(DataReceive[186]))<<16);	
			ShowLongOrder(N16D0,d);
			d=((((u32)DataReceive[187]<<8)|DataReceive[188]))|((((u32)DataReceive[189]<<24)|(DataReceive[190]))<<16);	
			ShowLongOrder(N16D8,d);
			d=((((u32)DataReceive[191]<<8)|DataReceive[192]))|((((u32)DataReceive[193]<<24)|(DataReceive[194]))<<16);	
			ShowLongOrder(N16E0,d);
			d=((((u32)DataReceive[195]<<8)|DataReceive[196]))|((((u32)DataReceive[197]<<24)|(DataReceive[198]))<<16);	
			ShowLongOrder(N16E8,d);
			d=((((u32)DataReceive[199]<<8)|DataReceive[200]))|((((u32)DataReceive[201]<<24)|(DataReceive[202]))<<16);	
			ShowLongOrder(N16F0,d);
			d=((((u32)DataReceive[203]<<8)|DataReceive[204]))|((((u32)DataReceive[205]<<24)|(DataReceive[206]))<<16);	
			ShowLongOrder(N16F8,d);
			d=((((u32)DataReceive[207]<<8)|DataReceive[208]))|((((u32)DataReceive[209]<<24)|(DataReceive[210]))<<16);	
			ShowLongOrder(N1700,d);
			d=((((u32)DataReceive[211]<<8)|DataReceive[212]))|((((u32)DataReceive[213]<<24)|(DataReceive[214]))<<16);	
			ShowLongOrder(N1708,d);
			//IP1
			d=(DataReceive[215]<<8)|DataReceive[216];
			ShowLongOrder(N15D0,d);
			d=(DataReceive[217]<<8)|DataReceive[218];
			ShowLongOrder(N15D8,d);
			d=(DataReceive[219]<<8)|DataReceive[220];
			ShowLongOrder(N15E0,d);
			d=(DataReceive[221]<<8)|DataReceive[222];
			ShowLongOrder(N15E8,d);
			//Port
			d=(DataReceive[223]<<8)|DataReceive[224];
			ShowLongOrder(N15F0,d);
			//IP�˿��޸�λ
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//���к�
			d=(DataReceive[227]<<8)|DataReceive[228];
			ShowLongOrder(N1710,d);
			
			d=(DataReceive[229]<<8)|DataReceive[230];
			ShowLongOrder(N1718,d);
			
			d=(DataReceive[231]<<8)|DataReceive[232];
			ShowLongOrder(N1720,d);
			
			d=(DataReceive[233]<<8)|DataReceive[234];
			ShowLongOrder(N1728,d);
			
			d=(DataReceive[235]<<8)|DataReceive[236];
			ShowLongOrder(N1730,d);
			
			d=(DataReceive[237]<<8)|DataReceive[238];
			ShowLongOrder(N1738,d);
			
			d=(DataReceive[239]<<8)|DataReceive[240];
			ShowLongOrder(N1740,d);
			
			d=(DataReceive[241]<<8)|DataReceive[242];
			ShowLongOrder(N1748,d);
			//���к�����
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//�趨Modbus�汾
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//�趨�豸�汾��
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);
		
	}	
	
	
	

	


//��ѹ��ֵ��
void showSetPressureLow(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x13; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//��ѹ��ֵ��
void showSetPressureHigh(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x14; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//��·ѹ������,0�޹��ϣ�1���ͣ�2����
void showAirPressureState(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x15; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set021();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}
//��ѹ����
void showAirPressureNub(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x16; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
					//ͨ�ųɹ�����λ����ʾ
			Set022();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//��Դ��ֵ
void showLightThreshold(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x17; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//��Դ����״̬
void showLightState(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x18; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;

			Set024();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}
//��Դ����
void showLightReading(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x19; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set025();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}


//������ֵ
void showSaturationThreshold(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x1A; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//����״̬
void showSaturationState(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x1B; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set027();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//0.3um  ��������
void showData1Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x1C;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set028();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}
//0.3um  �������� ��16λ
void showData1High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x1D; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			u8 res;
			ModbusRx.ModbusReceDoneNum=0;
			res=ModbusReceiveOrderCheck();		//���Ӧ��ָ��
			if(res==0xff)											//ָ����ȷ
			{
					//ͨ�ųɹ�����λ����ʾ
					//send_uart3_string("ID:SSSS202008N254*");
			}
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//0.5um  ��������
void showData2Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x1E;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
					//ͨ�ųɹ�����λ����ʾ
			Set030();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}


//0.5um  �������� ��16λ
void showData2High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x1F; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//���Ӧ��ָ��
//			if(res==0xff)											//ָ����ȷ
//			{
//					//ͨ�ųɹ�����λ����ʾ
//					//send_uart3_string("ID:SSSS202008N255*");
//			}
//	}
//	else	//ͨ�ų�ʱ
//	{
//		
//	}
}

//1.0um  �������� ��16λ
void showData3Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x20;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
					//ͨ�ųɹ�����λ����ʾ
			Set032();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//1.0um  �������� ��16λ
void showData3High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x21; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//���Ӧ��ָ��
//			if(res==0xff)											//ָ����ȷ
//			{
//					//ͨ�ųɹ�����λ����ʾ
//					//Set034();
//			}
//	}
//	else	//ͨ�ų�ʱ
//	{
//		
//	}
}
//3.0um  �������� ��16λ
void showData4Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x22;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set034();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//3.0um  �������� ��16λ
void showData4High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x23; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//���Ӧ��ָ��
//			if(res==0xff)											//ָ����ȷ
//			{
//					//ͨ�ųɹ�����λ����ʾ
//					//send_uart3_string("ID:SSSS202008N261*");
//			}
//	}
//	else	//ͨ�ų�ʱ
//	{
//		
//	}
}
//5.0um  �������� ��16λ
void showData5Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x24;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
					//ͨ�ųɹ�����λ����ʾ
			Set036();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//5.0um  �������� ��16λ
void showData5High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x25; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//���Ӧ��ָ��
//			if(res==0xff)											//ָ����ȷ
//			{
//					//ͨ�ųɹ�����λ����ʾ
//			}
//	}
//	else	//ͨ�ų�ʱ
//	{
//		
//	}
}
//10.0um  �������� ��16λ
void showData6Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x26;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set038();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//10.0um  �������� ��16λ
void showData6High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x27; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//���Ӧ��ָ��
//			if(res==0xff)											//ָ����ȷ
//			{
//					//ͨ�ųɹ�����λ����ʾ
//			}
//	}
//	else	//ͨ�ų�ʱ
//	{
//		
//	}
}
//���ͱ���������16λ
void showData7Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x28;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set040();

	}
	else	//ͨ�ų�ʱ
	{
		
	}
}

//���ͱ���������16λ
void showData7High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x29; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//���Ӧ��ָ��
//			if(res==0xff)											//ָ����ȷ
//			{
//					//ͨ�ųɹ�����λ����ʾ
//			}
//	}
//	else	//ͨ�ų�ʱ
//	{
//		
//	}
}
//��Դ�����жϼ�����16λ
void showData8Low(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x2A;
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x02;
	ModbusTx.Txbuf[6]=0x04;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data1>>24; 
	ModbusTx.Txbuf[10]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,11);
	ModbusTx.Txbuf[11]=crc>>8;
	ModbusTx.Txbuf[12]=crc;
	ModbusTx.Txlen=13;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
			//ͨ�ųɹ�����λ����ʾ
			Set042();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}
//��Դ�����жϼ�����16λ
void showData8High(u32 r_data1)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x2B; 
	ModbusTx.Txbuf[4]=r_data1>>24; 
	ModbusTx.Txbuf[5]=r_data1>>16;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck16();		//���Ӧ��ָ��
//			if(res==0xff)											//ָ����ȷ
//			{
//					//ͨ�ųɹ�����λ����ʾ
//			}
//	}
//	else	//ͨ�ų�ʱ
//	{
//		
//	}
}
//��ѹ��ֵ
void showSetPressureThreshold(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x2C; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//IP
void showSetIP(u16 r_data1,u16 r_data2,u16 r_data3,u16 r_data4)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x32; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x04;
	ModbusTx.Txbuf[6]=0x08;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data2>>8; 
	ModbusTx.Txbuf[10]=r_data2;
	ModbusTx.Txbuf[11]=r_data3>>8; 
	ModbusTx.Txbuf[12]=r_data3;
	ModbusTx.Txbuf[13]=r_data4>>8; 
	ModbusTx.Txbuf[14]=r_data4;
	crc=crc16(ModbusTx.Txbuf,15);
	ModbusTx.Txbuf[15]=crc>>8;
	ModbusTx.Txbuf[16]=crc;
	ModbusTx.Txlen=17;
	ModbusSendOrder();//
}
//�˿�
void showSetPort(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x36; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//IP�Ͷ˿ڵ��޸�λ
void showSetIPAndPort(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x37; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//��������ʱ
void showSetUpdateTiming(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x38; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	if(ModbusRx.ModbusReceDoneNum>=3)          		//Ӧ��������
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set056();
	}
	else	//ͨ�ų�ʱ
	{
		
	}
}
void sendAllData(){

}
//___________________________________________________________________________________________________________
//0.1����
//���õ�ַ
void showSetAddress_uart3_1(u8 r_data)
{
	u16 crc;
//	u16 val;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x00; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

////���ò�����
//void showSetBaudRate(u8 r_data)
//{
//	u16 crc;
//	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
//	ModbusTx.Txbuf[1]=0x06;
//	ModbusTx.Txbuf[2]=0x00;
//	ModbusTx.Txbuf[3]=0x24; 
//	ModbusTx.Txbuf[4]=r_data>>8; 
//	ModbusTx.Txbuf[5]=r_data;
//	crc=crc16(ModbusTx.Txbuf,6);
//	ModbusTx.Txbuf[6]=crc>>8;
//	ModbusTx.Txbuf[7]=crc;
//	ModbusTx.Txlen=8;
//	ModbusSendOrder1();//
//	
//	SetBaudRate(r_data);
//	delay_ms(1000);
//	delay_ms(1000);
//	//delay_ms(20);
//	//�޸��겨���ʣ��ٷ�һ��
//	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
//	ModbusTx.Txbuf[1]=0x06;
//	ModbusTx.Txbuf[2]=0x00;
//	ModbusTx.Txbuf[3]=0x24; 
//	ModbusTx.Txbuf[4]=r_data>>8; 
//	ModbusTx.Txbuf[5]=r_data;
//	crc=crc16(ModbusTx.Txbuf,6);
//	ModbusTx.Txbuf[6]=crc>>8;
//	ModbusTx.Txbuf[7]=crc;
//	ModbusTx.Txlen=8;
//	ModbusSendOrder();//

//}
//����
void showOpen_uart3_1(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x03; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x01; 
	ModbusTx.Txbuf[6]=0xAD; 
	ModbusTx.Txbuf[7]=0xE7;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	
}
//�ػ�
void showClose_uart3_1(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x03; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x00; 
	ModbusTx.Txbuf[6]=0x6C; 
	ModbusTx.Txbuf[7]=0x27;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���Կ�
void showSetDebugStateON_1(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x29; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=0x01;
	ModbusTx.Txbuf[6]=0x8C;
	ModbusTx.Txbuf[7]=0x2F;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//���Թ�
void showSetDebugStateOFF_1(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x29; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=0x00;
	ModbusTx.Txbuf[6]=0x4D;
	ModbusTx.Txbuf[7]=0xEF;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//����PWM
void showSetPumpPwm_1(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x26; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//ͨ��У��
void showCommunicationCheck_1(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x25; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//��ѹ��ֵ��
void showSetPressureLow_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x2B; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//��ѹ��ֵ��
void showSetPressureHigh_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x2C; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//���õ���
void showSetAirPumpResistance_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x2A; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//���ù���ʱ��
void showSetWorkTime_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//����������ʱ
void showSetWorkDelay_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x02; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���õ�һ�Ƚϵ�ѹ
void showSetComparisonVoltage1_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x3D; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage2_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x3E; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage3_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x3F; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//���õ��ıȽϵ�ѹ
void showSetComparisonVoltage4_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x40; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ���Ƚϵ�ѹ
void showSetComparisonVoltage5_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x41; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ����Ƚϵ�ѹ
void showSetComparisonVoltage6_1(u16 r_data)
{
		u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x42; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//���õ��߱Ƚϵ�ѹ
void showSetComparisonVoltage7_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x43; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//���õ��˱Ƚϵ�ѹ
void showSetComparisonVoltage8_1(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x44; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}


//----------------------------------------------------------------------------
//3.����������
//���õ�ַ
void showSetAddress_uart3_3(u8 r_data)
{
	u16 crc;
//	u16 val;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x00; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

void showSetBaudRate_3(u8 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder1();//
	
	SetBaudRate_3(r_data);
	delay_ms(1000);
	delay_ms(1000);
	//�޸��겨���ʣ��ٷ�һ��
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x01; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}

//����
void showOpen_uart3_3(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x03; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x01; 
	ModbusTx.Txbuf[6]=0xAD; 
	ModbusTx.Txbuf[7]=0xE7;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	
}
//�ػ�
void showClose_uart3_3(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x03; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x00; 
	ModbusTx.Txbuf[6]=0x6C; 
	ModbusTx.Txbuf[7]=0x27;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���Կ�
void showSetDebugStateON_3(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x29; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=0x01;
	ModbusTx.Txbuf[6]=0x8C;
	ModbusTx.Txbuf[7]=0x2F;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//���Թ�
void showSetDebugStateOFF_3(void)
{
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x29; 
	ModbusTx.Txbuf[4]=0x00; 
	ModbusTx.Txbuf[5]=0x00;
	ModbusTx.Txbuf[6]=0x4D;
	ModbusTx.Txbuf[7]=0xEF;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//----------------------------------------------------------------------------
//��ѹ0.1
//��Դ���ϲ���
void ShowLightFailureMeasurement(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x48; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//�¶���ֵ
void ShowTemperatureThreshold(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x49; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}

//�趨����ͨ����
void ShowSetNumberChannels(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x4B; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//�������
void ShowSamplingInterval(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x4C; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
	
}
//��������
void ShowSamplingFrequency(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x4D; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//�趨����
void ShowSetFlow(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x51; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//�趨����ϵ��
void ShowSetGasCoefficient(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x52; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//PMT���Ƶ�ѹ
void ShowPMTControlVoltage(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x53; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//PMT����
void ShowPMTResistance(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x54; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//����PWM
void ShowAirPumpPWM(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x56; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//������ֵ
void ShowAlarmThreshold(u32 r_data1)
{
		u16 crc;
		ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
		ModbusTx.Txbuf[1]=0x10;
		ModbusTx.Txbuf[2]=0x00;
		ModbusTx.Txbuf[3]=0x57;
		ModbusTx.Txbuf[4]=0x00;
		ModbusTx.Txbuf[5]=0x02;
		ModbusTx.Txbuf[6]=0x04;
		ModbusTx.Txbuf[7]=r_data1>>24; 
		ModbusTx.Txbuf[8]=r_data1>>16;
		ModbusTx.Txbuf[9]=r_data1>>8; 
		ModbusTx.Txbuf[10]=r_data1;
		crc=crc16(ModbusTx.Txbuf,11);
		ModbusTx.Txbuf[11]=crc>>8;
		ModbusTx.Txbuf[12]=crc;
		ModbusTx.Txlen=13;
		ModbusSendOrder();//
}
//������ֵ��
void ShowAlarmThresholdHigh(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x57; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
		

	
}
//������ֵ��
void ShowAlarmThresholdLow(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x58; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//IP
void showSetIP_5(u16 r_data1,u16 r_data2,u16 r_data3,u16 r_data4)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x10;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x6A; 
	ModbusTx.Txbuf[4]=0x00;
	ModbusTx.Txbuf[5]=0x04;
	ModbusTx.Txbuf[6]=0x08;
	ModbusTx.Txbuf[7]=r_data1>>8; 
	ModbusTx.Txbuf[8]=r_data1;
	ModbusTx.Txbuf[9]=r_data2>>8; 
	ModbusTx.Txbuf[10]=r_data2;
	ModbusTx.Txbuf[11]=r_data3>>8; 
	ModbusTx.Txbuf[12]=r_data3;
	ModbusTx.Txbuf[13]=r_data4>>8; 
	ModbusTx.Txbuf[14]=r_data4;
	crc=crc16(ModbusTx.Txbuf,15);
	ModbusTx.Txbuf[15]=crc>>8;
	ModbusTx.Txbuf[16]=crc;
	ModbusTx.Txlen=17;
	ModbusSendOrder();//
}
//�˿�
void ShowPortData_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x6E; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//

}
//IP�˿��޸�λ
void ShowIPAndPortChange_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x6F; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�1
void ShowSerialNumber1_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x70; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�2
void ShowSerialNumber2_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x71; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�3
void ShowSerialNumber3_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x72; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�4
void ShowSerialNumber4_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x73; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�5
void ShowSerialNumber5_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x74; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�6
void ShowSerialNumber6_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x75; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�7
void ShowSerialNumber7_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x76; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�8
void ShowSerialNumber8_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x77; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//���к�����
void ShowSetSerialNumber_5(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x78; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//�趨Modbus�汾
void ShowSetModbusVersion(u16 r_data)
{
 u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x79; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}
//�趨�豸�汾��
void ShowSetDeviceVersion(u16 r_data)
{
	u16 crc;
	ModbusTx.Txbuf[0]=ModbusBroadcastAddress;
	ModbusTx.Txbuf[1]=0x06;
	ModbusTx.Txbuf[2]=0x00;
	ModbusTx.Txbuf[3]=0x7A; 
	ModbusTx.Txbuf[4]=r_data>>8; 
	ModbusTx.Txbuf[5]=r_data;
	crc=crc16(ModbusTx.Txbuf,6);
	ModbusTx.Txbuf[6]=crc>>8;
	ModbusTx.Txbuf[7]=crc;
	ModbusTx.Txlen=8;
	ModbusSendOrder();//
}


//-----------------------------------------------------------------------------
