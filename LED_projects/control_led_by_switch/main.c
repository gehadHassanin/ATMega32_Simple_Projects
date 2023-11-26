// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Pull Up & Pull Down Resistor >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util\delay.h>

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"

LED_Type_t LED = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
SW_Type_t  SW  = {SW_PORTD, SW_PIN0, SW_Ext_PULL_DOWN};

void main()
{
	SW_voidInit  (SW);
    LED_voidInit (LED);

	while(1)
	{
		if (SW_u8GetPressed (SW)) {
			LED_voidOn (LED);
		}

		else {
			LED_voidOff (LED);
		}
	}
}
