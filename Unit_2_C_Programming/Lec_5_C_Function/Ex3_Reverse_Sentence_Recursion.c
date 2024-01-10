/*
 * main.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Arsany
 */
#include "stdio.h"
#include "string.h"
void reverseString ();

int main ()
{

	printf("Enter a sentence :");
	fflush(stdin);fflush(stdout);
	reverseString();
	return 0;
}

void reverseString ()
{
	char c;
	scanf("%c",&c);
	if(c !='\n')
	{
		reverseString();
		printf("%c",c);
	}

}
