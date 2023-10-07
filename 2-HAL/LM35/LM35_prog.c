/*
 * LM35_prog.c
 *
 *  Created on: Aug 28, 2023
 *      Author: marwa
 */
#include "LM35_config.h"
#include "LM35_interface.h"
#include "LM35_private.h"
#include "../../4-LIB/STD_TYPES.h"
#include "../../3-MCAL/DIO/DIO_INTERFACE.h"
#include "../../3-MCAL/ADC/ADC_INTERFAC.h"

#ifndef _HAL_LM35_LM35_PROG_C_
#define _HAL_LM35_LM35_PROG_C_

void LM35_voidinti()
{
    ADC_voidInit();
}


uint8 LM35_uint8Read(){

    uint16 local_uint16Result =0;
	uint16 local_uint16Analog = 0;
	uint8  local_uint8Temp = 0;

	local_uint16Result = ADC_uint16GetDigitalValue(LM35_channel);

	local_uint16Analog = (local_uint16Result * (ADC_uint8_VOLT_REF*10000ul))/1024;

	local_uint8Temp = local_uint16Analog / 10;

    return local_uint8Temp;
}


#endif /* 2_HAL_LM35_LM35_PROG_C_ */
