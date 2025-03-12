#include "Drv_spi.h"

#include "systick.h"

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
void SPI_GPIO_Init(void)
{
    dbg_trace_pin_disable();
    rcu_periph_clock_enable(RCU_AF);
    gpio_pin_remap_config(GPIO_SWJ_SWDPENABLE_REMAP, ENABLE);
    //MOSI SCLK
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOB);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5 | GPIO_PIN_3);
    //MISO;
    rcu_periph_clock_enable(RCU_GPIOB);

    /* connect port to USARTx_Tx */
    //gpio_init(GPIOB, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, GPIO_PIN_4);
    gpio_init(GPIOB, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, GPIO_PIN_4);


//          gpio_bit_set(GPIOB, GPIO_PIN_3);
//          gpio_bit_set(GPIOB, GPIO_PIN_5);

}

void SCLK_H(void)
{
    gpio_bit_set(GPIOB, GPIO_PIN_3);
}
void SCLK_L(void)
{
    gpio_bit_reset(GPIOB, GPIO_PIN_3);
}

void MOSI_H(void)
{
    gpio_bit_set(GPIOB, GPIO_PIN_5);
}
void MOSI_L(void)
{
    gpio_bit_reset(GPIOB, GPIO_PIN_5);
}

FlagStatus  MISO_READ(void)
{
    return gpio_input_bit_get(GPIOB, GPIO_PIN_4);
}


/*----软件 SPI ----*/
uint8_t drv_spi_read_write_byte(uint8_t txDat)
{
    uint8_t i ;
    for (i = 0 ; i < 8 ; i++)
    {
        if (txDat & 0X80)
            MOSI_H();
        else
            MOSI_L();
        txDat <<= 1;
        delay_us(65);
        SCLK_H();

        if (MISO_READ())
            txDat |= 0X01;
        delay_us(65);
        SCLK_L();
    }
    return txDat;
}
