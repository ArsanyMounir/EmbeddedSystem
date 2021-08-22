/*
 * Controller.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Arshy
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include"states.h"
enum{
	idle,
	HighPressure
}Controller_State_ID;

STATE_define(idle);
STATE_define(HighPressure);

extern void (*Controller_State)();

#endif /* CONTROLLER_H_ */
