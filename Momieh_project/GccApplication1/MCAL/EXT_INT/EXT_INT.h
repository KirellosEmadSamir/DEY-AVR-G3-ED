/*
 * EXT_INT.h
 *
 * Created: 11/04/2022 10:06:58 ص
 *  Author: dell
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

void M_ExtInt0Init(void);
void M_EXT_INT_SetCallBack(void(*)(void));

#define FAILLING_EDGE         1
#define RISING_EDGE           2
#define ANY_LOGICAL_CHANGE    3
#define LOW_LEVEL             4

#endif /* EXT_INT_H_ */