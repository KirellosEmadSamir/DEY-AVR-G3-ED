/*
 * SPI.h
 *
 * Created: 21/04/2022 10:25:33 ص
 *  Author: dell
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "STD.h"

void M_SpiInit(void);
u8   M_SpiTransive(u8);

#define MASTER     1
#define SLAVE      2

#endif /* SPI_H_ */