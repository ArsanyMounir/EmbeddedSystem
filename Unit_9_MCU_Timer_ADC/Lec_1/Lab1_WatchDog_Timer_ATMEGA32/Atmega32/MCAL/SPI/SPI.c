/*
 * SPI.c
 *
 *  Created on: Apr 29, 2024
 *      Author: Arsany
 */

#include "SPI.h"






void MCAL_SPI_Init(SPI_Config_t * Config)
{
	GPIO_PinConfig_t PinConfig;
	if(Config->SPI_MODE == SPI_MASTER)
	{
		PinConfig.GPIO_PinNumber = GPIO_PIN_4;
		PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		PinConfig.GPIO_PinNumber = GPIO_PIN_5;
		PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		PinConfig.GPIO_PinNumber = GPIO_PIN_6;
		PinConfig.GPIO_DataDirection = GPIO_INPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		PinConfig.GPIO_PinNumber = GPIO_PIN_7;
		PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		//Bit 4 – MSTR: Master/Slave Select
		SPI->SPCR |= (1<<4);
	}

	else if (Config->SPI_MODE == SPI_SLAVE)
	{
		PinConfig.GPIO_PinNumber = GPIO_PIN_4;
		PinConfig.GPIO_DataDirection = GPIO_INPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		PinConfig.GPIO_PinNumber = GPIO_PIN_5;
		PinConfig.GPIO_DataDirection = GPIO_INPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		PinConfig.GPIO_PinNumber = GPIO_PIN_6;
		PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		PinConfig.GPIO_PinNumber = GPIO_PIN_7;
		PinConfig.GPIO_DataDirection = GPIO_INPUT;
		MCAL_GPIO_Init(GPIOB,&PinConfig);

		//Bit 4 – MSTR: Master/Slave Select
		SPI->SPCR &= ~(1<<4);
	}


	//Configure Clock

	switch(Config->SPI_SCK_RATE)
	{
	case SPI_SCK_RATE_2:
		SPI->SPCR &= ~(1<<0);
		SPI->SPCR &= ~(1<<1);
		SPI->SPSR |= (1<<0);
		break;
	case SPI_SCK_RATE_4:
		SPI->SPCR &= ~(1<<0);
		SPI->SPCR &= ~(1<<1);
		SPI->SPSR &= ~(1<<0);
		break;
	case SPI_SCK_RATE_8:
		SPI->SPCR |= (1<<0);
		SPI->SPCR &= ~(1<<1);
		SPI->SPSR |= (1<<0);
		break;
	case SPI_SCK_RATE_16:
		SPI->SPCR |= (1<<0);
		SPI->SPCR &= ~(1<<1);
		SPI->SPSR &= ~(1<<0);
		break;
	case SPI_SCK_RATE_32:
		SPI->SPCR &= ~(1<<0);
		SPI->SPCR |= (1<<1);
		SPI->SPSR |= (1<<0);
		break;
	case SPI_SCK_RATE_64:
		SPI->SPCR &= ~(1<<0);
		SPI->SPCR |= (1<<1);
		SPI->SPSR &= ~(1<<0);
		break;
	case SPI_SCK_RATE_128:
		SPI->SPCR |= (1<<0);
		SPI->SPCR |= (1<<1);
		SPI->SPSR &= ~(1<<0);
		break;
	}

	//Rest of options to be implemented later


	//Enable SPI
	SPI->SPCR|=(1<<6);
}
uint8_t MCAL_SPI_MASTER_SEND(uint8_t data)
{
	SPI->SPDR = data;
	while(!(SPI->SPSR & (1<<7)));
	return data;

}

uint8_t MCAL_SPI_SLAVE_RECIEVE(void)
{
	while(!(SPI->SPSR & (1<<7)));
	return SPI->SPDR;

}

uint8_t MCAL_SPI_SEND_RECIEVE(uint8_t data)
{
	SPI->SPDR = data;
	while(!(SPI->SPSR & (1<<7)));
	return SPI->SPDR;
}
