/*
 * DIO.c
 *
 *  Created on: ١٤‏/٠٢‏/٢٠٢٣
 *      Author: Ahmed Khalifa
 */

/*Standard Types and Bit Math Includes*/
#include "..\STD_TYPE.h"
#include "..\BIT_MATH.h"

/*DIO Headers Includes*/
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"

/*Functions Definitions*/

/*1-DIO_SetPortDirection()*/
void DIO_SetPortDirection(uint8 Port_no, uint8 Port_mode){
	switch (Port_no){
		case DIO_PORTA:
			DDRA=Port_mode;
			break;
		case DIO_PORTB:
			DDRB=Port_mode;
			break;
		case DIO_PORTC:
			DDRC=Port_mode;
			break;
		case DIO_PORTD:
			DDRD=Port_mode;
			break;	}
	}

/*2-DIO_SetPinDirection()*/
void DIO_SetPinDirection(uint8 Pin_no, uint8 Pin_mode){
	switch(Pin_mode){
		case DIO_PIN_INPUT:
			if((Pin_no>=DIO_PINA0) && (Pin_no<=DIO_PINA7)){
				CLR_BIT(DDRA, (Pin_no-(DIO_PORTA*8)));
			}
			else if((Pin_no>=DIO_PINB0) && (Pin_no<=DIO_PINB7)){
				CLR_BIT(DDRB, (Pin_no-(DIO_PORTB*8)));
			}
			else if((Pin_no>=DIO_PINC0) && (Pin_no<=DIO_PINC7)){
				CLR_BIT(DDRC, (Pin_no-(DIO_PORTC*8)));
						}
			else if((Pin_no>=DIO_PIND0) && (Pin_no<=DIO_PIND7)){
				CLR_BIT(DDRD, (Pin_no-(DIO_PORTD*8)));
			}
			break;

		case DIO_PIN_OUTPUT:
			if((Pin_no>=DIO_PINA0) && (Pin_no<=DIO_PINA7)){
				SET_BIT(DDRA, (Pin_no-(DIO_PORTA*8)));
			}
			else if((Pin_no>=DIO_PINB0) && (Pin_no<=DIO_PINB7)){
				SET_BIT(DDRB, (Pin_no-(DIO_PORTB*8)));
			}
			else if((Pin_no>=DIO_PINC0) && (Pin_no<=DIO_PINC7)){
				SET_BIT(DDRC, (Pin_no-(DIO_PORTC*8)));
			}
			else if((Pin_no>=DIO_PIND0) && (Pin_no<=DIO_PIND7)){
				SET_BIT(DDRD, (Pin_no-(DIO_PORTD*8)));
			}
			break;
	}
}

/*3-DIO_SetPortValue()*/
void DIO_SetPortValue(uint8 Port_no, uint8 Port_value){
	switch(Port_no){
		case(DIO_PORTA):
			PORTA=Port_value;
			break;
		case(DIO_PORTB):
			PORTB=Port_value;
			break;
		case(DIO_PORTC):
			PORTC=Port_value;
			break;
		case(DIO_PORTD):
			PORTD=Port_value;
			break;	}
}

/*4-DIO_SetPinValue*/
void DIO_SetPinValue(uint8 Pin_no, uint8 Pin_value){
	switch(Pin_value){
	case DIO_PIN_LOW:
		if((Pin_no>=DIO_PINA0) && (Pin_no<=DIO_PINA7)){
			CLR_BIT(PORTA, (Pin_no-(DIO_PORTA*8)));
		}
		else if((Pin_no>=DIO_PINB0) && (Pin_no<=DIO_PINB7)){
			CLR_BIT(PORTB, (Pin_no-(DIO_PORTB*8)));
		}
		else if((Pin_no>=DIO_PINC0) && (Pin_no<=DIO_PINC7)){
			CLR_BIT(PORTC, (Pin_no-(DIO_PORTC*8)));
					}
		else if((Pin_no>=DIO_PIND0) && (Pin_no<=DIO_PIND7)){
			CLR_BIT(PORTD, (Pin_no-(DIO_PORTD*8)));
		}
		break;

	case DIO_PIN_HIGH:
		if((Pin_no>=DIO_PINA0) && (Pin_no<=DIO_PINA7)){
			SET_BIT(PORTA, (Pin_no-(DIO_PORTA*8)));
		}
		else if((Pin_no>=DIO_PINB0) && (Pin_no<=DIO_PINB7)){
			SET_BIT(PORTB, (Pin_no-(DIO_PORTB*8)));
		}
		else if((Pin_no>=DIO_PINC0) && (Pin_no<=DIO_PINC7)){
			SET_BIT(PORTC, (Pin_no-(DIO_PORTC*8)));
		}
		else if((Pin_no>=DIO_PIND0) && (Pin_no<=DIO_PIND7)){
			SET_BIT(PORTD, (Pin_no-(DIO_PORTD*8)));
		}
		break;
	}
}

/*5-DIO_TogglePort()*/
void DIO_TogglePort(uint8 Port_no){
	switch(Port_no){
		case(DIO_PORTA):
			PORTA^=0xff;
			break;
		case(DIO_PORTB):
			PORTB^=0xff;
			break;
		case(DIO_PORTC):
			PORTC^=0xff;
			break;
		case(DIO_PORTD):
			PORTD^=0xff;
			break;	}
}

/*6-DIO_TogglePin()*/
void DIO_TogglePin(uint8 Pin_no){
	if((Pin_no>=DIO_PINA0) && (Pin_no<=DIO_PINA7)){
		TOG_BIT(PORTA, (Pin_no-(DIO_PORTA*8)));
		}
	else if((Pin_no>=DIO_PINB0) && (Pin_no<=DIO_PINB7)){
		TOG_BIT(PORTB, (Pin_no-(DIO_PORTB*8)));
		}
	else if((Pin_no>=DIO_PINC0) && (Pin_no<=DIO_PINC7)){
		TOG_BIT(PORTC, (Pin_no-(DIO_PORTC*8)));
		}
	else if((Pin_no>=DIO_PIND0) && (Pin_no<=DIO_PIND7)){
		TOG_BIT(PORTD, (Pin_no-(DIO_PORTD*8)));
		}
				}

/*7-DIO_GetPortValue()*/
uint8 DIO_GetPortValue(uint8 Port_no){
	uint8 PortValue=0x00;
	switch(Port_no){
	case DIO_PORTA:
		PortValue=PINA;
		break;
	case DIO_PORTB:
		PortValue=PINB;
		break;
	case DIO_PORTC:
		PortValue=PINC;
		break;
	case DIO_PORTD:
		PortValue=PIND;
		break;
	}
	return PortValue;
}

/*8-DIO_GetPinValue()*/
uint8 DIO_GetPinValue(uint8 Pin_no){
	uint8 PinValue=0;

	if((Pin_no>=DIO_PINA0) && (Pin_no<=DIO_PINA7)){
		PinValue=GET_BIT(PORTA, (Pin_no-(DIO_PORTA*8)));
		}
	else if((Pin_no>=DIO_PINB0) && (Pin_no<=DIO_PINB7)){
		PinValue=GET_BIT(PORTB, (Pin_no-(DIO_PORTB*8)));
		}
	else if((Pin_no>=DIO_PINC0) && (Pin_no<=DIO_PINC7)){
		PinValue=GET_BIT(PORTC, (Pin_no-(DIO_PORTC*8)));
		}
	else if((Pin_no>=DIO_PIND0) && (Pin_no<=DIO_PIND7)){
		PinValue=GET_BIT(PORTD, (Pin_no-(DIO_PORTD*8)));
		}

	return PinValue;
}
