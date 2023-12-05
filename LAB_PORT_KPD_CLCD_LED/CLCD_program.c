/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  CLCD
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_extrachar.h"

void CLCD_voidSendData    (u8 Copy_u8Data       )
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    8 Bits Mode    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    #if CLCD_MODE == 8
	
	DIO_enumSetPortValue     (CLCD_DATA_PORT, Copy_u8Data                   );
	DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RS, DIO_PIN_HIGH   );
	DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RW, DIO_PIN_LOW    );
	CLCD_voidSendFallingEdge ();
	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    4 Bits Mode    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    #elif  CLCD_MODE == 4

	DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RS, DIO_PIN_HIGH   );
	DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RW, DIO_PIN_LOW    );

	DIO_enumWritHighNibbles (CLCD_DATA_PORT, Copy_u8Data >> 4);
	CLCD_voidSendFallingEdge ();

	DIO_enumWritHighNibbles (CLCD_DATA_PORT, Copy_u8Data);
	CLCD_voidSendFallingEdge ();

	#endif
	
	_delay_ms(1);
	
}

void CLCD_voidSendCommand (u8 Copy_u8Command    )
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    8 Bits Mode    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    #if CLCD_MODE == 8

    DIO_enumSetPortValue     (CLCD_DATA_PORT   , Copy_u8Command            );
    DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RS, DIO_PIN_LOW    );
    DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RW, DIO_PIN_LOW    );
    CLCD_voidSendFallingEdge ();

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    4 Bits Mode    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    #elif  CLCD_MODE == 4

	DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RS, DIO_PIN_LOW    );
	DIO_enumSetPinValue      (CLCD_CONTROL_PORT, CONTROL_RW, DIO_PIN_LOW    );

	DIO_enumWritHighNibbles (CLCD_DATA_PORT, Copy_u8Command >> 4);
	CLCD_voidSendFallingEdge ();

	DIO_enumWritHighNibbles (CLCD_DATA_PORT, Copy_u8Command);
	CLCD_voidSendFallingEdge ();

    #endif
    
    _delay_ms(1);
}

void CLCD_voidInit        (void                 )
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    8 Bits Mode    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    #if CLCD_MODE == 8
	
	/*
	 *   delay must be more than 30ms after VDD rises to 4.5V
	 */
	_delay_ms(50);
	
	/*                         All pins as output pins                   */
	DIO_enumSetPortDirection (CLCD_DATA_PORT   , DIO_PORT_OUTPUT           );
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, CONTROL_RS, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, CONTROL_RW, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, CONTROL_EN, DIO_PIN_OUTPUT);
	
	/* Return cursor to the first position on the first line  */
	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(1);
	
	/*   FUNCTION SET Command : 2 lines , 5*8 font size  */
	CLCD_voidSendCommand (EIGHT_BITS);
	_delay_ms(1);
	
	/*   Disblay => ON  &  Cursor => OFF  */
	CLCD_voidSendCommand (lcd_DisblayOn_CursorOff);
	_delay_ms(1);
	
	/*   Disblay Clear  */
	CLCD_voidClearScreen ();
	
	/*  Entry Mode Set  */
	CLCD_voidSendCommand (lcd_EntryMode);
	_delay_ms(1);
	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    4 Bits Mode    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    #elif CLCD_MODE == 4

	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, DIO_PIN7, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, DIO_PIN4, DIO_PIN_OUTPUT);

	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, CONTROL_RS, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, CONTROL_RW, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT, CONTROL_EN, DIO_PIN_OUTPUT);

	/* Return cursor to the first position on the first line  */
	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(1);

	/*   FUNCTION SET Command : 2 lines , 5*8 font size  */
	CLCD_voidSendCommand (EIGHT_BITS);
	_delay_ms(1);

	/*   Disblay => ON  &  Cursor => OFF  */
	CLCD_voidSendCommand (lcd_DisblayOn_CursorOff);
	_delay_ms(1);

	/*   Disblay Clear  */
	CLCD_voidClearScreen ();

	/*  Entry Mode Set  */
	CLCD_voidSendCommand (lcd_EntryMode);
	_delay_ms(1);

    #endif
}

void CLCD_voidSendString  (u8 *Copy_u8PtrString )
{
	u8 LOC_u8Iteration = 0;
	while (Copy_u8PtrString[LOC_u8Iteration] != '\0') {
		
		CLCD_voidSendData (Copy_u8PtrString[LOC_u8Iteration]);
		LOC_u8Iteration ++;
	}
}

void CLCD_voidSendNumber    (u64 Copy_u64Number          )
{
	u64 Copy_u64Reversed = 1;
	
	if (Copy_u64Number == 0) {
		
		CLCD_voidSendData ('0');	
	}
	
	else {
		
		while (Copy_u64Number != 0) {
			
			Copy_u64Reversed = (Copy_u64Reversed * 10) + (Copy_u64Number % 10);
			Copy_u64Number /= 10;
		}
		
		while (Copy_u64Number != 1) {
			
			CLCD_voidSendData ((Copy_u64Reversed % 10) + '0');
		}
	}
	
}

void CLCD_voidSetPosition (u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 LOC_u8data;
	if (Copy_u8Row > 2 || Copy_u8Row < 1 || Copy_u8Col > 16 || Copy_u8Col < 1) {
		
		LOC_u8data = lcd_SetCursor; // first location
	}
	
	else if (Copy_u8Row == CLCD_ROW_1) {
		
		LOC_u8data = ((lcd_SetCursor) + (Copy_u8Col - 1)); // 0x80+col-1
	}
	
	else if (Copy_u8Row == CLCD_ROW_2) {
		
		LOC_u8data = ((lcd_SetCursor + 64) + (Copy_u8Col - 1)); // 0x80+64+col-1
	}
	
	CLCD_voidSendCommand (LOC_u8data);
	_delay_ms(1);
}

void CLCD_voidSendExtraChar (u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 LOC_u8Iterator;
	
	// Go to CGRAM
	CLCD_voidSendCommand (lcd_CGRAM); // cursor refer to first Address in GCRAM
	
	// Draw Character in GCRAM
	for (LOC_u8Iterator = 0; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]); LOC_u8Iterator++) {
		
		CLCD_voidSendData (CLCD_u8ExtraChar[LOC_u8Iterator]);
	}
	
	// cursor back to DDRAM
	CLCD_voidSetPosition   (Copy_u8Row, Copy_u8Col);
	
	// send character Address
	for (LOC_u8Iterator = 0; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]); LOC_u8Iterator++) {
		
		CLCD_voidSendData (LOC_u8Iterator);
	}	
	
}

/*-----------------------------------------------------------------------------------------------*/

void CLCD_voidClearScreen (void                 )
{
	CLCD_voidSendCommand (lcd_Clear);
	_delay_ms(1);	
}

static CLCD_voidSendFallingEdge (void           )
{
	DIO_enumSetPinValue (CLCD_CONTROL_PORT, CONTROL_EN, DIO_PIN_HIGH   );
	_delay_ms(1);
	DIO_enumSetPinValue (CLCD_CONTROL_PORT, CONTROL_EN, DIO_PIN_LOW    );
	_delay_ms(1);
}
