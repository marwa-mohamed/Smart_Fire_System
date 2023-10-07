/*********************************************************
********* File       ; DIO_program.c **** program
********* created on : 22/7/2023
********* Author     : Ahmed Saeed      
*********************************************************/

/*********************************************************
*    LAIBRARY INCLUDE                                    *
*********************************************************/

#include "../../4-LIB/BIT_MATH.h"
#include "../../4-LIB/STD_TYPES.h"

#include "DIO_private.h"
#include "DIO_interface.h"

/*********************************************************
*    FUNCTION OF DIO                                     *
*********************************************************/

Std_ReturnType DIO_udtSetPinDirection
(
    uint8 u8Port,
    uint8 u8Pin,
    uint8 u8Direction
)
{
    Std_ReturnType udtReturnValue = E_NOT_OK ;

    if
    (
        u8Direction == DIO_OUTPUT
    )
    {

        switch
        (
            u8Port
        )
        {

        case DIO_PORTA:
		    SET_BIT(DDRA, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTB:
            SET_BIT(DDRB, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTC:
            SET_BIT(DDRC, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTD:
            SET_BIT(DDRD, u8Pin);
            udtReturnValue = E_OK ;
            break;

        default:
            /*!Comment : Do nothing */
            break;

        }
    }
    else if
    (
        u8Direction == DIO_INPUT
    )
    {
        switch
        (
            u8Port
        )
        {

        case DIO_PORTA:
            CLR_BIT(DDRA, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTB:
            CLR_BIT(DDRB, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTC:
            CLR_BIT(DDRC, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTD:
            CLR_BIT(DDRD, u8Pin);
            udtReturnValue = E_OK ;
            break;

        default :
            /*!Comment : Do nothing */
            break ;

        }
    }
    else
    {
        /*!Comment : Do nothing */
    }

    return udtReturnValue ;
}


Std_ReturnType DIO_udtSetPinValue
(
    uint8 u8Port,
    uint8 u8Pin,
    uint8 u8Value
)
{
    Std_ReturnType udtReturnValue = E_NOT_OK ;

    if
	(
        u8Value == DIO_HIGH
    )
    {
        switch
        (
            u8Port
        )
        {

        case DIO_PORTA:
            SET_BIT(PORTA, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTB:
            SET_BIT(PORTB, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTC:
            SET_BIT(PORTC, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTD:
            SET_BIT(PORTD, u8Pin);
            udtReturnValue = E_OK ;
            break;

        default:
            /*!Comment : Do nothing */
            break;

        }
    }
    else if
    (
        u8Value == DIO_LOW
    )
    {
        switch
        (
            u8Port
        )
        {

        case DIO_PORTA:
            CLR_BIT(PORTA, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTB:
            CLR_BIT(PORTB, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTC:
            CLR_BIT(PORTC, u8Pin);
            udtReturnValue = E_OK ;
            break;

        case DIO_PORTD:
            CLR_BIT(PORTD, u8Pin);
            udtReturnValue = E_OK ;
            break;

        default :
            /*!Comment : Do nothing */
            break ;

        }
    }
    else
    {
        /*!Comment : Do nothing */
    }

    return udtReturnValue ;
}


Std_ReturnType DIO_udtGetPinValue
(
    uint8  u8Port,
    uint8  u8Pin,
    uint8* pu8Value
)
{
    Std_ReturnType udtReturnValue = E_NOT_OK ;

    switch 
	(
        u8Port
    )
    {

    case DIO_PORTA:
        *pu8Value = GET_BIT(PINA, u8Pin);
        udtReturnValue = E_OK ;
        break;

    case DIO_PORTB:
        *pu8Value = GET_BIT(PINB, u8Pin);
        udtReturnValue = E_OK ;
        break;

    case DIO_PORTC:
        *pu8Value = GET_BIT(PINC, u8Pin);
        udtReturnValue = E_OK ;
        break;

    case DIO_PORTD:
        *pu8Value = GET_BIT(PIND, u8Pin);
        udtReturnValue = E_OK ;
        break;

    default :
        /*!Comment : Do nothing */
        break ;

    }
    udtReturnValue = E_OK;
    return udtReturnValue ;
}


void DIO_voidSetPortDirection	(uint8 copy_uint8PORT , uint8 Copy_uint8PortDirection){
// check to be input (clear the bit) or ouput (set the bit)

       switch (copy_uint8PORT)
        {
            case DIO_PORTA: DDRA = Copy_uint8PortDirection; 
                break;
            case DIO_PORTB: DDRB = Copy_uint8PortDirection;
                break;
            case DIO_PORTC: DDRC = Copy_uint8PortDirection;
                break;
            case DIO_PORTD: DDRD = Copy_uint8PortDirection;
                break;
       }
}

void DIO_voidSetPortValue	(uint8 copy_uint8PORT  , uint8 Copy_uint8PortValue)
{
        switch (copy_uint8PORT)
        {
            case DIO_PORTA: PORTA = Copy_uint8PortValue;
                break;
            case DIO_PORTB: PORTB = Copy_uint8PortValue;
                break;
            case DIO_PORTC: PORTC = Copy_uint8PortValue;
                break;
            case DIO_PORTD: PORTD = Copy_uint8PortValue;
                break;
       }
}

uint8	 DIO_uint8GetPortValue		(uint8 copy_uint8PORT)
{
        switch (copy_uint8PORT)
        {
            case DIO_PORTA: return PINA;
            case DIO_PORTB: return PINB;
            case DIO_PORTC: return PINC;
            case DIO_PORTD: return PIND;
            default : return 0;
        }
}


/*****************FILE REVISION**************************
********* Auther name ;
********* Ahmed Saeed    AS
*********
********* Updated record:
*********
*********  22/7/2023 AS V1.0 Updated function of DIO
*********
*********************************************************/
