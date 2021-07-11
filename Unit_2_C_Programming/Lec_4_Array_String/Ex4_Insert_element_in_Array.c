/*
 * Ex4_Insert_element_in_Array.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	int i,arr[20],number,location,element;
	printf("Enter no of elements : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be inserted : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&element);
	printf("\nEnter the location : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&location);
	for(i=number;i>=location;i--)
	{
		arr[i]=arr[i-1];
	}
	number++;
	arr[location-1]=number;
	for(i=0;i<number;i++)
	{
		printf("%d ",arr[i]);
	}
}

