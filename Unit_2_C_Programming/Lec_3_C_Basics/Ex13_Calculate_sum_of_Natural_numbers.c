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
	int sum=0;
	printf("Enter an integer: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&x);
	if(x<=0)
		printf("%d is not postive",x);
	else
	{
		for(i=1;i<=x;i++)
		{
			sum+=i;
		}
		printf("sum = %d",sum);
	}
	return 0;
}
