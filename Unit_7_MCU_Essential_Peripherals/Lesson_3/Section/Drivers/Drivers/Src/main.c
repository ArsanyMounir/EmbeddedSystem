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
#include "LCD.h"
#include "Keypad.h"
#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10



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
	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PA13 input HighZ Floating input (reset state)
	PinCfg.GPIO_PinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB13 (output PUSH pull Mode)
	PinCfg.GPIO_PinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);



}



int main(void)
{
	clock_init();
	LCD_INIT();
	LCD_WR_STR("HEY...");
	wait_ms(300);
	LCD_CLEAR();
	GPIO_init();
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WR_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9);
		wait_ms(1000);
	}
	LCD_CLEAR();
	KEYPAD_init();
	LCD_WR_STR("Keypad is ready");
	wait_ms(50);
	LCD_CLEAR();

    volatile char KEY;
    volatile int count=0;
	while(1)
	{
    	KEY=KEYPAD_CHAR();
    	switch(KEY)
    	{
    	case'!':LCD_CLEAR();break;
    	case'N':break;
    	default:
    		if(count<16){
    		LCD_WR_CHAR(KEY);
    		count++;
    		}
    		else
    		{
    			count=0;
    			LCD_CLEAR();
    			LCD_WR_CHAR(KEY);
    		}
    		break;
    	}
    }

}
