/*
 * Keypad.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Arshy
 */
#include"keypad.h"


int KEYPAD_R[]={R0,R1,R2,R3};
int KEYPAD_C[]={C0,C1,C2,C3};

void KEYPAD_init()
{
	DDIR_KEYPAD_PORT &= ~((1<<KEYPAD_R[0]) | (1<<KEYPAD_R[1]) | (1<<KEYPAD_R[2]) | (1<<KEYPAD_R[3]));
	DDIR_KEYPAD_PORT |= ((1<<KEYPAD_C[0]) | (1<<KEYPAD_C[1]) | (1<<KEYPAD_C[2]) | (1<<KEYPAD_C[3]));
	KEYPAD_PORT = 0xFF;
}

char KEYPAD_CHAR()
{
	volatile int i, j;
	for (i=0;i<4;i++)
	{
		KEYPAD_PORT |= ((1<<KEYPAD_C[0]) | (1<<KEYPAD_C[1]) | (1<<KEYPAD_C[2]) | (1<<KEYPAD_C[3]));
		KEYPAD_PORT &= ~(1<<KEYPAD_C[i]);
		for(j=0;j<4;j++)
		{
			if(!(KEYPAD_PIN & (1<<KEYPAD_R[j])))
			{
				while(!(KEYPAD_PIN & (1<<KEYPAD_R[j])));
				switch(i)
				{
				case 0:
				{
					if(j==0) return '7';
					else if (j==1) return '4';
					else if (j==2) return '1';
					else if (j==3) return '!';
				}break;
				case 1:
				{
					if(j==0) return '8';
					else if (j==1) return '5';
					else if (j==2) return '2';
					else if (j==3) return '0';
				}break;
				case 2:
				{
					if(j==0) return '9';
					else if (j==1) return '6';
					else if (j==2) return '3';
					else if (j==3) return '=';
				}break;
				case 3:
				{
					if(j==0) return '/';
					else if (j==1) return '*';
					else if (j==2) return '-';
					else if (j==3) return '+';
				}break;
				}
			}
		}

	}
	return 'N';
}
