/*
 * FIFO.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Arsany
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdint.h"
#include "stdio.h"

//select data type (uint8_t,uint16_t,uint32_t)

#define USER_DEFINED_DATA_TYPE uint32_t

//Select buffer length

#define FIFO_SIZE (unsigned int)5


USER_DEFINED_DATA_TYPE Buffer[FIFO_SIZE];

//type definition of the FIFO

typedef struct {
	unsigned int legnth;
	unsigned int count;
	USER_DEFINED_DATA_TYPE* base;
	USER_DEFINED_DATA_TYPE* head;
	USER_DEFINED_DATA_TYPE* tail;
}FIFO_Queue_t;

typedef enum {
	FIFO_NOERROR,
	FIFO_EMPTY,
	FIFO_FULL,
	FIFO_NULL
}FIFO_Queue_State;



//APIs
FIFO_Queue_State FIFO_init(FIFO_Queue_t* QUEUE_buf ,USER_DEFINED_DATA_TYPE* buf,unsigned int size );

FIFO_Queue_State FIFO_enqueue(FIFO_Queue_t* QUEUE_buf ,USER_DEFINED_DATA_TYPE item);

FIFO_Queue_State FIFO_dequeue(FIFO_Queue_t* QUEUE_buf ,USER_DEFINED_DATA_TYPE* item);

void FIFO_print(FIFO_Queue_t* QUEUE_buf);

#endif /* FIFO_H_ */
