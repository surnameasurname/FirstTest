#include "show3.h"
#include "uart.h"
#include "communication.h"
#include "DataChange.h"
#include "show1.h"
#include "delay.h"
#include "equipment.h"
#include "conflash.h"
//输出仪器ID 
void show_ID_uart3(void)
{
	send_uart3_string("ID:SSS202005");
}


//设置地址
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


//1.世尘1-9600，2-19200(出厂默认)，3-38400
//2.0.3（510）1-9600，2-19200（出厂默认2），3-38400，4-57600，5-115200
//3.气溶胶1-9600，2-19200（出厂默认），3-38400
//4.0.1 大流量 1-9600，2-19200（出厂默认），3-38400


//设置波特率
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
	//修改完波特率，再发一次
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
	//修改完波特率，再发一次
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
	//修改完波特率，再发一次
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
	//修改完波特率，再发一次
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
	//修改完波特率，再发一次
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
	//修改完波特率，再发一次
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


//开机
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
//关机
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


//设置工作时间
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

//设置启动延时
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
//计数器当前计数累计时
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set005();
	}
	else	//通信超时
	{
		
	}
}
//调试开
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

//调试关
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

//设置PWM
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

//更新倒计时
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
					//通信成功，上位机显示
			Set008();
	}
	else	//通信超时
	{
		
	}
}

//通信校验
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
//工作累加次数
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
//设置档一比较电压
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
//设置档二比较电压
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

//设置档三比较电压
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
//设置档四比较电压
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

//设置档五比较电压
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

//设置档六比较电压
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
//设置档七比较电压
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

//设置档八比较电压
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

////一键设置
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
////	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
////	{
////			u8 res;
////			ModbusRx.ModbusReceDoneNum=0;
////			res=ModbusReceiveOrderCheck16();		//检查应答指令
////			if(res==0xff)											//指令正确
////			{
////					//通信成功，上位机显示
////					SetData();
////			}
////	}
////	else	//通信超时
////	{
////		
////	}
//}
//一键设置
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
	ModbusTx.Txbuf[46]=0x00;		//--45-46————20
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
					//通信成功，上位机显示
			//ShowDataforAll();
	}
	else	//通信超时
	{
		
	}
}

