/*
 * keypad.c
 *
 *  Created on: Apr 5, 2024
 *      Author: Arsany
 */
#include"keypad.h"

int KEYPAD_Rows[] = {R0,R1,R2,R3}; //Rows of keypad
int KEYPAD_Cols[] = {C0,C1,C2,C3}; //Columns of keypad


//========================================================
//			APIs Supported by "HAL KEYPAD DRIVER"
//========================================================
void HAL_KEYPAD_Init(void)
{

	GPIO_PinConfig_t PinConfig;

	PinConfig.GPIO_PinNumber = R0;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R2;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R3;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C0;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C1;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C2;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C3;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}


char HAL_KEYPAD_GetChar(void)
{
	volatile int i ,j;
	for (i=0;i<4;i++)
	{
		MCAL_GPIO_WritePin(KEYPAD_PORT, R0, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, R1, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, R2, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, R3, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD_Rows[i], GPIO_PIN_SET);
		for(j=0;j<4;j++)
		{
			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD_Cols[j]))
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD_Cols[j]));
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
