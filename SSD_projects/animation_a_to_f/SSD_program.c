/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SSD_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  SSD
 *
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"

u8 LOC_u8Numbers[10] =  SSD_NUMBER_ARR;

void SSD_voidInitDataPort   (SSD_Type_t Copy_structSSDConfig)
{
	DIO_enumSetPortDirection (Copy_structSSDConfig.DataPort, DIO_PORT_OUTPUT);
}

void SSD_voidEnable         (SSD_Type_t Copy_structSSDConfig)
{
	if (Copy_structSSDConfig.Type == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPinDirection (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue     (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_LOW);
	}

	else if (Copy_structSSDConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enumSetPinDirection (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue     (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_HIGH);
	}
}

void SSD_voidDisable        (SSD_Type_t Copy_structSSDConfig)
{
	if (Copy_structSSDConfig.Type == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPinDirection (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue     (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_HIGH);
	}

	else if (Copy_structSSDConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enumSetPinDirection (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_OUTPUT);
		DIO_enumSetPinValue     (Copy_structSSDConfig.EnablePort, Copy_structSSDConfig.EnablePin, DIO_PIN_LOW);
	}
}

void SSD_voidSendNumber     (SSD_Type_t Copy_structSSDConfig, u8 Copy_u8Number)
{
	if (Copy_structSSDConfig.Type == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPortValue     (Copy_structSSDConfig.EnablePort, LOC_u8Numbers[Copy_u8Number]);
	}

	else if (Copy_structSSDConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enumSetPortValue     (Copy_structSSDConfig.EnablePort, ~(LOC_u8Numbers[Copy_u8Number]));
	}
}

void SSD_voidMakeAnimation (SSD_Type_t Copy_structSSDConfig, u8 Copy_u8Number, u8 Copy_u8Time_ms)
{
	if (Copy_structSSDConfig.Type == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPortValue     (Copy_structSSDConfig.EnablePort, DIO_PORT_LOW);

		for (u8 i = 0; i < 8; ++i) {
			if (LOC_u8Numbers[Copy_u8Number] & (1 << i)) {
				DIO_enumSetPinValue (Copy_structSSDConfig.EnablePort, i, DIO_PIN_HIGH);
				_delay_ms(Copy_u8Time_ms)                                                    ;
				DIO_enumSetPinValue (Copy_structSSDConfig.EnablePort, i, DIO_PIN_LOW) ;
			}
		}
	}

	else if (Copy_structSSDConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enumSetPortValue     (Copy_structSSDConfig.EnablePort, DIO_PORT_HIGH);

		for (u8 i = 0; i < 8; ++i) {
			if (LOC_u8Numbers[Copy_u8Number] & (1 << i)) {
				DIO_enumSetPinValue (Copy_structSSDConfig.EnablePort, i, DIO_PIN_LOW);
				_delay_ms(Copy_u8Time_ms);                                                   ;
				DIO_enumSetPinValue (Copy_structSSDConfig.EnablePort, i, DIO_PIN_HIGH) ;
			}
		}
	}

}
