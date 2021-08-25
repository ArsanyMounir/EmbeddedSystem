/*
 * Queue.c
 *
 *  Created on: Aug 24, 2021
 *      Author: Arshy
 */
#include"stdio.h"
#include"Queue.h"
#include"string.h"
#include"stdlib.h"
#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin)

QueueStatus Queue_Init (Queue*MainBuffer,Sstudent*FIFO_Buffer,int length)
{
	if(FIFO_Buffer==NULL)
	{
		DPRINTF("[ERROR] Queue NULL\n");
		return QNULL;
	}
	MainBuffer->base=FIFO_Buffer;
	MainBuffer->head=FIFO_Buffer;
	MainBuffer->tail=FIFO_Buffer;
	MainBuffer->length=length;
	MainBuffer->count=0;
	return NoError;
}


QueueStatus add_student_manually(Queue*MainBuffer)
{
	int temp,i;
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(isFULL(MainBuffer)==QFULL)
	{
		DPRINTF("[ERROR] Database FULL \n");
		DPRINTF("[INFO] Maximum size is 50 element \n");
		return QFULL;
	}

	DPRINTF("===============================================\n");
	DPRINTF("Enter ID:");
	scanf("%d",&temp);
	if(checkID(MainBuffer,temp))
	{
		DPRINTF("[ERROR] ID already taken \n");
		return QERROR;
	}
	MainBuffer->head->ID=temp;
	DPRINTF("Enter the first name of student:");
	gets(MainBuffer->head->firstName);
	DPRINTF("Enter the last name of student:");
	gets(MainBuffer->head->lastName);
	DPRINTF("Enter the GPA of student:");
	scanf("%f",&MainBuffer->head->GPA);
	for(i=0;i<5;i++)
	{
		DPRINTF("Enter course %d ID:",i+1);
		scanf("%d",&MainBuffer->head->courseID[i]);
	}
	//circular queue check
	if(MainBuffer->head==(MainBuffer->base+(MainBuffer->length * sizeof(Sstudent))))
		MainBuffer->head=MainBuffer->base;
	else
		MainBuffer->head++;
	MainBuffer->count++;
	DPRINTF("[INFO] Student Details are added successfully \n");
	totalNumber(MainBuffer);
	//	DPRINTF("===============================================\n");
	//	DPRINTF("[INFO] the total number of students is : %d\n", MainBuffer->count);
	//	DPRINTF("[INFO] you can add up to %d students \n", MainBuffer->length);
	//	DPRINTF("[INFO] you can add more about %d students \n", MainBuffer->length - MainBuffer->count);
	//	DPRINTF("===============================================\n");
	return NoError;
}

QueueStatus find_ID(Queue*MainBuffer)
{
	Sstudent* ptr=MainBuffer->base;
	int temp,i,j;
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(MainBuffer->count == 0)
	{
		DPRINTF("[ERROR] Database EMPTY \n");
		return QEMPTY;
	}

	DPRINTF("===============================================\n");
	DPRINTF("Enter ID:");
	scanf("%d",&temp);
	for(i=0;i<MainBuffer->count;i++)
	{
		if(temp==ptr->ID)
		{
			DPRINTF("===============================================\n");
			DPRINTF("Student Data for ID %d is \n",temp);
			DPRINTF("First Name:%s\n",ptr->firstName);
			DPRINTF("Last Name:%s\n",ptr->lastName);
			DPRINTF("GPA:%.2f\n",ptr->GPA);
			DPRINTF("Courses entered:\n");
			for(j=0;j<5;j++)
			{
				DPRINTF("course %d ID is:%d\n",j+1,ptr->courseID[j]);
			}
			return NoError;
		}
		ptr++;
	}
	DPRINTF("===============================================\n");
	DPRINTF("[ERROR] ID %d Not found\n",temp);
	DPRINTF("===============================================\n");
	return QERROR;
}

