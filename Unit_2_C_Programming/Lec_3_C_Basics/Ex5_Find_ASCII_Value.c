/*
 * Ex5_Find_ASCII_Value.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include "stdio.h"
void main ()
{
	char c;
	printf("Enter a character: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&c);
	printf("ASCII value of %c = %d",c,c);
}


