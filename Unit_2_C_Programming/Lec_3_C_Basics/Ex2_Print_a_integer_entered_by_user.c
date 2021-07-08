/*
 * Ex2_Print_a_integer_entered_by_user.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include "stdio.h"
void main ()
{
	int number;
	printf("Enter a integer: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&number);
	printf("You entered: %d",number);
}




