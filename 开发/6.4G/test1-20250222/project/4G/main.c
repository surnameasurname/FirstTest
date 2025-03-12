/*!
    \file  main.c
    \brief TIMER Breath LED demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-05-19, V1.0.0, demo for GD32F30x
*/

#include "gd32f30x.h"
#include "gd32f303e_eval.h"
#include "systick.h"
#include "timer_pwm.h"
#include "timer.h"
#include "communication1.h"
#include "led.h"
#include "adc.h"



/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/

uint8_t uart2_rcev_buff[100];
uint8_t uart2_rcev_index = 0;
uint8_t u8UsartRxData[100];
uint8_t u8UsartRxCnt;
uint8_t u8fReceiveStart;
uint8_t receive_done = 0;
uint8_t receive_flag = 0;

uint8_t Led_Flag = 0;
uint16_t ADC_val1 = 0;
uint16_t ADC_val2 = 0;

uint16_t crc_data = 0;
uint8_t Modbus2_Data[20];


int main(void)
{
    int16_t i = 0;
    FlagStatus breathe_flag = SET;
    
    
    /* configure the TIMER peripheral */
    //timer_pwm_config();
    
    /* configure systick */
    systick_config();
	
		gpio_pwm_config();
//		led_init();
//		adc_init();
//	
//		timer5_init(3000 - 1, 100 - 1);
//    timer1_init();
//    communication1_init();
//	
//		ReceiveMode = fmc_read_ReceiveMode_16b(0x08010004);
//		if(ReceiveMode == 0xffff)
//		{
//			ReceiveMode = 1;						//默认发送模式
//			WriteAdd(Address1,Address2,ReceiveMode);
//		}
	

    while (1){
        /* delay a time in milliseconds */
        delay_1ms(40);
        if (SET == breathe_flag){
             i = i + 10;
        }else{
            i = i - 10;
        }
        if(500 < i){
            breathe_flag = RESET;
						
        }
        if(0 >= i){
            breathe_flag = SET;
        }
        //配置TIMER通道输出脉冲值 也就是 CHX_CV值
				//-----------------------------------------------------------------
//				if(NumTest >= 1){
//						//转换LED    发送模块  发送ADC值
//						if(ReceiveMode == 1){
//							ADC_val1 = adc_inserted_data_read(ADC0,ADC_CHANNEL_6);
//							ADC_val2 = adc_inserted_data_read(ADC0,ADC_CHANNEL_7);
//							//send
//							if(receive_done == 3){

//								Modbus2_Send();
//								
//							}
//							
//						}
//						if(Led_Flag == 0)				//进入一次   灯反向一次
//						{
//							led_on();
//						}if(Led_Flag == 1)
//						{
//							led_off();
//						}
//						NumTest = 0;
//				}
//				//串口modbus
//        Modbus_Event_1();
//				if(ReceiveMode == 2)
//				{
//					//网口Modbus   接收处理
//					if(receive_done == 10){
//						timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_1,100);
//						timer_channel_output_pulse_value_config(TIMER4,TIMER_CH_2,200);
//						Modbus2_Receive();
//					}
//				
//					
//				}
				
				
				
				
				//--------------------------------------------------------------------
				
				
				
				
				
				
				
				
				
    }
}
