/*
 * LED.c
 *
 * Created: 04/04/2022 09:43:54 ص
 *  Author: dell
 */ 
#include "LED_CFG.h"
#include "LED.h"
#include "DIO.h"
# define F_CPU 16000000UL
#include <util/delay.h>
void H_LedInit(u8 u8_led)
{
	switch(u8_led)
	{
		case R_LED:
		M_PinMode(R_LED_PIN,OUTPUT);
		break;
		case G_LED:
		M_PinMode(G_LED_PIN,OUTPUT);
		break;
		case B_LED:
		M_PinMode(B_LED_PIN,OUTPUT);
		break;
		case BAZER:
		M_PinMode(BAZER_PIN,OUTPUT);
		break;		
		case Motor_LED:
		M_PinMode(Motor_LED_PIN,OUTPUT);
		break;
		case Right_LED:
		M_PinMode(Right_LED_PIN,OUTPUT);
		break;
		case Lift_LED:
		M_PinMode(Lift_LED_PIN,OUTPUT);
		break;					
		default:
		break;
	}
}
void H_LedOn(u8 u8_led)
{
	switch(u8_led)
	{
		case R_LED:
		M_PinWrite(R_LED_PIN,HIGH);
		break;
		case G_LED:
		M_PinWrite(G_LED_PIN,HIGH);
		break;
		case B_LED:
		M_PinWrite(B_LED_PIN,HIGH);
		break;
		case BAZER:
		M_PinWrite(BAZER_PIN,HIGH);
		break;
		case Motor_LED:
		M_PinWrite(Motor_LED_PIN,HIGH);
		break;
		case Right_LED:
		M_PinWrite(Right_LED_PIN,HIGH);
		break;
		case Lift_LED:
		M_PinWrite(Lift_LED_PIN,HIGH);
		break;		
		default:
		break;
	}
}
void H_LedOff(u8 u8_led)
{
	switch(u8_led)
	{
		case R_LED:
		M_PinWrite(R_LED_PIN,LOW);
		break;
		case G_LED:
		M_PinWrite(G_LED_PIN,LOW);
		break;
		case B_LED:
		M_PinWrite(B_LED_PIN,LOW);
		break;
		case BAZER:
		M_PinWrite(BAZER_PIN,LOW);
		break;
		case Motor_LED:
		M_PinWrite(Motor_LED_PIN,LOW);
		break;
		case Right_LED:
		M_PinWrite(Right_LED_PIN,LOW);
		break;
		case Lift_LED:
		M_PinWrite(Lift_LED_PIN,LOW);
		break;
		default:
		break;
	}
}
void H_LedTog(u8 u8_led)
{
	switch(u8_led)
	{
		case R_LED:
		M_PinTog(R_LED_PIN);
		break;
		case G_LED:
		M_PinTog(G_LED_PIN);
		break;
		case B_LED:
		M_PinTog(B_LED_PIN);
		break;
		case BAZER:
		M_PinTog(BAZER_PIN);
		break;	
		case Motor_LED:
		M_PinTog(Motor_LED_PIN);
		break;
		case Right_LED:
		M_PinTog(Right_LED_PIN);
		break;
		case Lift_LED:
		M_PinTog(Lift_LED_PIN);
		break;			
		default:
		break;
	}
}
void H_LedBlink(u8 u8_led)
{
	switch(u8_led)
	{
		case R_LED:
		M_PinWrite(R_LED_PIN,HIGH);
		_delay_ms(50);
		M_PinWrite(R_LED_PIN,LOW);
		break;
		case G_LED:
		M_PinWrite(G_LED_PIN,HIGH);
		_delay_ms(500);
		M_PinWrite(G_LED_PIN,LOW);
		break;
		case B_LED:
		M_PinWrite(B_LED_PIN,HIGH);
		_delay_ms(50);
		M_PinWrite(B_LED_PIN,LOW);
		break;
		case BAZER:
		M_PinWrite(BAZER_PIN,HIGH);
		_delay_ms(50);
		M_PinWrite(BAZER_PIN,LOW);
		break;
		case Motor_LED:
		M_PinWrite(Motor_LED_PIN,HIGH);
				_delay_ms(50);
		M_PinWrite(Motor_LED_PIN,LOW);											
		break;
		case Right_LED:
		M_PinWrite(Right_LED_PIN,HIGH);
				_delay_ms(50);
		M_PinWrite(Right_LED_PIN,LOW);
		break;
		case Lift_LED:
		M_PinWrite(Lift_LED_PIN,HIGH);
				_delay_ms(50);
		M_PinWrite(Lift_LED_PIN,LOW);		
		break;
		default:
		break;
	}	
}