/*
 * LCD_Keypad.c
 *
 * Created: 10/11/2021 4:30:02 PM
 * Author : Arshy
 */

#include <avr/io.h>
#include "LCD.h"
#include "keypad.h"

int main(void)
{
    LCD_INIT();
    KEYPAD_init();
    volatile char KEY;
    volatile int count=0;
    while (1)
    {
    	KEY=KEYPAD_CHAR();
    	switch(KEY)
    	{
    	case'!':LCD_CLEAR();break;
    	case'N':break;
    	default:
    		if(count<16){
    		LCD_WR_CHAR(KEY);
    		count++;
    		}
    		else
    		{
    			count=0;
    			LCD_CLEAR();
    			LCD_WR_CHAR(KEY);
    		}
    		break;
    	}
    }
}

