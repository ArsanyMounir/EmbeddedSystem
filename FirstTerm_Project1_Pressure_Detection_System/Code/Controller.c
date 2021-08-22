/*
 * Controller.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Arshy
 */
#include"driver.h"
#include"Controller.h"
#include"Alarm.h"
#include"pSensor.h"
#include"states.h"
#define threshold 20
unsigned int Pressure_level=0;
unsigned int Alarm_Condition=1;
void(*Controller_State)();

void getPressure(int p)
{
	Pressure_level = p;
	(Pressure_level<=threshold) ? (Controller_State=STATE(idle)) : (Controller_State=STATE(HighPressure));
}

STATE_define(idle)
{
	Controller_State_ID=idle;
	Alarm_Condition=1;
	setAlarm(Alarm_Condition);
}


STATE_define(HighPressure)
{
	Controller_State_ID=HighPressure;
	Alarm_Condition=0;
	setAlarm(Alarm_Condition);
}
