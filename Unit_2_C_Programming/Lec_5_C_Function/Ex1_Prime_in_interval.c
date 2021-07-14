/*
 * Ex1_Prime_in_interval.c
 *
 *  Created on: Jul 14, 2021
 *      Author: Arsany
 */
#include "stdio.h"

int findPrime(int a);
void main()
{
	int a,b,i;
	printf("Enter two numbers (Intervals): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&a,&b);
	printf("Prime number between %d and %d are: ",a,b);
	for(i=a;i<=b;i++)
	{
		if(findPrime(i))
			printf("%d ",i);
		else
			continue;
	}
}

int findPrime(int a)
{
	int j,check;
	for(j=2;j<a;j++)
	{
		if(a%j==0)
			return 0;
	}
	return 1;
}
