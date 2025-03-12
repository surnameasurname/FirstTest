#include "main.h"
#include "led.h"
#include "timer.h"
#include "gd32f30x_dac.h"
#include "sx126x_driver.h"



uint8_t u8UsartRxData[100];
uint8_t u8UsartRxCnt;
uint8_t u8fReceiveStart;
uint16_t u16RxcheckSum = 0;
uint8_t u8RxFinished;
uint8_t Test[4] = {0};
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

int main(void)
{
    //uint16_t tempdata[1] = {100};
    nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
    systick_config();    //主频120MHz
    usart0_config(4800);//

    led_init();

    /* configure RCU peripheral */
    dac_init();

    timer5_init(3000 - 1, 100 - 1);
    timer1_init();
    communication1_init();

    dbg_trace_pin_disable();
    rcu_periph_clock_enable(RCU_AF);
    gpio_pin_remap_config(GPIO_SWJ_SWDPENABLE_REMAP, ENABLE);

    //初始化  reset后，lora的BUSY一直为高，   感觉是SPI通信有问题
    RadioInit();            //SX1268初始化
    RadioStandby();
    {
        RadioSetTxConfig(MODEM_LORA, 22, 0,
                         2, 11,
                         1, 12,
                         FALSE, TRUE,
                         FALSE, 0, 0, 3000);

        RadioSetChannel(433000000);
    }
    RadioRx(0);


    //flash 写入函数   读取函数
    Address1 = fmc_read_data_16b(0x08010000);
    Address2 = fmc_read_Address2_16b(0x08010002);
    ReceiveMode = fmc_read_ReceiveMode_16b(0x08010004);
		if(Address1 == 255){
			Address1 = 10;
			AddressInit = 1;
		}
		if(Address2 == 255){
			Address2 = 11;
			AddressInit = 1;
		}
		if(ReceiveMode == 255){
			ReceiveMode = 1;
			AddressInit = 1;
		}
		if(AddressInit == 1)
		{
			WriteAdd(Address1,Address2,ReceiveMode);
			AddressInit = 0;
		}
    ReceiveBuff[0] = Address1;
    ReceiveBuff[1] = 0;
    ReceiveBuff[2] = 0;
    ReceiveBuff[3] = 0;
    ReceiveBuff[4] = '*';
    while (1)
    {
        //delay_1ms(1000);
        ////        //SX1268接收
        irqRegs = RadioGetIrqStatus();
        if ((irqRegs & IRQ_RX_DONE) == IRQ_RX_DONE)
        {
            RadioClearIrqStatus(IRQ_RADIO_ALL);
            RadioRx(0);                         //变为接收状态
            RadioGetBuffer(g_RxBuffer, &g_RxLen, 10);

            if (g_RxLen)
            {
                if (ReceiveMode == 2)
                {
                    if (g_RxBuffer[0] == Address1 || g_RxBuffer[0] == Address2)
                    {
                        countnum = 0;
                        led_on();
                        delay_1ms(50);
                        led_off();
                        delay_1ms(300);
                        led_on();
                        delay_1ms(50);
                        led_off();
												//----------------------------//
												Test[0] = g_RxBuffer[2];
												Test[1] = g_RxBuffer[3];
												Test[2] = g_RxBuffer[4];
												Test[3] = g_RxBuffer[5];
												//----------------------------//
                        tempdata1 = g_RxBuffer[4];
                        tempdata1 = tempdata1 << 8 | g_RxBuffer[5];
                        tempdata2 = g_RxBuffer[2];
                        tempdata2 = tempdata2 << 8 | g_RxBuffer[3];
                        
                        if(tempdata1>tempdata2)
                        {
                            countnum1=0;
                            DACdata1 = tempdata1;
                            dac_enable(DAC0);
                            dac_data_set(DAC0, DAC_ALIGN_12B_R, DACdata1);
														//-----------------------------------//
														RS485_Send_Data(Test,4);
                            //-----------------------------------//
                        }
                        else if(tempdata1<tempdata2)
                        {
                            countnum2=0;
                            DACdata2 = tempdata2;
                            dac_enable(DAC1);
                            dac_data_set(DAC1, DAC_ALIGN_12B_R, DACdata2);
														//-----------------------------------//
														RS485_Send_Data(Test,4);
                            //-----------------------------------//
                        }
                    }
                }
                else
                {
                    if (g_RxBuffer[0] == Address1)
                    {
                        countnum = 0;
                        countnum1=0;
                        countnum2=0;
                        led_on();
                        delay_1ms(50);
                        led_off();
                        delay_1ms(300);
                        led_on();
                        delay_1ms(50);
                        led_off();
                        tempdata1 = g_RxBuffer[4];
                        tempdata1 = tempdata1 << 8 | g_RxBuffer[5];
                        tempdata2 = g_RxBuffer[2];
                        tempdata2 = tempdata2 << 8 | g_RxBuffer[3];

                        DACdata1 = tempdata1;
                        dac_enable(DAC0);
                        dac_data_set(DAC0, DAC_ALIGN_12B_R, DACdata1);

                        DACdata2 = tempdata2;
                        dac_enable(DAC1);
                        dac_data_set(DAC1, DAC_ALIGN_12B_R, DACdata2);
												
												//-----------------------------------//
														RS485_Send_Data(Test,4);
                        //-----------------------------------//
                    }
                }
            }
        }
				
/**********************************************************************/

        if (countnum == 1200)
        {
            dac_enable(DAC0);
            dac_data_set(DAC0, DAC_ALIGN_12B_R, 0);
            dac_enable(DAC1);
            dac_data_set(DAC1, DAC_ALIGN_12B_R, 0);
        }
        if(countnum1==1200)
        {
            dac_enable(DAC0);
            dac_data_set(DAC0, DAC_ALIGN_12B_R, 0);
        }
        if(countnum2==1200)
        {
            dac_enable(DAC1);
            dac_data_set(DAC1, DAC_ALIGN_12B_R, 0);
        }
/**********************************************************************/
        
        if (NumTest != 0)
        {
            SX126xSetFs();
            OrderSend(ReceiveMode);
            SX126xSetFs();
            RadioRx(0);
            led_on();
            delay_1ms(50);
            led_off();
            NumTest = 0;

        }

        Modbus_Event_1();
    }
}
