/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */
#include"stdio.h"
#include"CA.h"

void setup()
{
	//init all drivers
	//init IRQ
	//init HAL US_Driver DC_Motor
	//init BLOCK
	//Set States pointer
	CA_state= STATE(CA_waiting);
}




void main()
{
	volatile int i;
	setup();
	while(1)
	{
		CA_state();
		for(i=1;i<1000;i++);
	}
}
