/*
 * Ex1_Student_data_entry.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Arsany
 */
#include "stdio.h"

struct Sstudent{
	char name[50];
	int roll;
	float mark;
};
void main()
{
	struct Sstudent s;
	printf("Enter information of students:\n");
	printf("Enter name:");
	fflush(stdin);fflush(stdout);
	gets(s.name);
	printf("Enter roll number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&s.roll);
	printf("Enter marks:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&s.mark);
	printf("\nDisplaying Information\n");
	printf("Name: %s\n",s.name);
	printf("Roll no.: %d\n",s.roll);
	printf("Marks: %.3f",s.mark);

}

