/*
 * STM32_F103C6_GPIO_Driver.c
 *
 *  Created on: Apr 7, 2024
 *      Author: Arsany
 */

//========================================================
//						Includes
//========================================================


#include "STM32_F103C6_EXTI_Driver.h"


//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//					Generic Variables
//========================================================
void (*GP_IRQ_CALLBACK[15])(void);

//========================================================
//					Generic Macros
//========================================================

#define AFIO_GPIO_EXTI_MAPPING(x)		(	(x==GPIOA)? 0:\
											(x==GPIOB)?	1:\
											(x==GPIOC)? 2:\
											(x==GPIOD)?	3:0	)



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//					Generic Functions
//========================================================

void ENABLE_NVIC (uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0 :
		NVIC_IRQ6_EXTI0_Enable();
		break;
	case 1 :
		NVIC_IRQ7_EXTI1_Enable();
		break;
	case 2 :
		NVIC_IRQ8_EXTI2_Enable();
		break;
	case 3 :
		NVIC_IRQ9_EXTI3_Enable();
		break;
	case 4 :
		NVIC_IRQ10_EXTI4_Enable();
		break;
	case 5 :
	case 6 :
	case 7 :
	case 8 :
	case 9 :
		NVIC_IRQ23_EXTI5_9_Enable();
		break;

	case 10 :
	case 11 :
	case 12 :
	case 13 :
	case 14 :
	case 15	:
		NVIC_IRQ40_EXTI10_15_Enable();
		break;

	}
}

void DISABLE_NVIC (uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0 :
		NVIC_IRQ6_EXTI0_Disable();
		break;
	case 1 :
		NVIC_IRQ7_EXTI1_Disable();
		break;
	case 2 :
		NVIC_IRQ8_EXTI2_Disable();
		break;
	case 3 :
		NVIC_IRQ9_EXTI3_Disable();
		break;
	case 4 :
		NVIC_IRQ10_EXTI4_Disable();
		break;
	case 5 :
	case 6 :
	case 7 :
	case 8 :
	case 9 :
		NVIC_IRQ23_EXTI5_9_Disable();
		break;

	case 10 :
	case 11 :
	case 12 :
	case 13 :
	case 14 :
	case 15	:
		NVIC_IRQ40_EXTI10_15_Disable();
		break;

	}
}












void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	//Configure GPIO Pin to work as AF Input (Floating Input)
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_AF_INPUT;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PinConfig);


	//Update AFIO to Route to EXTI line with PORT A, B, C, D
	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_InputLineNumber /4;
	uint8_t AFIO_EXTICR_Position =(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber %4 )*4 ;
	//Note: remainder gives an index that when multiplied by 4 gives the exact bit index

	//Clear 4 bits to prevent wrong port selection
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF<<AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_MAPPING(EXTI_Config->EXTI_PIN.GPIO_PORT) & 0xF) << AFIO_EXTICR_Position );



	//Update Rising Or Falling Edge OR BOTH
	EXTI->RTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_BOTH)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}


	//Update IRQ Handling Callback
	GP_IRQ_CALLBACK[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->Ptr_IRQ_CALLBACK;

	//Enable or Disable IRQ & NVIC
	if(EXTI_Config->IRQ_Enable == EXTI_IRQ_ENBALE)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		ENABLE_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else
	{
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		DISABLE_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

}







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

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}





/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Reset
 * @brief		-Reset the EXTI Registers and NVIC IRQ MASK
 * @param [in]	-None
 * @retval 		-None
 * Note 		-None
 */
void MCAL_EXTI_GPIO_Reset(void)
{
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;

	//rc_w1 == Write One to clear
	EXTI->PR = 0xFFFFFFFF;

	//Disable EXTI IRQ From NVIC
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();

}

/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Update
 * @brief		-Updates EXTIx from specific GPIO PIN and the mask, trigger condition and the call back function
 * @param [in] 	-EXTI_Config : set by @ref EXTI_Define @ref EXTI_Trigger_Define @ref EXTI_IRQ_Define
 * @retval 		-None
 * Note 		-STM32F103C6 MCU has GPIO A,B,C,D,E
 * 				 but LQFP48 Package has A,B ,Part of C&D and no E
 * 				-RCC clock for AFIO and the used GPIO port must be enabled
 */

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}








//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------







//========================================================
//			External Interrupt Routines
//========================================================


void EXTI0_IRQHandler (void)
{
	//Clear EXTI PR
	EXTI->PR |= 1<<0;
	//Call IRQ
	GP_IRQ_CALLBACK[0]();
}

void EXTI1_IRQHandler (void)
{
	//Clear EXTI PR
	EXTI->PR |= 1<<1;
	//Call IRQ
	GP_IRQ_CALLBACK[1]();
}

void EXTI2_IRQHandler (void)
{
	//Clear EXTI PR
	EXTI->PR |= 1<<2;
	//Call IRQ
	GP_IRQ_CALLBACK[2]();
}

void EXTI3_IRQHandler (void)
{
	//Clear EXTI PR
	EXTI->PR |= 1<<3;
	//Call IRQ
	GP_IRQ_CALLBACK[3]();
}

void EXTI4_IRQHandler (void)
{
	//Clear EXTI PR
	EXTI->PR |= 1<<4;
	//Call IRQ
	GP_IRQ_CALLBACK[4]();
}

void EXTI9_5_IRQHandler (void)
{
	if(EXTI->PR & 1 <<5)
	{
		EXTI->PR |= 1<<5;
		GP_IRQ_CALLBACK[5]();
	}
	if(EXTI->PR & 1 <<6)
	{
		EXTI->PR |= 1<<6;
		GP_IRQ_CALLBACK[6]();
	}
	if(EXTI->PR & 1 <<7)
	{
		EXTI->PR |= 1<<7;
		GP_IRQ_CALLBACK[7]();
	}
	if(EXTI->PR & 1 <<8)
	{
		EXTI->PR |= 1<<8;
		GP_IRQ_CALLBACK[8]();
	}
	if(EXTI->PR & 1 <<9)
	{
		EXTI->PR |= 1<<9;
		GP_IRQ_CALLBACK[9]();
	}

}

void EXTI15_10_IRQHandler (void)
{
	if(EXTI->PR & 1 <<10)
	{
		EXTI->PR |= 1<<10;
		GP_IRQ_CALLBACK[10]();
	}
	if(EXTI->PR & 1 <<11)
	{
		EXTI->PR |= 1<<11;
		GP_IRQ_CALLBACK[11]();
	}
	if(EXTI->PR & 1 <<12)
	{
		EXTI->PR |= 1<<12;
		GP_IRQ_CALLBACK[12]();
	}
	if(EXTI->PR & 1 <<13)
	{
		EXTI->PR |= 1<<13;
		GP_IRQ_CALLBACK[13]();
	}
	if(EXTI->PR & 1 <<14)
	{
		EXTI->PR |= 1<<14;
		GP_IRQ_CALLBACK[14]();
	}
	if(EXTI->PR & 1 <<15)
	{
		EXTI->PR |= 1<<15;
		GP_IRQ_CALLBACK[15]();
	}

}








