/*
 * main.c
 *
 *  Created on: May 09, 2024
 *      Author: Arsany
 */

#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "PWM.h"
#include "avr/delay.h"




int main(void)
{
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(GPIOB,&PinConfig);

	PWM_Config_t Config;
	Config.MODE = FAST_PWM;
	Config.CLK = PRESCALING_CLK8;
	Config.CMP_MODE = NON_INVERTING;
	MCAL_PWM_Init(&Config);

	while(1)
	{

		MCAL_PWM_Start(&Config,30);

	}

}





