/*
 * main.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Arsany
 */

#include"stdio.h"

int main ()
{
	int arr[15],size,i;
	int *ptr = arr;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdout);
	scanf("%d",&size);
	printf("Input %d number of elements in the array : \n",size);
	fflush(stdout);
	for(i=0;i<size;i++)
	{
		printf("Element - %d :",i+1);
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	printf("The elements of array in reverse order\n");
	for(i=size-1;i>=0;i--)
	{
		printf("Element - %d : %d\n",i+1,*(ptr+i));
	}
	return 0;
}
