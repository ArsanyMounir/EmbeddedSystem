/*
 * Ex2_Factorial_Recursion.c
 *
 *  Created on: Jul 14, 2021
 *      Author: Arsany
 */
#include "stdio.h"

int findFactorial(int x);

void main()
{
	int a;
	printf("Enter an positive integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&a);
	printf("Factorial of %d = %d",a,findFactorial(a));
}

int findFactorial(int x)
{
	if(x==0||x==1)
		return 1;
	else
		return x*findFactorial(x-1);
}
