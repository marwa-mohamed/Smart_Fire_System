/*********************************************************
********* File       ; STD_TYPES.H **** Standerd Types
********* created on : 21/7/2023
********* Author     : Ahmed Saeed
*********************************************************/

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/*********************************************************
*    STANDERED TYPES FOR UNSIGNED INTEGERS               *
*********************************************************/

typedef unsigned char       uint8;
typedef unsigned short int uint16;
typedef unsigned long int  uint32;

/*********************************************************
*    STANDERED TYPES FOR SIGNED INTEGERS                 *
*********************************************************/

typedef signed  char         int8;
typedef signed short int    int16;
typedef signed long int     int32;

/*********************************************************
*    STD_RETURNTYPE DEFINES                              *
*********************************************************/

typedef enum 
{
	
	E_NOT_OK,
	E_OK    ,
	E_PINDING
	
}Std_ReturnType;



#define NULL	((void*)0)

typedef  void (*PF_voidCallback)(void);

#define my_ISR(vector)	void vector (void)	__attribute__((signal));\
void vector (void)

/*****************FILE REVISION**************************
********* Auther name ;
********* Ahmed Saeed      AS
*********
********* Updated record:
*********
*********  21/7/2023 AS SY.0 Updated STANDERED TYPES FOR (S/UNS ints , Std_ReturnType  ).
*********
*********************************************************/

#endif
