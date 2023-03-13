/*
 * EXTINT.c
 *
 *  Created on: ١٦‏/٠٢‏/٢٠٢٣
 *      Author: Ahmed Khalifa
 */

/*Standard Types and Bit Math Includes*/
#include "..\STD_TYPE.h"
#include "..\BIT_MATH.h"

/*DIO Headers Includes*/
#include "EXTINT_CONFIGURATION.h"
#include "EXTINT_PRIVATE.h"
#include "EXTINT_INTERFACE.h"




/*We will start by defining pointers to the callback functions*/
static void (*EXTINT0_CallBack)(void)=Null;
static void (*EXTINT1_CallBack)(void)=Null;
static void (*EXTINT2_CallBack)(void)=Null;

/*Functions Definitions*/

/*1-EXTINT_Enable()*/
void EXTINT_Enable(uint8 Interrupt_no){
	switch(Interrupt_no){
	case INT0:
		SET_BIT(GICR,INT0);
		break;
	case INT1:
		SET_BIT(GICR,INT1);
		break;
	case INT2:
		SET_BIT(GICR,INT2);
		break;
	}
}

/*2-EXTINT_Disable()*/
void EXTINT_Disable(uint8 Interrupt_no){
	switch(Interrupt_no){
	case INT0:
		CLR_BIT(GICR,INT0);
		break;


	case INT1:
		CLR_BIT(GICR,INT1);
		break;

	case INT2:
		CLR_BIT(GICR,INT2);
		break;
		}
}

/*3-EXTINT_SetTrigger()*/
void EXTINT_SetTrigger(uint8 Interrupt_no, uint8 Trigger_mode){
	switch(Interrupt_no){
	case INT0:
		switch(Trigger_mode){
		case LOW_LEVEL_TRIG:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		case BOTH_EDGE_TRIG:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		case FALLING_EDGE_TRIG:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case RISING_EDGE_TRIG:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;		}
		break;


		case INT1:
			switch(Trigger_mode){
			case LOW_LEVEL_TRIG:
				CLR_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
			case BOTH_EDGE_TRIG:
				SET_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
			case FALLING_EDGE_TRIG:
				CLR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
			case RISING_EDGE_TRIG:
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;	}
			break;
		case INT2:
			switch(Trigger_mode){
			case FALLING_EDGE_TRIG:
				CLR_BIT(MCUCSR,ISC2);
				break;
			case RISING_EDGE_TRIG:
				SET_BIT(MCUCSR,ISC2);
				break;
			default:
				CLR_BIT(MCUCSR,ISC2);
				break;
			}
			break;
		}

	}


/*4-EXTINT_SetCallBack()*/
void EXTINT_SetCallBack(uint8 Interrupt_no, void(*Local_ptr)(void)){
	switch(Interrupt_no){
		case INT0:
			EXTINT0_CallBack=Local_ptr;
			break;
		case INT1:
			EXTINT1_CallBack=Local_ptr;
			break;

		case INT2:
			EXTINT2_CallBack=Local_ptr;
			break;
	}
}


/*ISR Functions*/

ISR(INT0_VECTOR){
	if(EXTINT0_CallBack!=Null){
		EXTINT0_CallBack();
	}
}

ISR(INT1_VECTOR){
	if(EXTINT1_CallBack!=Null){
		EXTINT1_CallBack();
	}
}

ISR(INT2_VECTOR){
	if(EXTINT2_CallBack!=Null){
		EXTINT2_CallBack();
	}
}

/*How all this works:
 The user uses the EXTINT_SetCallBack() function to point the interrupt callback function
 to the function which he wants to execute upon the Interrupt signaling.
 When an external signal happens, the ISR starts it's routine, then checks to see if the EXTINT_CallBack()
 function actually points to a function (The callback function set by the user), if it's not NULL, the
 callback function is called from within and the it's executed, if not (The CallBack function points
 to NULL), then there's no function to be executed, and an error should be raised (or a default action
 for bad interrupts).
 */

