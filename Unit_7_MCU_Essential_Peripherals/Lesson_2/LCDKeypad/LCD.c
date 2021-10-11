/*
 * LCD.c
 *
 * Created: 10/11/2021 4:31:53 PM
 *  Author: Arshy
 */
#include "LCD.h"
#include "avr/io.h"
#include "util/delay.h"

void LCD_KICK()
{
	LCD_CTRL &= ~(1<<EN_SWITCH);
	_delay_ms(30);
	LCD_CTRL |= (1<<EN_SWITCH);
}
void LCD_CLEAR()
{
	LCD_WR_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_isbusy()
{
	DDIR_LCD_PORT &= ~(0xFF<<DATA_SHIFT);
	LCD_CTRL |= (1<<RW_SWITCH);
	LCD_CTRL &= ~(1<<RS_SWITCH);
	LCD_KICK();
	DDIR_LCD_PORT = 0xFF;
	LCD_CTRL &= ~(1<<RW_SWITCH);
}

void LCD_INIT(void)
{
	_delay_ms(20);
	LCD_isbusy();
	DDIR_LCD_CTRL |= ((1<<EN_SWITCH) | (1<<RW_SWITCH)| (1<<RS_SWITCH));
	LCD_CTRL &= ~((1<<EN_SWITCH) | (1<<RW_SWITCH)| (1<<RS_SWITCH));
	DDIR_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_CLEAR();
	#ifdef EIGHT_BIT
		LCD_WR_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT
		LCD_WR_COMMAND(0x02);
		LCD_WR_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_WR_COMMAND(LCD_ENTRY_MODE);
	LCD_WR_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WR_COMMAND(LCD_DISP_ON_CURSOR_BLINK);

}
void LCD_WR_COMMAND(unsigned char COMMAND)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT
		LCD_PORT = COMMAND ;
		LCD_CTRL &= ~((1<<RW_SWITCH)| (1<<RS_SWITCH));
		_delay_ms(1);
		LCD_KICK();
	#endif
	#ifdef FOUR_BIT
		LCD_PORT = ((LCD_PORT & 0x0F) | (COMMAND & 0xF0));
		LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
		_delay_ms(10);
		LCD_KICK();
		LCD_PORT = ((LCD_PORT & 0x0F) | (COMMAND << 4));
		LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
		_delay_ms(10);
		LCD_KICK();

	#endif

}
void LCD_WR_CHAR(unsigned char DATA)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT
		LCD_PORT = DATA;
		LCD_CTRL &= ~(1<<RW_SWITCH);
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_KICK();
	#endif
	#ifdef FOUR_BIT
		LCD_PORT = ((LCD_PORT & 0x0F) | (DATA & 0xF0));
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_CTRL &= ~(1<<RW_SWITCH);
		_delay_ms(10);
		LCD_KICK();
		LCD_PORT = ( (LCD_PORT & 0x0F) | (DATA << 4) );
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_CTRL &= ~(1<<RW_SWITCH);
		_delay_ms(10);
		LCD_KICK();
	#endif

}
void LCD_LINE(int LINE, int POSITION)
{
	if(LINE==1)
	{
		if(POSITION <16 && POSITION >=0)
			LCD_WR_COMMAND(LCD_BEGIN_AT_FIRST_ROW+POSITION);
	}
	else if (LINE==2)
		if(POSITION <16 && POSITION >=0)
			LCD_WR_COMMAND(LCD_BEGIN_AT_SECOND_ROW+POSITION);
}
void LCD_WR_STR(char* data)
{
	volatile int count = 0;

	while (*data > 0)
	{
		LCD_WR_CHAR(data++);
		count++;
		if(count == 16)
		{
			LCD_LINE(2,0);
		}
		else if (count == 32)
		{
			LCD_CLEAR();
			LCD_LINE(1,0);
			count=0;
		}
	}

}
