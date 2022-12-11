//Eng. Mohamed Gamal Saleh Mohamed

#include"uart.h"
#include <stdlib.h>
#include <stdio.h>

/************************** Generic_Functions ****************************************/

 int tostring(char str[], int num)
{
    int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
	return len;
}

/************************************************************************************/

//Delay
void delay_ms(){
	for (int i=0; i<15000;i++);
}

/************************************************************************************/


/************************** APIs ***************************************************/

void uart0_init(uint32_t clk, uint32_t baud_rate){

	SYSCTL_RCGCUART_R |= (1<<0);//enable uart 0
	SYSCTL_RCGCGPIO_R |= (1<<0);//enable port A

	GPIO_PORTA_AFSEL_R |= (1<<1) | (1<<0);//enable alternative function for PA0,PA1

	GPIO_PORTA_DEN_R |= (1<<0) | (1<<1); //digital enable for PA0,PA1

	UART0_CTL_R &= ~1; //disable uart

    /*float ibrd = ((clk*1000000) / (16*baud_rate));
	int fbrd = (int)((ibrd - (int)ibrd)*64 + 0.5);
	UART0_IBRD_R = (int)ibrd;
	UART0_FBRD_R = fbrd;*/

    int CLK = clk*1000000;
    UART0_IBRD_R = IBRD( CLK , baud_rate);
    UART0_FBRD_R = FBRD( CLK , baud_rate);

	UART0_LCRH_R = (0x3<<5); //8bit data

	UART0_CC_R = 0x0; //use system clock

	UART0_CTL_R = (1<<0) | (1<<8) | (1<<9); //uart anable + UART Transmit Enable + UART Recieve Enable
}

/************************************************************************************/

void print(const char * str){
	while(*str){
			uart0_putchar(*(str++));
			delay_ms();
	}
}

/************************************************************************************/
 
void print_ibin(unsigned int n){

	print("0b: ");
	 for (int i = 31; i >= 0; i--) {
        int mask = (1 << i);
        if (n & mask)
           print("1");
        else 
           print("0");
    }
}
 
 /************************************************************************************/
 
void print_ihex(unsigned int n){

    long quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];
 
    quotient = n;
 
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
 

    print("0x: ");
    // display integer into character
    for (i = j; i >= 0; i--)
            uart0_putchar(hexadecimalnum[i]);
 }
 
/************************************************************************************/

int print_idec(int n){
	
    print("Decimal: ");
    int count=0;
	if(n<0){
		uart0_putchar('-');
		count++;
		n*=-1;
	}else if(n==0){
		uart0_putchar('0');
		return 1;
	}
   char buff[16]; 
   count +=tostring(buff,n);
   print(buff);
   return count;
 }

/************************************************************************************/