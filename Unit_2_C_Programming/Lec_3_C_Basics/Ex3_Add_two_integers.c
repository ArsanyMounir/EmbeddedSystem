/*
 * Ex3_Add_two_integers.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include "stdio.h"
void main ()
{
	int num1,num2;
	printf("Enter two integers: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d %d",&num1,&num2);
	printf("Sum: %d",num1+num2);
}

