/*
 * SevenSeg.h
 *
 *  Created on: Apr 5, 2024
 *      Author: Arsany
 */

#ifndef INC_SEVENSEG_H_
#define INC_SEVENSEG_H_
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32F103X6.h"

#define ZERO 	0x64
#define ONE 	0x79
#define TWO 	0x24
#define THREE 	0x30
#define FOUR 	0x4C
#define FIVE 	0x12
#define SIX 	0x02
#define SEVEN 	0x19
#define EIGHT 	0x00
#define NINE 	0x10

void HAL_Seven_segment_init(void);

#endif /* INC_SEVENSEG_H_ */
