/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	char x;
	printf("Enter a character: ");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&x);
	if(x>=65 && x<=90 ||x>=97 && x<=122)
		printf("%c is an alphabet",x);
	else
		printf("%c is not an alphabet",x);
	return 0;
}
