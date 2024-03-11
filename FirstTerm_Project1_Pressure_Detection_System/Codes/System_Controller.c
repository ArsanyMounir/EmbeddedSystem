/*
 * System_Controller.c
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */
#include "System_Controller.h"


void (*SystemController_State)();


void SystemController_init()
{
	SystemController_State= STATE(waiting);
}

STATE_define(idle)
{
	System_Controller_State_ID = idle;

	if(PressureVal < lowThreshold)
	{
		setLedON(GreenON);
		setLedOFF(YellowOFF);
		setLedOFF(RedOFF);
		//Delay(GreenLedTimer);

	}
	else if(PressureVal>=lowThreshold && PressureVal <= highThreshold)
	{
		setLedOFF(GreenOFF);
		setLedON(YellowON);
		setLedOFF(RedOFF);
		//Delay(YellowLedTimer);
	}
	else
	{
		setLedOFF(GreenOFF);
		setLedOFF(YellowOFF);
		setLedON(RedON);
		//Delay(RedLedTimer);
	}
	SystemController_State = STATE(waiting);
}


STATE_define(waiting)
{
	System_Controller_State_ID = waiting;
	SystemController_State = STATE(idle);
	SystemController_State();
}


