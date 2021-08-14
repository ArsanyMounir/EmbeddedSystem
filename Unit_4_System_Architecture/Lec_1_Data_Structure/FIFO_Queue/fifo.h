/*
 * fifo.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Arshy
 */
#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"

//USER Configuration
//Select Data type (uint8_t,uint16_t,uint32_t)
#define USER_DATA_TYPE uint8_t
//Select buffer width
#define width 5
USER_DATA_TYPE uart_buffer[width];

//FIFO Type definitions
typedef struct{
	unsigned int length;
	unsigned int count;
	USER_DATA_TYPE* base;
	USER_DATA_TYPE* head;
	USER_DATA_TYPE* tail;
}FIFO_Buffer;

typedef enum{
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Empty,
	FIFO_NULL
}FIFO_Status;

//APIs
FIFO_Status FIFO_Init (FIFO_Buffer* FIFO_Buf,USER_DATA_TYPE* buf, uint32_t length);
FIFO_Status FIFO_enqueue (FIFO_Buffer* FIFO_Buf,USER_DATA_TYPE item);
FIFO_Status FIFO_dequeue (FIFO_Buffer* FIFO_Buf,USER_DATA_TYPE* item);
FIFO_Status FIFO_FULL (FIFO_Buffer* FIFO_Buf);
void FIFO_print(FIFO_Buffer* FIFO_Buf);


#endif /* FIFO_H_ */
