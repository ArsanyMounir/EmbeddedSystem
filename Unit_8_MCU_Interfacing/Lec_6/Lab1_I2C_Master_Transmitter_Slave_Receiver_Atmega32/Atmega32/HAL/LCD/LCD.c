/*
 * LCD.c
 *
 *  Created on: Apr 16, 2024
 *      Author: Arsany
 */


#include"LCD.h"



//========================================================
//				Private Functions
//========================================================



/**================================================================
 * @Fn			-wait_ms
 * @brief		-Custom delay function
 * @param [in] 	-time : Variable for amount of loops needed
 * @retval 		-None
 * Note 		-None
 */
void wait_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<time;j++);
}
/**================================================================
 * @Fn			-LCD_kick
 * @brief		-Kick the EN pin i.e: give it a low to high pulse
 * @param [in] 	-None
 * @retval 		-None
 * Note 		-None
 */

void LCD_kick(void)
{
	MCAL_GPIO_WritePin(LCD_CTRL,EN_SWITCH,GPIO_PIN_RESET);
	wait_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL,EN_SWITCH,GPIO_PIN_SET);
}
/**================================================================
 * @Fn			-LCD_GPIO_Init
 * @brief		-initialize the GPIO Specific pins that are connected to the LCD
 * @param [in] 	-None
 * @retval 		-None
 * Note 		-None
 */
void LCD_GPIO_Init(void)
{
	GPIO_PinConfig_t PinConfig;

	//Set RS_SWITCH As Push-Pull Output
	PinConfig.GPIO_PinNumber = RS_SWITCH;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	//Set EN_SWITCH As Push-Pull Output
	PinConfig.GPIO_PinNumber = EN_SWITCH;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

#ifdef EIGHT_BIT_MODE
	//Set the LCD 8 PINS as Output
	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

#endif
#ifdef FOUR_BIT_MODE
	//Set the LCD 4 PINS as Output
	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

#endif
	//Reset EN Switch Pin
	MCAL_GPIO_WritePin(LCD_CTRL,EN_SWITCH,GPIO_PIN_RESET);
	//Reset RS Switch Pin
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_RESET);

	GPIOA->DDR = 0x7E;

}

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			APIs Supported by "HAL LCD DRIVER"
//========================================================

/**================================================================
 * @Fn			-HAL_LCD_Init
 * @brief		-initialize LCD
 * @param [in] 	-None
 * @retval 		-None
 * Note 		-None
 */

void HAL_LCD_Init(void)
{
	wait_ms(20);
	LCD_GPIO_Init();
	wait_ms(15);
	HAL_LCD_CLEAR();
#ifdef EIGHT_BIT_MODE
	 HAL_LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE
	 HAL_LCD_WRITE_COMMAND(0x02);
	 HAL_LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
#endif
	HAL_LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	HAL_LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);

}


/**================================================================
 * @Fn			-HAL_LCD_WRITE_COMMAND
 * @brief		-Writes command to the LCD, helps in initialization and changing internal LCD Settings
 * @param [in] 	-command : holds the required command , must select from commands found in @ref LCD Commands
 * @retval 		-None
 * Note 		-None
 */

void HAL_LCD_WRITE_COMMAND(uint8_t command)
{
#ifdef EIGHT_BIT_MODE
	//HAL_LCD_isbusy();
	MCAL_GPIO_WritePort(LCD_CTRL,command);
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_RESET);
	LCD_kick();
#endif

#ifdef FOUR_BIT_MODE
	MCAL_GPIO_WritePort(LCD_CTRL,((LCD_CTRL->PORT & 0x87) | ((command & 0xF0)>>1)));
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_RESET);
	wait_ms(50);
	LCD_kick();
	MCAL_GPIO_WritePort(LCD_CTRL,((LCD_CTRL->PORT & 0x87) | ((command & 0x0F)<<3)));
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_RESET);
	wait_ms(50);
	LCD_kick();
#endif

}


/**================================================================
 * @Fn			-HAL_LCD_WRITE_CHAR
 * @brief		-Sends a Character to be displayed on the LCD
 * @param [in] 	-data : takes a single character to be displayed
 * @retval 		-None
 * Note 		-None
 */

void HAL_LCD_WRITE_CHAR(int8_t data)
{
#ifdef EIGHT_BIT_MODE
	//HAL_LCD_isbusy();
	MCAL_GPIO_WritePort(LCD_CTRL,data);
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_SET);
	LCD_kick();
#endif


#ifdef FOUR_BIT_MODE
	MCAL_GPIO_WritePort(LCD_CTRL,((LCD_CTRL->PORT & 0x87) | ((data & 0xF0)>>1)));
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_SET);
	wait_ms(50);
	LCD_kick();
	MCAL_GPIO_WritePort(LCD_CTRL,((LCD_CTRL->PORT & 0x87) | ((data & 0x0F)<<3)));
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_SET);
	wait_ms(50);
	LCD_kick();
#endif

}



/**================================================================
 * @Fn			-HAL_LCD_WRITE_STR
 * @brief		-Sends a String to be displayed on the LCD
 * @param [in] 	-data :takes a String of character to be displayed
 * @retval 		-None
 * Note 		-None
 */
void HAL_LCD_WRITE_STR(char* data)
{
	int i = 0;
	while (*data != '\0')
	{
		HAL_LCD_WRITE_CHAR(*data++);
		i++;
		if(i==16)
		{
			HAL_LCD_GOTO_XY(2,0);
		}
		else if(i==32)
		{
			HAL_LCD_CLEAR();
			HAL_LCD_GOTO_XY(1,0);
			i=0;

		}
	}
}


/**================================================================
 * @Fn			-HAL_LCD_isbusy
 * @brief		-Checks if the LCD is busy
 * @param [in] 	-None
 * @retval 		-None
 * Note 		-None
 */

void HAL_LCD_isbusy(void)
{
	GPIO_PinConfig_t PinConfig;

#ifdef EIGHT_BIT_MODE
	//Set the LCD 8 PINS as Input
	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

#endif
#ifdef FOUR_BIT_MODE
	//Set the LCD 4 PINS as Input
	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	MCAL_GPIO_Init(LCD_CTRL,&PinConfig);

#endif

	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_RESET);
	LCD_kick();


}


/**================================================================
 * @Fn			-HAL_LCD_CLEAR
 * @brief		-Clears Screen of the LCD
 * @param [in] 	-None
 * @retval 		-None
 * Note 		-None
 */
void HAL_LCD_CLEAR(void)
{
	HAL_LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}


/**================================================================
 * @Fn			-HAL_LCD_GOTO_XY
 * @brief		-Moves the cursor to desired postion
 * @param [in] 	-line : which line of the LCD to move to , choose from @ref LCD LINES
 * @param [in] 	-Position : which Character position of the line chosen to move to , choose a value from 0->16
 * @retval 		-None
 * Note 		-None
 */
void HAL_LCD_GOTO_XY(uint8_t line , uint8_t position)
{
	if(line == FIRST_LINE)
	{
		if(position <16 && position >=0)
		{
			HAL_LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	else if (line == SECOND_LINE)
		{
			if(position <16 && position>=0)
			{
				HAL_LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);

			}
		}

}


