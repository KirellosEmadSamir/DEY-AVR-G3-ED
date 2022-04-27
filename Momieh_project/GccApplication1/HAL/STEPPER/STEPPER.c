/*
 * STEPPER.c
 *
 * Created: 19/04/2022 09:42:51 ص
 *  Author: dell
 */ 
#include "STEPPER_CFG.h"
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void H_StepperInit(void)
{
	M_PinMode(IN_1,OUTPUT);
	M_PinMode(IN_2,OUTPUT);
	M_PinMode(IN_3,OUTPUT);
	M_PinMode(IN_4,OUTPUT);
}
void H_StepperRotate(u32 u32_local_angle)
{
	u32 u32_local_i = 0;
	for(u32_local_i = 0 ; u32_local_i < u32_local_angle ; u32_local_i++)
	{
		M_PinWrite(IN_1,HIGH);
		M_PinWrite(IN_2,LOW);
		M_PinWrite(IN_3,LOW);
		M_PinWrite(IN_4,LOW);
		_delay_ms(10);
		M_PinWrite(IN_1,LOW);
		M_PinWrite(IN_2,HIGH);
		M_PinWrite(IN_3,LOW);
		M_PinWrite(IN_4,LOW);
		_delay_ms(10);
		M_PinWrite(IN_1,LOW);
		M_PinWrite(IN_2,LOW);
		M_PinWrite(IN_3,HIGH);
		M_PinWrite(IN_4,LOW);
		_delay_ms(10);
		M_PinWrite(IN_1,LOW);
		M_PinWrite(IN_2,LOW);
		M_PinWrite(IN_3,LOW);
		M_PinWrite(IN_4,HIGH);
		_delay_ms(10);	
		M_PinWrite(IN_4,LOW);
	}
}