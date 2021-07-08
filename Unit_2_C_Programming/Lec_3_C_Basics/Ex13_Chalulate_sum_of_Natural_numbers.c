/*
 * Ex13_Chalulate_sum_of_Natural_numbers.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	int x,i,sum=0;
	printf("Enter an integer:");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&x);
	for(i=0;i<=x;i++)
	{
		sum+=i;
	}
	printf("Sum = %d",sum);
}

