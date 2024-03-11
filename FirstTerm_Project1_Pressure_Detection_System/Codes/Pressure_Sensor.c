/*
 * Pressure_Sensor.c
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */


#include "Pressure_Sensor.h"


void (*PressureSensor_State)();


int PressureVal;

void PressureSensor_init()
{
	PressureSensor_State = STATE(wait);
}

STATE_define(reading)
{
	PressureSensor_State_ID=reading;
	PressureVal = getPressureVal();
	Delay(1000);
	PressureSensor_State =STATE(wait);
}

STATE_define(wait)
{
	PressureSensor_State_ID=wait;
	PressureSensor_State = STATE(reading);
	PressureSensor_State();
}
