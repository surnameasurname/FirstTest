#ifndef __STMFLASH_H__
#define __STMFLASH_H__
#include "sys.h"  

//�û������Լ�����Ҫ����
#define STM32_FLASH_SIZE 	512 	 		//��ѡSTM32��FLASH������С(��λΪK)
#define STM32_FLASH_WREN 	1              	//ʹ��FLASHд��(0��������;1��ʹ��)
//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH��ʼ��ַ
#define STM32_FLASH_BASE 0x08000000 		//STM32 FLASH����ʼ��ַ
//FLASH������ֵ
#define FLASH_KEY1               0X45670123
#define FLASH_KEY2               0XCDEF89AB

#define FLASH_ReceiveOrSend_DA_ADDR  					0X08010000 			//���ջ��Ƿ���   ����Ϊ0������Ϊ1
#define FLASH_Mode_DA_ADDR  									0X08010002 			//Lora����ģʽ1����  0�м�
#define FLASH_LocalGroupNumber_DA_ADDR  			0X08010004
#define FLASH_LocalAddress_DA_ADDR  					0X08010006
#define FLASH_TargetGroupNumber_DA_ADDR  			0X08010008
#define FLASH_DestinationAddress_DA_ADDR  		0X0801000A
#define FLASH_PathGroupANumber_DA_ADDR  			0X0801000C
#define FLASH_PathAAddress_DA_ADDR  					0X0801000E
#define FLASH_PathGroupBNumber_DA_ADDR  			0X08010010
#define FLASH_PathBAddress_DA_ADDR  					0X08010012
#define FLASH_Channel_DA_ADDR  								0X08010014
#define FLASH_ArmChannel_DA_ADDR  						0X08010016
#define FLASH_TempChannel_DA_ADDR  						0X08010018

#define FLASH_PB4_DA_ADDR											0X08010010
#define FLASH_PB5_DA_ADDR											0X08010020
#define FLASH_PB6_DA_ADDR											0X08010030
#define FLASH_PB7_DA_ADDR											0X08010040

void STMFLASH_Unlock(void);					  //FLASH����
void STMFLASH_Lock(void);					  //FLASH����
u8 STMFLASH_GetStatus(void);				  //���״̬
u8 STMFLASH_WaitDone(u16 time);				  //�ȴ���������
u8 STMFLASH_ErasePage(u32 paddr);			  //����ҳ
u8 STMFLASH_WriteHalfWord(u32 faddr, u16 dat);//д�����
u16 STMFLASH_ReadHalfWord(u32 faddr);		  //��������  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//ָ����ַ��ʼд��ָ�����ȵ�����
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//ָ����ַ��ʼ��ȡָ����������
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//��ָ����ַ��ʼд��ָ�����ȵ�����
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����

//����д��
void Test_Write(u32 WriteAddr,u16 WriteData);	

void ReadAllData(void);

void ReadReceiveOrSend(void);
void ReadMode(void);
void ReadLocalGroupNumber(void);
void ReadLocalAddress(void);
void ReadTargetGroupNumber(void);
void ReadDestinationAddress(void);
void ReadPathGroupANumber(void);
void ReadPathAAddress(void);
void ReadPathGroupBNumber(void);
void ReadPathBAddress(void);
void ReadChannel(void);
void ReadArmChannel(void);
void ReadTempChannel(void);
//д
void WriteReceiveOrSend(void);
void WriteMode(void);
void WriteLocalGroupNumber(void);
void WriteLocalAddress(void);
void WriteTargetGroupNumber(void);
void WriteDestinationAddress(void);
void WritePathGroupANumber(void);
void WritePathAAddress(void);
void WritePathGroupBNumber(void);
void WritePathBAddress(void);
void WriteChannel(void);
void WriteArmChannel(void);
void WriteTempChannel(void);




void WritePB4(void);
void WritePB5(void);
void WritePB6(void);
void WritePB7(void);
void ReadPB4(void);
void ReadPB5(void);
void ReadPB6(void);
void ReadPB7(void);

#endif

















