#define __ADC_C__

#include <gd32f30x.h>
#include "adc.h"

void adc_gpio_config(void)
{
	/* 使能 GPIOC clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    /* 使能 GPIOA clock */
    rcu_periph_clock_enable(RCU_GPIOA); 
	
    /* 设置PC3 和 PC5 引脚为模拟输入 */  
    gpio_init(GPIOC, GPIO_MODE_AIN, GPIO_OSPEED_MAX, GPIO_PIN_3|GPIO_PIN_5);
    /*configure PA8(TIMER0 CH0) as alternate function*/
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_8);  
}

//设置DMA传输
void adc_dma_init(void)
{
	/* ADC_DMA_channel configuration */
	dma_parameter_struct dma_data_parameter;
	
	/* 使能 DMA clock */
    rcu_periph_clock_enable(RCU_DMA0);
	
	/* ADC_DMA_channel deinit */
	dma_deinit(DMA0, DMA_CH0);
	
	/* initialize DMA single data mode */
	dma_data_parameter.periph_addr = (uint32_t)(&ADC_RDATA(ADC0));
	dma_data_parameter.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
	dma_data_parameter.memory_addr = (uint32_t)(adc_value);
	dma_data_parameter.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
	dma_data_parameter.periph_width = DMA_PERIPHERAL_WIDTH_32BIT;
	dma_data_parameter.memory_width = DMA_MEMORY_WIDTH_32BIT;
	dma_data_parameter.direction = DMA_PERIPHERAL_TO_MEMORY;
	dma_data_parameter.number = 2;
	dma_data_parameter.priority = DMA_PRIORITY_HIGH;  
	dma_init(DMA0, DMA_CH0, dma_data_parameter);
  
	dma_circulation_enable(DMA0, DMA_CH0);
  
	/* enable DMA channel */
	dma_channel_enable(DMA0, DMA_CH0);	
}

//定时器触发采集
void adc_timer_init(void)
{
	timer_oc_parameter_struct timer_ocintpara;
	timer_parameter_struct timer_initpara;
	
	/* enable TIMER0 clock */
    rcu_periph_clock_enable(RCU_TIMER0);

	/* TIMER0 configuration */
	timer_initpara.prescaler		 = 8399;
	timer_initpara.alignedmode		 = TIMER_COUNTER_EDGE;
	timer_initpara.counterdirection  = TIMER_COUNTER_UP;
	timer_initpara.period			 = 9999;
	timer_initpara.clockdivision	 = TIMER_CKDIV_DIV1;
	timer_initpara.repetitioncounter = 0;
	timer_init(TIMER0, &timer_initpara);

	/* CH0 configuration in PWM mode0 */
	timer_ocintpara.ocpolarity	= TIMER_OC_POLARITY_HIGH;
	timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
	timer_channel_output_config(TIMER0, TIMER_CH_0, &timer_ocintpara);

	timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_0, 3999);
	timer_channel_output_mode_config(TIMER0, TIMER_CH_0, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(TIMER0, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);

	/* TIMER0 primary output enable */
	timer_primary_output_config(TIMER0, ENABLE);
	/* auto-reload preload enable */
	timer_auto_reload_shadow_enable(TIMER0); 
	
	/* enable TIMER0 */
	timer_enable(TIMER0);
}


void adc_init(void)
{
	/* enable ADC0 clock */
    rcu_periph_clock_enable(RCU_ADC0);
    /* enable ADC1 clock */
    rcu_periph_clock_enable(RCU_ADC1);
    /* config ADC clock */
    rcu_adc_clock_config(RCU_CKADC_CKAPB2_DIV6);
	
	/* ADC scan mode function enable */
	adc_special_function_config(ADC0, ADC_SCAN_MODE, ENABLE);
	adc_special_function_config(ADC1, ADC_SCAN_MODE, ENABLE);
	/* ADC trigger config */
	adc_external_trigger_source_config(ADC0, ADC_REGULAR_CHANNEL, ADC0_1_EXTTRIG_REGULAR_T0_CH0);
	adc_external_trigger_source_config(ADC1, ADC_REGULAR_CHANNEL, ADC0_1_2_EXTTRIG_REGULAR_NONE);
	/* ADC data alignment config */
	adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);
	adc_data_alignment_config(ADC1, ADC_DATAALIGN_RIGHT);
	/* configure the ADC sync mode */
	adc_mode_config(ADC_DAUL_REGULAL_FOLLOWUP_FAST);  
	/* ADC channel length config */
	adc_channel_length_config(ADC0, ADC_REGULAR_CHANNEL,2);
	adc_channel_length_config(ADC1, ADC_REGULAR_CHANNEL,2);
  
	/* ADC regular channel config */
	adc_regular_channel_config(ADC0, 0, ADC_CHANNEL_13, ADC_SAMPLETIME_239POINT5);
	adc_regular_channel_config(ADC0, 1, ADC_CHANNEL_15, ADC_SAMPLETIME_239POINT5);
	adc_regular_channel_config(ADC1, 0, ADC_CHANNEL_15, ADC_SAMPLETIME_239POINT5);
	adc_regular_channel_config(ADC1, 1, ADC_CHANNEL_13, ADC_SAMPLETIME_239POINT5);
  
	/* ADC external trigger enable */
	adc_external_trigger_config(ADC0, ADC_REGULAR_CHANNEL, ENABLE);
	adc_external_trigger_config(ADC1, ADC_REGULAR_CHANNEL, ENABLE);
   
	/* enable ADC interface */
	adc_enable(ADC0);
	delay_1ms(1);	 
	/* ADC calibration and reset calibration */
	adc_calibration_enable(ADC0);
	/* enable ADC interface */
	adc_enable(ADC1);	 
	delay_1ms(1);
	/* ADC calibration and reset calibration */
	adc_calibration_enable(ADC1);
	
	/* ADC DMA function enable */
	adc_dma_mode_enable(ADC0);
}




