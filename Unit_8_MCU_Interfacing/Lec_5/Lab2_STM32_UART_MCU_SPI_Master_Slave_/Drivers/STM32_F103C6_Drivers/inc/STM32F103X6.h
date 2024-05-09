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

//NVIC Register Memory Map
#define NVIC_BASE										0xE000E100UL
#define NVIC_ISER0										*(volatile uint32_t*)(NVIC_BASE + 0x000)
#define NVIC_ISER1										*(volatile uint32_t*)(NVIC_BASE + 0x004)
#define NVIC_ISER2										*(volatile uint32_t*)(NVIC_BASE + 0x008)
#define NVIC_ICER0										*(volatile uint32_t*)(NVIC_BASE + 0x080)
#define NVIC_ICER1										*(volatile uint32_t*)(NVIC_BASE + 0x084)
#define NVIC_ICER2										*(volatile uint32_t*)(NVIC_BASE + 0x088)

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

//USART1
#define USART1_BASE										0x40013800UL

//SPI1
#define SPI1_BASE										0x40013000UL


//========================================================
//		  Base Addresses for APB1 Bus Peripherals
//========================================================

//USART2

#define USART2_BASE										0x40004400UL

//USART3
#define USART3_BASE										0x40004800UL

//SPI2
#define SPI2_BASE										0x40003800UL



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
	volatile uint32_t EXTICR[4] ;			//External Interrupt Configuration1-4	(0x08->0x14)
	volatile uint32_t Reserved;				//Reserved								(0x18)
	volatile uint32_t MAPR2 ;				//Remap I/O Configuration Register2		(0x1C)

}AFIO_TypeDef;

//========================================================
//		    Peripheral Registers : USART
//========================================================

typedef struct
{
	volatile uint32_t SR ;					//Status Register 					(0x00)
	volatile uint32_t DR ;					//Data Register 					(0x04)
	volatile uint32_t BRR ;					//Baud Rate Register 				(0x08)
	volatile uint32_t CR1 ;					//Control Register 	1				(0x0C)
	volatile uint32_t CR2 ;					//Control Register 	2				(0x10)
	volatile uint32_t CR3 ;					//Control Register 	3				(0x14)
	volatile uint32_t GTPR ;				//Guard Time & Prescaler Register	(0x18)
}USART_TypeDef;

//========================================================
//		    Peripheral Registers : SPI
//========================================================

typedef struct
{
	volatile uint32_t CR1 ;					//Control Register 	1				(0x00)
	volatile uint32_t CR2 ;					//Control Register 	2				(0x04)
	volatile uint32_t SR ;					//Status Register	 				(0x08)
	volatile uint32_t DR ;					//Data Register						(0x0C)
	volatile uint32_t CRCPR ;				//CRC Polynomial Register			(0x10)
	volatile uint32_t RXCRCR ;				//Rx CRC Register					(0x14)
	volatile uint32_t TXCRCR ;				//Tx CRC Register					(0x18)
	volatile uint32_t I2SCFGR ;				//I2S Configuration Register		(0x1C)
	volatile uint32_t I2SPR ;				//I2S Prescaler Register			(0x20)
}SPI_TypeDef;





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

//USART
#define USART1								((USART_TypeDef *)USART1_BASE)
#define USART2								((USART_TypeDef *)USART2_BASE)
#define USART3								((USART_TypeDef *)USART3_BASE)

//SPI
#define SPI1								((SPI_TypeDef *)SPI1_BASE)
#define SPI2								((SPI_TypeDef *)SPI2_BASE)

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

//Enable USART Clock
#define RCC_USART1_CLK_EN()					(RCC->APB2ENR |= 1<<14)
#define RCC_USART2_CLK_EN()					(RCC->APB1ENR |= 1<<17)
#define RCC_USART3_CLK_EN()					(RCC->APB1ENR |= 1<<18)


//Disable USART Clock
#define RCC_USART1_CLK_RESET()				(RCC->APB2RSTR |= 1<<14)
#define RCC_USART2_CLK_RESET()				(RCC->APB1RSTR |= 1<<17)
#define RCC_USART3_CLK_RESET()				(RCC->APB1RSTR |= 1<<18)

//Enable SPI Clock
#define RCC_SPI1_CLK_EN()					(RCC->APB2ENR |= 1<<12)
#define RCC_SPI2_CLK_EN()					(RCC->APB1ENR |= 1<<14)

//Disable SPI Clock
#define RCC_SPI1_CLK_RESET()					(RCC->APB2RSTR |= 1<<12)
#define RCC_SPI2_CLK_RESET()					(RCC->APB1RSTR |= 1<<14)



//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//				 Interrupt Vector Table
//========================================================

//External Interrupts
#define EXTI0_IRQ					6
#define EXTI1_IRQ					7
#define EXTI2_IRQ					8
#define EXTI3_IRQ					9
#define EXTI4_IRQ					10
#define EXTI5_IRQ					23
#define EXTI6_IRQ					23
#define EXTI7_IRQ					23
#define EXTI8_IRQ					23
#define EXTI9_IRQ					23
#define EXTI10_IRQ					40
#define EXTI11_IRQ					40
#define EXTI12_IRQ					40
#define EXTI13_IRQ					40
#define EXTI14_IRQ					40
#define EXTI15_IRQ					40

//USART Interrupts
#define USART1_IRQ					37
#define USART2_IRQ					38
#define USART3_IRQ					39

//SPI Interrupts
#define SPI1_IRQ					35
#define SPI2_IRQ					36

//========================================================
//		  NVIC IRQ Enable and Disable Macros
//========================================================


#define NVIC_IRQ6_EXTI0_Enable()			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable()			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable()			(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable()			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable()			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable()			(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable()		(NVIC_ISER1 |= 1<<(EXTI10_IRQ-32) )//40-32 = 8

#define NVIC_IRQ6_EXTI0_Disable()			(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable()			(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable()			(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable()			(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable()			(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable()		(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable()		(NVIC_ICER1 |= 1<<(EXTI10_IRQ-32) )//40-32 = 8

//USART Interrupt Enable
#define NVIC_IRQ37_USART1_Enable()			(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_Enable()			(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_Enable()			(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))

//USART Interrupt Disable
#define NVIC_IRQ37_USART1_Disable()			(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_Disable()			(NVIC_ICER1 |= 1<<(USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_Disable()			(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))

//SPI Interrupt Enable
#define NVIC_IRQ35_SPI1_Enable()			(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_IRQ36_SPI2_Enable()			(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))

//SPI Interrupt Disable
#define NVIC_IRQ35_SPI1_Disable()			(NVIC_ICER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_IRQ36_SPI2_Disable()			(NVIC_ICER1 |= 1<<(SPI2_IRQ - 32))




#endif /* INC_STM32F103X6_H_ */
