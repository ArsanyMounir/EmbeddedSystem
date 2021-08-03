#include "uart.h"
unsigned char string_buffer[100]="Learn-In_Depth:<Arsany Ashraf>";
unsigned char const string_buffer1[100]="Learn-In_Depth:<Arsany Ashraf>";
void main(void)
{
	UART_Send_string(string_buffer);
}
