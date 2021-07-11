/*
 * Ex8_Reverse_String.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Arsany
 */
#include"stdio.h"
#include"string.h"
void main()
{
	char string[100],revString[100];
	int i,j;
	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(string);
	for(i=strlen(string)-1,j=0;i>=0&&j<strlen(string);i--,j++)
	{
		revString[j]=string[i];
	}
	revString[j]=0;
	printf("Reverse string is : %s",revString);
}

