/*
 * Ex4_Power_Recursion.c
 *
 *  Created on: Jul 14, 2021
 *      Author: Arsany
 */
#include"stdio.h"

int Power(int x,int e);

void main()
{
	int x,e;
	printf("Enter base number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&x);
	printf("Enter power numbe (positive integer): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&e);
	printf("%d^%d = %d",x,e,Power(x,e));
}

int Power(int x,int e)
{
	if(e==0)
		return 1;
	else
		return x*Power(x,e-1);
}
