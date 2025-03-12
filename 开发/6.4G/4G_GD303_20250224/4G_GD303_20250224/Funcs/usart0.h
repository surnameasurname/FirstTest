#include "gd32f30x.h"
#include <stdio.h>
#include "string.h"

void usart0_config(uint32_t u32uaud_mode);
void usart2_config(uint32_t u32uaud_mode);
void uart2_send_data(uint8_t *data, int len);
void EN485(void);
void Dis485(void);


