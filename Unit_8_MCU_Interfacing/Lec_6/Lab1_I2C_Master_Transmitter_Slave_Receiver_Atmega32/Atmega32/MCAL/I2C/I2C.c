/*
 * I2C.c
 *
 *  Created on: May 12, 2024
 *      Author: Arsany
 */

#include"I2C.h"
#undef F_CPU
#define F_CPU 8000000UL
#define prescaler 1

void MCAL_I2C_Init(unsigned long SCL_CLK)
{
	TWBR = (uint8_t) (((F_CPU / SCL_CLK )-16) / (2*prescaler));
	switch(prescaler)
	{
	case 1:
		TWSR = 0;
		break;
	case 4:
		TWSR = 1;
		break;
	case 16:
		TWSR = 2;
		break;
	case 64:
		TWSR = 3;
		break;
	}

}
void MCAL_I2C_Start_Condition(void)
{
	TWCR = (1<<7)|(1<<2)|(1<<5);
	while(((TWCR & (1<<7))== 0));
	while ((TWSR)!=0x08);
}

void MCAL_I2C_Write(uint8_t Data)
{
	TWDR =  Data;
	TWCR = (1<<7)|(1<<2);
	while ((TWCR&0x80)==0);
}

void MCAL_I2C_Stop_Condition(void)
{
	TWCR = (1<<7)|(1<<2)|(1<<4);
}

void MCAL_I2C_Set_Address(uint8_t address)
{
	TWAR = address;
}
uint8_t MCAL_I2C_Read(uint8_t ACK)
{
	uint8_t ch = 0;
	TWCR = (1<<7)|(1<<2)|(ACK<<6);
	while((TWCR & (1<<7))==0);
	while ((TWSR)!=0x60)
	{
		ch = TWSR;
	}
	TWCR = (1<<7)|(1<<2)|(ACK<<6);
	while((TWCR & (1<<7))==0);
	while ((TWSR)!=0x80)
	{
		ch = TWSR;
	}
	return TWDR;

}

