#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../3-MCAL/DIO/DIO_INTERFACE.h"


#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"
#include "LCD_PRIVATE.h"
#include "util/delay.h"


/*
*   name : LCD_voidInit
*   brief : intializing the LCD to use
*/
void LCD_voidInit(void)
{
    DIO_udtSetPinDirection(LCD_uint8_CTRL_PORT, LCD_uint8_RSPIN, DIO_OUTPUT);
    DIO_udtSetPinDirection(LCD_uint8_CTRL_PORT, LCD_uint8_RWPIN, DIO_OUTPUT);
    DIO_udtSetPinDirection(LCD_uint8_CTRL_PORT, LCD_uint8_EPIN, DIO_OUTPUT);
    DIO_voidSetPortDirection(LCD_uint8_DATA_PORT, 0xff);
    _delay_ms(40);

    //En set
    LCD_voidSendInstruction(LCD_uint8_EnSET);
    _delay_ms(1);

    //Display on/off
    LCD_voidSendInstruction(LCD_uint8_Display_on);
    _delay_ms(1);

    //clear display
    LCD_voidClearDisplay();
    _delay_ms(2);

    //entry mode set
    LCD_voidSendInstruction(LCD_uint8_EntryModeSet);
}

/*
*   name : LCD_voidSendInstruction
*   brief : send instruction to the LCD to run
    set RS to 0 to send instruction
    set RW to 1 to write
    set E to 1 to recive instruction

*/

void LCD_voidSendInstruction(uint8 copy_uint8instruction)
{
    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT,LCD_uint8_RSPIN,DIO_LOW);
    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT,LCD_uint8_RWPIN,DIO_LOW);

    DIO_voidSetPortValue(LCD_uint8_DATA_PORT, copy_uint8instruction);

    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT, LCD_uint8_EPIN, DIO_HIGH);
    _delay_ms(1);
    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT, LCD_uint8_EPIN, DIO_LOW);
}

void LCD_voidWriteChar(uint8 copy_uint8Data){
    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT,LCD_uint8_RSPIN,DIO_HIGH);
    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT,LCD_uint8_RWPIN,DIO_LOW);

    DIO_voidSetPortValue(LCD_uint8_DATA_PORT, copy_uint8Data);

    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT, LCD_uint8_EPIN, DIO_HIGH);
    _delay_ms(1);
    DIO_udtSetPinValue(LCD_uint8_CTRL_PORT, LCD_uint8_EPIN, DIO_LOW);
}

void LCD_vidPrintWords (uint8* Words )
{
	uint8 Counter = 0;
	while(Words [Counter] !='\0')
		LCD_voidWriteChar(Words[Counter++]);
}

void LCD_voidClearDisplay()
{
    LCD_voidSendInstruction(LCD_uint8_ClearDisplay);
    _delay_us(1);
}

void LCD_vidLocation(uint8 u8Row,uint8 u8Column)
{
	if(	u8Row == 0)
		LCD_voidSendInstruction(u8Column + 128);
	
	else
		LCD_voidSendInstruction((u8Column + 0x40)+ 128);
}

void void_LCDWriteNumber(uint32 copy_u32DataValue){
 	if(copy_u32DataValue == 0){
 		LCD_voidWriteChar(copy_u32DataValue+48);
 	}
 else{
 	uint8 Lastdigait=0;
 	uint32 TenPowLastdigait=1;
 	while(copy_u32DataValue/TenPowLastdigait){
 		Lastdigait++;
 		TenPowLastdigait*=10;
 	}
 	for(uint8 iteration=0; iteration<Lastdigait; iteration++){
 		TenPowLastdigait/=10;
 		uint8 Number=copy_u32DataValue/TenPowLastdigait;
 		LCD_voidWriteChar(Number+48);
 		copy_u32DataValue=copy_u32DataValue-Number*TenPowLastdigait;
 	}
 }
 		_delay_ms(2);
}
