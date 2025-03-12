#include "Drv_spi.h"
#include "delay.h"

/*--射频模块与单片机接线
    SX1268   STM32
    SCK         PA5     --输出
    MISO        PA6     --输入
    MOSI        PA7     --输出
    NSS         PA4     --片选
    
    NRST        PA3     --  
    BUSY        PA2
    TXEN        PA1
    RXEN        PA0
    DIO1        PC0     
  */
/*----SPI GPIO 初始化----*/
void SPI_GPIO_Init( void )
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);
    //MOSI SCLK
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7 ;   
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    //MISO;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_Init(GPIOA,&GPIO_InitStructure);    
}

/*----软件 SPI ----*/
uint8_t drv_spi_read_write_byte( uint8_t txDat )
{
 	uint8_t i ;
	for( i = 0 ; i < 8 ; i++ )
	{
		if( txDat & 0X80 )
			MOSI_H;
		else
			MOSI_L;
		txDat <<= 1;
		delay_us(4);
		SCLK_H;
		
		if( MISO_READ )
			txDat |= 0X01;
		delay_us(4);
		SCLK_L;
	}
	return txDat;    
}
