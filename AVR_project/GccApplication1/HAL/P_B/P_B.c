/*
 * P_B.c
 *
 * Created: 04/04/2022 10:42:24 ص
 *  Author: dell
 */ 
#include "P_B_CFG.h"
#include "P_B.h"
#include "DIO.h"
void H_PushButtonInit(u8 u8_local_pb)
{
	switch(u8_local_pb)
	{
		case PB_1:
		M_PinMode(PUSH_BUTTON_1_PIN,INPUT);
		M_PinPullUp(PUSH_BUTTON_1_PIN,ENABLE);
		break;
		case PB_2:
		M_PinMode(PUSH_BUTTON_2_PIN,INPUT);
		M_PinPullUp(PUSH_BUTTON_2_PIN,ENABLE);	
		break;
		case PB_3:
		M_PinMode(PUSH_BUTTON_3_PIN,INPUT);
		M_PinPullUp(PUSH_BUTTON_3_PIN,ENABLE);	
		break;
		case PB_4:
		M_PinMode(PUSH_BUTTON_4_PIN,INPUT);
		M_PinPullUp(PUSH_BUTTON_4_PIN,ENABLE);	
		break;
		default:
		break;
	}
}
u8   H_PushButtonRead(u8 u8_local_pb)
{
	u8 reading = 0;
	switch(u8_local_pb)
	{
		case PB_1:
	    reading = M_PinRead(PUSH_BUTTON_1_PIN);
		break;
		case PB_2:
		reading = M_PinRead(PUSH_BUTTON_2_PIN);
		break;
		case PB_3:
		reading = M_PinRead(PUSH_BUTTON_3_PIN);
		break;
		case PB_4:
		reading = M_PinRead(PUSH_BUTTON_4_PIN);
		break;
		default:
		break;
	}
	return reading;
}