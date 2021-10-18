/*
 * LCD.h
 *
 *  Created on: Oct 17, 2021
 *      Author: Arshy
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6.h"
#include "stdint.h"

#define LCD_PORT GPIOA
#define LCD_CTRL GPIOA


#define RS_SWITCH GPIO_PIN_8
#define RW_SWITCH GPIO_PIN_9
#define EN_SWITCH GPIO_PIN_10


//#define DATA_SHIFT 4

//#define EIGHT_BIT
//#define FOUR_BIT

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)




void LCD_INIT(void);
void LCD_WR_COMMAND(unsigned char COMMAND);
void LCD_WR_CHAR(unsigned char DATA);
void LCD_WR_STR(char* data);
void LCD_isbusy();
void LCD_CLEAR();


#endif /* INC_LCD_H_ */
