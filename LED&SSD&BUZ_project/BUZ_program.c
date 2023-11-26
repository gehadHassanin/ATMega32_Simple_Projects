/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  BUZ_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  BUZ
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "BUZ_interface.h"


void BUZ_voidInit   (BUZ_Type_t BUZ)
{
	DIO_enumSetPinDirection (BUZ.Port, BUZ.Pin, DIO_PIN_OUTPUT);
}

void BUZ_voidOn     (BUZ_Type_t BUZ)
{
	if (BUZ.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue (BUZ.Port, BUZ.Pin, DIO_PIN_HIGH);
	}
	
	else if (BUZ.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue (BUZ.Port, BUZ.Pin, DIO_PIN_LOW);
	}
}

void BUZ_voidOff    (BUZ_Type_t BUZ)
{
	if (BUZ.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue (BUZ.Port, BUZ.Pin, DIO_PIN_LOW);
	}
	
	else if (BUZ.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue (BUZ.Port, BUZ.Pin, DIO_PIN_HIGH);
	}	
}

void BUZ_voidToggle (BUZ_Type_t BUZ)
{
	DIO_enumTogglePinValue (BUZ.Port, BUZ.Pin);
}
