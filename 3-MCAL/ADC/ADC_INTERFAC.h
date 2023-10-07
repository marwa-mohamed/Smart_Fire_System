/*
 * ADC_INTERFAC.h
 *
 *  Created on: Aug 27, 2023
 *      Author: marwa
 */

#ifndef _MCAL_ADC_ADC_INTERFAC_H_
#define _MCAL_ADC_ADC_INTERFAC_H_
#include "../../4-LIB/STD_TYPES.h"
#include "ADC_CONFIG.h"

#define ADC_uint8_CHANNEL_0			0
#define ADC_uint8_CHANNEL_1			1
#define ADC_uint8_CHANNEL_2			2
#define ADC_uint8_CHANNEL_3			3
#define ADC_uint8_CHANNEL_4			4
#define ADC_uint8_CHANNEL_5			5
#define ADC_uint8_CHANNEL_6			6
#define ADC_uint8_CHANNEL_7			7



void ADC_voidInit(void);

uint16 ADC_uint16GetDigitalValue(uint8 copy_u8ChannelNum);


#endif /* 3_MCAL_ADC_ADC_INTERFAC_H_ */
