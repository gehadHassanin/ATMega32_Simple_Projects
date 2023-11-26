#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SSD_interface.h"
#include "BUZ_interface.h"
#include "SW_interface.h"

#define NUM_OF_LEDS    8
#define LOOP(N) for(u8 i = 0; i < N; ++i)

// Define All Configuration for LEDs
LED_Type_t Leds[NUM_OF_LEDS] = {
		              {LED_PORTD, LED_PIN0, ACTIVE_HIGH},
		              {LED_PORTD, LED_PIN1, ACTIVE_HIGH},
			      {LED_PORTD, LED_PIN2, ACTIVE_HIGH},
			      {LED_PORTD, LED_PIN3, ACTIVE_HIGH},
			      {LED_PORTD, LED_PIN4, ACTIVE_HIGH},
			      {LED_PORTD, LED_PIN5, ACTIVE_HIGH ,
                              {LED_PORTD, LED_PIN6, ACTIVE_HIGH},
			      {LED_PORTD, LED_PIN7, ACTIVE_HIGH}
};

SSD_Type_t SSD1 = {SSD_COMMON_CATHODE, SSD_PORTA, SSD_PORTA, SSD_PIN7};
BUZ_Type_t BUZ1 = {LED_PORTC, LED_PIN7, ACTIVE_HIGH}                  ;
SW_Typed_t SW1  = {SW_PORTC, SW_PIN0, SW_Int_PULL_UP}                 ;

void main()
{
	SSD_voidInitDataPort   (SSD1);
	SSD_voidEnable         (SSD1);
	BUZ_voidInit           (BUZ1);
	SW_voidInit            (SW1) ;

    LOOP(NUM_OF_LEDS) {
    	LED_voidInit   (Leds[i]);
    }

    while (1)
    {
    	LOOP(NUM_OF_LEDS + 1) {
		
    		if (i == 0) {
			LOOP(8) {
				LED_voidOff   (Leds[i]);
    	                }

    			BUZ_voidOff            (BUZ1);
    			SSD_voidSendNumber     (SSD1, i);
    			_delay_ms(1000);
    		}

    		else {
    			LED_voidOn             (Leds[i - 1]);
    			SSD_voidSendNumber     (SSD1, i);
    			_delay_ms(1000);
    		}
	}

    	BUZ_voidOn     (BUZ1);
    	_delay_ms(1000);
    }
}

