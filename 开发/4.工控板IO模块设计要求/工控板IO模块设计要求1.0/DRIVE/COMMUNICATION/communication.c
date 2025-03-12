#include "communication.h"
#include "uart.h"
#include "encapsulation.h"

#define TOUCH_ORDER_SIZE  100											//指令存储数组大小



#define N022		0x022					//区域1报警/区域入侵/拌线
#define N023		0x023					//区域1报警/安全帽检测
#define N024		0x024					//区域1安全
#define N025		0x025					//区域1设备手动报警打开
#define N026		0x026					//区域1设备手动报警关闭
#define N027		0x027					//区域1设备自动报警打开
#define N028		0x028					//区域1设备自动报警关闭



#define N042		0x042					//区域2报警/区域入侵/拌线
#define N043		0x043					//区域2报警/安全帽检测
#define N044		0x044					//区域2安全
#define N045		0x045					//区域2设备手动报警打开
#define N046		0x046					//区域2设备手动报警关闭
#define N047		0x047					//区域2设备自动报警打开
#define N048		0x048					//区域2设备自动报警关闭

#define N061		0x061					//机械手1 良品生产数  	 复位
#define N063		0x063					//机械手1 不良品生产数  复位
#define N065		0x065					//机械手1 异常发生回数  复位

#define N100		0x100					//报警灯打开
#define N101		0x101					//报警灯关闭



//定义存储接收数据的数据
u8 communication_array_data_u2[TOUCH_ORDER_SIZE];
//数组下标
u8 communication_index_u2=0;
//接收使能标志位
u8 communication_receive_en_u2=0;

//接收完成标志位
u8 communication_receive_done_u2=0;

//通信初始化
void communication2_init(void)
{
	
	communication_index_u2=0;
	communication_receive_en_u2=0;
	communication_receive_done_u2=0;
}



//串口2中断函数
void USART2_IRQHandler(void)
{
	u8 res;
	if(USART2->SR&(1<<5))//接收到数据
	{
		res=USART2->DR;
		if((communication_receive_done_u2==0)&&(res=='N'))	//接收到了起始位
		{
			communication_receive_en_u2=1;										//使能
		}
		if(communication_receive_en_u2==1)
		{
			communication_array_data_u2[communication_index_u2++]=res;
		}
		if(res=='*')		//接收到结束位
		{
			communication_index_u2=0;
			communication_receive_en_u2=0;
			communication_receive_done_u2=1;
		}
		//执行代码
	}
}

//得到指令数据
u16 GetCommunicationData_u1(void)
{
	u8 seeki=0,seekj=0;
	u16 CommunicationData=0;
	u8 i=0;
	for(seeki=1;seeki<TOUCH_ORDER_SIZE;seeki++)
	{
		if(communication_array_data_u2[seeki]==':')
		{
			seekj=seeki;
		}
		if(communication_array_data_u2[seeki]=='*')
		{
			break;
		}
	}
	
	if(seekj==seeki)//指令错误
	{
		return 0;
	}
	else
	{
		i=seeki-seekj;
	}

	switch(i)
	{
		case 2:CommunicationData=communication_array_data_u2[seekj+1]-'0';
				break;
		case 3:CommunicationData=(communication_array_data_u2[seekj+1]-'0')*10+(communication_array_data_u2[seekj+2]-'0');
				break;
		case 4:CommunicationData=(communication_array_data_u2[seekj+1]-'0')*100+(communication_array_data_u2[seekj+2]-'0')*10+(communication_array_data_u2[seekj+3]-'0');
				break;
		case 5:CommunicationData=(communication_array_data_u2[seekj+1]-'0')*1000+(communication_array_data_u2[seekj+2]-'0')*100+(communication_array_data_u2[seekj+3]-'0')*10+(communication_array_data_u2[seekj+4]-'0');
				break;
		case 6:CommunicationData=(communication_array_data_u2[seekj+1]-'0')*10000+(communication_array_data_u2[seekj+2]-'0')*1000+(communication_array_data_u2[seekj+3]-'0')*100+(communication_array_data_u2[seekj+4]-'0')*10+(communication_array_data_u2[seekj+5]-'0');
				break;
			default:break;
	}
	return CommunicationData;
}


