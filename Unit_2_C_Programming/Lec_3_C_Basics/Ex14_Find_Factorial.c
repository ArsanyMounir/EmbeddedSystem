/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	int x,i;
	unsigned long long int fact=1;
	printf("Enter a postive integer: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&x);
	if(x<0)
		printf("%d is not postive",x);
	else
	{
		for(i=1;i<=x;i++)
		{
			fact*=i;
		}
		printf("%d factorial = %lu",x,fact);
	}
	return 0;
}
