/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LED_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  LED
 *
 */
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

#include "LED_private.h"

void LED_voidInit   (LED_Type_t Copy_structLedConfig)
{
	DIO_enumSetPinDirection (Copy_structLedConfig.Port, Copy_structLedConfig.Pin, DIO_PIN_OUTPUT);
}

void LED_voidOn     (LED_Type_t Copy_structLedConfig)
{
	if (Copy_structLedConfig.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue (Copy_structLedConfig.Port, Copy_structLedConfig.Pin, DIO_PIN_HIGH);
	}
	
	else if (Copy_structLedConfig.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue (Copy_structLedConfig.Port, Copy_structLedConfig.Pin, DIO_PIN_LOW);
	}
}

void LED_voidOff    (LED_Type_t Copy_structLedConfig)
{
	if (Copy_structLedConfig.Active_State == ACTIVE_HIGH)
	{
		DIO_enumSetPinValue (Copy_structLedConfig.Port, Copy_structLedConfig.Pin, DIO_PIN_LOW);
	}
	
	else if (Copy_structLedConfig.Active_State == ACTIVE_LOW)
	{
		DIO_enumSetPinValue (Copy_structLedConfig.Port, Copy_structLedConfig.Pin, DIO_PIN_HIGH);
	}	
}

void LED_voidToggle (LED_Type_t Copy_structLedConfig)
{
	DIO_enumTogglePinValue (Copy_structLedConfig.Port, Copy_structLedConfig.Pin);
}
