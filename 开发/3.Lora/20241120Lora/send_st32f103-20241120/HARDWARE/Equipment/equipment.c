#include "equipment.h"
u16 ReceiveOrSend = 10;                  //���ջ��Ƿ���   ����Ϊ0������Ϊ1��2͸������
u16 Mode = 0;                                   //Lora����ģʽ 1 ����ͨ��1    2  ����ͨ��2  3 ��������ͨ��
u16 LocalGroupNumber = 0;               //�������0-254
u16 LocalAddress = 0;                       //���ص�ַ0-254
u16 TargetGroupNumber = 0;          //Ŀ����� 0-254
u16 DestinationAddress = 0;         //Ŀ���ַ

u16 PathGroupANumber = 0;               //·��A���
u16 PathAAddress = 0;                       //·��A��ַ
u16 PathGroupBNumber = 0;               //·��B���
u16 PathBAddress = 0;                       //·��B��ַ
u16 Channel = 0;                                //�ŵ�          1-80
u16 ArmChannel = 0;                         //Ŀ���ŵ�
u16 TempChannel = 0;                        //��ʱ�ŵ�

u16 ADC_1 = 0;              //SIGNAL1
u16 ADC_2 = 0;              //SIGNAL2

u16 DAC_1 = 0;
u16 DAC_2 = 0;
u16 TempDac_1 = 0;
u16 TempDac_2 = 0;
u8 buff[ 10 ] = { 0 };

u8 communication_done = 0;



u16 Add1;
u16 Add2;
u16 Add3;
u16 Add4;
u16 Add5;
u16 Add6;


