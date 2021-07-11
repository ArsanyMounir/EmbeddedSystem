/*
 * Ex5_Search_in_Array.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	int elements, arr[40],i,findElement;
	printf("Enter no of elemets : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&elements);
	for(i=0;i<elements;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the elemets to be searched : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&findElement);
	for(i=0;i<elements;i++)
	{
		if(arr[i]==findElement)
			break;
	}
	if(i<elements)
	{
		printf("Number found at location = %d",i+1);
	}
	else
	{
		printf("element not found");
	}
}

