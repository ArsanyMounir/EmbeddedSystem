/*
 * lifo.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Arsany
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdint.h"


//USER Configuration
//select Data type (uint8_t,uint16_t,uint32_t)
#define USER_DATA_TYPE uint32_t

//Select buffer width
#define width 5
USER_DATA_TYPE buffer[width];

//LIFO type definitions
typedef struct {
	unsigned int length;
	unsigned int count;
	USER_DATA_TYPE* base;
	USER_DATA_TYPE* head;

}LIFO_Buffer;

typedef enum{
	LIFO_No_Error,
	LIFO_Full,
	LIFO_Empty,
	LIFO_NULL
}LIFO_Status;

//APIs
LIFO_Status LIFO_Add_item (LIFO_Buffer* LIFO_Buf, USER_DATA_TYPE item);
LIFO_Status LIFO_get_item (LIFO_Buffer* LIFO_Buf, USER_DATA_TYPE* item);
LIFO_Status LIFO_Init (LIFO_Buffer* LIFO_Buf, USER_DATA_TYPE* buffer,unsigned int length);




#endif /* LIFO_H_ */
