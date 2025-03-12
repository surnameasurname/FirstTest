#include "sys.h"
#include "uart.h"
#include "delay.h"
#include "adc.h"
#include "stmflash.h"
#include "time.h"
#include "communication1.h"
#include "equipment.h"
#include "radio.h"

uint8_t g_RxBuffer[ 10 ] = { 0 };
uint8_t g_RxLen = 0;
uint8_t irqRegs = 0;
uint8_t Send = 0;
uint8_t Test[ 10 ] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };

int main(void)
{
    u8 size = 10;

    Stm32_Clock_Init(9); //系统时钟设置
    delay_init(72); //延时初始化
    AdcInit();
    communication1_init();
    TIM3_Int_Init(9999, 7199); //1秒
    Time3En(1);
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

    ReadAllData();          //Lora指令：   目的地址  mode  adc1 adc2


    while (1)
    {

        irqRegs = RadioGetIrqStatus();
        if ((irqRegs & IRQ_RX_DONE) == IRQ_RX_DONE)
        {
            RadioClearIrqStatus(IRQ_RADIO_ALL);
            RadioRx(0);                         //变为接收状态
            RadioGetBuffer(g_RxBuffer, &g_RxLen, 10);
            if (g_RxLen)
            {
                if (g_RxBuffer[0] == ReceiveOrSend)
                {
                    Send = 1;
                    LED = 1;
                    delay_ms(50);
                    LED = 0;
                    delay_ms(300);
                    LED = 1;
                    delay_ms(50);
                    LED = 0;
                }

            }
        }


        if (SendTime != 0)
        {
            SendTime = 0;

            ADC_1 = GetAdcAverage(ADC_CH2, 500);
            ADC_2 = GetAdcAverage(ADC_CH1, 500);
            buff[1] = ReceiveOrSend;
            buff[2] = ADC_1 >> 8;
            buff[3] = ADC_1;
            buff[4] = ADC_2 >> 8;
            buff[5] = ADC_2;

            //RS485_Send_Data(Test, 10);    //发送数据
            //RadioSend(buff, size, 0);
//            LED = ~LED;
            //Lora_SendAdc();
        }
        Modbus_Event_1();
//          //DAC_Receive();
        if (Send == 1)
        {
            SX126xSetFs();
            RadioSend(buff, size, 0);
            SX126xSetFs();
            RadioRx(0);
            LED = 1;
            delay_ms(50);
            LED = 0;
            Send = 0;
        }

    }


}
