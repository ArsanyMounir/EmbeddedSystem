/*
 * main.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Arsany
 */
#include "stdio.h"

int factorial (int x );

int main ()
{
	int x ;
	printf(" Enter a positive integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if (x<0)
	{
		printf("Error ,number is negative.");
	}
	else if (x %1 !=0 )
	{
		printf("Error ,number isn't an integer");
	}
	printf("Factorial of %d = %d",x,factorial(x));
	return 0;
}

int factorial (int x)
{
	if(x==1||x==0)
		return 1;
	else
		return x*factorial(x-1);
}
