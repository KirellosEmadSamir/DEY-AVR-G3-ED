/*
 * SSD.c
 *
 * Created: 05/04/2022 10:09:35 ص
 *  Author: dell
 */ 

#include "SSD_CFG.h"
#include "SSD.h"

void H_SsdInit(void)
{
	#if SSD_MODE     ==    DIRECT_MODE
	M_PinMode(SSD_LED_A,OUTPUT);
	M_PinMode(SSD_LED_B,OUTPUT);
	M_PinMode(SSD_LED_C,OUTPUT);
	M_PinMode(SSD_LED_D,OUTPUT);
	M_PinMode(SSD_LED_E,OUTPUT);
	M_PinMode(SSD_LED_F,OUTPUT);
	M_PinMode(SSD_LED_G,OUTPUT);
	M_PinMode(SSD_1_ENABLE,OUTPUT);
	M_PinMode(SSD_2_ENABLE,OUTPUT);
	#elif SSD_MODE   ==    DECODER_MODE
	M_PinMode(DECODER_1_PIN,OUTPUT);
	M_PinMode(DECODER_2_PIN,OUTPUT);
	M_PinMode(DECODER_3_PIN,OUTPUT);
	M_PinMode(DECODER_4_PIN,OUTPUT);
	M_PinMode(SSD_1_ENABLE,OUTPUT);
	M_PinMode(SSD_2_ENABLE,OUTPUT);
	#endif
}
void H_SsdDisplayBlink(u8 u8_number)
{
	u8 u8_tens = u8_number / 10;
	u8 u8_ones = u8_number % 10;
	u8 i = 0;
	for(i=0;i<100;i++)
	{
		#if SSD_MODE     ==   DIRECT_MODE
		M_PinWrite(SSD_1_ENABLE,HIGH);
		M_PinWrite(SSD_2_ENABLE,LOW);
		switch(u8_ones)
		{
			case 0:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 1:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 2:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,LOW);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 3:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 4:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 5:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 6:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 7:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 8:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 9:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			default:
			break;
		}
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,HIGH);
		switch(u8_tens)
		{
			case 0:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 1:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 2:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,LOW);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 3:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 4:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 5:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 6:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 7:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 8:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			case 9:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);
			break;
			default:
			break;
		}
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,LOW);
		#elif SSD_MODE    ==    DECODER_MODE
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,HIGH);
		switch(u8_ones)
		{
			case 0:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 1:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 2:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 3:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 4:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 5:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 6:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 7:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 8:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);
			break;
			case 9:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);
			break;
			default:
			break;
		}
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,HIGH);
		M_PinWrite(SSD_2_ENABLE,LOW);
		switch(u8_tens)
		{
			case 0:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 1:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 2:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 3:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 4:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 5:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 6:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 7:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 8:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);
			break;
			case 9:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);
			break;
			default:
			break;
		}
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,LOW);
		#endif
	}	
}
void H_SsdDisplay(u8 u8_number)
{
	u8 u8_tens = u8_number / 10;	
	u8 u8_ones = u8_number % 10;
	for(;;)
	{
		#if SSD_MODE     ==   DIRECT_MODE
		M_PinWrite(SSD_1_ENABLE,HIGH);
		M_PinWrite(SSD_2_ENABLE,LOW);
		switch(u8_ones)
		{
			case 0:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 1:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);		
			break;
			case 2:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,LOW);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 3:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 4:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 5:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 6:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 7:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);		
			break;
			case 8:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 9:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			default:
			break;
		}
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,HIGH);
		switch(u8_tens)
		{
			case 0:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,LOW);
			break;
			case 1:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);		
			break;
			case 2:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,LOW);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 3:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 4:
			M_PinWrite(SSD_LED_A,LOW);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 5:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 6:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,LOW);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 7:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,LOW);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,LOW);
			M_PinWrite(SSD_LED_G,LOW);		
			break;
			case 8:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,HIGH);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			case 9:
			M_PinWrite(SSD_LED_A,HIGH);
			M_PinWrite(SSD_LED_B,HIGH);
			M_PinWrite(SSD_LED_C,HIGH);
			M_PinWrite(SSD_LED_D,HIGH);
			M_PinWrite(SSD_LED_E,LOW);
			M_PinWrite(SSD_LED_F,HIGH);
			M_PinWrite(SSD_LED_G,HIGH);		
			break;
			default:
			break;
		}	
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,LOW);
		#elif SSD_MODE    ==    DECODER_MODE
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,HIGH);
		switch(u8_ones)
		{
			case 0:
			M_PinWrite(DECODER_1_PIN,LOW);
		    M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 1:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);	
			break;
			case 2:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);	
			break;
			case 3:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);	
			break;
			case 4:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 5:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);	
			break;
			case 6:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);	
			break;
			case 7:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);		
			break;
			case 8:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);		
			break;
			case 9:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);	
			break;
			default:
			break;
		}
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,HIGH);
		M_PinWrite(SSD_2_ENABLE,LOW);
		switch(u8_tens)
		{
			case 0:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 1:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 2:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 3:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 4:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 5:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 6:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 7:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,HIGH);
			M_PinWrite(DECODER_3_PIN,HIGH);
			M_PinWrite(DECODER_4_PIN,LOW);
			break;
			case 8:
			M_PinWrite(DECODER_1_PIN,LOW);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);
			break;
			case 9:
			M_PinWrite(DECODER_1_PIN,HIGH);
			M_PinWrite(DECODER_2_PIN,LOW);
			M_PinWrite(DECODER_3_PIN,LOW);
			M_PinWrite(DECODER_4_PIN,HIGH);
			break;
			default:
			break;
		}
		_delay_ms(5);
		M_PinWrite(SSD_1_ENABLE,LOW);
		M_PinWrite(SSD_2_ENABLE,LOW);	
		#endif
	}
}
void H_SsdCountUp(u8 u8_number)
{
	u8 i = 0;
	for (i=0;i<=u8_number;i++)
	{
		H_SsdDisplayBlink(i);
	}
}
void H_SsdCountDown(u8 u8_number)
{
	s8 i = 0;
	for (i=u8_number;i>=0;i--)
	{
		H_SsdDisplayBlink(i);
	}
}
void H_SsdClear(void);