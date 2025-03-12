#include "stmflash.h"
#include "delay.h"
#include "uart.h"
#include "equipment.h"
#include "lora.h"
#include "show1.h"


//解锁STM32的FLASH
void STMFLASH_Unlock(void)
{
	FLASH->KEYR=FLASH_KEY1;//写入解锁序列.
	FLASH->KEYR=FLASH_KEY2;
}
//flash上锁
void STMFLASH_Lock(void)
{
	FLASH->CR|=1<<7;//上锁
}
//得到FLASH状态
u8 STMFLASH_GetStatus(void)
{	
	u32 res;		
	res=FLASH->SR; 
	if(res&(1<<0))return 1;		    //忙
	else if(res&(1<<2))return 2;	//编程错误
	else if(res&(1<<4))return 3;	//写保护错误
	return 0;						//操作完成
}
//等待操作完成
//time:要延时的长短
//返回值:状态.
u8 STMFLASH_WaitDone(u16 time)
{
	u8 res;
	do
	{
		res=STMFLASH_GetStatus();
		if(res!=1)break;//非忙,无需等待了,直接退出.
		delay_us(1);
		time--;
	 }while(time);
	 if(time==0)res=0xff;//TIMEOUT
	 return res;
}
//擦除页
//paddr:页地址
//返回值:执行情况
u8 STMFLASH_ErasePage(u32 paddr)
{
	u8 res=0;
	res=STMFLASH_WaitDone(0X5FFF);//等待上次操作结束,>20ms    
	if(res==0)
	{ 
		FLASH->CR|=1<<1;//页擦除
		FLASH->AR=paddr;//设置页地址 
		FLASH->CR|=1<<6;//开始擦除		  
		res=STMFLASH_WaitDone(0X5FFF);//等待操作结束,>20ms  
		if(res!=1)//非忙
		{
			FLASH->CR&=~(1<<1);//清除页擦除标志.
		}
	}
	return res;
}
//在FLASH指定地址写入半字
//faddr:指定地址(此地址必须为2的倍数!!)
//dat:要写入的数据
//返回值:写入的情况
u8 STMFLASH_WriteHalfWord(u32 faddr, u16 dat)
{
	u8 res;	   	    
	res=STMFLASH_WaitDone(0XFF);	 
	if(res==0)//OK
	{
		FLASH->CR|=1<<0;		//编程使能
		*(vu16*)faddr=dat;		//写入数据
		res=STMFLASH_WaitDone(0XFF);//等待操作完成
		if(res!=1)//操作成功
		{
			FLASH->CR&=~(1<<0);	//清除PG位.
		}
	} 
	return res;
} 
//读取指定地址的半字(16位数据) 
//faddr:读地址 
//返回值:对应数据.
u16 STMFLASH_ReadHalfWord(u32 faddr)
{
	return *(vu16*)faddr; 
}
#if STM32_FLASH_WREN	//如果使能了写   
//不检查的写入
//WriteAddr:起始地址
//pBuffer:数据指针
//NumToWrite:半字(16位)数   
void STMFLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	for(i=0;i<NumToWrite;i++)
	{
		STMFLASH_WriteHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//地址增加2.
	}  
} 
//从指定地址开始写入指定长度的数据
//WriteAddr:起始地址(此地址必须为2的倍数!!)
//pBuffer:数据指针
//NumToWrite:半字(16位)数(就是要写入的16位数据的个数.)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //字节
#else 
#define STM_SECTOR_SIZE	2048
#endif		 
u16 STMFLASH_BUF[STM_SECTOR_SIZE/2];//最多是2K字节
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)	
{
	u32 secpos;	   //扇区地址
	u16 secoff;	   //扇区内偏移地址(16位字计算)
	u16 secremain; //扇区内剩余地址(16位字计算)	   
 	u16 i;    
	u32 offaddr;   //去掉0X08000000后的地址
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))return;//非法地址
	STMFLASH_Unlock();						//解锁
	offaddr=WriteAddr-STM32_FLASH_BASE;		//实际偏移地址.
	secpos=offaddr/STM_SECTOR_SIZE;			//扇区地址  0~127 for STM32F103RBT6
	secoff=(offaddr%STM_SECTOR_SIZE)/2;		//在扇区内的偏移(2个字节为基本单位.)
	secremain=STM_SECTOR_SIZE/2-secoff;		//扇区剩余空间大小   
	if(NumToWrite<=secremain)secremain=NumToWrite;//不大于该扇区范围
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//读出整个扇区的内容
		for(i=0;i<secremain;i++)	//校验数据
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;//需要擦除  	  
		}
		if(i<secremain)				//需要擦除
		{
			STMFLASH_ErasePage(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE);//擦除这个扇区
			for(i=0;i<secremain;i++)//复制
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//写入整个扇区  
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);//写已经擦除了的,直接写入扇区剩余区间. 				   
		if(NumToWrite==secremain)break;//写入结束了
		else//写入未结束
		{
			secpos++;				//扇区地址增1
			secoff=0;				//偏移位置为0 	 
		   	pBuffer+=secremain;  	//指针偏移
			WriteAddr+=secremain*2;	//写地址偏移(16位数据地址,需要*2)	   
		   	NumToWrite-=secremain;	//字节(16位)数递减
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;//下一个扇区还是写不完
			else secremain=NumToWrite;//下一个扇区可以写完了
		}	 
	};	
	STMFLASH_Lock();//上锁
}
#endif

