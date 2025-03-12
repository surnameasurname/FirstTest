#include "Emm42_usart.h"

__IO uint8_t rxBuffer[20] = {0};
__IO uint16_t rxReceiveCount = 0;
__IO bool rxFrameFlag = false;	//��ʾһ֡���ݽ������

/**
	* @brief   Emm42_UART�жϺ���
	* @param   ��
	* @retval  ��
	*/
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(Emm42_UART, USART_IT_RXNE) != RESET)
	{
		if(rxReceiveCount < 20)
		{
			rxBuffer[rxReceiveCount] = (uint8_t)Emm42_UART->DR;

			++rxReceiveCount;
		}
		else
		{
			rxReceiveCount = 0;
		}

		USART_ClearITPendingBit(Emm42_UART, USART_IT_RXNE);
	}
	else if(USART_GetITStatus(Emm42_UART, USART_IT_IDLE) != RESET)
	{
/**********************************************************
***	�ȶ�SR�ٶ�DR�����IDLE�ж�
**********************************************************/
		Emm42_UART->SR; Emm42_UART->DR;

/**********************************************************
***	�ͷŻ�����
**********************************************************/
		rxFrameFlag = true;
	}
}

/**
	* @brief   Emm42_UART���ͺ���
	* @param   ��
	* @retval  ��
	*/
void usartSend(uint16_t Data)
{
	uint16_t t0 = 0;
	
	Emm42_UART->DR = (Data & (uint16_t)0x01FF);

	while( !(Emm42_UART->SR & USART_FLAG_TXE) )
	{
		++t0; if(t0 > 6000)	{	return;}
	}
}
