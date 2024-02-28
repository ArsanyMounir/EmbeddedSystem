/*
 * LIFO.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Arsany
 */

#include "stdio.h"
#include "LIFO.h"

//Creating a new LIFO Buffer
LIFO_State LIFO_init(LIFO_Buf_t* lifo_buf , USER_DATA_TYPE* buf , unsigned int size )
{
	//Checking for address given if null
	if (buf == NULL)
	{
		return LIFO_NULL;
	}
	//initializing components of the LIFO Buffer.
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = size;
	lifo_buf->count = 0;
	return LIFO_NOERROR;
}



//Adding item to the top of the LIFO Buffer
LIFO_State LIFO_push(LIFO_Buf_t* lifo_buf , USER_DATA_TYPE item)
{

	//Checking if given LIFO buffer is valid
	if(!lifo_buf->base || !lifo_buf->head)
	{
		return LIFO_NULL;
	}

	//Checking if given LIFO buffer is FULL
	if(lifo_buf->count==lifo_buf->length)
	{
		return LIFO_FULL;
	}

	//Adding item to current head location
	*(lifo_buf->head) = item;
	//Adjusting the head pointer position to the next location
	lifo_buf->head ++;
	//Incrementing count
	lifo_buf->count ++;

	return LIFO_NOERROR;
}

//Removing item from the LIFO Buffer
LIFO_State LIFO_pop(LIFO_Buf_t* lifo_buf , USER_DATA_TYPE *item)
{
	//Checking if given LIFO buffer is valid
	if(!lifo_buf->base || !lifo_buf->head)
	{
		return LIFO_NULL;
	}

	//Checking if given LIFO buffer is EMPTY
	if(lifo_buf->count==0)
	{
		return LIFO_EMPTY;
	}

	/*Moving head pointer one place to the data needed ,
	since in the push function the last head position is empty/garbage ,
	so we need to adjust to retrieve data*/
	lifo_buf->head--;
	//Decrementing Count
	lifo_buf->count--;
	//point item to the data needed
	*item = *(lifo_buf->head);
	return LIFO_NOERROR;
}


