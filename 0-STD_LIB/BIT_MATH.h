/*
 * BIT_MATH.h
 *
 *  Created on: ١٤‏/٠٢‏/٢٠٢٣
 *      Author: a4c
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Mask Macro*/
#define MASK(X) 1<<X

/*Bit Manipulation Macros*/
#define SET_BIT(REG,BIT) REG|=MASK(BIT)
#define CLR_BIT(REG,BIT) REG&=~MASK(BIT)
#define TOG_BIT(REG,BIT) REG^=MASK(BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)


#endif /* BIT_MATH_H_ */
