/*
 * Ex10_Largest_Number.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	float x,y,z;
	printf("Enter three numbers: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f %f",&x,&y,&z);
	if(x>y)
	{
		if(x>z)
		{
			printf("Largest Number = %.2f",x);
		}
		else
		{
			printf("Largest Number = %.2f",z);
		}
	}
	else if (y>z)
	{
		printf("Largest Number = %.2f",y);
	}
	else
	{
		printf("Largest Number = %.2f",z);
	}
}

