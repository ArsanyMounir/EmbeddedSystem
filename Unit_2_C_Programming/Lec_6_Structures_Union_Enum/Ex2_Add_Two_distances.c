/*
 * main.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Arsany
 */
#include "stdio.h"

struct SDistance
{
	int feet;
	float inches;
};
struct SDistance sumDistance(struct SDistance z1,struct SDistance z2);
struct SDistance readDistance();
void printDistance(struct SDistance x);
int main()
{
	struct SDistance x1,x2,sum;
	sum.feet=0;
	x1=readDistance();
	x2=readDistance();
	sum=sumDistance(x1,x2);
	printDistance(sum);
	return 0;

}
struct SDistance sumDistance(struct SDistance z1,struct SDistance z2)
{
	z1.feet+=z2.feet;
	z1.inches+=z2.inches;
	while(z1.inches/12>1)
		{
		z1.feet++;
		z1.inches-=12;
		}
	return z1;
}
struct SDistance readDistance()
{
	struct SDistance x;
	printf("Enter distance information:\n");
	printf("Enter feet:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x.feet);
	printf("Enter Inches:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x.inches);
	return x;

}
void printDistance(struct SDistance x)
{
	printf("Sum of distances = %d' , %.2f\" ",x.feet,x.inches);
}
