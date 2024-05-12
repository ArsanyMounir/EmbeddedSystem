/*
 * main.c
 *
 *  Created on: May 09, 2024
 *      Author: Arsany
 */
#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "I2C.h"

void _WAIT(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<time;j++);
}

#define MASTER
//#define SLAVE


int main(void)
{
	uint8_t ch =0;
#ifdef MASTER
	DDRA = 0xFF;
	MCAL_I2C_Init(0x48);
	while(1)
	{
		_WAIT(300);
		MCAL_I2C_Start_Condition();
		MCAL_I2C_Write(0b11010000+1);
		ch = MCAL_I2C_Read(0);
		MCAL_I2C_Stop_Condition();
		PORTA = ch ;
	}
#endif
#ifdef SLAVE
	MCAL_I2C_Set_Address(0b11010000);
	while(1)
	{
		MCAL_I2C_Read(1);
		MCAL_I2C_Write(ch++);
	}

#endif
	return 0;
}



