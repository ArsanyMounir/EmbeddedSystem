/*
 * TIMER.C
 *
 *  Created on: Jun 6, 2024
 *      Author: Arsany
 */
#include "TIMER.h"

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
