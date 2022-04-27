/*
 * DIO.c
 *
 * Created: 03/04/2022 01:20:09 م
 *  Author: dell
 */ 
#include "STD.h"
#include "REG.h"
#include "BIT_MATH.h"
#include "DIO.h"

void M_PinMode(u8 x,u8 state)
{
	u8 port = x / 10;    
	u8 pin  = x % 10;    
	switch(state)
	{
		case INPUT:
		switch(port)
		{
			case GROUP_A:
			CLR_BIT(DDRA,pin);
			break;
			case GROUP_B:
			CLR_BIT(DDRB,pin);
			break;
			case GROUP_C:
			CLR_BIT(DDRC,pin);
			break;
			case GROUP_D:
			CLR_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case GROUP_A:
			SET_BIT(DDRA,pin);
			break;
			case GROUP_B:
			SET_BIT(DDRB,pin);
			break;
			case GROUP_C:
			SET_BIT(DDRC,pin);
			break;
			case GROUP_D:
			SET_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}  
}

void M_PinWrite(u8 x,u8 state)
{
	u8 port = x / 10;
	u8 pin  = x % 10;
	switch(state)
	{
		case LOW:
		switch(port)
		{
			case GROUP_A:
			CLR_BIT(PORTA,pin);
			break;
			case GROUP_B:
			CLR_BIT(PORTB,pin);
			break;
			case GROUP_C:
			CLR_BIT(PORTC,pin);
			break;
			case GROUP_D:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case HIGH:
		switch(port)
		{
			case GROUP_A:
			SET_BIT(PORTA,pin);
			break;
			case GROUP_B:
			SET_BIT(PORTB,pin);
			break;
			case GROUP_C:
			SET_BIT(PORTC,pin);
			break;
			case GROUP_D:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}	
}
void M_PinTog(u8 x)
{
	u8 port = x / 10;    
	u8 pin  = x % 10;    
	switch(port)
	{
		case GROUP_A:
		TOG_BIT(PORTA,pin);
		break;
		case GROUP_B:
		TOG_BIT(PORTB,pin);
		break;
		case GROUP_C:
		TOG_BIT(PORTC,pin);
		break;
		case GROUP_D:
		TOG_BIT(PORTD,pin);
		break;
		default:
		break;
	}
}
u8   M_PinRead(u8 x)
{
	u8 port = x / 10;
	u8 pin  = x % 10;
	u8 reading = 0;
	switch(port)
	{
		case GROUP_A:
		reading = GET_BIT(PINA,pin);
		break;
		case GROUP_B:
		reading = GET_BIT(PINB,pin);
		break;
		case GROUP_C:
		reading = GET_BIT(PINC,pin);
		break;
		case GROUP_D:
		reading = GET_BIT(PIND,pin);
		break;
		default:
		break;
	}
	return reading;
}

void M_PinPullUp(u8 x,u8 state)
{
	u8 port = x / 10;
	u8 pin  = x % 10;
	switch(state)
	{
		case DISABLE:
		switch(port)
		{
			case GROUP_A:
			CLR_BIT(PORTA,pin);
			break;
			case GROUP_B:
			CLR_BIT(PORTB,pin);
			break;
			case GROUP_C:
			CLR_BIT(PORTC,pin);
			break;
			case GROUP_D:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case ENABLE:
		switch(port)
		{
			case GROUP_A:
			SET_BIT(PORTA,pin);
			break;
			case GROUP_B:
			SET_BIT(PORTB,pin);
			break;
			case GROUP_C:
			SET_BIT(PORTC,pin);
			break;
			case GROUP_D:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}