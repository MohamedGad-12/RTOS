// Eng. Mohamed Gamal Saleh Mohamed

/************************** include ****************************************/

#include<stdint.h>

/************************** SYSCTL ****************************************/

#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))

#define SYSCTL_RCGCUART_R       (*((volatile uint32_t *)0x400FE618))


/************************** GPIO ****************************************/


#define GPIO_PORTA_AFSEL_R      (*((volatile uint32_t *)0x40004420))

#define GPIO_PORTA_DEN_R        (*((volatile uint32_t *)0x4000451C))

#define SYSCTL_RCGCGPIO_R5      0x00000020  // GPIO Port F Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R4      0x00000010  // GPIO Port E Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R3      0x00000008  // GPIO Port D Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R2      0x00000004  // GPIO Port C Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R1      0x00000002  // GPIO Port B Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R0      0x00000001  // GPIO Port A Run Mode Clock
                                            // Gating Control

/************************** UART ****************************************/

#define UART0_CTL_R             (*((volatile uint32_t *)0x4000C030))

#define UART0_LCRH_R            (*((volatile uint32_t *)0x4000C02C))

#define UART0_CC_R              (*((volatile uint32_t *)0x4000CFC8))

#define UART0_CTL_R             (*((volatile uint32_t *)0x4000C030))

#define UART0_IBRD_R            (*((volatile uint32_t *)0x4000C024))

#define UART0_DR_R              (*((volatile uint32_t *)0x4000C000))

#define UART0_FR_R              (*((volatile uint32_t *)0x4000C018))

#define UART0_FBRD_R            (*((volatile uint32_t *)0x4000C028))

#define SYSCTL_RCGCUART_R7      0x00000080  // UART Module 7 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R6      0x00000040  // UART Module 6 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R5      0x00000020  // UART Module 5 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R4      0x00000010  // UART Module 4 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R3      0x00000008  // UART Module 3 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R2      0x00000004  // UART Module 2 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R1      0x00000002  // UART Module 1 Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCUART_R0      0x00000001  // UART Module 0 Run Mode Clock
                                            // Gating Control

/************************** Generic_Functions ****************************************/

/*function to transmit character */
void uart0_putchar(char c);

/************************************************************************************/

