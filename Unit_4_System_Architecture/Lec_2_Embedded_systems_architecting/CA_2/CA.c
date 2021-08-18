/*
 * CA.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */

#include"state.h"
#include"stdlib.h"
#include"stdio.h"
#include"CA.h"
#include"US.h"
#include"DC.h"

int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

void (*CA_state)();
int distanceRandom (int l, int r, int count);


void US_Set_distance(int d)
{
	CA_distance = d;
	(CA_distance<=CA_threshold) ? (CA_state=STATE(CA_waiting)) : (CA_state=STATE(CA_driving));
	printf("\nUS ---------distance = %d-----------> CA\n",CA_distance);
}


STATE_define(CA_waiting)
{
	CA_State_ID =CA_waiting;
	printf("\nCA_Waiting State: distance =%d Speed =%d",CA_distance,CA_speed);
	CA_speed = 0;
	DC_motor(CA_speed);

}

STATE_define(CA_driving)
{
	CA_State_ID =CA_driving;
	printf("\nCA_driving State: distance =%d Speed =%d",CA_distance,CA_speed);
	CA_speed = 30;
	DC_motor(CA_speed);


}

