/*
 * ADC.c
 *
 *  Created on: Jun 10, 2024
 *      Author: Arsany
 */
#include "ADC.h"


void MCAL_ADC_Init(ADC_Verf_t Vref, ADC_PreScaler_t Prescaler)
{
	switch (Vref)
	{
	//		• Bit 7:6 – REFS1:0: Reference Selection Bits
	//		These bits select the voltage reference for the ADC, as shown in Table 83. If these bits are
	//		changed during a conversion, the change will not go in effect until this conversion is complete
	//		(ADIF in ADCSRA is set). The internal voltage reference options may not be used if an external
	//		reference voltage is being applied to the AREF pin.
	//		Table 83. Voltage Reference Selections for ADC
	//	REFS1	REFS0	Vref
	//	0		0		AREF
	//	0		1		AVCC
	//	1		0		Reserved
	//	1		1		Internal 2.56V

	case Vref_AREF:
	{
		ADMUX &= ~(1<<6);
		ADMUX &= ~(1<<7);
		break;
	}
	case Vref_AVCC:
	{
		ADMUX |= (1<<6);
		ADMUX &= ~(1<<7);
		break;
	}
	case Vref_256:
	{
		ADMUX |= (1<<6);
		ADMUX |= (1<<7);
		break;
	}
	}

//	• Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
//	These bits determine the division factor between the XTAL frequency and the input clock to the ADC
	ADCSRA |= Prescaler;

//	• Bit 7 – ADEN: ADC Enable
//	Writing this bit to one enables the ADC. By writing it to zero, the ADC is turned off. Turning the
//	ADC off while a conversion is in progress, will terminate this conversion
	ADCSRA |= (1<<7);


}

uint16_t MCAL_ADC_Read(ADC_Channel_t Channel)
{
	uint16_t Value=0;


//	Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
//	The value of these bits selects which combination of analog inputs are connected to the ADC.
//	These bits also select the gain for the differential channels. See Table 84 for details. If these bits
//	are changed during a conversion, the change will not go in effect until this conversion is
//	complete (ADIF in ADCSRA is set).
	ADMUX |= Channel;

//	Bit 6 – ADSC: ADC Start Conversion
//	In Single Conversion mode, write this bit to one to start each conversion. In Free Running Mode,
//	write this bit to one to start the first conversion. The first conversion after ADSC has been written
//	after the ADC has been enabled, or if ADSC is written at the same time as the ADC is enabled,
//	will take 25 ADC clock cycles instead of the normal 13. This first conversion performs initialization of the ADC.
//	ADSC will read as one as long as a conversion is in progress. When the conversion is complete,
//	it returns to zero. Writing zero to this bit has no effect.
	ADCSRA |= (1<<6);

	while ((ADCSRA>>6)& 1);

	Value |= (ADCL | ((ADCH & (0x03)) << 8));

	return Value;



}


uint16_t MCAL_ADC_ReadVoltPercent(ADC_Channel_t Channel)
{
	uint16_t data = MCAL_ADC_Read(Channel);
	uint16_t volt = (((uint32_t)data * 100) / 1023 );

	return volt;

}


