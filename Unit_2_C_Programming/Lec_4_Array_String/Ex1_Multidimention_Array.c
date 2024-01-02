/*
 * main.c
 *
 *  Created on: Jan 2, 2024
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float m1[2][2],m2[2][2],sum[2][2];
	int i,j;
	printf("Enter the elements of 1st matrix \n");
	fflush(stdin);fflush(stdout);
	for (i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&m1[i][j]);
			fflush(stdin);fflush(stdout);
		}
	}
	printf("Enter the elements of 2nd matrix \n");
	fflush(stdin);fflush(stdout);
	for (i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&m2[i][j]);
		}
	}
	for (i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum[i][j]=m1[i][j]+m2[i][j];
		}
	}
	printf("Sum of Matrix:\n");
	for (i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%.2f  ",sum[i][j]);
		}
		printf("\n");
	}



	return 0;
}
