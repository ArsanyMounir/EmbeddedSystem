/*
 * Utilities.h
 *
 *  Created on: Apr 3, 2024
 *      Author: Arsany
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#define SET_BIT(reg,bit) 		(reg |= (1<<bit))
#define CLEAR_BIT(reg,bit) 		(reg &= ~(1<<bit))
#define TOGGLE_BIT(reg,bit) 	(reg ^= (1<<bit))
#define READ_BIT(reg,bit) 		((reg>>bit) & 1)




#endif /* UTILITIES_H_ */
