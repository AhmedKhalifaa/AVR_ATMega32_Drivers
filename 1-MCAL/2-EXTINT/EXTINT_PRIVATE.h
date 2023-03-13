/*
 * EXTINT_PRIVATE.h
 *
 *  Created on: ١٥‏/٠٢‏/٢٠٢٣
 *      Author: Ahmed Khalifa
 */

#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_

/*Defining The External Interrupts' Registers*/
#define GICR *((volatile uint8*)(0x5B))		//General Interrupt Control Register
#define GIFR *((volatile uint8*)(0x5A))		//General Interrupt Flag Register
#define MCUCR *((volatile uint8*)(0x55))	//MCU Control Register
#define MCUCSR *((volatile uint8*)(0x54))	//MCU Control & Status Register

/*Defining The Interrupt Enable: INT0, INT1 & INT2 Bits' Positions in the GICR*/
#define INT0 6
#define INT1 7
#define INT2 5

/*Defining The Interrupt Flags: INTF0, INTF1 & INTF2 Bits' Positions in the GIFR*/
#define INTF0 6
#define INTF1 7
#define INTF2 5

/*Defining The Interrupt Sense Control Bits: ISC00 & ISC01 for INT0, ISC10 & ISC11 for INT1 Bits' Positions in the MCUCR*/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/*Defining The Interrupt Sense Control Bit: ISC2 for INT2 Bit's Position in the MCUCSR*/
#define ISC2 6

/*Defining The Interrupt Activation Modes*/
#define LOW_LEVEL_TRIG 0
#define BOTH_EDGE_TRIG 1
#define FALLING_EDGE_TRIG 2
#define RISING_EDGE_TRIG 3


#endif /* EXTINT_PRIVATE_H_ */
