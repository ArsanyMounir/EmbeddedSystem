/*
 * ADC.h
 *
 *  Created on: Jun 10, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_ADC_H_
#define MCAL_INC_ADC_H_
#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"


#define VoltRef					5000
#define Resolution				1024


typedef enum{
	Vref_AREF,
	Vref_AVCC,
	Vref_256
}ADC_Verf_t;

typedef enum{
	ADC_PRESCALER_2=0x00,
	ADC_PRESCALER_4=0x02,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
}ADC_PreScaler_t;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_t;



void MCAL_ADC_Init(ADC_Verf_t Vref, ADC_PreScaler_t Prescaler);

uint16_t MCAL_ADC_Read(ADC_Channel_t Channel);

uint16_t MCAL_ADC_ReadVoltPercent(ADC_Channel_t Channel);


#endif /* MCAL_INC_ADC_H_ */
