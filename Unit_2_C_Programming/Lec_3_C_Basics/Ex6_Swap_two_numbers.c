/*
 * Ex6_Swap_two_numbers.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include "stdio.h"
void main ()
{
	float a,b,temp;
	printf("Enter value of a: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %f \n",a);
	printf("After swapping, value of b = %f",b);
}

