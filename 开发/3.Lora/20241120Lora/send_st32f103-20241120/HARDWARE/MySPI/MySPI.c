#include "MySPI.h"
#include "sys.h"
#include "delay.h"


void SPI1_SetSpeed(u8 SpeedSet);
//u8 drv_spi_read_write_byte(u8 TxData);


//������SPIģ��ĳ�ʼ�����룬���ó�����ģʽ				  
//SPI�ڳ�ʼ��
//�������Ƕ�SPI1�ĳ�ʼ��
void SPI1_Init(void)
{	 
	RCC->APB2ENR|=1<<2;       //PORTAʱ��ʹ�� 	 
//	RCC->APB2ENR|=1<<12;      //SPI1ʱ��ʹ�� 
		   
	//����ֻ���SPI�ڳ�ʼ��
	GPIOA->CRL&=0X0000FFFF; 
	GPIOA->CRL|=0X3B330000;//PA4.5.6.7���� 	    
	//GPIOA->ODR|=0X5<<5;    //PA4.5.6.7����
	
	
		
//	SPI1->CR1|=0<<10;//ȫ˫��ģʽ	
//	SPI1->CR1|=1<<9; //���nss����
//	SPI1->CR1|=1<<8;  

//	SPI1->CR1|=1<<2; //SPI����
//	SPI1->CR1|=0<<11;//8bit���ݸ�ʽ	
//	SPI1->CR1|=1<<1; //����ģʽ��SCKΪ1 CPOL=1
//	SPI1->CR1|=1<<0; //���ݲ����ӵڶ���ʱ����ؿ�ʼ,CPHA=1  
//	SPI1->CR1|=7<<3; //Fsck=Fcpu/256
//	SPI1->CR1|=0<<7; //MSBfirst   
//	SPI1->CR1|=1<<6; //SPI�豸ʹ��
//	drv_spi_read_write_byte(0xff);//��������(��Ҫ���ã�ά��MOSIΪ��)		 
//	
//	SPI1_SetSpeed(SPI_SPEED_32);
}   

//SPI1 �ٶ����ú���
//SpeedSet:0~7
//SPI�ٶ�=fAPB2/2^(SpeedSet+1)
//APB2ʱ��һ��Ϊ72Mhz
void SPI1_SetSpeed(u8 SpeedSet)
{
//	SpeedSet&=0X07;			//���Ʒ�Χ
//	SPI1->CR1&=0XFFC7; 
//	SPI1->CR1|=SpeedSet<<3;	//����SPI1�ٶ�  
//	SPI1->CR1|=1<<6; 		//SPI�豸ʹ�� 
} 

//SPI1 ��дһ���ֽ�
//TxData:Ҫд����ֽ�
//����ֵ:��ȡ�����ֽ�
//u8 drv_spi_read_write_byte(u8 TxData)
//{		
//	u16 retry=0;				 
//	while((SPI1->SR&1<<1)==0)//�ȴ���������	
//	{
//		retry++;
//		if(retry>0XFFFE)return 0;
//	}			  
//	SPI1->DR=TxData;	 	  //����һ��byte 
//	retry=0;
//	while((SPI1->SR&1<<0)==0) //�ȴ�������һ��byte  
//	{
//		retry++;
//		if(retry>0XFFFE)return 0;
//	}	  						    
//	return SPI1->DR;          //�����յ�������				    
//}

u8 drv_spi_read_write_byte(u8 txDat)
{		
	uint8_t i ;
	for( i = 0 ; i < 8 ; i++ )
	{
		if( txDat & 0X80 )
			MOSI_H;
		else
			MOSI_L;
		txDat <<= 1;
		delay_us(65);
		SCLK_H;
		
		if( MISO_READ )
			txDat |= 0X01;
		delay_us(65);
		SCLK_L;
	}
	return txDat;			    
}






//SPI��������
void SPI_SendByte(u8 data)
{
	u8 i;
	for(i=0; i<8; i++){
		if(data & 0x80){
				//DACDATA = 1;
		}else{
				//DACDATA = 0;
		}
		//�л�SKL
		//DACSCK = 1;
		delay_us(60);
		//DACSCK = 0;
		data<<=1;
	}
	
}






