/*
 * UART.h
 *
 * Created: 20/04/2022 10:46:48 ص
 *  Author: dell
 */ 


#ifndef UART_H_
#define UART_H_

#include "STD.h"

void M_UartInit(void);
void M_UartSend(u8);
u8   M_UartRec(void);

#define OFF       0
#define ODD       1
#define EVEN      2

#endif /* UART_H_ */