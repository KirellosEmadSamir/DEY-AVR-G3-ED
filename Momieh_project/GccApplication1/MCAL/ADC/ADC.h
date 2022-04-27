/*
 * ADC.h
 *
 * Created: 12/04/2022 10:23:00 ص
 *  Author: dell
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD.h"

void M_AdcInit(void);
u16  M_AdcRead(void);

#define AVCC        1
#define AREF_PIN    2
#define _2_VOLT     3
#define RIGHT       0
#define LEFT        1
#define _64         0
#define _128        1
#define ON          1
#define OFF         2

#endif /* ADC_H_ */