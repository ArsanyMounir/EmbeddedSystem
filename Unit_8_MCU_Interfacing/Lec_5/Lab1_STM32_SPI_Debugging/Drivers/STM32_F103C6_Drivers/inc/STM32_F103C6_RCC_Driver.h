/*
 * STM32_F103C6_RCC_Driver.h
 *
 *  Created on: Apr 23, 2024
 *      Author: Arsany
 */

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

#include "STM32F103X6.h"

#define HSI_CLK							(uint32_t)8000000
#define HSE_CLK							(uint32_t)16000000


uint32_t MCAL_RCC_GET_SYSCLK(void);
uint32_t MCAL_RCC_GET_HCLK(void);
uint32_t MCAL_RCC_GET_PCLK1(void);
uint32_t MCAL_RCC_GET_PCLK2(void);



#endif /* INC_STM32_F103C6_RCC_DRIVER_H_ */
