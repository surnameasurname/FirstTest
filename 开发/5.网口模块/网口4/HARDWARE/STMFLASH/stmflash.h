#ifndef __STMFLASH_H__
#define __STMFLASH_H__
#include "sys.h"  

//用户根据自己的需要设置
#define STM32_FLASH_SIZE 	512 	 		//所选STM32的FLASH容量大小(单位为K)
#define STM32_FLASH_WREN 	1              	//使能FLASH写入(0，不是能;1，使能)
//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH起始地址
#define STM32_FLASH_BASE 0x08000000 		//STM32 FLASH的起始地址
//FLASH解锁键值
#define FLASH_KEY1               0X45670123
#define FLASH_KEY2               0XCDEF89AB

#define FLASH_ReceiveOrSend_DA_ADDR  					0X08010000 			//接收还是发送   接收为0，发送为1
#define FLASH_Mode_DA_ADDR  									0X08010002 			//Lora工作模式1定点  0中继
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

void STMFLASH_Unlock(void);					  //FLASH解锁
void STMFLASH_Lock(void);					  //FLASH上锁
u8 STMFLASH_GetStatus(void);				  //获得状态
u8 STMFLASH_WaitDone(u16 time);				  //等待操作结束
u8 STMFLASH_ErasePage(u32 paddr);			  //擦除页
u8 STMFLASH_WriteHalfWord(u32 faddr, u16 dat);//写入半字
u16 STMFLASH_ReadHalfWord(u32 faddr);		  //读出半字  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//指定地址开始写入指定长度的数据
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//指定地址开始读取指定长度数据
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//从指定地址开始写入指定长度的数据
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//从指定地址开始读出指定长度的数据

//测试写入
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
//写
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

















