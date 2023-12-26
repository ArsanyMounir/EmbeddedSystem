/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	int x;
	printf("Enter an integer you want to check: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&x);
	(x%2==0)?printf("%d is even",x):printf("%d is odd",x);
	return 0;
}
