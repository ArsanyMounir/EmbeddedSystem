/*
 * Ex6_UNION_Vs_Struct_Size.c
 *
 *  Created on: Jul 19, 2021
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
