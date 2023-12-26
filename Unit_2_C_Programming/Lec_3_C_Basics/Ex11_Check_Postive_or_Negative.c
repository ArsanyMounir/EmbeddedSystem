/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float x;
	printf("Enter a number: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&x);
	if(x>0)
		printf("%.2f is postive",x);
	else if (x==0)
		printf("You entered zero");
	else
		printf("%.2f is negative",x);
	return 0;
}
