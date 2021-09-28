/*
 * MemMap.h
 *
 *  Created on: Sep 26, 2021
 *      Author: Arshy
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "stdint.h"

#define PORTA *(volatile uint8_t *)(0x3B)
#define DDRA *(volatile uint8_t *)(0x3A)
#define PINA *(volatile uint8_t *)(0x39)

#define PORTC *(volatile uint8_t *)(0x35)
#define DDRC *(volatile uint8_t *)(0x34)
#define PINC *(volatile uint8_t *)(0x33)
#endif /* MEMMAP_H_ */
