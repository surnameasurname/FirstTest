#include "sys.h"

#define DAC1CS 			PBout(4)
#define DAC2CS 			PBout(5)
#define DACSCK 			PBout(6)
#define DACDATA 		PBout(7)

void SPI_Init(void);
void SPI_SendByte(u8 data);
void Choose4(u8 cs);
void Choose5(u8 cs);
void SetDac4(u16 dac_value);
void SetDac5(u16 dac_value);


