#include "Emm42_board.h"

/**
	*	@brief		����ʱ�ӳ�ʼ��
	*	@param		��
	*	@retval		��
	*/
void Emm42_clock_init(void)
{
	RCC_APB2PeriphClockCmd(Emm42_RCC_GPIOA, ENABLE);	//ʹ��GPIOA�˿�ʱ��
}

/**
	*	@brief		gpio���ų�ʼ��
	*	@param		��
	*	@retval		��
	*/
void Emm42_gpio_init(void)
{
/**************************************************************
	*	1. STM32��PA5��Emm42�ջ�������En���ţ�ȷ��Emm42_�ջ�������Ļ�ϵ�Enѡ��ѡ��Hold����L��Ĭ����Hold��
	*	2. STM32��PA6��Emm42�ջ�������Stp����
	* 3. STM32��PA7��Emm42�ջ�������Dir����
***************************************************************/
 GPIO_InitTypeDef  GPIO_InitStructure;
 GPIO_InitStructure.GPIO_Pin = Emm42_En_Pin | Emm42_Stp_Pin | Emm42_Dir_Pin;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(Emm42_GPIO, &GPIO_InitStructure);
 GPIO_ResetBits(Emm42_GPIO, Emm42_En_Pin | Emm42_Stp_Pin | Emm42_Dir_Pin);
}

/**
	*	@brief		���س�ʼ��
	*	@param		��
	*	@retval		��
	*/
void Emm42_board_init(void)
{
	Emm42_clock_init();	/* ��������ʱ�� */
	Emm42_gpio_init();	/* ��ʼ��GPIO */
}
