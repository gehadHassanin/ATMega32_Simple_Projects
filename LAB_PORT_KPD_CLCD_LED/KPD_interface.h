/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  KPD_interface.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  KPD
 *
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define NOT_PRESSED 0xff

void KPD_voidInit     (void);
u8   KPD_u8GetPressed (void);
#endif // KPD_INTERFACE_H_
