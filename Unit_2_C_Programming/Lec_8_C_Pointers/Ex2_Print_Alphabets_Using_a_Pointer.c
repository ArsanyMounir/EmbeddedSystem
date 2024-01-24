/*
 * main.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Arsany
 */

#include"stdio.h"

int main ()
{
	char alphabet[26];
	char*ptr = alphabet;
	int i;
	for(i=0;i<26;i++)
	{
		*ptr=i+'A';
		ptr++;
	}
	ptr=alphabet;
	printf("The Alphabets Are :");
	for(i=0;i<26;i++)
	{
		printf("%c ", *ptr+i);
	}
	return 0;
}
