/*
 * main.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Arsany
 */

#include"stdio.h"


struct SEmployee{
	char name[20];
	int ID;
};


int main ()
{
	struct SEmployee emp0={"Ahmed",1001};
	struct SEmployee emp1={"Alex",1002};
	struct SEmployee emp2={"Arsany",1003};
	struct SEmployee *ptr_Struct[10];
	ptr_Struct[0]=&emp0;
	ptr_Struct[1]=&emp1;
	ptr_Struct[2]=&emp2;
	struct SEmployee *(*Ptr)[10]=ptr_Struct;
	printf("Employer name :%s\n",(*(*Ptr)[1]).name);
	printf("Employer ID :%d",(*(*Ptr)[1]).ID);
	return 0;
}
