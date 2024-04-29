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


void GPIO_Init()
{
	GPIO_PinConfig_t PinConfig;

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_0 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_1 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_2 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_3 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_4 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_5 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_6 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);

	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	PinConfig.GPIO_PinNumber = GPIO_PIN_7 ;
	MCAL_GPIO_Init(GPIOA,&PinConfig);
}


int main(void)
{
	uint8_t i ;
	GPIO_Init();
	SPI_Config_t Config;
	Config.SPI_MODE = SPI_SLAVE;
	Config.SPI_SCK_RATE = SPI_SCK_RATE_16;
	MCAL_SPI_Init(&Config);
	while(1)
	{
			MCAL_GPIO_WritePort(GPIOA,MCAL_SPI_SLAVE_RECIEVE());
			wait_ms(200);

	}

	return 0;
}

