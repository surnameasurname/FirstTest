#include "show1.h"
#include "uart.h"
#include "DataChange.h"
#include "equipment.h"
#include "delay.h"
#include "stmflash.h"
#include "lora.h"

void 	SetReceiveOrSend(u16 Temp)
{
	ReceiveOrSend = Temp;
	buff[0] = ReceiveOrSend;
	WriteReceiveOrSend();
	
}

void 	SetMode(u16 Temp)
{
	Mode = Temp;
	buff[1] = Mode;
	WriteMode();
//	SetLora();
	
}
void 	SetLocalGroupNumber(u16 Temp)
{
	LocalGroupNumber = (u8)Temp;
	buff[0] = LocalGroupNumber;
	WriteLocalGroupNumber();
	//SetLocGro();

}
void 	SetLocalAddress(u16 Temp)
{
	LocalAddress = Temp;
	WriteLocalAddress();
	//SetLocAdd();
}
void 	SetTargetGroupNumber(u16 Temp)
{
//	TargetGroupNumber = Temp;
//	WriteTargetGroupNumber();
//	SetArmLocGro();
}
void 	SetDestinationAddress(u16 Temp)
{
//	DestinationAddress = Temp;
//	WriteDestinationAddress();
//	SetArmLocAdd();

}
void 	SetPathGroupANumber(u16 Temp)
{
//	PathGroupANumber = Temp;
//	WritePathGroupANumber();
//	Lora_SetPathGroupANumber();
}
void 	SetPathAAddress(u16 Temp)
{
//	PathAAddress = Temp;
//	WritePathAAddress();
//	Lora_SetPathAAddress();
}
void 	SetPathGroupBNumber(u16 Temp)
{
//	PathGroupBNumber = Temp;
//	WritePathGroupBNumber();
//	Lora_SetPathGroupBNumber();
}
void 	SetPathBAddress(u16 Temp)
{
//	PathBAddress = Temp;
//	WritePathBAddress();
//	Lora_SetPathBAddress();
}
void 	SetChannelAdd(u16 Temp)
{
//	Channel = Temp;
//	Lora_SetChannelAdd(Channel);
//	WriteChannel();
}
void 	SetArmChannelAdd(u16 Temp)
{
//	ArmChannel = Temp;
//	WriteArmChannel();
}
void 	SetTempChannelAdd(u16 Temp)
{
//	TempChannel = Temp;
//	WriteTempChannel();
}





