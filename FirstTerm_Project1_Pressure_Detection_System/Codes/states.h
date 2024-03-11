/*
 * states.h
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#ifndef STATES_H_
#define STATES_H_

#define STATE_define(_statefun_) void ST_##_statefun_()
#define STATE(_statefun_) ST_##_statefun_
typedef enum{
	GreenON,
	GreenOFF,
	YellowON,
	YellowOFF,
	RedON,
	RedOFF
}LED_State_ID;
extern void (*PressureSensor_State)();
extern void (*SystemController_State)();

#endif /* STATES_H_ */
