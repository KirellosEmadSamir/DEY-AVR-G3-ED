/*
 * TIMER_0_CFG.h
 *
 * Created: 13/04/2022 10:13:48 ص
 *  Author: dell
 */ 


#ifndef TIMER_0_CFG_H_
#define TIMER_0_CFG_H_

// TIMER_0_MODE options --> [ NORMAL_MODE , CTC_MODE ]
#define TIMER_0_MODE       CTC_MODE
// select crystal oscillator frequency in MHz
#define CRYSTAL_FREQ       16
// select PRESCALER_D_F options --> [ 256 , 1024 ]
#define PRESCALER_D_F      1024
// PWM0MODE options --> [ PHASE_CORRECT_PWM , FAST_PWM ]
#define PWM0MODE          PHASE_CORRECT_PWM

#endif /* TIMER_0_CFG_H_ */