//从指定地址开始读出指定长度的数据
//ReadAddr:起始地址
//pBuffer:数据指针
//NumToWrite:半字(16位)数
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);//读取2个字节.
		ReadAddr+=2;//偏移2个字节.	
	}
}

//////////////////////////////////////////测试用///////////////////////////////////////////
//WriteAddr:起始地址
//WriteData:要写入的数据
//void Test_Write(u32 WriteAddr,u16 WriteData)   	
//{
//	STMFLASH_Write(WriteAddr,&WriteData,1);//写入一个字 
//}


//void ReadReceiveOrSend(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_ReceiveOrSend_DA_ADDR,(u16*)datatemp1,1);
//	ReceiveOrSend=datatemp1[0];
//}

//void ReadMode(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_Mode_DA_ADDR,(u16*)datatemp1,1);
//	Mode=datatemp1[0];
//}
//void ReadLocalGroupNumber(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_LocalGroupNumber_DA_ADDR,(u16*)datatemp1,1);
//	LocalGroupNumber=datatemp1[0];
//}
//void ReadLocalAddress(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_LocalAddress_DA_ADDR,(u16*)datatemp1,1);
//	LocalAddress=datatemp1[0];
//}
//void ReadTargetGroupNumber(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_TargetGroupNumber_DA_ADDR,(u16*)datatemp1,1);
//	TargetGroupNumber=datatemp1[0];
//}
//void ReadDestinationAddress(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_DestinationAddress_DA_ADDR,(u16*)datatemp1,1);
//	DestinationAddress=datatemp1[0];
//}
//void ReadPathGroupANumber(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_PathGroupANumber_DA_ADDR,(u16*)datatemp1,1);
//	PathGroupANumber=datatemp1[0];
//}
//void ReadPathAAddress(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_PathAAddress_DA_ADDR,(u16*)datatemp1,1);
//	PathAAddress=datatemp1[0];
//}
//void ReadPathGroupBNumber(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_PathGroupBNumber_DA_ADDR,(u16*)datatemp1,1);
//	PathGroupBNumber=datatemp1[0];
//}
//void ReadPathBAddress(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_PathBAddress_DA_ADDR,(u16*)datatemp1,1);
//	PathBAddress=datatemp1[0];
//}
//void ReadChannel(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_Channel_DA_ADDR,(u16*)datatemp1,1);
//	Channel=datatemp1[0];
//}
//void ReadArmChannel(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_ArmChannel_DA_ADDR,(u16*)datatemp1,1);
//	ArmChannel=datatemp1[0];
//}
//void ReadTempChannel(void)
//{
//	u16 datatemp1[1];
//	STMFLASH_Read(FLASH_TempChannel_DA_ADDR,(u16*)datatemp1,1);
//	TempChannel=datatemp1[0];
//}

////写
//void WriteReceiveOrSend(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0]  = ReceiveOrSend;
//	STMFLASH_Write(FLASH_ReceiveOrSend_DA_ADDR,(u16*)datatemp1,1);
//	
//}

//void WriteMode(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = Mode;
//	STMFLASH_Write(FLASH_Mode_DA_ADDR,(u16*)datatemp1,1);
//}
//void WriteLocalGroupNumber(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = LocalGroupNumber;
//	STMFLASH_Write(FLASH_LocalGroupNumber_DA_ADDR,(u16*)datatemp1,1);
//	
//}
//void WriteLocalAddress(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = LocalAddress;
//	STMFLASH_Write(FLASH_LocalAddress_DA_ADDR,(u16*)datatemp1,1);
//}
//void WriteTargetGroupNumber(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = TargetGroupNumber;
//	STMFLASH_Write(FLASH_TargetGroupNumber_DA_ADDR,(u16*)datatemp1,1);
//}
//void WriteDestinationAddress(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = DestinationAddress;
//	STMFLASH_Write(FLASH_DestinationAddress_DA_ADDR,(u16*)datatemp1,1);
//}
//void WritePathGroupANumber(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = PathGroupANumber;
//	STMFLASH_Write(FLASH_PathGroupANumber_DA_ADDR,(u16*)datatemp1,1);

