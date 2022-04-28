/*
 * TIMER_0.c
 *
 * Created: 13/04/2022 10:13:14 ص
 *  Author: dell
 */ 

#include "TIMER_2_CFG.h"
#include "TIMER_2.h"
#include "BIT_MATH.h"
#include "STD.h"
#include "DIO.h"
#include "REG.h"
#include <avr/interrupt.h>

void (*call_back)(void);
u32 u32_global_no_of_ov2 = 0;
u8  u8_global_rem_ticks2 = 0;
u32 u32_global_no_of_cm2 = 0;
void M_Timer2Init(void)
{
	#if  TIMER_2_MODE         ==    NORMAL_MODE
	CLR_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);
	// to enable timer0 ov int
	SET_BIT(TIMSK,6);
	#elif TIMER_2_MODE        ==    CTC_MODE
	SET_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);
	// to enable timer2 cm int
	SET_BIT(TIMSK,7);
	#endif
	// to enable global int
	SET_BIT(SREG,7);
}
void M_Timer2SetTime(u32 u32_local_desired_time) 
{
	u32 u32_local_tick_time   =  PRESCALER_D_F / CRYSTAL_FREQ;    // in micro second
	u32 u32_local_total_ticks =  (u32_local_desired_time * 1000) / u32_local_tick_time;
	#if TIMER_2_MODE          ==    NORMAL_MODE
	    u32_global_no_of_ov2   =  u32_local_total_ticks / 256;
		u8_global_rem_ticks2   =  u32_local_total_ticks % 256;
	if(u8_global_rem_ticks2 != 0)
	{
		TCNT2                     =  256 - u8_global_rem_ticks2;
		u32_global_no_of_ov2 ++;
	}
	#elif TIMER_2_MODE        ==    CTC_MODE
	u8 u8_local_division_number = 255;
	while(u32_local_total_ticks % u8_local_division_number)
	{
		u8_local_division_number--;
	}
	u32_global_no_of_cm2   =  u32_local_total_ticks / u8_local_division_number;
	OCR2                  = u8_local_division_number - 1;
	#endif
}
void M_Timer2Start(void)
{
	#if   PRESCALER_D_F       ==      1024
	SET_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);
	#elif PRESCALER_D_F       ==      256
	CLR_BIT(TCCR2,0);
    CLR_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);
	#endif
}
void M_Timer2Stop(void)
{
	CLR_BIT(TCCR2,0);
	CLR_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);
}

void M_Timer2_SetCallBack(void(*ptr)(void))
{
	call_back = ptr;
}
#if TIMER_2_MODE        ==    NORMAL_MODE
ISR(TIMER2_OVF_vect)
{
	static u32 u32_static_local_counter = 0;
	u32_static_local_counter++;
	if(u32_static_local_counter == u32_global_no_of_ov2)
	{
		call_back();
		u32_static_local_counter = 0;
		TCNT2                    = 256 - u8_global_rem_ticks2;
	}
}
#elif TIMER_2_MODE        ==    CTC_MODE
ISR(TIMER2_COMP_vect)
{
		// to enable global int
		CLR_BIT(SREG,7);
	static u32 u32_static_local_counter = 0;
	u32_static_local_counter++;
	if(u32_static_local_counter == u32_global_no_of_cm2)
	{
		call_back();
		u32_static_local_counter = 0;
	}	
		// to enable global int
		SET_BIT(SREG,7);
}
#endif
void M_Pwm2Init(void)
{
	// to enable output circuit
	SET_BIT(DDRD,7);
	//M_PinMode(PB3,OUTPUT);                     // test this line hardware
	#if PWM0MODE         ==     FAST_PWM
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
	// to select non inverted mode
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
	#elif PWM0MODE       ==     PHASE_CORRECT_PWM
	SET_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);
	// to select non inverted mode
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
	#endif
}
void M_Pwm2SetDutyCycle(u8 u8_local_dutyCycle)
{
	#if PWM0MODE       ==     FAST_PWM
	OCR2 = ((u8_local_dutyCycle * 256 ) / 100 ) - 1;
	#elif PWM0MODE       ==     PHASE_CORRECT_PWM
	OCR2 = ((u8_local_dutyCycle * 255 ) / 100 );
	#endif
}
void M_Pwm2Start(void)
{
	M_Timer2Start();
}
void M_Pwm2Stop(void)
{
	M_Timer2Stop();
}