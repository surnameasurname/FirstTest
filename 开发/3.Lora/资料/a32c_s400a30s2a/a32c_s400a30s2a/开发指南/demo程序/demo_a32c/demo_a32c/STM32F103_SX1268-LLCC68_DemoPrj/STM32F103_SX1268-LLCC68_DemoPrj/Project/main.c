#include "main.h"

/**
  ******************************************************************************
  * @author  泽耀科技 ASHINING
  * @version V3.0
  * @date    2021-11-24
  * @brief   主函数C文件
  ******************************************************************************
  * @attention
  *
  * 官网	:	http://www.ashining.com
  * 淘宝	:	https://shop105912646.taobao.com
  * 阿里巴巴:	https://cdzeyao.1688.com
  ******************************************************************************
  
 //==========引脚接线图
1、STM32串口配置：串口1（PA9-TXD   PA10-RXD）   波特率-9600    8位数据位   1位停止位
    STM32与SX1268是软件SPI通信
    
2、LED     LED0    PC3       --发送指示灯
           LED1    PC2       --接收指示灯

3、射频模块与单片机接线---最少接线图
    SX1268   STM32
    SCK         PA5     --SPI时钟输出
    MISO        PA6     --SPI数据输入
    MOSI        PA7     --SPI数据输出
    NSS         PA4     --SPI片选
    
    NRST        PA3     --复位
    BUSY        PA2     --忙
    TXEN        PA1     --发送使能
    RXEN        PA0     --接收使能
    DIO1        PC0     --（按需求使用）
4、程序功能--射频收发一体
    射频发送：SX1268发送单片机串口接收到的数据
    射频接收：SX1268接收到数据以后，通过单片机串口打印出来
  */

uint8_t g_RxBuffer[ 256 ] = { 0 }; 
uint8_t g_RxLen = 0;

int main()
{
	uint8_t irqRegs=0;
	delay_init();	    //延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//NVIC分组2：2位抢占优先级，2位响应优先
	USART1_Init(9600);		//UASRT1初始化
	LEDGPIO_Init();
	TIMx_Init(TIM2,10);	    //定时器2初始化
    
    RadioInit();            //SX1268初始化
    RadioStandby();
	{
		RadioSetTxConfig(MODEM_LORA, 22, 0,
						 2,11,
						 1, 12,
						 FALSE, TRUE  ,
						 FALSE,0, 0, 3000);

		RadioSetChannel(433000000);					 		 
	}
    
    USART_SendString( USART1 , "STM32F103+SX1268 收发测试\r\n");
    LED_Toogle(3);
    
    RadioRx(0);	
    
	while(1)
	{
        //SX1268发送
        if( Uart_dat.Receive_OK )
		{
            RadioSend( Uart_dat.Recv_Buff , Uart_dat.Receive_Num , 0 );
			Clear_Uart_Dat( &Uart_dat );
            USART_SendString( USART1 , "发送完成\r\n");
            LED0_TOOGLE;                        //发送指示
		}
        
        //SX1268接收
        irqRegs = RadioGetIrqStatus();
        if( ( irqRegs & IRQ_RX_DONE ) == IRQ_RX_DONE )
		{
            RadioClearIrqStatus(IRQ_RADIO_ALL);
            RadioRx(0);                         //变为接收状态
            RadioGetBuffer( g_RxBuffer, &g_RxLen, 255 );
            
            if( g_RxLen )
            {
                USART_SendBuffDat( USART1 , g_RxBuffer , g_RxLen );
                LED1_TOOGLE;                    //接收指示灯
            }
        } 
	}
}
