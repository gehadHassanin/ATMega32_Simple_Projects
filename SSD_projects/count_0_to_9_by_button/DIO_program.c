/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   DIO_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  MCAL
 *    SWC      :  DIO/GPIO
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< IO PIN <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

DIO_ErrorStatus DIO_enumSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7)
	{
		if (Copy_u8Direction == DIO_PIN_OUTPUT)
		{
			switch (Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(DDRA_Register, Copy_u8Pin); break;
			case DIO_PORTB : SET_BIT(DDRB_Register, Copy_u8Pin); break;
			case DIO_PORTC : SET_BIT(DDRC_Register, Copy_u8Pin); break;
			case DIO_PORTD : SET_BIT(DDRD_Register, Copy_u8Pin); break;
			}
		}
		
		else if (Copy_u8Direction == DIO_PIN_INPUT)
		{
			switch (Copy_u8Port)
			{
			case DIO_PORTA : CLR_BIT(DDRA_Register, Copy_u8Pin); break;
			case DIO_PORTB : CLR_BIT(DDRB_Register, Copy_u8Pin); break;
			case DIO_PORTC : CLR_BIT(DDRC_Register, Copy_u8Pin); break;
			case DIO_PORTD : CLR_BIT(DDRD_Register, Copy_u8Pin); break;
			}			
		}
		
		else
		{
			LOC_enumState = DIO_NOK;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState; 
}

DIO_ErrorStatus DIO_enumSetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value    )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7)
	{
		if (Copy_u8Value == DIO_PIN_HIGH)
		{
			switch (Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(PORTA_Register, Copy_u8Pin); break;
			case DIO_PORTB : SET_BIT(PORTB_Register, Copy_u8Pin); break;
			case DIO_PORTC : SET_BIT(PORTC_Register, Copy_u8Pin); break;
			case DIO_PORTD : SET_BIT(PORTD_Register, Copy_u8Pin); break;
			}
		}
		
		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			switch (Copy_u8Port)
			{
			case DIO_PORTA : CLR_BIT(PORTA_Register, Copy_u8Pin); break;
			case DIO_PORTB : CLR_BIT(PORTB_Register, Copy_u8Pin); break;
			case DIO_PORTC : CLR_BIT(PORTC_Register, Copy_u8Pin); break;
			case DIO_PORTD : CLR_BIT(PORTD_Register, Copy_u8Pin); break;
			}			
		}
		
		else
		{
			LOC_enumState = DIO_NOK;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState; 	
}

DIO_ErrorStatus DIO_enumGetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8PtrData )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : *Copy_u8PtrData = GET_BIT(PINA_Register, Copy_u8Pin); break;
		case DIO_PORTB : *Copy_u8PtrData = GET_BIT(PINB_Register, Copy_u8Pin); break;
		case DIO_PORTC : *Copy_u8PtrData = GET_BIT(PINC_Register, Copy_u8Pin); break;
		case DIO_PORTD : *Copy_u8PtrData = GET_BIT(PIND_Register, Copy_u8Pin); break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState; 	
}

DIO_ErrorStatus DIO_enumTogglePinValue  (u8 Copy_u8Port, u8 Copy_u8Pin                               )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : TOG_BIT(PORTA_Register, Copy_u8Pin); break;
		case DIO_PORTB : TOG_BIT(PORTB_Register, Copy_u8Pin); break;
		case DIO_PORTC : TOG_BIT(PORTC_Register, Copy_u8Pin); break;
		case DIO_PORTD : TOG_BIT(PORTD_Register, Copy_u8Pin); break;
		}		
	}

	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState; 
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< IO PORT <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

DIO_ErrorStatus DIO_enumSetPortDirection (u8 Copy_u8Port, u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : DDRA_Register = Copy_u8Direction; break;
		case DIO_PORTB : DDRB_Register = Copy_u8Direction; break;
		case DIO_PORTC : DDRC_Register = Copy_u8Direction; break;
		case DIO_PORTD : DDRD_Register = Copy_u8Direction; break;
		default        : LOC_enumState = DIO_NOK         ; break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState; 
}

DIO_ErrorStatus DIO_enumSetPortValue     (u8 Copy_u8Port, u8 Copy_u8Value    )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : PORTA_Register = Copy_u8Value; break;
		case DIO_PORTB : PORTB_Register = Copy_u8Value; break;
		case DIO_PORTC : PORTC_Register = Copy_u8Value; break;
		case DIO_PORTD : PORTD_Register = Copy_u8Value; break;
		default        : LOC_enumState  = DIO_NOK          ; break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState; 
}

DIO_ErrorStatus DIO_enumGetPortValue     (u8 Copy_u8Port, u8 *Copy_u8PtrData )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : *Copy_u8PtrData = PINA_Register; break;
		case DIO_PORTB : *Copy_u8PtrData = PINB_Register; break;
		case DIO_PORTC : *Copy_u8PtrData = PINC_Register; break;
		case DIO_PORTD : *Copy_u8PtrData = PIND_Register; break;
		default        : LOC_enumState        = DIO_NOK      ; break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumTogglePortValue  (u8 Copy_u8Port                               )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : PORTA_Register = ~ PORTA_Register; break;
		case DIO_PORTB : PORTB_Register = ~ PORTB_Register; break;
		case DIO_PORTC : PORTC_Register = ~ PORTC_Register; break;
		case DIO_PORTD : PORTD_Register = ~ PORTD_Register; break;
		default        : LOC_enumState  = DIO_NOK         ; break;
		}		
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< IO NIBBLES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

DIO_ErrorStatus DIO_enumWritHighNibbles (u8 Copy_u8Port, u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD)
	{
		Copy_u8Value <<= 4;
		
		switch (Copy_u8Port)
		{
		case DIO_PORTA : 
			PORTA_Register &= 0x0f;
			PORTA_Register |= Copy_u8Value;
		    break; 
		case DIO_PORTB :
		    PORTB_Register &= 0x0f;
			PORTB_Register |= Copy_u8Value;
		    break; 
		case DIO_PORTC :
			PORTC_Register &= 0x0f;
			PORTC_Register |= Copy_u8Value;
		    break; 
		case DIO_PORTD :
			PORTD_Register &= 0x0f;
			PORTD_Register |= Copy_u8Value;
		    break; 
		default : LOC_enumState = DIO_NOK;
		    break; 
		}		
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;	
}

DIO_ErrorStatus DIO_enumWritLowNibbles  (u8 Copy_u8Port, u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	if (Copy_u8Port <= DIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : 
			PORTA_Register &= 0xf0;
			PORTA_Register |= Copy_u8Value;
		    break; 
		case DIO_PORTB :
			PORTB_Register &= 0xf0;
			PORTB_Register |= Copy_u8Value;
		    break; 
		case DIO_PORTC :
			PORTC_Register &= 0xf0;
			PORTC_Register |= Copy_u8Value;
		    break; 
		case DIO_PORTD :
			PORTD_Register &= 0xf0;
			PORTD_Register |= Copy_u8Value;
		    break; 
		default : LOC_enumState = DIO_NOK;
		    break; 
		}		
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;	
}
