#include "communication.h"
#include "uart.h"
#include "show.h"
#include "delay.h"

//u8 EquipmentState=0;//设备状态，1，正在通信，0，空闲
u8 SlaveState[20];//20个设备状态，1存在并空闲，0不存在,2,开始传令
u8 DataReceive[250];
u8 DataReceive6[20];

void communication_init(void)			//通信初始化
{
	communication1_init();
	communication3_init();
}

//接收数组指令处理
void communication_order_dispose(void)
{
	order_dispose_u3();
}

