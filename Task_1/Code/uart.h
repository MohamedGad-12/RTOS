// Eng. Mohamed Gamal Saleh Mohamed

#ifndef _UART_H_
#define _UART_H_

#include "bsp.h"

/******************************** Baud Rate *******************************/

#define BRD(_CLK_,_Baud_Rate_)          (int)( ( (_CLK_<<2) + (_Baud_Rate_>>1) ) /_Baud_Rate_)
#define IBRD(_CLK_,_Baud_Rate_)         (int)( (BRD(_CLK_,_Baud_Rate_)) >> 6)
#define FBRD(_CLK_,_Baud_Rate_)         (int)( (BRD(_CLK_,_Baud_Rate_)) & 0x3F)

/******************************** APIs ************************************/

//uart0 initialization
void uart0_init(uint32_t clk, uint32_t baud_rate);

 /*function to print 32 bit binary */
 void print_ibin(unsigned int n);

 /*function to print hexadecimal */
 void print_ihex(unsigned int n);

 /*function to print decimal number */
 int print_idec(int n);
 
 /*function to print  string */
 void print(const char *str);

/**************************************************************************/

#endif