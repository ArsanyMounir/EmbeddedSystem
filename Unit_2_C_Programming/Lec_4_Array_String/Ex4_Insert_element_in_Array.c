/*
 * main.c
 *
 *  Created on: Jan 2, 2024
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float m[100],element;
	int i,j,x;
	printf("Enter no of elements :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	while(x>100||x<0)
	{
		printf("invalid input , range should be between 1 and 100 \n");
		printf("Please re-enter no of elements");
		fflush(stdin);fflush(stdout);
		scanf("%d",&x);
	}
	printf("Enter elements of array :\n");
	for (i=0;i<x;i++)
	{
		printf("Enter element %d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&m[i]);
	}
	printf("Enter the element to be inserted :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&element);
	printf("Enter the location :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&j);
	for(i=x;i>=j;i--)
	{
		m[i]=m[i-1];
	}
	m[j-1]=element;
	for(i=0;i<=x;i++)
	{
		printf("%.2f ",m[i]);
	}
	return 0;
}
