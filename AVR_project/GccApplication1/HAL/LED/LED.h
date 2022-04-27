/*
 * LED.h
 *
 * Created: 04/04/2022 09:44:02 ص
 *  Author: dell
 */ 


#ifndef LED_H_
#define LED_H_

#include "STD.h"

void H_LedInit(u8);
void H_LedOn(u8);
void H_LedOff(u8);
void H_LedTog(u8);
void H_LedBlink(u8);

#define R_LED      1
#define G_LED      2
#define B_LED      3

#define BAZER      4

#define Motor_LED  5
#define Right_LED  6
#define Lift_LED  7



#endif /* LED_H_ */