/*
 * Ex8_Check_Even_or_Odd.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include "stdio.h"
void main()
{
	int x;
	printf("Enter an intger you want to check: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&x);
	if(x%2==0)
	{
		printf("%d is even",x);
	}
	else
	{
		printf("%d is odd",x);
	}
}

