#include "usart0.h"
#include "delay.h"
#include "communication1.h"


//uart1下位机通信
ModbusSend_typedef ModbusTx;                    //Modbus发送
ModbusReceive_typedef ModbusRx;         //Modbus接收
uint8_t UpdateNum = 0;//串口1中断  判断功能码
uint8_t DataReceive[250];
uint8_t DataReceive6[20];

uint16_t ReceiveOrSend = 0;


uint8_t ReceiveBuff[10];
uint8_t DataNum = 0;
uint16_t ReceiveMode = 1;               //接收模式
uint16_t Address1 = 0;              //
uint16_t Address2 = 0;              //


//模式控制
#define RS485_TX_EN     PAout(8)    //485模式控制.0,接收;1,发送.

uint8_t ModbusEquipmentExist[8];//设备存在数组，0不存在，1存在


extern uint8_t Modbus2_Data[20];
extern uint16_t crc_data;
extern uint8_t receive_done;
extern uint16_t ADC_val1;
extern uint16_t ADC_val2;
extern uint8_t uart2_rcev_buff[100];


/// CRC 高位字节值表 ///
const uint8_t  auchCRCHi[] =
{
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
} ;
/// CRC低位字节值表///
const uint8_t  auchCRCLo[] =
{
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
    0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
    0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
    0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
    0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
    0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
    0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
    0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
    0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
    0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
    0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
    0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
    0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
    0x43, 0x83, 0x41, 0x81, 0x80, 0x40
} ;


//初始化modbus
void ModbusInit(void);
//Modbus发送指令
void ModbusSendOrder(void);


//通信初始化
void communication1_init(void)
{
    //uart1_init(72,9600);
    //uart2_init(36,9600);  //串口2初始化
    //uart2_init(72,19200); //串口2初始化

//  //为485通信添加
//  RCC->APB2ENR |=1<<2;//使能端口PORTA口时钟
//  GPIOA->CRH &=0xFFFFFFF0;
//  GPIOA->CRH |=0x00000003;//PORTA8推挽输出
//
//  TIM2_Int_Init(99,7199);//10毫秒

    ModbusInit();
}


//初始化modbus
void ModbusInit(void)
{
    uint16_t i;
    for (i = 0; i < MoubusReceArrLength; i++)
    {
        ModbusTx.Txbuf[i] = 0;
        ModbusRx.Rxbuf[i] = 0;
    }
    for (i = 0; i < 8; i++)
    {
        ModbusEquipmentExist[i] = 0;
    }

    ModbusTx.EquipmentNum = 0;
    ModbusTx.ModbusOrder = 0;
    ModbusTx.StartAddress = 0;
    ModbusTx.RegisterNum = 0;
    ModbusTx.Txlen = 0;
    ModbusTx.CrcData = 0;

    ModbusRx.EquipmentNum = 0;
    ModbusRx.ModbusOrder = 0;
    ModbusRx.StartAddress = 0;
    ModbusRx.RegisterNum = 0;
    ModbusRx.Rxlen = 0;
    ModbusRx.ModbusReceDoneNum = 0;
}

uint8_t ModbusReceiveOrderCheck(void)
{
    if (ModbusRx.Rxbuf[1] == 6)
    {
        return 0xFF;
    }
    return 0x00;
}
uint8_t ModbusReceiveOrderCheck3(void)
{
    if (ModbusRx.Rxbuf[1] == 3)
    {
        return 0xFF;
    }
    return 0x00;
}
uint8_t ModbusReceiveOrderCheck16(void)
{
    if (ModbusRx.Rxbuf[1] == 16)
    {
        return 0xFF;
    }
    return 0x00;
}



//Modbus发送指令
void ModbusSendOrder(void)
{
    {
        RS485_Send_Data(ModbusTx.Txbuf, ModbusTx.Txlen);    //发送数据
        ModbusRx.Rxlen = 0; //准备接收
        ModbusRx.ModbusReceDoneNum = 0;
    }
}


//485接收
void RS485_Read(void)
{
//  RS485_TX_EN=0;
    gpio_bit_reset(GPIOA, GPIO_PIN_8);

}
//485发送
void RS485_Send(void)
{
//  RS485_TX_EN=1;
    gpio_bit_set(GPIOA, GPIO_PIN_8);
}
//RS485发送len个字节.
//buf:发送区首地址
//len:发送的字节数(为了和本代码的接收匹配,这里建议不要超过64个字节)
void RS485_Send_Data(uint8_t *buf, uint8_t len)
{
    //uint8_t t;
    RS485_Send();
    while (len--)
    {
        while (RESET == usart_flag_get(USART0, USART_FLAG_TBE));
        usart_data_transmit(USART0, *(buf++));
    }
    while (RESET == usart_flag_get(USART0, USART_FLAG_TC));

    //fputc(len,*buf);
//  for(t=0;t<len;t++)      //循环发送数据
//  {
//      while((USART2->SR&0X40)==0);//等待发送结束
//      USART2->DR=buf[t];
//  }
//  while((USART2->SR&0X40)==0);//等待发送结束
//  RS485_TX_EN=0;              //设置为接收模式
    RS485_Read();
}


void USART0_IRQHandler(void)  //串口0中断服务程序
{
    if (usart_interrupt_flag_get(USART0, USART_INT_FLAG_RBNE) == SET)
    {
        usart_interrupt_flag_clear(USART0, USART_INT_FLAG_RBNE);
        //uint8_tUsartRxData[uint8_tUsartRxCnt] = usart_data_receive(USART0);
        DataReceive[ModbusRx.Rxlen] = usart_data_receive(USART0);
        ModbusRx.Rxlen++;
        //判断两条modbus之间时间
        ModbusRx.ModbusReceDoneNum = 1;

    }

}

