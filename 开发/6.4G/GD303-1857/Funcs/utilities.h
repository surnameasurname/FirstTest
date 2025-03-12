#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include "gd32f30x.h"


void memset1( uint8_t *dst, uint8_t value, uint16_t size );
void memcpy1( uint8_t *dst, const uint8_t *src, uint16_t size );
uint8_t strncmp1(uint8_t *str1,uint8_t const *str2,uint8_t size);

#endif // __UTILITIES_H__
