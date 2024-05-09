/*
 * STM32_F103C6_GPIO_Driver.h
 *
 *  Created on: Apr 7, 2024
 *      Author: Arsany
 */

#ifndef INC_STM32_F103C6_EXTI_DRIVER_H_
#define INC_STM32_F103C6_EXTI_DRIVER_H_

//========================================================
//						INCLUDES
//========================================================


#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//				Configuration Structure
//========================================================
typedef struct
{
	uint16_t 		EXTI_InputLineNumber;
	GPIO_TypeDef* 	GPIO_PORT;
	uint16_t 		GPIO_PIN;
	uint8_t 		IVT_IRQ_Number;
}EXTI_GPIO_Mapping_t;

typedef struct
{
 	EXTI_GPIO_Mapping_t 		EXTI_PIN;		//Specifies the External Interrupt GPIO Mapping
												//This Parameter must be set with value
												//from Macro Configuration Manual @ref EXTI_Define

 	uint8_t						Trigger_Case;	//Specifies RISING or FALLING or BOTH Triggers
 												//This Parameter must be set with value
 												//from Macro Configuration Manual @ref EXTI_Trigger_Define

 	uint8_t						IRQ_Enable;		//ENABLE or DISABLE the EXTI IRQ
 												//This Parameter must be set with value
 												//from Macro Configuration Manual @ref EXTI_EN_IRQ_Define

 	void(* Ptr_IRQ_CALLBACK)(void);				//Set C Function which will be called after the IRQ Happen


}EXTI_PinConfig_t;






//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//			Macros Configuration References
//========================================================

//@ref EXTI_Define

//EXTI0
#define EXTI0_PORTA0						(EXTI_GPIO_Mapping_t){ EXTI0 , GPIOA , GPIO_PIN_0 , EXTI0_IRQ }
#define EXTI0_PORTB0						(EXTI_GPIO_Mapping_t){ EXTI0 , GPIOB , GPIO_PIN_0 , EXTI0_IRQ }
#define EXTI0_PORTC0						(EXTI_GPIO_Mapping_t){ EXTI0 , GPIOC , GPIO_PIN_0 , EXTI0_IRQ }
#define EXTI0_PORTD0						(EXTI_GPIO_Mapping_t){ EXTI0 , GPIOD , GPIO_PIN_0 , EXTI0_IRQ }

//EXTI1
#define EXTI1_PORTA1						(EXTI_GPIO_Mapping_t){ EXTI1 , GPIOA , GPIO_PIN_1 , EXTI1_IRQ }
#define EXTI1_PORTB1						(EXTI_GPIO_Mapping_t){ EXTI1 , GPIOB , GPIO_PIN_1 , EXTI1_IRQ }
#define EXTI1_PORTC1						(EXTI_GPIO_Mapping_t){ EXTI1 , GPIOC , GPIO_PIN_1 , EXTI1_IRQ }
#define EXTI1_PORTD1						(EXTI_GPIO_Mapping_t){ EXTI1 , GPIOD , GPIO_PIN_1 , EXTI1_IRQ }

//EXTI2
#define EXTI2_PORTA2						(EXTI_GPIO_Mapping_t){ EXTI2 , GPIOA , GPIO_PIN_2 , EXTI2_IRQ }
#define EXTI2_PORTB2						(EXTI_GPIO_Mapping_t){ EXTI2 , GPIOB , GPIO_PIN_2 , EXTI2_IRQ }
#define EXTI2_PORTC2						(EXTI_GPIO_Mapping_t){ EXTI2 , GPIOC , GPIO_PIN_2 , EXTI2_IRQ }
#define EXTI2_PORTD2						(EXTI_GPIO_Mapping_t){ EXTI2 , GPIOD , GPIO_PIN_2 , EXTI2_IRQ }


//EXTI3
#define EXTI3_PORTA3						(EXTI_GPIO_Mapping_t){ EXTI3 , GPIOA , GPIO_PIN_3 , EXTI3_IRQ }
#define EXTI3_PORTB3						(EXTI_GPIO_Mapping_t){ EXTI3 , GPIOB , GPIO_PIN_3 , EXTI3_IRQ }
#define EXTI3_PORTC3						(EXTI_GPIO_Mapping_t){ EXTI3 , GPIOC , GPIO_PIN_3 , EXTI3_IRQ }
#define EXTI3_PORTD3						(EXTI_GPIO_Mapping_t){ EXTI3 , GPIOD , GPIO_PIN_3 , EXTI3_IRQ }

//EXTI4
#define EXTI4_PORTA4						(EXTI_GPIO_Mapping_t){ EXTI4 , GPIOA , GPIO_PIN_4 , EXTI4_IRQ }
#define EXTI4_PORTB4						(EXTI_GPIO_Mapping_t){ EXTI4 , GPIOB , GPIO_PIN_4 , EXTI4_IRQ }
#define EXTI4_PORTC4						(EXTI_GPIO_Mapping_t){ EXTI4 , GPIOC , GPIO_PIN_4 , EXTI4_IRQ }
#define EXTI4_PORTD4						(EXTI_GPIO_Mapping_t){ EXTI4 , GPIOD , GPIO_PIN_4 , EXTI4_IRQ }


