/*
 * TIMER_0.h
 *
 * Created: 13/04/2022 10:13:34 ص
 *  Author: dell
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_
#include "STD.h"

void M_Timer0Init(void);
void M_Timer0SetTime(u32);
void M_Timer0Start(void);
void M_Timer0Stop(void);
void M_Timer0_SetCallBack(void(*)(void));

void M_Pwm0Init(void);
void M_Pwm0SetDutyCycle(u8);
void M_Pwm0Start(void);
void M_Pwm0Stop(void);

#define NORMAL_MODE           1
#define CTC_MODE              2
#define FAST_PWM              3
#define PHASE_CORRECT_PWM     4

#endif /* TIMER_0_H_ */