/*
 * Ex9_Check_Vowel_or_Constant.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include "stdio.h"
void main()
{
	char x;
	printf("Enter an alphabet: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&x);
	switch(x)
	{
		case'a':
		case'A':
		case'e':
		case'E':
		case'i':
		case'I':
		case'o':
		case'O':
		case'u':
		case'U':printf("%c is a vowel",x);break;
		default:printf("%c is a consonant",x);break;
	}
}

