/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LED_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  LED
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

#include "LED_private.h"

void LED_voidInit   (LED_Type_t LED)
{
	DIO_enumSetPinDirection (LED.Port, LED.Pin, DIO_PIN_OUTPUT);
}

void LED_voidOn     (LED_Type_t LED)
{
	if (LED.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue (LED.Port, LED.Pin, DIO_PIN_HIGH);
	}
	
	else if (LED.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue (LED.Port, LED.Pin, DIO_PIN_LOW);
	}
}

void LED_voidOff    (LED_Type_t LED)
{
	if (LED.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue (LED.Port, LED.Pin, DIO_PIN_LOW);
	}
	
	else if (LED.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue (LED.Port, LED.Pin, DIO_PIN_HIGH);
	}	
}

void LED_voidToggle (LED_Type_t LED)
{
	DIO_enumTogglePinValue (LED.Port, LED.Pin);
}
