#include "stmflash.h"
#include "delay.h"
#include "uart.h"
#include "equipment.h"
#include "lora.h"
#include "show1.h"


//����STM32��FLASH
void STMFLASH_Unlock(void)
{
	FLASH->KEYR=FLASH_KEY1;//д���������.
	FLASH->KEYR=FLASH_KEY2;
}
//flash����
void STMFLASH_Lock(void)
{
	FLASH->CR|=1<<7;//����
}
//�õ�FLASH״̬
u8 STMFLASH_GetStatus(void)
{	
	u32 res;		
	res=FLASH->SR; 
	if(res&(1<<0))return 1;		    //æ
	else if(res&(1<<2))return 2;	//��̴���
	else if(res&(1<<4))return 3;	//д��������
	return 0;						//�������
}
//�ȴ��������
//time:Ҫ��ʱ�ĳ���
//����ֵ:״̬.
u8 STMFLASH_WaitDone(u16 time)
{
	u8 res;
	do
	{
		res=STMFLASH_GetStatus();
		if(res!=1)break;//��æ,����ȴ���,ֱ���˳�.
		delay_us(1);
		time--;
	 }while(time);
	 if(time==0)res=0xff;//TIMEOUT
	 return res;
}
//����ҳ
//paddr:ҳ��ַ
//����ֵ:ִ�����
u8 STMFLASH_ErasePage(u32 paddr)
{
	u8 res=0;
	res=STMFLASH_WaitDone(0X5FFF);//�ȴ��ϴβ�������,>20ms    
	if(res==0)
	{ 
		FLASH->CR|=1<<1;//ҳ����
		FLASH->AR=paddr;//����ҳ��ַ 
		FLASH->CR|=1<<6;//��ʼ����		  
		res=STMFLASH_WaitDone(0X5FFF);//�ȴ���������,>20ms  
		if(res!=1)//��æ
		{
			FLASH->CR&=~(1<<1);//���ҳ������־.
		}
	}
	return res;
}
//��FLASHָ����ַд�����
//faddr:ָ����ַ(�˵�ַ����Ϊ2�ı���!!)
//dat:Ҫд�������
//����ֵ:д������
u8 STMFLASH_WriteHalfWord(u32 faddr, u16 dat)
{
	u8 res;	   	    
	res=STMFLASH_WaitDone(0XFF);	 
	if(res==0)//OK
	{
		FLASH->CR|=1<<0;		//���ʹ��
		*(vu16*)faddr=dat;		//д������
		res=STMFLASH_WaitDone(0XFF);//�ȴ��������
		if(res!=1)//�����ɹ�
		{
			FLASH->CR&=~(1<<0);	//���PGλ.
		}
	} 
	return res;
} 
//��ȡָ����ַ�İ���(16λ����) 
//faddr:����ַ 
//����ֵ:��Ӧ����.
u16 STMFLASH_ReadHalfWord(u32 faddr)
{
	return *(vu16*)faddr; 
}
#if STM32_FLASH_WREN	//���ʹ����д   
//������д��
//WriteAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��   
void STMFLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	for(i=0;i<NumToWrite;i++)
	{
		STMFLASH_WriteHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//��ַ����2.
	}  
} 
//��ָ����ַ��ʼд��ָ�����ȵ�����
//WriteAddr:��ʼ��ַ(�˵�ַ����Ϊ2�ı���!!)
//pBuffer:����ָ��
//NumToWrite:����(16λ)��(����Ҫд���16λ���ݵĸ���.)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //�ֽ�
#else 
#define STM_SECTOR_SIZE	2048
#endif		 
u16 STMFLASH_BUF[STM_SECTOR_SIZE/2];//�����2K�ֽ�
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)	
{
	u32 secpos;	   //������ַ
	u16 secoff;	   //������ƫ�Ƶ�ַ(16λ�ּ���)
	u16 secremain; //������ʣ���ַ(16λ�ּ���)	   
 	u16 i;    
	u32 offaddr;   //ȥ��0X08000000��ĵ�ַ
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))return;//�Ƿ���ַ
	STMFLASH_Unlock();						//����
	offaddr=WriteAddr-STM32_FLASH_BASE;		//ʵ��ƫ�Ƶ�ַ.
	secpos=offaddr/STM_SECTOR_SIZE;			//������ַ  0~127 for STM32F103RBT6
	secoff=(offaddr%STM_SECTOR_SIZE)/2;		//�������ڵ�ƫ��(2���ֽ�Ϊ������λ.)
	secremain=STM_SECTOR_SIZE/2-secoff;		//����ʣ��ռ��С   
	if(NumToWrite<=secremain)secremain=NumToWrite;//�����ڸ�������Χ
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//������������������
		for(i=0;i<secremain;i++)	//У������
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;//��Ҫ����  	  
		}
		if(i<secremain)				//��Ҫ����
		{
			STMFLASH_ErasePage(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE);//�����������
			for(i=0;i<secremain;i++)//����
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//д����������  
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);//д�Ѿ������˵�,ֱ��д������ʣ������. 				   
		if(NumToWrite==secremain)break;//д�������
		else//д��δ����
		{
			secpos++;				//������ַ��1
			secoff=0;				//ƫ��λ��Ϊ0 	 
		   	pBuffer+=secremain;  	//ָ��ƫ��
			WriteAddr+=secremain*2;	//д��ַƫ��(16λ���ݵ�ַ,��Ҫ*2)	   
		   	NumToWrite-=secremain;	//�ֽ�(16λ)���ݼ�
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;//��һ����������д����
			else secremain=NumToWrite;//��һ����������д����
		}	 
	};	
	STMFLASH_Lock();//����
}
#endif

//��ָ����ַ��ʼ����ָ�����ȵ�����
//ReadAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);//��ȡ2���ֽ�.
		ReadAddr+=2;//ƫ��2���ֽ�.	
	}
}

//////////////////////////////////////////������///////////////////////////////////////////
//WriteAddr:��ʼ��ַ
//WriteData:Ҫд�������
//void Test_Write(u32 WriteAddr,u16 WriteData)   	
//{
//	STMFLASH_Write(WriteAddr,&WriteData,1);//д��һ���� 
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

////д
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


