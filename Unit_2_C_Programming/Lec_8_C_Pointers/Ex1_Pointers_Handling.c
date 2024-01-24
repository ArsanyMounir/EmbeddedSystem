/*
 * main.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Arsany
 */

#include"stdio.h"

int main ()
{
	int m,*ab;
	m=29;
	printf("Address of m : 0x%x \n",&m);
	printf("Value of m : %d\n",m);
	ab=&m;
	printf("Address of pointer ab : 0x%x \n",ab);
	printf("Content of pointer ab : %d\n",*ab);
	m = 34;
	printf("Address of pointer ab : 0x%x \n",ab);
	printf("Content of pointer ab : %d\n",*ab);
	*ab = 7;
	printf("Address of m : 0x%x \n",&m);
	printf("Value of m : %d\n",m);



	return 0;
}
