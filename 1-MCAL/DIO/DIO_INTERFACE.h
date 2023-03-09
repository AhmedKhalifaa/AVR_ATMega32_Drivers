/*
 * DIO_interface.h
 *
 *  Created on: ١٤‏/٠٢‏/٢٠٢٣
 *      Author: Ahmed Khalifa
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/***
 First, We begin by defining PORTs' & PINs':
 1-DEFINITIONS FOR THEIR DIFFERENT OPTIONS (PORTS A-D, PINS 0-7).
 2-DEFINITIONS FOR THEIR DIFFERENT MODES (INPUT/OUTPUT).
 3-DEFINITIONS FOR THEIR DIFFERENT VALUES (HIGH/LOW).
 ***/


/*PORTs' Options Definitions*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/*PORTs' Modes Definitions*/
#define DIO_PORT_INPUT 0x00
#define DI0_PORT_OUTPUT 0xff

/*PINs' Modes Definitions*/
#define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1

/*PORTs' Values Definitions*/
#define DIO_PORT_LOW 0x00
#define DIO_PORT_HIGH 0xff

/*PINs' Values Definitions*/
#define DIO_PIN_LOW 0
#define DIO_PIN_HIGH 1

/*PINs' Options Definitions*/
#define DIO_PINA0 0
#define DIO_PINA1 1
#define DIO_PINA2 2
#define DIO_PINA3 3
#define DIO_PINA4 4
#define DIO_PINA5 5
#define DIO_PINA6 6
#define DIO_PINA7 7
#define DIO_PINB0 8
#define DIO_PINB1 9
#define DIO_PINB2 10
#define DIO_PINB3 11
#define DIO_PINB4 12
#define DIO_PINB5 13
#define DIO_PINB6 14
#define DIO_PINB7 15
#define DIO_PINC0 16
#define DIO_PINC1 17
#define DIO_PINC2 18
#define DIO_PINC3 19
#define DIO_PINC4 20
#define DIO_PINC5 21
#define DIO_PINC6 22
#define DIO_PINC7 23
#define DIO_PIND0 24
#define DIO_PIND1 25
#define DIO_PIND2 26
#define DIO_PIND3 27
#define DIO_PIND4 28
#define DIO_PIND5 29
#define DIO_PIND6 30
#define DIO_PIND7 31



/***
 Second: We Declare the functions that we will use later, which are:
 1-DIO_SetPortDirection(Port_no, Port_mode).
 2-DIO_SetPinDirection(Pin_no, Pin_mode).
 3-DIO_SetPortValue(Port_no, Port_value).
 4-DIO_SetPinValue(Pin_no, Pin_value)
 5-DIO_TogglePort(Port_no)
 6-DIO_TogglePin(Pin_no)
 7-DIO_GetPortValue(Port_no)
 8-DIO_GetPinValue(Pin_no)
 ***/

/***
 Function: DIO_SetPortDirection().
 Parameters: 1-Port Number (A-D). 2-Port Mode (INPUT / OUTPUT).
 Return Type: void.
 ***/
void DIO_SetPortDirection(uint8 Port_no, uint8 Port_mode);

/***
 Function: DIO_SetPinDirection().
 Parameters: 1-Pin Number (Port A-D / Pin 0-7). 2-Pin Mode (INPUT / Output).
 Return Type: void.
 ***/
void DIO_SetPinDirection(uint8 Pin_no, uint8 Pin_mode);

/***
 Function: DIO_SetPortValue().
 Parameters: 1-Port Number (A-D). 2-Port Value (LOW / High).
 Return Type: void.
 ***/
void DIO_SetPortValue(uint8 Port_no, uint8 Port_value);

/***
 Function: DIO_SetPinValue().
 Parameters: 1-Pin Number (Port A-D, Pin 0-7). 2-Pin Value (LOW / High).
 Return Type: void.
 ***/
void DIO_SetPinValue(uint8 Pin_no, uint8 Pin_value);

/***
 Function: DIO_TogglePort().
 Parameters: 1-Port Number (A-D).
 Return Type: Void.
 ***/
void DIO_TogglePort(uint8 Port_no);

/***
 Function: DIO_TogglePin().
 Parameters: 1-Pin Number (Port A-D, Pin 0-7).
 Return Type: Void.
 ***/
void DIO_TogglePin(uint8 Pin_no);

/***
 Function: DIO_GetPortValue().
 Parameters: 1-Port Number (A-D).
 Return Type: Void.
 ***/
uint8 DIO_GetPortValue(uint8 Port_no);

/***
 Function: DIO_GetPinValue().
 Parameters: 1-Pin Number (Port A-D, Pin 0-7).
 Return Type: Void.
 ***/
uint8 DIO_GetPinValue(uint8 Pin_no);


#endif /* DIO_INTERFACE_H_ */
