/*
 * Ex11_Check_Postive_or_Negative.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	float x;
	printf("Enter a number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&x);
	if(x>0)
	{
		printf("%.2f is positive",x);
	}
	else if(x<0)
	{
		printf("%.2f is negative",x);
	}
	else
	{
		printf("You entered zero.");
	}

}
