/*****************************************************
 *
 * Module: UART
 *
 * File Name: UART.C
 *
 *  Description: Source file for UART driver
 *
 *******************************************************/

#include "uart.h"

#define BAUD_PRESCAL ((F_CPU / (USART_BAUDRATE * 8UL))-1)

/*******************************************************
 *                      Function Definitions
 ********************************************************/

void UART_init(void)
{
	/*U2X = 1 for double transmit speed */
	UCSRA = 1<<U2X ;
	/***************** UCSRB DESCRIPTION ***********************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART TX Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN = 1 Recieve Enable
	 * TXEN = 1 Transmit Enable
	 * UCSZ2 = 0 for 8-bit data mode
	 * RXB8 & TXB8 NOT USED FOR 8 BIT MODE
	 **********************************************************/
	UCSRB = 1<<RXEN| 1<<TXEN;

	/***************** UCSRC DESCRIPTION ***********************
		 * URSEL    = 1 this pin must be 1  when writting the UCSRC
		 * UMSEL    = 0 Asynchronous Operation
		 * UPM1:0   = 0 00 Disable Parity Bit
		 * USBS     = 0 1 stop bit
		 * UCSZ1:0  = 11 for b-bit data mode
		 * UCPOL    = 0 used with the Synchronous operation only
		 **********************************************************/
	UCSRC = 1<<URSEL| 1<<UCSZ0| 1<<UCSZ1;

    /* first b bit from the BAUD_BRESCALE inside UBRRL and the last 4 bit in UBBRH */
	UBBRH = BAUD_PRESCAL>>8;
	UBBRL = BAUD_PRESCAL;

}

void UART_sendByte(const u8 data)
{
	/*
	 * UDRE flag must be 1 to be empty to send new data
	 */
	while (!GET_BIT(UCSRA,UDRE)){} //wait until this flag to set 1
	 /* NOW WE CAN SEND DATA */
	UDR =data;
	/************Another Method ***************
	 * 	while (!GET_BIT(UCSRA,TXC)){} wait until the transmition is complete TXC = 1
	 *  SET_BIT(UCSRA,TXC);
	 */

}

void UART_recieveByte(void)
{
	/* RXC flag must be 1 to recieve data */
	while (!GET_BIT(UCSRA,RXC)){} //wait until the Recieving is complete RXC = 1
	SET_BIT(UCSRA,TXC);
	return UDR;
}

void UART_sendString(const u8 *str)
{
 u8 i =0;
 while (str[i] != '\0')
 {
	 UART_sendByte(str[i]);
	 i++;
 }
}

void UART_recieveString( u8 *str)
{
	u8 j=0;
	str[j]= UART_recieveByte();
	while (str[j] != '#')
	{
		j++;
		str[j]= UART_recieveByte();

	}
	str[j]= '\0';
}

