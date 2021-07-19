/*
 * Ex2_Add_Two_distances.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Arsany
 */
#include "stdio.h"

struct SDistance
{
	int feet;
	float inch;
};

struct SDistance add(struct SDistance a,struct SDistance b);

int main()
{
	struct SDistance a,b,sum;
	printf("Enter information for 1st distance\n");
	printf("Enter feet: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a.feet);
	printf("Enter inch: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a.inch);
	printf("Enter information for 2nd distance\n");
	printf("Enter feet: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&b.feet);
	printf("Enter inch: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b.inch);
	sum=add(a,b);
	printf("\n\nSum of distances = %d\',%.2f\"",sum.feet,sum.inch);
	return 0;
}

struct SDistance add(struct SDistance a,struct SDistance b)
{
	struct SDistance sum;
	sum.feet=a.feet+b.feet;
	sum.inch=a.inch+b.inch;
	while(sum.inch>12.0)
	{
		sum.feet++;
		sum.inch-=12.0;
	}
	return sum;
}
