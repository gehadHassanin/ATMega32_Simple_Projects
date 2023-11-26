/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SSD_interface.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  SSD
 *
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

// PINS_Define
#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
#define SSD_PIN4 4
#define SSD_PIN5 5
#define SSD_PIN6 6
#define SSD_PIN7 7

// PORTS_Define
#define SSD_PORTA 0
#define SSD_PORTB 1
#define SSD_PORTC 2
#define SSD_PORTD 3

//Type
#define SSD_COMMON_CATHODE 0
#define SSD_COMMON_ANODE   1

typedef struct {
	
	u8 Type      ;
	u8 DataPort  ;
	u8 EnablePort;
	u8 EnablePin ;
}SSD_Type_t;

// SSD_Operations
void SSD_voidInitDataPort   (SSD_Type_t Copy_structSSDConfig);
void SSD_voidEnable         (SSD_Type_t Copy_structSSDConfig);
void SSD_voidDisable        (SSD_Type_t Copy_structSSDConfig);
void SSD_voidSendNumber     (SSD_Type_t Copy_struct_SSD, u8 Copy_u8Number);
#endif // SSD_INTERFACE_H_
