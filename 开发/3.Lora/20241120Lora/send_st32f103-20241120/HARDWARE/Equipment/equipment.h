#ifndef _equipment_h_
#define _equipment_h_

#include "sys.h"
extern u8 buff[ 10 ]; 

extern u16 ReceiveOrSend; 					//���ջ��Ƿ���   ����Ϊ0������Ϊ1
extern u16 Mode; 										//Lora����ģʽ1����  0�м�  2͸������
extern u16 LocalGroupNumber;				//�������0-254
extern u16 LocalAddress;						//���ص�ַ0-254
extern u16 TargetGroupNumber;				//Ŀ����� 0-254
extern u16 DestinationAddress;			//Ŀ���ַ
extern u16 PathGroupANumber;				//·��A���
extern u16 PathAAddress;						//·��A��ַ
extern u16 PathGroupBNumber;				//·��B���
extern u16 PathBAddress;						//·��B��ַ
extern u16 Channel;									//�ŵ�
extern u16 ArmChannel;							//Ŀ���ŵ�
extern u16 TempChannel;						//��ʱ�ŵ�


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
