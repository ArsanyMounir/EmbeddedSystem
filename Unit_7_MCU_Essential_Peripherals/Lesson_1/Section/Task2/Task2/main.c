/*
 * main.c
 *
 *  Created on: Mar 30, 2024
 *      Author: Arsany
 */


#include "MemMap.h"
#include "Utilities.h"


int main(void)
{
	DDRA = 0xFF;
	CLEAR_BIT(DDRC,0);
	SET_BIT(PORTC,0);
	volatile int i=0;
	while(1)
	{
		for(i=0;i<=8;i++)
		{
			while(READ_BIT(PINC,0)== 1);
			SET_BIT(PORTA,i);
			delay(500);
		}
		PORTA = 0x00;
	}
}

