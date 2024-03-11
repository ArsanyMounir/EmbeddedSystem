/*
 * Flash_Memory.h
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */

#ifndef FLASH_MEMORY_H_
#define FLASH_MEMORY_H_

#define SIZE 10

#include "stdio.h"

typedef struct {
	unsigned int length;
	unsigned int count;
	int* base;
	int* head;
	int* tail;
}FIFO_Queue_t;

typedef enum {
	FIFO_NOERROR,
	FIFO_EMPTY,
	FIFO_FULL,
	FIFO_NULL
}FIFO_Queue_State;

extern void store_STATE(int);
extern void wait_STATE(int);

extern int buffer[SIZE];
extern FIFO_Queue_t* ptrFlashMemory;

FIFO_Queue_State FlashMemory_init(FIFO_Queue_t* QUEUE_buf, int* buf, unsigned int size );
FIFO_Queue_State FlashMemory_enqueue (FIFO_Queue_t* QUEUE_buf,int* PressureVal);

#endif /* FLASH_MEMORY_H_ */