//}
//void WritePathAAddress(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = PathAAddress;
//	STMFLASH_Write(FLASH_PathAAddress_DA_ADDR,(u16*)datatemp1,1);

//}
//void WritePathGroupBNumber(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = PathGroupBNumber;
//	STMFLASH_Write(FLASH_PathGroupBNumber_DA_ADDR,(u16*)datatemp1,1);

//}
//void WritePathBAddress(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = PathBAddress;
//	STMFLASH_Write(FLASH_PathBAddress_DA_ADDR,(u16*)datatemp1,1);

//}
//void WriteChannel(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = Channel;
//	STMFLASH_Write(FLASH_Channel_DA_ADDR,(u16*)datatemp1,1);

//}
//void WriteArmChannel(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = ArmChannel;
//	STMFLASH_Write(FLASH_ArmChannel_DA_ADDR,(u16*)datatemp1,1);

//}
//void WriteTempChannel(void)
//{
//	u16 datatemp1[1];
//	datatemp1[0] = TempChannel;
//	STMFLASH_Write(FLASH_TempChannel_DA_ADDR,(u16*)datatemp1,1);

//}



void WritePB4(void)
{
	u16 datatemp1[2];
	datatemp1[0] = PB4Count;
	datatemp1[1] = PB4Count>>16;
	STMFLASH_Write(FLASH_PB4_DA_ADDR,(u16*)datatemp1,2);
}
void WritePB5(void)
{
	u16 datatemp1[2];
	datatemp1[0] = PB5Count;
	datatemp1[1] = PB5Count>>16;
	STMFLASH_Write(FLASH_PB5_DA_ADDR,(u16*)datatemp1,2);
}
void WritePB6(void)
{
	u16 datatemp1[2];
	datatemp1[0] = PB6Count;
	datatemp1[1] = PB6Count>>16;
	STMFLASH_Write(FLASH_PB6_DA_ADDR,(u16*)datatemp1,2);
}
void WritePB7(void)
{
	u16 datatemp1[2];
	datatemp1[0] = PB7Count;
	datatemp1[1] = PB7Count>>16;
	STMFLASH_Write(FLASH_PB7_DA_ADDR,(u16*)datatemp1,2);
}


void ReadPB4(void)
{
	u16 datatemp1[2];
	u16 test;
	STMFLASH_Read(FLASH_PB4_DA_ADDR,(u16*)datatemp1,2);
	test=datatemp1[1];
	PB4Count = test;
	PB4Count=PB4Count<<16 | datatemp1[0];
}
void ReadPB5(void)
{
	u16 datatemp1[2];
	u16 test;
	STMFLASH_Read(FLASH_PB5_DA_ADDR,(u16*)datatemp1,2);
	test=datatemp1[1];
	PB5Count = test;
	PB5Count=PB5Count<<16  | datatemp1[0];
}
void ReadPB6(void)
{
	u16 datatemp1[2];
	u16 test;
	STMFLASH_Read(FLASH_PB6_DA_ADDR,(u16*)datatemp1,2);
	test=datatemp1[1];
	PB6Count = test;
	PB6Count=PB6Count<<16 | datatemp1[0];
}
void ReadPB7(void)
{
	u16 datatemp1[2];
	u16 test;
	STMFLASH_Read(FLASH_PB7_DA_ADDR,(u16*)datatemp1,2);
	test=datatemp1[1];
	PB7Count = test;
	PB7Count=PB7Count<<16 |  datatemp1[0];
}


void ReadAllData(void)
{
	ReadPB4();
	ReadPB5();
	ReadPB6();
	ReadPB7();
	if(PB4Count == 0xFFFFFFFF)
	{
		PB4Count = 0;
		WritePB4();
	}
	number1 = count_digits(PB4Count);
	if(PB5Count == 0xFFFFFFFF)
	{
		PB5Count = 0;
		WritePB5();
	}
	number2 = count_digits(PB5Count);
	if(PB6Count == 0xFFFFFFFF)
	{
		PB6Count = 0;
		WritePB6();
	}
	number3 = count_digits(PB6Count);
	if(PB7Count == 0xFFFFFFFF)
	{
		PB7Count = 0;
		WritePB7();
	}
	number4 = count_digits(PB7Count);
}


