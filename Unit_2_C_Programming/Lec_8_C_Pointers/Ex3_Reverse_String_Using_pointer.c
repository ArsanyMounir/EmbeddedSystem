/*
 * Ex3_Reverse_String_Using_pointer.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Arsany
 */
#include "stdio.h"
#include "string.h"
int main()
{
	char str[50];
	char rev_str[50];
	char* ptr=str;
	int i;
	printf("Input a string :");
	fflush(stdin);fflush(stdout);
	scanf("%s",str);
	i=strlen(str);
	ptr+=i-1;
	for(i=0;i<strlen(str);i++,ptr--)
	{
		rev_str[i]=*ptr;
	}
	rev_str[i]='\0';
	printf("Reverse of the string is : %s",rev_str);
	return 0;
}

