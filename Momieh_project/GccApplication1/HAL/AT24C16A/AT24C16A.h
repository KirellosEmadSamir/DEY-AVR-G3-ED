/*
 * AT24C16A.h
 *
 * Created: 25/04/2022 11:43:09 ص
 *  Author: dell
 */ 


#ifndef AT24C16A_H_
#define AT24C16A_H_

#include "STD.h"
void H_Eeprom16kInit(void);
void H_Eeprom16kWrite(u8,u8,u8);
u8   H_Eeprom16kRead(u8,u8);

#endif /* AT24C16A_H_ */