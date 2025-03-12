#include "utilities.h"


void memset1( uint8_t *dst, uint8_t value, uint16_t size )
{
    while( size-- )
    {
        *dst++ = value;
    }
}

void memcpy1( uint8_t *dst, const uint8_t *src, uint16_t size )
{
    while( size-- )
    {
        *dst++ = *src++;
    }
}

uint8_t strncmp1(uint8_t *str1,uint8_t const *str2,uint8_t size)
{
	uint8_t sta = 0;
	
	while(size--)
	{
		if( *str1++ != *str2++ )
		{
			return sta;
		}
	}
	sta = 1;
	return sta;
}
