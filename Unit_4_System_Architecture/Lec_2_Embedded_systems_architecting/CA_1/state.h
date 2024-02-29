/*
 * state.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Arsany
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_DEFINE(STATEFUN_) void ST_##STATEFUN_()
#define STATE(STATEFUN_) ST_##STATEFUN_

#endif /* STATE_H_ */
