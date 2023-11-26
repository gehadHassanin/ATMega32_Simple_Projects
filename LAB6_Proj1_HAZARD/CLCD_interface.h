/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_interface.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 *    Author   :  Gehad Hassanin
 *    Layer    :  HAL
 *    SWC      :  CLCD
 *
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "CLCD_config.h"

/***************************************************************/

#if CLCD_MODE == 8 
#define EIGHT_BITS                  0x38
#elif CLCD_MODE == 4
#define FOUR_BITS                   0x28
#endif

/***************************************************************/

#define lcd_DisblayOn_CursorOff     0x0c  // display on ,  cursor off , don't blink character
#define lcd_DisblayOn_CursorOn      0x0e  // display on ,  cursor on  , don't blink character
#define lcd_DisblayOff_CursorOff    0x08  // display off,  cursor off , don't blink character
#define lcd_Clear                   0x01  // replace all characters with ASCII => space character 
#define lcd_EntryMode               0x06  // shift cursor from left to right
#define lcd_Home                    0x02  // Return cursor to the first position on the first line
#define lcd_SetCursor               0x80  // Set Cursor Position
#define lcd_CGRAM                   0x40  // first position in CGRAM

/***************************************************************/

#define CLCD_ROW_1      1
#define CLCD_ROW_2      2

#define CLCD_COL_1   1
#define CLCD_COL_2   2
#define CLCD_COL_3   3
#define CLCD_COL_4   4
#define CLCD_COL_5   5
#define CLCD_COL_6   6
#define CLCD_COL_7   7
#define CLCD_COL_8   8
#define CLCD_COL_9   9
#define CLCD_COL_10  10
#define CLCD_COL_11  11
#define CLCD_COL_12  12
#define CLCD_COL_13  13
#define CLCD_COL_14  14
#define CLCD_COL_15  15
#define CLCD_COL_16  16

/***************************************************************/

void CLCD_voidInit          (void                        );
void CLCD_voidSendData      (u8 Copy_u8Data              );
void CLCD_voidSendCommand   (u8 Copy_u8Command           );
void CLCD_voidSendString    (u8 *Copy_u8PtrString        );
void CLCD_voidSendNumber    (u64 Copy_u64Number          );
void CLCD_voidSetPosition   (u8 Copy_u8Row, u8 Copy_u8Col);
void CLCD_voidSendExtraChar (u8 Copy_u8Row, u8 Copy_u8Col);
void CLCD_voidClearScreen   (void                        );



#endif // CLCD_INTERFACE_H_
