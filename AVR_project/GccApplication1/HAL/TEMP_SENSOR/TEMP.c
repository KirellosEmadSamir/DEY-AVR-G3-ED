/*
 * TEMP.c
 *
 * Created: 12/04/2022 01:41:12 م
 *  Author: dell
 */ 
#include "STD.h"
#include "ADC.h"

void H_TempSensorInit(void)
{
	M_AdcInit();
}
u16  H_TempSensorRead(void)
{
	u16 adc_reading = M_AdcRead();
	u16 temp        = ((u32)adc_reading * 500) / 1023;
	return temp;
}