////输出数据
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
//	send_uart3_string(DataChangeNumberToString(d));//设备号，地址
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[5]<<8)|ModbusRx.Rxbuf[6];
//	send_uart3_string(DataChangeNumberToString(d));//波特率
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[7]<<8)|ModbusRx.Rxbuf[8];
//	send_uart3_string(DataChangeNumberToString(d));//仪器状态，启动，停止
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[9]<<8)|ModbusRx.Rxbuf[10];
//	send_uart3_string(DataChangeNumberToString(d));//计数器的周期
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[11]<<8)|ModbusRx.Rxbuf[12];
//	send_uart3_string(DataChangeNumberToString(d));//计数器的启动延时
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[13]<<8)|ModbusRx.Rxbuf[14];
//	send_uart3_string(DataChangeNumberToString(d));//当前累计计时
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[15]<<8)|ModbusRx.Rxbuf[16];
//	send_uart3_string(DataChangeNumberToString(d));//调试模式
//	send_uart3(',');	
//	
//	d=(ModbusRx.Rxbuf[17]<<8)|ModbusRx.Rxbuf[18];
//	send_uart3_string(DataChangeNumberToString(d));//设置气泵PWM
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[19]<<8)|ModbusRx.Rxbuf[20];
//	send_uart3_string(DataChangeNumberToString(d));//更新倒计时
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[21]<<8)|ModbusRx.Rxbuf[22];
//	send_uart3_string(DataChangeNumberToString(d));//通信校验位
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[23]<<8)|ModbusRx.Rxbuf[24];
//	send_uart3_string(DataChangeNumberToString(d));//工作累加次数
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[25]<<8)|ModbusRx.Rxbuf[26];
//	send_uart3_string(DataChangeNumberToString(d));//设置档一比较电压，0.3
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[27]<<8)|ModbusRx.Rxbuf[28];
//	send_uart3_string(DataChangeNumberToString(d));//设置档二比较电压，0.5
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[29]<<8)|ModbusRx.Rxbuf[30];
//	send_uart3_string(DataChangeNumberToString(d));//设置档三比较电压，1.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[31]<<8)|ModbusRx.Rxbuf[32];
//	send_uart3_string(DataChangeNumberToString(d));//设置档四比较电压，3.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[33]<<8)|ModbusRx.Rxbuf[34];
//	send_uart3_string(DataChangeNumberToString(d));//设置档五比较电压，5.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[35]<<8)|ModbusRx.Rxbuf[36];
//	send_uart3_string(DataChangeNumberToString(d));//设置档六比较电压，10.0
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[37]<<8)|ModbusRx.Rxbuf[38];
//	send_uart3_string(DataChangeNumberToString(d));//设置档七比较电压
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[39]<<8)|ModbusRx.Rxbuf[40];
//	send_uart3_string(DataChangeNumberToString(d));//设置档八比较电压
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[41]<<8)|ModbusRx.Rxbuf[42];
//	send_uart3_string(DataChangeNumberToString(d));//气压阈值低
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[43]<<8)|ModbusRx.Rxbuf[44];
//	send_uart3_string(DataChangeNumberToString(d));//气压阈值高
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[45]<<8)|ModbusRx.Rxbuf[46];
//	send_uart3_string(DataChangeNumberToString(d));//气压故障状态
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[47]<<8)|ModbusRx.Rxbuf[48];
//	send_uart3_string(DataChangeNumberToString(d));//气压读数
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[49]<<8)|ModbusRx.Rxbuf[50];
//	send_uart3_string(DataChangeNumberToString(d));//光源阈值
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[51]<<8)|ModbusRx.Rxbuf[52];
//	send_uart3_string(DataChangeNumberToString(d));//光源故障状态
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[53]<<8)|ModbusRx.Rxbuf[54];
//	send_uart3_string(DataChangeNumberToString(d));//光源读数
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[55]<<8)|ModbusRx.Rxbuf[56];
//	send_uart3_string(DataChangeNumberToString(d));//饱和阈值
//	send_uart3(',');
//	d=(ModbusRx.Rxbuf[57]<<8)|ModbusRx.Rxbuf[58];
//	send_uart3_string(DataChangeNumberToString(d));//饱和状态
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[59]<<8)|ModbusRx.Rxbuf[60]))|((((u32)ModbusRx.Rxbuf[61]<<8)|(ModbusRx.Rxbuf[62]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档一数值，0.3
//	send_uart3(',');	
//	
//	d2=((((u32)ModbusRx.Rxbuf[63]<<8)|ModbusRx.Rxbuf[64]))|((((u32)ModbusRx.Rxbuf[65]<<8)|(ModbusRx.Rxbuf[66]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档二数值，0.5
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[67]<<8)|ModbusRx.Rxbuf[68]))|((((u32)ModbusRx.Rxbuf[69]<<8)|(ModbusRx.Rxbuf[70]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档三数值，1.0
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[71]<<8)|ModbusRx.Rxbuf[72]))|((((u32)ModbusRx.Rxbuf[73]<<8)|(ModbusRx.Rxbuf[74]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档四数值，3.0
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[75]<<8)|ModbusRx.Rxbuf[76]))|((((u32)ModbusRx.Rxbuf[77]<<8)|(ModbusRx.Rxbuf[78]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档五数值，5.0
//	send_uart3(',');
//	
//	d2=((((u32)ModbusRx.Rxbuf[79]<<8)|ModbusRx.Rxbuf[80]))|((((u32)ModbusRx.Rxbuf[81]<<8)|(ModbusRx.Rxbuf[82]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档六数值，10.0
//	send_uart3(',');

//	d2=((((u32)ModbusRx.Rxbuf[83]<<8)|ModbusRx.Rxbuf[84]))|((((u32)ModbusRx.Rxbuf[85]<<8)|(ModbusRx.Rxbuf[86]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档七预留
//	send_uart3(',');	

//	d2=((((u32)ModbusRx.Rxbuf[87]<<8)|ModbusRx.Rxbuf[88]))|((((u32)ModbusRx.Rxbuf[89]<<8)|(ModbusRx.Rxbuf[90]))<<16);
//	send_uart3_string(DataChangeNumberToString(d2));//档八预留
//	send_uart3(',');
//	
//	d=(ModbusRx.Rxbuf[91]<<8)|ModbusRx.Rxbuf[92];
//	send_uart3_string(DataChangeNumberToString(d));//更新正计时
//	send_uart3_string(";*");
//	
//	//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,0,0,");//地址44-61，预留给8个档累计数据
//	
////	send_uart3(ModbusRx.Rxbuf[89]);//粒子计数器设备唯一ID，比如Y 2020 05 20 001
//}
//输出数据
void showData_1(void)
{
	u32 d;
	if(EquipmentState == 1){
			d=(DataReceive[7]<<8)|DataReceive[8];				//延时
			DelayTime = d;
			ShowLongOrder(N1460,d);
			//周期数据
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
			//观察数据
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


			d=(DataReceive[81]<<8)|DataReceive[82];					//更新倒计时
			UpdataTimeDownNum = d;
			ShowLongOrder(N1420,d);
			d=(DataReceive[83]<<8)|DataReceive[84];					//更新正计时		
			ShowLongOrder(N1450,d);		 
			d=(DataReceive[93]<<8)|DataReceive[94];//气压读数
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
//			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
//			ShowLongOrder(N1400,d);
			d=(DataReceive[5]<<8)|DataReceive[6];				//周期
			ShowLongOrder(N1458,d);
			d=(DataReceive[7]<<8)|DataReceive[8];				//延时
			ShowLongOrder(N1460,d);
//			d=(DataReceive[9]<<8)|DataReceive[10];				//仪器开关
//			ShowOrder(N1411,d);
			//周期数据
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
			//观察数据
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
	
			d=(DataReceive[75]<<8)|DataReceive[76];				//波特率
			ShowLongOrder(N1408,d);
			 
			d=(DataReceive[77]<<8)|DataReceive[78];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			ShowLongOrder(N1428,d);
			d=(DataReceive[79]<<8)|DataReceive[80];					//PWM
			ShowLongOrder(N1418,d);
			d=(DataReceive[81]<<8)|DataReceive[82];					//更新倒计时
			ShowLongOrder(N1420,d);
			d=(DataReceive[83]<<8)|DataReceive[84];					//更新正计时		
			ShowLongOrder(N1450,d);		 
//			d=(DataReceive[85]<<8)|DataReceive[86];				//调试
//			ShowOrder(N1413,d);
			d=(DataReceive[87]<<8)|DataReceive[88];					//气泵电阻
			ShowLongOrder(N1448,d);
			d=(DataReceive[89]<<8)|DataReceive[90];//气压阈值低
			ShowLongOrder(N1430,d);
			 
			d=(DataReceive[91]<<8)|DataReceive[92];//气压阈值高
			ShowLongOrder(N1438,d);
			 
			d=(DataReceive[93]<<8)|DataReceive[94];//气压读数
			ShowLongOrder(N1440,d);
			
//		46-59
//		95-122
			d=(DataReceive[123]<<8)|DataReceive[124];				//地址
			Address = d;
			ShowLongOrder(N1400,d);
			d=(DataReceive[125]<<8)|DataReceive[126];					//比较电压1
			ShowOrder(N14E8,d);
			 
			d=(DataReceive[127]<<8)|DataReceive[128];					//比较电压2
			ShowOrder(N14F0,d);
			 
			d=(DataReceive[129]<<8)|DataReceive[130];					//比较电压3
			ShowOrder(N14F8,d);
			 
			d=(DataReceive[131]<<8)|DataReceive[132];					//比较电压4
			ShowOrder(N1500,d);
			 
			d=(DataReceive[133]<<8)|DataReceive[134];					//比较电压5
			ShowOrder(N1508,d);
			 
			d=(DataReceive[135]<<8)|DataReceive[136];					//比较电压6
			ShowOrder(N1510,d);
			 
			d=(DataReceive[137]<<8)|DataReceive[138];					//比较电压7
			ShowOrder(N1518,d);
			 		
			d=(DataReceive[139]<<8)|DataReceive[140];					//比较电压8
			ShowOrder(N1520,d);
			
			FlagVoltage = d;
	}
	
	
}
//输出数据
void showData1_1(void)
{
	u32 d;
			
			
			d=(DataReceive[5]<<8)|DataReceive[6];				//周期
			WorkPeriod = d;
			ShowLongOrder(N1458,d);
			d=(DataReceive[7]<<8)|DataReceive[8];				//延时
			DelayTime = d;
			ShowLongOrder(N1460,d);
//			d=(DataReceive[9]<<8)|DataReceive[10];				//仪器开关
//			ShowOrder(N1411,d);
			//周期数据
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
			//观察数据
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
	
			d=(DataReceive[75]<<8)|DataReceive[76];				//波特率
			BTL = d;
			ShowLongOrder(N1408,d);
			 
			d=(DataReceive[77]<<8)|DataReceive[78];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			CommunicationCheck = d;
			ShowLongOrder(N1428,d);
			d=(DataReceive[79]<<8)|DataReceive[80];					//PWM
			PumpPWM = d;
			ShowLongOrder(N1418,d);
			d=(DataReceive[81]<<8)|DataReceive[82];					//更新倒计时
			ShowLongOrder(N1420,d);
			d=(DataReceive[83]<<8)|DataReceive[84];					//更新正计时		
			ShowLongOrder(N1450,d);		 
//			d=(DataReceive[85]<<8)|DataReceive[86];				//调试
//			ShowOrder(N1413,d);
			d=(DataReceive[87]<<8)|DataReceive[88];					//气泵电阻
			AirPumpResistance = d;
			ShowLongOrder(N1448,d);
			d=(DataReceive[89]<<8)|DataReceive[90];//气压阈值低
			PressureLow = d;
			ShowLongOrder(N1430,d);
			 
			d=(DataReceive[91]<<8)|DataReceive[92];//气压阈值高
			PressureHigh = d;
			ShowLongOrder(N1438,d);
			 
			d=(DataReceive[93]<<8)|DataReceive[94];//气压读数
			ShowLongOrder(N1440,d);
			
//		46-59
//		95-122
			d=(DataReceive[123]<<8)|DataReceive[124];				//地址
			Address = d;
			ShowLongOrder(N1400,d);
			d=(DataReceive[125]<<8)|DataReceive[126];					//比较电压1
			ComparisonVoltage1 = d;
			ShowOrder(N14E8,d);
			 
			d=(DataReceive[127]<<8)|DataReceive[128];					//比较电压2
			ComparisonVoltage2 = d;
			ShowOrder(N14F0,d);
			 
			d=(DataReceive[129]<<8)|DataReceive[130];					//比较电压3
			ComparisonVoltage3 = d;
			ShowOrder(N14F8,d);
			 
			d=(DataReceive[131]<<8)|DataReceive[132];					//比较电压4
			ComparisonVoltage4 = d;
			ShowOrder(N1500,d);
			 
			d=(DataReceive[133]<<8)|DataReceive[134];					//比较电压5
			ComparisonVoltage5 = d;
			ShowOrder(N1508,d);
			 
			d=(DataReceive[135]<<8)|DataReceive[136];					//比较电压6
			ComparisonVoltage6 = d;
			ShowOrder(N1510,d);
			 
			d=(DataReceive[137]<<8)|DataReceive[138];					//比较电压7
			ComparisonVoltage7 = d;
			ShowOrder(N1518,d);
			 		
			d=(DataReceive[139]<<8)|DataReceive[140];					//比较电压8
			ComparisonVoltage8 = d;
			ShowOrder(N1520,d);
			 
	}
//输出数据
void showData_2(void)
{
	u32 d;
	if(EquipmentState == 1){
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
			ShowLongOrder(N1070,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
//			ShowLongOrder(N1068,d);
//			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];//更新倒计时
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);			
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			DelayTime = d;
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];//计数器当前累计时
			ShowLongOrder(N1010,d);
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
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
			d=(DataReceive[115]<<8)|DataReceive[116];	//更新正计时
			ShowLongOrder(N1078,d);
			//累加数
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
			
			if(Particle1_Ins==0)		//计时
			{
					Times++;
					ShowLongOrder(N1148,Times);
			}else{
					Times = 0;
					ShowLongOrder(N1148,Times);
			}
			
			//			//无延时
			if(DelayTime == 0){
					
					if(UpdataTimeDownNum == 1){
							//存储
						//RememberNum++;
						WriteNumber();
					}
			}
			//有延时
			if(DelayTime != 0){

					if(RememberTimes == 1){

						if(UpdataTimeDownNum == 1){
							//存储
							//RememberNum++;
							WriteNumber();
						}
					
					}
					
					if(UpdataTimeDownNum == 1){
							RememberTimes = 1;
					}
				}	
			
			
			
			
//			//无延时
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
//							//存储
//					}
//			}
//			//有延时
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
//							//存储
//						}
//					
//					}
//					
//					if(UpdataTimeDownNum == 1){
//							RememberTimes = 1;
//					}
//				}	
	}else{
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
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
			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
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
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP和端口的修改位
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//更新正计时
			//累加数
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
//输出数据
void showData1_2(void)
{
			u32 d;
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			 
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			 
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
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
			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
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
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP和端口的修改位
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//更新正计时
			//累加数
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
	//输出数据
void showData_3(void)
{
	u32 d;
	if(EquipmentState == 1){
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
			ShowLongOrder(N1070,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
//			ShowLongOrder(N1068,d);
//			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];//更新倒计时
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);			
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			DelayTime = d;
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];//计数器当前累计时
			ShowLongOrder(N1010,d);
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
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
			d=(DataReceive[115]<<8)|DataReceive[116];	//更新正计时
			ShowLongOrder(N1078,d);
			//累加数
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
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
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
			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
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
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP和端口的修改位
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//更新正计时
			//累加数
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
//输出数据
void showData1_3(void)
{
	u32 d;
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			 
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			 
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
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
			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
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
			d=(DataReceive[113]<<8)|DataReceive[114];	//IP和端口的修改位
			ShowLongOrder(N1140,d);
			d=(DataReceive[115]<<8)|DataReceive[116];
			ShowLongOrder(N1078,d);
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//更新正计时
			//累加数
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

	
	//输出数据
void showData_4(void)
{
	u32 d;
	if(EquipmentState == 1){

			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
			ShowLongOrder(N1070,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
//			ShowLongOrder(N1068,d);
//			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];//更新倒计时
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);			
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			DelayTime = d;
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];//计数器当前累计时
			ShowLongOrder(N1010,d);
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
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
			d=(DataReceive[115]<<8)|DataReceive[116];	//更新正计时
			ShowLongOrder(N1078,d);
			//累加数
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
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
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
			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
			ShowLongOrder(N1138,d);
			

			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//更新正计时
			//累加数
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
//输出数据
void showData1_4(void)
{
	u32 d;
			d=(DataReceive[57]<<8)|DataReceive[58];			//饱和状态
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			 
			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
			ShowLongOrder(N1010,d);
			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			 
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			 
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
			ShowLongOrder(N1068,d);
			 
			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
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
			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
			ShowLongOrder(N1138,d);
			
			//send_uart3_string("0,0,0,0,0,0,0,0,0,0,0,0,");//44-55
			d=(DataReceive[115]<<8)|DataReceive[124];
			ShowLongOrder(N1078,d);		//更新正计时
		
	}	

	
	//输出数据
void showData_5(void)
{
	u32 d;
	if(EquipmentState == 1){
			//ShowLongOrder(N1088,d);
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
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
			//44-50备用
//			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//观察数据
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
			//67-69备用
			//光源故障判断
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//温度值
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//工作时间
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1378,d);
			//瞬时流量
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//累计流量
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//气压计算值
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86气泵PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//报警状态
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//累计周期
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
			
			 
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			DelayTime = d;
			 
//			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
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
			//44-50备用
//			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//观察数据
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
			//67-69备用
			//光源故障判断
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//光源故障测量
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
			//温度阈值
			d=(DataReceive[149]<<8)|DataReceive[150];
			ShowLongOrder(N1650,d);
			//温度值
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//设定粒子通道数
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//采样间隔
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//采样次数
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//工作时间
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1378,d);
			//瞬时流量
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//累计流量
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//设定流量
			d=(DataReceive[165]<<8)|DataReceive[166];
			ShowLongOrder(N1688,d);
			//设定气体系数
			d=(DataReceive[167]<<8)|DataReceive[168];
			ShowLongOrder(N1690,d);
			//PMT控制电压
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT电阻
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
			//气压计算值
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86气泵PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//报警阈值
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);
			ShowLongOrder(N16B8,d);
			//报警状态
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//累计周期
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
			//IP端口修改位
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//序列号
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
			//序列号设置
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//设定Modbus版本
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//设定设备版本号
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);
	}
	
	
}
//输出数据
void showData1_5(void)
{
	u32 d;
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			DelayTime = d;
//			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
//			ShowLongOrder(N1070,d);
			 //周期数据
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
			//44-50备用
//			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//观察数据
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
			//67-69备用
			//光源故障判断
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//光源故障测量
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
			//温度阈值
			d=(DataReceive[149]<<8)|DataReceive[150];
			ShowLongOrder(N1650,d);
			//温度值
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//设定粒子通道数
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//采样间隔
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//采样次数
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//工作时间
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1678,d);
			//瞬时流量
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//累计流量
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//设定流量
			d=(DataReceive[165]<<8)|DataReceive[166];
			ShowLongOrder(N1688,d);
			//设定气体系数
			d=(DataReceive[167]<<8)|DataReceive[168];
			ShowLongOrder(N1690,d);
			//PMT控制电压
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT电阻
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
			//气压计算值
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86气泵PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//报警阈值
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);	
			ShowLongOrder(N16B8,d);
			//报警状态
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//累计周期
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
			//IP端口修改位
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//序列号
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
			//序列号设置
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//设定Modbus版本
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//设定设备版本号
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);
		
	}	

	
	
	//输出数据
void showData_6(void)
{
	u32 d;
	if(EquipmentState == 1){
			//ShowLongOrder(N1088,d);
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			UpdataTimeDownNum = d;
			ShowLongOrder(N1018,d);
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
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
			//44-50备用
//			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//观察数据
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
			//67-69备用
			//光源故障判断
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//温度值
			d=(DataReceive[151]<<8)|DataReceive[152];
			ShowLongOrder(N1658,d);
			//工作时间
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1378,d);
			//瞬时流量
			d=(DataReceive[161]<<8)|DataReceive[162];
			ShowLongOrder(N1680,d);
			//累计流量
			d=(DataReceive[163]<<8)|DataReceive[164];
			ShowLongOrder(N1768,d);
			//气压计算值
			d=(DataReceive[173]<<8)|DataReceive[174];
			ShowLongOrder(N16A8,d);
			//86气泵PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//报警状态
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//累计周期
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
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			DelayTime = d;
//			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
//			ShowLongOrder(N1070,d);
			 //周期数据
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
			//44-50备用
//			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//观察数据
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
			//67-69备用
			//光源故障判断
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//光源故障测量
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
//			//温度阈值
//			d=(DataReceive[149]<<8)|DataReceive[150];
//			ShowLongOrder(N1650,d);
//			//温度值
//			d=(DataReceive[151]<<8)|DataReceive[152];
//			ShowLongOrder(N1658,d);
			//设定粒子通道数
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//采样间隔
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//采样次数
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//工作时间
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1678,d);
//			//瞬时流量
//			d=(DataReceive[161]<<8)|DataReceive[162];
//			ShowLongOrder(N1680,d);
//			//累计流量
//			d=(DataReceive[163]<<8)|DataReceive[164];
//			ShowLongOrder(N1768,d);
//			//设定流量
//			d=(DataReceive[165]<<8)|DataReceive[166];
//			ShowLongOrder(N1688,d);
//			//设定气体系数
//			d=(DataReceive[167]<<8)|DataReceive[168];
//			ShowLongOrder(N1690,d);
			//PMT控制电压
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT电阻
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
//			//气压计算值
//			d=(DataReceive[173]<<8)|DataReceive[174];
//			ShowLongOrder(N16A8,d);
			//86气泵PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//报警阈值
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);	
			ShowLongOrder(N16B8,d);
			//报警状态
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//累计周期
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
			//IP端口修改位
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//序列号
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
			//序列号设置
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//设定Modbus版本
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//设定设备版本号
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);



	}
	
	
}
//输出数据
void showData1_6(void)
{
	u32 d;
			d=(DataReceive[3]<<8)|DataReceive[4];				//地址
			ShowLongOrder(N1000,d);
			 
			d=(DataReceive[5]<<8)|DataReceive[6];				//波特率
			ShowLongOrder(N1008,d);
			 
//			d=(DataReceive[7]<<8)|DataReceive[8];				//仪器开关
//			ShowOrder(N1811,d);
//			 
			d=(DataReceive[9]<<8)|DataReceive[10];				//周期
			ShowLongOrder(N1080,d);
			 
			d=(DataReceive[11]<<8)|DataReceive[12];				//延时
			ShowLongOrder(N1088,d);
			DelayTime = d;
//			d=(DataReceive[13]<<8)|DataReceive[14];				//计数器当前计数累计时(秒)
//			ShowLongOrder(N1010,d);
//			 
//			d=(DataReceive[15]<<8)|DataReceive[16];				//调试
//			ShowOrder(N1C75,d);
//			 
//			d=(DataReceive[17]<<8)|DataReceive[18];					//PWM
//			ShowLongOrder(N1AD8,d);
			 
			d=(DataReceive[19]<<8)|DataReceive[20];					//更新倒计时
			ShowLongOrder(N1018,d);
			 
//			d=(DataReceive[21]<<8)|DataReceive[22];					//通信校验位，0-无校验，1-偶校验，2-奇校验（数据位固定8位，校验位加在数据位之后）
//			ShowLongOrder(N1020,d);
			 
			d=(DataReceive[23]<<8)|DataReceive[24];					//工作累加次数（1-200），和周期配合，一次就是一周期
			ShowLongOrder(N1028,d);
			 
			d=(DataReceive[25]<<8)|DataReceive[26];					//比较电压1
			ShowOrder(InputGear1,d);
			
			d=(DataReceive[27]<<8)|DataReceive[28];					//比较电压2
			ShowOrder(InputGear2,d);
			 
			d=(DataReceive[29]<<8)|DataReceive[30];					//比较电压3
			ShowOrder(InputGear3,d);
			 
			d=(DataReceive[31]<<8)|DataReceive[32];					//比较电压4
			ShowOrder(InputGear4,d);
			 
			d=(DataReceive[33]<<8)|DataReceive[34];					//比较电压5
			ShowOrder(InputGear5,d);
			 
			d=(DataReceive[35]<<8)|DataReceive[36];					//比较电压6
			ShowOrder(InputGear6,d);
			 
			d=(DataReceive[37]<<8)|DataReceive[38];					//比较电压7
			ShowOrder(InputGear7,d);
			 		
			d=(DataReceive[39]<<8)|DataReceive[40];					//比较电压8
			ShowOrder(InputGear8,d);
			FlagVoltage = d;
			
			d=(DataReceive[41]<<8)|DataReceive[42];//气压阈值低
			ShowLongOrder(N1030,d);
			 
			d=(DataReceive[43]<<8)|DataReceive[44];//气压阈值高
			ShowLongOrder(N1038,d);
			 
			d=(DataReceive[45]<<8)|DataReceive[46];//气压故障状态
			ShowLongOrder(N1040,d);
			 
			d=(DataReceive[47]<<8)|DataReceive[48];//气压读数
			ShowLongOrder(N1048,d);
			 
			d=(DataReceive[49]<<8)|DataReceive[50];//光源阈值
			ShowLongOrder(N1050,d);
			 
			d=(DataReceive[51]<<8)|DataReceive[52];//光源故障状态
			ShowLongOrder(N1058,d);
			 
			d=(DataReceive[53]<<8)|DataReceive[54];//光源读数
			ShowLongOrder(N1060,d);
			 
//			d=(DataReceive[55]<<8)|DataReceive[56];//饱和阈值
//			ShowLongOrder(N1068,d);
//			 
//			d=(DataReceive[57]<<8)|DataReceive[58];//饱和状态
//			ShowLongOrder(N1070,d);
			 //周期数据
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
			//44-50备用
//			d=(DataReceive[91]<<8)|DataReceive[92];	//气压阈值
//			ShowLongOrder(N1138,d);
			//d=(DataReceive[105]<<8)|DataReceive[106];
			//观察数据
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
			//67-69备用
			//光源故障判断
			d=((((u32)DataReceive[143]<<8)|DataReceive[144]))|((((u32)DataReceive[145]<<24)|(DataReceive[146]))<<16);	
			ShowLongOrder(N1640,d);
			//光源故障测量
			d=(DataReceive[147]<<8)|DataReceive[148];
			ShowOrder(N1648,d);
//			//温度阈值
//			d=(DataReceive[149]<<8)|DataReceive[150];
//			ShowLongOrder(N1650,d);
//			//温度值
//			d=(DataReceive[151]<<8)|DataReceive[152];
//			ShowLongOrder(N1658,d);
			//设定粒子通道数
			d=(DataReceive[153]<<8)|DataReceive[154];
			ShowLongOrder(N1660,d);
			//采样间隔
			d=(DataReceive[155]<<8)|DataReceive[156];
			ShowLongOrder(N1668,d);
			//采样次数
			d=(DataReceive[157]<<8)|DataReceive[158];
			ShowLongOrder(N1670,d);
			//工作时间
			d=(DataReceive[159]<<8)|DataReceive[160];
			ShowLongOrder(N1678,d);
//			//瞬时流量
//			d=(DataReceive[161]<<8)|DataReceive[162];
//			ShowLongOrder(N1680,d);
//			//累计流量
//			d=(DataReceive[163]<<8)|DataReceive[164];
//			ShowLongOrder(N1768,d);
//			//设定流量
//			d=(DataReceive[165]<<8)|DataReceive[166];
//			ShowLongOrder(N1688,d);
//			//设定气体系数
//			d=(DataReceive[167]<<8)|DataReceive[168];
//			ShowLongOrder(N1690,d);
			//PMT控制电压
			d=(DataReceive[169]<<8)|DataReceive[170];
			ShowLongOrder(N1698,d);
			//PMT电阻
			d=(DataReceive[171]<<8)|DataReceive[172];
			ShowLongOrder(N16A0,d);
//			//气压计算值
//			d=(DataReceive[173]<<8)|DataReceive[174];
//			ShowLongOrder(N16A8,d);
			//86气泵PWM
			d=(DataReceive[175]<<8)|DataReceive[176];
			ShowLongOrder(N16B0,d);
			//报警阈值
			//d=((((u32)DataReceive[177]<<8)|DataReceive[178]))|((((u32)DataReceive[179]<<24)|(DataReceive[180]))<<16);	
			d=((((u32)DataReceive[179]<<8)|DataReceive[180]))|((((u32)DataReceive[177]<<24)|(DataReceive[178]))<<16);	
			ShowLongOrder(N16B8,d);
			//报警状态
			d=(DataReceive[181]<<8)|DataReceive[182];
			ShowLongOrder(N16C0,d);
			//累计周期
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
			//IP端口修改位
			d=(DataReceive[225]<<8)|DataReceive[226];
			ShowLongOrder(N15F8,d);
			//序列号
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
			//序列号设置
			d=(DataReceive[243]<<8)|DataReceive[244];
			ShowLongOrder(N1750,d);
			//设定Modbus版本
			d=(DataReceive[245]<<8)|DataReceive[246];
			ShowLongOrder(N1758,d);
			//设定设备版本号
			d=(DataReceive[247]<<8)|DataReceive[248];
			ShowLongOrder(N1760,d);
		
	}	
	
	
	

	


