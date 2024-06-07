/*
 * main.c
 *
 *  Created on: May 09, 2024
 *      Author: Arsany
 */

#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "TIMER.h"
#include "util/delay.h"



void TIMER_OVF_CallBack()
{
	PORTA = ~PORTA;
}



int main(void)
{
	DDRA = 0xFF;
	sei();
	MCAL_TIMER0_SetCallBack_Compare_Interrupt(TIMER_OVF_CallBack);
	TIMER0_Config_t Config = {CTC,PRESCALING_CLK8,OCIE_ENABLE,TOIE_DISABLE};
	MCAL_TIMER0_SetCMPValue(0xF0);
	MCAL_TIMER0_Init(&Config);

	while(1)
	{

	}

}





