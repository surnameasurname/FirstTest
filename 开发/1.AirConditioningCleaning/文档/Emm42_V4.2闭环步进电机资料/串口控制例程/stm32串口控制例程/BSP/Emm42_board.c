#include "Emm42_board.h"

/**
	* @brief   ����NVIC������
	* @param   ��
	* @retval  ��
	*/
void Emm42_nvic_init(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);						///< 4bit��ռ���ȼ�λ

/**********************************************************
***	����USART1����ռ���ȼ�Ϊ0
**********************************************************/
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;				///< ��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	///< ��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_Init(&NVIC_InitStructure);
}


/**
	*	@brief		����ʱ�ӳ�ʼ��
	*	@param		��
	*	@retval		��
	*/
void Emm42_clock_init(void)
{
/**********************************************************
***	����GPIOA��AFIO����ʱ��
**********************************************************/
	RCC_APB2PeriphClockCmd(Emm42_RCC_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

/**********************************************************
***	����USART����ʱ��
**********************************************************/
	RCC_APB2PeriphClockCmd(Emm42_RCC_UART, ENABLE);

/**********************************************************
***	����JTAG
**********************************************************/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
}

/**
	* @brief   ��ʼ��USART
	* @param   ��
	* @retval  ��
	*/
void Emm42_usart_init(void)
{
/**********************************************************
***	��ʼ��USART����
**********************************************************/
	/* PA9 - USART1_TX */
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = Emm42_TX_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;				/* ����������� */
	GPIO_Init(Emm42_UART_PORT, &GPIO_InitStructure);
	/* PA10 - USART1_RX */
	GPIO_InitStructure.GPIO_Pin = Emm42_RX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	/* �������� */
	GPIO_Init(Emm42_UART_PORT, &GPIO_InitStructure);

/**********************************************************
***	USART��ʼ��
**********************************************************/
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 38400;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(Emm42_UART, &USART_InitStructure);

/**********************************************************
***	ʹ��USART�ж�
**********************************************************/	
	USART_ITConfig(Emm42_UART, USART_IT_RXNE, ENABLE);
	USART_ITConfig(Emm42_UART, USART_IT_IDLE, ENABLE);

/**********************************************************
***	ʹ��USART
**********************************************************/
	USART_Cmd(Emm42_UART, ENABLE);
}

/**
	*	@brief		���س�ʼ��
	*	@param		��
	*	@retval		��
	*/
void Emm42_board_init(void)
{
	Emm42_nvic_init();	/* ��ʼ��NVIC */
	Emm42_clock_init();	/* ��������ʱ�� */
	Emm42_usart_init();	/* ��ʼ��UART */
}
