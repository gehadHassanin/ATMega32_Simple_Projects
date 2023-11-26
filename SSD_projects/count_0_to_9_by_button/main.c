/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Using button to count up from 0:9, One count with one click <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */

#include <util\delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SW_interface.h"

SSD_Type_t SSD1 = {SSD_COMMON_CATHODE, SSD_PORTC, SSD_PORTC, SSD_PIN7};
SW_Type_t  SW1  = {SW_PORTD, SW_PIN7, SW_Int_PULL_UP};

void main()
{
	SSD_voidInitDataPort   (SSD1);
	SSD_voidEnable         (SSD1);
	SW_voidInit            (SW1) ;

	u8 count = 0;
	while (1)
	{
		while (count != 10) {

			if (SW_u8GetPressed (SW1)) {

				while (SW_u8GetPressed (SW1)) {
					SSD_voidSendNumber     (SSD1, count);
				}

				count++;
			}
		}

		count = 0;
	}
}