//气压阈值低
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
//气压阈值高
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

//气路压力故障,0无故障，1过低，2过高
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set021();
	}
	else	//通信超时
	{
		
	}
}
//气压读数
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
					//通信成功，上位机显示
			Set022();
	}
	else	//通信超时
	{
		
	}
}

//光源阈值
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

//光源故障状态
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;

			Set024();
	}
	else	//通信超时
	{
		
	}
}
//光源读数
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set025();
	}
	else	//通信超时
	{
		
	}
}


//饱和阈值
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
//饱和状态
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set027();
	}
	else	//通信超时
	{
		
	}
}

//0.3um  周期数据
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set028();
	}
	else	//通信超时
	{
		
	}
}
//0.3um  周期数据 高16位
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			u8 res;
			ModbusRx.ModbusReceDoneNum=0;
			res=ModbusReceiveOrderCheck();		//检查应答指令
			if(res==0xff)											//指令正确
			{
					//通信成功，上位机显示
					//send_uart3_string("ID:SSSS202008N254*");
			}
	}
	else	//通信超时
	{
		
	}
}

//0.5um  周期数据
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
					//通信成功，上位机显示
			Set030();
	}
	else	//通信超时
	{
		
	}
}


//0.5um  周期数据 高16位
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
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//检查应答指令
//			if(res==0xff)											//指令正确
//			{
//					//通信成功，上位机显示
//					//send_uart3_string("ID:SSSS202008N255*");
//			}
//	}
//	else	//通信超时
//	{
//		
//	}
}

