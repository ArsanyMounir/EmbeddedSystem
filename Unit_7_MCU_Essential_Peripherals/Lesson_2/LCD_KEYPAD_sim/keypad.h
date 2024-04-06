/*
 * keypad.h
 *
 *  Created on: Apr 3, 2024
 *      Author: Arsany
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"Utilities.h"
#include"MemMap.h"

#define KEYPAD_PORT 					PORTD
#define DDR_KEYPAD_PORT 				DDRD
#define KEYPAD_PIN						PIND


#define R0								0
#define R1								1
#define R2								2
#define R3								3
#define C0								4
#define C1								5
#define C2								6
#define C3								7

void KEYPAD_Init(void);
char KEYPAD_GetChar();




#endif /* KEYPAD_H_ */
