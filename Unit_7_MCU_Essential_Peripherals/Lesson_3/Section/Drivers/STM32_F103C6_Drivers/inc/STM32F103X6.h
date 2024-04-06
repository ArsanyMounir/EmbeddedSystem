/*
 * STM32F103X6.h
 *
 *  Created on: Apr 4, 2024
 *      Author: Arsany
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//========================================================
//						INCLUDES
//========================================================

#include "stdlib.h"
#include "stdint.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//				Base Addresses for Memories
//========================================================

#define FLASH_MEMORY_BASE								0x08000000UL
#define SYSTEM_MEMORY_BASE								0x1FFFF000UL
#define SRAM_MEMORY_BASE								0x20000000UL


#define PERIPHERALS_BASE								0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE				0xE0000000UL


//========================================================
//		  Base Addresses for AHB Bus Peripherals
//========================================================


#define RCC_BASE										0x40021000UL


//========================================================
//		  Base Addresses for APB2 Bus Peripherals
//========================================================



//GPIO "General Purpose Input Output"
//PORTA , PORTB Are fully included in Package LPFP48 package
#define GPIOA_BASE										0x40010800UL
#define GPIOB_BASE										0x40010C00UL

//PORTC , PORTD Are partially included
#define GPIOC_BASE										0x40011000UL
#define GPIOD_BASE										0x40011400UL

//PORTE is not included
#define GPIOE_BASE										0x40011800UL


//EXTI "External Interrupt"
#define EXTI_BASE										0x40010400UL


//AFIO	"Alternative Function Input Output"
#define AFIO_BASE										0x40010000UL


//========================================================
//		  Base Addresses for APB1 Bus Peripherals
//========================================================




//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------




//========================================================
//				    Peripheral Registers
//========================================================


//========================================================
//		    Peripheral Registers : GPIO
//========================================================

typedef struct
{
	volatile uint32_t CRL ;					//Configuration Register Low			(0x00)
	volatile uint32_t CRH ;					//Configuration Register High			(0x04)
	volatile uint32_t IDR ;					//Input Data Register 					(0x08)
	volatile uint32_t ODR ;					//Input Data Register					(0x0C)
	volatile uint32_t BSRR ;				//Bit Set/Reset Register				(0x10)
	volatile uint32_t BRR ;					//Bit Reset Register					(0x14)
	volatile uint32_t LCKR ;				//Lock register							(0x18)
}GPIO_TypeDef;




//========================================================
//		    Peripheral Registers : RCC
//========================================================

typedef struct
{
	volatile uint32_t CR ;					//Clock Control Register 				(0x00)
	volatile uint32_t CFGR ;				//Clock Configuration Register 			(0x04)
	volatile uint32_t CIR ;					//Clock Interrupt Register 				(0x08)
	volatile uint32_t APB2RSTR ;			//APB2 Peripheral Reset Register		(0x0C)
	volatile uint32_t APB1RSTR ;			//APB1 Peripheral Reset Register		(0x10)
	volatile uint32_t AHBENR ;				//AHB Peripheral Clock Enable Register	(0x14)
	volatile uint32_t APB2ENR ;				//APB2 Peripheral Clock Enable Register	(0x18)
	volatile uint32_t APB1ENR ;				//APB1 Peripheral Clock Enable Register	(0x1C)
	volatile uint32_t BDCR ;				//Backup Domain Control Register		(0x20)
	volatile uint32_t CSR ;					//Control/Status Register				(0x24)
}RCC_TypeDef;



//========================================================
//		    Peripheral Registers : EXTI
//========================================================

typedef struct
{
	volatile uint32_t IMR ;					//Interrupt Mask Register				(0x00)
	volatile uint32_t EMR ;					//Event Mask Register		 			(0x04)
	volatile uint32_t RTSR ;				//Rising Trigger Selection Register		(0x08)
	volatile uint32_t FTSR ;				//Falling Trigger Selection Register	(0x0C)
	volatile uint32_t SWIER ;				//Software Interrupt Event Register		(0x10)
	volatile uint32_t PR ;					//Pending Register						(0x14)
}EXTI_TypeDef;



//========================================================
//		    Peripheral Registers : AFIO
//========================================================

typedef struct
{
	volatile uint32_t EVCR ;				//Event Control Register				(0x00)
	volatile uint32_t MAPR ;				//Remap I/O Configuration Register1		(0x04)
	volatile uint32_t EXTICR1 ;				//External Interrupt Configuration1		(0x08)
	volatile uint32_t EXTICR2 ;				//External Interrupt Configuration2		(0x0C)
	volatile uint32_t EXTICR3 ;				//External Interrupt Configuration3		(0x10)
	volatile uint32_t EXTICR4 ;				//External Interrupt Configuration4		(0x14)
	volatile uint32_t Reserved;				//Reserved								(0x18)
	volatile uint32_t MAPR2 ;				//Remap I/O Configuration Register2		(0x1C)

}AFIO_TypeDef;




//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//				    Peripheral Instants
//========================================================


//GPIOs
#define GPIOA								((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB								((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC								((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD								((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE								((GPIO_TypeDef *)GPIOE_BASE)

//RCC
#define RCC									((RCC_TypeDef *)RCC_BASE)

//EXTI
#define EXTI								((EXTI_TypeDef *)EXTI_BASE)

//AFIO
#define AFIO								((AFIO_TypeDef *)AFIO_BASE)

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


//========================================================
//				   Clock Enable Macros
//========================================================

//Enable GPIO Clock
#define RCC_GPIOA_CLK_EN()					(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()					(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()					(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()					(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()					(RCC->APB2ENR |= 1<<6)

//Enable AFIO Clock
#define RCC_AFIO_CLK_EN()					(RCC->APB2ENR |= 1<<0)





#endif /* INC_STM32F103X6_H_ */
