/*
 * main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */

#include"CA.h"
#include"US.h"
#include"DC.h"
#include"stdio.h"

void setup()
{
	//init all drivers
	//init IRQ
	//init HAL US_Driver DC_Motor
	//init BLOCK
	US_init();
	DC_init();
	//Set States pointer
	CA_state= STATE(CA_waiting);
	US_state= STATE(US_busy);
	DC_state= STATE(DC_idle);
}




void main()
{
	volatile int i;
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		for(i=1;i<1000;i++);
	}
}
