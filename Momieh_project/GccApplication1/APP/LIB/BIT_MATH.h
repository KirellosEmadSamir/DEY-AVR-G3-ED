/*
 * BIT_MATH.h
 *
 * Created: 03/04/2022 10:12:25 ص
 *  Author: dell
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)      REG |= (1 << BIT)
#define CLR_BIT(REG,BIT)      REG &= ~(1 << BIT)
#define TOG_BIT(REG,BIT)      REG ^= (1 << BIT)
#define GET_BIT(REG,BIT)      (1 & (REG >> BIT))

#endif /* BIT_MATH_H_ */