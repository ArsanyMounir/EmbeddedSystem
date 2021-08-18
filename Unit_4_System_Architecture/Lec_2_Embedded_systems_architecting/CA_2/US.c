/*
 * US.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */
#include "US.h"
#include"state.h"
int US_distance=0;

void (*US_state)();
int distanceRandom (int l, int r, int count);


void US_init()
{
	printf("US_init\n");

}
STATE_define(US_busy)
{
	US_State_ID =US_busy;
	US_distance=distanceRandom(45,55,1);
	printf("\nUS_Waiting State: distance =%d",US_distance);
	US_Set_distance(US_distance);
	US_state=STATE(US_busy);
}


int distanceRandom (int l, int r, int count)
{
	int i, rand_num;
	for(i=0; i<count; i++)
	{
		rand_num =( rand() % (r - l + 1) ) + l;
	}
	return rand_num;

}

