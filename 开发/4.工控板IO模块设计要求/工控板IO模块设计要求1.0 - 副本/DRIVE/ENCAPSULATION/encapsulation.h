#include "sys.h"
#include "uart.h"
#include "communication.h"


extern u8 ChangeLog1;
extern u8 ChangeLog2;
extern u8 first1;
extern u8 first2;



#define Work_LED    										PAout(4)

#define Device2_Status_Auto 						PAin(8)
#define Device2_ManualOperation_Pause  	PAout(9)
#define Device2_Auto_Pause  						PAout(10)
#define Device2_Status_ManualOperation  PCin(9)

#define LED_Red    											PBout(12)
#define LED_Yellow    									PBout(13)
#define LED_Green    										PBout(14)

#define Device1_Status_ManualOperation 	PBin(15)
#define Device1_Status_Auto						 	PCin(6)
#define Device1_Auto_Pause  						PCout(7)
#define Device1_ManualOperation_Pause  	PCout(8)

void Receive(void);
void Send(void);

void Sys_Init(void);


