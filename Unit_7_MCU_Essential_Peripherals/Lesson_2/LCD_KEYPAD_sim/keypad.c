/*
 * keypad.c
 *
 *  Created on: Apr 3, 2024
 *      Author: Arsany
 */
#include"keypad.h"

int KEYPAD_Rows[] = {R0,R1,R2,R3};
int KEYPAD_Cols[] = {C0,C1,C2,C3};



void KEYPAD_Init(void)
{
	SET_BIT(DDR_KEYPAD_PORT,C0);
	SET_BIT(DDR_KEYPAD_PORT,C1);
	SET_BIT(DDR_KEYPAD_PORT,C2);
	SET_BIT(DDR_KEYPAD_PORT,C3);
	CLEAR_BIT(DDR_KEYPAD_PORT,R0);
	CLEAR_BIT(DDR_KEYPAD_PORT,R1);
	CLEAR_BIT(DDR_KEYPAD_PORT,R2);
	CLEAR_BIT(DDR_KEYPAD_PORT,R3);
	KEYPAD_PORT = 0xFF;
}
char KEYPAD_GetChar()
{
	volatile int i ,j;
	for (i=0;i<4;i++)
	{
		SET_BIT(KEYPAD_PORT,C0);
		SET_BIT(KEYPAD_PORT,C1);
		SET_BIT(KEYPAD_PORT,C2);
		SET_BIT(KEYPAD_PORT,C3);
		CLEAR_BIT(KEYPAD_PORT,KEYPAD_Cols[i]);
		for(j=0;j<4;j++)
		{
			if(!(READ_BIT(KEYPAD_PIN,KEYPAD_Rows[j])))
			{
				while(!(READ_BIT(KEYPAD_PIN,KEYPAD_Rows[j])));
				switch(i)
				{
				case 0:
				{
					if(j==0){return '7';}
					else if (j==1) {return '4';}
					else if (j==2) {return '1';}
					else if (j==3) {return '!';}
					break;
				}
				case 1:
				{
					if(j==0){return '8';}
					else if (j==1) {return '5';}
					else if (j==2) {return '2';}
					else if (j==3) {return '0';}
					break;
				}
				case 2:
				{
					if(j==0){return '9';}
					else if (j==1) {return '6';}
					else if (j==2) {return '3';}
					else if (j==3) {return '=';}
					break;
				}
				case 3:
				{
					if(j==0){return '/';}
					else if (j==1) {return '*';}
					else if (j==2) {return '-';}
					else if (j==3) {return '+';}
					break;
				}
				}
			}
		}
	}
	return 'N';
}
