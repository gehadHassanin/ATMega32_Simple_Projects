/*
 *
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<< Using 8 Switches , each switch run a specific task from the 8 tasks in LED >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"


#define NUM_OF_LEDS    8
#define NUM_OF_SW      8
#define LOOP(N) for(u8 i = 0; i < N; ++i)

// Define All Configuration for LEDs
LED_Type_t Leds[NUM_OF_LEDS] = {
		{LED_PORTD, LED_PIN0, ACTIVE_HIGH},
		{LED_PORTD, LED_PIN1, ACTIVE_HIGH},
		{LED_PORTD, LED_PIN2, ACTIVE_HIGH},
		{LED_PORTD, LED_PIN3, ACTIVE_HIGH},
		{LED_PORTD, LED_PIN4, ACTIVE_HIGH},
		{LED_PORTD, LED_PIN5, ACTIVE_HIGH},
		{LED_PORTD, LED_PIN6, ACTIVE_HIGH},
		{LED_PORTD, LED_PIN7, ACTIVE_HIGH}
};

SW_Type_t SW[NUM_OF_SW] = {
		{SW_PORTA, LED_PIN0, SW_Int_PULL_UP},
		{SW_PORTA, LED_PIN1, SW_Int_PULL_UP},
		{SW_PORTA, LED_PIN2, SW_Int_PULL_UP},
		{SW_PORTA, LED_PIN3, SW_Int_PULL_UP},
		{SW_PORTA, LED_PIN4, SW_Int_PULL_UP},
		{SW_PORTA, LED_PIN5, SW_Int_PULL_UP},
		{SW_PORTA, LED_PIN6, SW_Int_PULL_UP},
		{SW_PORTA, LED_PIN7, SW_Int_PULL_UP}
};

void flashingEvery1000ms              (void);
void shiftingLeftEvery250ms           (void);
void shiftingRightEvery250ms          (void);
void twoLedsConvergeEvery250ms        (void);
void twoLedsDivergeEvery250ms         (void);
void pingPongEvery250ms               (void);
void incrementingEvery250             (void);
void twoLedsConvergeDivergeEvery250ms (void);

void main()
{
	// Initialization Of LEDs
	LOOP(NUM_OF_LEDS) {

		LED_voidInit   (Leds[i]);
	}

	// Initialization Of Switchs
	LOOP(NUM_OF_SW) {

		SW_voidInit    (SW[i]);
	}

	while(1)
	{
		LOOP(NUM_OF_SW) {

			if (SW_u8GetPressed (SW[i])) {

				switch (i)
				{
				case 0 : flashingEvery1000ms              (); break;
				case 1 : shiftingLeftEvery250ms           (); break;
				case 2 : shiftingRightEvery250ms          (); break;
				case 3 : twoLedsConvergeEvery250ms        (); break;
				case 4 : twoLedsDivergeEvery250ms         (); break;
				case 5 : pingPongEvery250ms               (); break;
				case 6 : incrementingEvery250             (); break;
				case 7 : twoLedsConvergeDivergeEvery250ms (); break;
				}
			}
		}
	}
}

void flashingEvery1000ms              (void) {

	LOOP(NUM_OF_LEDS) {

		LED_voidOn (Leds[i]);
	}

	_delay_ms(1000);

	LOOP(NUM_OF_LEDS) {

		LED_voidOff (Leds[i]);
	}
	_delay_ms(1000);
}

void shiftingLeftEvery250ms           (void) {

	LOOP(NUM_OF_LEDS) {

		LED_voidOn     (Leds[i]);
		_delay_ms(250);
		LED_voidOff     (Leds[i]);
	}
}

void shiftingRightEvery250ms          (void) {

	LOOP(NUM_OF_LEDS) {

		LED_voidOn     (Leds[7 - i]);
		_delay_ms(250);
		LED_voidOff     (Leds[7 - i]);
	}
}

void twoLedsConvergeEvery250ms        (void) {

	LOOP(NUM_OF_LEDS / 2) {

		LED_voidOn     (Leds[i]);
		LED_voidOn     (Leds[7 - i]);
		_delay_ms(250);
		LED_voidOff     (Leds[i]);
		LED_voidOff     (Leds[7 - i]);
	}
}

void twoLedsDivergeEvery250ms         (void) {

	LOOP(NUM_OF_LEDS / 2) {

		LED_voidOn     (Leds[i + 4]);
		LED_voidOn     (Leds[3 - i]);
		_delay_ms(250);
		LED_voidOff     (Leds[i + 4]);
		LED_voidOff     (Leds[3 - i]);
	}
}

void pingPongEvery250ms               (void) {

	LOOP(NUM_OF_LEDS) {

		LED_voidOn     (Leds[i]);
		_delay_ms(250);
		LED_voidOff     (Leds[i]);
	}

	LOOP(NUM_OF_LEDS) {

		LED_voidOn     (Leds[7 - i]);
		_delay_ms(250);
		LED_voidOff     (Leds[7 - i]);
	}

	_delay_ms(250);
}

void incrementingEvery250             (void) {

	LOOP(NUM_OF_LEDS) {

		LED_voidOn     (Leds[i]);
		_delay_ms(250);
	}

	LOOP(NUM_OF_LEDS) {

		LED_voidOff     (Leds[i]);
	}

	_delay_ms(250);
}

void twoLedsConvergeDivergeEvery250ms (void) {

	LOOP(NUM_OF_LEDS / 2) {

		LED_voidOn     (Leds[i]);
		LED_voidOn     (Leds[7 - i]);
		_delay_ms(250);
		LED_voidOff     (Leds[i]);
		LED_voidOff     (Leds[7 - i]);
	}

	LOOP(NUM_OF_LEDS / 2) {

		LED_voidOn     (Leds[i + 4]);
		LED_voidOn     (Leds[3 - i]);
		_delay_ms(250);
		LED_voidOff     (Leds[i + 4]);
		LED_voidOff     (Leds[3 - i]);
	}
}

