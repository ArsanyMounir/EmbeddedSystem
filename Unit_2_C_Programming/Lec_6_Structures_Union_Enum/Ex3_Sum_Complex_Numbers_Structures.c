/*
 * main.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Arsany
 */
#include "stdio.h"

struct SComplex
{
	float real ;
	float img;
};
struct SComplex sumComplex(struct SComplex z1,struct SComplex z2);
struct SComplex readComplex();
void printComplex(struct SComplex x);
int main()
{
	struct SComplex x1,x2,sum;
	sum.img=0;
	x1=readComplex();
	x2=readComplex();
	sum=sumComplex(x1,x2);
	printComplex(sum);
	return 0;

}

struct SComplex sumComplex(struct SComplex z1,struct SComplex z2)
{
	z1.real+=z2.real;
	z1.img+=z2.img;
	return z1;
}
struct SComplex readComplex()
{
	struct SComplex x;
	printf("Enter Real part of the number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x.real);
	printf("Enter imaginary part of the number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x.img);
	return x;

}
void printComplex(struct SComplex x)
{
	printf("Sum = %.2f + %.2fi",x.real,x.img);
}

