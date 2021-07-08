/*
 * Ex15_Simple_Calculator.c
 *
 *  Created on: Jul 8, 2021
 *      Author: Arsany
 */
#include "stdio.h"
void main()
{
	char x;
	float num1,num2;
	printf("Enter operator either + or - or * or / ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&x);
	printf("Enter two operands: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f",&num1,&num2);
	switch(x)
	{
		case'+':printf("%.1f %c %.1f = %.1f",num1,x,num2,num1+num2);break;
		case'-':printf("%.1f %c %.1f = %.1f",num1,x,num2,num1-num2);break;
		case'*':printf("%.1f %c %.1f = %.1f",num1,x,num2,num1*num2);break;
		case'/':printf("%.1f %c %.1f = %.1f",num1,x,num2,num1/num2);break;
		default:printf("error:invalide operator");break;
	}
}

