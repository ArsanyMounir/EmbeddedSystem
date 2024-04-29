/*
 * Queue.c
 *
 *  Created on: Apr 29, 2024
 *      Author: Arsany
 */

#include"Queue.h"
#define PRINT(...)	printf(__VA_ARGS__);fflush(stdout);fflush(stdin);

QueueState_t isNULL(Queue_t* Buffer)
{
	if(!Buffer->base || !Buffer->tail || !Buffer->head)
	{
		return QUEUE_NULL;
	}
	return NO_ERROR;
}

QueueState_t isFULL(Queue_t* Buffer)
{
	if(isNULL(Buffer) == QUEUE_NULL)
	{
		return QUEUE_NULL;
	}
	if(Buffer->count == Buffer-> length)
	{
		return QUEUE_FULL;
	}
	return NO_ERROR;
}

int checkID(Queue_t* Buffer, int ID)
{
	int i ;
	student_t* ptrStudent = Buffer->base;
	for (i=0;i<Buffer->count;i++)
	{
		if(ptrStudent->ID == ID)
		{
			return 1;
		}
		ptrStudent++;
	}
	return 0;
}


QueueState_t addStudent_MANUALY(Queue_t* Buffer)
{
	int temp_data;
	int i ;
	if(isNULL(Buffer)== QUEUE_NULL)
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}

	if(isFULL(Buffer) == QUEUE_FULL)
	{
		PRINT("[ERROR] : Queue FULL \n");
		PRINT("[INFO] : MAX Size is %d \n",SIZE);
		return QUEUE_FULL;
	}

	PRINT("============================================\n");
	PRINT("Enter ID:");
	scanf("%d",&temp_data);
	if(checkID(Buffer,temp_data))
	{
		PRINT("[ERROR] : ID Already Entered Before \n");
		return QUEUE_ERROR;
	}
	Buffer->head->ID = temp_data;
	PRINT("Enter Student's First Name:");
	gets(Buffer->head->FirstName);
	PRINT("Enter Student's Last Name:");
	gets(Buffer->head->LastName);
	PRINT("Enter Student's GPA:");
	scanf("%f",&Buffer->head->GPA);

	for(i=0;i<5;i++)
	{
		PRINT("Enter Course %d ID :",i+1)
																						scanf("%d",&Buffer->head->courseID[i]);
	}

	if(Buffer->head == (Buffer->base + (Buffer->length * sizeof(student_t))))
	{
		Buffer->head = Buffer->base;
	}
	else
	{
		Buffer->head++;
	}
	Buffer->count++;

	PRINT("[INFO] : Data Added Successfully\n");

	return NO_ERROR;
}


QueueState_t addStudent_FILE(Queue_t* Buffer)
{
	FILE* ptrFILE= fopen("DATA.txt","r");
	int temp;

	if(isNULL(Buffer)== QUEUE_NULL)
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}

	if(isFULL(Buffer) == QUEUE_FULL)
	{
		PRINT("[ERROR] : Queue FULL \n");
		PRINT("[INFO] : MAX Size is %d \n",SIZE);
		return QUEUE_FULL;
	}

	while(fscanf(ptrFILE,"%d %s %s %f %d %d %d %d %d [^\n]",&Buffer->head->ID,Buffer->head->FirstName,Buffer->head->LastName,
			&Buffer->head->GPA,&Buffer->head->courseID[0],&Buffer->head->courseID[1],&Buffer->head->courseID[2],
			&Buffer->head->courseID[3],&Buffer->head->courseID[4])!=EOF )
	{

		temp=Buffer->head->ID;
		if(checkID(Buffer,temp))
		{
			PRINT("[ERROR] ID %d already taken \n",temp);
			return QUEUE_ERROR;
		}

		if(Buffer->head==(Buffer->base+(Buffer->length * sizeof(student_t))))
		{
			Buffer->head=Buffer->base;
		}
		else
		{
			Buffer->head++;
		}
		Buffer->count++;
	}
	fclose(ptrFILE);

	PRINT("[INFO] : Data Added Successfully\n");

	return NO_ERROR;

}


