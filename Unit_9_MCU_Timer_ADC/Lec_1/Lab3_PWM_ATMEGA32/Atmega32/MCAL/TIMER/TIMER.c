/*
 * TIMER.C
 *
 *  Created on: Jun 6, 2024
 *      Author: Arsany
 */
#include "TIMER.h"

Ptr_VoidFun_t Callback_OVF;
Ptr_VoidFun_t Callback_CMP;

uint8_t OVF_Value;

TIMER0_Config_t* GL_TIMER0_Config;




void MCAL_WDT_OFF()
{
//	• Bit 4 – WDTOE: Watchdog Turn-off Enable
//	This bit must be set when the WDE bit is written to logic zero. Otherwise, the Watchdog will not
//	be disabled. Once written to one, hardware will clear this bit after four clock cycles. Refer to the
//	description of the WDE bit for a Watchdog disable procedure.
//	• Bit 3 – WDE: Watchdog Enable
//	When the WDE is written to logic one, the Watchdog Timer is enabled, and if the WDE is written
//	to logic zero, the Watchdog Timer function is disabled. WDE can only be cleared if the WDTOE
//	bit has logic level one. To disable an enabled Watchdog Timer, the following procedure must be
//	followed:
//	1. In the same operation, write a logic one to WDTOE and WDE. A logic one must be written to WDE even though it is set to one before the disable operation starts.
//	2. Within the next four clock cycles, write a logic 0 to WDE. This disables the Watchdog.
	WDTCR |= (1<<4)|(1<<3)  ;
	WDTCR = 0x00;

}

void MCAL_WDT_ON()
{
	WDTCR |= (1<<3) ;
	WDTCR |= (1<<1)|(1<<2); //2.1 s delay
	WDTCR &= ~(1<<0); //2.1 s delay


}

void MCAL_TIMER0_Init(TIMER0_Config_t* Config)
{
	GL_TIMER0_Config = Config;
	TCCR0 |= GL_TIMER0_Config->MODE;
	TCCR0 |= GL_TIMER0_Config->CLK;
	TIMSK |= GL_TIMER0_Config->OCM_INTERRUPT;
	TIMSK |= GL_TIMER0_Config->TOVF_INTERRUPT;
}

void MCAL_TIMER0_Stop()
{
	TIMSK &= ~(1<<0);
	TIMSK &= ~(1<<1);
	TIMSK &= ~(1<<2);
}

void MCAL_TIMER0_GetCMPValue(uint8_t* Ticks)
{
	*Ticks = OCR0;
}

void MCAL_TIMER0_SetCMPValue(uint8_t Ticks)
{
	OCR0 = Ticks;
}

void MCAL_TIMER0_GetCounterValue(uint8_t* Ticks)
{
	*Ticks = TCNT0;
}

void MCAL_TIMER0_SetCounterValue(uint8_t Ticks)
{
	TCNT0 = Ticks;
}

void MCAL_TIMER0_GetOverFlowValue(uint8_t* Ticks)
{
	*Ticks = OVF_Value;
}

void MCAL_TIMER0_SetOverFlowValue(uint8_t Ticks)
{
	OVF_Value = Ticks;
}

void MCAL_TIMER0_SetCallBack_OverFlow_Interrupt(Ptr_VoidFun_t  CallBack)
{
	Callback_OVF = CallBack;
}
void MCAL_TIMER0_SetCallBack_Compare_Interrupt(Ptr_VoidFun_t CallBack)
{
	Callback_CMP = CallBack;
}

ISR(TIMER0_COMP_vect)
{
	Callback_CMP();
}

ISR(TIMER0_OVF_vect)
{
	OVF_Value++;
	Callback_OVF();
}
