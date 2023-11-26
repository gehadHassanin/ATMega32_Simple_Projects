#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

SSD_Type_t SSD1 = {SSD_COMMON_CATHODE, SSD_PORTC, SSD_PORTD, SSD_PIN1}; // right
SSD_Type_t SSD2 = {SSD_COMMON_CATHODE, SSD_PORTC, SSD_PORTD, SSD_PIN0}; // left

void main()
{
	u8 right_seg;
	u8 left_seg ;

	SSD_voidInitDataPort   (SSD1);

	SSD_voidDisable        (SSD1);
	SSD_voidDisable        (SSD2);

	while (1)
	{
		for (u8 i = 0; i < 100; ++i) {

			right_seg = i % 10;
			left_seg  = i / 10;

			for (u8 j = 0; j < 50; j++) {

				SSD_voidSendNumber     (SSD1, right_seg) ;
				SSD_voidEnable         (SSD1)            ;
				_delay_ms(10)                            ;
				SSD_voidDisable        (SSD1)            ;

				SSD_voidSendNumber     (SSD2, left_seg) ;
				SSD_voidEnable         (SSD2)           ;
				_delay_ms(10)                           ;
				SSD_voidDisable        (SSD2)           ;
			}
		}
	}
}



