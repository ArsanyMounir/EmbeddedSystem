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
	int no,i;
	printf("Enter no of elements :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&no);
	while(no>100||no<0)
	{
		printf("invalid input , range should be between 1 and 100 \n");
		printf("Please re-enter no of elements");
		fflush(stdin);fflush(stdout);
		scanf("%d",&no);
	}
	printf("Enter elements of array :\n");
	for (i=0;i<no;i++)
	{
		printf("Enter element %d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&m[i]);
	}
	printf("Enter the element to be searched :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&element);
	for(i=0;i<no;i++)
	{
		if(m[i]==element)
		{
			printf("Number found at the location = %d",i+1);
			return 0;
		}
	}
	printf("Error number not found.");
	return 0;
}
