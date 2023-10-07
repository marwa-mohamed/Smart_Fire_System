#include "3-MCAL/DIO/DIO_interface.h"
#include "2-HAL/LCD2/LCD_interface.h"
#include "2-HAL/LM35/LM35_interface.h"
#include "util/delay.h"


int main(void)
{
    /* Replace with your application code */ 
	LCD_voidInit();
	LCD_vidLocation(0,0);
	DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN3, DIO_OUTPUT); 	//green
	DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN4, DIO_OUTPUT); 	//yellow
	DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN5, DIO_OUTPUT); 	//red
	DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN6, DIO_OUTPUT);	//Buzzer


	DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);		//smoke detector
	DIO_udtSetPinValue( DIO_PORTA, DIO_PIN0, DIO_HIGH); 		//Turn on Pull up resistor

	DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);	//Water MOTOR
	DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN3, DIO_OUTPUT);	//fans motor


	while (1)
    {
		LM35_voidinti(); 
		uint8 IsPushed;
		Std_ReturnType localu8return = DIO_udtGetPinValue(DIO_PORTA,DIO_PIN0,&IsPushed);
	 	uint8 temp = LM35_uint8Read();
	 	LCD_vidPrintWords("Temp = ");
	 	void_LCDWriteNumber(temp);
		LCD_vidLocation(1,0);
 		_delay_ms(30);

		switch (IsPushed)
		{
		case DIO_HIGH:
			{
			LCD_vidLocation(0,0);
 			LCD_vidPrintWords("SMOKE DETECTED");
			LCD_vidLocation(1,0);
 			LCD_vidPrintWords("Turn ON Water");
			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN3, DIO_LOW); 		//green led OFF
			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN4, DIO_LOW);		// yellow OFF
			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN5, DIO_HIGH);		// red led ON 
			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN6, DIO_HIGH); 	// bazzar ON

			DIO_udtSetPinValue( DIO_PORTA, DIO_PIN1, DIO_HIGH); 	// Water MOTOR ON
			DIO_udtSetPinValue( DIO_PORTA, DIO_PIN3, DIO_HIGH); 	// fan1 ON
			_delay_ms(40);

	 	}			
			break;

		case DIO_LOW:
		{
			DIO_udtSetPinValue( DIO_PORTA, DIO_PIN1, DIO_LOW); 	// Water MOTOR ON
			if ( temp >= 30 && temp < 40 )
     		{
	 			LCD_vidPrintWords("Turn ON Fans");
	 			_delay_ms(40);

	 			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN3, DIO_HIGH); 	//green led ON
	 			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN4, DIO_LOW);		//yellow OFF
				DIO_udtSetPinValue( DIO_PORTC, DIO_PIN5, DIO_LOW);		//red OFF
	 			DIO_udtSetPinValue( DIO_PORTA, DIO_PIN3, DIO_HIGH); 	// fan1 ON
				DIO_udtSetPinValue( DIO_PORTC, DIO_PIN6, DIO_LOW);		// bazzar OFF
     		}
	 		else if(temp >= 40)
	 		{
	 			LCD_vidPrintWords("Warning, HOT");
				_delay_ms(40);
				DIO_udtSetPinValue( DIO_PORTC, DIO_PIN3, DIO_LOW); 		//green led OFF
	 			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN4, DIO_HIGH);		// yellow ON
	 			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN5, DIO_LOW);		// red led  OFF
				DIO_udtSetPinValue( DIO_PORTC, DIO_PIN6, DIO_LOW); 		// bazzar ON

	 			LCD_vidPrintWords(temp);
				DIO_udtSetPinValue( DIO_PORTA, DIO_PIN3, DIO_HIGH); 	// fan1 ON
	 			LCD_vidLocation(1,0);
	 			LCD_voidClearDisplay();
	 		}
			
     		else
     		{
 				LCD_vidPrintWords("Fine");
     			DIO_udtSetPinValue( DIO_PORTA, DIO_PIN3, DIO_LOW);		// motor fan1 OFF
				DIO_udtSetPinValue( DIO_PORTA, DIO_PIN5, DIO_LOW); 		// fan2 OFF
     			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN3, DIO_HIGH);		// green led ON
     			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN4, DIO_LOW);		// yellow led  OFF
     			DIO_udtSetPinValue( DIO_PORTC, DIO_PIN5, DIO_LOW);		// red led  OFF
				DIO_udtSetPinValue( DIO_PORTC, DIO_PIN6, DIO_LOW);		// bazzar OFF
 	 			_delay_ms(40);
     		}
		}
			break;
		
		default:
			break;
		}

		LCD_voidClearDisplay();
	}
}
