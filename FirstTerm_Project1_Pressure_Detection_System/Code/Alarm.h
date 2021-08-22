/*
 * Alarm.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Arshy
 */

#ifndef ALARM_H_
#define ALARM_H_
#include"states.h"
#include"driver.h"
enum{
	AlarmOFF,
	AlarmON
}Alarm_State_ID;

STATE_define(AlarmOFF);
STATE_define(AlarmON);

extern void (*Alarm_State)();

#endif /* ALARM_H_ */
