/*
 * US.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Arsany
 */

#include "US.h"

//Global variables
int US_distance = 0;

void US_init()
{
	//init US Driver
	printf("US Init \n");
}


void (*US_STATE)();
int US_Random_Distance(int l , int r );


STATE_DEFINE(US_busy)
{
	//State Name
	US_STATE_ID = US_busy;
	//State Action
	US_distance = US_Random_Distance(45,55);
	printf("\nUS_Waiting State: distance =%d",US_distance);

	//Send distance Signal
	US_Set_Distance(US_distance);
	//loop to self
	US_STATE=STATE(US_busy);

}


int US_Random_Distance(int l , int r )
{
	int random_number;
	random_number = (rand() % (r-l+1))+l;
	return random_number;
}

