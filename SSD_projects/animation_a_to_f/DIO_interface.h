/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   DIO_interface.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Author  :  Gehad Hassanin
 * Layer   :  MCAL
 * SWC     :  DIO/GPIO
 *
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum {
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;

// PORTS_Defines
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

// PINS_Defines
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

// PIN_Direction
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0

// PIN_Value_Options
#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

// PORT_Direction
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT 0

// PORT_Value_Options
#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW  0

// PINS
DIO_ErrorStatus DIO_enumSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value    );
DIO_ErrorStatus DIO_enumGetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8PtrData );
DIO_ErrorStatus DIO_enumTogglePinValue  (u8 Copy_u8Port, u8 Copy_u8Pin                               );

// PORTS
DIO_ErrorStatus DIO_enumSetPortDirection (u8 Copy_u8Port, u8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPortValue     (u8 Copy_u8Port, u8 Copy_u8Value    );
DIO_ErrorStatus DIO_enumGetPortValue     (u8 Copy_u8Port, u8 *Copy_u8PtrData );
DIO_ErrorStatus DIO_enumTogglePortValue  (u8 Copy_u8Port                               );

// NIBBLES
DIO_ErrorStatus DIO_enumWritHighNibbles (u8 Copy_u8Port, u8 Copy_u8Value);
DIO_ErrorStatus DIO_enumWritLowNibbles  (u8 Copy_u8Port, u8 Copy_u8Value);
#endif // DIO_INTERFACE_H_
