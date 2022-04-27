/*
 * TIMER_1.c
 *
 * Created: 17/04/2022 10:09:52 ص
 *  Author: dell
 */ 

#include "STD.h"
#include "REG.h"
#include "BIT_MATH.h"

void M_Pwm1Init(void)
{
	// to enable output circuit
	SET_BIT(DDRD,5);
	// to select mode no. 14 --> fast pwm with ICR top
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	// to select non inverted mode
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	ICR1 = 1250;
}
void M_Pwm1SetFrequancy(u32 u32_local_frequancy)
{
	//ICR1 = ( CRYSTAL_FREQ / PRESCALER_D_F ) / u32_local_frequancy;
}
void M_Pwm1SetDutyCycle(f64 f64_local_dutyCycle)
{
	OCR1A = ((f64_local_dutyCycle * 1250 ) / 100 ) - 1;
}
void M_Pwm1Start(void)
{
	// to select 1024 division factor
// 	SET_BIT(TCCR1B,0);
// 	CLR_BIT(TCCR1B,1);
// 	SET_BIT(TCCR1B,2);
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);

}
void M_Pwm1Stop(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}