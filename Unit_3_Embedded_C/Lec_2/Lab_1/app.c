#include "stdio.h"
#include "uart.h"

unsigned char string[100] = "Learn-In-Depth:<Arsany Ashraf>";

int main ()
{

	uart_send_string (string);

	return 0;
}