/*
 * main.c
 *
 * Created: 24-Mar-24 7:03:09 PM
 *  Author: Arsany
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU		1000000UL

#define BASE		0x20
//INT
#define MCUCR		*(volatile unsigned char *)(BASE + 0x35)
#define MCUCSR		*(volatile unsigned char *)(BASE + 0x34)
#define GICR		*(volatile unsigned char *)(BASE + 0x3B)
#define GIFR		*(volatile unsigned char *)(BASE + 0x3A)
#define SREG		*(volatile unsigned char *)(BASE + 0x3F)

//GPIO
#define DDRD		*(volatile unsigned char *)(BASE + 0x11)
#define DDRB		*(volatile unsigned char *)(BASE + 0x17)
#define PORTD		*(volatile unsigned char *)(BASE + 0x12)


void GPIO_Init(void)
{
	//Config PORTD PIN5,PIN6,PIN7 As output
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);
	//Config PORTD PIN2,PIN3 As Input
	DDRD &= ~(1<<2);
	DDRD &= ~(1<<3);
	//Config PORTB PIN2 As Input
	DDRB &= ~(1<<2);
}


void INT_Init(void)
{
	
	//Enable global interrupt
	SREG |= (1<<7);
	//Enable INT0 , INT1 , INT2
	GICR |= (1<<7);
	GICR |= (1<<6);
	GICR |= (1<<5);
	//Config INT0 to activate at any logic
	MCUCR |= (0b01<<0);
	//Config INT1 to activate at rising edge
	MCUCR |= (0b11<<2);
	//Config INT2 to activate at Falling edge
	MCUCSR &= ~(1<<6);
	
}


int main(void)
{
	GPIO_Init();
	INT_Init();
    while(1);
}

ISR(INT0_vect)
{
	PORTD |= (1<<5);
	_delay_ms(1000);
	PORTD &= ~(1<<5);
}

ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(1000);
	PORTD &= ~(1<<6);
	
}

ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
	PORTD &= ~(1<<7);
}