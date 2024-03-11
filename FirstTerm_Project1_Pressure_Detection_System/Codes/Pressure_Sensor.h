/*
 * Pressure_Sensor.h
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "states.h"
#include "driver.h"


enum{
	reading,
	wait
}PressureSensor_State_ID;


void PressureSensor_init();


extern STATE_define(reading);
extern STATE_define(wait);



#endif /* PRESSURE_SENSOR_H_ */
