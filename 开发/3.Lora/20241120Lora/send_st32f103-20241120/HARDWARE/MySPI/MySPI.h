#ifndef __myspi_H
#define __myspi_H	
#include "sys.h"
	
// SPI 速度设置
#define SPI_SPEED_2 	0
#define SPI_SPEED_4 	1
#define SPI_SPEED_8 	2
#define SPI_SPEED_16 	3
#define SPI_SPEED_32 	4
#define SPI_SPEED_64 	5
#define SPI_SPEED_128 6
#define SPI_SPEED_256 7


#define SCLK_H	PAout(5) = 1		//时钟信号输出高电平
#define SCLK_L	PAout(5) = 0		//时钟信号输出低电平

#define MOSI_H	PAout(7) = 1
#define MOSI_L	PAout(7) = 0

#define MISO_READ	PAin(6)

void SPI1_Init(void);
u8 drv_spi_read_write_byte(u8 TxData);
//SPI发送数据
void SPI_SendByte(u8 data);
#endif 



