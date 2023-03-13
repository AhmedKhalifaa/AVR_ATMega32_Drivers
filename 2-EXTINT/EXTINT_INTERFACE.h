/*
 * EXTINT_INTERFACE.h
 *
 *  Created on: ١٥‏/٠٢‏/٢٠٢٣
 *      Author: Ahmed Khalifa
 */

#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_


/*First, we will define ISR function like Macro.
 We used the Attribute ((signal)) to indicate that the call back can be generated using external
 signal, so when the context switching happens, to avoid data loss, the compiler pushes necessary
 registers into the stack, and after the ISR is served, this data is popped again.
 We added the __VA_ARGS__ in case we wanted to add other attributes like ISR_NOBLOCK or ISR_NAKED... etc.
 */

#define ISR(vector,...)\
void vector(void) __attribute__((signal))__VA_ARGS__;\
void vector(void)

/*We then define the EXTINT Vectors*/
#define INT0_VECTOR __vector1_
#define INT1_VECTOR __vector2_
#define INT2_VECTOR __vector3_


/***
 We will now define Several functions for each interrupt, which are:
 1-EXTINT_Enable(Interrupt_no).
 2-EXTINT_Disable(Interrupt_no).
 3-EXTINT_SetTrigger(Interrupt_no, Trigger_mode)
 4-EXTINT_SetCallBack(uint8 Interrupt_no, void(*Local_ptr)(void))
 ***/

/***
 Function: EXTINT_Enable().
 Parameters: 1-Interrupt Number (INT0 - INT2).
 Return Type: void.
 ***/
void EXTINT_Enable(uint8 Interrupt_no);

/***
 Function: EXTINT_DISABLE().
 Parameters: 1-Interrupt Number (INT0 - INT2).
 Return Type: void.
 ***/
void EXTINT_Disable(uint8 Interrupt_no);

/***
 Function:  3-EXTINT_SetTrigger().
 Parameters: 1-Interrupt Number (INT0 - INT2). 2-Trigger Mode (LOW LEVEL, EDGE, FALLING EDGE & RISING EDGE).
 Return Type: void.
 ***/
void EXTINT_SetTrigger(uint8 Interrupt_no, uint8 Trigger_mode);

/***
 Function: EXTINT_SetCallBack().
 Parameters: 1-Interrupt Number (INT0 - INT2). 2-Void Pointer to the first line in the ISR.
 Return Type: void.
 ***/
void EXTINT_SetCallBack(uint8 Interrupt_no, void(*Local_ptr)(void));


#endif /* EXTINT_INTERFACE_H_ */
