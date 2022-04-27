/*
 * DC_MOTOR.h
 *
 * Created: 18/04/2022 09:43:15 ص
 *  Author: dell
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD.h"

void H_DcMotorInit(void);
void H_DcMotorSetDirection(u8);
void H_DcMotorSetSpeed(u32);
void H_DcMotorStart(void);
void H_DcMotorStop(void);

#define CLK_W       1
#define A_CLK_W     2

#endif /* DC_MOTOR_H_ */