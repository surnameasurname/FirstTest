#include "delay.h"


#define Delay_1us()    {\
    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();\
    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();\
    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();\
    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();\
    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();\
    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();\
    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();\
    __nop();__nop();\
}

//us—” ±
void Delay_nus(uint64_t time)
{
    while(time--)
    {
        Delay_1us();
    }
}

//ms??
void Delay_nms(uint64_t time)
{
    time *= 1000;
    while(time--)
    {
        Delay_1us();
    }    
}
