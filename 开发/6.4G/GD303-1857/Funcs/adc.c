#include "gd32f30x_adc.h"
#include "adc.h"
#include "delay.h"

void adc_init()
{
    rcu_periph_clock_enable(RCU_GPIOA);
    gpio_init(GPIOA, GPIO_MODE_AIN, GPIO_OSPEED_MAX, GPIO_PIN_6 | GPIO_PIN_7);
		//使能ADC0时钟源
		rcu_periph_clock_enable(RCU_ADC0);
		//rcu_periph_clock_enable(RCU_ADC1);
    //配置预分频
		rcu_adc_clock_config(RCU_CKADC_CKAHB_DIV6); 
		
		//adc_mode_config(ADC_MODE_FREE);
		
		//ADC扫描模式打开
		adc_special_function_config(ADC0, ADC_SCAN_MODE, ENABLE);
	
		//adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, ENABLE);
	
		//ADC 触发方式配置 不需要外部触发
		adc_external_trigger_source_config(ADC0, ADC_INSERTED_CHANNEL,ADC0_1_2_EXTTRIG_INSERTED_NONE);
		//数据右对齐
		adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);
		/* ADC 模式配置，所有 ADC 独立工作 */
		adc_mode_config(ADC_MODE_FREE);
		//ADC转换通道大小配置，2个通道
		adc_channel_length_config(ADC0, ADC_INSERTED_CHANNEL, 2);
		//ADC通道配置
		adc_regular_channel_config(ADC0, 0, ADC_CHANNEL_6, ADC_SAMPLETIME_7POINT5);
    adc_regular_channel_config(ADC0, 1, ADC_CHANNEL_7, ADC_SAMPLETIME_7POINT5);
		/* ADC 插入组使能 */
		adc_external_trigger_config(ADC0,ADC_INSERTED_CHANNEL,ENABLE);
		
		//adc_resolution_config(ADC0, ADC_RESOLUTION_12B);
		
		
		/* 使能 ADC */
		adc_enable(ADC0);
		Delay_nms(10);
		/* ADC 校准 */
		adc_calibration_enable(ADC0);
		
		//adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, DISABLE);
	
	  //adc_resolution_config(ADC0, ADC_RESOLUTION_12B);
	
		
		
		
    
    
	
}
