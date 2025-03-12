#include "DataChange.h"

u8 ChangeDataString[11];

/*数据类型转换，数字转换位字符串*/
//注意平台位数极限
u8* DataChangeNumberToString(u32 data)
{
	u8 i;
	i=0;
	if(data>=1000000000)//十亿位
	{
		ChangeDataString[i++]=data/1000000000+'0';
	}
	if(data>=100000000)//亿位
	{
		ChangeDataString[i++]=(data/100000000)%10+'0';
	}
	if(data>=10000000)//千万位
	{
		ChangeDataString[i++]=(data/10000000)%10+'0';
	}	
	if(data>=1000000)//百万位
	{
		ChangeDataString[i++]=(data/1000000)%10+'0';
	}	
	if(data>=100000)//十万位
	{
		ChangeDataString[i++]=(data/100000)%10+'0';
	}
	if(data>=10000)//万位
	{
		ChangeDataString[i++]=(data/10000)%10+'0';
	}	
	if(data>=1000)//千位
	{
		ChangeDataString[i++]=(data/1000)%10+'0';
	}
	if(data>=100)//百位
	{
		ChangeDataString[i++]=(data/100)%10+'0';
	}	
	if(data>=10)//十位
	{
		ChangeDataString[i++]=(data/10)%10+'0';
	}	

	ChangeDataString[i++]=(data/1)%10+'0';//个位
	ChangeDataString[i]='\0';
		
	return ChangeDataString;
}
