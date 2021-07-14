/*
 * Ex3_Reverse_Sentence_Recursion.c
 *
 *  Created on: Jul 14, 2021
 *      Author: Arsany
 */
#include "stdio.h"

void reverseSentence();

void main()
{
	printf("Enter a sentence: ");
	fflush(stdout);
	fflush(stdin);
	reverseSentence();
}

void reverseSentence()
{
	char c;
	scanf("%c",&c);
	if(c!='\n')
	{
		reverseSentence();
		printf("%c",c);
	}

}

