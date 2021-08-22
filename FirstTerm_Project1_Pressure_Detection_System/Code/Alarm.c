/*
 * Alarm.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Arshy
 */
#include"driver.h"
#include"Alarm.h"

int Alarm=1;

void (*Alarm_State)();
void setAlarm(int a)
{
	Alarm = a;
	(Alarm==1) ? (Alarm_State=STATE(AlarmOFF)) : (Alarm_State=STATE(AlarmON));
}

STATE_define(AlarmOFF)
{
	Alarm_State_ID=AlarmOFF;
	Set_Alarm_actuator(1);

}

STATE_define(AlarmON)
{
	Alarm_State_ID=AlarmON;
	Set_Alarm_actuator(0);
	Delay(2000);//assume 2000 = 60sec
}
