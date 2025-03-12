#include "equipment.h"
u16 ReceiveOrSend = 10;                  //接收还是发送   接收为0，发送为1，2透明传输
u16 Mode = 0;                                   //Lora工作模式 1 发送通道1    2  发送通道2  3 发送两个通道
u16 LocalGroupNumber = 0;               //本地组号0-254
u16 LocalAddress = 0;                       //本地地址0-254
u16 TargetGroupNumber = 0;          //目标组号 0-254
u16 DestinationAddress = 0;         //目标地址

u16 PathGroupANumber = 0;               //路径A组号
u16 PathAAddress = 0;                       //路径A地址
u16 PathGroupBNumber = 0;               //路径B组号
u16 PathBAddress = 0;                       //路径B地址
u16 Channel = 0;                                //信道          1-80
u16 ArmChannel = 0;                         //目标信道
u16 TempChannel = 0;                        //临时信道

u16 ADC_1 = 0;              //SIGNAL1
u16 ADC_2 = 0;              //SIGNAL2

u16 DAC_1 = 0;
u16 DAC_2 = 0;
u16 TempDac_1 = 0;
u16 TempDac_2 = 0;
u8 buff[ 10 ] = { 0 };

u8 communication_done = 0;



u16 Add1;
u16 Add2;
u16 Add3;
u16 Add4;
u16 Add5;
u16 Add6;


