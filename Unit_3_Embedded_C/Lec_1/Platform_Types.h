/*
 * h.h
 *
 *  Created on: Feb 1, 2024
 *      Author: Arsany
 */

#ifndef TYPES_H_
#define TYPES_H_
#ifndef _Bool
#define _Bool unsigned long


#define	CPU_TYPE_8				8
#define	CPU_TYPE_16				16
#define	CPU_TYPE_32				32


#define	HIGH_BYTE_FIRST			0
#define	LOW_BYTE_FIRST			1

#define	MSB_FIRST				0
#define	LSB_FIRST				1





//Definition for stm32

#define CPU_TYPE				CPU_TYPE_32
#define	CPU_BIT_ORDER			LSB_FIRST
#define	CPU_BYTE_ORDER			LOW_BYTE_FIRST


typedef unsigned char			uint8;
typedef unsigned short			uint16;
typedef unsigned long			uint32;
typedef volatile unsigned char	vuint8;
typedef volatile unsigned short	vuint16;
typedef volatile unsigned long	vuint32;


typedef signed char				sint8;
typedef signed short			sint16;
typedef signed long				sint32;
typedef volatile signed char	vsint8;
typedef volatile signed short	vsint16;
typedef volatile signed long	vsint32;

typedef float					float32;
typedef double					float64;





#ifndef False
#define False		               (boolean)false
#endif
#ifndef True
#define True		               (boolean)true
#endif
typedef _Bool                      boolean;


#endif /* TYPES_H_ */
