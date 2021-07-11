/*
 * Ex6_Frequency_of_char_in_string.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Arsany
 */
#include"stdio.h"
#include"string.h"
void main()
{
	char string[100],c;
	int i,counter=0;
	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(string);
	printf("Enter a character to find frequency: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&c);
	//printf("%d",strlen(string));
	for(i=0;i<strlen(string);i++)
	{
		if(c==string[i])
		{
			counter++;
		}

	}
	printf("Frequency of %c = %d",c,counter);
}
