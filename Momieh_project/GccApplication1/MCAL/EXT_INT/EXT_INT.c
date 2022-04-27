/*
 * EXT_INT.c
 *
 * Created: 11/04/2022 10:05:29 ص
 *  Author: dell
 */ 
#include "EXT_INT_CFG.h"
#include "EXT_INT.h"
#include "LED.h"
#include "BIT_MATH.h"
#include "REG.h"
#include <avr/interrupt.h>

void (*call_back)(void);

void M_ExtInt0Init(void)
{
	#if   SENSE_CONTROL   ==   FAILLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif SENSE_CONTROL   ==   RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif SENSE_CONTROL   ==   LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#elif SENSE_CONTROL   ==   ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#endif
	// to enable global int
	SET_BIT(SREG,7);
	// to enable extint0 int
	SET_BIT(GICR,6);
}
void M_EXT_INT_SetCallBack(void(*ptr)(void))
{
	call_back = ptr;
}
ISR(INT0_vect)
{
	call_back(); 
}