/*
 * main.c
 *
 *  Created on: Apr 3, 2024
 *      Author: Arsany
 */

#include "LCD.h"
#include "keypad.h"


int main(void)
{
	LCD_Init();
	KEYPAD_Init();
	char input;
	int i=0;
	while(1)
	{
		input = KEYPAD_GetChar();
		if(input == 'N');
		else if(input == '!')
		{
			LCD_CLEAR();
			i=0;

		}
		else
		{
			LCD_WRITE_CHAR(input);
			i++;
		}
		if(i == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if(i==32)
		{
			LCD_CLEAR();
			LCD_GOTO_XY(1,0);
			i =0;
		}

	}


	return 0;
}

