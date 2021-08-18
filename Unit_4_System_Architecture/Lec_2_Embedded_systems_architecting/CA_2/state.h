/*
 * state.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Arshy
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_statefun_) void ST_##_statefun_()
#define STATE(_statefun_) ST_##_statefun_

void US_Set_distance(int d);
void DC_motor(int s);


#endif /* STATE_H_ */
