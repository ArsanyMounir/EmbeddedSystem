/*
 * ATMEGA32_GPIO_Driver.h
 *
 *  Created on: Apr 11, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_ATMEGA32_GPIO_DRIVER_H_
#define MCAL_INC_ATMEGA32_GPIO_DRIVER_H_

//========================================================
//						INCLUDES
//========================================================

#include "ATMEGA32.h"


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//				Configuration Structure
//========================================================
typedef struct
{
	uint8_t	GPIO_PinNumber;					//Specifies the GPIO Pins to be Configured
											//This Parameter must be set with value
											//from Macro Configuration Manual @ref GPIO_PINS_Define

	uint8_t	GPIO_DataDirection;				//Specifies the Data direction of GPIO Pins
											//This Parameter must be set with value
											//from Macro Configuration Manual @ref GPIO_DataDirection_Define

	uint8_t	GPIO_Resistor_State;			//Specifies the Driving Resistor (Pull-up / Pull-down)
											//This Parameter must be set with value
											//from Macro Configuration Manual @ref GPIO_Resistor_State_Define





}GPIO_PinConfig_t;





//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//			Macros Configuration References
//========================================================
//@ref GPIO_PINS_Define
#define  GPIO_PIN_0 						0	//Pin 0 Selected
#define  GPIO_PIN_1 						1	//Pin 1 Selected
#define  GPIO_PIN_2 						2	//Pin 2 Selected
#define  GPIO_PIN_3 						3	//Pin 3 Selected
#define  GPIO_PIN_4 						4	//Pin 4 Selected
#define  GPIO_PIN_5 						5	//Pin 5 Selected
#define  GPIO_PIN_6 						6	//Pin 6 Selected
#define  GPIO_PIN_7 						7	//Pin 7 Selected





//------------------------------------------
//@ref GPIO_DataDirection_Define
#define GPIO_INPUT							0	//Input mode
#define GPIO_OUTPUT							1	//Output mode


//------------------------------------------
//@ref GPIO_Resistor_State_Define
#define GPIO_PULL_UP						1	//High State
#define GPIO_PULL_DOWN						0	//Low State



//------------------------------------------
//@ref GPIO_PIN_State
#define GPIO_PIN_SET								1
#define GPIO_PIN_RESET								0



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			APIs Supported by "MCAL GPIO DRIVER"
//========================================================

/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief		-Initializes the GPIOx PINy according to the specified parameters of PinConfig
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinConfig : Pointer to GPIO_PinConfig_t which contains the configuration info for specified GPIO
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* PinConfig );




/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief		-Read specific Pin
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinNumber : Pin number to be read from according to @ref GPIO_PINS_Define
 * @retval 		-The input Pin value (two values based on @ref GPIO_PIN_State)
 * Note 		-None
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx,uint8_t PinNumber);


/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief		-Read entire Port values
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @retval 		-The input PORT value
 * Note 		-None
 */
uint8_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx);



/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief		-Write value on specific PIN
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinNumber : Specific Pin number to be Write on according to @ref GPIO_PINS_Define
 * @param [in]	-Value : PIN value
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx ,uint8_t PinNumber , uint8_t Value);


/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief		-Write value on Port
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-Value : Port value
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint8_t Value);


/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief		-Toggle a specific PIN
 * @param [in] 	-GPIOx : where x can be (A,B,C,D depending on device used) to select which GPIO Peripheral Instant
 * @param [in]	-PinNumber : Specific Pin number to be Toggled according to @ref GPIO_PINS_Define
 * @retval 		-None
 * Note 		-None
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx , uint8_t PinNumber);






#endif /* MCAL_INC_ATMEGA32_GPIO_DRIVER_H_ */
