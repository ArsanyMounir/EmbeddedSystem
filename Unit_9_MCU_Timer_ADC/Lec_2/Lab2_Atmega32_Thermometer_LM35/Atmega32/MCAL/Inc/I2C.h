/*
 * I2C.h
 *
 *  Created on: May 12, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_I2C_H_
#define MCAL_INC_I2C_H_

#include "ATMEGA32_GPIO_Driver.h"


void MCAL_I2C_Init(unsigned long SCL_CLK);
void MCAL_I2C_Start_Condition(void);
void MCAL_I2C_Write(uint8_t Data);
void MCAL_I2C_Stop_Condition(void);
void MCAL_I2C_Set_Address(uint8_t address);
uint8_t MCAL_I2C_Read(uint8_t ACK);
#endif /* MCAL_INC_I2C_H_ */
