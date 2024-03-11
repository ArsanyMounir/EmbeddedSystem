/*
 * driver.c
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#include "driver.h"
#include <stdint.h>
#include <stdio.h>
void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

int getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}

void setLedIndicator(LED_State_ID LEDState)
{
	if (LEDState == GreenON)
	{
		RESET_BIT(GPIOA_ODR,10);
	}
	else if (LEDState == GreenOFF)
	{
		SET_BIT(GPIOA_ODR,10);
	}
	else if (LEDState == YellowON)
	{
		RESET_BIT(GPIOA_ODR,11);
	}
	else if (LEDState == YellowOFF)
	{
		SET_BIT(GPIOA_ODR,11);
	}
	else if (LEDState == RedON)
	{
		RESET_BIT(GPIOA_ODR,12);
	}
	else if (LEDState == RedOFF)
	{
		SET_BIT(GPIOA_ODR,12);
	}
}


void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}

