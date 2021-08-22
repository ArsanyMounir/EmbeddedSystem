/*
 * pSensor.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Arshy
 */

#include"pSensor.h"
#include"driver.h"

int Pressure_reading=0;
void(*pSensor_State)();

STATE_define(reading)
{
	pSensor_State_ID=reading;
	Pressure_reading=getPressureVal();
	getPressure(Pressure_reading);
	pSensor_State = STATE(reading);
}


