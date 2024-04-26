/*
 * STM32_F103C6_RCC_Driver.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Arsany
 */
#include "STM32_F103C6_RCC_Driver.h"



//Set and cleared by software to control the division factor of the APB low-speed clock (PCLK1).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16

const uint8_t APBPrescaler[8U] = {0,0,0,0,1,2,3,4} ;

//Bits 7:4 HPRE: AHB prescaler
//Set and cleared by software to control the division factor of the AHB clock.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512

const uint8_t AHBPrescaler[16U] = {0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9} ;




/**================================================================
 * @Fn			-MCAL_RCC_GET_PCLK1
 * @brief		-Gives the value of PCLK1 clock
 * @param [in] 	-None
 * @retval 		-PCLK1
 * Note 		-None
*/
uint32_t MCAL_RCC_GET_PCLK1(void)
{
	//Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	return (MCAL_RCC_GET_HCLK() >> APBPrescaler[(RCC->CFGR >> 8) & 0b111]);

}



/**================================================================
 * @Fn			-MCAL_RCC_GET_PCLK2
 * @brief		-Gives the value of PCLK2 clock
 * @param [in] 	-None
 * @retval 		-PCLK2
 * Note 		-None
*/
uint32_t MCAL_RCC_GET_PCLK2(void)
{
	//Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	return (MCAL_RCC_GET_HCLK() >> APBPrescaler[((RCC->CFGR >> 11) & 0b111)]);

}


/**================================================================
 * @Fn			-MCAL_RCC_GET_SYSCLK
 * @brief		-Gives the value of SYSCLK
 * @param [in] 	-None
 * @retval 		-SYSCLK
 * Note 		-None
*/
uint32_t MCAL_RCC_GET_SYSCLK(void)
{

//	Bits 3:2 SWS: System clock switch status
//	Set and cleared by hardware to indicate which clock source is used as system clock
//	00: HSI oscillator used as system clock
//	01: HSE oscillator used as system clock
//	10: PLL used as system clock
//	11: not applicable
	switch ((RCC->CFGR >> 2)& 0b11)
	{
	case 0 :
		return HSI_CLK;
		break;
	case 1 :
		//To be implemented later
		return HSE_CLK;
		break;
	case 2 :
		//To be implemented later
		return 16000000;
		break;


	}


}

/**================================================================
 * @Fn			-MCAL_RCC_GET_HCLK
 * @brief		-Gives the value of HCLK
 * @param [in] 	-None
 * @retval 		-HCLK
 * Note 		-None
*/
uint32_t MCAL_RCC_GET_HCLK(void)
{

	return (MCAL_RCC_GET_SYSCLK() >> AHBPrescaler[((RCC->CFGR >> 4) & 0xF)]);

}



