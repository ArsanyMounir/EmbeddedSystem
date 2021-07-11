/*
 * Ex2_Average_Array.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	float arr[100],sum=0,avg;
	int n,i;
	printf("Enter the numbers of data: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	while(n>100||n<0)
	{
		printf("invalid input (number should be between 0 and 100)\n");
		printf("Please re-enter the number");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
	{
		printf("%d. Enter number: ",i+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	avg=sum/n;
	printf("Average = %.2f",avg);

}

