/*
 * Ex1_Pointers_Handling.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Arsany
 */
#include "stdio.h"

int main()
{
	int m=29;
	int* ab;
	printf("Address of m : 0x%p\n",&m);
	printf("Value of m : %d\n\n",m);
	ab=&m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%p\n",ab);
	printf("Value of pointer ab : %d\n\n",*ab);
	m=34;
	printf("TThe value of m assigned to %d now.\n",m);
	printf("Address of pointer ab : 0x%p\n",ab);
	printf("Value of pointer ab : %d\n\n",*ab);
	*ab=7;
	printf("The pointer variable ab is assigned with the value %d now.\n",*ab);
	printf("Address of m : 0x%p\n",&m);
	printf("Value of m : %d",m);
	return 0;

}

