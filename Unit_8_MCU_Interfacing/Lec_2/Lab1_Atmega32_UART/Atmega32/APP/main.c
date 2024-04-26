/*
 * main.c
 *
 *  Created on: Apr 11, 2024
 *      Author: Arsany
 */
#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "LCD.h"
#include "USART.h"



//uint8_t Buffer[30];
uint8_t Buffer;
/*
void UART_IRQ_CallBack(void)
{

	Buffer =MCAL_USART_RECEIVE(Polling_DISABLED);
	MCAL_USART_SEND( Buffer,Polling_DISABLED );

}
*/

int main(void)
{
	HAL_LCD_Init();

	USART_Config_t UART_Config;
	UART_Config.BaudRate = 51;
	UART_Config.IRQ_Enable = USART_IRQ_DISABLED;
	UART_Config.Ptr_IRQ_CallBack = NULL;
	UART_Config.Parity = USART_PARITY_NONE ;
	UART_Config.Data_Length = USART_DATA_LEGNTH_8BIT;
	UART_Config.Stop_Bits = USART_StopBits_1;
	UART_Config.USART_MODE = USART_MODE_Asynchronous;
	MCAL_USART_Init(&UART_Config);

	HAL_LCD_WRITE_STR("UART Initialized");
	HAL_LCD_GOTO_XY(2,0);
	HAL_LCD_WRITE_STR("Watch Terminal");


	char input;
	while(1)
	{

		input = MCAL_USART_RECEIVE(Polling_DISABLED);
		MCAL_USART_SEND(input,Polling_DISABLED);

	}

	return 0;
}


