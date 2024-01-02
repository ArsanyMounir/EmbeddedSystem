/*
 * main.c
 *
 *  Created on: Jan 2, 2024
 *      Author: Arsany
 */
#include "stdio.h"
#include "string.h"
int main ()
{
	char string[100];
	int i=0;
	printf("Enter a string :");
	fflush(stdin);fflush(stdout);
	gets(string);

	while(string[i]!= '\0')
	{
		i++;
	}
	printf("length of string %d ",i);
	return 0;
}
