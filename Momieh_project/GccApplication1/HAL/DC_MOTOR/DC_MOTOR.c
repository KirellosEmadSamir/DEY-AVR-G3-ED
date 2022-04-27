/*
 * DC_MOTOR.c
 *
 * Created: 18/04/2022 09:41:46 ص
 *  Author: dell
 */ 
#include "DC_MOTOR_CFG.h"
#include "DC_MOTOR.h"
#include "STD.h"
#include "TIMER_0.h"
#include "DIO.h"
void H_DcMotorInit(void)
{
	M_PinMode(IN_1,OUTPUT);
	M_PinMode(IN_2,OUTPUT);
	M_Pwm0Init();
}
void H_DcMotorSetDirection(u8 u8_local_deirection)
{
	switch(u8_local_deirection)
	{
		case CLK_W:
		M_PinWrite(IN_1,HIGH);
		M_PinWrite(IN_2,LOW);
		break;
		case A_CLK_W:
		M_PinWrite(IN_1,LOW);
		M_PinWrite(IN_2,HIGH);
		break;
		default:
		break;
	}
}
void H_DcMotorSetSpeed(u32 u32_local_speed)
{
	M_Pwm0SetDutyCycle(u32_local_speed);
}
void H_DcMotorStart(void)
{
	M_Pwm0Start();
}
void H_DcMotorStop(void)
{
	M_Pwm0Stop();
}