//EXTI5
#define EXTI5_PORTA5					(EXTI_GPIO_Mapping_t){ EXTI5 , GPIOA , GPIO_PIN_5 , EXTI5_IRQ }
#define EXTI5_PORTB5					(EXTI_GPIO_Mapping_t){ EXTI5 , GPIOB , GPIO_PIN_5 , EXTI5_IRQ }
#define EXTI5_PORTC5					(EXTI_GPIO_Mapping_t){ EXTI5 , GPIOC , GPIO_PIN_5 , EXTI5_IRQ }
#define EXTI5_PORTD5					(EXTI_GPIO_Mapping_t){ EXTI5 , GPIOD , GPIO_PIN_5 , EXTI5_IRQ }


//EXTI6
#define EXTI6_PORTA6					(EXTI_GPIO_Mapping_t){ EXTI6 , GPIOA , GPIO_PIN_6 , EXTI6_IRQ }
#define EXTI6_PORTB6					(EXTI_GPIO_Mapping_t){ EXTI6 , GPIOB , GPIO_PIN_6 , EXTI6_IRQ }
#define EXTI6_PORTC6					(EXTI_GPIO_Mapping_t){ EXTI6 , GPIOC , GPIO_PIN_6 , EXTI6_IRQ }
#define EXTI6_PORTD6					(EXTI_GPIO_Mapping_t){ EXTI6 , GPIOD , GPIO_PIN_6 , EXTI6_IRQ }


//EXTI7
#define EXTI7_PORTA7					(EXTI_GPIO_Mapping_t){ EXTI7 , GPIOA , GPIO_PIN_7 , EXTI7_IRQ }
#define EXTI7_PORTB7					(EXTI_GPIO_Mapping_t){ EXTI7 , GPIOB , GPIO_PIN_7 , EXTI7_IRQ }
#define EXTI7_PORTC7					(EXTI_GPIO_Mapping_t){ EXTI7 , GPIOC , GPIO_PIN_7 , EXTI7_IRQ }
#define EXTI7_PORTD7					(EXTI_GPIO_Mapping_t){ EXTI7 , GPIOD , GPIO_PIN_7 , EXTI7_IRQ }


//EXTI8
#define EXTI8_PORTA8					(EXTI_GPIO_Mapping_t){ EXTI8 , GPIOA , GPIO_PIN_8 , EXTI8_IRQ }
#define EXTI8_PORTB8					(EXTI_GPIO_Mapping_t){ EXTI8 , GPIOB , GPIO_PIN_8 , EXTI8_IRQ }
#define EXTI8_PORTC8					(EXTI_GPIO_Mapping_t){ EXTI8 , GPIOC , GPIO_PIN_8 , EXTI8_IRQ }
#define EXTI8_PORTD8					(EXTI_GPIO_Mapping_t){ EXTI8 , GPIOD , GPIO_PIN_8 , EXTI8_IRQ }

//EXTI9
#define EXTI9_PORTA9					(EXTI_GPIO_Mapping_t){ EXTI9 , GPIOA , GPIO_PIN_9 , EXTI9_IRQ }
#define EXTI9_PORTB9					(EXTI_GPIO_Mapping_t){ EXTI9 , GPIOB , GPIO_PIN_9 , EXTI9_IRQ }
#define EXTI9_PORTC9					(EXTI_GPIO_Mapping_t){ EXTI9 , GPIOC , GPIO_PIN_9 , EXTI9_IRQ }
#define EXTI9_PORTD9					(EXTI_GPIO_Mapping_t){ EXTI9 , GPIOD , GPIO_PIN_9 , EXTI9_IRQ }


//EXTI10
#define EXTI10_PORTA10					(EXTI_GPIO_Mapping_t){ EXTI10 , GPIOA , GPIO_PIN_10 , EXTI10_IRQ }
#define EXTI10_PORTB10					(EXTI_GPIO_Mapping_t){ EXTI10 , GPIOB , GPIO_PIN_10 , EXTI10_IRQ }
#define EXTI10_PORTC10					(EXTI_GPIO_Mapping_t){ EXTI10 , GPIOC , GPIO_PIN_10 , EXTI10_IRQ }
#define EXTI10_PORTD10					(EXTI_GPIO_Mapping_t){ EXTI10 , GPIOD , GPIO_PIN_10 , EXTI10_IRQ }


//EXTI11
#define EXTI11_PORTA11					(EXTI_GPIO_Mapping_t){ EXTI11 , GPIOA , GPIO_PIN_11 , EXTI11_IRQ }
#define EXTI11_PORTB11					(EXTI_GPIO_Mapping_t){ EXTI11 , GPIOB , GPIO_PIN_11 , EXTI11_IRQ }
#define EXTI11_PORTC11					(EXTI_GPIO_Mapping_t){ EXTI11 , GPIOC , GPIO_PIN_11 , EXTI11_IRQ }
#define EXTI11_PORTD11					(EXTI_GPIO_Mapping_t){ EXTI11 , GPIOD , GPIO_PIN_11 , EXTI11_IRQ }


