/*
 * DC.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"

enum{
	DC_idle,
	DC_busy
}DC_State_ID;

STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

extern void (*DC_state)();



#endif /* DC_H_ */
