/*
 * main.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Arshy
 */
#include"Queue.h"
#include"stdio.h"
#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin)

int main()
{
	int temp;
	Queue MainBuffer;
	Queue_Init (&MainBuffer,FIFO_Buffer,50);
	DPRINTF("===============================================\n");
	DPRINTF("=================INIT COMPLETE=================\n");
	DPRINTF("===============================================\n");
	DPRINTF("Welcome to the student Management System\n");
	while(1)
	{
		DPRINTF("===============================================\n");
		DPRINTF("Choose the task that you want to perform\n");
		DPRINTF("1. Add the student Details Manually\n");
		DPRINTF("2. Add the student Details from file\n");
		DPRINTF("3. Find student details by ID\n");
		DPRINTF("4. Find student details by First Name\n");
		DPRINTF("5. Find student details by course ID\n");
		DPRINTF("6. Find total number of students\n");
		DPRINTF("7. Delete the student details by ID\n");
		DPRINTF("8. Update the student details by ID\n");
		DPRINTF("9. Show all stored data\n");
		DPRINTF("10. To Exit\n");
		DPRINTF("Enter your choice number :\n");
		scanf("%d",&temp);
		DPRINTF("===============================================\n");
		switch(temp)
				{
				case 1: add_student_manually(&MainBuffer);break;
				case 2: add_student_file(&MainBuffer);break;
				case 3: find_ID(&MainBuffer);break;
				case 4: find_firstName(&MainBuffer);break;
				case 5: find_courseID(&MainBuffer);break;
				case 6: totalNumber(&MainBuffer);break;
				case 7: delete(&MainBuffer);break;
				case 8: update(&MainBuffer);break;
				case 9: viewAll(&MainBuffer);break;
				case 10:DPRINTF("\n\t\t\t thank you\n");exit(1) ;break;
				default:
					DPRINTF("\n invalid entry");break;
				}
			}

		return 0;
}
