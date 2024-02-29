/*
 * CA.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Arsany
 */

#include "CA.h"

//Global variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;



void (*CA_STATE)();
int US_Random_Distance(int l , int r );


STATE_DEFINE(CA_waiting)
{
	//State Name
	CA_STATE_ID = CA_waiting;
	//State Action
	CA_speed = 0;
	//Event Check
	CA_distance = US_Random_Distance(45,55);
	(CA_distance <= CA_threshold) ? (CA_STATE=STATE(CA_waiting)):(CA_STATE=STATE(CA_driving));
	printf("Waiting State : Distance = %d Speed = %d\n",CA_distance,CA_speed);
}

STATE_DEFINE(CA_driving)
{
	//State Name
	CA_STATE_ID = CA_driving;
	//State Action
	CA_speed = 30;
	//Event Check
	CA_distance = US_Random_Distance(45,55);
	(CA_distance <= CA_threshold) ? (CA_STATE=STATE(CA_waiting)):(CA_STATE=STATE(CA_driving));
	printf("Driving State : Distance = %d Speed = %d\n",CA_distance,CA_speed);

}

int US_Random_Distance(int l , int r )
{
	int random_number;
	random_number = (rand() % (r-l+1))+l;
	return random_number;
}

