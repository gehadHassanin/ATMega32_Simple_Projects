/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< display numbers from 0:9 (Count up) then from 9:0 (count down) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */

#include <util\delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

#define LOOP(N) for(u8 i = 0; i < N; ++i)

SSD_Type_t SSD1 = {SSD_COMMON_CATHODE, SSD_PORTA, SSD_PORTA, SSD_PIN7};

void main()
{
	SSD_voidInitDataPort   (SSD1);
	SSD_voidEnable         (SSD1);

	while (1)
	{
		LOOP(10) {

			SSD_voidSendNumber     (SSD1, i);
			_delay_ms(1000);
		}

		LOOP(10) {

			SSD_voidSendNumber     (SSD1, 9 - i);
			_delay_ms(1000);
		}
	}
}
