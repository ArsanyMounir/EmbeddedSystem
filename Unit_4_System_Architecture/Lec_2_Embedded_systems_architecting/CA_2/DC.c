/*
 * DC.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */
#include "DC.h"

int DC_speed=0;

void (*DC_state)();


void DC_init()
{
	printf("DC_init\n");
}

void DC_motor(int s)
{
	DC_speed=s;
	DC_state=STATE(DC_busy);
	printf("\nCA ---------speed = %d-----------> DC\n",DC_speed);
}

STATE_define(DC_idle)
{
	DC_State_ID =DC_idle;

	//call PWM to make speed = DC_speed

	printf("\nDC_idle State: speed =%d",DC_speed);

}

STATE_define(DC_busy)
{
	DC_State_ID =DC_busy;
	//call PWM to make speed = DC_speed
	printf("\nDC_busy State: speed =%d",DC_speed);
	DC_state=STATE(DC_idle);
}



