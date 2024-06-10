/*
 * TIMER.h
 *
 *  Created on: Jun 6, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_TIMER_H_
#define MCAL_INC_TIMER_H_

#include "ATMEGA32.h"
#include "avr/interrupt.h"
#include "avr/io.h"
typedef void(*Ptr_VoidFun_t)(void);


typedef enum
{
	NORMAL,
	CTC=0x08
}TIMER0_MODE_t;

typedef enum
{
	NO_CLK,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING
}TIMER0_CLK_t;


typedef enum
{
	OCIE_DISABLE= 0x00,
	OCIE_ENABLE = 0x02
}OCMIE0_t;

typedef enum
{
	TOIE_DISABLE = 0x00,
	TOIE_ENABLE = 0x01
}TOVFIE0_t;



typedef struct
{
	TIMER0_MODE_t MODE;
	TIMER0_CLK_t CLK;
	OCMIE0_t OCM_INTERRUPT;
	TOVFIE0_t TOVF_INTERRUPT;
}TIMER0_Config_t;








void MCAL_WDT_OFF();
void MCAL_WDT_ON();



void MCAL_TIMER0_Init(TIMER0_Config_t* Config);
void MCAL_TIMER0_Stop();
void MCAL_TIMER0_GetCMPValue(uint8_t* Ticks);
void MCAL_TIMER0_SetCMPValue(uint8_t Ticks);
void MCAL_TIMER0_GetCounterValue(uint8_t* Ticks);
void MCAL_TIMER0_SetCounterValue(uint8_t Ticks);
void MCAL_TIMER0_GetOverFlowValue(uint8_t* Ticks);
void MCAL_TIMER0_SetOverFlowValue(uint8_t Ticks);

void MCAL_TIMER0_SetCallBack_OverFlow_Interrupt(Ptr_VoidFun_t  CallBack);
void MCAL_TIMER0_SetCallBack_Compare_Interrupt(Ptr_VoidFun_t  CallBack);









#endif /* MCAL_INC_TIMER_H_ */
