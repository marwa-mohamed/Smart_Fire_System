/*
 * ADC_PROG.c
 *
 *  Created on: Aug 27, 2023
 *      Author: marwa
 */


#include "../../4-LIB\STD_TYPES.h"
#include "../../4-LIB\BIT_MATH.h"

#include "../../3-MCAL/DIO/DIO_Interface.h"

#include "ADC_CONFIG.h"
#include "ADC_INTERFAC.h"
#include "ADC_PRIVATE.h"



void ADC_voidInit(void){

	ADC_uint8_ADMUX_REG |= (ADC_uint8_VOLT_REF << 6);

	ADC_uint8_ADMUX_REG |= (ADC_uint8_ADJUST << 5);

	ADC_uint8_ADCSRA_REG |= ADC_uint8_PRESCALER;

	SET_BIT(ADC_uint8_ADCSRA_REG , 7);
}

uint16 ADC_uint16GetDigitalValue(uint8 copy_uint8ChannelNum){

	ADC_uint8_ADMUX_REG &= 0B11100000;
	ADC_uint8_ADMUX_REG |= copy_uint8ChannelNum;

	SET_BIT(ADC_uint8_ADCSRA_REG , 6);

	while((GET_BIT(ADC_uint8_ADCSRA_REG,4)) == 0);

	SET_BIT(ADC_uint8_ADCSRA_REG,4);

	uint16 local_uint8Result = ADC_uint16_ADC_REG;

	return local_uint8Result;
}

