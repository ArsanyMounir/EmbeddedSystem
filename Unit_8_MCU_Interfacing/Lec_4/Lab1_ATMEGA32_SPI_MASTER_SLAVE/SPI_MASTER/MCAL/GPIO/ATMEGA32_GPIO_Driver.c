/*
 * ATMEGA32_GPIO_Driver.c
 *
 *  Created on: Apr 11, 2024
 *      Author: Arsany
 */

#include "ATMEGA32_GPIO_Driver.h"



/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief		-Initializes the GPIOx PINy according to the specified parameters of PinConfig
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinConfig : Pointer to GPIO_PinConfig_t which contains the configuration info for specified GPIO
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig )
{
	//Configure Pin to be Output or Input
	if(PinConfig->GPIO_DataDirection == GPIO_OUTPUT)
	{
		GPIOx->DDR |= (1<<PinConfig->GPIO_PinNumber);
	}
	else if(PinConfig->GPIO_DataDirection == GPIO_INPUT)
	{
		GPIOx->DDR &= ~(1<<PinConfig->GPIO_PinNumber);
	}

	//Configure State to be High or Low
	if(PinConfig->GPIO_Resistor_State == GPIO_PULL_UP)
	{
		GPIOx->PORT	|= (1<<PinConfig->GPIO_PinNumber);
	}
	else if(PinConfig->GPIO_DataDirection == GPIO_PULL_DOWN)
	{
		GPIOx->PORT &= ~(1<<PinConfig->GPIO_PinNumber);
	}


}




/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief		-Read specific Pin
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinNumber : Pin number to be read from according to @ref GPIO_PINS_Define
 * @retval 		-The input Pin value (two values based on @ref GPIO_PIN_State)
 * Note 		-None
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx,uint8_t PinNumber)
{
	uint8_t ReadStatus;
	if ((GPIOx->PIN>>PinNumber) &1)
	{
		ReadStatus = GPIO_PIN_SET;
	}
	else
	{
		ReadStatus = GPIO_PIN_RESET;

	}

	return ReadStatus;


}


/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief		-Read entire Port values
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @retval 		-The input PORT value
 * Note 		-None
 */
uint8_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx)
{
	uint8_t ReadStatus;
	ReadStatus = GPIOx->PIN;
	return ReadStatus;
}



/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief		-Write value on specific PIN
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinNumber : Specific Pin number to be Write on according to @ref GPIO_PINS_Define
 * @param [in]	-Value : PIN value
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx ,uint8_t PinNumber , uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		GPIOx->PORT	|= (1<<PinNumber);
	}
	else if (Value == GPIO_PIN_RESET)
	{
		GPIOx->PORT &= ~(1<<PinNumber);
	}
}


/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief		-Write value on Port
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-Value : Port value
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint8_t Value)
{
	GPIOx->PORT	= Value;
}


/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief		-Toggle a specific PIN
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinNumber : Specific Pin number to be Toggled according to @ref GPIO_PINS_Define
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx , uint8_t PinNumber)
{
	GPIOx->PORT ^= 1<<PinNumber;
}




