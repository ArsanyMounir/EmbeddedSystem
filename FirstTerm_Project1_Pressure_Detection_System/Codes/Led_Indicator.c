/*
 * Led_Indicator.c
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#include "Led_Indicator.h"


void (*LedIndicatore_State)(LED_State_ID);

void LedIndicator_init()
{
	LedIndicatore_State = LedOFF_State;
	SET_BIT(GPIOA_ODR,10);
	SET_BIT(GPIOA_ODR,11);
	SET_BIT(GPIOA_ODR,12);
}




void LedOn_State (LED_State_ID LEDState)
{
	Led_Indicatore_State_ID = LedON;
	if(LEDState == GreenON)
	{
		setLedIndicator(GreenON);
	}
	else if (LEDState == YellowON)
	{
		setLedIndicator(YellowON);
	}
	else if (LEDState == RedON)
	{
		setLedIndicator(RedON);
	}


}

void LedOFF_State (LED_State_ID LEDState)
{

	Led_Indicatore_State_ID = LedOFF;
	if(LEDState == GreenOFF)
	{
		setLedIndicator(GreenOFF);
	}
	else if (LEDState == YellowOFF)
	{
		setLedIndicator(YellowOFF);
	}
	else if (LEDState == RedOFF)
	{
		setLedIndicator(RedOFF);
	}


}


void setLedOFF (LED_State_ID LEDState)
{
	LedIndicatore_State = LedOFF_State;
	LedIndicatore_State(LEDState);
}

void setLedON (LED_State_ID LEDState)
{
	LedIndicatore_State = LedOn_State ;
	LedIndicatore_State(LEDState);
}




