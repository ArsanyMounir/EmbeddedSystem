/*
 * main.c
 *
 *  Created on: Mar 30, 2024
 *      Author: Arsany
 */


#include "MemMap.h"
#include "Utilities.h"



void GPIO_Init(void)
{
	SET_BIT(DDRD,4);
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
}

int main(void)
{
	GPIO_Init();
	volatile int i;
	while(1)
	{
		for(i=7;i>=4;i--)
		{
			SET_BIT(PORTD,i);
			delay(500);
			CLEAR_BIT(PORTD,i);
			delay(500);
		}
	}
}

