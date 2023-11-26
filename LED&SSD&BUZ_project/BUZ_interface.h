/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  BUZ_interface.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  BUZ
 *
 */

#ifndef BUZ_INTERFACE_H_
#define BUZ_INTERFACE_H_

// PINS_Define
#define BUZ_PIN0 0
#define BUZ_PIN1 1
#define BUZ_PIN2 2
#define BUZ_PIN3 3
#define BUZ_PIN4 4
#define BUZ_PIN5 5
#define BUZ_PIN6 6
#define BUZ_PIN7 7

// PORTS_Define
#define BUZ_PORTA 0
#define BUZ_PORTB 1
#define BUZ_PORTC 2
#define BUZ_PORTD 3

// Connection_Type
#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0

typedef struct {
	
	u8 Port;
	u8 Pin;
	u8 Active_State;
}BUZ_Type_t;

// BUZ_Operations
void BUZ_voidInit   (BUZ_Type_t BUZ);
void BUZ_voidOn     (BUZ_Type_t BUZ);
void BUZ_voidOff    (BUZ_Type_t BUZ);
void BUZ_voidToggle (BUZ_Type_t BUZ);


#endif // BUZ_INTERFACE_H_
