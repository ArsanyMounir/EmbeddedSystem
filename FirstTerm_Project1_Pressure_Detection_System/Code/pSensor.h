/*
 * pSensor.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Arshy
 */

#ifndef PSENSOR_H_
#define PSENSOR_H_
#include"states.h"
#include"driver.h"
enum{
	reading
}pSensor_State_ID;

STATE_define(reading);

extern void (*pSensor_State)();


#endif /* PSENSOR_H_ */
