/*
 * CA.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
//States

enum{
	CA_waiting,
	CA_driving
}CA_State_ID;

STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*CA_state)();



#endif /* CA_H_ */
