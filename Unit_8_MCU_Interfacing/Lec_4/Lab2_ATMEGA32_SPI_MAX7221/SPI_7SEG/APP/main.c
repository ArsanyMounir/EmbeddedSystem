/*
 * main.c
 *
 *  Created on: Apr 11, 2024
 *      Author: Arsany
 */
#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "SPI.h"

extern void wait_ms(uint32_t time);

void MAX7221_Interface(uint8_t COMMAND , uint8_t Data)
{
	//make SS Low first
	MCAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);
	//Send First byte (Command)
	SPI->SPDR = COMMAND;
	//wait till finished
	while(!(SPI->SPSR & (1<<7)));
	//Send Second byte (data)
	SPI->SPDR = Data;
	//wait till finished
	while(!(SPI->SPSR & (1<<7)));
	//Make SS High again
	MCAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);

}

void MAX7221_Init()
{
	MAX7221_Interface(0x09,0xFF);//Decode all Displays
	MAX7221_Interface(0x0B,0x07);//Set Scan limit 0->7
	MAX7221_Interface(0x0A,0x0F);//Max Intensity
	MAX7221_Interface(0x0C,0x01);//Enable Normal mode

}

int main(void)
{
	uint8_t i ;
	uint8_t SEG_Select = 0;

	SPI_Config_t Config;
	Config.SPI_MODE = SPI_MASTER;
	Config.SPI_SCK_RATE = SPI_SCK_RATE_16;
	MCAL_SPI_Init(&Config);

	MAX7221_Init();

	while(1)
	{
		for(i=1;i<9;i++)
		{
			MAX7221_Interface(i,SEG_Select++);
			wait_ms(200);
		}
		for(i=0;i<9;i++)
		{
			MAX7221_Interface(i,0); //CLEAR all 7 SEG
		}


	}

	return 0;
}


