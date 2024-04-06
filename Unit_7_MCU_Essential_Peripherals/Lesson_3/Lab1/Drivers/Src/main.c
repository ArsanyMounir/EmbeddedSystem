/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"



void clk_Init(void)
{
	//Enable clock for GPIO A
	RCC_GPIOA_CLK_EN() ;
	//Enable clock for GPIO B
	RCC_GPIOB_CLK_EN() ;
}

void GPIO_Init(void)
{
	GPIO_PinConfig_t PinConfig;

	//===============Input Pins===============
	//Configure PIN 1 in GPIOA to be Floating input
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);


	//Configure PIN 13 in GPIOA to be Floating input
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);


	//===============Output Pins===============

	//Configure PIN 1 in GPIOB to be General Purpose Push-Pull
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);


	//Configure PIN 13 in GPIOB to be General Purpose Push-Pull
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

}

void wait()
{
	int i;
	for (i=0;i<2000;i++);
}


int main(void)
{

	clk_Init();
	GPIO_Init();
	while(1)
	{
		//PORT A Pin 1 Connected to external Pull-Up Resistance (default = 1)
		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 ) // should be single press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			//Loop until state change , so continuous pressing doesn't register as multiple presses
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 );
		}

		//PORT A Pin 13 Connected to external Pull-Down Resistance (default = 0)
		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1 ) // should be Multi press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}

		wait();
	}
}
