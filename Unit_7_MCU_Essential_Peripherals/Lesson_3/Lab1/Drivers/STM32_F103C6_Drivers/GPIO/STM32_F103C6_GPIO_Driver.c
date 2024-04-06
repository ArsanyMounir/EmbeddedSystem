/*
 * STM32_F103C6_GPIO_Driver.c
 *
 *  Created on: Apr 4, 2024
 *      Author: Arsany
 */
#include "STM32_F103C6_GPIO_Driver.h"

/**================================================================
 * @Fn			-Get_CRL_CRH_Position
 * @brief		-Find the Position of bits for CRL & CRH Reg
 * @param [in]	-PinNumber : Pin number to be read from according to @ref GPIO_PINS_Define
 * @retval 		-The bit position
 * Note 		-None
 */

uint8_t Get_CRL_CRH_Position (uint16_t PinNumber)
{
	switch (PinNumber)
	{
	//CRL
	case GPIO_PIN_0:
		return 0; break;
	case GPIO_PIN_1:
			return 4; break;
	case GPIO_PIN_2:
			return 8; break;
	case GPIO_PIN_3:
			return 12; break;
	case GPIO_PIN_4:
			return 16; break;
	case GPIO_PIN_5:
			return 20; break;
	case GPIO_PIN_6:
			return 24; break;
	case GPIO_PIN_7:
			return 28; break;
	//CRH
	case GPIO_PIN_8:
		return 0; break;
	case GPIO_PIN_9:
			return 4; break;
	case GPIO_PIN_10:
			return 8; break;
	case GPIO_PIN_11:
			return 12; break;
	case GPIO_PIN_12:
			return 16; break;
	case GPIO_PIN_13:
			return 20; break;
	case GPIO_PIN_14:
			return 24; break;
	case GPIO_PIN_15:
			return 28; break;
	}
	return 0;
}




/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief		-Initializes the GPIOx PINy according to the specified parameters of PinConfig
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinConfig : Pointer to GPIO_PinConfig_t which contains the configuration info for specified GPIO
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig )
{
	//Port configuration register low (GPIOx_CRL) Configures Pins from 0->7
	//Port configuration register high (GPIOx_CRH) Configures Pins from 8->15
	volatile uint32_t* configReg = NULL;
	volatile uint8_t CNFx_MODEx = 0;
	//to configure CRL or CRH , check the pin number and work accordingly
	configReg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL : &GPIOx->CRH;

	//Clear CNFx[1:0] & MODEx[1:0]
	(*configReg) &= ~(0xF << Get_CRL_CRH_Position(PinConfig->GPIO_PinNumber));

	//if the Pin is set as Output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD)|(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP)|(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)|(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		// Set CNFx[1:0] & MODE[1:0]
		CNFx_MODEx = (((PinConfig->GPIO_MODE - 4)<<2)| (PinConfig->GPIO_Output_Speed)) & 0x0F;
		//Note : GPIO_MODE - 4 because its values according to @ref GPIO_MODE_Define is as follows
		//4: General purpose output push-pull
		//5: General purpose output Open-drain
		//6: Alternate function output Push-pull
		//7: Alternate function output Open-drain
		//---------which corresponds to TRM values as follows:
		//00(0): General purpose output push-pull
		//01(1): General purpose output Open-drain
		//10(2): Alternate function output Push-pull
		//11(3): Alternate function output Open-drain

		//So when we subtract the 4 from the values we get the required values for the CNF configuration
	}

	//if the Pin is set as Input , in that case MODE == 00 by default
	else
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG))
		{
			// Set CNFx[1:0] & MODEx[1:0] = 0x00
			CNFx_MODEx = ((( (PinConfig->GPIO_MODE)<<2) | 0x0   ) & 0x0F);
		}
		//Alternative function input is the same as input floating Based on the TRM definition
		else if ((PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT))
		{
			// Set CNFx[1:0] & MODEx[1:0] = 0x00
			CNFx_MODEx = ((( (GPIO_MODE_INPUT_FLO)<<2) | 0x0   ) & 0x0F);
		}
		else 		//This means it's either Pull-Up Input or Pull-Down Input
		{
			// Set CNFx[1:0] & MODEx[1:0] = 0x00
			// 10: Input with pull-up / pull-down
			CNFx_MODEx = ((( (GPIO_MODE_INPUT_PU)<<2) | 0x0   ) & 0x0F);
			if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU))
			{
				//Table 20. Port Bit configuration table
				//If Pull-Up input -> PxODR == 1
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber);
				//Shifting already made in Macros Definition of pin number;
			}
			else
			{
				//Table 20. Port Bit configuration table
				//If Pull-Up input -> PxODR == 0
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}

		}

	}
	//Writing the configuration base on PinConfig on CNFx & MODEx
	(*configReg) |= ( (CNFx_MODEx)<<Get_CRL_CRH_Position(PinConfig->GPIO_PinNumber) );
}

