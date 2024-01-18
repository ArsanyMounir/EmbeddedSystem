/*
 * main.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Arsany
 */
#include "stdio.h"

struct STest
{
	char name[32];
	float salary;
	int x;
}test1;
union UNUMTest
{
	char name[32];
	float salary;
	int x;
}test2;

int main()
{
	printf("size of union = %d",sizeof(test2));
	printf("\nsize of structure = %d",sizeof(test1));
	return 0;
}
