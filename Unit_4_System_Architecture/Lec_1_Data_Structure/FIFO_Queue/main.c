/*
 * main.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Arsany
 */

#include "FIFO.h"

int main()
{
	int i ;
	FIFO_Queue_t FIFO_UART;
	USER_DEFINED_DATA_TYPE item;
	if(FIFO_init(&FIFO_UART,Buffer,FIFO_SIZE)==FIFO_NOERROR)
	{
		printf("===============FIFO init done==============\n");
	}
	for(i=0;i<7;i++)
	{
		if(FIFO_enqueue(&FIFO_UART,i)==FIFO_NOERROR)
		{
			printf("FIFO Enqueue %d Done \n",i);
		}
		else
		{
			switch(FIFO_enqueue(&FIFO_UART,i))
			{
				case FIFO_NULL:printf("ERROR FIFO Address is NULL\n");break;
				case FIFO_FULL:printf("ERROR FIFO is FULL\n");break;
			}
		}
	}


	FIFO_print(&FIFO_UART);


	for(i=0;i<2;i++)
	{
		if(FIFO_dequeue(&FIFO_UART,&item)==FIFO_NOERROR)
		{
			printf("FIFO dequeue %d Done \n",item);
		}
		else
		{
			switch(FIFO_dequeue(&FIFO_UART,&item))
			{
				case FIFO_NULL:printf("ERROR FIFO Address is NULL\n");break;
				case FIFO_EMPTY:printf("ERROR FIFO is EMPTY\n");break;
			}
		}
	}

	FIFO_print(&FIFO_UART);


	return 0;
}
