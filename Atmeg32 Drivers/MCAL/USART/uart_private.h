/*****************************************************
 *
 * Module: UART
 *
 * File Name:private.h
 *
 *  Description: USART PRIVATE
 *
 *******************************************************/
 
 
 
 #define UDR    *((volatile unsigned char* const)0X2C)
 #define UCSRA  *((volatile unsigned char* const)0X2B)
 #define UCSRB  *((volatile unsigned char* const)0X2A)
 #define UBRRL  *((volatile unsigned char* const)0X29)
 #define UBRRH  *((volatile unsigned char* const)0X40)
 #define UBRRL  *((volatile unsigned char* const)0X29)
