/*
 * ADC_PRIVATE.h
 *
 *  Created on: Aug 27, 2023
 *      Author: marwa
 */

#ifndef _MCAL_ADC_ADC_PRIVATE_H_
#define _MCAL_ADC_ADC_PRIVATE_H_

#define ADC_uint8_AREF			        0
#define ADC_uint8_AVCC			        1
#define ADC_uint8_INTERNAL		        3

#define ADC_uint8_LEFT_ADJUST	        1
#define ADC_uint8_RIGHT_ADJUST	        0

#define ADC_uint8_PRESCALER_2			1
#define ADC_uint8_PRESCALER_4			2
#define ADC_uint8_PRESCALER_8			3
#define ADC_uint8_PRESCALER_16			4
#define ADC_uint8_PRESCALER_32			5
#define ADC_uint8_PRESCALER_64			6
#define ADC_uint8_PRESCALER_128		    7



#define ADC_uint8_ADMUX_REG		    *((volatile uint8*)0x27)
#define ADC_uint8_ADCSRA_REG		*((volatile uint8*)0x26)
#define ADC_uint8_ADCH_REG			*((volatile uint8*)0x25)
#define ADC_uint8_ADCl_REG			*((volatile uint8*)0x24)
#define ADC_uint8_SFIOR_REG		    *((volatile uint8*)0x50)

#define ADC_uint16_ADC_REG			    *((volatile uint16*)0x24 )

#endif /* 3_MCAL_ADC_ADC_PRIVATE_H_ */