//uart2接收指令处理
void order_dispose_u2(void)
{
	if(communication_receive_done_u2==1)//如果一条指令接收完成
	{
		u16 order=0;
		if(communication_array_data_u2[0]=='N')
		{
			order=((communication_array_data_u2[1]-'0')*256)+((communication_array_data_u2[2]-'0')*16)+(communication_array_data_u2[3]-'0');	 //更新指令代号				
		}
			
		switch(order)
		{
			
			case N022:			//区域1报警
						if(Device1_Status_ManualOperation == 0)
						{
							Device1_ManualOperation_Pause = 1;
						}
						if(Device1_Status_Auto == 0)
						{
							Device1_Auto_Pause = 1;
						}
						OpenWarn();
//						send_uart2_string("ID:N022*");
				break;
			case N023:			//区域1报警
						if(Device1_Status_ManualOperation == 0)
						{
							Device1_ManualOperation_Pause = 1;
						}
						if(Device1_Status_Auto == 0)
						{
							Device1_Auto_Pause = 1;
						}				
						OpenWarn();
//						send_uart2_string("ID:N023*");
				break;
			case N024:			//区域1安全
						if(Device1_Status_ManualOperation == 0)
						{
							Device1_ManualOperation_Pause = 0;
						}
						if(Device1_Status_Auto == 0)
						{
							Device1_Auto_Pause = 0;
						}						
						CloseWarn();
//						send_uart2_string("ID:N024*");
				break;
			case N025:			//区域1手动报警声   打开
						Device1_ManualOperation_Pause = 1;
						OpenWarn();
//						send_uart2_string("ID:N025*");
				break;
			case N026:			//区域1手动报警声   关闭
						Device1_ManualOperation_Pause = 0;
						CloseWarn();
//						send_uart2_string("ID:N026*");
				break;
			case N027:			//区域1自动报警声   打开
						Device1_Auto_Pause = 1;	
						OpenWarn();
//						send_uart2_string("ID:N027*");
				break;
			case N028:			//区域1自动报警声   关闭
						Device1_Auto_Pause = 0;	
						CloseWarn();
//						send_uart2_string("ID:N028*");
				break;
			
			case N042:			//区域2报警
						if(Device2_Status_ManualOperation == 0)
						{
							Device2_ManualOperation_Pause = 1;
						}
						if(Device2_Status_Auto == 0)
						{
							Device2_Auto_Pause = 1;
						}					
						OpenWarn();
//						send_uart2_string("ID:N042*");
				break;
			case N043:			//区域2报警
						if(Device2_Status_ManualOperation == 0)
						{
							Device2_ManualOperation_Pause = 1;
						}
						if(Device2_Status_Auto == 0)
						{
							Device2_Auto_Pause = 1;
						}						
						OpenWarn();
//						send_uart2_string("ID:N043*");
				break;
			case N044:			//区域2安全
						if(Device2_Status_ManualOperation == 0)
						{
							Device2_ManualOperation_Pause = 0;
						}
						if(Device2_Status_Auto == 0)
						{
							Device2_Auto_Pause = 0;
						}					
						CloseWarn();
//						send_uart2_string("ID:N044*");
				break;
			case N045:			//区域2手动报警声   打开
						Device2_ManualOperation_Pause = 1;
						OpenWarn();
//						send_uart2_string("ID:N045*");
				break;
			case N046:			//区域2手动报警声   关闭
						Device2_ManualOperation_Pause = 0;
						CloseWarn();
//						send_uart2_string("ID:N046*");
				break;
			case N047:			//区域2自动报警声   打开
						Device2_Auto_Pause = 1;
						OpenWarn();
//						send_uart2_string("ID:N047*");
				break;
			case N048:			//区域2自动报警声   关闭
						Device2_Auto_Pause = 0;
						CloseWarn();
//						send_uart2_string("ID:N048*");
				break;
			
			
			case N061:			//机械手1良品生产书复位
				
//						send_uart2_string("ID:N061*");
				break;
			case N063:			//机械手1不良品生产数 复位
						
//						send_uart2_string("ID:N063*");
				break;
			case N065:			//机械手1异常发生回数 复位
				
						send_uart2_string("ID:N065*");
				break;
			
			case N100:			//报警灯打开
				OpenWarn();
//				send_uart2_string("ID:N100*");
				break;
			case N101:			//报警灯关闭
				CloseWarn();
//				send_uart2_string("ID:N101*");	
				break;
			
		 
			default:break;
			
		}
		communication_receive_done_u2=0;		//一条指令处理完成
	}
}



void OpenWarn(void)
{
	LED_Red = 1;
	LED_Yellow = 1;
	LED_Green = 1;
}

void CloseWarn(void)
{
	LED_Red = 0;
	LED_Yellow = 0;
	LED_Green = 0;
}






