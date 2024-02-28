/*
 * main.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Arsany
 */
#include "stdio.h"
#include "stdlib.h"
#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin)

typedef struct {
	int ID;
	char name[40];
	float height;
}Sdata ;

typedef struct {
	Sdata student;
	struct SStudent *pNextStudent;
}SStudent;

SStudent * gpFirstStudent = NULL ;

//APIs
void AddStudent();
int DeleteStudent();
void printList();
void DeleteAll();
void GetNthNode();
void lengthIterative();
int lengthRecursive(SStudent* pCurrentStudent);
void GetNthNodeEndIterative();
void GetNthNodeEndptr();
void mid();
int loop();
void reverse();




int main()
{
	char temp[40];
	while(1)
	{
		DPRINTF("\n============================\n");
		DPRINTF("\n\tChoose one of the following options ");
		DPRINTF("\n1: Add student ");
		DPRINTF("\n2: Delete student ");
		DPRINTF("\n3: Delete all ");
		DPRINTF("\n4: View students ");
		DPRINTF("\n5: Reverse list ");
		DPRINTF("\n6: Find Middle ");
		DPRINTF("\n7: nth node ");
		DPRINTF("\n8: List length (iterative Function)");
		DPRINTF("\n9: List length (recursive Function)");
		DPRINTF("\n10: Nth node from the end (Using list length)");
		DPRINTF("\n11: Nth node from the end (Using Sliding window Pointer)");
		DPRINTF("\n12: Detect Loop");
		DPRINTF("\nEnter 0 to exit ");
		DPRINTF("\nEnter your option: ");
		gets(temp);
		DPRINTF("\n============================\n");
		switch(atoi(temp))
		{
		case 0: return 0; break;
		case 1: AddStudent();break;
		case 2: DeleteStudent();break;
		case 3: DeleteAll();break;
		case 4: printList();break;
		case 5: reverse();break;
		case 6: mid();break;
		case 7: GetNthNode();break;
		case 8: lengthIterative();break;
		case 9: DPRINTF("length = %d",lengthRecursive(gpFirstStudent));break;
		case 10:GetNthNodeEndIterative();break;
		case 11:GetNthNodeEndptr();break;
		case 12:if(!loop())DPRINTF("\nNO LOOP");break;
		default:
			DPRINTF("\n invalid entry");break;
		}
	}
	return 0;


}



void AddStudent()
{
	SStudent* pNewStudent;
	SStudent* pLastStudent;
	char temp_text[40];
	//Check if Linked List is empty
	if(gpFirstStudent == NULL)
	{
		pNewStudent = (SStudent *) malloc(sizeof(SStudent));

		if(!pNewStudent)
		{
			DPRINTF("Error in allocating memory for data");
		}
		else
		{
			gpFirstStudent = pNewStudent;
		}
	}
	else
	{
		pLastStudent = gpFirstStudent;
		while(pLastStudent->pNextStudent)
		{
			pLastStudent=(SStudent*) pLastStudent->pNextStudent;
		}

		pNewStudent = (SStudent *) malloc(sizeof(SStudent));

		if(!pNewStudent)
		{
			DPRINTF("Error in allocating memory for data");
		}
		else
		{
			pLastStudent->pNextStudent =  pNewStudent;

		}

	}
	DPRINTF(" Enter the ID: \n");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);
	DPRINTF(" Enter student full name:");
	gets(pNewStudent->student.name);
	DPRINTF(" Enter student height :");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);



	pNewStudent->pNextStudent = NULL;


}

int DeleteStudent()
{
	char temp_text[40];
	unsigned int sID;
	DPRINTF("Enter the ID to be deleted");
	gets(temp_text);
	sID = atoi(temp_text);
	if(gpFirstStudent)
	{
		SStudent* pPrevStudent = NULL;
		SStudent* pSelectedStudent = gpFirstStudent;
		while(pSelectedStudent)
		{
			if(pSelectedStudent->student.ID == sID)
			{
				if(pPrevStudent)
				{
					pPrevStudent->pNextStudent=pSelectedStudent->pNextStudent;
				}
				else
				{
					gpFirstStudent= (SStudent*) pSelectedStudent->pNextStudent;
				}
				free(pSelectedStudent);
				return 1;
			}
			else
			{
				pPrevStudent=pSelectedStudent;
				pSelectedStudent= (SStudent*) pSelectedStudent->pNextStudent;

			}

		}

	}
	else
	{
		DPRINTF("Error List is Empty\n");
		return 0;
	}

	DPRINTF("Error ID not found in List\n");
	return 0;
}


void printList()
{
	SStudent* pCurrentStudent = gpFirstStudent;
	unsigned int count = 0;
	if(gpFirstStudent)
	{
		while(pCurrentStudent)
		{
			DPRINTF("Data number %d \n",count+1);
			DPRINTF("ID: %d \n",pCurrentStudent->student.ID);
			DPRINTF("Name: %s \n",pCurrentStudent->student.name);
			DPRINTF("Height: %f \n",pCurrentStudent->student.height);
			pCurrentStudent=(SStudent*) pCurrentStudent->pNextStudent;
			count++;

		}
	}
	else
	{
		DPRINTF("Error List is Empty");
	}


}

