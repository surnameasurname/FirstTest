#include "DataChange.h"

u8 ChangeDataString[11];

/*��������ת��������ת��λ�ַ���*/
//ע��ƽ̨λ������
u8* DataChangeNumberToString(u32 data)
{
	u8 i;
	i=0;
	if(data>=1000000000)//ʮ��λ
	{
		ChangeDataString[i++]=data/1000000000+'0';
	}
	if(data>=100000000)//��λ
	{
		ChangeDataString[i++]=(data/100000000)%10+'0';
	}
	if(data>=10000000)//ǧ��λ
	{
		ChangeDataString[i++]=(data/10000000)%10+'0';
	}	
	if(data>=1000000)//����λ
	{
		ChangeDataString[i++]=(data/1000000)%10+'0';
	}	
	if(data>=100000)//ʮ��λ
	{
		ChangeDataString[i++]=(data/100000)%10+'0';
	}
	if(data>=10000)//��λ
	{
		ChangeDataString[i++]=(data/10000)%10+'0';
	}	
	if(data>=1000)//ǧλ
	{
		ChangeDataString[i++]=(data/1000)%10+'0';
	}
	if(data>=100)//��λ
	{
		ChangeDataString[i++]=(data/100)%10+'0';
	}	
	if(data>=10)//ʮλ
	{
		ChangeDataString[i++]=(data/10)%10+'0';
	}	

	ChangeDataString[i++]=(data/1)%10+'0';//��λ
	ChangeDataString[i]='\0';
		
	return ChangeDataString;
}
