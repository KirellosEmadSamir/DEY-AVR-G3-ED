/*
 * ULTRASONIC.c
 *
 * Created: 27/04/2022 10:49:24 م
 *  Author: hassa
 */ 
#include "ULTRASONIC_CFG.h"
#include "ULTRASONIC.h"
#include "DIO.h"
#include "STD.h"
#include "BIT_MATH.h"
#include "LCD.h"
#include "REG.h"
#include "LED.h"
#define F_CPU 16000000UL
#include <util/delay.h>

static u16 u16_global_RissingValue = 0;
static u16 u16_global_FallingValue = 0;

void H_UltraInit(void)
{
	//TCCR1A = 0;
	M_PinMode(Trigger,OUTPUT);
	M_PinMode(Echo,INPUT);
	SET_BIT(TIFR,5);     /* Clear ICF flag */
	
}
void H_UltraTrigger(void)
{
	M_PinWrite(Trigger,HIGH);
	_delay_ms(50);
	M_PinWrite(Trigger,LOW);
	
}

void H_UltraUltraRissingEdge(void)
{
	// Rising edge, no prescaler , noise canceler
	SET_BIT(TCCR1B,7);
	SET_BIT(TCCR1B,6);
	SET_BIT(TCCR1B,0);
	
	while ((GET_BIT(TIFR,5)) == 0);
	u16_global_RissingValue = ICR1;  		/* Take value of capture register */
	SET_BIT(TIFR,5);     /* Clear ICF flag */
	
	
}
void H_UltraUltraFallingEdge(void)
{
	// Rising edge, no prescaler , noise canceler
	SET_BIT(TCCR1B,7);
	CLR_BIT(TCCR1B,6);
	SET_BIT(TCCR1B,0);
	while ((GET_BIT(TIFR,5)) == 0);
	u16_global_FallingValue = ICR1;  		/* Take value of capture register */
	SET_BIT(TIFR,5);     /* Clear ICF flag */
	TCNT1=0;        // try to remove ****************
	TCCR1B= 0;  		/* Stop the timer */
	
}




u32  H_UltraDistance(void)
{
	u32 u32_local_TimeOn = u16_global_FallingValue - u16_global_RissingValue;
	u32 u32_local_Distance = 0;
	u32_local_Distance = ((u32_local_TimeOn * 34600) / (F_CPU*2)); //cpu*2
	
	H_LcdClear();
	H_LcdWriteString("distance=");
	H_LcdWriteNumber(u32_local_Distance);
	//H_LcdWriteNumber(u32_local_Distance);
	H_LcdWriteString("cm");
	
	/*if (u32_local_Distance>=80)
	{
		
		H_LcdClear();
		H_LcdWriteString("no object");
		_delay_ms(500);
	}
	else
	{
		H_LcdClear();
		H_LcdWriteString("distance=");
		H_LcdWriteNumber(u32_local_Distance);
		//H_LcdWriteNumber(u32_local_Distance);
		H_LcdWriteString("cm");
		_delay_ms(500);
	}*/
}

void H_UltraStop(void)
{
	
}