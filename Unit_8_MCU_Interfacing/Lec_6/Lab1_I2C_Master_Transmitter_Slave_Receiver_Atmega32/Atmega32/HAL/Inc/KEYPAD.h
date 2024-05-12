/*
 * KEYPAD.h
 *
 *  Created on: Apr 16, 2024
 *      Author: Arsany
 */

#ifndef HAL_INC_KEYPAD_H_
#define HAL_INC_KEYPAD_H_
//========================================================
//						INCLUDES
//========================================================

#include "ATMEGA32_GPIO_Driver.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//			Ports Connections Configurations
//========================================================

#define KEYPAD_ROWS_PORT					GPIOB
#define KEYPAD_COLS_PORT					GPIOD



#define R0									GPIO_PIN_4
#define R1									GPIO_PIN_5
#define R2									GPIO_PIN_6
#define R3									GPIO_PIN_7

#define C0									GPIO_PIN_2
#define C1									GPIO_PIN_3
#define C2									GPIO_PIN_4
#define C3									GPIO_PIN_5


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//			APIs Supported by "HAL KEYPAD DRIVER"
//========================================================

void HAL_KEYPAD_Init(void);
char HAL_KEYPAD_GetChar(void);


#endif /* HAL_INC_KEYPAD_H_ */
