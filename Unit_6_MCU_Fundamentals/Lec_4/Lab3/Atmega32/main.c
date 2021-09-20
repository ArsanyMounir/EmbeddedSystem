/*
 * main.c
 *
 *  Created on: Sep 20, 2021
 *      Author: Arshy
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define  F_CPU  1000000UL
//INT
#define IO_BASE         0x20
#define MCUCR			*(volatile unsigned int *)(IO_BASE + 0x35)
#define MCUCSR			*(volatile unsigned int *)(IO_BASE + 0x34)
#define GICR			*(volatile unsigned int *)(IO_BASE + 0x3B)
#define GIFR			*(volatile unsigned int *)(IO_BASE + 0x3A)
#define SREG			*(volatile unsigned int *)(IO_BASE + 0x3F)
//GPIO
#define PORTD			*(volatile unsigned int *)(IO_BASE + 0x12)
#define DDRD			*(volatile unsigned int *)(IO_BASE + 0x11)
#define DDRB			*(volatile unsigned int *)(IO_BASE + 0x17)




void GPIO_init()
{
	//Set Pin 5,6,7 in PORT D as an output
	DDRD |= 1<<5 ;
	DDRD |= 1<<6 ;
	DDRD |= 1<<7 ;
	//Set Pin 2,3 in PORT D as an input
	DDRD &= ~(1<<2) ;
	DDRD &= ~(1<<3) ;
	//Set Pin 2 in PORT B as an input
	DDRB &= ~(1<<2);

}
void EXTI_init()
{
	//Enable Global interrupt
	SREG  |= (1<<7);
	//Enable interrupt in GICR
	GICR |= 1<<5 ;
	GICR |= 1<<6 ;
	GICR |= 1<<7 ;
	//	External Interrupt 0 (INT0)-PD2. >> irq occur when “any logical change”
	MCUCR |= (0b01<<0);
	//	External Interrupt 1 (INT1)-PD3. >> irq occur when “rising edge”
	MCUCR |= (0b11<<2);
	//	External Interrupt 2 (INT2)-PB2. >> irq occur when “Falling edge”
	MCUCSR &= ~(1<<6);

}


int main()
{
	GPIO_init();
	EXTI_init();
	while(1);
}

ISR (INT0_vect)
{
	PORTD |= 1<<5;
	_delay_ms(1000);
	PORTD &= ~(1<<5);
}
ISR (INT1_vect)
{
	PORTD |= 1<<6;
	_delay_ms(1000);
	PORTD &= ~(1<<6);
}
ISR (INT2_vect)
{
	PORTD |= 1<<7;
	_delay_ms(1000);
	PORTD &= ~(1<<7);
}
