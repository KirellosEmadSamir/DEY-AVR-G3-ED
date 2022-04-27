/*
 * SERVO.c
 *
 * Created: 19/04/2022 01:58:05 م
 *  Author: dell
 */ 
#include "TIMER_1.h"
#include "STD.h"

void H_ServoInit(void)
{
	M_Pwm1Init();
}
void H_ServoSetAngle(u16 u16_local_angle)
{
	f64 f64_local_DutyCycle = ( ( ( 5 * u16_local_angle ) / 180 ) + 5 );
	M_Pwm1SetDutyCycle(f64_local_DutyCycle); 
}
void H_ServoStart(void)
{
	M_Pwm1Start();
}
void H_ServoStop(void)
{
	M_Pwm1Stop();
}