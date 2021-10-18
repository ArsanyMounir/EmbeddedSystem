/*
 * LCD.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Arsany
 */
#include "LCD.h"

GPIO_PinConfig_t PinCfg;


void wait_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}


void LCD_KICK()
{
	MCAL_GPIO_WritePin(LCD_PORT, EN_SWITCH, GPIO_PIN_SET);
	wait_ms(50);
	MCAL_GPIO_WritePin(LCD_PORT, EN_SWITCH, GPIO_PIN_RESET);
}
void LCD_CLEAR()
{
	LCD_WR_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_isbusy()
{

	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FO;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_RESET);

	LCD_KICK();



	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);


}

void LCD_INIT(void)
{
	wait_ms(20);

	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = EN_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M ;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

	wait_ms(15);
	LCD_isbusy();
	LCD_CLEAR();
	LCD_WR_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WR_COMMAND(LCD_ENTRY_MODE);
	LCD_WR_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WR_COMMAND(LCD_DISP_ON_CURSOR_BLINK);

}
void LCD_WR_COMMAND(unsigned char COMMAND)
{
	LCD_isbusy();
	MCAL_GPIO_WritePort(LCD_PORT, COMMAND);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_RESET);
	wait_ms(1);
	LCD_KICK();


}
void LCD_WR_CHAR(unsigned char DATA)
{
	LCD_isbusy();
	MCAL_GPIO_WritePort(LCD_PORT, DATA);
	MCAL_GPIO_WritePin(LCD_PORT, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_SWITCH, GPIO_PIN_SET);
	wait_ms(1);
	LCD_KICK();

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
		LCD_WR_CHAR(*data++);
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

