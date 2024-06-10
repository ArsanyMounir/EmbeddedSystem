/*
 * PWM.c
 *
 *  Created on: Jun 7, 2024
 *      Author: Arsany
 */
#include "PWM.h"


void MCAL_PWM_Init(PWM_Config_t* Config)
{
	TCCR0|= Config->MODE;
	TCCR0|= Config->CLK;
	TCCR0|= Config->CMP_MODE;




}
void MCAL_PWM_Start(PWM_Config_t* Config,uint8_t duty_cycle)
{
	if(Config->CMP_MODE == INVERTING)
	{
		OCR0 = 255-(255*duty_cycle/100);
	}
	else if (Config->CMP_MODE == NON_INVERTING)
	{
		OCR0 = (255*duty_cycle/100);
	}
}
