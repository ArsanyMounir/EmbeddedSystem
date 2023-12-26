/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float a,b ;
	printf("Enter value of a:");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&b);
	a+=b;
	b=a-b;
	a-=b;
	printf("After swapping, value of a = %.2f",a);
	printf("\nAfter swapping, value of b = %.2f",b);
	return 0;
}
