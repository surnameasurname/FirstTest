#include "main.h"
#include "led.h"
#include "adc.h"
#include "timer.h"
#include "gd32f30x_dac.h"
#include "sx126x_driver.h"
#include "drv_pwm.h"


uint8_t u8UsartRxData[100];
uint8_t u8UsartRxCnt;
uint8_t u8fReceiveStart;
uint16_t u16RxcheckSum = 0;
uint8_t u8RxFinished;
uint8_t Test[ 10 ] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
uint8_t EnReceive = 0;

uint8_t irqRegs = 0;
uint8_t g_RxBuffer[ 256 ] = { 0 };
uint8_t g_RxLen = 0;
uint8_t buff[ 10 ] = { 0 };


uint8_t AddressInit = 0;

uint16_t tempdata1 = 0;
uint16_t tempdata2 = 0;
uint16_t DACdata1 = 0;
uint16_t DACdata2 = 0;

uint16_t countnum = 0;
uint16_t countnum1=0;
uint16_t countnum2=0;

uint8_t uart2_rcev_buff[100];
uint8_t uart2_rcev_index = 0;
uint8_t receive_done = 0;
uint8_t receive_flag = 0;
uint8_t Led_Flag = 0;
uint16_t ADC_val1 = 0;
uint16_t ADC_val2 = 0;
uint16_t crc_data = 0;
uint8_t Modbus2_Data[20];
uint16_t radio1 = 0;
uint16_t radio2 = 0;

int main(void)
{

    nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
    systick_config();    //主频120MHz
    usart0_config(4800);//
    usart2_config(57600);
    led_init();

//    /* configure RCU peripheral */
//    dac_init();

    timer5_init(3000 - 1, 100 - 1);
    timer4_init();
    communication1_init();

    dbg_trace_pin_disable();
    rcu_periph_clock_enable(RCU_AF);
    gpio_pin_remap_config(GPIO_SWJ_SWDPENABLE_REMAP, ENABLE);

    adc_config();
    //flash 写入函数   读取函数
    Address1 = fmc_read_data_16b(0x08010000);
    Address2 = fmc_read_Address2_16b(0x08010002);
    ReceiveMode = fmc_read_ReceiveMode_16b(0x08010004);
    if(Address1 == 0xFFFF){
        Address1 = 10;
        AddressInit = 1;
    }
    if(Address2 == 0xFFFF){
        Address2 = 11;
        AddressInit = 1;
    }
    if(ReceiveMode == 0xFFFF){
        ReceiveMode = 2;
        AddressInit = 1;
    }
    if(AddressInit == 1)
    {
        WriteAdd(Address1,Address2,ReceiveMode);
        AddressInit = 0;
    }
    ReceiveBuff[0] = 'I';
    ReceiveBuff[1] = 'D';
    ReceiveBuff[2] = ':';
    ReceiveBuff[3] = Address1;
    ReceiveBuff[4] = '*';
    
    
    pwm_gpio_config();
    pwm_timer_config();
    while (1)
    {
        
//        uint32_t system_clock = rcu_clock_freq_get(CK_SYS);
////        printf("System Clock: %d Hz\n", system_clock);
//        
//        if (NumTest != 0)
//        {
////            printf("a usart transmit test example!");
////            printf("11111\r\n");
//            printf("%d \n", system_clock);
//            led_on();
//            delay_1ms(50);
//            led_off();
//            delay_1ms(300);
//            led_on();
//            delay_1ms(50);
//            led_off();
//            NumTest = 0;

//        }
//        Modbus_Event_1();
        
        ReceiveMode = 2;
        if(NumTest >= 1)
        {
            if(ReceiveMode == 1)
            {
                ADC_val1=(uint16_t)(adc_channel_sample(ADC_CHANNEL_6)/4096.0f*20000);    //换算成mA
                ADC_val2=(uint16_t)(adc_channel_sample(ADC_CHANNEL_7)/4096.0f*20000);
                
                if(receive_done == 3)
                {
                    Modbus2_Send();
                }
            }
            if(Led_Flag == 0)            
            {
                led_on();
            }
            if(Led_Flag == 1)
            {
                led_off();
            }
            NumTest = 0;
        }
        
        Modbus_Event_1();
        if(ReceiveMode == 2)
        { 
            if(receive_done == 6)
            {
                ADC_val1 = uart2_rcev_buff[4]*256+uart2_rcev_buff[5];
                ADC_val2 = uart2_rcev_buff[2]*256+uart2_rcev_buff[3];
                Modbus2_Send();
                //uint16_t current=(uint16_t)(ADC_val1/(4096.0f-819.0f)*16.0f*1000);       //换算成mA
                radio1=(uint16_t)(ADC_val1*(-0.0786f)+2001.5);
                radio2=(uint16_t)(ADC_val2*(-0.0786f)+2001.5);
                timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_1,radio1);
                timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_2,radio2);
            }
        }
    }
}

