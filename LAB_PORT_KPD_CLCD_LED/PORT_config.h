/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   PORT_config.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  MCAL
 *    SWC      :  PORT
 *
 */

 #ifndef PORT_CONFIG_H_
 #define PORT_CONFIG_H_
/******************************************  Pins_Direction ***************************************************/
#define DIO_INPUT  0
#define DIO_OUTPUT 1

/*
 *  $ options :-
 *               1- DIO_INPUT
 *               2- DIO_OUTPUT
 */

#define PORTA_PIN0_DIR      DIO_OUTPUT
#define PORTA_PIN1_DIR      DIO_OUTPUT
#define PORTA_PIN2_DIR      DIO_OUTPUT
#define PORTA_PIN3_DIR      DIO_INPUT
#define PORTA_PIN4_DIR      DIO_INPUT
#define PORTA_PIN5_DIR      DIO_INPUT
#define PORTA_PIN6_DIR      DIO_INPUT
#define PORTA_PIN7_DIR      DIO_INPUT

#define PORTB_PIN0_DIR      DIO_OUTPUT
#define PORTB_PIN1_DIR      DIO_OUTPUT
#define PORTB_PIN2_DIR      DIO_OUTPUT
#define PORTB_PIN3_DIR      DIO_OUTPUT
#define PORTB_PIN4_DIR      DIO_OUTPUT
#define PORTB_PIN5_DIR      DIO_OUTPUT
#define PORTB_PIN6_DIR      DIO_OUTPUT
#define PORTB_PIN7_DIR      DIO_OUTPUT

#define PORTC_PIN0_DIR      DIO_OUTPUT
#define PORTC_PIN1_DIR      DIO_OUTPUT
#define PORTC_PIN2_DIR      DIO_OUTPUT
#define PORTC_PIN3_DIR      DIO_OUTPUT
#define PORTC_PIN4_DIR      DIO_OUTPUT
#define PORTC_PIN5_DIR      DIO_OUTPUT
#define PORTC_PIN6_DIR      DIO_OUTPUT
#define PORTC_PIN7_DIR      DIO_OUTPUT

#define PORTD_PIN0_DIR      DIO_INPUT
#define PORTD_PIN1_DIR      DIO_INPUT
#define PORTD_PIN2_DIR      DIO_INPUT
#define PORTD_PIN3_DIR      DIO_INPUT
#define PORTD_PIN4_DIR      DIO_OUTPUT
#define PORTD_PIN5_DIR      DIO_OUTPUT
#define PORTD_PIN6_DIR      DIO_OUTPUT
#define PORTD_PIN7_DIR      DIO_OUTPUT

/******************************************  Pins_Values  ***************************************************/

/* INPUT Values   */
#define INPUT_FLOATING 0
#define INPUT_PULL_UP  1

/* OUTPUT Values   */
#define OUTPUT_LOW  0
#define OUTPUT_HIGH 1

/*
 *  $ options :-
 *                1- INPUT_FLOATING
 *                2- INPUT_PULL_UP
 *                3- OUTPUT_LOW
 *                4- OUTPUT_HIGH
 *
 */

/*
 *  Hint : This is the initial values for the system we could change it using DIO driver
 */

#define PORTA_PIN0_INITIAL_VALUE      INPUT_FLOATING
#define PORTA_PIN1_INITIAL_VALUE      INPUT_FLOATING
#define PORTA_PIN2_INITIAL_VALUE      INPUT_FLOATING
#define PORTA_PIN3_INITIAL_VALUE      INPUT_FLOATING
#define PORTA_PIN4_INITIAL_VALUE      INPUT_FLOATING
#define PORTA_PIN5_INITIAL_VALUE      INPUT_FLOATING
#define PORTA_PIN6_INITIAL_VALUE      INPUT_FLOATING
#define PORTA_PIN7_INITIAL_VALUE      INPUT_FLOATING

#define PORTB_PIN0_INITIAL_VALUE      INPUT_FLOATING
#define PORTB_PIN1_INITIAL_VALUE      INPUT_FLOATING
#define PORTB_PIN2_INITIAL_VALUE      INPUT_FLOATING
#define PORTB_PIN3_INITIAL_VALUE      INPUT_FLOATING
#define PORTB_PIN4_INITIAL_VALUE      INPUT_FLOATING
#define PORTB_PIN5_INITIAL_VALUE      INPUT_FLOATING
#define PORTB_PIN6_INITIAL_VALUE      INPUT_FLOATING
#define PORTB_PIN7_INITIAL_VALUE      INPUT_FLOATING

#define PORTC_PIN0_INITIAL_VALUE      INPUT_FLOATING
#define PORTC_PIN1_INITIAL_VALUE      INPUT_FLOATING
#define PORTC_PIN2_INITIAL_VALUE      INPUT_FLOATING
#define PORTC_PIN3_INITIAL_VALUE      INPUT_FLOATING
#define PORTC_PIN4_INITIAL_VALUE      INPUT_FLOATING
#define PORTC_PIN5_INITIAL_VALUE      INPUT_FLOATING
#define PORTC_PIN6_INITIAL_VALUE      INPUT_FLOATING
#define PORTC_PIN7_INITIAL_VALUE      INPUT_FLOATING

#define PORTD_PIN0_INITIAL_VALUE      OUTPUT_HIGH
#define PORTD_PIN1_INITIAL_VALUE      OUTPUT_HIGH
#define PORTD_PIN2_INITIAL_VALUE      OUTPUT_HIGH
#define PORTD_PIN3_INITIAL_VALUE      OUTPUT_HIGH
#define PORTD_PIN4_INITIAL_VALUE      OUTPUT_HIGH
#define PORTD_PIN5_INITIAL_VALUE      OUTPUT_HIGH
#define PORTD_PIN6_INITIAL_VALUE      OUTPUT_HIGH
#define PORTD_PIN7_INITIAL_VALUE      OUTPUT_HIGH
 #endif // PORT_CONFIG_H_
