/*
 * LIFO.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Arsany
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdint.h"




//select data type (uint8_t,uint16_t,uint32_t)

#define USER_DATA_TYPE uint32_t

//Select buffer length
#define width 5


USER_DATA_TYPE buffer[width];


//type definition of the LIFO


typedef struct LIFO_Buf{
	unsigned int count;
	unsigned int length;
	USER_DATA_TYPE* head;
	USER_DATA_TYPE* base;
}LIFO_Buf_t;

typedef enum{
	LIFO_NOERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_State;



//APIs

//initialize a LIFO buffer
LIFO_State LIFO_init(LIFO_Buf_t* lifo_buf , USER_DATA_TYPE* buf, unsigned int size);

//PUSH function for LIFO buffer
LIFO_State LIFO_push(LIFO_Buf_t* lifo_buf , USER_DATA_TYPE item);

//POP function of LIFO buffer
LIFO_State LIFO_pop(LIFO_Buf_t* lifo_buf , USER_DATA_TYPE *item);








#endif /* LIFO_H_ */
