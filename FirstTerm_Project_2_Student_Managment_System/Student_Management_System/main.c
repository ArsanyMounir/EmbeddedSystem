/*
 * main.c
 *
 *  Created on: Apr 29, 2024
 *      Author: Arsany
 */

#include "Queue.h"
#define PRINT(...)	printf(__VA_ARGS__);fflush(stdout);fflush(stdin);



void main()
{
	int temp;
	Queue_t Buffer;
	Queue_INIT(&Buffer,FIFO_Buffer,SIZE);
	PRINT("=================INIT COMPLETE=================\n");
	PRINT("Welcome to Student Management System \n");
	while(1)
	{
		PRINT("===============================================\n");
		PRINT("Choose the task that you want to perform\n");
		PRINT("1. Add the student Details Manually\n");
		PRINT("2. Add the student Details from file\n");
		PRINT("3. Find student details by ID\n");
		PRINT("4. Find student details by First Name\n");
		PRINT("5. Find student details by course ID\n");
		PRINT("6. Find total number of students\n");
		PRINT("7. Delete the student details by ID\n");
		PRINT("8. Update the student details by ID\n");
		PRINT("9. Show all stored data\n");
		PRINT("10. To Exit\n");
		PRINT("Enter your choice number :\n");
		scanf("%d",&temp);
		PRINT("===============================================\n");
		switch(temp)
		{
		case 1: addStudent_MANUALY(&Buffer);break;
		case 2: addStudent_FILE(&Buffer);break;
		case 3: findStudent_ID(&Buffer);break;
		case 4: findStudent_FIRSTNAME(&Buffer);break;
		case 5: findStudent_COURSE_ID(&Buffer);break;
		case 6: countStudent(&Buffer);break;
		case 7: deleteStudent(&Buffer);break;
		case 8: updateStudent(&Buffer);break;
		case 9: viewALL(&Buffer);break;
		case 10:PRINT("\n\t\t\t thank you\n");exit(1) ;break;
		default:
			PRINT("\n invalid entry");break;
		}
	}



}
