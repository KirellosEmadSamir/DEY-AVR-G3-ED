/*
 * TIMER_2.h
 *
 * Created: 13/04/2022 10:13:34 ص
 *  Author: dell
 */ 


#ifndef TIMER_2_H_
#define TIMER_2_H_
#include "STD.h"

void M_Timer2Init(void);
void M_Timer2SetTime(u32);
void M_Timer2Start(void);
void M_Timer2Stop(void);
void M_Timer2_SetCallBack(void(*)(void));

void M_Pwm2Init(void);
void M_Pwm2SetDutyCycle(u8);
void M_Pwm2Start(void);
void M_Pwm2Stop(void);

#define NORMAL_MODE           1
#define CTC_MODE              2
#define FAST_PWM              3
#define PHASE_CORRECT_PWM     4

#endif /* TIMER_2_H_ */