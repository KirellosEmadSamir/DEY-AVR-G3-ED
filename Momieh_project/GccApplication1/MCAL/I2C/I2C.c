/*
 * I2C.c
 *
 * Created: 24/04/2022 01:05:05 م
 *  Author: dell
 */ 

#include "I2C_CFG.h"
#include "I2C.h"
#include "STD.h"
#include "BIT_MATH.h"
#include "REG.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void M_I2cInit(void)
{
	#if   I2C_MODE      ==    MASTER
	// to select Fscl -> 400 KHz
	TWBR = 12;
	#elif I2C_MODE      ==    SLAVE
	TWAR = 0b00000010;
	#endif
	// to enable i2c circuit
	SET_BIT(TWCR,2);
}
void M_I2cStartCondition(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);   // to clear the flag
	while( (GET_BIT(TWCR,7)) == 0 );
	while( ( TWSR & 0xF8 ) != START_ACK );
}
void M_I2cStopCondition(void)
{
	SET_BIT(TWCR,4);
	SET_BIT(TWCR,7);   // to clear the flag
	//while( GET_BIT(TWCR,7) == 0 );
}
void M_I2cRepeatedStart(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);   // to clear the flag
	while( (GET_BIT(TWCR,7)) == 0 );	
	while( ( TWSR & 0xF8 ) != REP_START_ACK );	
}
void M_I2cMasterSendSlaveAddressWrite(u8 u8_local_address)  
{
	TWDR = ( u8_local_address << 1 );
	SET_BIT(TWCR,7);   // to clear the flag
	while( (GET_BIT(TWCR,7)) == 0 );	
	while( ( TWSR & 0xF8 ) != SLAVE_AD_AND_WR_ACK );


}
void M_I2cMasterSendSlaveAddressRead(u8 u8_local_address)
{
	TWDR = (( u8_local_address << 1 ) | 1 );
	SET_BIT(TWCR,7);   // to clear the flag
	while((GET_BIT(TWCR,7)) == 0 );	
	while(( TWSR & 0xF8 ) != SLAVE_AD_AND_RD_ACK );
}
void M_I2cMasterSendByte(u8 u8_local_byte)
{
	TWDR = u8_local_byte;
	CLR_BIT(TWCR,5);  
	SET_BIT(TWCR,7);   // to clear the flag
	while( (GET_BIT(TWCR,7)) == 0 );	
	while( ( TWSR & 0xF8 ) != WR_BYTE_ACK );	
}
u8   M_I2cMasterReadByte(void)
{
	u8 u8_local_data = 0;
	CLR_BIT(TWCR,5);   // add this line
	CLR_BIT(TWCR,4);   // add this line
	SET_BIT(TWCR,6);   // add this line
	SET_BIT(TWCR,7);   // to clear the flag
	while( (GET_BIT(TWCR,7)) == 0 );	
	while( ( TWSR & 0xF8 ) != RD_BYTE_WITH_ACK );	
	u8_local_data = TWDR;
	return u8_local_data;
}