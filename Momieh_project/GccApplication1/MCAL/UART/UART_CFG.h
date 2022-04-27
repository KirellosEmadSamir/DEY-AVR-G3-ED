/*
 * UART_CFG.h
 *
 * Created: 20/04/2022 10:47:01 ص
 *  Author: dell
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

// CHARACTER_SIZE options --> [ 5 , 6 , 7 , 8 , 9 ]
#define CHARACTER_SIZE       8
// PARITY_CHECK options --> [ EVEN , ODD , OFF ]
#define PARITY_CHECK        EVEN
// STOP_BITS options --> [ 1 , 2]
#define STOP_BITS            1
// BAUD_RATE options --> [ 9600 , 115200 , 38400 ]
#define BAUD_RATE           9600

#endif /* UART_CFG_H_ */