/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6.h"


void clock_init()
{
	//Enable GPIO A clock
	RCC_GPIOA_CLK_EN();
	//Enable GPIO B clock
	RCC_GPIOB_CLK_EN();

}

void GPIO_init()
{
	GPIO_PinConfig_t PinCfg;

	//INPUT
	//PORT A1 Floating Input
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PORT A13 Floating Input
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);


	//OUTPUT
	//PORT B1 Push Pull Output
	//Output mode, max speed 10 MHz.
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	//PORT B13 Push Pull Output
	//Output mode, max speed 10 MHz.
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

void wait()
{
	unsigned int i;
	for(i=0;i<2000;i++);
}
int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{
		//Port A1 >> Pull Up
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
		{
			//toggle led on Port B1
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			//single press check
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);

		}
		//Port A13 >> Pull Down
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
		{
			//toggle led on Port B13
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);

		}
		wait();

	}
}
