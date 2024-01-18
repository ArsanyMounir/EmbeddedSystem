/*
 * main.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Arsany
 */
#include "stdio.h"

struct Sstudent
{
	char name[50];
	int roll;
	float marks;
};
struct Sstudent readData();
void printData(struct Sstudent data);
int main()
{
	struct Sstudent dataBase[10];
	int i=0,flag=1;
	while (flag == 1)
	{
		dataBase[i]=readData();
		printData(dataBase[i]);
		printf("Enter 1 to enter another student , 0 to exit");
		fflush(stdin);fflush(stdout);
		scanf("%d",&flag);
	}
	return 0;

}
struct Sstudent readData()
{
	struct Sstudent data;
	printf("Enter information of students:\n");
	printf("Enter name :");
	fflush(stdin);fflush(stdout);
	gets(data.name);
	printf("Enter roll number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&data.roll);
	printf("Enter Marks :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&data.marks);
	return data;
}
void printData(struct Sstudent data)
{
	fflush(stdin);fflush(stdout);
	printf("Displaying input data\n\nname : %s \nRoll: %d \nMarks: %.3f\n",data.name,data.roll,data.marks);
}

