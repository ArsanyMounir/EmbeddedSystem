/*
 * Ex4_Store_Data_of_Students.c
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
int main()
{
	struct Sstudent students[10];
	int i;
	printf("Enter information of students:\n");
	for(i=0;i<10;i++){
		printf("Enter roll number:");
		fflush(stdin);fflush(stdout);
		scanf("%d",&students[i].roll);
		printf("Enter name:");
		fflush(stdin);fflush(stdout);
		gets(students[i].name);
		printf("Enter marks:");
		fflush(stdin);fflush(stdout);
		scanf("%f",&students[i].mark);
	}
	printf("\nDisplaying Information\n");
	for(i=0;i<10;i++)
	{
		printf("Roll no.: %d\n",students[i].roll);
		printf("Name: %s\n",students[i].name);
		printf("Marks: %0.1f\n",students[i].mark);
	}
	return 0;

}



