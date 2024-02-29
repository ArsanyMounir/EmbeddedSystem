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


void US_Set_Distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold) ? (CA_STATE=STATE(CA_waiting)):(CA_STATE=STATE(CA_driving));
	printf("\nUS ---------distance = %d-----------> CA\n",CA_distance);

}




STATE_DEFINE(CA_waiting)
{
	//State Name
	CA_STATE_ID = CA_waiting;
	printf("\nCA_Waiting State: distance =%d Speed =%d",CA_distance,CA_speed);
	//State Action
	CA_speed = 0;
	//Send speed signal to DC motor module
	DC_motor(CA_speed);
}

STATE_DEFINE(CA_driving)
{
	//State Name
	CA_STATE_ID = CA_driving;
	printf("\nCA_driving State: distance =%d Speed =%d",CA_distance,CA_speed);
	//State Action
	CA_speed = 30;
	//Send speed signal to DC motor module
	DC_motor(CA_speed);
}


