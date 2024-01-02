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
	char string[100],flip[100];
	int i,length;
	printf("Enter a string :");
	fflush(stdin);fflush(stdout);
	gets(string);
	length = strlen(string);

	for(i=0;i<length;i++)
	{
		flip[(length-1)-i]= string[i];
	}
	flip[length]='\0';
	printf("Reverse of string : %s ",flip);
	return 0;
}
