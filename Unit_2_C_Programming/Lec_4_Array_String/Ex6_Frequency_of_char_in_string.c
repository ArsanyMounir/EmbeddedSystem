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
	char string[100],character;
	int i,counter=0,length;
	printf("Enter a string :");
	fflush(stdin);fflush(stdout);
	gets(string);
	printf("Enter a charcter to find frequency :");
	fflush(stdin);fflush(stdout);
	scanf("%c",&character);
	length = strlen(string);
	for(i=0;i<length;i++)
	{
		if (character == string[i])
			counter++;
	}
	printf("Frequency of %c = %d ",character , counter);
	return 0;
}
