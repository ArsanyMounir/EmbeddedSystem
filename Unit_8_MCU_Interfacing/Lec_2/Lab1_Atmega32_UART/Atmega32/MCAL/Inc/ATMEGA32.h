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


/*//USART I/O Data Register
#define UDR							*((volatile uint8_t*)0x2C)
//USART Control and Status Register A
#define UCSRA						*((volatile uint8_t*)0x2B)
//USART Control and Status Register B
#define UCSRB						*((volatile uint8_t*)0x2A)
//USART Control and Status Register C
#define UCSRC						*((volatile uint8_t*)0x40)
//USART Baud Rate Registers
#define UBRRL						*((volatile uint8_t*)0x29)
#define UBRRH						*((volatile uint8_t*)0x40)
*/

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


//USART
#define USART					((USART_TypeDef*)USART_BASE)

//-----------------------------------------------------------------
//*****************************************************************
//-----------------------------------------------------------------


#define ENABLE_GLOBAL_INTERRUPT()				SREG |= (1<<7)
#define DISABLE_GLOBAL_INTERRUPT()				SREG &= ~(1<<7)



#endif /* MCAL_INC_ATMEGA32_H_ */
