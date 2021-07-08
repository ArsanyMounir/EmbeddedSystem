/*
 * Ex14_Find_Factorial.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	int x,i,factorial=1;
	printf("Enter an integer: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&x);
	if(x<0)
	{
		printf("Error!!! Factorial if negative numbers doesn't exist");
	}
	else
	{
		for(i=1;i<=x;i++)
		{
			factorial*=i;
		}
		printf("Factorial = %d",factorial);
	}


}


