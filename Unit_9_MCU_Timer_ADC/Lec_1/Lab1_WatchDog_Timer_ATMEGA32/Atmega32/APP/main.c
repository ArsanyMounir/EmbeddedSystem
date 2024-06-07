/*
 * main.c
 *
 *  Created on: May 09, 2024
 *      Author: Arsany
 */



#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "TIMER.h"
#include "util/delay.h"


int main(void)
{
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(GPIOC,&PinConfig);
	_delay_ms(200);
	while(1)
	{
		MCAL_WDT_ON();
		MCAL_GPIO_TogglePin(GPIOC,GPIO_PIN_0);
		_delay_ms(2000);
		MCAL_WDT_OFF();
	}

}