//EXTI12
#define EXTI12_PORTA12					(EXTI_GPIO_Mapping_t){ EXTI12 , GPIOA , GPIO_PIN_12 , EXTI12_IRQ }
#define EXTI12_PORTB12					(EXTI_GPIO_Mapping_t){ EXTI12 , GPIOB , GPIO_PIN_12 , EXTI12_IRQ }
#define EXTI12_PORTC12					(EXTI_GPIO_Mapping_t){ EXTI12 , GPIOC , GPIO_PIN_12 , EXTI12_IRQ }
#define EXTI12_PORTD12					(EXTI_GPIO_Mapping_t){ EXTI12 , GPIOD , GPIO_PIN_12 , EXTI12_IRQ }


//EXTI13
#define EXTI13_PORTA13					(EXTI_GPIO_Mapping_t){ EXTI13 , GPIOA , GPIO_PIN_13 , EXTI13_IRQ }
#define EXTI13_PORTB13					(EXTI_GPIO_Mapping_t){ EXTI13 , GPIOB , GPIO_PIN_13 , EXTI13_IRQ }
#define EXTI13_PORTC13					(EXTI_GPIO_Mapping_t){ EXTI13 , GPIOC , GPIO_PIN_13 , EXTI13_IRQ }
#define EXTI13_PORTD13					(EXTI_GPIO_Mapping_t){ EXTI13 , GPIOD , GPIO_PIN_13 , EXTI13_IRQ }


//EXTI14
#define EXTI14_PORTA14					(EXTI_GPIO_Mapping_t){ EXTI14 , GPIOA , GPIO_PIN_14 , EXTI14_IRQ }
#define EXTI14_PORTB14					(EXTI_GPIO_Mapping_t){ EXTI14 , GPIOB , GPIO_PIN_14 , EXTI14_IRQ }
#define EXTI14_PORTC14					(EXTI_GPIO_Mapping_t){ EXTI14 , GPIOC , GPIO_PIN_14 , EXTI14_IRQ }
#define EXTI14_PORTD14					(EXTI_GPIO_Mapping_t){ EXTI14 , GPIOD , GPIO_PIN_14 , EXTI14_IRQ }


//EXTI15
#define EXTI15_PORTA15					(EXTI_GPIO_Mapping_t){ EXTI15 , GPIOA , GPIO_PIN_15 , EXTI15_IRQ }
#define EXTI15_PORTB15					(EXTI_GPIO_Mapping_t){ EXTI15 , GPIOB , GPIO_PIN_15 , EXTI15_IRQ }
#define EXTI15_PORTC15					(EXTI_GPIO_Mapping_t){ EXTI15 , GPIOC , GPIO_PIN_15 , EXTI15_IRQ }
#define EXTI15_PORTD15					(EXTI_GPIO_Mapping_t){ EXTI15 , GPIOD , GPIO_PIN_15 , EXTI15_IRQ }


//---------------------------------------------------
//@ref EXTI_Trigger_Define
#define EXTI_Trigger_RISING				0
#define EXTI_Trigger_FALLING			1
#define EXTI_Trigger_BOTH				2



//---------------------------------------------------
//@ref EXTI_EN_IRQ_Define
#define EXTI_IRQ_ENBALE					1
#define EXTI_IRQ_DISABLE				0



//---------------------------------------------------
#define 	EXTI0		0
#define 	EXTI1		1
#define 	EXTI2		2
#define 	EXTI3		3
#define 	EXTI4		4
#define 	EXTI5		5
#define 	EXTI6		6
#define 	EXTI7		7
#define 	EXTI8		8
#define 	EXTI9		9
#define 	EXTI10		10
#define 	EXTI11		11
#define 	EXTI12		12
#define 	EXTI13		13
#define 	EXTI14		14
#define 	EXTI15		15



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//			APIs Supported by "MCAL EXTI DRIVER"
//========================================================


/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Init
 * @brief		-Initialize EXTIx from specific GPIO PIN and the mask, trigger condition and the call back function
 * @param [in] 	-EXTI_Config : set by @ref EXTI_Define @ref EXTI_Trigger_Define @ref EXTI_IRQ_Define
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 * 				-RCC clock for AFIO and the used GPIO port must be enabled
*/
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config);


/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Reset
 * @brief		-Reset the EXTI Registers and NVIC IRQ MASK
 * @param [in]	-None
 * @retval 		-None
 * Note 		-None
 */
void MCAL_EXTI_GPIO_Reset(void);



/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Update
 * @brief		-Updates EXTIx from specific GPIO PIN and the mask, trigger condition and the call back function
 * @param [in] 	-EXTI_Config : set by @ref EXTI_Define @ref EXTI_Trigger_Define @ref EXTI_IRQ_Define
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 * 				-RCC clock for AFIO and the used GPIO port must be enabled
*/


void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config);



#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
