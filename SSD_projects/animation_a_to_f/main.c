/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Make Animation as one led on a 7S move from a to f <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */

#include <util\delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

SSD_Type_t SSD1 = {SSD_COMMON_CATHODE, SSD_PORTC, SSD_PORTC, SSD_PIN7};

void main()
{
	SSD_voidInitDataPort   (SSD1);
	SSD_voidEnable         (SSD1);

	while (1)
	{
		SSD_voidMakeAnimation (SSD1, 0, 200);
	}
}

