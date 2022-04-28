/*
 * ULTRASONIC.h
 *
 * Created: 27/04/2022 10:49:39 م
 *  Author: hassa
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include "STD.h"
void H_UltraInit(void);
void H_UltraTrigger(void);

u32  H_UltraDistance(void);

void H_UltraUltraRissingEdge(void);
void H_UltraUltraFallingEdge(void);

void H_UltraStop(void);



#endif /* ULTRASONIC_H_ */