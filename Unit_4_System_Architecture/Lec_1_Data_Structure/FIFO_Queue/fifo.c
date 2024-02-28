/*
 * FIFO.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Arsany
 */
#include "FIFO.h"

//Creating New FIFO CIRCULAR QUEUE
FIFO_Queue_State FIFO_init(FIFO_Queue_t* QUEUE_buf ,USER_DEFINED_DATA_TYPE* buf,unsigned int size )
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
	QUEUE_buf->legnth = size;

	return FIFO_NOERROR;

}

//Adding a new item to the FIFO QUEUE
FIFO_Queue_State FIFO_enqueue(FIFO_Queue_t* QUEUE_buf ,USER_DEFINED_DATA_TYPE item)
{

	//Checking for valid FIFO initialization
	if(!QUEUE_buf->base ||  !QUEUE_buf->head || !QUEUE_buf->tail )
	{
		return FIFO_NULL;
	}
	//Checking if FIFO is FULL
	if(QUEUE_buf->count == QUEUE_buf->legnth)
	{
		return FIFO_FULL;
	}

	//Adding item in the current head pointer space
	*(QUEUE_buf->head) = item;
	//Incrementing the count
	QUEUE_buf->count++;
	//Circular Queue check if the head is at the edge of the Queue and adjusting position
	if(QUEUE_buf->head == ( QUEUE_buf->base + (QUEUE_buf->legnth * sizeof(USER_DEFINED_DATA_TYPE))))
	{
		QUEUE_buf->head = QUEUE_buf->base;
	}
	else
	{
		QUEUE_buf->head ++;
	}

	return FIFO_NOERROR;
}

//Removing item from the FIFO Queue

FIFO_Queue_State FIFO_dequeue(FIFO_Queue_t* QUEUE_buf ,USER_DEFINED_DATA_TYPE* item)
{
	//Checking for valid FIFO initialization
	if(!QUEUE_buf->base ||  !QUEUE_buf->head || !QUEUE_buf->tail )
	{
		return FIFO_NULL;
	}
	//Checking if Queue is EMPTY
	if(QUEUE_buf->count == 0)
	{
		return FIFO_EMPTY;
	}
	//Retrieving the item from tail pointer
	*item = *(QUEUE_buf->tail) ;
	//Decrementing count
	QUEUE_buf->count--;
	//Circular Queue check
	if(QUEUE_buf->tail == ( QUEUE_buf->base + (QUEUE_buf->legnth * sizeof(USER_DEFINED_DATA_TYPE))))
	{
		QUEUE_buf->tail = QUEUE_buf->base;
	}
	else
	{
		QUEUE_buf->tail ++;
	}

	return FIFO_NOERROR;
}


//Printing the current data inside the Queue
void FIFO_print(FIFO_Queue_t* QUEUE_buf)
{
	USER_DEFINED_DATA_TYPE* temp;
	int i ;
	if(!QUEUE_buf->base ||  !QUEUE_buf->head || !QUEUE_buf->tail )
	{
		printf("FIFO is NULL\n");
	}
	if(QUEUE_buf->count == 0)
	{
		printf("FIFO is EMPTY\n");
	}
	temp = QUEUE_buf->tail;
	printf("==========FIFO Print=========\n");
	for (i=0;i<QUEUE_buf->count;i++)
	{
		printf("%x\n",*temp);
		temp++;
	}
	printf("================================\n");




}
