/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   SW_interface.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  SW
 *
 */

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

// Port_Defines
#define SW_PORTA 0
#define SW_PORTB 1
#define SW_PORTC 2
#define SW_PORTD 3

// Pin_Defines
#define SW_PIN0 0
#define SW_PIN1 1
#define SW_PIN2 2
#define SW_PIN3 3
#define SW_PIN4 4
#define SW_PIN5 5
#define SW_PIN6 6
#define SW_PIN7 7

// Pull_State
#define SW_Int_PULL_UP   0
#define SW_Ext_PULL_UP   1
#define SW_Ext_PULL_DOWN 2
#define SW_FLOATING      3

typedef struct {
	
	u8 Port       ;
	u8 Pin        ;
	u8 Pull_State ;
}SW_Type_t;

void SW_voidInit     (SW_Type_t Copy_structSwConfig);
u8   SW_u8GetPressed (SW_Type_t Copy_structSwConfig);
#endif //SW_INTERFACE_H_
