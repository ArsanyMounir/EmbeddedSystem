/*
 * main.c
 *
 *  Created on: May 09, 2024
 *      Author: Arsany
 */

#include "ATMEGA32.h"
#include "ATMEGA32_GPIO_Driver.h"
#include "LCD.h"
#include "avr/delay.h"
#include "ADC.h"







int main(void)
{
	char buffer[10];
	uint16_t data;
	uint8_t arr[16]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	uint16_t bar;
	uint8_t i;
	HAL_LCD_Init();
	MCAL_ADC_Init(Vref_AVCC,ADC_PRESCALER_64);
	while(1)
	{

		data = MCAL_ADC_ReadVoltPercent(CH_0);
		HAL_LCD_WRITE_STR("Percent:");
		sprintf(buffer,"%d",data);
		HAL_LCD_WRITE_STR(buffer);
		HAL_LCD_WRITE_STR("%");
		HAL_LCD_GOTO_XY(2,0);
		bar = (160/(1000/data));
		for (i=0;i<bar;i++)
		{
			HAL_LCD_WRITE_CHAR(0xFF);
		}
			_delay_ms(1000);
			HAL_LCD_CLEAR();


	}

}





