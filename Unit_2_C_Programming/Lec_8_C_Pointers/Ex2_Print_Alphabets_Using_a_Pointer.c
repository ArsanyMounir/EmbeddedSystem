/*
 * Ex2_Print_Alphabets_Using_a_Pointer.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Arsany
 */
#include "stdio.h"
int main()
{
	char alphabets[26];
	char*ptr=alphabets;
	int i;
	for(i=0;i<26;i++,ptr++)
	{
		*ptr=i+'a';
	}
	ptr=alphabets;
	printf("Alphabets are:\n");

	for(i=0;i<26;i++,ptr++)
	{
		printf("%c  ",*ptr);
	}
	return 0;
}

