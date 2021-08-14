/*
 * main.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Arsany
 */
#include "lifo.h"
#include "stdio.h"
#include "stdint.h"


void main()
{
	USER_DATA_TYPE i,temp=0;
	LIFO_Buffer uart_LIFO;
	//static allocation
	LIFO_Init(&uart_LIFO ,buffer ,5);
	for(i=0;i<7;i++)
	{
		if(LIFO_Add_item(&uart_LIFO,i)==LIFO_No_Error)
			printf("UART_LIFO add item: %d\n",i);
		else
		{
			switch(LIFO_Add_item(&uart_LIFO,i))
			{
			case LIFO_Empty:printf("\n=================ERROR LIFO IS EMPTY=================\n");break;
			case LIFO_NULL:printf("\n=================ERROR LIFO IS NULL=================\n");break;
			case LIFO_Full:printf("\n=================ERROR LIFO IS FULL=================\n");break;
			}
		}
	}
	for(i=0;i<7;i++)
	{
		if(LIFO_get_item(&uart_LIFO,&temp)==LIFO_No_Error)
			printf("UART_LIFO get item: %d\n",temp);
		else
		{
			switch(LIFO_get_item(&uart_LIFO,&temp))
			{
			case LIFO_Empty:printf("\n=================ERROR LIFO IS EMPTY=================\n");break;
			case LIFO_NULL:printf("\n=================ERROR LIFO IS NULL=================\n");break;
			case LIFO_Full:printf("\n=================ERROR LIFO IS FULL=================\n");break;
			}
		}
	}





}

