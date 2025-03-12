#include "main.h"

/**
  ******************************************************************************
  * @author  ��ҫ�Ƽ� ASHINING
  * @version V3.0
  * @date    2021-11-24
  * @brief   ������C�ļ�
  ******************************************************************************
  * @attention
  *
  * ����	:	http://www.ashining.com
  * �Ա�	:	https://shop105912646.taobao.com
  * ����Ͱ�:	https://cdzeyao.1688.com
  ******************************************************************************
  
 //==========���Ž���ͼ
1��STM32�������ã�����1��PA9-TXD   PA10-RXD��   ������-9600    8λ����λ   1λֹͣλ
    STM32��SX1268�����SPIͨ��
    
2��LED     LED0    PC3       --����ָʾ��
           LED1    PC2       --����ָʾ��

3����Ƶģ���뵥Ƭ������---���ٽ���ͼ
    SX1268   STM32
    SCK         PA5     --SPIʱ�����
    MISO        PA6     --SPI��������
    MOSI        PA7     --SPI�������
    NSS         PA4     --SPIƬѡ
    
    NRST        PA3     --��λ
    BUSY        PA2     --æ
    TXEN        PA1     --����ʹ��
    RXEN        PA0     --����ʹ��
    DIO1        PC0     --��������ʹ�ã�
4��������--��Ƶ�շ�һ��
    ��Ƶ���ͣ�SX1268���͵�Ƭ�����ڽ��յ�������
    ��Ƶ���գ�SX1268���յ������Ժ�ͨ����Ƭ�����ڴ�ӡ����
  */

uint8_t g_RxBuffer[ 256 ] = { 0 }; 
uint8_t g_RxLen = 0;

int main()
{
	uint8_t irqRegs=0;
	delay_init();	    //��ʱ������ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//NVIC����2��2λ��ռ���ȼ���2λ��Ӧ����
	USART1_Init(9600);		//UASRT1��ʼ��
	LEDGPIO_Init();
	TIMx_Init(TIM2,10);	    //��ʱ��2��ʼ��
    
    RadioInit();            //SX1268��ʼ��
    RadioStandby();
	{
		RadioSetTxConfig(MODEM_LORA, 22, 0,
						 2,11,
						 1, 12,
						 FALSE, TRUE  ,
						 FALSE,0, 0, 3000);

		RadioSetChannel(433000000);					 		 
	}
    
    USART_SendString( USART1 , "STM32F103+SX1268 �շ�����\r\n");
    LED_Toogle(3);
    
    RadioRx(0);	
    
	while(1)
	{
        //SX1268����
        if( Uart_dat.Receive_OK )
		{
            RadioSend( Uart_dat.Recv_Buff , Uart_dat.Receive_Num , 0 );
			Clear_Uart_Dat( &Uart_dat );
            USART_SendString( USART1 , "�������\r\n");
            LED0_TOOGLE;                        //����ָʾ
		}
        
        //SX1268����
        irqRegs = RadioGetIrqStatus();
        if( ( irqRegs & IRQ_RX_DONE ) == IRQ_RX_DONE )
		{
            RadioClearIrqStatus(IRQ_RADIO_ALL);
            RadioRx(0);                         //��Ϊ����״̬
            RadioGetBuffer( g_RxBuffer, &g_RxLen, 255 );
            
            if( g_RxLen )
            {
                USART_SendBuffDat( USART1 , g_RxBuffer , g_RxLen );
                LED1_TOOGLE;                    //����ָʾ��
            }
        } 
	}
}
