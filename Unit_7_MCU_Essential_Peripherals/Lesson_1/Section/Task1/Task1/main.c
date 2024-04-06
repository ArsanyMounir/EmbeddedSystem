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

	while(1)
	{
		volatile int i;
		for(i=0;i<=7;i++)
		{
			SET_BIT(PORTA,i);
			delay(200);
		}
		for(i=7;i>=0;i--)
		{
			CLEAR_BIT(PORTA,i);
			delay(200);
		}


	}
}

