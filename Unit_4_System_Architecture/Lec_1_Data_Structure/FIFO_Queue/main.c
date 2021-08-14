/*
 * main.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Arshy
 */
#include "fifo.h"
#include "stdio.h"
#include "stdint.h"

void main()
{
	USER_DATA_TYPE i, temp=0;
	FIFO_Buffer FIFO_UART;
	if(FIFO_Init(&FIFO_UART , uart_buffer,5)==FIFO_No_Error)
		printf("=================FIFO INIT DONE=================\n");
	for(i=0;i<7;i++)
	{
		printf("FIFO Enqueue (%x) \n",i);
		if(FIFO_enqueue(&FIFO_UART, i)==FIFO_No_Error)
			printf("FIFO Enqueue Done\n");
		else
			printf("FIFO Enqueue Failed\n");
	}

	FIFO_print(&FIFO_UART);

	for(i=0;i<2;i++){
		if(FIFO_dequeue(&FIFO_UART, &temp)==FIFO_No_Error)
			printf("FIFO Dequeue %x done\n",temp);
	}

	FIFO_print(&FIFO_UART);

}

