/*
 * LCD.c
 *
 * Created: 06/04/2022 02:04:37 م
 *  Author: dell
 */     
#include "LCD_CFG.h"
#include "LCD.h"

void H_LcdInit(void)
{
	M_PinMode(LCD_RS_PIN,OUTPUT);
	M_PinMode(LCD_EN_PIN,OUTPUT);
	M_PinMode(LCD_RW_PIN,OUTPUT);
	#if LCD_MODE     ==   _8_BIT_MODE
	M_PinMode(LCD_DATA_PIN_0,OUTPUT);
	M_PinMode(LCD_DATA_PIN_1,OUTPUT);
	M_PinMode(LCD_DATA_PIN_2,OUTPUT);
	M_PinMode(LCD_DATA_PIN_3,OUTPUT);
	M_PinMode(LCD_DATA_PIN_4,OUTPUT);
	M_PinMode(LCD_DATA_PIN_5,OUTPUT);
	M_PinMode(LCD_DATA_PIN_6,OUTPUT);
	M_PinMode(LCD_DATA_PIN_7,OUTPUT);

	_delay_ms(500);
	H_LcdWriteCommand(0x38);    // to select 8-bit mode
	H_LcdWriteCommand(0x0C);    // to turn display on , cursor off
	H_LcdWriteCommand(0x02);    // to return home
	H_LcdWriteCommand(0x06);    // to display from left to right
	H_LcdWriteCommand(0x01);    // to clear LCD
	#elif LCD_MODE    ==   _4_BIT_MODE
	M_PinMode(LCD_DATA_PIN_4,OUTPUT);
	M_PinMode(LCD_DATA_PIN_5,OUTPUT);
	M_PinMode(LCD_DATA_PIN_6,OUTPUT);
	M_PinMode(LCD_DATA_PIN_7,OUTPUT);
	_delay_ms(500);
	H_LcdWriteCommand(0x33);
	H_LcdWriteCommand(0x32);
	H_LcdWriteCommand(0x28);
	H_LcdWriteCommand(0x0C);    // to turn display on , cursor off
	H_LcdWriteCommand(0x02);    // to return home
	H_LcdWriteCommand(0x06);    // to display from left to right
	H_LcdWriteCommand(0x01);    // to clear LCD
	#endif
}
void H_LcdWriteCharacter(u8 u8_Local_caracter)
{
	M_PinWrite(LCD_RS_PIN,HIGH);
	M_PinWrite(LCD_RW_PIN,LOW);
	#if LCD_MODE    ==  _8_BIT_MODE
	LCD_DATA_PORT = u8_Local_caracter;
	M_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_PIN,LOW);	
	_delay_ms(5);
	#elif LCD_MODE    ==   _4_BIT_MODE
	LCD_DATA_PORT = (((u8_Local_caracter >> 1) & 0b01111000) | (LCD_DATA_PORT & 0b10000111));
	M_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	LCD_DATA_PORT = (((u8_Local_caracter << 3) & 0b01111000) | (LCD_DATA_PORT & 0b10000111));
	M_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}
void H_LcdWriteCommand(u8 u8_Local_command)
{
	M_PinWrite(LCD_RS_PIN,LOW);
	M_PinWrite(LCD_RW_PIN,LOW);
	#if LCD_MODE    ==   _8_BIT_MODE
	LCD_DATA_PORT = u8_Local_command;
	M_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#elif LCD_MODE    ==   _4_BIT_MODE
	LCD_DATA_PORT = (((u8_Local_command >> 1) & 0b01111000) | (LCD_DATA_PORT & 0b10000111));
	M_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	LCD_DATA_PORT = (((u8_Local_command << 3) & 0b01111000) | (LCD_DATA_PORT & 0b10000111));
	M_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif
}

void H_LcdWriteString(u8* u8_Local_ptr)
{
	u8 u8_local_counter = 0;
	while(u8_Local_ptr[u8_local_counter] != '\0')
	{
		H_LcdWriteCharacter(u8_Local_ptr[u8_local_counter]);
		u8_local_counter++;
	}
}

void H_LcdWriteNumber(f64 f64_local_number)   
{
	s32 s32_local_number_copy = f64_local_number;
	u8 u8_local_arr [10] = {0};
	s8 s8_local_counter = 0;
	if(s32_local_number_copy == 0)
	{
		H_LcdWriteCharacter('0');
	}
	else if(s32_local_number_copy < 0)
	{
		H_LcdWriteCharacter('-');
		s32_local_number_copy = s32_local_number_copy * (-1);
	}
	while(s32_local_number_copy != 0)
	{
		u8_local_arr [s8_local_counter] = s32_local_number_copy % 10;
		s8_local_counter++;
		s32_local_number_copy = s32_local_number_copy / 10;
	}
	s8_local_counter--;
	while (s8_local_counter >= 0)
	{
		H_LcdWriteCharacter(u8_local_arr[s8_local_counter] + '0');
		s8_local_counter--;
	}
}

void H_LcdClear(void)
{
	H_LcdWriteCommand(0x01);
}

void H_LcdGoTo(u8 u8_local_row,u8 u8_local_col)
{
	u8 arr[2] = {0x80,0xC0};
	H_LcdWriteCommand(arr[u8_local_row]+u8_local_col);  
}