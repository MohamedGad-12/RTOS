// Eng. Mohamed Gamal Saleh Mohamed

#include "uart.h"

unsigned char string_buffer_Info[100] = "Name: Mohamed Gamal Saleh Moahemd\r\nID: 1807570\r\nSEC: 1";

unsigned char string_buffer_CLK[500] = "Equation: BRD = BRDI + BRDF = UARTSysClk / (16 * Baud Rate)\r\nUARTSysClk: 20,000,000\r\nBaud Rate: 115,200";

void main(void)
{
	uart0_init(20,115200);
	print("\r\n");
	print(string_buffer_Info);
	print("\r\n");
	print("\r\n");
	print(string_buffer_CLK);
	print("\r\n");
	print("IBRD in ");
	print_idec(IBRD( 20000000 , 115200));
	print("\r\n");
	print("FBRD in ");
	print_idec(FBRD( 20000000 , 115200));
	print("\r\n");
	print("\r\n");
	print("One Hundred in HEX ");
	print_ihex(100);
	print("\r\n");
	print("One Hundred in ");
	print_idec(100);
	print("\r\n");
	print("One Hundred in Binary ");
	print_ibin(100);
	print("\r\n");
}