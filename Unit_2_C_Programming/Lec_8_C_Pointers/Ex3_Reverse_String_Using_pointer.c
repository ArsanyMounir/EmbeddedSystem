/*
 * main.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Arsany
 */

#include"stdio.h"
#include"string.h"
int main ()
{
	char str[50];
	char *ptr = str;
	int size,i;
	printf("Enter String :");
	fflush(stdout);
	gets(str);
	size = strlen(str);
	for(i=size-1;i>=0;i--)
		printf("%c",*(ptr+i));
	return 0;
}
