/*
 * BIT_MATH.h
 *
 *  Created on: Aug 22, 2023
 *      Author: marwa
 */

#ifndef _LIB_BIT_MATH_H_
#define _LIB_BIT_MATH_H_


#define GET_BIT(var,Bitno)       (var & (1 << Bitno)) >> Bitno

#define SET_BIT(var,Bitno)       (var |= (1 << Bitno))
#define CLR_BIT(var,Bitno)       (var &= (~(1 << Bitno)))
#define TOGGLE_BIT(var,Bitno)    (var ^= (1 << Bitno))

#endif /* 4_LIB_BIT_MATH_H_ */
