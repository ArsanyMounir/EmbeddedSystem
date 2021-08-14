/*
 * fifo.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Arshy
 */

#include "fifo.h"
#include "stdio.h"
#include "stdint.h"


//Creating a new FIFO Queue
FIFO_Status FIFO_Init (FIFO_Buffer* FIFO_Buf,USER_DATA_TYPE* buf,uint32_t length)
{
	//checking for dynamic allocation if null
	if(buf==NULL)
		return FIFO_NULL;
	FIFO_Buf->base=buf;
	FIFO_Buf->head=buf;
	FIFO_Buf->tail=buf;
	FIFO_Buf->length=length;
	FIFO_Buf->count=0;

	return FIFO_No_Error;

}
//Adding item to Queue
FIFO_Status FIFO_enqueue (FIFO_Buffer* FIFO_Buf,USER_DATA_TYPE item)
{
	//check FIFO is valid
	if(!FIFO_Buf->base||!FIFO_Buf->head||!FIFO_Buf->tail)
		return FIFO_NULL;
	//checking if FIFO is FULL
	if(FIFO_FULL(FIFO_Buf)==FIFO_Full)
		return FIFO_Full;
	//adding the item
	*(FIFO_Buf->head)=item;
	//circular Queue, checking position of head and adjusting accordingly
	if(FIFO_Buf->head == (FIFO_Buf->base+(FIFO_Buf->length * sizeof(USER_DATA_TYPE))))
		FIFO_Buf->head=FIFO_Buf->base;
	else
		FIFO_Buf->head++;
	//incrementing count
	FIFO_Buf->count++;
	return FIFO_No_Error;
}

//Removing from Queue
FIFO_Status FIFO_dequeue (FIFO_Buffer* FIFO_Buf,USER_DATA_TYPE* item)
{
	//check FIFO is valid
	if(!FIFO_Buf->base||!FIFO_Buf->head||!FIFO_Buf->tail)
		return FIFO_NULL;
	//checking if FIFO is Empty
	if(FIFO_Buf->count==0)
		return FIFO_Empty;
	*item = *(FIFO_Buf->tail);
	FIFO_Buf->count--;
	//circular Queue, checking position of head and adjusting accordingly
	if(FIFO_Buf->tail == (FIFO_Buf->base+(FIFO_Buf->length * sizeof(USER_DATA_TYPE))))
		FIFO_Buf->tail=FIFO_Buf->base;
	else
		FIFO_Buf->tail++;
	return FIFO_No_Error;
}

//Checking of Queue is FULL
FIFO_Status FIFO_FULL (FIFO_Buffer* FIFO_Buf)
{
	if(!FIFO_Buf->base||!FIFO_Buf->head||!FIFO_Buf->tail)
		return FIFO_NULL;
	if(FIFO_Buf->count==FIFO_Buf->length)
		return FIFO_Full;
	return FIFO_No_Error;
}

//Printing Queue
void FIFO_print(FIFO_Buffer* FIFO_Buf)
{
	USER_DATA_TYPE* temp;
	int i;
	if (FIFO_Buf->count==0)
		printf("FIFO is EMPTY\n");
	else
	{
		temp = FIFO_Buf->tail;
		printf("=================FIFO Print=================\n");
		for(i=0;i<FIFO_Buf->count;i++)
		{
			printf("\t\t\t%x\n",*temp);
			temp++;
		}
	}
	printf("============================================\n");
}