//1.0um  周期数据 低16位
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
					//通信成功，上位机显示
			Set032();
	}
	else	//通信超时
	{
		
	}
}

//1.0um  周期数据 高16位
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
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//检查应答指令
//			if(res==0xff)											//指令正确
//			{
//					//通信成功，上位机显示
//					//Set034();
//			}
//	}
//	else	//通信超时
//	{
//		
//	}
}
//3.0um  周期数据 低16位
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set034();
	}
	else	//通信超时
	{
		
	}
}

//3.0um  周期数据 高16位
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
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//检查应答指令
//			if(res==0xff)											//指令正确
//			{
//					//通信成功，上位机显示
//					//send_uart3_string("ID:SSSS202008N261*");
//			}
//	}
//	else	//通信超时
//	{
//		
//	}
}
//5.0um  周期数据 低16位
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
					//通信成功，上位机显示
			Set036();
	}
	else	//通信超时
	{
		
	}
}

//5.0um  周期数据 高16位
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
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//检查应答指令
//			if(res==0xff)											//指令正确
//			{
//					//通信成功，上位机显示
//			}
//	}
//	else	//通信超时
//	{
//		
//	}
}
//10.0um  周期数据 低16位
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set038();
	}
	else	//通信超时
	{
		
	}
}

//10.0um  周期数据 高16位
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
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//检查应答指令
//			if(res==0xff)											//指令正确
//			{
//					//通信成功，上位机显示
//			}
//	}
//	else	//通信超时
//	{
//		
//	}
}
//饱和报警计数低16位
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{

			ModbusRx.ModbusReceDoneNum=0;
			Set040();

	}
	else	//通信超时
	{
		
	}
}

