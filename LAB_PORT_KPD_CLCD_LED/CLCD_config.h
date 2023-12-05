/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_config.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  CLCD
 *
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

//--------------------------------------------------------------------------------

/*
  LCD modes
  
  option :-
  
           1- 8
           2- 4
  
 */
#define CLCD_MODE 8

//--------------------------------------------------------------------------------

/*
  options :- 
 
            1- DIO_PORTA
            2- DIO_PORTB
            3- DIO_PORTC
            4- DIO_PORTD
  
 */
// D0 -----> D7
#define CLCD_DATA_PORT    DIO_PORTB

// RS, RW, EN
#define CLCD_CONTROL_PORT DIO_PORTA

//--------------------------------------------------------------------------------

/*
  options :- 
  
             1- DIO_PIN0
             2- DIO_PIN1
             3- DIO_PIN2
             4- DIO_PIN3
             5- DIO_PIN4
             6- DIO_PIN5
             7- DIO_PIN6
             8- DIO_PIN7
  
 */
#define CONTROL_RS  DIO_PIN0
#define CONTROL_RW  DIO_PIN1
#define CONTROL_EN  DIO_PIN2
//--------------------------------------------------------------------------------


#endif // CLCD_CONFIG_H_
