//startup.c
//End.Arsany
#include"stdint.h"
extern int main();
void Reset_Handler();
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler()__attribute__((weak,alias("Default_Handler")));
void Bus_Fault_Handler()__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__((weak,alias("Default_Handler")));

//reserving stack size without using the linker_script
static unsigned long Stack_top[256];

void (*const g_p_fn_Vectors[])()__attribute__((section(".vectors")))=
{
	(void(*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault_Handler,
	&Usage_Fault_Handler
};


extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
int i;


void Reset_Handler()
{
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	for( i=0;i<DATA_SIZE;i++)
	{
		*((unsigned char*)P_dst++)=*((unsigned char*)P_src);
	}
	unsigned int bss_SIZE = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst=(unsigned char*)&_S_bss;
	for( i=0;i<DATA_SIZE;i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	main();
}