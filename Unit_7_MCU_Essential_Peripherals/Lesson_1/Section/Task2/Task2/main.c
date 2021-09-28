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
	ResetBit(DDRC,0);
	SetBit(PORTC,0);
	PORTA = 0x00;
	volatile int x;
	while(1)
	{
		for(x=0;x<=8;x++)
		{
			while(ReadBit(PINC,0)==1);
			SetBit(PORTA,x);
			_delay_ms(300);
		}
		PORTA = 0x00;
	}

}
