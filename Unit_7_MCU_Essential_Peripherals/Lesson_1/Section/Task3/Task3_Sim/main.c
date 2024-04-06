/*
 * main.c
 *
 *  Created on: Mar 31, 2024
 *      Author: Arsany
 */


#include "MemMap.h"
#include "Utilities.h"


void GPIO_Init(void)
{
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	SET_BIT(DDRC,6);
	SET_BIT(DDRC,7);
}

int main(void)
{
	GPIO_Init();
	volatile int i,j;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				PORTC = 0b1011|(i<<4);
				delay(250);
				PORTC = 0b0111|(j<<4);
				delay(250);
			}
		}

	}
}

