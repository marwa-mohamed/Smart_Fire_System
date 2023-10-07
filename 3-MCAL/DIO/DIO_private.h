/*********************************************************
********* File       ; DIO_private.h **** DIO PRAIVATE
********* created on : 21/7/2023
********* Author     : Ahmed Saeed      
*********************************************************/

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/*********************************************************
*    PORTX REGISTERS                                     *
*********************************************************/

/*!Comment : DDRA , PORTA , PINA Defintion */

#define DDRA  *((volatile uint8*)0x3A)
#define PORTA *((volatile uint8*)0x3B)
#define PINA  *((volatile uint8*)0x39)

/*!Comment : DDRB , PORTB , PINB Defintion */

#define DDRB  *((volatile uint8*)0x37)
#define PORTB *((volatile uint8*)0x38)
#define PINB  *((volatile uint8*)0x36)

/*!Comment : DDRC , PORTC , PINC Defintion */

#define DDRC  *((volatile uint8*)0x34)
#define PORTC *((volatile uint8*)0x35)
#define PINC  *((volatile uint8*)0x33)

/*!Comment : DDRD , PORTD , PIND Defintion */

#define DDRD  *((volatile uint8*)0x31)
#define PORTD *((volatile uint8*)0x32)
#define PIND  *((volatile uint8*)0x30)

/*****************FILE REVISION**************************
********* Auther name ;
********* Ahmed Saeed            AS
********* Updated record:
*********
*********  21/7/2023 AS SY.0 Updated PORTX PRAIVATE
*********
*********************************************************/

#endif