void DeleteAll()
{
	SStudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent)
	{
		while(pCurrentStudent)
		{
			SStudent* temp = pCurrentStudent;
			pCurrentStudent =(SStudent*) pCurrentStudent->pNextStudent;
			free(temp);
		}
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}
	gpFirstStudent= NULL;
}



void GetNthNode()
{
	unsigned int count = 0,input;
	char temp[10];
	SStudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent)
	{
		DPRINTF("\n Enter nth index wanted");
		gets(temp);
		input = atoi(temp);
		while(count!=input)
		{
			pCurrentStudent=(SStudent* ) pCurrentStudent->pNextStudent;
			count++;
		}
		if(!pCurrentStudent)
		{
			DPRINTF("index %d Not found \n",input);
		}
		else
		{
			DPRINTF("ID: %d \n",pCurrentStudent->student.ID);
			DPRINTF("Name: %s \n",pCurrentStudent->student.name);
			DPRINTF("Height: %f \n",pCurrentStudent->student.height);
		}
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}

}

void lengthIterative()
{
	unsigned int count=1;
	SStudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent)
	{
		while(pCurrentStudent->pNextStudent)
		{
			pCurrentStudent=(SStudent* ) pCurrentStudent->pNextStudent;
			count++;
		}
		DPRINTF("linked list length = %d ",count);
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}

}



int lengthRecursive(SStudent* pCurrentStudent)
{
	if(!pCurrentStudent->pNextStudent)
	{
		return 1;
	}
	else
	{
		return 1 + lengthRecursive((SStudent*) pCurrentStudent->pNextStudent);
	}
}

void GetNthNodeEndIterative()
{
	unsigned int count=0;
	unsigned int end = lengthRecursive(gpFirstStudent);
	SStudent* pCurrentStudent = gpFirstStudent;
	DPRINTF("Enter Index needed from the end\n");
	scanf("%d",&count);
	count = end - count;
	if(gpFirstStudent)
	{
		while(count)
		{
			pCurrentStudent=(SStudent* ) pCurrentStudent->pNextStudent;
			count--;
		}
		DPRINTF("ID: %d \n",pCurrentStudent->student.ID);
		DPRINTF("Name: %s \n",pCurrentStudent->student.name);
		DPRINTF("Height: %f \n",pCurrentStudent->student.height);
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}
}


void GetNthNodeEndptr()
{
	unsigned int count=1,place;
	SStudent* pFast = gpFirstStudent;
	SStudent* pSlow = gpFirstStudent;
	DPRINTF("Enter Index needed from the end\n");
	scanf("%d",&place);
	if(gpFirstStudent)
	{
		while(pFast->pNextStudent)
		{
			if(count>=place)
			{
				count++;
				pFast = (SStudent* ) pFast->pNextStudent;
				pSlow = (SStudent* ) pSlow->pNextStudent;
			}
			else
			{
				count++;
				pFast = (SStudent* )pFast->pNextStudent;
			}
		}
		DPRINTF("ID: %d \n",pSlow->student.ID);
		DPRINTF("Name: %s \n",pSlow->student.name);
		DPRINTF("Height: %f \n",pSlow->student.height);
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}
}



void mid()
{
	SStudent* pFast = gpFirstStudent;
	SStudent* pSlow = gpFirstStudent;
	if(gpFirstStudent)
	{
		while(pFast->pNextStudent)
		{
			pFast=(SStudent *) pFast->pNextStudent;
			if(!pFast->pNextStudent)
			{
				break;
			}
			else
			{
				pFast=(SStudent *) pFast->pNextStudent;
			}

			pSlow =(SStudent *) pSlow->pNextStudent;
		}
		DPRINTF("ID: %d \n",pSlow->student.ID);
		DPRINTF("Name: %s \n",pSlow->student.name);
		DPRINTF("Height: %f \n",pSlow->student.height);
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}

}


int loop()
{
	SStudent* pFast = gpFirstStudent;
	SStudent* pSlow = gpFirstStudent;
	if(gpFirstStudent)
	{
		while(pFast&&pSlow&&pFast->pNextStudent)
		{
			pSlow =(SStudent *) pSlow->pNextStudent;
			pFast=(SStudent *) pFast->pNextStudent;
			pFast=(SStudent *) pFast->pNextStudent;
			if(pSlow==pFast)
			{
				DPRINTF("There is Loop");
				return 1;

			}

		}
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}


	return 0;
}


void reverse()
{
	SStudent* pCurrentStudent = (SStudent*) gpFirstStudent->pNextStudent;
	SStudent* pPrevStudent = gpFirstStudent;
	SStudent* pNextStudent = NULL;
	if(gpFirstStudent)
	{
		while(pCurrentStudent)
		{
			pNextStudent = (SStudent *) pCurrentStudent->pNextStudent;
			pCurrentStudent->pNextStudent=pPrevStudent;
			pPrevStudent = pCurrentStudent;
			pCurrentStudent = pNextStudent;
		}
		gpFirstStudent->pNextStudent = NULL;
		gpFirstStudent=pPrevStudent;
	}
	else
	{
		DPRINTF("Error List is Empty\n");
	}

	DPRINTF("Reverse Complete\n");


}
