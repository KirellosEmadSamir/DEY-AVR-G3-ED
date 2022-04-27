/*
 * AT24C16A.c
 *
 * Created: 25/04/2022 11:42:57 ص
 *  Author: dell
 */
#include "LED.h"
#include "STD.h"
#include "I2C.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void H_Eeprom16kInit(void)
{
	M_I2cInit();
}
void H_Eeprom16kWrite(u8 u8_local_page,u8 u8_local_byte,u8 u8_local_data)
{
		
	M_I2cStartCondition();
	
	M_I2cMasterSendSlaveAddressWrite((0x50 | u8_local_page));
	
	M_I2cMasterSendByte(u8_local_byte);

	M_I2cMasterSendByte(u8_local_data);
	
	M_I2cStopCondition();
	
	_delay_ms(100);
}
u8   H_Eeprom16kRead(u8 u8_local_page,u8 u8_local_byte)
{
	u8 u8_local_data = 0;
	M_I2cStartCondition();
		
	M_I2cMasterSendSlaveAddressWrite((0x50 | u8_local_page));
	
	M_I2cMasterSendByte(u8_local_byte);
	
	M_I2cRepeatedStart();
	
	M_I2cMasterSendSlaveAddressRead((0x50 | u8_local_page));
	
	u8_local_data = M_I2cMasterReadByte();
	M_I2cStopCondition();
	
	return u8_local_data;
}