/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float x,y ;
	printf("Enter two numbers : ");
	fflush(stdin);	fflush(stdout);
	scanf("%f %f",&x,&y);
	printf("Product: %f",x*y);
	return 0;
}
