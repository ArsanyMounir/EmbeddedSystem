/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float x,y,z;
	printf("Enter three numbers: ");
	fflush(stdin);	fflush(stdout);
	scanf("%f %f %f",&x,&y,&z);
	if(x>y)
	{
		if(x>z)
			printf("largest number = %.4f",x);
		else
			printf("largest number = %.4f",z);
	}
	else if (y>z)
		printf("largest number = %.4f",y);
	else
		printf("largest number = %.4f",z);
	return 0;
}
