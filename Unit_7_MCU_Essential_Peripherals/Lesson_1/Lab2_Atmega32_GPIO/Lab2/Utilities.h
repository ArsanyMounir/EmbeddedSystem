/*
 * Utilities.h
 *
 *  Created on: Sep 26, 2021
 *      Author: Arshy
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#define SetBit(reg,bit) reg|=(1<<bit)
#define ResetBit(reg,bit) reg&=~(1<<bit)
#define ToggleBit(reg,bit) reg^=(1<<bit)
#define ReadBit(reg,bit) (reg>>bit)&1


void Delay(int time)
{
	volatile long int _x,_y;
	for(_x=time;_x>0;_x--)
		for(_y=time;_y>0;_y--);
}


#endif /* UTILITIES_H_ */
