/*
 * US.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Arsany
 */

#ifndef US_H_
#define US_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"


//Define states of the module
enum {
	US_busy
}US_STATE_ID;


//declare states for Collision Avoidance : US
STATE_DEFINE(US_busy);

void US_init();

extern void (*US_STATE)();


#endif /* US_H_ */
