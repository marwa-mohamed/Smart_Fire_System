#ifndef _HAL_LCD_INTERFACE_H_
#define _HAL_LCD_INTERFACE_H_
#include "../../3-MCAL/DIO/DIO_INTERFACE.h"
#include "../../4-LIB/STD_TYPES.h"



void LCD_voidInit(void);
void LCD_voidSendInstruction(uint8 copy_uint8instruction);
void LCD_voidWriteChar(uint8 copy_uint8Data);
void LCD_voidSendString(uint8 *copy_uint8String, uint8 copy_size);
void LCD_voidClearDisplay();
void LCD_vidLocation(uint8 u8Row, uint8 u8Column);
void void_LCDWriteNumber(uint32 copy_u32DataValue);


#endif
