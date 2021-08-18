/*
 * US.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Arshy
 */

#ifndef US_H_
#define US_H_

enum{
	US_busy
}US_State_ID;

STATE_define(US_busy);

void US_init();

extern void (*US_state)();


#endif /* US_H_ */
