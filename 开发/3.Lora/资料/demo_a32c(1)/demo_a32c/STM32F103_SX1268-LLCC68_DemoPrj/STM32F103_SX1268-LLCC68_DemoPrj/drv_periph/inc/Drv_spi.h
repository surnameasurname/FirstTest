#ifndef _DRV_SPI_H
#define _DRV_SPI_H

#include "sys.h"

#define SCLK_H	PAout(5) = 1		//时钟信号输出高电平
#define SCLK_L	PAout(5) = 0		//时钟信号输出低电平

#define MOSI_H	PAout(7) = 1
#define MOSI_L	PAout(7) = 0

#define MISO_READ	PAin(6)

void SPI_GPIO_Init( void );
uint8_t drv_spi_read_write_byte( uint8_t dat );
#endif