QueueState_t findStudent_ID(Queue_t* Buffer)
{
	student_t* ptrStudent = Buffer->base;
	int temp,i,j;
	if(isNULL(Buffer))
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	if(Buffer->count == 0)
	{
		PRINT("[ERROR] : Queue Empty \n");
		return QUEUE_EMPTY;
	}

	PRINT("============================================\n");
	PRINT("Enter ID:");
	scanf("%d",&temp);
	for(i=0;i<Buffer->count;i++)
	{
		if(temp == ptrStudent->ID)
		{
			PRINT("============================================\n");
			PRINT("Student Data for ID %d is \n",temp);
			PRINT("First Name:%s\n",ptrStudent->FirstName);
			PRINT("Last Name:%s\n",ptrStudent->LastName);
			PRINT("GPA:%.2f\n",ptrStudent->GPA);
			PRINT("Courses entered:\n");
			for(j=0;j<5;j++)
			{
				PRINT("course %d ID is:%d\n",j+1,ptrStudent->courseID[j]);
			}
			return NO_ERROR;
		}
		ptrStudent++;
	}
	PRINT("============================================\n");
	PRINT("[ERROR] ID %d not Found \n",temp);
	return QUEUE_ERROR;


}

QueueState_t findStudent_FIRSTNAME(Queue_t* Buffer)
{
	student_t* ptrStudent=Buffer->base;
	int i,j;

	int ERROR_FLAG=0;

	char temp[50];
	if(isNULL(Buffer))
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	if(Buffer->count == 0)
	{
		PRINT("[ERROR] : Queue Empty \n");
		return QUEUE_EMPTY;
	}

	PRINT("===============================================\n");
	PRINT("Enter first name:");
	gets(temp);
	for(i=0;i<Buffer->count;i++)
	{
		if(stricmp(temp,ptrStudent->FirstName)==0)
		{
			PRINT("===============================================\n");
			PRINT("Student Data for first name %s is \n",temp);
			PRINT("ID:%d\n",ptrStudent->ID);
			PRINT("Last Name:%s\n",ptrStudent->LastName);
			PRINT("GPA:%.2f\n",ptrStudent->GPA);
			PRINT("Courses entered:\n");
			for(j=0;j<5;j++)
			{
				PRINT(" course %d ID is:%d\n",j+1,ptrStudent->courseID[j]);
			}
			ERROR_FLAG=1;
		}
		ptrStudent++;
	}
	if(ERROR_FLAG)
		return NO_ERROR;
	else
	{
		PRINT("===============================================\n");
		PRINT("[ERROR] first name %s Not found\n",temp);
		return QUEUE_ERROR;
	}

}
QueueState_t findStudent_COURSE_ID(Queue_t* Buffer)
{
	student_t* ptrStudent=Buffer->base;
	int i,j,temp;
	int ERROR_FLAG=0;
	if(isNULL(Buffer))
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	if(Buffer->count == 0)
	{
		PRINT("[ERROR] : Queue Empty \n");
		return QUEUE_EMPTY;
	}

	PRINT("===============================================\n");
	PRINT("Enter Course ID:");
	scanf("%d",&temp);
	for(i=0;i<Buffer->count;i++)
	{
		for(j=0;j<5;j++)
		{
			if(ptrStudent->courseID[j]==temp)
			{
				PRINT("===============================================\n");
				PRINT("Student Data for course ID %d is \n",temp);
				PRINT("ID:%d\n",ptrStudent->ID);
				PRINT("First Name:%s\n",ptrStudent->FirstName);
				PRINT("Last Name:%s\n",ptrStudent->LastName);
				PRINT("GPA:%.2f\n",ptrStudent->GPA);
				ERROR_FLAG=1;
			}

		}
		ptrStudent++;
	}

	if(ERROR_FLAG)
		return NO_ERROR;
	else
	{
		PRINT("===============================================\n");
		PRINT("[ERROR] course ID %d Not found\n",temp);
		return QUEUE_ERROR;
	}


}
QueueState_t countStudent(Queue_t* Buffer)
{
	if(isNULL(Buffer))
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	if(Buffer->count == 0)
	{
		PRINT("[ERROR] : Queue Empty \n");
		return QUEUE_EMPTY;
	}
	PRINT("===============================================\n");
	PRINT("[INFO] the total number of students is : %d\n", Buffer->count);
	PRINT("[INFO] you can add up to %d students \n", Buffer->length);
	PRINT("[INFO] you can add %d more students \n", Buffer->length - Buffer->count);
	PRINT("===============================================\n");
	return NO_ERROR;

}
QueueState_t deleteStudent(Queue_t* Buffer)
{
	student_t* ptrStudent=Buffer->base;
	int i,j,temp;
	int position =0;
	if(isNULL(Buffer))
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	if(Buffer->count == 0)
	{
		PRINT("[ERROR] : Queue Empty \n");
		return QUEUE_EMPTY;
	}

	PRINT("===============================================\n");
	PRINT("Enter ID:");
	scanf("%d",&temp);
	for(i=0;i<Buffer->count;i++)
	{
		if(ptrStudent->ID==temp)
		{
			for(j=position;j<Buffer->count;j++)
			{
				FIFO_Buffer[j]=FIFO_Buffer[j+1];
			}
			if(Buffer->tail==(Buffer->base+(Buffer->length * sizeof(student_t))))
				Buffer->tail=Buffer->base;
			else
			{
				Buffer->tail--;
			}
			Buffer->count--;
			PRINT("[INFO] ID %d was deleted Successfully\n",temp);
			return NO_ERROR;
		}
		ptrStudent++;
		position++;
	}
	PRINT("===============================================\n");
	PRINT("[ERROR] ID %d Not found\n",temp);
	return QUEUE_ERROR;


}
QueueState_t updateStudent(Queue_t* Buffer)
{
	student_t* ptrStudent=Buffer->base;
	int i,j,k,temp;
	int ERROR_FLAG=0;
	if(isNULL(Buffer))
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	if(Buffer->count == 0)
	{
		PRINT("[ERROR] : Queue Empty \n");
		return QUEUE_EMPTY;
	}

	PRINT("===============================================\n");
	PRINT("Enter ID:");
	scanf("%d",&temp);
	for(i=0;i<Buffer->count;i++)
	{
		if(ptrStudent->ID==temp)
		{
			PRINT("Choose the data that you want to update\n");
			PRINT("1.ID \n");
			PRINT("2.first name \n");
			PRINT("3.last name \n");
			PRINT("4.GPA \n");
			PRINT("5.courses enrolled\n ");
			PRINT("Enter the choice");
			scanf("%d",&j);
			switch(j)
			{
			case 1:
			{
				PRINT("Enter new ID:");
				scanf("%d",&ptrStudent->ID);
				ERROR_FLAG=1;
				break;
			}
			case 2:
			{
				PRINT("Enter new first name:");
				scanf("%s",&ptrStudent->FirstName);
				ERROR_FLAG=1;
				break;
			}
			case 3:
			{
				PRINT("Enter new last name:");
				scanf("%s",&ptrStudent->LastName);
				ERROR_FLAG=1;
				break;
			}
			case 4:
			{
				PRINT("Enter new GPA :");
				scanf("%f",&ptrStudent->GPA);
				ERROR_FLAG=1;
				break;
			}
			case 5:
			{
				for(k=0;k<5;k++)
				{
					PRINT("Enter course %d ID:",i+1);
					scanf("%d",&ptrStudent->courseID[i]);
				}
				ERROR_FLAG=1;
				break;
			}
			default:PRINT("[ERROR} Wrong Input\n");
			break;
			}
		}
		ptrStudent++;
	}
	if(!ERROR_FLAG)
	{
		PRINT("===============================================\n");
		PRINT("[ERROR] ID %d Not found\n",temp);
		return QUEUE_ERROR;
	}
	else
	{
		return NO_ERROR;
	}
}
QueueState_t viewALL(Queue_t* Buffer)
{
	student_t* ptrStudent=Buffer->base;
	int i,j;
	if(isNULL(Buffer))
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	if(Buffer->count == 0)
	{
		PRINT("[ERROR] : Queue Empty \n");
		return QUEUE_EMPTY;
	}

	for(i=0;i<Buffer->count;i++)
	{
		PRINT("===============================================\n");
		PRINT("Student Data for ID %d is \n",ptrStudent->ID);
		PRINT("First Name:%s\n",ptrStudent->FirstName);
		PRINT("Last Name:%s\n",ptrStudent->LastName);
		PRINT("GPA:%.2f\n",ptrStudent->GPA);
		PRINT("Courses entered:\n");
		for(j=0;j<5;j++)
		{
			PRINT("course %d ID is:%d\n",j+1,ptrStudent->courseID[j]);
		}
		ptrStudent++;
	}
	return NO_ERROR;

}

QueueState_t Queue_INIT(Queue_t* Buffer, student_t* FIFO_Buffer , int length)
{
	if (FIFO_Buffer == NULL)
	{
		PRINT("[ERROR] : Queue NULL \n");
		return QUEUE_NULL;
	}
	Buffer->base = FIFO_Buffer;
	Buffer->head  = FIFO_Buffer;
	Buffer->tail = FIFO_Buffer;
	Buffer->count = 0;
	Buffer->length = length;
	return NO_ERROR;
}



