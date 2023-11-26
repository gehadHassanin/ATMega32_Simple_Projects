/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   SW_program.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  SW
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"

#include "DIO_interface.h"
#include "SW_interface.h"

void SW_voidInit     (SW_Type_t Copy_structSwConfig)
{
	DIO_enumSetPinDirection (Copy_structSwConfig.Port, Copy_structSwConfig.Pin, DIO_PIN_INPUT);
	
	if (Copy_structSwConfig.Pull_State == SW_Int_PULL_UP) {
		DIO_enumSetPinValue (Copy_structSwConfig.Port, Copy_structSwConfig.Pin, DIO_PIN_HIGH);
	}
}

u8   SW_u8GetPressed (SW_Type_t Copy_structSwConfig)
{
	u8 LOC_u8Result = SW_NOT_PRESSED;
	u8 LOC_u8PinValue  = SW_NOT_PRESSED;
	
	if (Copy_structSwConfig.Pull_State == SW_Int_PULL_UP || Copy_structSwConfig.Pull_State == SW_Ext_PULL_UP) {
		DIO_enumGetPinValue (Copy_structSwConfig.Port, Copy_structSwConfig.Pin, &LOC_u8PinValue);
		
		if (LOC_u8PinValue == 0) {
			LOC_u8Result = SW_PRESSED;
		}
	}
	
	else if (Copy_structSwConfig.Pull_State == SW_Ext_PULL_DOWN) {
		DIO_enumGetPinValue (Copy_structSwConfig.Port, Copy_structSwConfig.Pin, &LOC_u8PinValue);
		
		if (LOC_u8PinValue == 1) {
			LOC_u8Result = SW_PRESSED;
		}		
	}
	
	return LOC_u8Result;
}