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
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
//#include "keypad.h"
//#include "LCD.h"

uint8_t IRQ_flag ;

void wait(int x)
{
	int i,j;
	for (i=0;i<x;i++)
		for(j=0;j<x;j++);
}


void clk_Init(void)
{
	//Enable clock for GPIO A
	RCC_GPIOA_CLK_EN() ;
	//Enable clock for GPIO B
	RCC_GPIOB_CLK_EN() ;
	//Enable clock for AFIO
	RCC_AFIO_CLK_EN();
}


unsigned char ch;

void UART_IRQ_CallBack(void)
{

	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, disable);

}



int main(void)
{
	clk_Init();
	USART_Config_t UART_Config;
	UART_Config.BaudRate = UART_BaudRate_115200;
	UART_Config.FlowCtrl = USART_FlowCtrl_NONE;
	UART_Config.IRQ_Enable = USART_IRQ_EN_RXNEIE;
	UART_Config.Ptr_IRQ_CallBack = UART_IRQ_CallBack;
	UART_Config.Parity = USART_PARITY_NONE;
	UART_Config.Data_Length = USART_DATA_LEGNTH_8BIT;
	UART_Config.Stop_Bits = USART_StopBits_1;
	UART_Config.USART_MODE = UART_MODE_TX_RX;
	MCAL_UART_Init(USART1, &UART_Config);
	MCAL_UART_GPIO_Set_Pins(USART1);
	while(1)
	{
	}


}