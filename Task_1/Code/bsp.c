// Eng. Mohamed Gamal Saleh Mohamed

#include "bsp.h"

void uart0_putchar(char c){
	while( UART0_FR_R & (1<<5) != 0); //wait until fifo is full 
	UART0_DR_R = c;
}