//饱和报警计数高16位
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
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck();		//检查应答指令
//			if(res==0xff)											//指令正确
//			{
//					//通信成功，上位机显示
//			}
//	}
//	else	//通信超时
//	{
//		
//	}
}
//光源故障判断计数低16位
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
			//通信成功，上位机显示
			Set042();
	}
	else	//通信超时
	{
		
	}
}
//光源故障判断计数高16位
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
//	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
//	{
//			u8 res;
//			ModbusRx.ModbusReceDoneNum=0;
//			res=ModbusReceiveOrderCheck16();		//检查应答指令
//			if(res==0xff)											//指令正确
//			{
//					//通信成功，上位机显示
//			}
//	}
//	else	//通信超时
//	{
//		
//	}
}
//气压阈值
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
//端口
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
//IP和端口的修改位
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
//更新正计时
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
	if(ModbusRx.ModbusReceDoneNum>=3)          		//应答接收完成
	{
			ModbusRx.ModbusReceDoneNum=0;
			Set056();
	}
	else	//通信超时
	{
		
	}
}
void sendAllData(){

}
//___________________________________________________________________________________________________________
//0.1界面
//设置地址
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

////设置波特率
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
//	//修改完波特率，再发一次
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
//开机
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
//关机
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
//调试开
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

//调试关
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
//设置PWM
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
//通信校验
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
//气压阈值低
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
//气压阈值高
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
//气泵电阻
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
//设置工作时间
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

//设置启动延时
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
//设置档一比较电压
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
//设置档二比较电压
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

//设置档三比较电压
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
//设置档四比较电压
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

//设置档五比较电压
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

//设置档六比较电压
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
//设置档七比较电压
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

//设置档八比较电压
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
//3.生物气凝胶
//设置地址
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
	//修改完波特率，再发一次
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

//开机
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
//关机
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
//调试开
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

//调试关
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
//高压0.1
//光源故障测量
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
//温度阈值
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

//设定粒子通道数
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
//采样间隔
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
//采样次数
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
//设定流量
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
//设定气体系数
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
//PMT控制电压
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
//PMT电阻
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
//气泵PWM
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
//报警阈值
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
//报警阈值高
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
//报警阈值低
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
//端口
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
//IP端口修改位
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
//序列号1
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
//序列号2
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
//序列号3
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
//序列号4
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
//序列号5
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
//序列号6
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
//序列号7
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
//序列号8
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
//序列号设置
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
//设定Modbus版本
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
//设定设备版本号
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
