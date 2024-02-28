/*
 * main.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Arsany
 */

#include "stdio.h"
#include "stdlib.h"
#include "LIFO.h"



int main ()
{
	int i;
	USER_DATA_TYPE temp=0;
	LIFO_Buf_t UART_LIFO ;
	//statically allocated LIFO buffer
	LIFO_init(&UART_LIFO,buffer,width);
	for(i=0;i<7;i++)
	{
		if (LIFO_push(&UART_LIFO,i)==LIFO_NOERROR)
		{
			printf("UART_LIFO Push : %d \n",i);
		}
		else
		{
			switch (LIFO_push(&UART_LIFO,i))
			{
			case LIFO_NULL:printf("ERROR LIFO IS NULL \n");break;
			case LIFO_FULL:	printf("ERROR LIFO IS FULL \n");break;
			}
		}
	}
	printf("===================================\n");
	for(i=0;i<7;i++)
	{
		if (LIFO_pop(&UART_LIFO,&temp)==LIFO_NOERROR)
		{
			printf("UART_LIFO Push : %d \n",i);
		}
		else
		{
			switch (LIFO_pop(&UART_LIFO,&temp))
			{
			case LIFO_NULL:printf("ERROR LIFO IS NULL \n");break;
			case LIFO_EMPTY:printf("ERROR LIFO IS EMPTY \n");break;
			}
		}
	}
	printf("===================================\n");




	return 0;
}
