/*
 * lifo.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Arsany
 */
#include"lifo.h"
#include"stdio.h"




//APIs Implementation

//Adding item to the LIFO Buffer
LIFO_Status LIFO_Add_item (LIFO_Buffer* LIFO_Buf, USER_DATA_TYPE item)
{
	//check LIFO is valid
	if(!LIFO_Buf->base||!LIFO_Buf->head)
		return LIFO_NULL;
	//checking if LIFO is FULL
	if(LIFO_Buf->count==LIFO_Buf->length)
		return LIFO_Full;
	//adding the item
	*(LIFO_Buf->head)=item;
	//adjusting the head pointer position to next location in Buffer
	LIFO_Buf->head++;
	//incrementing count
	LIFO_Buf->count++;
	return LIFO_No_Error;

}


//getting an item from LIFO Buffer
LIFO_Status LIFO_get_item (LIFO_Buffer* LIFO_Buf, USER_DATA_TYPE* item)
{
	//check LIFO is valid
	if(!LIFO_Buf->base||!LIFO_Buf->head)
		return LIFO_NULL;
	//checking if LIFO is Empty
	if(LIFO_Buf->count==0)
		return LIFO_Empty;
	//adjusting the head pointer position to previous location in Buffer
	LIFO_Buf->head--;
	*item= *(LIFO_Buf->head);
	//decrementing count
	LIFO_Buf->count--;
	return LIFO_No_Error;

}

//Creating a new LIFO Buffer
LIFO_Status LIFO_Init (LIFO_Buffer* LIFO_Buf, USER_DATA_TYPE* buffer,unsigned int length)
{
	//checking for dynamic allocation if null
	if(buffer==NULL)
		return LIFO_NULL;

	LIFO_Buf->base=buffer;
	LIFO_Buf->head=buffer;
	LIFO_Buf->length=length;
	LIFO_Buf->count=0;

	return LIFO_No_Error ;
}

