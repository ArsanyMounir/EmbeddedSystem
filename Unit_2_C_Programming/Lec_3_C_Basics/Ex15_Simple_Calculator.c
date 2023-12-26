/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Arsany
 */
#include "stdio.h"

int main ()
{
	float x,y;
	char c ;
	while (1)
	{
		printf("Enter operand either + or - or * or /: ");
		fflush(stdin);	fflush(stdout);
		scanf("%c",&c);
		printf("Enter two number:");
		fflush(stdin);	fflush(stdout);
		scanf("%f %f",&x,&y);
		if(c=='+')
			printf ("%.3f %c %.3f = %.3f\n",x,c,y,x+y);
		if(c=='-')
			printf ("%.3f %c %.3f = %.3f\n",x,c,y,x-y);
		if(c=='*')
			printf ("%.3f %c %.3f = %.3f\n",x,c,y,x*y);
		if(c=='/')
		{
			if(y ==0)
				printf("Can't divide by zero\n");
			else
				printf ("%.3f %c %.3f = %.3f\n",x,c,y,x/y);
		}
		printf("press Y to do another operation , N to exit\n");
		fflush(stdin);	fflush(stdout);
		scanf("%c",&c);
		if (c=='y'||c=='Y')
			continue;
		else if (c=='n'||c=='N')
			break;
		else
		{
			printf("Error , Bye Bye");
			break;
		}
	}

	return 0;
}
