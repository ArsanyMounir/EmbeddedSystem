/*
 * Utilities.h
 *
 *  Created on: Mar 31, 2024
 *      Author: Arsany
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_


#define SET_BIT(reg,bit) 		(reg |= (1<<bit))
#define CLEAR_BIT(reg,bit) 		(reg &= ~(1<<bit))
#define TOGGLE_BIT(reg,bit) 	(reg ^= (1<<bit))
#define READ_BIT(reg,bit) 		((reg>>bit) & 1)

void delay (int time)
{
	volatile int i,j ;
	for (i=0;i<time;i++)
	{
		for(j=0;j<time;j++);
	}
}



#endif /* UTILITIES_H_ */
