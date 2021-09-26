/*
 * main.c
 *
 *  Created on: Sep 26, 2021
 *      Author: Arshy
 */


#include "MemMap.h"
#include "Utilities.h"
#include "util/delay.h"
#define F_CPU 8000000UL

int main(void)
{
	DDRA = 0xff;
	PORTA = 0x00;
	volatile int x;
	while(1)
	{
		for(x=0;x<8;x++)
		{
			PORTA |=(1<<x);
			_delay_ms(200);
		}
		for(x=7;x>=0;x--)
		{
			PORTA &= ~(1<<x);
			_delay_ms(200);
		}
	}

}
