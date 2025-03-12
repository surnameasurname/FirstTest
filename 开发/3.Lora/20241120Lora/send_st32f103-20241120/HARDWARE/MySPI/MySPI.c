#include "MySPI.h"
#include "sys.h"
#include "delay.h"


void SPI1_SetSpeed(u8 SpeedSet);
//u8 drv_spi_read_write_byte(u8 TxData);


//以下是SPI模块的初始化代码，配置成主机模式				  
//SPI口初始化
//这里针是对SPI1的初始化
void SPI1_Init(void)
{	 
	RCC->APB2ENR|=1<<2;       //PORTA时钟使能 	 
//	RCC->APB2ENR|=1<<12;      //SPI1时钟使能 
		   
	//这里只针对SPI口初始化
	GPIOA->CRL&=0X0000FFFF; 
	GPIOA->CRL|=0X3B330000;//PA4.5.6.7复用 	    
	//GPIOA->ODR|=0X5<<5;    //PA4.5.6.7上拉
	
	
		
//	SPI1->CR1|=0<<10;//全双工模式	
//	SPI1->CR1|=1<<9; //软件nss管理
//	SPI1->CR1|=1<<8;  

//	SPI1->CR1|=1<<2; //SPI主机
//	SPI1->CR1|=0<<11;//8bit数据格式	
//	SPI1->CR1|=1<<1; //空闲模式下SCK为1 CPOL=1
//	SPI1->CR1|=1<<0; //数据采样从第二个时间边沿开始,CPHA=1  
//	SPI1->CR1|=7<<3; //Fsck=Fcpu/256
//	SPI1->CR1|=0<<7; //MSBfirst   
//	SPI1->CR1|=1<<6; //SPI设备使能
//	drv_spi_read_write_byte(0xff);//启动传输(主要作用：维持MOSI为高)		 
//	
//	SPI1_SetSpeed(SPI_SPEED_32);
}   

//SPI1 速度设置函数
//SpeedSet:0~7
//SPI速度=fAPB2/2^(SpeedSet+1)
//APB2时钟一般为72Mhz
void SPI1_SetSpeed(u8 SpeedSet)
{
//	SpeedSet&=0X07;			//限制范围
//	SPI1->CR1&=0XFFC7; 
//	SPI1->CR1|=SpeedSet<<3;	//设置SPI1速度  
//	SPI1->CR1|=1<<6; 		//SPI设备使能 
} 

//SPI1 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
//u8 drv_spi_read_write_byte(u8 TxData)
//{		
//	u16 retry=0;				 
//	while((SPI1->SR&1<<1)==0)//等待发送区空	
//	{
//		retry++;
//		if(retry>0XFFFE)return 0;
//	}			  
//	SPI1->DR=TxData;	 	  //发送一个byte 
//	retry=0;
//	while((SPI1->SR&1<<0)==0) //等待接收完一个byte  
//	{
//		retry++;
//		if(retry>0XFFFE)return 0;
//	}	  						    
//	return SPI1->DR;          //返回收到的数据				    
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






//SPI发送数据
void SPI_SendByte(u8 data)
{
	u8 i;
	for(i=0; i<8; i++){
		if(data & 0x80){
				//DACDATA = 1;
		}else{
				//DACDATA = 0;
		}
		//切换SKL
		//DACSCK = 1;
		delay_us(60);
		//DACSCK = 0;
		data<<=1;
	}
	
}






