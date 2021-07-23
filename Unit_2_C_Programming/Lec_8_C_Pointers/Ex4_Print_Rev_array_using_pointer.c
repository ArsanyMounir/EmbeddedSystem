/*
 * Ex4_Print_Rev_array_using_pointer.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Arsany
 */
#include "stdio.h"
int main()
{
	int arr[15],i,num;
	int* ptr=arr;
	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	printf("Input %d number of elements in the array :\n",num);
	for(i=0;i<num;i++,ptr++)
	{
		printf("element %d :",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",ptr);
	}
	ptr--;
	printf("\nThe elements of array in reverse order are :");
	for(i=num;i>0;i--,ptr--)
	{
		printf("\nelement %d : %d",i,*ptr);
	}
	return 0;
}

