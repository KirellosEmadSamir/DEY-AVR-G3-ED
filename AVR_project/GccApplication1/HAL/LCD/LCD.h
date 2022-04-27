/*
 * LCD.h
 *
 * Created: 06/04/2022 02:04:47 م
 *  Author: dell
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "STD.h"
#include "DIO.h"
#include "REG.h"
# define F_CPU 16000000UL
#include <util/delay.h>

void H_LcdInit(void);
void H_LcdWriteCharacter(u8);
void H_LcdWriteCommand(u8);
void H_LcdWriteString(u8*);
void H_LcdWriteNumber(f64);
void H_LcdClear(void);
void H_LcdGoTo(u8,u8);

#define _4_BIT_MODE       4
#define _8_BIT_MODE       8

#endif /* LCD_H_ */