/**================================================================
 * @Fn			-MCAL_GPIO_Reset
 * @brief		-Resets the GPIOx Registers
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select which GPIO Peripheral Instant
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 */
void MCAL_GPIO_Reset(GPIO_TypeDef *GPIOx)
{
	// //Manually Reseting GPIO Register
	//GPIOx->CRL = 0x44444444;
	//GPIOx->CRH = 0x44444444;
	// //GPIOx->IDR = read only
	//GPIOx->ODR = 0x00000000;
	//GPIOx->BSRR = 0x00000000;
	//GPIOx->BRR = 0x00000000;
	//GPIOx->LCKR = 0x00000000;

	//Using Reset Controller
	//Reseting Bus that the GPIOx Connected to
	//APB2 Peripheral Reset Register (RCC_APB2RSTR)
	//Set then reset register to restart the port
	if(GPIOx == GPIOA)
	{
		//Bit2 IOPARST : IO PORT A Reset
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		//Bit3 IOPBRST : IO PORT B Reset
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		//Bit4 IOPCRST : IO PORT C Reset
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		//Bit5 IOPDRST : IO PORT D Reset
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		//Bit6 IOPERST : IO PORT E Reset
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}


/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief		-Read specific Pin
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Pin number to be read from according to @ref GPIO_PINS_Define
 * @retval 		-The input Pin value (two values based on @ref GPIO_PIN_State)
 * Note 		-None
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber)
{
	uint8_t ReadStatus;
	if( ((GPIOx->IDR) & PinNumber) != (uint32_t) GPIO_PIN_RESET )
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
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @retval 		-The input PORT value
 * Note 		-None
 */
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx)
{
	uint16_t ReadStatus;
	ReadStatus = (uint16_t)GPIOx->IDR;
	return ReadStatus;
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
void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx ,uint16_t PinNumber , uint8_t Value)
{
	if( Value != GPIO_PIN_RESET )
	{
		//using bit set/reset register (BSRR)
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit
		GPIOx->BSRR = PinNumber;
	}
	else
	{
		//using bit reset register (BRR)
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BRR = PinNumber;
	}
}




/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief		-Write value on Port
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-Value : Port value
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint16_t Value)
{
	GPIOx->ODR = (uint16_t)Value;
}


/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief		-Toggle a specific PIN
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Toggled according to @ref GPIO_PINS_Define
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}


/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief		-Locking allows the IO configuration to be frozen Until reset
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Locked according to @ref GPIO_PINS_Define
 * @retval 		-Ok if lock is successful , Error if not (according to @ref GPIO_LOCK_State)
 * Note 		-None
 */
uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{

/*	Bit 16 LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	0: Port configuration lock key not active
	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.
	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	These bits are read write but can only be written when the LCKK bit is 0.
	0: Port configuration not locked
	1: Port configuration locked.
	*/

	//Set LCKK: BIT16
	volatile uint32_t LCK_Config = 1<<16;

	//Set LCKy
	LCK_Config |= PinNumber;

	//Write 1
	GPIOx->LCKR = LCK_Config ;
	//Write 0
	GPIOx->LCKR = PinNumber ;
	//Write 1
	GPIOx->LCKR = LCK_Config ;
	//Read 0
	LCK_Config = GPIOx->LCKR;
	//Read 1 (Confirm that Lock is Active)
	if ((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_LOCK_OK;
	}
	else
	{
		return GPIO_LOCK_ERROR;
	}
}

