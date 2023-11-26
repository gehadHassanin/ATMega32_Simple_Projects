/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SSD_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  SSD
 *
 */

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
