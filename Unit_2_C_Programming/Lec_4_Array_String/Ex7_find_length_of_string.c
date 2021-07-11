/*
 * Ex7_find_length_of_string.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	char string[100];
	int i=0;
	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(string);
	while(string[i]!=0)
	{
		i++;
	}
	printf("Length of string: %d",i);
}

