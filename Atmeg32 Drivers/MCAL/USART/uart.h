/*****************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 *  Description: Header file for UART driver
 *
 *******************************************************/

#ifndef UART_H_
#define UART_H_


#include "STD_types.h"
#include "BIT_math.h"
#include "Atmega32_reg.h"

/* UCSRA*/

#define RXC    7
#define TXC    6
#define UDRE   5
#define FE     4
#define DOR    3
#define PE     2
#define U2X    1
#define MPCM   0

/*UCSRB*/

#define RXCIE    7
#define TXCIE    6
#define UDRIE    5
#define RXEN     4
#define TXEN     3
#define UCSZ2    2
#define RXB8     1
#define TXB8     0


/*UCSRC*/

#define URSEL    7
#define UMSEL    6
#define UPM1    5
#define UPM0     4
#define USBS     3
#define UCSZ1    2
#define UCSZ0     1
#define UCPOL     0

/******************************************************
 *                   Preprocessor Macros
 *****************************************************/

/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************
 *               Function Prototypes
 * ****************************************************/

void UART_init(void);

void UART_sendByte(const u8 data);

u8 UART_recieveByte(void);

void UART_sendString(const u8 *str);

void UART_recieveString( u8 *str);


#endif /* UART_H_ */
