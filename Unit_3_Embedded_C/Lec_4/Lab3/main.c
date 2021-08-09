//@Copyright: Arasny

#include"stdint.h"
#define SYSCTL_RCGC2_R          (*(volatile unsigned long*)(0x400FE108))
#define GPIO_PORTF_DATA_R		(*(volatile unsigned long*)(0x400253FC))
#define GPIO_PORTF_DIR_R		(*(volatile unsigned long*)(0x40025400))
#define GPIO_PORTF_DEN_R		(*(volatile unsigned long*)(0x4002551C))

int main(void)
{
	volatile unsigned long delay_led;
	SYSCTL_RCGC2_R = 0x00000020;
	for(delay_led = 0;delay_led<200;delay_led++);
	GPIO_PORTF_DIR_R |= 1<<3;
	GPIO_PORTF_DEN_R |= 1<<3;
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_led = 0;delay_led<20000;delay_led++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_led = 0;delay_led<20000;delay_led++);
	}
	return 0;
}
