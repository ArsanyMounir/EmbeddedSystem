/*
 * Platform_Types.h
 *
 *  Created on: Jul 29, 2021
 *      Author: Arsany
 */
#include <stdbool.h>



#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
#ifndef _Bool
#define _Bool unsigned long



//CPU_TYPE
#define CPU_TYPE_8 			       8
#define CPU_TYPE_16 		       16
#define CPU_TYPE_32 		       32


//Bit_Ordering
#define MSB_FIRST 			       0
#define LSB_FIRST 			       1


//Byte_Ordering
#define HIGH_BYTE_FIRST 	       0
#define LOW_BYTE_FIRST 		       1



//ST30
#define CPU_TYPE		           CPU_TYPE_32
#define CPU_BIT_ORDER              LSB_FIRST
#define CPU_BYTE_ORDER             LOW_BYTE_FIRST


//boolean_Defenation
#ifndef False
#define False		               (boolean)false
#endif
#ifndef True
#define True		               (boolean)true
#endif
typedef _Bool                      boolean;


//Unsigned_Data_Types
typedef unsigned char              uint8;
typedef unsigned short             uint16;
typedef unsigned long              uint32;
typedef volatile unsigned char     vuint8;
typedef volatile unsigned short    vuint16;
typedef volatile unsigned long     vuint32;


//Signed_Data_types
typedef signed char                sint8;
typedef signed short               sint16;
typedef signed long                sint32;
typedef volatile signed char       vsint8;
typedef volatile signed short      vsint16;
typedef volatile signed long       vsint32;


//Least
typedef signed long                sint8_least;
typedef signed long                sint16_least;
typedef signed long                sint32_least;
typedef unsigned long              uint8_least;
typedef unsigned long              uint16_least;
typedef unsigned long              uint32_least;


//Real_Numbers
typedef float                      float32;
typedef double	                   float64;


#endif
