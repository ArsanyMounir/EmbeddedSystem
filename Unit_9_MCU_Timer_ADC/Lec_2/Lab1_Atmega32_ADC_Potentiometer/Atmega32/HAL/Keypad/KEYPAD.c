/*
 * KEYPAD.c
 *
 *  Created on: Apr 16, 2024
 *      Author: Arsany
 */


#include "KEYPAD.h"

int KEYPAD_ROWS[] = {R0,R1,R2,R3};//Rows of keypad

int KEYPAD_COLS[] = {C0,C1,C2,C3};//Columns of keypad



//========================================================
//			APIs Supported by "HAL KEYPAD DRIVER"
//========================================================

void HAL_KEYPAD_Init(void)
{

	GPIO_PinConfig_t PinConfig;

	PinConfig.GPIO_PinNumber = R0;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(KEYPAD_ROWS_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R1;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(KEYPAD_ROWS_PORT, &PinConfig);


	PinConfig.GPIO_PinNumber = R2;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(KEYPAD_ROWS_PORT, &PinConfig);


	PinConfig.GPIO_PinNumber = R3;
	PinConfig.GPIO_DataDirection = GPIO_OUTPUT;
	MCAL_GPIO_Init(KEYPAD_ROWS_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C0;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	PinConfig.GPIO_Resistor_State = GPIO_PULL_UP;
	MCAL_GPIO_Init(KEYPAD_COLS_PORT, &PinConfig);


	PinConfig.GPIO_PinNumber = C1;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	PinConfig.GPIO_Resistor_State = GPIO_PULL_UP;
	MCAL_GPIO_Init(KEYPAD_COLS_PORT, &PinConfig);


	PinConfig.GPIO_PinNumber = C2;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	PinConfig.GPIO_Resistor_State = GPIO_PULL_UP;
	MCAL_GPIO_Init(KEYPAD_COLS_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C3;
	PinConfig.GPIO_DataDirection = GPIO_INPUT;
	PinConfig.GPIO_Resistor_State = GPIO_PULL_UP;
	MCAL_GPIO_Init(KEYPAD_COLS_PORT, &PinConfig);


	MCAL_GPIO_WritePort(KEYPAD_ROWS_PORT,0xFF);
	MCAL_GPIO_WritePort(KEYPAD_COLS_PORT,0xFF);

}


char HAL_KEYPAD_GetChar(void)
{
	volatile int i ,j;
	for (i=0;i<4;i++)
	{
		MCAL_GPIO_WritePin(KEYPAD_ROWS_PORT, R0, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_ROWS_PORT, R1, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_ROWS_PORT, R2, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_ROWS_PORT, R3, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_ROWS_PORT, KEYPAD_ROWS[i], GPIO_PIN_RESET);
		for(j=0;j<4;j++)
		{
			if(!(MCAL_GPIO_ReadPin(KEYPAD_COLS_PORT, KEYPAD_COLS[j])))
			{
				while(!(MCAL_GPIO_ReadPin(KEYPAD_COLS_PORT, KEYPAD_COLS[j])));
				switch(i)
				{
				case 0:

					if(j==0){return '7';}
					else if (j==1) {return '8';}
					else if (j==2) {return '9';}
					else if (j==3) {return '/';}
					break;

				case 1:

					if(j==0){return '4';}
					else if (j==1) {return '5';}
					else if (j==2) {return '6';}
					else if (j==3) {return '*';}
					break;

				case 2:

					if(j==0){return '1';}
					else if (j==1) {return '2';}
					else if (j==2) {return '3';}
					else if (j==3) {return '-';}
					break;

				case 3:

					if(j==0){return '!';}
					else if (j==1) {return '0';}
					else if (j==2) {return '=';}
					else if (j==3) {return '+';}
					break;

				}
			}
		}
	}
	return 'N';
}




