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



#include"stdint.h"
#include"stdio.h"
#include"stdlib.h"

/*
 * Requirements:
 * 				APB1 Bus : 4MHz
 * 				APB2 Bus : 2MHz
 * 				AHB Bus  : 8MHz
 * 				sysclk   : 8MHz
 * 				Using only internal HSI_RC
 *
 */

#define GPIOA_BASE			0x40010800
#define GPIOA_CRH			*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR			*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define RCC_BASE			0x40021000
#define RCC_APB2ENR			*(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR			*(volatile uint32_t *)(RCC_BASE + 0x04)



void clk_Init()
{
	//	Bits 1:0 SW: System clock switch
	//  00: HSI selected as system clock
		RCC_CFGR |=(0b00);
	//	Bits 7:4 HPRE: AHB prescaler
	//	0xxx: SYSCLK not divided
		RCC_CFGR |=(0b0000<<4);
	//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	//  100: HCLK divided by 2
		RCC_CFGR |=(0b100<<8);
	//	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	//	101: HCLK divided by 4
		RCC_CFGR |=(0b101<<11);
	//  Bit 2 IOPAEN: IO port A clock enable
	//  1: IO port A clock enabled
		RCC_APB2ENR |= (1<<2);
}





int main(void)
{
	clk_Init();
	while(1)
	{
		/*Code*/
	}
}






