/*
 * main.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Arsany
 */
#include "stdio.h"
#include "string.h"
int Power (int x,int y);

int main ()
{
	int z,n;
	printf("Enter base number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&z);
	printf("Enter power number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	printf("%d ^ %d = %d",z,n,Power(z,n));

	return 0;
}

int Power (int x,int y)
{
	if(y==0)
		return 1;
	else
		return x* Power(x,y-1) ;

}
