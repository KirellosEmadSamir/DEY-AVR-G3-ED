/*
 * SERVO.h
 *
 * Created: 19/04/2022 02:00:15 م
 *  Author: dell
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "STD.h"

void H_ServoInit(void);
void H_ServoSetAngle(u16);
void H_ServoStart(void);
void H_ServoStop(void);

#endif /* SERVO_H_ */