/*
 * Ex5_Macro_Circle_Area.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Arsany
 */
#include "stdio.h"
#define pi 3.1415
#define area(x)(pi*(x)*(x))

int main()
{
	int r;
	float a;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&r);
	a=area(r);
	printf("Area = %.3f",a);
	return 0;
}

