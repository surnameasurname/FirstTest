#include "main.h"
#include "led.h"
#include "timer.h"
#include "gd32f30x_dac.h"
#include "sx126x_driver.h"
#include "adc.h"
#include "pwm.h"

uint8_t uart2_rcev_buff[100];
uint8_t uart2_rcev_index = 0;
uint8_t u8UsartRxData[100];
uint8_t u8UsartRxCnt;
uint8_t u8fReceiveStart;
uint8_t receive_done = 0;
uint8_t receive_flag = 0;

uint8_t Modbus2_Data[20];


uint8_t Led_Flag = 0;
uint16_t ADC_val1 = 0;
uint16_t ADC_val2 = 0;

uint16_t crc_data = 0;

int main(void)
{
	
		
    //uint16_t tempdata[1] = {100};
    nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
    systick_config();    //主频120MHz

    led_init();
		adc_init();
		
		timer_CH2_3_pwm_config();
    /* configure RCU peripheral */
    //dac_init();
		//-----------------------------
		//Modbus	chuankou
    timer5_init(3000 - 1, 100 - 1);
    timer1_init();
    communication1_init();
		//--------------------------------------
//    dbg_trace_pin_disable();
//    rcu_periph_clock_enable(RCU_AF);
//    gpio_pin_remap_config(GPIO_SWJ_SWDPENABLE_REMAP, ENABLE);



    //flash 写入函数   读取函数
			ReceiveMode = fmc_read_ReceiveMode_16b(0x08010004);
			if(ReceiveMode == 0xffff)
			{
				ReceiveMode = 1;						//默认发送模式
				WriteAdd(Address1,Address2,ReceiveMode);
			}

    while (1)
    {
				if(NumTest >= 1){
					
						if(ReceiveMode == 1){
							ADC_val1 = adc_inserted_data_read(ADC0,ADC_CHANNEL_6);
							ADC_val2 = adc_inserted_data_read(ADC0,ADC_CHANNEL_7);
							//send
							if(receive_done == 3){

								Modbus2_Send();
								
							}
							
						}
						if(Led_Flag == 0)				//进入一次   灯反向一次
						{
							led_on();
						}if(Led_Flag == 1)
						{
							led_off();
						}
						NumTest = 0;
				}
				//串口modbus
        Modbus_Event_1();
				if(ReceiveMode == 2)
				{
					//网口Modbus   接收处理
					if(receive_done == 10){
						timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,100);
						timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_2,200);
						Modbus2_Receive();
					}
				
					
				}
				
    }
}
