/*
 * UART.c
 *
 * Created: 20/04/2022 10:46:38 ص
 *  Author: dell
 */ 
#include "UART_CFG.h"
#include "UART.h"
#include "STD.h"
#include "REG.h"
#include "BIT_MATH.h"

void M_UartInit(void)
{
	u8 u8_localUCSRCValue = 0b10000000;
	// to enable input circuit
	CLR_BIT(DDRD,0);
	// to enable output circuit
	SET_BIT(DDRD,1);
	// to select asynch. mode
	CLR_BIT(u8_localUCSRCValue,6);
	#if   CHARACTER_SIZE       ==    7
	CLR_BIT(UCSRB,2);
	CLR_BIT(u8_localUCSRCValue,1);
	SET_BIT(u8_localUCSRCValue,2);
	#elif CHARACTER_SIZE       ==    8
	CLR_BIT(UCSRB,2);
	SET_BIT(u8_localUCSRCValue,1);
	SET_BIT(u8_localUCSRCValue,2);
	#endif
	#if   PARITY_CHECK      ==     EVEN
	CLR_BIT(u8_localUCSRCValue,4);
	SET_BIT(u8_localUCSRCValue,5);
	#elif PARITY_CHECK      ==     ODD
	SET_BIT(u8_localUCSRCValue,4);
	SET_BIT(u8_localUCSRCValue,5);
	#elif PARITY_CHECK      ==     OFF
	CLR_BIT(u8_localUCSRCValue,4);
	CLR_BIT(u8_localUCSRCValue,5);
	#endif
	#if   STOP_BITS       ==   1
	CLR_BIT(u8_localUCSRCValue,3);
	#elif STOP_BITS       ==   2
	SET_BIT(u8_localUCSRCValue,3);
	#endif
	#if    BAUD_RATE       ==    9600
	UBRRL = 103;
	#elif  BAUD_RATE       ==   115200
	UBRRL = 8;
	#endif
	UCSRC = u8_localUCSRCValue;
	// to enable rec. circuit
	SET_BIT(UCSRB,4);
	// to enable transmitter circuit
	SET_BIT(UCSRB,3);
}
void M_UartSend(u8 u8_local_data)
{
	UDR = u8_local_data;
	while(GET_BIT(UCSRA,6) == 0);
}
u8   M_UartRec(void)
{
	while(GET_BIT(UCSRA,7) == 0);
	return UDR;
}