QueueStatus find_firstName(Queue*MainBuffer)
{
	Sstudent* ptr=MainBuffer->base;
	int i,j;
	int FLAG=0;
	char temp[50];
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(MainBuffer->count == 0)
	{
		DPRINTF("[ERROR] Database EMPTY \n");
		return QEMPTY;
	}

	DPRINTF("===============================================\n");
	DPRINTF("Enter first name:");
	gets(temp);
	for(i=0;i<MainBuffer->count;i++)
	{
		if(stricmp(temp,ptr->firstName)==0)
		{
			DPRINTF("===============================================\n");
			DPRINTF("Student Data for first name %s is \n",temp);
			DPRINTF("ID:%d\n",ptr->ID);
			DPRINTF("Last Name:%s\n",ptr->lastName);
			DPRINTF("GPA:%.2f\n",ptr->GPA);
			DPRINTF("Courses entered:\n");
			for(j=0;j<5;j++)
			{
				DPRINTF(" course %d ID is:%d\n",j+1,ptr->courseID[j]);
			}
			FLAG=1;
		}
		ptr++;
	}
	if(FLAG)
		return NoError;
	else
	{
		DPRINTF("===============================================\n");
		DPRINTF("[ERROR] first name %s Not found\n",temp);
		DPRINTF("===============================================\n");
		return QERROR;
	}

}
QueueStatus find_courseID(Queue*MainBuffer)
{
	Sstudent* ptr=MainBuffer->base;
	int i,j,temp;
	int FLAG=0;
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(MainBuffer->count == 0)
	{
		DPRINTF("[ERROR] Database EMPTY \n");
		return QEMPTY;
	}

	DPRINTF("===============================================\n");
	DPRINTF("Enter Course ID:");
	scanf("%d",&temp);
	for(i=0;i<MainBuffer->count;i++)
	{
		for(j=0;j<5;j++)
		{
			if(ptr->courseID[j]==temp)
			{
				DPRINTF("===============================================\n");
				DPRINTF("Student Data for course ID %d is \n",temp);
				DPRINTF("ID:%d\n",ptr->ID);
				DPRINTF("First Name:%s\n",ptr->firstName);
				DPRINTF("Last Name:%s\n",ptr->lastName);
				DPRINTF("GPA:%.2f\n",ptr->GPA);
				FLAG=1;
			}

		}
		ptr++;
	}

	if(FLAG)
		return NoError;
	else
	{
		DPRINTF("===============================================\n");
		DPRINTF("[ERROR] course ID %d Not found\n",temp);
		DPRINTF("===============================================\n");
		return QERROR;
	}


}


QueueStatus delete(Queue*MainBuffer)
				{
	Sstudent* ptr=MainBuffer->base;
	int i,j,temp;
	int position =0;
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(MainBuffer->count == 0)
	{
		DPRINTF("[ERROR] Database EMPTY \n");
		return QEMPTY;
	}

	DPRINTF("===============================================\n");
	DPRINTF("Enter ID:");
	scanf("%d",&temp);
	for(i=0;i<MainBuffer->count;i++)
	{
		if(ptr->ID==temp)
		{
			for(j=position;j<MainBuffer->count;j++)
			{
				FIFO_Buffer[j]=FIFO_Buffer[j+1];
			}
			if(MainBuffer->tail==(MainBuffer->base+(MainBuffer->length * sizeof(Sstudent))))
				MainBuffer->tail=MainBuffer->base;
			else
				MainBuffer->tail--;
			MainBuffer->count--;
			DPRINTF("[INFO] ID %d was deleted Successfully\n",temp);
			return NoError;
		}
		ptr++;
		position++;
	}
	DPRINTF("===============================================\n");
	DPRINTF("[ERROR] ID %d Not found\n",temp);
	DPRINTF("===============================================\n");
	return QERROR;
				}



QueueStatus isFULL(Queue*MainBuffer)
{
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
		return QNULL;
	if(MainBuffer->count==MainBuffer->length)
		return QFULL;
	return NoError;

}

int checkID(Queue*MainBuffer,int check)
{
	int i;
	Sstudent* ptr=MainBuffer->base;
	for(i=0;i<MainBuffer->count;i++)
	{
		if(ptr->ID==check)
			return 1;
		ptr++;
	}
	return 0;
}


QueueStatus viewAll(Queue*MainBuffer)
{
	Sstudent* ptr=MainBuffer->base;
	int i,j;
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(MainBuffer->count == 0)
	{
		DPRINTF("[ERROR] Database EMPTY \n");
		return QEMPTY;
	}

	for(i=0;i<MainBuffer->count;i++)
	{
		DPRINTF("===============================================\n");
		DPRINTF("Student Data for ID %d is \n",ptr->ID);
		DPRINTF("First Name:%s\n",ptr->firstName);
		DPRINTF("Last Name:%s\n",ptr->lastName);
		DPRINTF("GPA:%.2f\n",ptr->GPA);
		DPRINTF("Courses entered:\n");
		for(j=0;j<5;j++)
		{
			DPRINTF("course %d ID is:%d\n",j+1,ptr->courseID[j]);
		}
		ptr++;
	}
	return NoError;
}


