/*
 * STM32F103C6_GPIO_Driver.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Arsany
 */
#include "STM32F103C6_GPIO_Driver.h"


uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	//CRL
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

	//CRH
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}





/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief		-Initializes the GPIOx PINy accourding to the specefied parameters of PinConfig
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinConfig : Pointer to GPIO_PinConfig_t which contains
 * 				 the configuration info for specified GPIO
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 */

void MCAL_GPIO_Init (GPIO_TypeDef* GPIOx,GPIO_PinConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) config pins 0 -> 7
	//Port configuration register high (GPIOx_CRH)  config pins 8 -> 15
	volatile uint32_t* configReg = NULL ;
	volatile uint8_t PIN = 0;
	configReg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL : &GPIOx->CRH ;

	// clear CNF[1:0] & MODE[1:0]
	(*configReg) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//if pin is OUTPUT
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD ) | (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP ) | (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD ) | (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		//Set CNF[1:0] & MODE[1:0]
		PIN = (((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0F ;

	}
	//if pin is INPUT
	else //MODE = 00 input mode (reset state)
	{
		if ( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FO) | (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG))
		{
			PIN = (((PinConfig->GPIO_MODE ) << 2) | (0x0)) & 0x0F ;
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)//considered as INPUT Floating
		{
			PIN = (((GPIO_MODE_INPUT_FO) << 2) | (0x0)) & 0x0F ;
		}
		else // PU PD INPUT
		{
			PIN = (((GPIO_MODE_INPUT_PU) << 2) | (0x0)) & 0x0F ;
			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//ODR = 1 INPUT Pull Up :Table 20. Port bit configuration table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}else
			{
				//ODR = 0 INPUT Pull Down :Table 20. Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}

	}

	//Write on CRL or CRH
	(*configReg) |= ( (PIN) << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;

}




/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief		-Reset all GPIOx Registers
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @retval 		-None
 * Note 		-None
 */

void MCAL_GPIO_DeInit (GPIO_TypeDef* GPIOx)
{
	if(GPIOx==GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);	//Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);

	}
	else if (GPIOx==GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);	//Bit 3 IOPARST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx==GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);	//Bit 4 IOPARST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx==GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);	//Bit 5 IOPARST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if (GPIOx==GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);	//Bit 6 IOPARST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);
	}

}



/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief		-Read specific Pin
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be read from according to @ref GPIO_PINS_Define
 * @retval 		-The input Pin value (two values based on @ref GPIO_PIN_State)
 * Note 		-None
 */

uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	uint8_t bitStatus;
	if (((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET )
	{
		bitStatus = GPIO_PIN_SET;
	}
	else
	{
		bitStatus = GPIO_PIN_RESET;
	}
	return bitStatus;
}



/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief		-Read PORT Value
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @retval 		-The input PORT value (two values based on @ref GPIO_PIN_State)
 * Note 		-None
 */

uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef* GPIOx)
{
	uint16_t portValue;
	portValue = (uint16_t)(GPIOx->IDR);
	return portValue;
}


/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief		-Write value on specific PIN
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Write on according to @ref GPIO_PINS_Define
 * @param [in]	-Value : PIN value
 * @retval 		-None
 * Note 		-None
 */

void MCAL_GPIO_WritePin (GPIO_TypeDef* GPIOx,uint16_t PinNumber,uint8_t Value)
{

	if (Value != GPIO_PIN_RESET )
	{
		//Port bit set/reset register (GPIOx_BSRR)
		//BRy: Port x Reset bit y (y= 0 .. 15)
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BSRR =(uint32_t) PinNumber;
	}
	else
	{
		//Port bit reset register (GPIOx_BRR)
		//Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BRR =(uint32_t) PinNumber;
	}

}


/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief		-Write value on PORT
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-Value : PORT value
 * @retval 		-None
 * Note 		-None
 */


void MCAL_GPIO_WritePort (GPIO_TypeDef* GPIOx,uint16_t Value)
{
	GPIOx->ODR =(uint32_t) Value;
}


/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief		-Toggle a specific PIN
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Toggled according to @ref GPIO_PINS_Define
 * @retval 		-None
 * Note 		-None
 */

void MCAL_GPIO_TogglePin (GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}


/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief		-Locking allows the IO configuration to be frozen
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Locked according to @ref GPIO_PINS_Define
 * @retval 		-Ok if lock is successful , Error if not (according to @ref GPIO_LOCK_State
 * Note 		-None
 */

uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{

	//Bit 16 LCKK[16]: Lock key
	//This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//0: Port configuration lock key not active
	//1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//LOCK key writing sequence:
	//Write 1
	//Write 0
	//Write 1
	//Read 0
	//Read 1 (this read is optional but confirms that the lock is active)
	//Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//These bits are read write but can only be written when the LCKK bit is 0.
	//0: Port configuration not locked
	//1: Port configuration locked.

	//Set LCKK[16]
	volatile uint32_t tmp = 1<<16;
	//Set LCKy
	tmp |= PinNumber;

	//Write 1
	GPIOx->LCKR = tmp;
	//Write 0
	GPIOx->LCKR = PinNumber;
	//Write 1
	GPIOx->LCKR = tmp;
	//Read 0
	tmp = GPIOx->LCKR;
	//Read 1 (this read is optional but confirms that the lock is active)
	if ( (uint32_t) (GPIOx->LCKR & 1<<16 ))
		return GPIO_LOCK_OK ;
	else
		return GPIO_LOCK_ERROR ;

}




