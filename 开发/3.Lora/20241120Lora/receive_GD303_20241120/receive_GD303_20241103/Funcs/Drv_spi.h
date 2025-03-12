#ifndef _DRV_SPI_H
#define _DRV_SPI_H

#include "gd32f30x.h"
#include "delay.h"


void SCLK_H(void);
void SCLK_L(void);

void MOSI_H(void);
void MOSI_L(void);

FlagStatus  MISO_READ(void);

//#define MISO_READ	PAin(6)

void SPI_GPIO_Init( void );
uint8_t drv_spi_read_write_byte( uint8_t dat );
#endif
