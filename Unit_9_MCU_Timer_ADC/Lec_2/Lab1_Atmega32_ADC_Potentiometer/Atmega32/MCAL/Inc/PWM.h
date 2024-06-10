/*
 * PWM.h
 *
 *  Created on: Jun 7, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_PWM_H_
#define MCAL_INC_PWM_H_


#include "TIMER.h"
#include "avr/io.h"
#include "avr/interrupt.h"

typedef enum {
	PHASE_CORRECT = 0x40,
	FAST_PWM = 0x48
}PWM_MODE_t;

typedef enum {
	INVERTING = 0x30,
	NON_INVERTING = 0x20
}OUTPUT_CMP_MODE_t;


typedef struct{
	PWM_MODE_t MODE;
	TIMER0_CLK_t CLK;
	OUTPUT_CMP_MODE_t CMP_MODE;
}PWM_Config_t;


void MCAL_PWM_Init(PWM_Config_t* Config);
void MCAL_PWM_Start(PWM_Config_t* Config,uint8_t duty_cycle);



#endif /* MCAL_INC_PWM_H_ */
