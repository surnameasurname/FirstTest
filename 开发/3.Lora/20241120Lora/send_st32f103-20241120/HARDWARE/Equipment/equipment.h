#ifndef _equipment_h_
#define _equipment_h_

#include "sys.h"
extern u8 buff[ 10 ]; 

extern u16 ReceiveOrSend; 					//接收还是发送   接收为0，发送为1
extern u16 Mode; 										//Lora工作模式1定点  0中继  2透明传输
extern u16 LocalGroupNumber;				//本地组号0-254
extern u16 LocalAddress;						//本地地址0-254
extern u16 TargetGroupNumber;				//目标组号 0-254
extern u16 DestinationAddress;			//目标地址
extern u16 PathGroupANumber;				//路径A组号
extern u16 PathAAddress;						//路径A地址
extern u16 PathGroupBNumber;				//路径B组号
extern u16 PathBAddress;						//路径B地址
extern u16 Channel;									//信道
extern u16 ArmChannel;							//目标信道
extern u16 TempChannel;						//临时信道


extern u16 ADC_1;				//SIGNAL1
extern u16 ADC_2;				//SIGNAL2

extern u8 communication_done;
extern u16 DAC_1;
extern u16 DAC_2;
extern u16 TempDac_1;
extern u16 TempDac_2;



extern u16 Add1;
extern u16 Add2;
extern u16 Add3;
extern u16 Add4;
extern u16 Add5;
extern u16 Add6;


#endif
