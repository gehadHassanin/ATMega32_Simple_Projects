/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LED_interface.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  LED
 *
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

// PINS_Define
#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

// PORTS_Define
#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

// Connection_Type
#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0

typedef struct {
	
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_Type_t;

// LED_Operations
void LED_voidInit   (LED_Type_t Copy_structLedConfig);
void LED_voidOn     (LED_Type_t Copy_structLedConfig);
void LED_voidOff    (LED_Type_t Copy_structLedConfig);
void LED_voidToggle (LED_Type_t Copy_structLedConfig);


#endif // LED_INTERFACE_H_
