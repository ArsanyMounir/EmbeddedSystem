/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	int x,y ;
	printf("Enter two integers : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d %d",&x,&y);
	printf("Sum: %d",x+y);
	return 0;
}
