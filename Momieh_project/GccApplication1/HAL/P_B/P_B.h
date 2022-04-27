/*
 * P_B.h
 *
 * Created: 04/04/2022 10:42:34 ص
 *  Author: dell
 */ 


#ifndef P_B_H_
#define P_B_H_

#include "STD.h"

void H_PushButtonInit(u8);
u8   H_PushButtonRead(u8);

#define PB_1        1
#define PB_2        2
#define PB_3        3
#define PB_4        4

#define    PRESSED         0
#define    RELEASED        1

#endif /* P_B_H_ */