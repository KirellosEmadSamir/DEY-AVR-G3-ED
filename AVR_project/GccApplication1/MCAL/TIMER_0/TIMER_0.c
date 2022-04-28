/*
 * TIMER_0.c
 *
 * Created: 13/04/2022 10:13:14 ص
 *  Author: dell
 */ 

#include "TIMER_0_CFG.h"
#include "TIMER_0.h"
#include "BIT_MATH.h"
#include "STD.h"
#include "DIO.h"
#include "REG.h"
#include <avr/interrupt.h>

void (*call_back)(void);
u32 u32_global_no_of_ov = 0;
u8  u8_global_rem_ticks = 0;
u32 u32_global_no_of_cm = 0;
void M_Timer0Init(void)
{
	#if  TIMER_0_MODE         ==    NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	// to enable timer0 ov int
	SET_BIT(TIMSK,0);
	#elif TIMER_0_MODE        ==    CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	// to enable timer0 cm int
	SET_BIT(TIMSK,1);
	#endif
	// to enable global int
	SET_BIT(SREG,7);
}
void M_Timer0SetTime(u32 u32_local_desired_time) 
{
	u32 u32_local_tick_time   =  PRESCALER_D_F / CRYSTAL_FREQ;    // in micro second
	u32 u32_local_total_ticks =  (u32_local_desired_time * 1000) / u32_local_tick_time;
	#if TIMER_0_MODE          ==    NORMAL_MODE
	    u32_global_no_of_ov   =  u32_local_total_ticks / 256;
		u8_global_rem_ticks   =  u32_local_total_ticks % 256;
	if(u8_global_rem_ticks != 0)
	{
		TCNT0                     =  256 - u8_global_rem_ticks;
		u32_global_no_of_ov++;
	}
	#elif TIMER_0_MODE        ==    CTC_MODE
	u8 u8_local_division_number = 255;
	while(u32_local_total_ticks % u8_local_division_number)
	{
		u8_local_division_number--;
	}
	u32_global_no_of_cm   =  u32_local_total_ticks / u8_local_division_number;
	OCR0                  = u8_local_division_number - 1;
	#endif
}
void M_Timer0Start(void)
{
	#if   PRESCALER_D_F       ==      1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#elif PRESCALER_D_F       ==      256
	CLR_BIT(TCCR0,0);
    CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#endif
}
void M_Timer0Stop(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void M_Timer0_SetCallBack(void(*ptr)(void))
{
	call_back = ptr;
}
#if TIMER_0_MODE        ==    NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
		// to enable global int
		CLR_BIT(SREG,7);
	static u32 u32_static_local_counter = 0;
	u32_static_local_counter++;
	if(u32_static_local_counter == u32_global_no_of_ov)
	{
		call_back();
		u32_static_local_counter = 0;
		TCNT0                    = 256 - u8_global_rem_ticks;
	}
		// to enable global int
		SET_BIT(SREG,7);
}
#elif TIMER_0_MODE        ==    CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 u32_static_local_counter = 0;
	u32_static_local_counter++;
	if(u32_static_local_counter == u32_global_no_of_cm)
	{
		call_back();
		u32_static_local_counter = 0;
	}	
}
#endif
void M_Pwm0Init(void)
{
	// to enable output circuit
	SET_BIT(DDRB,3);
	//M_PinMode(PB3,OUTPUT);                     // test this line hardware
	#if PWM0MODE         ==     FAST_PWM
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	// to select non inverted mode
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#elif PWM0MODE       ==     PHASE_CORRECT_PWM
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	// to select non inverted mode
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#endif
}
void M_Pwm0SetDutyCycle(u8 u8_local_dutyCycle)
{
	#if PWM0MODE       ==     FAST_PWM
	OCR0 = ((u8_local_dutyCycle * 256 ) / 100 ) - 1;
	#elif PWM0MODE       ==     PHASE_CORRECT_PWM
	OCR0 = ((u8_local_dutyCycle * 255 ) / 100 );
	#endif
}
void M_Pwm0Start(void)
{
	M_Timer0Start();
}
void M_Pwm0Stop(void)
{
	M_Timer0Stop();
}