/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  KPD_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  KPD
 *
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"

void KPD_voidInit     (void) {
	
	/*                 connect the pins of the columns as output pins (HIGH)                    */
	
	DIO_enumSetPinDirection ( KPD_PORT, KPD_C0, DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection ( KPD_PORT, KPD_C1, DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection ( KPD_PORT, KPD_C2, DIO_PIN_OUTPUT );
	DIO_enumSetPinDirection ( KPD_PORT, KPD_C3, DIO_PIN_OUTPUT );
	
	DIO_enumSetPinValue ( KPD_PORT, KPD_C0, DIO_PIN_HIGH );
	DIO_enumSetPinValue ( KPD_PORT, KPD_C1, DIO_PIN_HIGH );
	DIO_enumSetPinValue ( KPD_PORT, KPD_C2, DIO_PIN_HIGH );
	DIO_enumSetPinValue ( KPD_PORT, KPD_C3, DIO_PIN_HIGH );
	
	/*                connect Internal pull up for the pins of the rows                         */
	
	DIO_enumSetPinDirection ( KPD_PORT, KPD_R0, DIO_PIN_INPUT );
	DIO_enumSetPinDirection ( KPD_PORT, KPD_R1, DIO_PIN_INPUT );
	DIO_enumSetPinDirection ( KPD_PORT, KPD_R2, DIO_PIN_INPUT );
	DIO_enumSetPinDirection ( KPD_PORT, KPD_R3, DIO_PIN_INPUT );
	
	DIO_enumSetPinValue ( KPD_PORT, KPD_R0, DIO_PIN_HIGH );
	DIO_enumSetPinValue ( KPD_PORT, KPD_R1, DIO_PIN_HIGH );
	DIO_enumSetPinValue ( KPD_PORT, KPD_R2, DIO_PIN_HIGH );
	DIO_enumSetPinValue ( KPD_PORT, KPD_R3, DIO_PIN_HIGH );

}

u8   KPD_u8GetPressed (void) {
	
	u8 LOC_u8ReturnData = NOT_PRESSED;
	u8 LOC_u8GetPressed;
	
	u8 LOC_u8ROW;
	u8 LOC_u8COL;
	
	for ( LOC_u8COL = KPD_COL_INIT; LOC_u8COL < KPD_COL_END + 1; LOC_u8COL++) {
		
		DIO_enumSetPinValue ( KPD_PORT, LOC_u8COL, DIO_PIN_LOW );
		
		for ( LOC_u8ROW = KPD_ROW_INIT; LOC_u8ROW < KPD_ROW_END + 1; LOC_u8ROW++) {
			
			DIO_enumGetPinValue ( KPD_PORT, LOC_u8ROW, &LOC_u8GetPressed );
			
			if ( LOC_u8GetPressed == 0) {
				
				_delay_ms(50); // delay for bouncing
				DIO_enumGetPinValue ( KPD_PORT, LOC_u8ROW, &LOC_u8GetPressed ); // to make sure that the button is pressed & check again
				
				if ( LOC_u8GetPressed == 0) {
					
					LOC_u8ReturnData = KPD_u8Button [LOC_u8ROW - KPD_ROW_INIT] [LOC_u8COL - KPD_COL_INIT];
				}
				
				// stay here if the button is pressed   # we could put delay 200 ms instead of that
				DIO_enumGetPinValue ( KPD_PORT, LOC_u8ROW, &LOC_u8GetPressed );
				while (DIO_PIN_LOW == LOC_u8GetPressed) {
					
					DIO_enumGetPinValue ( KPD_PORT, LOC_u8ROW, &LOC_u8GetPressed );	
				}

				break;
			}
		}	
		
		DIO_enumSetPinValue ( KPD_PORT, LOC_u8COL, DIO_PIN_HIGH );
	}
	
	return LOC_u8ReturnData; 
}

