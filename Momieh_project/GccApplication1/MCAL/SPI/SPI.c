/*
 * SPI.c
 *
 * Created: 21/04/2022 10:25:26 ص
 *  Author: dell
 */ 

#include "STD.h"
#include "SPI_CFG.h"
#include "DIO.h"
#include "SPI.h"
#include "BIT_MATH.h"
#include "REG.h"
#define F_CPU 16000000UL
#include <util/delay.h>
// master
void M_SpiInit(void)
{
	#if   SPI_MODE     ==     MASTER
	SET_BIT(SPCR,4);
	M_PinMode(MOSI,OUTPUT);
	M_PinMode(MISO,INPUT);
	M_PinMode(SS,OUTPUT);
	M_PinMode(SCK,OUTPUT);
	// to select devision factor --> 128 , SPI freq. -> 125 KHz
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	// to setup at leading edge
	SET_BIT(SPCR,2);
	#elif SPI_MODE     ==     SLAVE
	CLR_BIT(SPCR,4);

	M_PinMode(MOSI,INPUT);
	M_PinMode(MISO,OUTPUT);
	M_PinMode(SS,INPUT);
	M_PinMode(SCK,INPUT);
	SET_BIT(SPCR,2);
	#endif
	// to select send from LSB
	SET_BIT(SPCR,5);
	// to enable SPI circuit
	SET_BIT(SPCR,6);
}
u8   M_SpiTransive(u8 u8_local_data)
{
	GET_BIT(SPSR,7);
	SPDR = u8_local_data;
	while(GET_BIT(SPSR,7) == 0);
	
	return SPDR;
}