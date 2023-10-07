#ifndef _HAL_LCD_CONFIG_H_
#define _HAL_LCD_CONFIG_H_
#include "../../3-MCAL/DIO/DIO_INTERFACE.h"
#include "../../4-LIB/STD_TYPES.h"

#define LCD_uint8_DATA_PORT			DIO_PORTD
#define LCD_uint8_CTRL_PORT			DIO_PORTC

#define LCD_uint8_RSPIN            DIO_PIN0
#define LCD_uint8_RWPIN            DIO_PIN1
#define LCD_uint8_EPIN             DIO_PIN2

#endif
