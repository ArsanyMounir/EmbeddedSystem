/*
 * Ex12_Check_Alphabet.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	char x;
	printf("Enter a character ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&x);
	//ASCII range for lower and upper case alphabets
	//[65,90] for upper , [97,122] for lower
	if((x>=65&&x<=90)||(x>=97&&x<=122))
	{
		printf("%c is an aplhabet",x);
	}
	else
	{
		printf("%c is not an aphabet",x);
	}
}

