#include "time.h"
#include "communication1.h"

u8 SendTime = 0;
//��ʱ��2�жϷ������
void TIM2_IRQHandler(void)
{

    if (TIM2->SR & 0X0001) //����ж� ,modbusʹ�ã�һ��ָ��������
    {
        if (ModbusRx.ModbusReceDoneNum != 0) //��Ϊ0��ʼ�ۻ�
        {
            ModbusRx.ModbusReceDoneNum++;
        }
//      if(ModbusRx.ModbusReceDoneNum > 100)
//      {
//          ModbusRx.ModbusReceDoneNum=10;

//      }


    }
    TIM2->SR &= ~(1 << 0); //����жϱ�־λ
}
//ͨ�ö�ʱ��2�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM2_Int_Init(u16 arr, u16 psc)
{
    RCC->APB1ENR |= 1 << 0;           //TIM2ʱ��ʹ��
    TIM2->ARR = arr;                  //�趨�������Զ���װֵ//�պ�1ms
    TIM2->PSC = psc;                  //Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��
    TIM2->DIER |= 1 << 0;         //��������ж�
    TIM2->CR1 &= ~(1 << 4);     //���ϼ���ģʽ
    TIM2->CR1 |= (1 << 0);      //������ʱ����
    TIM2->CR1 |= (1 << 2);      //ֻ�м��������/����Ų��������жϻ�DMA����
    MY_NVIC_Init(1, 2, TIM2_IRQn, 2); //��2
}

//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)
{
    if (TIM3->SR & 0X0001) //����ж�
    {
        SendTime++;
    }
    TIM3->SR &= ~(1 << 0); //����жϱ�־λ
}
//ͨ�ö�ʱ��3�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Int_Init(u16 arr, u16 psc)
{
    RCC->APB1ENR |= 1 << 1;           //TIM3ʱ��ʹ��
    TIM3->ARR = arr;                  //�趨�������Զ���װֵ//�պ�1ms
    TIM3->PSC = psc;                  //Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��
    TIM3->DIER |= 1 << 0;         //��������ж�
    TIM3->CR1 &= ~(1 << 0);     //��ֹ��ʱ��3
    MY_NVIC_Init(3, 2, TIM3_IRQn, 2); //��ռ3�������ȼ�2����2
}

//�źŶ�ʱ������
//0,��ֹ������������
void Time3En(u8 time_contorl)
{
    if (time_contorl == 0x00)
    {
        TIM3->CR1 &= ~(1 << 0);      //��ֹ��ʱ��3
    }
    else
    {
        TIM3->CR1 |= (1 << 0);      //�򿪶�ʱ��3
    }
}

