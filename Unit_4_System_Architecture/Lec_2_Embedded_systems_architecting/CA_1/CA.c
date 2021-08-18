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
int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

void (*CA_state)();
int distanceRandom (int l, int r, int count);
STATE_define(CA_waiting)
{
	CA_State_ID =CA_waiting;
	CA_speed = 0;
	CA_distance=distanceRandom(45,55,1);
	(CA_distance<=CA_threshold) ? (CA_state=STATE(CA_waiting)) : (CA_state=STATE(CA_driving));

	printf("\nCA_Waiting State: distance =%d Speed =%d",CA_distance,CA_speed);
}

STATE_define(CA_driving)
{
	CA_State_ID =CA_driving;
	CA_speed = 30;
	CA_distance=distanceRandom(45,55,1);
	(CA_distance<=CA_threshold)?(CA_state=STATE(CA_waiting)):(CA_state=STATE(CA_driving));

	printf("\nCA_driving State: distance =%d Speed =%d",CA_distance,CA_speed);

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
