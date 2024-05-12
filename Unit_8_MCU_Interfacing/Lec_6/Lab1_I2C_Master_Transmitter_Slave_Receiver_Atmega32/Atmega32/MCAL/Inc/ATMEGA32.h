/*
 * ATMEGA32.h
 *
 *  Created on: Apr 11, 2024
 *      Author: Arsany
 */

#ifndef MCAL_INC_ATMEGA32_H_
#define MCAL_INC_ATMEGA32_H_


//========================================================
//						INCLUDES
//========================================================

#include "stdlib.h"
#include "stdint.h"

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------



//========================================================
//			  Base Addresses for Peripherals
//========================================================
//GPIOs
#define PORTA_BASE  				(0x39)
#define PORTB_BASE		   			(0x36)
#define PORTC_BASE 					(0x33)
#define PORTD_BASE   				(0x30)

//EXTI
#define EXTI_BASE   				(0x54)
#define SREG_BASE					(0x5F)
#define SREG 						*((volatile uint8_t*)SREG_BASE)
//UART
#define USART_BASE					(0x29)

#define UCSRC_BASE					(0x40)
#define UBRRH_BASE					(0x40)

//SPI
#define	SPI_BASE					(0x2D)

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
	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;

}GPIO_TypeDef;

//========================================================
//		    Peripheral Registers : USART
//========================================================

typedef struct
{
	volatile uint8_t UBRRL;
	volatile uint8_t UCSRB;
	volatile uint8_t UCSRA;
	volatile uint8_t UDR;
}USART_TypeDef;

#define UCSRC						*((volatile uint8_t*)UCSRC_BASE)
#define UBRRH						*((volatile uint8_t*)UBRRH_BASE)



//========================================================
//		    Peripheral Registers : SPI
//========================================================
typedef struct
{
	volatile uint8_t SPCR;
	volatile uint8_t SPSR;
	volatile uint8_t SPDR;
}SPI_TypeDef;




//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------

//========================================================
//				    Peripheral Instants
//========================================================

//GPIOs
#define GPIOA					((GPIO_TypeDef*)PORTA_BASE)
#define GPIOB					((GPIO_TypeDef*)PORTB_BASE)
#define GPIOC					((GPIO_TypeDef*)PORTC_BASE)
#define GPIOD					((GPIO_TypeDef*)PORTD_BASE)
#define DDRA					*((volatile uint8_t*)0x3A)
#define PORTA					*((volatile uint8_t*)0x3B)
//USART
#define USART					((USART_TypeDef*)USART_BASE)

//SPI
#define SPI						((SPI_TypeDef*)SPI_BASE)

//TWI
#define TWBR					*((volatile uint8_t*)0x20)
#define TWCR					*((volatile uint8_t*)0x56)
#define TWSR					*((volatile uint8_t*)0x21)
#define TWDR					*((volatile uint8_t*)0x23)
#define TWAR					*((volatile uint8_t*)0x22)

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


#define ENABLE_GLOBAL_INTERRUPT()				SREG |= (1<<7)
#define DISABLE_GLOBAL_INTERRUPT()				SREG &= ~(1<<7)



#endif /* MCAL_INC_ATMEGA32_H_ */
