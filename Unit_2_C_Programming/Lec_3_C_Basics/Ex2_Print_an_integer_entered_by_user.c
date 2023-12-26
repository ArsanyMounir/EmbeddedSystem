/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	int input ;
	printf("Enter an integer : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&input);
	printf("You entered: %d",input);
	return 0;
}
