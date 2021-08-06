//@Copyright: Arasny

#include"stdint.h"
#define RCC_BASE			0x40021000
#define GPIOA_BASE			0x40010800
#define RCC_APB2ENR			*(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH			*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR			*(volatile uint32_t *)(GPIOA_BASE + 0x0C)

unsigned char g_variabled[3]={1,2,3};
unsigned char const const_var[3]={1,2,3};
unsigned char bss_var[3]; 

int main(void)
{
	int i;
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |=1<<13;
		for(i=0;i<5000;i++);
		GPIOA_ODR &= ~(1<<13);
		for(i=0;i<5000;i++);
	}
}