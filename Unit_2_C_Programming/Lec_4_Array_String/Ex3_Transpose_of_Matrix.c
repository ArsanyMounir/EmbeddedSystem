/*
 * main.c
 *
 *  Created on: Jan 2, 2024
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float m[10][10],t[10][10];
	int i,j,r,c;
	printf("Enter rows and column of matrix :");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&r,&c);
	while(r>10||r<0||c<0||c>10)
	{

		printf("invalid input , range should be between 1 and 10 \n");
		printf("Please re-enter rows and columns");
		fflush(stdin);fflush(stdout);
		scanf("%d %d",&r,&c);
	}
	printf("Enter elements of matrix :\n");
	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element a%d%d : ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&m[i][j]);
		}
	}
	printf("Entered matrix: \n");
	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%.2f ",m[i][j]);
			t[j][i]=m[i][j]; // calculating the transpose while printing rather than using another loop
		}
		printf("\n");
	}
	printf("Transpose of Matrix: \n");
	for (i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%.2f ",t[i][j]);
		}
		printf("\n");
	}

	return 0;
}
