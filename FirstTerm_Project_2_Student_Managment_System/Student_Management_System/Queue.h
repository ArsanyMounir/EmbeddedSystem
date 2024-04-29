/*
 * Queue.h
 *
 *  Created on: Apr 29, 2024
 *      Author: Arsany
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#define PRINT(...)	printf(__VA_ARGS__);fflush(stdout);fflush(stdin);


typedef struct{
	char FirstName[50];
	char LastName[50];
	int ID;
	float GPA;
	int courseID[5];
}student_t;

typedef struct {
	uint32_t length;
	uint32_t count;
	student_t* base;
	student_t* head;
	student_t* tail;
}Queue_t;

typedef enum{
	NO_ERROR,
	QUEUE_FULL,
	QUEUE_EMPTY,
	QUEUE_NULL,
	QUEUE_ERROR
}QueueState_t;


#define SIZE 		50

//Define size of buffer

student_t FIFO_Buffer[SIZE];



QueueState_t addStudent_MANUALY(Queue_t* Buffer);
QueueState_t addStudent_FILE(Queue_t* Buffer);
QueueState_t findStudent_ID(Queue_t* Buffer);
QueueState_t findStudent_FIRSTNAME(Queue_t* Buffer);
QueueState_t findStudent_COURSE_ID(Queue_t* Buffer);
QueueState_t countStudent(Queue_t* Buffer);
QueueState_t deleteStudent(Queue_t* Buffer);
QueueState_t updateStudent(Queue_t* Buffer);
QueueState_t viewALL(Queue_t* Buffer);
QueueState_t Queue_INIT(Queue_t* Buffer, student_t* FIFO_Buffer , int length);











#endif /* QUEUE_H_ */
