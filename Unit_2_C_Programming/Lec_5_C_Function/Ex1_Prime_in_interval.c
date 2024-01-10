/*
 * main.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Arsany
 */
#include "stdio.h"

int primeFinder (int x );

int main ()
{
	int x,y,i ;
	printf(" Enter two number (intervals): ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&x,&y);
	printf("Prime numbers between %d and %d are :",x,y);
	for(i=x;i<=y;i++)
	{
		if(primeFinder(i))
			printf("%d ", i);
	}
		return 0;
}

int primeFinder (int x)
{
	int j;
	for(j=2;j<x;j++)
	{
		if(x%j==0)
			return 0; //will make if statement false , so it doesn't print this number
	}
	return 1; // end of loop without return means number is prime , so returns 1 whice makes if statment true
}
