/*
 * Ex3_Sum_Complex_Numbers_Structures.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Arsany
 */
#include "stdio.h"

struct SComplex
{
	float Real;
	float Imaginary;
};

struct SComplex add(struct SComplex a,struct SComplex b);

int main()
{
	struct SComplex a,b,sum;
	printf("Enter information for 1st Complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&a.Real,&a.Imaginary);
	printf("Enter information for 2nd Complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&b.Real,&b.Imaginary);
	sum=add(a,b);
	printf("\nSum= %.2f+%.2fi",sum.Real,sum.Imaginary);
	return 0;
}

struct SComplex add(struct SComplex a,struct SComplex b)
{
	struct SComplex sum;
	sum.Real=a.Real+b.Real;
	sum.Imaginary=a.Imaginary+b.Imaginary;
	return sum;
}


