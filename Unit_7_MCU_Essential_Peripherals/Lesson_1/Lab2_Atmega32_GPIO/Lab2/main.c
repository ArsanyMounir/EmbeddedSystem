/*
 * main.c
 *
 *  Created on: Sep 26, 2021
 *      Author: Arshy
 */


#include "MemMap.h"
#include "Utilities.h"

#define F_CPU 8000000UL

int main(void)
{
	SetBit(DDRD,5);
	SetBit(DDRD,6);
	SetBit(DDRD,7);
	SetBit(DDRD,4);
	volatile int x;
	while(1)
	{
		for(x=7;x>=4;x--)
		{
			SetBit(PORTD,x);
			Delay(500);
			ResetBit(PORTD,x);
			Delay(500);
		}
	}

}
