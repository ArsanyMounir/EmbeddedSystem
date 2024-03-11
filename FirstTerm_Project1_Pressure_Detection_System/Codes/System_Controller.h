/*
 * System_Controller.h
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#ifndef SYSTEM_CONTROLLER_H_
#define SYSTEM_CONTROLLER_H_


#include "states.h"
#include "Led_Indicator.h"
#define GreenLedTimer 1000 // 3 seconds delay
#define YellowLedTimer 2000 // 12 seconds delay
#define RedLedTimer 3000// 18 seconds delay
#define lowThreshold 10
#define highThreshold 20

enum{
	idle,
	waiting
}System_Controller_State_ID;



extern void SystemController_init();

extern STATE_define(idle);
extern STATE_define(waiting);

extern int PressureVal;
extern void setLedOFF (LED_State_ID LEDState);
extern void setLedON (LED_State_ID LEDState);


#endif /* SYSTEM_CONTROLLER_H_ */
