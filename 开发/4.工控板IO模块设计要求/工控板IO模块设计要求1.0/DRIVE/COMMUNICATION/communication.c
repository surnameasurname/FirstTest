#include "communication.h"
#include "uart.h"
#include "encapsulation.h"

#define TOUCH_ORDER_SIZE  100											//ָ��洢�����С



#define N022		0x022					//����1����/��������/����
#define N023		0x023					//����1����/��ȫñ���
#define N024		0x024					//����1��ȫ
#define N025		0x025					//����1�豸�ֶ�������
#define N026		0x026					//����1�豸�ֶ������ر�
#define N027		0x027					//����1�豸�Զ�������
#define N028		0x028					//����1�豸�Զ������ر�



#define N042		0x042					//����2����/��������/����
#define N043		0x043					//����2����/��ȫñ���
#define N044		0x044					//����2��ȫ
#define N045		0x045					//����2�豸�ֶ�������
#define N046		0x046					//����2�豸�ֶ������ر�
#define N047		0x047					//����2�豸�Զ�������
#define N048		0x048					//����2�豸�Զ������ر�

#define N061		0x061					//��е��1 ��Ʒ������  	 ��λ
#define N063		0x063					//��е��1 ����Ʒ������  ��λ
#define N065		0x065					//��е��1 �쳣��������  ��λ

#define N100		0x100					//�����ƴ�
#define N101		0x101					//�����ƹر�



//����洢�������ݵ�����
u8 communication_array_data_u2[TOUCH_ORDER_SIZE];
//�����±�
u8 communication_index_u2=0;
//����ʹ�ܱ�־λ
u8 communication_receive_en_u2=0;

//������ɱ�־λ
u8 communication_receive_done_u2=0;

//ͨ�ų�ʼ��
void communication2_init(void)
{
	
	communication_index_u2=0;
	communication_receive_en_u2=0;
	communication_receive_done_u2=0;
}



//����2�жϺ���
void USART2_IRQHandler(void)
{
	u8 res;
	if(USART2->SR&(1<<5))//���յ�����
	{
		res=USART2->DR;
		if((communication_receive_done_u2==0)&&(res=='N'))	//���յ�����ʼλ
		{
			communication_receive_en_u2=1;										//ʹ��
		}
		if(communication_receive_en_u2==1)
		{
			communication_array_data_u2[communication_index_u2++]=res;
		}
		if(res=='*')		//���յ�����λ
		{
			communication_index_u2=0;
			communication_receive_en_u2=0;
			communication_receive_done_u2=1;
		}
		//ִ�д���
	}
}

//�õ�ָ������
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
	
	if(seekj==seeki)//ָ�����
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


//uart2����ָ���
void order_dispose_u2(void)
{
	if(communication_receive_done_u2==1)//���һ��ָ��������
	{
		u16 order=0;
		if(communication_array_data_u2[0]=='N')
		{
			order=((communication_array_data_u2[1]-'0')*256)+((communication_array_data_u2[2]-'0')*16)+(communication_array_data_u2[3]-'0');	 //����ָ�����				
		}
			
		switch(order)
		{
			
			case N022:			//����1����
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
			case N023:			//����1����
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
			case N024:			//����1��ȫ
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
			case N025:			//����1�ֶ�������   ��
						Device1_ManualOperation_Pause = 1;
						OpenWarn();
//						send_uart2_string("ID:N025*");
				break;
			case N026:			//����1�ֶ�������   �ر�
						Device1_ManualOperation_Pause = 0;
						CloseWarn();
//						send_uart2_string("ID:N026*");
				break;
			case N027:			//����1�Զ�������   ��
						Device1_Auto_Pause = 1;	
						OpenWarn();
//						send_uart2_string("ID:N027*");
				break;
			case N028:			//����1�Զ�������   �ر�
						Device1_Auto_Pause = 0;	
						CloseWarn();
//						send_uart2_string("ID:N028*");
				break;
			
			case N042:			//����2����
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
			case N043:			//����2����
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
			case N044:			//����2��ȫ
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
			case N045:			//����2�ֶ�������   ��
						Device2_ManualOperation_Pause = 1;
						OpenWarn();
//						send_uart2_string("ID:N045*");
				break;
			case N046:			//����2�ֶ�������   �ر�
						Device2_ManualOperation_Pause = 0;
						CloseWarn();
//						send_uart2_string("ID:N046*");
				break;
			case N047:			//����2�Զ�������   ��
						Device2_Auto_Pause = 1;
						OpenWarn();
//						send_uart2_string("ID:N047*");
				break;
			case N048:			//����2�Զ�������   �ر�
						Device2_Auto_Pause = 0;
						CloseWarn();
//						send_uart2_string("ID:N048*");
				break;
			
			
			case N061:			//��е��1��Ʒ�����鸴λ
				
//						send_uart2_string("ID:N061*");
				break;
			case N063:			//��е��1����Ʒ������ ��λ
						
//						send_uart2_string("ID:N063*");
				break;
			case N065:			//��е��1�쳣�������� ��λ
				
						send_uart2_string("ID:N065*");
				break;
			
			case N100:			//�����ƴ�
				OpenWarn();
//				send_uart2_string("ID:N100*");
				break;
			case N101:			//�����ƹر�
				CloseWarn();
//				send_uart2_string("ID:N101*");	
				break;
			
		 
			default:break;
			
		}
		communication_receive_done_u2=0;		//һ��ָ������
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






