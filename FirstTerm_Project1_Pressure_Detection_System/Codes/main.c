/*
 * main.c
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Led_Indicator.h"
#include "System_Controller.h"
#include "Flash_Memory.h"
#include "Pressure_Sensor.h"
#include "states.h"


void setup ()
{
	//---MCAL Init----
	GPIO_INITIALIZATION();
	//---HAL Init---
	PressureSensor_init();
	LedIndicator_init();
	FlashMemory_init(ptrFlashMemory,buffer,SIZE);
	//---Block Init---
	SystemController_init();

}

int main (){
	setup();
	while (1)
	{
		PressureSensor_State();
		Delay(1000);
		SystemController_State ();
		Delay(1000);

	}
	return 0;
}
