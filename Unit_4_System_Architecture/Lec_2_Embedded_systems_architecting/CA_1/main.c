/*
 * main.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Arsany
 */

#include "CA.h"


void setup();



void main()
{
	setup();
	while(1)
	{
		CA_STATE();
	}

}


void setup()
{
	//init all drivers
	//init IRQ
	//init HAL US_Driver DC_Driver
	//init Block
	//Set state pointer for each block
	CA_STATE = STATE(CA_waiting);
}
