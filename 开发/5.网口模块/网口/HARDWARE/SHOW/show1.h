#ifndef _show1_h_
#define _show1_h_
#include "sys.h"
#define LED	PBout(9) //PB9

#define PB3	PBin(3) //PB3
#define PB4	PBin(4) //PB4
#define PB5	PBin(5) //PB5
#define PB6	PBin(6) //PB6
#define PB7	PBin(7) //PB7

void Starinit(void);
void WorkJudge(void);
void PortJudge(void);
#endif

