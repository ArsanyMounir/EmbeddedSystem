/*
 * Ex5_pointer_to_array_of_pointer_to_structure.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Arsany
 */
#include"stdio.h"

struct Semployee{
	char name[50];
	int id;
};
int main()
{
	struct Semployee emp0={"Alex",1002};
	struct Semployee *Ptr_emp[10];
	struct Semployee *(*PTR)[10]=Ptr_emp;
	Ptr_emp[0]=&emp0;
	printf("ExmployeeName : %s\n",(*(*PTR))->name);
	printf("Employee ID : %d",(*(*PTR))->id);

	return 0;
}
