/*
 * KEY_PAD.c
 *
 * Created: 10/04/2022 10:18:22 ص
 *  Author: dell
 */ 
#include "KEY_PAD_CFG.h"
#include "DIO.h"
# define F_CPU 16000000UL
#include <util/delay.h>

void H_KeyPadInit(void)
{
	M_PinMode(KEY_PAD_R0,OUTPUT);
	M_PinMode(KEY_PAD_R1,OUTPUT);
	M_PinMode(KEY_PAD_R2,OUTPUT);
	M_PinMode(KEY_PAD_R3,OUTPUT);
	M_PinMode(KEY_PAD_C0,INPUT);
	M_PinMode(KEY_PAD_C1,INPUT);
	M_PinMode(KEY_PAD_C2,INPUT);
	M_PinMode(KEY_PAD_C3,INPUT);
	M_PinWrite(KEY_PAD_R0,HIGH);
	M_PinWrite(KEY_PAD_R1,HIGH);
	M_PinWrite(KEY_PAD_R2,HIGH);
	M_PinWrite(KEY_PAD_R3,HIGH);
	M_PinPullUp(KEY_PAD_C0,ENABLE);
	M_PinPullUp(KEY_PAD_C1,ENABLE);
	M_PinPullUp(KEY_PAD_C2,ENABLE);
	M_PinPullUp(KEY_PAD_C3,ENABLE);
}
u8   H_KeyPadRead(void)
{
	u8 key_pad_arr [4][4] = {{'7' , '8' , '9' , '/'},
							 {'4' , '5' , '6' , '*'},
							 {'1' , '2' , '3' , '-'},
							 {'C' , '0' , '=' , '+'}};
	u8 u8_local_row = 0;
	u8 u8_local_col = 0;
	u8 u8_local_reading = 1;
	u8 u8_local_data = 0;
	for (u8_local_row=KEY_PAD_R0;u8_local_row<=KEY_PAD_R3;u8_local_row++)
	{
		M_PinWrite(u8_local_row,LOW);
		for (u8_local_col=KEY_PAD_C0;u8_local_col<=KEY_PAD_C3;u8_local_col++)
		{
			u8_local_reading = M_PinRead(u8_local_col);  
			if(u8_local_reading == 0)
			{
				_delay_ms(150);
				u8_local_reading = M_PinRead(u8_local_col);  
				if(u8_local_reading == 0)
				{
					while(M_PinRead(u8_local_col) == 0);
					u8_local_data =  key_pad_arr[u8_local_row-KEY_PAD_R0][u8_local_col-KEY_PAD_C0];
				} 
			}
		}
		M_PinWrite(u8_local_row,HIGH);
	}
	return u8_local_data;
}