//CRC校验码，高字节在前，低字节在后
uint16_t crc16(uint8_t *puchMsg, uint16_t usDataLen)
{
    uint8_t uchCRCHi = 0xFF ;                       /// 高CRC字节初始化 ///
    uint8_t uchCRCLo = 0xFF ;                       /// 低CRC 字节初始化 ///
    uint8_t uIndex ;                                            /// CRC循环中的索引 ///
    while (usDataLen--)                         /// 传输消息缓冲区 ///
    {
        uIndex = uchCRCHi ^ (*puchMsg++) ;          /// 计算CRC ///
        uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
        uchCRCLo = auchCRCLo[uIndex] ;
    }
    return (uchCRCHi << 8 | uchCRCLo) ;
}


//Modbus事件处理函数
void Modbus_Event_1(void)
{

    //判断是否接收Modbus信息
    if (ModbusRx.Rxlen == 0)
    {

        return;
    }
    //判断两条信息的间隔时间
    if (ModbusRx.ModbusReceDoneNum <= 2)
    {

        return ;
    }

    if (ModbusRx.ModbusReceDoneNum >= 3)
    {
        if (DataReceive[0] == ModbusBroadcastAddress)
        {

            switch (DataReceive[1])     //分析功能码
            {
            case 3:                     //读取寄存器的数据
                showData1_1();
                break;
            case 6:                 //写入单个寄存器数据
                ModbusFun6_1();
                break;

            default:
                break;
            }
        }
        ModbusRx.Rxlen = 0;
        ModbusRx.ModbusReceDoneNum = 0;
    }
}


// Modbus 6号功能码函数
// Modbus 主机写入寄存器值

void ModbusFun6_1(void)
{

    uint16_t Regadd;
    //uint16_t Temp;
    //uint16_t val;
    //得到要读取寄存器的首地址
    Regadd = DataReceive[2] << 8 | DataReceive[3];      //修改寄存器首地址

//  switch(Regadd){


    if (Regadd == 0)
    {
        Address1 = DataReceive[5];
    }
    else if (Regadd == 1)
    {
        Address2 = DataReceive[5];
    }
    else if (Regadd == 2)
    {
        ReceiveMode = DataReceive[5];
    }
    WriteAdd(Address1, Address2, ReceiveMode);
//      case 0:
//          Address1 = DataReceive[5];
//
//          WriteAdd(Address1);         //修改Address1
//          break;
//      case 1:
//          Address2 = DataReceive[5];      //修改Address2
//          Temp = Address2;
//          WriteAddress2(Temp);
//          break;
//      case 2:
//          ReceiveMode = DataReceive[5];           //修改接收模式
//          Temp = ReceiveMode;
//          WriteReceiveMode(Temp);
//          break;
//      default:
//          break;

//  }

}


//输出数据
void showData1_1(void)
{
    uint16_t crc;
    ModbusTx.Txbuf[0] = ModbusBroadcastAddress;
    ModbusTx.Txbuf[1] = 0x03;

    ModbusTx.Txbuf[2] = 0x06;


    ModbusTx.Txbuf[3] = 0;
    ModbusTx.Txbuf[4] = Address1;

    ModbusTx.Txbuf[5] = 0;
    ModbusTx.Txbuf[6] = Address2;

    ModbusTx.Txbuf[7] = 0;
    ModbusTx.Txbuf[8] = ReceiveMode;
//
//  ModbusTx.Txbuf[5]=ReceiveOrSend>>8;
//  ModbusTx.Txbuf[6]=ReceiveOrSend;

//  ModbusTx.Txbuf[7]=LocalGroupNumber>>8;
//  ModbusTx.Txbuf[8]=LocalGroupNumber;

    crc = crc16(ModbusTx.Txbuf, 9);
    ModbusTx.Txbuf[9] = crc >> 8;
    ModbusTx.Txbuf[10] = crc;
    ModbusTx.Txlen = 11;
    ModbusSendOrder();
}


void Modbus2_Send(void)
{
    Modbus2_Data[0] = 1;
    Modbus2_Data[1] = 3;
    Modbus2_Data[2] = 4;
    Modbus2_Data[3] = ADC_val1 >> 8;
    Modbus2_Data[4] = ADC_val1;
    Modbus2_Data[5] = ADC_val2 >> 8;
    Modbus2_Data[6] = ADC_val2;
    crc_data = crc16(Modbus2_Data, 7);
    Modbus2_Data[7] = crc_data >> 8;
    Modbus2_Data[8] = crc_data;
    uart2_send_data(Modbus2_Data, 9);

    receive_done = 0;

}

//void Modbus2_Receive(void)
//{
//    Modbus2_Data[0] = uart2_rcev_buff[0];
//    Modbus2_Data[1] = uart2_rcev_buff[1];
//    Modbus2_Data[2] = uart2_rcev_buff[2];
//    Modbus2_Data[3] = uart2_rcev_buff[3];
//    Modbus2_Data[4] = uart2_rcev_buff[4];
//    Modbus2_Data[5] = uart2_rcev_buff[5];
//    Modbus2_Data[6] = uart2_rcev_buff[6];
//    crc_data = crc16(Modbus2_Data, 7);
//    Modbus2_Data[7] = crc_data >> 8;
//    Modbus2_Data[8] = crc_data;
//    //uart2_send_data(Modbus2_Data, 9);
//    receive_done = 0;

//}
