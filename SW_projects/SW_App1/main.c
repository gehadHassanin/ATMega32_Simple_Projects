/*
 *
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Applications_On_Leds&SWs >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"

SW_Type_t  SW1  = {SW_PORTA, SW_PIN0, SW_Int_PULL_UP};
LED_Type_t LED1 = {LED_PORTD, LED_PIN0, ACTIVE_HIGH} ;

SW_Type_t  SW2  = {SW_PORTA, SW_PIN7, SW_Int_PULL_UP};
LED_Type_t LED2 = {LED_PORTD, LED_PIN7, ACTIVE_HIGH} ;

void main()
{
	LED_voidInit   (LED1);
	SW_voidInit    (SW1) ;

	LED_voidInit   (LED2);
	SW_voidInit    (SW2) ;

	while(1)
	{
		if (SW_u8GetPressed (SW1)) {
			LED_voidToggle (LED1);
		}

		if (SW_u8GetPressed (SW2)) {
			LED_voidOn     (LED2);
		}

		else if (!SW_u8GetPressed (SW2)) {
			LED_voidOff    (LED2);
		}
	}
}


