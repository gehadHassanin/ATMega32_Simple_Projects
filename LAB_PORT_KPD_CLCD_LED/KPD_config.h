/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  KPD_config.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  KPD
 *
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/********************************************************************/

#define KPD_ROW_INIT  0
#define KPD_ROW_END   3

#define KPD_COL_INIT  4
#define KPD_COL_END   7

/********************************************************************/

u8 KPD_u8Button [4][4] = { //  C0 , C1 , C2 , C3
		                     { '7', '8', '9', '/' }, // R0
							 { '4', '5', '6', '*' }, // R1
							 { '1', '2', '3', '-' }, // R2
							 { '?', '0', '=', '+' }, // R3				
};

/********************************************************************/

/*
 * 
 *  options :-
 *             1- DIO_PORTA
 *             1- DIO_PORTB
 *             1- DIO_PORTC
 *             1- DIO_PORTD
 *             
 */

#define KPD_PORT DIO_PORTD

/********************************************************************/

/*
 * 
 *  options :- 
 *             1- DIO_PIN0
 *             2- DIO_PIN1
 *             3- DIO_PIN2
 *             4- DIO_PIN3
 *             5- DIO_PIN4
 *             6- DIO_PIN5
 *             7- DIO_PIN6
 *             8- DIO_PIN7
 */

#define KPD_R0 DIO_PIN0
#define KPD_R1 DIO_PIN1
#define KPD_R2 DIO_PIN2
#define KPD_R3 DIO_PIN3

#define KPD_C0 DIO_PIN4
#define KPD_C1 DIO_PIN5
#define KPD_C2 DIO_PIN6
#define KPD_C3 DIO_PIN7

/********************************************************************/ 

#endif // KPD_CONFIG_H_
