/*
 * Queue.h
 *
 *  Created on: Aug 24, 2021
 *      Author: Arshy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct{
	char firstName[50];
	char lastName[50];
	int ID;
	float GPA;
	int courseID[5];

}Sstudent;

typedef struct{
	unsigned int length;
	unsigned int count;
	Sstudent* base;
	Sstudent* head;
	Sstudent* tail;
}Queue;

typedef enum{
	NoError,
	QFULL,
	QEMPTY,
	QNULL,
	QERROR
}QueueStatus;

Sstudent FIFO_Buffer[50];


QueueStatus add_student_file(Queue*MainBuffer);
QueueStatus add_student_manually(Queue*MainBuffer);
QueueStatus find_ID(Queue*MainBuffer);
QueueStatus find_firstName(Queue*MainBuffer);
QueueStatus find_courseID(Queue*MainBuffer);
QueueStatus totalNumber(Queue*MainBuffer);
QueueStatus delete(Queue*MainBuffer);
QueueStatus update(Queue*MainBuffer);
QueueStatus viewAll(Queue*MainBuffer);
QueueStatus Queue_Init (Queue*MainBuffer,Sstudent*FIFO_Buffer,int length);
QueueStatus isFULL(Queue*MainBuffer);
int checkID(Queue*MainBuffer,int check);


#endif /* QUEUE_H_ */
