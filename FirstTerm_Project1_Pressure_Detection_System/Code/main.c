#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Alarm.h"
#include "Controller.h"
#include "states.h"
#include "pSensor.h"

void setup()
{
	GPIO_INITIALIZATION();
	pSensor_State=STATE(reading);
	Controller_State=STATE(idle);
	Alarm_State=STATE(AlarmOFF);
}
int main (){
	volatile int i;
	setup();
	while (1)
	{
		pSensor_State();
		Controller_State();
		Alarm_State();
		for(i=1;i<1000;i++);
	}

}
