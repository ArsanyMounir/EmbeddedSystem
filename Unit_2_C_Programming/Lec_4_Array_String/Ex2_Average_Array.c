/*
 * main.c
 *
 *  Created on: Jan 2, 2024
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float m[100],average,sum=0;
	int i,limit;
	printf("Enter the number of data :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&limit);
	while(limit>100||limit<0)
	{
		printf("invalid input , Number should be between 0 and 100 \n");
		printf("Please re-enter the number");
		fflush(stdin);fflush(stdout);
		scanf("%d",&limit);
	}
	for (i=0;i<limit;i++)
	{
		printf("%d.Enter number : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&m[i]);
		fflush(stdin);fflush(stdout);
		sum+=m[i];
	}
	average = sum / limit;

	printf("Average = %.2f",average);

	return 0;
}
