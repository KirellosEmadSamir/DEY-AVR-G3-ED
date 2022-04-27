/*
 * WDT.c
 *
 * Created: 19/04/2022 10:52:24 ص
 *  Author: dell
 */ 
#include "REG.h"
#include "BIT_MATH.h"

void M_WdtInit(void)
{
	// to select 2.1 seconds
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	// to enable WDT
	SET_BIT(WDTCR,3);
}
void M_WdtRefresh(void)
{
	asm("WDR");
}