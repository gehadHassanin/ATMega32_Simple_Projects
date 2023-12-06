/*
 * main.c
 *
 *  Created on : Dec 5, 2023
 *  Author     : Gehad Hassanin
 *
 */

/*! Include compiler types header                                             */

/*     include LIP files   */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*     include MCAL files   */
#include "DIO_interface.h"
#include "PORT_interface.h"

/*     include HAL files   */
#include "LED_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"

/*********************************************/

/*  Definition of leds  */
LED_Type_t leds[8] = {
	                {LED_PORTC, LED_PIN0, ACTIVE_HIGH},
			{LED_PORTC, LED_PIN1, ACTIVE_HIGH},
			{LED_PORTC, LED_PIN2, ACTIVE_HIGH},
			{LED_PORTC, LED_PIN3, ACTIVE_HIGH},
	                {LED_PORTC, LED_PIN4, ACTIVE_HIGH},
			{LED_PORTC, LED_PIN5, ACTIVE_HIGH},
			{LED_PORTC, LED_PIN6, ACTIVE_HIGH},
			{LED_PORTC, LED_PIN7, ACTIVE_HIGH}
} ;

/*********************************************/

void lEDS_vidOn     ( LED_Type_t leds[] ) ;
void lEDS_vidOff    ( LED_Type_t leds[] ) ;
void APP_vidInit    ( void ) ;

/*********************************************/

/*   Global variable Definition              */
u8 LOC_u8Data ;
u8 LOC_u8Iterator ;

/*********************************************/
void main ()
{

	/*      ! Initialize the software     */
	PORT_voidInit () ;
	CLCD_voidInit () ;


	/*
	 *
	 *  $ this line equivalent to Initialize the software
	 *  APP_vidInit ();
	 *
	 */

   /*! Starting the Application                                               */
	while (1)
	{
		LOC_u8Data = KPD_u8GetPressed () ;
		if ( LOC_u8Data != 0xff ) {

			CLCD_voidSendData ( LOC_u8Data ) ;
			switch ( LOC_u8Data ) {

			case '0' :
				lEDS_vidOff ( leds ) ;
				break ;
			case '1' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[0] ) ;
				break ;
			case '2' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[1] ) ;
				break ;
			case '3' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[2] ) ;
				break ;
			case '4' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[3] ) ;
				break ;
			case '5' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[4] ) ;
				break ;
			case '6' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[5] ) ;
				break ;
			case '7' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[6] ) ;
				break ;
			case '8' :
				lEDS_vidOff ( leds ) ;
				LED_voidOn  ( leds[7] ) ;
				break ;
			case '9' :
				lEDS_vidOn ( leds ) ;
				break ;
			}
		}
	}
}

/*      this function used to off all leds       */
void lEDS_vidOff ( LED_Type_t leds[] ) {

	for ( LOC_u8Iterator = 0; LOC_u8Iterator < 9; LOC_u8Iterator++ ) {

		LED_voidOff (leds[LOC_u8Iterator]) ;
	}
}

/*      this function used to ON all leds       */
void lEDS_vidOn ( LED_Type_t leds[] ) {

	for ( LOC_u8Iterator = 0; LOC_u8Iterator < 9; LOC_u8Iterator++ ) {

		LED_voidOn (leds[LOC_u8Iterator]) ;
	}
}

void APP_vidInit ( void ) {

	for ( LOC_u8Iterator = 0; LOC_u8Iterator < 9; LOC_u8Iterator++ ) {

		LED_voidInit   ( leds[LOC_u8Iterator] ) ;
	}
	CLCD_voidInit ();
	KPD_voidInit  ();
}


