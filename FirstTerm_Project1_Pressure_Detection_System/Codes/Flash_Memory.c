/*
 * Flash_Memory.c
 *
 *  Created on: Mar 10, 2024
 *      Author: Arsany
 */
#include "Flash_Memory.h"


FIFO_Queue_t FlashMemory;
FIFO_Queue_t* ptrFlashMemory = &FlashMemory;
int buffer[SIZE];

enum {
	store,
	wait
}FlashMemory_State_ID;

void (*FlashMemory_State)(int);


FIFO_Queue_State FlashMemory_init(FIFO_Queue_t* QUEUE_buf, int* buf, unsigned int size )
{
	//Checking for address given if null
		if(buf == NULL)
		{
			return FIFO_NULL;
		}

		//initializing components of the FIFO Circular Queue.
		QUEUE_buf->base = buf;
		QUEUE_buf->head = buf;
		QUEUE_buf->tail = buf;
		QUEUE_buf->count = 0;
		QUEUE_buf->length = size;

		FlashMemory_State = wait_STATE;

		return FIFO_NOERROR;


}


FIFO_Queue_State FlashMemory_enqueue (FIFO_Queue_t* QUEUE_buf,int* PressureVal)
{
	//Checking for valid FIFO initialization
		if(!QUEUE_buf->base ||  !QUEUE_buf->head || !QUEUE_buf->tail )
		{
			return FIFO_NULL;
		}
		//Checking if FIFO is FULL
		if(QUEUE_buf->count == QUEUE_buf->length)
		{
			return FIFO_FULL;
		}

		//Adding PressureVal in the current head pointer space
		*(QUEUE_buf->head) = PressureVal;
		//Incrementing the count
		QUEUE_buf->count++;
		//Circular Queue check if the head is at the edge of the Queue and adjusting position
		if(QUEUE_buf->head == ( QUEUE_buf->base + (QUEUE_buf->length * sizeof(int))))
		{
			QUEUE_buf->head = QUEUE_buf->base;
		}
		else
		{
			QUEUE_buf->head ++;
		}

		return FIFO_NOERROR;
}


void store_STATE(int PressureVal)
{
	FlashMemory_State_ID= store;
	FlashMemory_enqueue(ptrFlashMemory, &PressureVal);
	FlashMemory_State_ID = wait;
}


void wait_STATE(int PressureVal)
{
	FlashMemory_State_ID = wait;
	if(ptrFlashMemory->count!=ptrFlashMemory->length)
	{
		FlashMemory_State = store_STATE;
		FlashMemory_State(PressureVal);
	}
	else
	{
		FlashMemory_State = wait_STATE;
	}

}




