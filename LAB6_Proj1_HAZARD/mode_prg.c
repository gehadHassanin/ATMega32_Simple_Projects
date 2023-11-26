/******************************************************************************/
/*                                                                            */
/* !Layer           : Application Abstraction Layer                           */

/*                                                                            */
/* !Component       : MODE                                                    */
/* !Description     : Hazzard Indicator Function module                       */
/*                                                                            */
/* !Module          : MODE                                                    */
/* !Description     : MODE Module interface                                   */
/*                                                                            */
/* !File            : mode_prg.c                                              */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Induction training exercise project                     */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Coded by        : Gehad Hassanin             !Date : NOV 21, 2023         */
/*                                                                            */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SW_interface.h"
#include "SSD_interface.h"
#include "CLCD_interface.h"


#include "mode_int.h"

/******************************************************************************/

/* Global Variables Definition */
MODE_enutModeState enum_state;
MODE_enutModeState previousState;
/*****************************************************************************************/
extern SSD_Type_t R_SSD ;
extern SSD_Type_t L_SSD ;

extern SW_Type_t R_SW ;
extern SW_Type_t L_SW ;
extern SW_Type_t H_SW ;
/*****************************************************************************************/

/******************************************************************************/
/*! \Description Helper Functions                                             */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void APP_vidSetMode(MODE_enutModeState enutSetMode)
{
	switch(enutSetMode)
	{
	case IDLE :
		CLCD_voidClearScreen();

		SSD_voidDisable          ( R_SSD );
		SSD_voidDisable          ( L_SSD );

		CLCD_voidSetPosition     (CLCD_ROW_1,CLCD_COL_1);
		CLCD_voidSendString      ((u8*)"IDEAL MODE");
		break;
	case RIGHT_BLINK :
		CLCD_voidClearScreen();

		SSD_voidDisable          ( L_SSD );
		SSD_voidEnable           ( R_SSD );
		SSD_voidSendNumber       ( R_SSD , 0 );

		CLCD_voidSetPosition     (CLCD_ROW_1,CLCD_COL_1);
		CLCD_voidSendString      ((u8*)"RIGHT MODE");
		break;
	case LEFT_BLINK :
		CLCD_voidClearScreen();
		SSD_voidDisable          ( R_SSD );
		SSD_voidEnable           ( L_SSD );
		SSD_voidSendNumber       ( L_SSD , 0 );

		CLCD_voidSetPosition     (CLCD_ROW_1,CLCD_COL_1);
		CLCD_voidSendString      ((u8*)"LEFT MODE");
		break;
	case HAZZARD_BLINK :
		CLCD_voidClearScreen();

		CLCD_voidSetPosition     (CLCD_ROW_1,CLCD_COL_1);
		CLCD_voidSendString      ((u8*)"HAZARD MODE");

		SSD_voidEnable           ( R_SSD );
		SSD_voidEnable           ( L_SSD );

		SSD_voidSendNumber       ( L_SSD , 0 );
		SSD_voidSendNumber       ( R_SSD , 0 );
		break;
	}

}

/***************************************/
void MODE_vidIdle (void)
{
	/* Set Mode to IDLE */
	APP_vidSetMode(IDLE);

	/* Check the SWs */
	if (SW_u8GetPressed   ( R_SW )) {

		enum_state = RIGHT_BLINK;
	}

	else if (SW_u8GetPressed   ( L_SW )) {

		enum_state = LEFT_BLINK;
	}

	else if (SW_u8GetPressed   ( H_SW )) {

		previousState = IDLE;
		enum_state = HAZZARD_BLINK;
	}

}
void MODE_vidRightBlink (void)
{
	/* Set Mode to RIGHT_BLINK */
	APP_vidSetMode(RIGHT_BLINK);

	/* Check the SWs */
	if (SW_u8GetPressed   ( L_SW )) {

		enum_state = IDLE;
	}

	else if (SW_u8GetPressed   ( H_SW )) {

		previousState = RIGHT_BLINK;
		enum_state = HAZZARD_BLINK;
	}
}
void MODE_vidLeftBlink (void)
{
	/* Set Mode to LEFT_BLINK */
	APP_vidSetMode(LEFT_BLINK);

	/* Check the SWs */
	if (SW_u8GetPressed   ( R_SW )) {

		enum_state = IDLE;
	}

	else if (SW_u8GetPressed   ( H_SW )) {

		previousState = LEFT_BLINK;
		enum_state = HAZZARD_BLINK;
	}

}
void MODE_vidHazardBlink (void)
{
	/* Set Mode to HAZZARD_BLINK */
	APP_vidSetMode(HAZZARD_BLINK);
	/* Check the SWs */
    if (SW_u8GetPressed   ( H_SW )) {

		enum_state = previousState;
	}
}


/*****************************************************************************************/

/******************************************************************************/
/*! \Description Initialize the MODE driver variables                         */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidInit(void)
{
	/* Set Mode to Default (IDLE) */
	enum_state = IDLE ;
	APP_vidSetMode(IDLE);
}

/******************************************************************************/
/*! \Description The MODE driver task, should be called periodically.
				 This service update the state of all configured push
                 buttons.                                                     */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidTask(void)
{
	/* Check the global enum then call Mode API According to it */

	if (enum_state == IDLE) {
		MODE_vidIdle ();
	}

	else if (enum_state == RIGHT_BLINK) {
		MODE_vidRightBlink ();
	}

	else if (enum_state == LEFT_BLINK) {
		MODE_vidLeftBlink ();
	}

	else if (enum_state == HAZZARD_BLINK) {
		MODE_vidHazardBlink ();
	}

}

/**********************************************************************************************/
