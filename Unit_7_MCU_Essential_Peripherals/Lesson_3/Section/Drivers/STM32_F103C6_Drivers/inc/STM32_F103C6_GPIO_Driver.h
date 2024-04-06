/*
 * STM32_F103C6_GPIO_Driver.h
 *
 *  Created on: Apr 4, 2024
 *      Author: Arsany
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//========================================================
//						INCLUDES
//========================================================


#include "STM32F103X6.h"


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//				Configuration Structure
//========================================================

typedef struct
{
	uint16_t GPIO_PinNumber ; 	//Specifies the GPIO Pins to be Configured
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref GPIO_PINS_Define

	uint8_t GPIO_MODE ;			//Specifies the Operation mode of the selected pins
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref GPIO_MODE_Define

	uint8_t GPIO_Output_Speed;  //Specifies clock speed of the selected pins
								//This Parameter must be set with value
								//from Macro Configuration Manual @ref GPIO_Output_Define

}GPIO_PinConfig_t;




//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//			Macros Configuration References
//========================================================

//@ref GPIO_PINS_Define

#define  GPIO_PIN_0 								((uint16_t)0x0001)	//Pin 0 Selected
#define  GPIO_PIN_1 								((uint16_t)0x0002)	//Pin 1 Selected
#define  GPIO_PIN_2 								((uint16_t)0x0004)	//Pin 2 Selected
#define  GPIO_PIN_3 								((uint16_t)0x0008)	//Pin 3 Selected
#define  GPIO_PIN_4 								((uint16_t)0x0010)	//Pin 4 Selected
#define  GPIO_PIN_5 								((uint16_t)0x0020)	//Pin 5 Selected
#define  GPIO_PIN_6 								((uint16_t)0x0040)	//Pin 6 Selected
#define  GPIO_PIN_7 								((uint16_t)0x0080)	//Pin 7 Selected
#define  GPIO_PIN_8 								((uint16_t)0x0100)	//Pin 8 Selected
#define  GPIO_PIN_9 								((uint16_t)0x0200)	//Pin 9 Selected
#define  GPIO_PIN_10 								((uint16_t)0x0400)	//Pin 10 Selected
#define  GPIO_PIN_11								((uint16_t)0x0800)	//Pin 11 Selected
#define  GPIO_PIN_12								((uint16_t)0x1000)	//Pin 12 Selected
#define  GPIO_PIN_13								((uint16_t)0x2000)	//Pin 13 Selected
#define  GPIO_PIN_14								((uint16_t)0x4000)	//Pin 14 Selected
#define  GPIO_PIN_15								((uint16_t)0x8000)	//Pin 15 Selected
#define  GPIO_PIN_ALL								((uint16_t)0xFFFF)	//ALL Pins Selected


//------------------------------------------
//@ref GPIO_MODE_Define

//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input

#define  GPIO_MODE_ANALOG 							0x00000000U	//Analog mode
#define  GPIO_MODE_INPUT_FLO						0x00000001U //Floating input (reset state)
#define  GPIO_MODE_INPUT_PU							0x00000002U	//Input with pull-up
#define  GPIO_MODE_INPUT_PD							0x00000003U	//Input with pull-down
#define  GPIO_MODE_OUTPUT_PP						0x00000004U //General purpose output push-pull
#define  GPIO_MODE_OUTPUT_OD						0x00000005U //General purpose output Open-drain
#define  GPIO_MODE_OUTPUT_AF_PP						0x00000006U //Alternate function output Push-pull
#define  GPIO_MODE_OUTPUT_AF_OD						0x00000007U //Alternate function output Open-drain
#define  GPIO_MODE_AF_INPUT 						0x00000008U //Alternate function input





//------------------------------------------
//@ref GPIO_Output_Define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.

#define  GPIO_Output_Speed_10M						0x00000001U //max speed 10 MHz.
#define  GPIO_Output_Speed_2M						0x00000002U	//max speed 2 MHz.
#define  GPIO_Output_Speed_50M						0x00000003U	//max speed 50 MHz.



//------------------------------------------
//@ref GPIO_PIN_State
#define GPIO_PIN_SET								1
#define GPIO_PIN_RESET								0



//------------------------------------------
//@ref GPIO_LOCK_State
#define GPIO_LOCK_OK								1
#define GPIO_LOCK_ERROR								0



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			APIs Supported by "MCAL GPIO DRIVER"
//========================================================

/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief		-Initializes the GPIOx PINy according to the specified parameters of PinConfig
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinConfig : Pointer to GPIO_PinConfig_t which contains the configuration info for specified GPIO
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig );


/**================================================================
 * @Fn			-MCAL_GPIO_Reset
 * @brief		-Resets the GPIOx Registers
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select which GPIO Peripheral Instant
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 */
void MCAL_GPIO_Reset(GPIO_TypeDef *GPIOx);


/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief		-Read specific Pin
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Pin number to be read from according to @ref GPIO_PINS_Define
 * @retval 		-The input Pin value (two values based on @ref GPIO_PIN_State)
 * Note 		-None
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber);


/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief		-Read entire Port values
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @retval 		-The input PORT value
 * Note 		-None
 */
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx);




/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief		-Write value on specific PIN
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Write on according to @ref GPIO_PINS_Define
 * @param [in]	-Value : PIN value
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx ,uint16_t PinNumber , uint8_t Value);


/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief		-Write value on Port
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-Value : Port value
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint16_t Value);


/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief		-Toggle a specific PIN
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Toggled according to @ref GPIO_PINS_Define
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx , uint16_t PinNumber);


/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief		-Locking allows the IO configuration to be frozen Until reset
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param [in]	-PinNumber : Specific Pin number to be Locked according to @ref GPIO_PINS_Define
 * @retval 		-Ok if lock is successful , Error if not (according to @ref GPIO_LOCK_State)
 * Note 		-None
 */
uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber);


#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
