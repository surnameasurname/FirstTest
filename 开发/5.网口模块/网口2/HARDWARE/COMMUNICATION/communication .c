#include "communication.h"
#include "uart.h"
#include "show.h"
#include "delay.h"

//u8 EquipmentState=0;//�豸״̬��1������ͨ�ţ�0������
u8 SlaveState[20];//20���豸״̬��1���ڲ����У�0������,2,��ʼ����
u8 DataReceive[250];
u8 DataReceive6[20];

void communication_init(void)			//ͨ�ų�ʼ��
{
	communication1_init();
	communication3_init();
}

//��������ָ���
void communication_order_dispose(void)
{
	order_dispose_u3();
}

