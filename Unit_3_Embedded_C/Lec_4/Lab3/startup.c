#include "stdint.h"

/*
In this startup we will init stack_top using an uninitilized array of int 256 element 
so it will be located ontop of .bss

*/
extern int main();
void Reset_Handler();

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak ,alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak ,alias("Default_Handler")));
void MM_fault_Handler()__attribute__((weak ,alias("Default_Handler")));
void Bus_fault_Handler()__attribute__((weak ,alias("Default_Handler")));
void Usage_fault_Handler()__attribute__((weak ,alias("Default_Handler")));


static unsigned long Stack_top[256] ;


void (* const g_p_fn_vectors []) () __attribute__((section(".vectors"))) =
{
	( void (*)() ) ((unsigned long) Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&MM_fault_Handler,
	&Bus_fault_Handler,
	&Usage_fault_Handler,
} ;


extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _E_text;

void Reset_Handler()
{
	//copy data from Flash to SRAM
	uint32_t DATA_size = (unsigned char*)&_E_DATA - (unsigned char*) &_S_DATA;
	//casting char to protect from memory not being aligned , even tho coping in int format is faster
	unsigned char * P_src = (unsigned char*) &_E_text;
	unsigned char * P_dst = (unsigned char*) &_S_DATA;
	volatile int i;
	for (i=0 ; i< DATA_size ; i++)
	{
		*((unsigned char *)P_dst++) = *((unsigned char*)P_src++);
	}
	uint32_t bss_size = (unsigned char*)&_E_bss -(unsigned char*)&_S_bss  ;
	P_dst = (unsigned char*) &_S_bss;
	
	for (i=0 ; i< DATA_size ; i++)
	{
		*((unsigned char *)P_dst++) = (unsigned char ) 0 ;
	}
	
	main();
}