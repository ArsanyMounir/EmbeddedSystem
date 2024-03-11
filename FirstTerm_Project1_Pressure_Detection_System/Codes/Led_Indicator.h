/*
 * Led_Indicator.h
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#ifndef LED_INDICATOR_H_
#define LED_INDICATOR_H_
#include "states.h"
#include "System_Controller.h"
#include "driver.h"

enum{
	LedON,
	LedOFF
}Led_Indicatore_State_ID;



void LedIndicator_init();

void LedON_State(LED_State_ID LEDState);
void LedOFF_State(LED_State_ID LEDState);

extern void setLedIndicator(LED_State_ID LEDState);


#endif /* LED_INDICATOR_H_ */
