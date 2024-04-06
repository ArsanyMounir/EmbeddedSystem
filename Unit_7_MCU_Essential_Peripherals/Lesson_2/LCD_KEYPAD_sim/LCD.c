/*
 * LCD.c
 *
 *  Created on: Apr 3, 2024
 *      Author: Arsany
 */

#include "LCD.h"




void LCD_kick(void)
{
	CLEAR_BIT(LCD_CTRL,EN_SWITCH);
	_delay_ms(50);
	SET_BIT(LCD_CTRL,EN_SWITCH);
}


void LCD_isbusy(void)
{
	DDR_LCD_PORT &= ~(0xFF<<DATA_SHIFT);
	SET_BIT(LCD_CTRL,RW_SWITCH);
	CLEAR_BIT(LCD_CTRL,RS_SWITCH);
	LCD_kick();
	DDR_LCD_PORT = 0xFF;
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
}

void LCD_WRITE_COMMAND(unsigned char command)
{
#ifdef EIGHT_BIT_MODE
	LCD_isbusy();
	LCD_PORT = command;
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	CLEAR_BIT(LCD_CTRL,RS_SWITCH);
	LCD_kick();
#endif

#ifdef FOUR_BIT_MODE
	LCD_PORT = ((LCD_PORT & 0x0F) | (command & 0xF0));
	CLEAR_BIT(LCD_CTRL,RS_SWITCH);
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	_delay_ms(10);
	LCD_kick();
	LCD_PORT = ((LCD_PORT & 0x0F) | (command << 4));
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	CLEAR_BIT(LCD_CTRL,RS_SWITCH);
	_delay_ms(10);
	LCD_kick();


#endif
}

void LCD_CLEAR(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}


void LCD_Init(void)
{
	_delay_ms(20);
	LCD_isbusy();
	SET_BIT(DDR_LCD_CTRL,EN_SWITCH);
	SET_BIT(DDR_LCD_CTRL,RW_SWITCH);
	SET_BIT(DDR_LCD_CTRL,RS_SWITCH);
	CLEAR_BIT(LCD_CTRL,EN_SWITCH);
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	CLEAR_BIT(LCD_CTRL,RS_SWITCH);
	DDR_LCD_PORT = 0xFF;
	LCD_CLEAR();
#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE

	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);

#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WRITE_CHAR(unsigned char data)
{
#ifdef EIGHT_BIT_MODE
	LCD_isbusy();
	LCD_PORT = data;
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	SET_BIT(LCD_CTRL,RS_SWITCH);
	LCD_kick();
#endif


#ifdef FOUR_BIT_MODE
	LCD_PORT = ((LCD_PORT & 0x0F) | (data & 0xF0));
	SET_BIT(LCD_CTRL,RS_SWITCH);
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	_delay_ms(10);
	LCD_kick();
	LCD_PORT = ((LCD_PORT & 0x0F) | (data << 4));
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	SET_BIT(LCD_CTRL,RS_SWITCH);
	_delay_ms(10);
	LCD_kick();
#endif

}



void LCD_GOTO_XY(int line , int position)
{
	if (line == 1)
	{
		if(position <16 && position>=0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);

		}
	}
	else if (line == 2)
	{
		if(position <16 && position>=0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);

		}
	}

}

void LCD_WRITE_STR(char* data)
{
	int i = 0;
	while(*data != '\0')
	{
		LCD_WRITE_CHAR(*data++);
		i++;
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
}





