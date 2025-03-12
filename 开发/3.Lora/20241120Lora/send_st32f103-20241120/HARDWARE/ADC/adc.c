#include "adc.h"
#include "delay.h"

//初始化ADC
void  AdcInit(void)
{
    //先初始化IO口
    RCC->APB2ENR |= 1 << 2; //使能PORTA口时钟
    GPIOA->CRL &= 0XFFFFF00F; //PA3 anolog输入

//  RCC->APB2ENR|=1<<3;    //使能PORTB口时钟
//  GPIOB->CRL&=0XFFFFFF00;//PB0,1 anolog输入
//  RCC->APB2ENR|=1<<4;    //使能PORTC口时钟
//  GPIOC->CRL&=0XFF0FF00F;//PC1,2，5 anolog输入


    RCC->APB2ENR |= 1 << 9; //ADC1时钟使能
    RCC->APB2RSTR |= 1 << 9; //ADC1复位
    RCC->APB2RSTR &= ~(1 << 9); //复位结束
    RCC->CFGR &= ~(3 << 14); //分频因子清零
    //SYSCLK/DIV2=12M ADC时钟设置为12M,ADC最大时钟不能超过14M!
    //否则将导致ADC准确度下降!
    RCC->CFGR |= 2 << 14;
    ADC1->CR1 &= 0XF0FFFF; //工作模式清零
    ADC1->CR1 |= 0 << 16;  //独立工作模式
    ADC1->CR1 &= ~(1 << 8); //非扫描模式
    ADC1->CR2 &= ~(1 << 1); //单次转换模式
    ADC1->CR2 &= ~(7 << 17);
    ADC1->CR2 |= 7 << 17;    //软件控制转换
    ADC1->CR2 |= 1 << 20;  //使用用外部触发(SWSTART)!!! 必须使用一个事件来触发
    ADC1->CR2 &= ~(1 << 11); //右对齐
    ADC1->SQR1 &= ~(0XF << 20);
    ADC1->SQR1 |= 0 << 20; //1个转换在规则序列中 也就是只转换规则序列1
    //设置通道0的采样时间
    ADC1->SMPR2 &= ~(7 << 3); //通道0采样时间清空
    ADC1->SMPR2 |= 7 << 3; //通道0  239.5周期,提高采样时间可以提高精确度
    ADC1->CR2 |= 1 << 0;   //开启AD转换器
    ADC1->CR2 |= 1 << 3;   //使能复位校准
    while (ADC1->CR2 & 1 << 3); //等待校准结束
    //该位由软件设置并由硬件清除。在校准寄存器被初始化后该位将被清除。
    ADC1->CR2 |= 1 << 2;    //开启AD校准
    while (ADC1->CR2 & 1 << 2); //等待校准结束
    //该位由软件设置以开始校准，并在校准结束时由硬件清除
}
//获得ADC值
//ch:通道值 0~16
//返回值:转换结果
u16 Get_Adc(u8 ch)
{
    //设置转换序列
    ADC1->SQR3 &= 0XFFFFFFE0; //规则序列1 通道ch
    ADC1->SQR3 |= ch;
    ADC1->CR2 |= 1 << 22;   //启动规则转换通道
    while (!(ADC1->SR & 1 << 1)); //等待转换结束
    return ADC1->DR;        //返回adc值
}
//获取通道ch的转换值，取times次,然后平均
//ch:通道编号
//times:获取次数
//返回值:通道ch的times次转换结果平均值
u16 GetAdcAverage(u8 ch, u16 times)
{
    u32 temp_val = 0;
    //float temp = 0;
    u16 t;
    for (t = 0; t < times; t++)
    {
        temp_val += Get_Adc(ch);
        delay_ms(1);
    }
    temp_val = temp_val / times;            //AD值
    
//    u16 temp_val[10] = {0};
//    u8 t;
//    for (t = 0; t < times; t++)
//    {
//        temp_val[t]= Get_Adc(ch);
//        delay_ms(90);
//    }

//    return ((temp_val[0]+temp_val[1]+temp_val[2]+temp_val[3]+temp_val[4]+temp_val[5]+temp_val[6]+temp_val[7]+temp_val[8]+temp_val[9]) / times);            //AD值
    
    
//  temp=(float)temp_val*(3.0/4096);//换算成电压值
//  //DAC输出值为AD值1.3333倍
//  temp = temp*1.3333;
//  //计算dac输出数字值
//  temp=(temp/4.84)*4095;
//  temp_val=temp;
//  //return temp_val/times;
    return temp_val;
}



