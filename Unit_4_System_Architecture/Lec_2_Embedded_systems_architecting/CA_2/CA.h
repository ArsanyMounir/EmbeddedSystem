/*
 * CA.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Arsany
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"


//Define states of the module
enum {
	CA_waiting,
	CA_driving
}CA_STATE_ID;


//declare states for Collision Avoidance : CA
STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);

extern void (*CA_STATE)();


#endif /* CA_H_ */