QueueStatus update(Queue*MainBuffer)
{
	Sstudent* ptr=MainBuffer->base;
	int i,j,k,temp;
	int FLAG=0;
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(MainBuffer->count == 0)
	{
		DPRINTF("[ERROR] Database EMPTY \n");
		return QEMPTY;
	}

	DPRINTF("===============================================\n");
	DPRINTF("Enter ID:");
	scanf("%d",&temp);
	for(i=0;i<MainBuffer->count;i++)
	{
		if(ptr->ID==temp)
		{
			DPRINTF("Choose the data that you want to update\n");
			DPRINTF("1.ID \n");
			DPRINTF("2.first name \n");
			DPRINTF("3.last name \n");
			DPRINTF("4.GPA \n");
			DPRINTF("5.courses enrolled\n ");
			DPRINTF("Enter the choice");
			scanf("%d",&j);
			switch(j)
			{
			case 1:
			{
				DPRINTF("Enter new ID:");
				scanf("%d",&ptr->ID);
				FLAG=1;
				break;
			}
			case 2:
			{
				DPRINTF("Enter new first name:");
				scanf("%s",&ptr->firstName);
				FLAG=1;
				break;
			}
			case 3:
			{
				DPRINTF("Enter new last name:");
				scanf("%s",&ptr->lastName);
				FLAG=1;
				break;
			}
			case 4:
			{
				DPRINTF("Enter new GPA :");
				scanf("%f",&ptr->GPA);
				FLAG=1;
				break;
			}
			case 5:
			{
				for(k=0;k<5;k++)
				{
					DPRINTF("Enter course %d ID:",i+1);
					scanf("%d",&ptr->courseID[i]);
				}
				FLAG=1;
				break;
			}
			default:DPRINTF("[ERROR} Wrong Input\n");break;
			}
		}
		ptr++;
	}
	if(!FLAG)
	{
	DPRINTF("===============================================\n");
	DPRINTF("[ERROR] ID %d Not found\n",temp);
	DPRINTF("===============================================\n");
	return QERROR;
	}
	else
		return NoError;

}
QueueStatus add_student_file(Queue*MainBuffer)
{
	FILE* fptr=fopen("text.txt","r");
	int temp;
	if(fptr==NULL)
	{
		DPRINTF("===============================================\n");
		DPRINTF("[ERROR] file Not found\n");
		DPRINTF("===============================================\n");
	}
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(isFULL(MainBuffer)==QFULL)
	{
		DPRINTF("[ERROR] Database FULL \n");
		DPRINTF("[INFO] Maximum size is 50 element \n");
		return QFULL;
	}
	while(fscanf(fptr,"%d %s %s %f %d %d %d %d %d [^\n]",&MainBuffer->head->ID,MainBuffer->head->firstName,&MainBuffer->head->lastName,
			&MainBuffer->head->GPA,&MainBuffer->head->courseID[0],&MainBuffer->head->courseID[1],&MainBuffer->head->courseID[2],
			&MainBuffer->head->courseID[3],&MainBuffer->head->courseID[4])!=EOF )
	{

		temp=MainBuffer->head->ID;
		if(checkID(MainBuffer,temp))
		{
			DPRINTF("[ERROR] ID %d already taken \n",temp);
			continue;
		}

		if(MainBuffer->head==(MainBuffer->base+(MainBuffer->length * sizeof(Sstudent))))
			MainBuffer->head=MainBuffer->base;
		else
			MainBuffer->head++;
		MainBuffer->count++;
	}
	fclose(fptr);
	DPRINTF("[INFO] Student Details are added successfully \n");
	totalNumber(MainBuffer);
	return NoError;

}

QueueStatus totalNumber(Queue*MainBuffer)
{
	if(!MainBuffer->base||!MainBuffer->head||!MainBuffer->tail)
	{
		DPRINTF("[ERROR] Database Not found\n");
		return QNULL;
	}

	if(MainBuffer->count == 0)
	{
		DPRINTF("[ERROR] Database EMPTY \n");
		return QEMPTY;
	}
	DPRINTF("===============================================\n");
	DPRINTF("[INFO] the total number of students is : %d\n", MainBuffer->count);
	DPRINTF("[INFO] you can add up to %d students \n", MainBuffer->length);
	DPRINTF("[INFO] you can add more about %d students \n", MainBuffer->length - MainBuffer->count);
	DPRINTF("===============================================\n");
	return NoError;
}

